/* Differential test: C implementation of one routine vs (a) a Snes9x entry/exit capture and (b) the LakeSnes oracle.
 *
 * difftest --rom ROM --entry HEX --variant NAME --caps DIR[,DIR...] [--max-caps N] [--fuzz N] [--seed S] [--ninsn N] [--size B]
 * Prints one JSON object.  No ROM bytes are printed.
 */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include "somrt.h"

/* A C routine that never returns (a wait loop on something the test cannot change) is stopped after 2 s of CPU time and
 * reported as failed instead of hanging the whole run. */
static sigjmp_buf wd_jmp;
static volatile sig_atomic_t wd_armed;
static void wd_handler(int sig) { (void)sig; if (wd_armed) siglongjmp(wd_jmp, 1); }
static void wd_trip(void) { if (wd_armed) siglongjmp(wd_jmp, 1); }
/* unwinders whose own return is not at entry S + return size: bytes popped before it (see the use in run_entry) */
static const struct { uint32_t entry; int n; } unwind_pop[] = { { 0xC03F69, 4 }, { 0x7EBA1C, 7 }, { 0x7E9646, 7 },
    { 0xC19566, 2 }, { 0xC195BC, 2 }, { 0xC199CB, 2 }, { 0xC1A991, 2 }, { 0xC1ABC7, 2 }, { 0xC1ADFD, 2 },
    { 0xC0A733, 3 }, { 0xC0AC5E, 3 } };
static void guarded(const SomImpl *im, SomCtx *g) {
    struct itimerval on = { { 0, 0 }, { 2, 0 } }, off = { { 0, 0 }, { 0, 0 } };
    signal(SIGVTALRM, wd_handler);
    if (sigsetjmp(wd_jmp, 1) == 0) { wd_armed = 1; setitimer(ITIMER_VIRTUAL, &on, 0); g->routine_sp = g->cpu.sp; g->c_run = 1; g->routine_ret = im->ret_op; g->routine_unw = (im->flags & SOM_UNWINDS) != 0; g->stop_hook = wd_trip; im->fn(g);
        if (g->task_mode == 2 && !g->switched) { const int d = (int)g->cpu.sp - (int)g->task_s; if (d >= 0x100 || d <= -0x100) g->switched = 1; } /* the C routine swapped the stack inline and returned into the resumed task: that return is the end of the call, as in the capture */
        /* A routine that drops its own return address ends where the original code does: the original stops at a return only
         * when the stack pointer before it is the entry one (or the entry one plus the return address, for routines that
         * unwind).  When the C routine returned at another depth (PLD, RTL taking the caller's frame), the original keeps
         * running from there until that rule stops it, so the same code is run from the C routine's exit state. */
        if ((im->flags & SOM_UNWINDS) && !g->fail && !g->switched && !g->exited && (im->ret_op == SOM_RTS || im->ret_op == SOM_RTL)) {
            const uint16_t esp = g->routine_sp, n = im->ret_op == SOM_RTS ? 2 : 3, un = som_unwind_n ? (uint16_t)som_unwind_n : n, before = (uint16_t)(g->cpu.sp - n);
            if (before != esp && before != (uint16_t)(esp + un)) { g->allow_unwind = 1; som_interp_run(g, im->ret_op, esp); }
        } }
    else { g->fail = 1; if (getenv("SOM_DEBUG")) fprintf(stderr, "C routine stopped by the watchdog\n"); }
    wd_armed = 0;
    setitimer(ITIMER_VIRTUAL, &off, 0);
}

typedef struct { uint16_t a, x, y, s, d, p, pc; uint8_t db, pb; } CapRegs;
typedef struct { uint32_t addr; uint8_t val, write; uint16_t pad; } CapIo;
/* continuation windows (header bit 23, see the trailer description in snes9x_capture_core_cont.patch): one swap-out / resume cycle */
typedef struct { uint32_t io_at_y; CapRegs y, k; struct { uint8_t dma[0x80]; uint32_t wmadd; uint16_t wrdiv, rddiv, rdmpy; uint8_t wrmpya, hdmaen; } khw; uint32_t ndy, ndk, nsy, nsk; } __attribute__((packed)) CapCycleHead;
typedef struct { CapCycleHead h; uint32_t *dy, *dk, *sy, *sk; /* (value << 24) | offset, chained: Y = previous image + dy, K = Y + dk */ uint32_t nwr; /* routine writes logged up to Y */ } CapCycle;
typedef struct {
    uint32_t entry, call, flags, nio, steps;
    CapRegs pre, post;
    uint8_t *wram_pre, *wram_post;
    CapIo *io;
    uint8_t ret_op, tainted;
    uint8_t forced;       /* the capture driver chose the inputs (header bit 18, or the staged name ends in _f.bin / _fo.bin) */
    uint8_t task;         /* TASK mode of this capture's window (0 none, 1 ends at the swap, 2 ends at the first return after it); per capture, a natural full-cycle capture of the same routine keeps mode 0 */
    const SomImpl *aim;   /* implementation registered at the capture's own entry when it is an alias (interior) entry of the routine under test */
    uint8_t switched;     /* header bit 22 / ret opcode 1B: TASK window, closed at a cooperative stack switch (S left the entry S by 0x100 or more) */
    uint8_t unwound;      /* header bit 21: the capture ended at the unwinding RTS/RTL (S = entry S + own return size) */
    uint8_t suspect;      /* forced capture made by an older core (staged name ends in _fo.bin): usable only because the oracle reproduces it */
    uint8_t badret;       /* the real run did not come back to the pushed return address: a state jump or continuation inside the window */
    uint8_t at_exit;      /* header bit 20 / ret opcode 4C: exit-address window, the capture ended before the instruction at post.pb:post.pc ran */
    uint32_t exit_pc;     /* normalised address of that instruction */
    uint8_t io_truncated; /* format-1 capture whose event log stopped at its 4096-entry limit: only the recorded prefix of writes is known */
    char path[512];
    uint8_t *sram_pre, *sram_post; uint32_t sram_size; /* SRAM image at entry and exit (format 2 captures) */
    uint32_t nint; SomEvent *ints; uint32_t *int_delta; /* interrupts taken inside the routine (format 2) */
    int has_hw; struct { uint8_t dma[0x80]; uint32_t wmadd; uint16_t wrdiv, rddiv, rdmpy; uint8_t wrmpya, hdmaen; } hw; /* hardware state at entry */
    SomRp rp;            /* the routine's own hardware reads, run-length coded per register */
    SomIo *wr; uint32_t nwr; /* the routine's own I/O writes (the interrupt handlers' are not part of the test) */
    uint8_t cont;         /* header bit 23: the window spans task switches; cyc holds the state at each swap-out return (Y) and resume return (K) */
    uint8_t endsw;        /* continuation window that closed at the next swap (ret opcode 1B) after its last cycle */
    uint32_t ncyc; CapCycle *cyc; uint32_t wr_from; /* writes of the last stage start at wr[wr_from] */
    uint32_t sram_size_c;
    uint8_t ob1, ob2, have_ob;   /* PPU open-bus latches at the entry (trailer SCP5) */
    uint32_t exit_n;             /* exit=ADDR@N window: it ended at the N-th arrival at the exit address (trailer SCP6; 0 = the first) */
} Cap;

static uint64_t rng_s = 88172645463325252ull;
static uint32_t rnd(void) { rng_s ^= rng_s << 13; rng_s ^= rng_s >> 7; rng_s ^= rng_s << 17; return (uint32_t)(rng_s >> 11); }

/* TASK windows of the routine under test: 1 = captures close at the stack swap (ret opcode 1B), 2 = they run on to the first return past the new stack */
static void set_regs(SomCtx *c, const CapRegs *r) {
    Cpu *p = &c->cpu;
    p->a = r->a; p->x = r->x; p->y = r->y; p->sp = r->s; p->dp = r->d; p->pc = r->pc; p->db = r->db; p->k = r->pb;
    uint8_t f = r->p & 0xFF;
    p->n = f & 0x80; p->v = f & 0x40; p->mf = f & 0x20; p->xf = f & 0x10; p->d = f & 8; p->i = f & 4; p->z = f & 2; p->c = f & 1;
    p->e = (r->p >> 8) & 1;
    p->irqWanted = p->nmiWanted = p->intWanted = p->resetWanted = p->waiting = p->stopped = false;
}

static int load_cap(const char *path, Cap *c) {
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    uint32_t h[6];
    if (fread(h, 4, 6, f) != 6 || h[0] != 0x50414353u) { fclose(f); return -1; }
    c->entry = h[1]; c->call = h[2]; c->tainted = h[3] & 1; c->ret_op = (h[3] >> 8) & 0xFF; c->nio = h[4]; c->steps = h[5];
    int v2 = (h[3] >> 16) & 1;
    c->io_truncated = !v2 && c->nio == 4096;
    c->wram_pre = malloc(SOM_WRAM_SIZE); c->wram_post = malloc(SOM_WRAM_SIZE);
    c->io = c->nio ? malloc(c->nio * sizeof(CapIo)) : NULL;
    int ok = fread(&c->pre, sizeof(CapRegs), 1, f) == 1 && fread(&c->post, sizeof(CapRegs), 1, f) == 1 &&
             fread(c->wram_pre, 1, SOM_WRAM_SIZE, f) == SOM_WRAM_SIZE && fread(c->wram_post, 1, SOM_WRAM_SIZE, f) == SOM_WRAM_SIZE &&
             (c->nio == 0 || fread(c->io, sizeof(CapIo), c->nio, f) == c->nio);
    if (ok && v2) {
        uint32_t magic = 0, nsr = 0;
        ok = fread(&magic, 4, 1, f) == 1 && magic == 0x32504353u && fread(&nsr, 4, 1, f) == 1;
        if (ok && nsr) {
            c->sram_size = nsr; c->sram_pre = malloc(nsr); c->sram_post = malloc(nsr);
            ok = fread(c->sram_pre, 1, nsr, f) == nsr && fread(c->sram_post, 1, nsr, f) == nsr;
        }
        if (ok) { ok = fread(&c->hw, sizeof c->hw, 1, f) == 1; c->has_hw = ok; }
        if (ok) ok = fread(&c->nint, 4, 1, f) == 1;
        if (ok && c->nint) {
            c->ints = calloc(c->nint, sizeof(SomEvent));
            for (uint32_t i = 0; ok && i < c->nint; i++) {
                struct { uint32_t kind, at, ndelta, wmadd; uint16_t wrdiv, rddiv, rdmpy; uint8_t wrmpya, hwvalid; uint8_t dma[0x80]; uint8_t hdmaen, pad; } __attribute__((packed)) rec;
                ok = fread(&rec, sizeof rec, 1, f) == 1;
                if (!ok) break;
                uint32_t *d = rec.ndelta ? malloc(rec.ndelta * 4) : NULL;
                ok = !rec.ndelta || fread(d, 4, rec.ndelta, f) == rec.ndelta;
                c->ints[i] = (SomEvent){ rec.at, 0, rec.ndelta, d, rec.hwvalid, rec.wmadd, rec.wrmpya, rec.wrdiv, rec.rddiv, rec.rdmpy };
                c->ints[i].kind = rec.kind;
                memcpy(c->ints[i].dma, rec.dma, 0x80); c->ints[i].hdmaen = rec.hdmaen;
            }
        }
        if (ok && ((h[3] >> 23) & 1)) {
            uint32_t m3 = 0, nc = 0, ns3 = 0;
            ok = fread(&m3, 4, 1, f) == 1 && m3 == 0x33504353u && fread(&nc, 4, 1, f) == 1 && fread(&ns3, 4, 1, f) == 1 && nc >= 1 && nc <= 255 && ns3 <= 0x8000;
            if (ok) { c->cyc = calloc(nc, sizeof *c->cyc); c->ncyc = nc; c->sram_size_c = ns3; }
            for (uint32_t i = 0; ok && i < nc; i++) {
                CapCycle *y = &c->cyc[i];
                ok = fread(&y->h, sizeof y->h, 1, f) == 1 && y->h.ndy <= 0x20000 && y->h.ndk <= 0x20000 && y->h.nsy <= 0x8000 && y->h.nsk <= 0x8000;
                if (!ok) break;
                y->dy = malloc((y->h.ndy + 1) * 4); y->dk = malloc((y->h.ndk + 1) * 4); y->sy = malloc((y->h.nsy + 1) * 4); y->sk = malloc((y->h.nsk + 1) * 4);
                ok = fread(y->dy, 4, y->h.ndy, f) == y->h.ndy && fread(y->dk, 4, y->h.ndk, f) == y->h.ndk && fread(y->sy, 4, y->h.nsy, f) == y->h.nsy && fread(y->sk, 4, y->h.nsk, f) == y->h.nsk;
            }
            c->cont = ok;
        }
        if (ok) { /* optional trailers after SCP3: SCP5 (open-bus latches), SCP6 (exit arrival count) */
            for (int tr = 0; tr < 2; tr++) {
                uint32_t m5 = 0; uint8_t ob[4];
                if (fread(&m5, 4, 1, f) != 1) break;
                if (m5 == 0x35504353u && fread(ob, 1, 4, f) == 4) { c->ob1 = ob[0]; c->ob2 = ob[1]; c->have_ob = 1; }
                else if (m5 == 0x36504353u && fread(&c->exit_n, 4, 1, f) == 1) { }
                else break;
            }
        }
    }
    fclose(f);
    snprintf(c->path, sizeof c->path, "%s", path);
    {   size_t pl = strlen(path);
        c->suspect = pl > 7 && !strcmp(path + pl - 7, "_fo.bin");
        c->unwound = (h[3] >> 21) & 1;
        c->at_exit = (h[3] >> 20) & 1;
        c->exit_pc = som_norm(((uint32_t)c->post.pb << 16) | c->post.pc);
        c->switched = !c->cont && (((h[3] >> 22) & 1) || c->ret_op == 0x1B);
        c->endsw = c->cont && c->ret_op == 0x1B;
        c->forced = ((h[3] >> 18) & 1) || c->suspect || (pl > 6 && !strcmp(path + pl - 6, "_f.bin"));
    }
    if (!ok) return -1;
    /* split the event log: the routine's hardware reads become per-register streams, its writes a plain list */
    uint32_t cnt[0x300] = { 0 };
    c->wr = malloc((c->nio + 1) * sizeof(SomIo));
    uint32_t nread = 0, run = 0; int in_run = 0;
    /* events of kind 2 are scenario WRAM writes made by the capture driver between frames: they have no handler and no log entries.
     * The handlers (kind 0/1) are matched with the logged runs of handler accesses in order; a capture that carries a separator
     * entry (addr FFFFFF) before every handler lets handlers without any access be placed as well. */
    uint32_t *hmap = malloc((c->nint + 1) * sizeof *hmap), nh = 0, nseps = 0;
    for (uint32_t i = 0; i < c->nint; i++) if (c->ints[i].kind != 2) hmap[nh++] = i;
    for (uint32_t i = 0; i < c->nio; i++) if (c->io[i].addr == 0xFFFFFF && !(c->io[i].pad & 1)) nseps++;
    const int sepmode = nseps && nseps == nh;
    uint32_t cyc_next = 0;
    for (uint32_t i = 0; i < c->nio; i++) {
        const CapIo *e = &c->io[i];
        while (cyc_next < c->ncyc && c->cyc[cyc_next].h.io_at_y <= i) c->cyc[cyc_next++].nwr = c->nwr; /* writes logged before the swap-out return of that cycle */
        if (sepmode && e->addr == 0xFFFFFF && !(e->pad & 1)) { if (run < nh) c->ints[hmap[run]].hwat = nread; run++; in_run = 0; continue; }
        if (e->pad & 1) { /* inside an interrupt handler: the k-th run of such events belongs to the k-th interrupt */
            if (!in_run && !sepmode) { if (run < nh) c->ints[hmap[run]].hwat = nread; run++; in_run = 1; }
            if (!e->write && run && run <= nh) { /* the handler's own hardware reads (the math unit is computed, not replayed) */
                uint32_t low = e->addr & 0xFFFF;
                if (low >= 0x4214 && low <= 0x4217) continue;
                SomEvent *ev = &c->ints[hmap[run - 1]];
                SomHRead *q = (SomHRead *)ev->hq;
                if (ev->nhq && q[ev->nhq - 1].addr == (e->addr & 0xFFFFFF) && q[ev->nhq - 1].val == e->val) { q[ev->nhq - 1].reps += (e->pad >> 1) + 1; continue; }
                if ((ev->nhq & (ev->nhq - 1)) == 0) { q = realloc(q, (ev->nhq ? ev->nhq * 2 : 16) * sizeof *q); ev->hq = q; }
                q[ev->nhq++] = (SomHRead){ e->addr & 0xFFFFFF, e->val, (uint32_t)(e->pad >> 1) + 1 };
            }
            continue;
        }
        in_run = 0;
        uint32_t low = e->addr & 0xFFFF;
        if (e->write) { c->wr[c->nwr++] = (SomIo){ e->addr, e->val, 1 }; continue; }
        if (!((low >= 0x2134 && low <= 0x213F) || (low >= 0x2140 && low <= 0x2143) || (low >= 0x4210 && low <= 0x421F) || low == 0x4016 || low == 0x4017)) continue;
        unsigned ix = som_rp_index(low);
        uint32_t reps = (e->pad >> 1) + 1;
        if (low < 0x4214 || low > 0x4217) nread += reps;
        SomRpRun *rr = c->rp.run[ix];
        if (c->rp.n[ix] && rr[c->rp.n[ix] - 1].val == e->val) { rr[c->rp.n[ix] - 1].reps += reps; continue; }
        if (c->rp.n[ix] == cnt[ix]) { cnt[ix] = cnt[ix] ? cnt[ix] * 2 : 8; c->rp.run[ix] = rr = realloc(rr, cnt[ix] * sizeof(SomRpRun)); }
        rr[c->rp.n[ix]++] = (SomRpRun){ e->val, reps };
    }
    while (cyc_next < c->ncyc) c->cyc[cyc_next++].nwr = c->nwr;
    c->wr_from = c->ncyc ? c->cyc[c->ncyc - 1].nwr : 0;
    /* a driver write is delivered right after the interrupt before it (exact mode places it by instruction count anyway) */
    for (uint32_t i = 0; i < c->nint; i++) if (c->ints[i].kind == 2) c->ints[i].hwat = i ? c->ints[i - 1].hwat : 0;
    if (run != nh) c->tainted = 1; /* an interrupt without hardware accesses cannot be placed */
    free(hmap);
    {   /* did the capture end at the return address the caller pushed?  (a savestate load or a WRAM poke by the capture driver inside a long routine
         * leaves the routine's frame; the capture then ends at an unrelated return with the same S) */
        const uint16_t sp = c->pre.s; const uint8_t *w = c->wram_pre;
        const uint16_t lo = w[(sp + 1) & 0x1FFFF] | (w[(sp + 2) & 0x1FFFF] << 8);
        int ok;
        if (c->switched || c->at_exit || c->endsw) ok = 1; /* a TASK window ends at the swap, an exit-address window before the instruction at the address: neither at a return */
        else if (c->ret_op == SOM_RTI) { /* interrupt capture: the frame the CPU pushed is P, PCL, PCH, PB; RTI resumes at the pushed PC itself */
            const uint16_t pcl = w[(sp + 2) & 0x1FFFF] | (w[(sp + 3) & 0x1FFFF] << 8);
            ok = c->post.pc == pcl && c->post.s == (uint16_t)(sp + 4) && ((c->post.pb ^ w[(sp + 4) & 0x1FFFF]) & 0x3F) == 0;
        } else {
            ok = c->post.pc == (uint16_t)(lo + 1) && c->post.s == (uint16_t)(sp + (c->ret_op == SOM_RTL ? 3 : 2));
            if (ok && c->ret_op == SOM_RTL) ok = ((c->post.pb ^ w[(sp + 3) & 0x1FFFF]) & 0x3F) == 0;
        }
        c->badret = !ok;
    }
    return 0;
}

typedef struct { SomCtx *c; } Exp; /* expected state is another SomCtx */

static int flags_of(const Cpu *p) {
    return (p->n << 7) | (p->v << 6) | (p->mf << 5) | (p->xf << 4) | (p->d << 3) | (p->i << 2) | (p->z << 1) | p->c;
}

/* compare two contexts after the routine returned; 0 = equal.  entry_sp = S at entry. */
static void dump_pair(const char *tag, const SomCtx *pre, const SomCtx *got, const SomCtx *exp) {
    if (!getenv("SOM_DEBUG")) return;
    fprintf(stderr, "%s pre: A=%04X X=%04X Y=%04X S=%04X D=%04X DB=%02X P=%02X | got: A=%04X X=%04X Y=%04X S=%04X pc=%04X P=%02X | exp: A=%04X X=%04X Y=%04X S=%04X pc=%04X P=%02X\n", tag,
            pre->cpu.a, pre->cpu.x, pre->cpu.y, pre->cpu.sp, pre->cpu.dp, pre->cpu.db, (pre->cpu.n << 7) | (pre->cpu.v << 6) | (pre->cpu.mf << 5) | (pre->cpu.xf << 4) | (pre->cpu.d << 3) | (pre->cpu.i << 2) | (pre->cpu.z << 1) | pre->cpu.c,
            got->cpu.a, got->cpu.x, got->cpu.y, got->cpu.sp, got->cpu.pc, (got->cpu.n << 7) | (got->cpu.v << 6) | (got->cpu.mf << 5) | (got->cpu.xf << 4) | (got->cpu.d << 3) | (got->cpu.i << 2) | (got->cpu.z << 1) | got->cpu.c,
            exp->cpu.a, exp->cpu.x, exp->cpu.y, exp->cpu.sp, exp->cpu.pc, (exp->cpu.n << 7) | (exp->cpu.v << 6) | (exp->cpu.mf << 5) | (exp->cpu.xf << 4) | (exp->cpu.d << 3) | (exp->cpu.i << 2) | (exp->cpu.z << 1) | exp->cpu.c);
}

/* diagnostics: where do the I/O write lists of two runs first differ (index, entries, PC of the oracle's write) */
static void io_diverge(const SomCtx *got, const SomCtx *exp) {
    uint32_t a = 0, b = 0, n = 0;
    for (;;) {
        while (a < got->nio && (got->io[a].write == 0 || (got->io[a].addr & 0xFFFF) - 0x2180u < 4u)) a++;
        while (b < exp->nio && (exp->io[b].write == 0 || (exp->io[b].addr & 0xFFFF) - 0x2180u < 4u)) b++;
        if (a >= got->nio || b >= exp->nio) { fprintf(stderr, "IODIFF lists end after %u common writes: oracle has %u more, snes9x %u more\n", n, got->nio - a, exp->nio - b); return; }
        if ((got->io[a].addr & 0xFFFF) != (exp->io[b].addr & 0xFFFF) || got->io[a].val != exp->io[b].val) {
            fprintf(stderr, "IODIFF first mismatch after %u common writes: oracle %04X=%02X (pc %04X), snes9x %04X=%02X\n", n, got->io[a].addr & 0xFFFF, got->io[a].val, got->io[a].pc, exp->io[b].addr & 0xFFFF, exp->io[b].val);
            for (int k = -3; k < 4; k++) if ((int)a + k >= 0 && a + k < got->nio) fprintf(stderr, "   oracle[%d] %04X=%02X %c pc %04X\n", k, got->io[a + k].addr & 0xFFFF, got->io[a + k].val, got->io[a + k].write ? 'W' : 'R', got->io[a + k].pc);
            return;
        }
        a++; b++; n++;
    }
}
/* diagnostics (SOM_IOHIST): writes per register in the two I/O logs */
static void io_hist(const SomCtx *got, const SomCtx *exp) {
    static uint32_t hg[0x10000], he[0x10000];
    memset(hg, 0, sizeof hg); memset(he, 0, sizeof he);
    for (uint32_t i = 0; i < got->nio; i++) if (got->io[i].write) hg[got->io[i].addr & 0xFFFF]++;
    for (uint32_t i = 0; i < exp->nio; i++) if (exp->io[i].write) he[exp->io[i].addr & 0xFFFF]++;
    for (uint32_t a = 0; a < 0x10000; a++) if (hg[a] != he[a]) fprintf(stderr, "IOHIST %04X: got %u exp %u\n", a, hg[a], he[a]);
    fprintf(stderr, "IOHIST totals: got %u entries, exp %u entries\n", got->nio, exp->nio);
}
static int cmp_math = 1;
static int cmp_io_prefix; /* the expected I/O write list is a truncated capture log: the actual one may be longer */
static int cmp_ctx(const SomCtx *got, const SomCtx *exp, int strict, uint32_t live, uint32_t stack_free, uint32_t implflags, uint16_t entry_sp, char *msg, size_t n) {
    const Cpu *g = &got->cpu, *e = &exp->cpu;
    msg[0] = 0;
    #define FAIL(...) do { snprintf(msg, n, __VA_ARGS__); return 1; } while (0)
    if (g->sp != e->sp) FAIL("S %04X != %04X", g->sp, e->sp);
    if (g->pc != e->pc || (g->k & 0x3F) != (e->k & 0x3F)) FAIL("return %02X:%04X != %02X:%04X", g->k, g->pc, e->k, e->pc);
    if ((implflags & SOM_POLLS) && exp->ev_inside_valid && got->ev_inside_valid && got->ev_inside != exp->ev_inside) FAIL("interrupts taken before the return %u != %u", got->ev_inside, exp->ev_inside);
    if (g->dp != e->dp) FAIL("D %04X != %04X", g->dp, e->dp);
    if (g->db != e->db) FAIL("DB %02X != %02X", g->db, e->db);
    if (g->mf != e->mf || g->xf != e->xf || g->e != e->e || g->d != e->d || g->i != e->i) FAIL("mode flags P %02X != %02X", flags_of(g), flags_of(e));
    if (strict) { if (g->a != e->a) FAIL("A %04X != %04X", g->a, e->a); }
    else {
        if ((live & L_A) && (g->a & 0xFF) != (e->a & 0xFF)) FAIL("A.low %02X != %02X", g->a & 0xFF, e->a & 0xFF);
        if ((live & L_B) && (g->a >> 8) != (e->a >> 8)) FAIL("A.high %02X != %02X", g->a >> 8, e->a >> 8);
    }
    if (strict || (live & L_X)) if (g->x != e->x) FAIL("X %04X != %04X", g->x, e->x);
    if (strict || (live & L_Y)) if (g->y != e->y) FAIL("Y %04X != %04X", g->y, e->y);
    if (strict || (live & L_C)) if (g->c != e->c) FAIL("C %d != %d", g->c, e->c);
    if (strict || (live & L_Z)) if (g->z != e->z) FAIL("Z %d != %d", g->z, e->z);
    if (strict || (live & L_N)) if (g->n != e->n) FAIL("N %d != %d", g->n, e->n);
    if (strict || (live & L_V)) if (g->v != e->v) FAIL("V %d != %d", g->v, e->v);
    if (getenv("SOM_IOHIST") && memcmp(got->wram, exp->wram, SOM_WRAM_SIZE)) io_hist(got, exp);
    uint32_t lo = 0, hi = 0; /* stack scratch window [lo, hi) in WRAM offsets */
    if (!strict && stack_free && entry_sp < 0x2000) { hi = entry_sp + 1u; lo = hi > stack_free ? hi - stack_free : 0; }
    const uint32_t dead_hi = entry_sp > e->sp + 1u ? entry_sp : e->sp + 1u; /* a routine that resets S (TXS) leaves its dead stack above the entry S */
    for (uint32_t i = 0; i < SOM_WRAM_SIZE; i++) {
        if (got->wram[i] != exp->wram[i]) {
            if (i >= lo && i < hi) continue;
            /* dead stack bytes below S that differ only in the bank mirror bits (a JSL pushed K = $00 in the capture and $C0 here) */
            if (i >= 0x100 && i < dead_hi && ((got->wram[i] ^ exp->wram[i]) & 0x3F) == 0 && ((got->wram[i] ^ exp->wram[i]) & 0xC0)) continue;
            if (getenv("SOM_DEBUG")) {
                uint32_t a_ = 0, b_ = 0, n_ = 0;
                for (;;) {
                    while (a_ < got->nio && (got->io[a_].write == 0 || (got->io[a_].addr & 0xFFFF) - 0x2180u < 4u)) a_++;
                    while (b_ < exp->nio && (exp->io[b_].write == 0 || (exp->io[b_].addr & 0xFFFF) - 0x2180u < 4u)) b_++;
                    if (a_ >= got->nio || b_ >= exp->nio) { fprintf(stderr, "  io lists end: got %u of %u, exp %u of %u (writes compared %u)\n", a_, got->nio, b_, exp->nio, n_); break; }
                    if ((got->io[a_].addr & 0xFFFF) != (exp->io[b_].addr & 0xFFFF) || got->io[a_].val != exp->io[b_].val) { fprintf(stderr, "  first io mismatch after %u writes: got %04X=%02X exp %04X=%02X\n", n_, got->io[a_].addr & 0xFFFF, got->io[a_].val, exp->io[b_].addr & 0xFFFF, exp->io[b_].val); break; }
                    a_++; b_++; n_++;
                }
            }
            if (getenv("SOM_DEBUG")) { int shown = 0; for (uint32_t j = i; j < SOM_WRAM_SIZE && shown < (getenv("SOM_DIFFN") ? atoi(getenv("SOM_DIFFN")) : 10); j++) if (got->wram[j] != exp->wram[j] && !(j >= lo && j < hi)) { fprintf(stderr, "  diff %05X got %02X exp %02X\n", j, got->wram[j], exp->wram[j]); shown++; } }
            FAIL("WRAM %05X: %02X != %02X", i, got->wram[i], exp->wram[i]);
        }
    }
    if (got->has_sram && exp->has_sram && memcmp(got->sram, exp->sram, 0x2000)) {
        uint32_t i = 0; while (got->sram[i] == exp->sram[i]) i++;
        FAIL("SRAM %04X: %02X != %02X", i, got->sram[i], exp->sram[i]);
    }
    int pure = !strict && (implflags & SOM_HWMATH_PURE);
    if (cmp_math && !pure && (got->rddiv != exp->rddiv || got->rdmpy != exp->rdmpy || got->wrdiv != exp->wrdiv || got->wrmpya != exp->wrmpya))
        FAIL("math unit state differs: div %04X/%04X mpy %04X/%04X", got->rddiv, exp->rddiv, got->rdmpy, exp->rdmpy);
    /* I/O writes (excluding the WRAM port, whose effect is in WRAM, and the math unit when pure) */
    uint32_t a = 0, b = 0;
    for (;;) {
        while (a < got->nio && (got->io[a].write == 0 || (got->io[a].addr & 0xFFFF) - 0x2180u < 4u || (pure && (got->io[a].addr & 0xFFFF) - 0x4202u < 5u))) a++;
        while (b < exp->nio && (exp->io[b].write == 0 || (exp->io[b].addr & 0xFFFF) - 0x2180u < 4u || (pure && (exp->io[b].addr & 0xFFFF) - 0x4202u < 5u))) b++;
        if (a >= got->nio || b >= exp->nio) break;
        if ((got->io[a].addr & 0xFFFF) != (exp->io[b].addr & 0xFFFF) || got->io[a].val != exp->io[b].val)
            FAIL("I/O write #%u %04X=%02X != %04X=%02X", a, got->io[a].addr & 0xFFFF, got->io[a].val, exp->io[b].addr & 0xFFFF, exp->io[b].val);
        a++; b++;
    }
    if (cmp_io_prefix && b >= exp->nio) return 0;
    if (a < got->nio || b < exp->nio) FAIL("I/O write count differs (got %u/%u, exp %u/%u; next got %04X=%02X exp %04X=%02X)", a, got->nio, b, exp->nio, a < got->nio ? got->io[a].addr & 0xFFFF : 0, a < got->nio ? got->io[a].val : 0, b < exp->nio ? exp->io[b].addr & 0xFFFF : 0, b < exp->nio ? exp->io[b].val : 0);
    return 0;
}

static void arm_events(SomCtx *c, const Cap *cp, int mode) {
    c->ev = cp->ints; c->ev_n = cp->nint; c->ev_next = 0; c->ev_steps = 0; c->last_read_steps = 0; c->ev_mode = cp->nint ? mode : 0; c->run_handlers = mode == 1 && !getenv("SOM_NO_HANDLER");
}
/* Snes9x's blank battery RAM: every byte $60 and the last one $00.  All format-2 captures taken from a fresh start carry exactly
 * this image (913 of 961 sampled), so a format-1 capture, which recorded none, is replayed from it.  Not compared (has_sram stays 0). */
static void sram_blank_image(SomCtx *c) { memset(c->sram, 0x60, 0x2000); c->sram[0x1FFF] = 0; }
/* Exit-address windows.  A replayed capture ends at its own exit address only (the run of a natural capture that passes an address another
 * capture of the routine exits at must not stop there); fuzz and synthetic states have no recorded end, so they stop at any exit address of
 * the routine's captures, in the oracle and in the C alike, and are compared there. */
static uint32_t exit_union[8]; static unsigned n_exit_union; static int exit_use_union; static int exit_only_union; /* every capture of the routine is an exit window: it never returns, only its exit addresses end an oracle run */
static void exit_add(uint32_t a) { for (unsigned i = 0; i < n_exit_union; i++) if (exit_union[i] == a) return; if (n_exit_union < 8) exit_union[n_exit_union++] = a; }
static void ctx_set_exits(SomCtx *c, const Cap *cp) {
    c->exit_need = 1; c->exit_seen = 0;
    if (exit_use_union) { c->nexit = n_exit_union; memcpy(c->exit_addr, exit_union, sizeof exit_union); c->exit_only = exit_only_union; }
    else if (cp->at_exit) { c->nexit = 1; c->exit_addr[0] = cp->exit_pc; c->exit_only = 1; if (cp->exit_n > 1) c->exit_need = cp->exit_n; }
}
static void ctx_from_cap_pre(SomCtx *c, const Cap *cp, const uint8_t *rom, size_t rom_size) {
    som_ctx_init(c, rom, rom_size);
    ctx_set_exits(c, cp);
    memcpy(c->wram, cp->wram_pre, SOM_WRAM_SIZE);
    set_regs(c, &cp->pre);
    c->rp = &cp->rp;
    c->ppu_ob1 = cp->ob1; c->ppu_ob2 = cp->ob2; c->have_ppu_ob = cp->have_ob;
    c->v1log = !cp->has_hw;
    c->wd_unk = cp->has_hw ? 0 : 3; c->wm_unk = !cp->has_hw;
    c->task_mode = cp->task; c->task_s = cp->pre.s;
    if (cp->cont) c->step_limit = (uint64_t)cp->steps * 2 + 2000000; /* replays only: fuzz and synthetic states set their own limit after the copy */
    else { uint64_t l = (uint64_t)cp->steps * 2 + 2000000; if (l > c->step_limit) c->step_limit = l > 40000000 ? 40000000 : l; } /* a window longer than the default 4M steps (capset accepts up to 16M) */
    c->rd_unk = cp->has_hw ? 0 : 0xF; /* a format-1 capture has no snapshot of the math unit */
    if (cp->has_hw) { memcpy(c->dmareg, cp->hw.dma, 0x80); c->wmadd = cp->hw.wmadd; c->wrdiv = cp->hw.wrdiv; c->rddiv = cp->hw.rddiv; c->rdmpy = cp->hw.rdmpy; c->wrmpya = cp->hw.wrmpya; c->hdmaen = cp->hw.hdmaen; }
    if (cp->sram_pre) { memcpy(c->sram, cp->sram_pre, cp->sram_size < sizeof c->sram ? cp->sram_size : sizeof c->sram); c->has_sram = 1; }
    else sram_blank_image(c); /* format-1 capture: no SRAM image was recorded */
}
static void ctx_from_cap_post(SomCtx *c, const Cap *cp, const uint8_t *rom, size_t rom_size) {
    som_ctx_init(c, rom, rom_size);
    memcpy(c->wram, cp->wram_post, SOM_WRAM_SIZE);
    set_regs(c, &cp->post);
    if (cp->sram_post) { memcpy(c->sram, cp->sram_post, cp->sram_size < sizeof c->sram ? cp->sram_size : sizeof c->sram); c->has_sram = 1; }
    c->nio = cp->nwr - cp->wr_from < SOM_MAX_IO ? cp->nwr - cp->wr_from : SOM_MAX_IO;
    for (uint32_t i = 0; i < c->nio; i++) c->io[i] = cp->wr[cp->wr_from + i];
}

/* ---- continuation windows: the compare at the end of each swap-out window and the jump to the state of the resumed task ---- */
enum { CONT_NONE = 0, CONT_VS_SNES = 1, CONT_SNAP = 2, CONT_VS_SNAP = 3 };
typedef struct { Cpu cpu; uint8_t *wram; uint8_t sram[0x8000]; int has_sram; SomIo *io; uint32_t nio; } YSnap;   /* what cmp_ctx reads of a state, kept by the oracle run that stands in for Snes9x */
typedef struct ContRun {
    SomCont vt; const Cap *cp; unsigned idx; int mode, mis, strict; uint32_t live, stack_free, flags; char msg[256];
    struct ContRun *ref; YSnap *ys; unsigned nys; uint8_t *chain, *chain_sram;   /* chain = the Snes9x image the capture's deltas are applied to */
} ContRun;
static SomCtx *cont_exp;   /* scratch expected state for the compare at Y */
static void cont_apply(uint8_t *img, const uint32_t *d, uint32_t n) { for (uint32_t i = 0; i < n; i++) img[d[i] & 0xFFFFFF] = (uint8_t)(d[i] >> 24); }
static void ysnaps_free(ContRun *cr) { for (unsigned i = 0; i < cr->nys; i++) { free(cr->ys[i].wram); free(cr->ys[i].io); } free(cr->ys); cr->ys = NULL; cr->nys = 0; }
static void cont_exp_from_snes(const Cap *cp, unsigned idx, const ContRun *cr, const uint8_t *rom, size_t rom_size) {
    SomCtx *c = cont_exp; const CapCycle *cy = &cp->cyc[idx];
    som_ctx_init(c, rom, rom_size);
    memcpy(c->wram, cr->chain, SOM_WRAM_SIZE);
    set_regs(c, &cy->h.y);
    if (cp->sram_size_c) { memcpy(c->sram, cr->chain_sram, cp->sram_size_c < sizeof c->sram ? cp->sram_size_c : sizeof c->sram); c->has_sram = 1; }
    const uint32_t from = idx ? cp->cyc[idx - 1].nwr : 0;
    c->nio = cy->nwr - from < SOM_MAX_IO ? cy->nwr - from : SOM_MAX_IO;
    for (uint32_t i = 0; i < c->nio; i++) c->io[i] = cp->wr[from + i];
}
static void cont_exp_from_snap(const YSnap *ys, const uint8_t *rom, size_t rom_size) {
    SomCtx *c = cont_exp;
    som_ctx_init(c, rom, rom_size);
    c->cpu = ys->cpu; c->cpu.mem = c;
    memcpy(c->wram, ys->wram, SOM_WRAM_SIZE);
    memcpy(c->sram, ys->sram, sizeof c->sram); c->has_sram = ys->has_sram;
    c->nio = ys->nio; if (ys->nio) memcpy(c->io, ys->io, ys->nio * sizeof *ys->io);
}
static int cont_jump(SomCtx *c, void *u) {
    ContRun *cr = u; const Cap *cp = cr->cp;
    if (cr->idx >= cp->ncyc) return 0;
    const CapCycle *cy = &cp->cyc[cr->idx];
    cont_apply(cr->chain, cy->dy, cy->h.ndy);
    if (cp->sram_size_c) cont_apply(cr->chain_sram, cy->sy, cy->h.nsy);
    if ((cr->mode == CONT_VS_SNES || cr->mode == CONT_VS_SNAP) && !cr->mis) {
        int have = 0;
        if (!cont_exp) cont_exp = malloc(sizeof *cont_exp);
        if (cr->mode == CONT_VS_SNES) { cont_exp_from_snes(cp, cr->idx, cr, c->rom, c->rom_size); have = 1; }
        else if (cr->ref && cr->idx < cr->ref->nys && cr->ref->ys[cr->idx].wram) { cont_exp_from_snap(&cr->ref->ys[cr->idx], c->rom, c->rom_size); have = 1; }
        if (have) {
            char msg[200];
            const int sm = cmp_math, sp = cmp_io_prefix; cmp_math = 0; cmp_io_prefix = 0;
            const int bad = cmp_ctx(c, cont_exp, cr->strict, cr->live, cr->stack_free, cr->flags, cp->pre.s, msg, sizeof msg);
            cmp_math = sm; cmp_io_prefix = sp;
            if (bad) { cr->mis = 1; snprintf(cr->msg, sizeof cr->msg, "at the task switch %u: %s", cr->idx, msg); }
        }
    } else if (cr->mode == CONT_SNAP && cr->idx < cr->nys) {
        YSnap *y = &cr->ys[cr->idx];
        if (!y->wram) y->wram = malloc(SOM_WRAM_SIZE);
        free(y->io); y->io = NULL;
        y->cpu = c->cpu; memcpy(y->wram, c->wram, SOM_WRAM_SIZE); memcpy(y->sram, c->sram, sizeof y->sram); y->has_sram = c->has_sram;
        y->nio = c->nio; if (c->nio) { y->io = malloc(c->nio * sizeof *y->io); memcpy(y->io, c->io, c->nio * sizeof *y->io); }
    }
    if (getenv("SOM_DEBUG")) fprintf(stderr, "CONT jump %u of %u (mode %d) at %02X:%04X S %04X after %llu steps, K at %02X:%04X S %04X%s%s\n", cr->idx + 1, cp->ncyc, cr->mode, c->cpu.k, c->cpu.pc, c->cpu.sp, (unsigned long long)c->ev_steps, cy->h.k.pb, cy->h.k.pc, cy->h.k.s, cr->mis ? " MISMATCH " : "", cr->mis ? cr->msg : "");
    cont_apply(cr->chain, cy->dk, cy->h.ndk);
    if (cp->sram_size_c) cont_apply(cr->chain_sram, cy->sk, cy->h.nsk);
    memcpy(c->wram, cr->chain, SOM_WRAM_SIZE);
    set_regs(c, &cy->h.k);
    if (cp->sram_size_c && c->has_sram) memcpy(c->sram, cr->chain_sram, cp->sram_size_c < sizeof c->sram ? cp->sram_size_c : sizeof c->sram);
    memcpy(c->dmareg, cy->h.khw.dma, 0x80); c->wmadd = cy->h.khw.wmadd; c->wrdiv = cy->h.khw.wrdiv; c->rddiv = cy->h.khw.rddiv; c->rdmpy = cy->h.khw.rdmpy; c->wrmpya = cy->h.khw.wrmpya; c->hdmaen = cy->h.khw.hdmaen;
    c->nio = 0; c->switched = 0; c->unwound = 0;
    cr->idx++;
    c->task_mode = cr->idx < cp->ncyc ? 2 : (cp->endsw ? 1 : 0);
    return 1;
}
static void cont_attach(SomCtx *c, const Cap *cp, ContRun *cr, int mode, ContRun *ref, int strict, uint32_t live, uint32_t stack_free, uint32_t flags) {
    c->cont = NULL;
    if (mode == CONT_SNAP) ysnaps_free(cr);
    cr->idx = 0; cr->mis = 0; cr->msg[0] = 0;
    if (!cp->cont) return;
    if (!cr->chain) { cr->chain = malloc(SOM_WRAM_SIZE); cr->chain_sram = malloc(0x8000); }
    memcpy(cr->chain, cp->wram_pre, SOM_WRAM_SIZE);
    if (cp->sram_pre) memcpy(cr->chain_sram, cp->sram_pre, cp->sram_size_c < 0x8000 ? cp->sram_size_c : 0x8000);
    if (mode == CONT_SNAP) { cr->ys = calloc(cp->ncyc, sizeof *cr->ys); cr->nys = cp->ncyc; }
    cr->vt.user = cr; cr->vt.jump = cont_jump; cr->cp = cp; cr->mode = mode; cr->ref = ref; cr->strict = strict; cr->live = live; cr->stack_free = stack_free; cr->flags = flags;
    c->cont = &cr->vt;
}

/* oracle step limit for a state derived from a capture: long captures (frame waits) need far more than the default */
static uint64_t lim_of(const Cap *cp) { if (cp->steps > 1900000) { uint64_t l = (uint64_t)cp->steps * 2 + 2000000; return l > 40000000 ? 40000000 : l; } uint64_t l = (uint64_t)cp->steps * 2 + 100000; return l < 300000 ? 300000 : l > 4000000 ? 4000000 : l; }

/* a fuzz state is a small change of a real call: it may run longer (a loop count changes), not by orders of magnitude; the states
 * that run away are skipped, so their cost is bounded by this */
static uint64_t fuzz_lim(const Cap *cp) { uint64_t l = (uint64_t)cp->steps * 400 + 20000, m = lim_of(cp); return l < m ? l : m; }

static uint8_t *read_file(const char *p, size_t *n) {
    FILE *f = fopen(p, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END); *n = ftell(f); fseek(f, 0, SEEK_SET);
    uint8_t *b = malloc(*n);
    if (fread(b, 1, *n, f) != *n) { free(b); b = NULL; }
    fclose(f);
    return b;
}


/* Coverage search (capture stream): SOM_DUMP_DIR=dir writes the entry state of every fuzz or synthetic state whose oracle run executed an
 * instruction offset listed in SOM_DUMP_TARGETS (comma separated; empty = any), at most SOM_DUMP_MAX (3) states per offset.  The file is
 * "SDMP" entry A X Y S D P(9 bit) DB, then the 128 KiB of WRAM: captures_r5/dumps2plan.py turns it into a forced Snes9x call. */
static const char *dump_dir; static uint8_t dump_tgt[65536]; static int dump_any; static unsigned dump_cnt[65536], dump_max = 3, dump_n;
static void dump_init(void) {
    dump_dir = getenv("SOM_DUMP_DIR"); if (!dump_dir) return;
    if (getenv("SOM_DUMP_MAX")) dump_max = atoi(getenv("SOM_DUMP_MAX"));
    const char *t = getenv("SOM_DUMP_TARGETS");
    if (!t || !*t) { dump_any = 1; return; }
    char *l = strdup(t); for (char *q = strtok(l, ","); q; q = strtok(NULL, ",")) { unsigned v = atoi(q); if (v < 65536) dump_tgt[v] = 1; } free(l);
}
static void dump_write(const char *path, const SomCtx *pre, uint32_t entry) {
    FILE *f = fopen(path, "wb"); if (!f) return;
    const Cpu *c = &pre->cpu;
    uint16_t p = (c->n << 7) | (c->v << 6) | (c->mf << 5) | (c->xf << 4) | (c->d << 3) | (c->i << 2) | (c->z << 1) | c->c | (c->e << 8);
    uint16_t h[8] = { c->a, c->x, c->y, c->sp, c->dp, p, c->db, 0 };
    uint32_t mg[2] = { 0x504d4453u, entry };
    fwrite(mg, 4, 2, f); fwrite(h, 2, 8, f); fwrite(pre->wram, 1, SOM_WRAM_SIZE, f); fclose(f);
}
/* SOM_DUMP_FAIL=dir: the entry state of every fuzz state on which the C and the oracle disagree, in the same file format (generator stream: a failing
 * state replayed by Snes9x as a forced call says which side is right, and it reproduces the failure without the whole fuzz run). */
static void dump_fail(const SomCtx *pre, uint32_t entry, const char *tag, unsigned it) {
    const char *d = getenv("SOM_DUMP_FAIL"); if (!d) return;
    char path[1024]; snprintf(path, sizeof path, "%s/fail_%06X_%s%u.st", d, entry, tag, it);
    dump_write(path, pre, entry);
}
static void dump_maybe(const SomCtx *pre, const uint8_t *tmpmap, uint32_t size, uint32_t entry, const char *tag, unsigned it) {
    if (!dump_dir || !tmpmap) return;
    int hit = 0;
    for (uint32_t i = 0; i < size && i < 65536; i++) if (tmpmap[i] && (dump_any || dump_tgt[i]) && dump_cnt[i] < dump_max) { hit = 1; dump_cnt[i]++; }
    if (!hit) return;
    char path[1024]; snprintf(path, sizeof path, "%s/d_%06X_%s%u_%u.st", dump_dir, entry, tag, it, dump_n++);
    dump_write(path, pre, entry);
}

/* ---- branch-flip search (coverage search only: SOM_FUZZ_BRFLIP=1 with SOM_DUMP_DIR and SOM_FUZZ_I2S) ----
 * The oracle log of a run says, for every conditional branch it executed, which flag setter decided it and where that setter's operands were loaded
 * from.  An edge (branch, direction) that no oracle run has taken yet is a frontier: the state is changed so that the deciding compare, test or
 * load sees a value that takes the other direction.  Only the oracle's execution decides whether it worked; the tested state is an ordinary one. */
static uint8_t *edgemap;   /* 2 bits per 24-bit address: edge (pc, direction) taken by some oracle run */
static int edge_seen(uint32_t pc, int dir) { return (edgemap[(pc & 0xFFFFFF) >> 2] >> (((pc & 3) << 1) + dir)) & 1; }
static void edge_mark(uint32_t pc, int dir) { edgemap[(pc & 0xFFFFFF) >> 2] |= (uint8_t)(1u << (((pc & 3) << 1) + dir)); }
static void brf_put(SomCtx *pre, const uint8_t *fetchset, int32_t aa, uint16_t v, int wide) {
    if (aa < 0 || (uint32_t)aa >= SOM_WRAM_SIZE || fetchset[aa] || (aa >= 0x0B00 && aa < 0x0B31)) return;
    pre->wram[aa] = v & 0xFF;
    if (wide && (uint32_t)aa + 1 < SOM_WRAM_SIZE && !fetchset[aa + 1]) pre->wram[aa + 1] = v >> 8;
}
static const uint8_t *brf_rom; static size_t brf_rom_size;
/* The value was read from ROM: change the pointer or the index that addressed it so that the read lands on a ROM byte (word) equal to `want`.
 * Positions near the original address are tried first (the data that follows is usually of the same kind). */
static int brf_redirect(SomCtx *pre, const uint8_t *fetchset, const SomProv *pv, uint16_t want, int wide) {
    if (!brf_rom || !pv->valid) return 0;
    const uint32_t bank = pv->ea >> 16;
    if (bank < 0x40 || (bank >= 0x7E && bank < 0xC0)) return 0;
    const uint32_t off0 = ((bank & 0x3F) << 16);
    uint32_t q = 0; int found = 0;
    for (unsigned t = 0; t < 400 && !found; t++) {
        uint32_t cand = (t < 160) ? (uint32_t)((pv->ea & 0xFFFF) + (int)(rnd() % 0x400) - 0x200) & 0xFFFF : rnd() & 0xFFFF;
        const size_t o = (off0 | cand) % brf_rom_size;
        const uint16_t v = brf_rom[o] | (wide ? (uint16_t)brf_rom[(o + 1) % brf_rom_size] << 8 : 0);
        if (v == (wide ? want : (uint16_t)(want & 0xFF))) { q = cand; found = 1; }
    }
    if (!found) return 0;
    if (pv->kind == 1) {   /* direct-page pointer: low, high (and keep the bank byte) */
        const uint16_t np = (uint16_t)(q - pv->iv);
        brf_put(pre, fetchset, pv->ptr, np, 1);
        return 1;
    }
    if (pv->kind == 2) {   /* table index */
        const uint32_t idx = ((bank << 16 | q) - pv->base) & (pv->iw ? 0xFFFFu : 0xFFu);
        if (((bank << 16 | q) - pv->base) > (pv->iw ? 0xFFFFu : 0xFFu)) return 0;
        if (pv->idxsrc >= 0) brf_put(pre, fetchset, pv->idxsrc, (uint16_t)idx, pv->iw);
        else if (pv->idxreg == 1) pre->cpu.x = pv->iw ? idx : (idx & 0xFF);
        else pre->cpu.y = pv->iw ? idx : (idx & 0xFF);
        return 1;
    }
    return 0;
}
/* make the flag that decides branch `b` take the other value; returns 1 when a byte or register was changed */
static int brf_flip(SomCtx *pre, const uint8_t *fetchset, const SomBr *b) {
    static const uint16_t bv[] = { 0, 1, 2, 0x7F, 0x80, 0x81, 0xFF, 0x7FFF, 0x8000, 0x8001, 0xFFFF, 0xFFFE, 0x100, 0x7E, 0x40 };
    const int flag = (b->op >> 6) & 3;           /* 0 N, 1 V, 2 C, 3 Z */
    const int cur = flag == 0 ? b->fn : flag == 1 ? b->fv : flag == 2 ? b->fc : b->fz;
    const uint16_t mem = b->mem, reg = b->reg, top = b->wide ? 0x8000 : 0x80;
    const uint16_t mask = b->wide ? 0xFFFF : 0xFF;
    const int sa = b->src >= 0, ma = b->maddr >= 0;
    if (!sa && b->pv.valid && (b->setk <= 2 || b->setk == 5) && !(b->setk <= 2 && ma && rnd() % 4 == 0)) {   /* the value came from ROM: move the pointer or the index */
        uint16_t want;
        if (b->setk == 5) want = flag == 3 ? (cur ? 0 : (uint16_t)(1 + rnd() % 0xFF)) : flag == 0 ? (cur ? (uint16_t)(rnd() & (mask >> 1)) : (uint16_t)(top | (rnd() & (mask >> 1)))) : (uint16_t)(rnd() & mask);
        else if (flag == 3) want = cur ? (uint16_t)(mem + 1) : mem;
        else if (flag == 2) want = cur ? (mem ? (uint16_t)(mem - 1) : 0) : mem;
        else if (flag == 0) want = (uint16_t)(mem + (rnd() & 1 ? top : (uint16_t)-1));
        else want = bv[rnd() % 15];
        if (brf_redirect(pre, fetchset, &b->pv, want & mask, b->wide)) return 1;
    }
    if (!sa && !ma) {   /* the compared register still holds a value the caller passed: change it */
        if (b->setk > 2) return 0;
        uint16_t v = reg;
        if (b->setk == 5 || flag == 1) return 0;
        if (flag == 3) v = cur ? mem + 1 : mem;
        else if (flag == 2) v = cur ? (mem ? mem - 1 : 0) : mem;
        else v = (uint16_t)(mem + (rnd() & 1 ? top : (uint16_t)-1));
        v &= mask;
        Cpu *c = &pre->cpu;
        if (b->setk == 0) c->a = c->mf ? (c->a & 0xFF00) | (v & 0xFF) : v;
        else if (b->setk == 1) c->x = c->xf ? v & 0xFF : v; else c->y = c->xf ? v & 0xFF : v;
        return 1;
    }
    switch (b->setk) {
    case 0: case 1: case 2: {   /* reg - mem */
        uint16_t vs, vm;
        if (flag == 3) { vs = cur ? mem + 1 + (rnd() % 3 == 0 ? rnd() & 0x7F : 0) : mem; vm = cur ? reg + 1 : reg; }
        else if (flag == 2) {   /* C = reg >= mem: vs is the new register value, vm the new operand */
            vs = cur ? (mem ? (uint16_t)(mem - 1 - (rnd() % 3 == 0 ? rnd() % mem : 0)) : 0) : (uint16_t)(mem + (rnd() % 3 == 0 ? rnd() & 0x7F : 0));
            vm = cur ? (uint16_t)(reg + 1 + (rnd() % 3 == 0 ? rnd() & 0x7F : 0)) : reg;
        }
        else if (flag == 0) { static const int d[] = { 0, 1, -1 }; vs = (uint16_t)(mem + (rnd() & 1 ? top : (uint16_t)d[rnd() % 3])); vm = (uint16_t)(reg + (rnd() & 1 ? top : (uint16_t)d[rnd() % 3])); }
        else { vs = bv[rnd() % 15]; vm = bv[rnd() % 15]; }
        vs &= mask; vm &= mask;
        if (sa && (!ma || rnd() & 1)) brf_put(pre, fetchset, b->src, vs, b->wide); else if (ma) brf_put(pre, fetchset, b->maddr, vm, b->wide);
        return 1;
    }
    case 3: {   /* BIT / AND-style test of reg against the operand */
        if (flag == 3) {
            uint16_t vm = cur ? (uint16_t)(mem | (reg ? reg : (1u << (rnd() % (b->wide ? 16 : 8))))) : (uint16_t)(mem & ~reg), vs = cur ? (uint16_t)(reg | (1u << (rnd() % (b->wide ? 16 : 8)))) : 0;
            if (ma && (!sa || rnd() & 1)) brf_put(pre, fetchset, b->maddr, vm & mask, b->wide); else if (sa) brf_put(pre, fetchset, b->src, vs & mask, b->wide);
        } else if (ma) {
            uint16_t bit = flag == 0 ? top : (uint16_t)(top >> 1);
            brf_put(pre, fetchset, b->maddr, (uint16_t)(mem ^ bit) & mask, b->wide);
        } else return 0;
        return 1;
    }
    case 4: {   /* ADC / SBC: boundary values on either side */
        uint16_t v = bv[rnd() % 15] & mask;
        if (sa && (!ma || rnd() & 1)) brf_put(pre, fetchset, b->src, v, b->wide); else if (ma) brf_put(pre, fetchset, b->maddr, v, b->wide); else return 0;
        return 1;
    }
    case 5: {   /* the result of a load or logic operation */
        uint16_t v;
        if (flag == 3) v = cur ? (uint16_t)(1 + rnd() % 0xFF) : 0;
        else if (flag == 0) v = cur ? (uint16_t)(rnd() & (mask >> 1)) : (uint16_t)(top | (rnd() & (mask >> 1)));
        else v = (uint16_t)rnd() & mask;
        if (b->wide && flag == 3 && cur && rnd() & 1) v <<= 8;
        if (sa) brf_put(pre, fetchset, b->src, v & mask, b->wide); else return 0;
        if (ma && rnd() % 3 == 0) brf_put(pre, fetchset, b->maddr, (flag == 3 && !cur) ? 0 : v & mask, b->wide);
        return 1;
    }
    default: return 0;
    }
}

/* Names in a directory that start with `prefix`, sorted by name (strcmp).  The order readdir() returns is file system specific (ext4 hash order,
 * APFS another) and decides which captures fit under --max-caps and which bases feed the synthetic states, so it must never decide a verdict. */
static int name_cmp(const void *a, const void *b) { return strcmp(*(char *const *)a, *(char *const *)b); }
static char **list_sorted(const char *dirpath, const char *prefix, size_t *n) {
    *n = 0;
    DIR *dir = opendir(dirpath);
    if (!dir) return NULL;
    char **names = NULL; size_t cap = 0; struct dirent *de;
    while ((de = readdir(dir))) {
        if (strncmp(de->d_name, prefix, strlen(prefix))) continue;
        if (*n == cap) { cap = cap ? cap * 2 : 64; names = realloc(names, cap * sizeof *names); }
        names[(*n)++] = strdup(de->d_name);
    }
    closedir(dir);
    if (*n) qsort(names, *n, sizeof *names, name_cmp);
    return names;
}
static void free_names(char **names, size_t n) { for (size_t i = 0; i < n; i++) free(names[i]); free(names); }


/* ---- hardware-state pass ----
 * Fuzz states that change only WRAM never change what the hardware says: the replayed register streams ($2134-$2143 reads, $4016/$4017, $4210-$4213,
 * $4218-$421F), SRAM, DMA channel registers.  A routine that branches on those (controller probes, beam polls, save data) keeps instructions that no
 * WRAM mutation reaches.  This pass runs after the normal fuzz states of a routine that read such state and has not reached every instruction,
 * on a private random sequence (the normal fuzz, synthetic and mutation results of a routine are unchanged).  The oracle and the C routine consume the same
 * changed streams, so it is the same differential test as for any other input; reads of the math unit ($4214-$4217) stay computed. */
static uint64_t hrng_s = 0x2545F4914F6CDD1Dull;
static uint32_t hrnd(void) { hrng_s ^= hrng_s << 13; hrng_s ^= hrng_s >> 7; hrng_s ^= hrng_s << 17; return (uint32_t)(hrng_s >> 11); }
static SomRp *rp_clone(const SomRp *s) {
    SomRp *d = calloc(1, sizeof *d);
    if (!s) return d;
    for (unsigned i = 0; i < 0x300; i++) if (s->n[i]) { d->run[i] = malloc(s->n[i] * sizeof(SomRpRun)); memcpy(d->run[i], s->run[i], s->n[i] * sizeof(SomRpRun)); d->n[i] = s->n[i]; }
    return d;
}
static void rp_free(SomRp *r) { if (!r) return; for (unsigned i = 0; i < 0x300; i++) free(r->run[i]); free(r); }
static void rp_push(SomRp *r, unsigned ix, uint8_t val, uint32_t reps) { r->run[ix] = realloc(r->run[ix], (r->n[ix] + 1) * sizeof(SomRpRun)); r->run[ix][r->n[ix]++] = (SomRpRun){ val, reps }; }
static const uint16_t hw_streams[] = { 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x210, 0x211, 0x212, 0x213, 0x218, 0x219, 0x21A, 0x21B, 0x21C, 0x21D, 0x21E, 0x21F, 0x2F6, 0x2F7 };
static void rp_perturb(SomRp *rp) {
    const unsigned nstreams = sizeof hw_streams / sizeof hw_streams[0];
    unsigned used[32], nused = 0;
    for (unsigned i = 0; i < nstreams; i++) if (rp->n[hw_streams[i]]) used[nused++] = hw_streams[i];
    unsigned nops = 1 + hrnd() % 3;
    while (nops--) {
        unsigned ix = (nused && hrnd() % 5 != 0) ? used[hrnd() % nused] : hw_streams[hrnd() % nstreams];
        if (!rp->n[ix]) { /* a register the capture never read: a few reads, then a steady value */
            unsigned k = 1 + hrnd() % 3;
            while (k--) rp_push(rp, ix, hrnd() & 0xFF, 1 + hrnd() % 6);
            rp_push(rp, ix, hrnd() & 0xFF, 1u << 24);
            continue;
        }
        unsigned k = hrnd() % rp->n[ix];
        switch (hrnd() % 5) {
        case 0: rp->run[ix][k].val ^= (uint8_t)(1u << (hrnd() & 7)); break;
        case 1: rp->run[ix][k].val = hrnd() & 0xFF; break;
        case 2: { /* split a run: the second part reads another value */
            SomRpRun *r = &rp->run[ix][k];
            if (r->reps < 2) { r->val ^= (uint8_t)(1u << (hrnd() & 7)); break; }
            uint32_t a = 1 + hrnd() % (r->reps - 1), b = r->reps - a; uint8_t v = r->val ^ (uint8_t)(1u << (hrnd() & 7));
            rp->run[ix] = realloc(rp->run[ix], (rp->n[ix] + 1) * sizeof(SomRpRun));
            memmove(&rp->run[ix][k + 2], &rp->run[ix][k + 1], (rp->n[ix] - k - 1) * sizeof(SomRpRun));
            rp->run[ix][k].reps = a; rp->run[ix][k + 1] = (SomRpRun){ v, b }; rp->n[ix]++;
            break; }
        case 3: { /* the reads after the recorded ones (a poll that runs on) */
            uint8_t v = rp->run[ix][rp->n[ix] - 1].val; unsigned m = 1 + hrnd() % 3;
            while (m--) { v ^= (uint8_t)(1u << (hrnd() & 7)); rp_push(rp, ix, v, 1 + hrnd() % 8); }
            rp_push(rp, ix, hrnd() % 2 ? v ^ (uint8_t)(1u << (hrnd() & 7)) : v, 1u << 24);
            break; }
        default: { /* one bit forced the same way in every read ("the line stays high for all eight reads") */
            uint8_t bit = (uint8_t)(1u << (hrnd() & 7)); int on = hrnd() & 1;
            for (uint32_t q = 0; q < rp->n[ix]; q++) rp->run[ix][q].val = on ? rp->run[ix][q].val | bit : rp->run[ix][q].val & (uint8_t)~bit;
            break; }
        }
    }
}
static SomRp *hw_rp_cur;
static void hw_mutate(SomCtx *pre, const uint8_t *srdset) {
    SomRp *n = rp_clone(pre->rp);
    if (hrnd() % 8 != 0) rp_perturb(n);
    pre->rp = n; rp_free(hw_rp_cur); hw_rp_cur = n;
    if (hrnd() % 2 == 0) { /* SRAM bytes the run read */
        uint32_t idx[0x2000], ni = 0;
        for (uint32_t i = 0; i < 0x2000; i++) if (srdset[i]) idx[ni++] = i;
        unsigned nm = 1 + hrnd() % 3;
        while (ni && nm--) { uint32_t i = idx[hrnd() % ni]; switch (hrnd() % 4) { case 0: pre->sram[i] ^= (uint8_t)(1u << (hrnd() & 7)); break; case 1: pre->sram[i] = 0; break; case 2: pre->sram[i] = 0xFF; break; default: pre->sram[i] = hrnd() & 0xFF; } }
    }
    if (hrnd() % 4 == 0) { unsigned nm = 1 + hrnd() % 3; while (nm--) pre->dmareg[hrnd() % 0x80] = hrnd() & 0xFF; } /* channel registers the routine reads back */
    if (hrnd() % 8 == 0) pre->hdmaen = hrnd() & 0xFF;
}

/* ---- escalation ladder for states that wait on the beam ----
 * A fuzz or synthetic state that reads the beam registers in another order than the capture (a changed loop count, a callee that polls $4212 from the interpreter) can
 * leave the replayed stream before the wait ends: the original code then spins on the last recorded value, or the deferred delivery lands an interrupt at the wrong poll.
 * The state is repeated under the next delivery rule, oracle and C alike, and compared at the first rule where the original code ends:
 *   1 anchored delivery (interrupt after the replayed read it followed), 2 the $4210/$4212 streams continue as a cycle of the recorded polls, 3 both.
 * A state is still skipped (oracle) or counted as a failure (C) when no rule lets the original code end; the comparison itself is never relaxed. */
static SomRp *rp_extend(const SomRp *s) {
    static const unsigned beam[] = { 0x210, 0x212 };
    if (!s) return NULL;
    SomRp *d = NULL;
    for (unsigned b = 0; b < 2; b++) {
        const unsigned ix = beam[b]; const uint32_t n = s->n[ix];
        if (!n) continue;
        uint32_t copies = 65536 / n; if (copies > 64) copies = 64;
        if (!copies) continue;
        if (!d) d = rp_clone(s);
        d->run[ix] = realloc(d->run[ix], (size_t)n * (copies + 1) * sizeof(SomRpRun));
        for (uint32_t k = 1; k <= copies; k++) memcpy(d->run[ix] + (size_t)n * k, d->run[ix], n * sizeof(SomRpRun));
        d->n[ix] = n * (copies + 1);
    }
    return d;
}
/* a ladder rerun that ends the wait does so within a few thousand steps; one that still runs away is stopped early so that the escalation costs at most about three quarters of the plain run */
static uint64_t ladder_lim(uint64_t l) { return l; }
static void call_marker(const char *m, unsigned it) { if (getenv("SOM_ICALLTRACE")) fprintf(stderr, "--- %s %u\n", m, it); }
/* the ladder switches itself off for a routine on which 24 escalations did not rescue a single state (it is then only a cost) */
static unsigned lad_try, lad_ok;
static int ladder_off(void) { static int v = -1; if (v < 0) v = (getenv("SOM_NO_LADDER") || getenv("SOM_RT_LEGACY")) ? 1 : 0; return v || (lad_try >= 24 && !lad_ok); }
/* rule l (1..3) -> delivery mode (0 = no events) and whether the extended streams apply; returns 0 when the rule cannot differ from rule 0 for this state */
static int ladder_rule(int l, const Cap *cp, const SomRp *rpx, int *mode, int *ext) {
    const int has_ev = cp && cp->nint;
    *ext = l >= 2; *mode = (l == 1 || l == 3) ? 3 : 2;
    if ((l == 1 || l == 3) && !has_ev) return 0;
    if (*ext && !rpx) return 0;
    if (!has_ev) *mode = 0;
    return 1;
}
static void ladder_arm(SomCtx *c, const Cap *cp, int mode, int ext, const SomRp *rpx) {
    if (cp && mode) arm_events(c, cp, mode);
    if (ext) c->rp = rpx;
}
static void ladder_oracle(SomCtx *o, const SomCtx *pre, const Cap *cp, int mode, int ext, const SomRp *rpx, uint8_t *tmpmap, uint32_t entry, uint32_t size, uint64_t limit, uint8_t ret_op, uint16_t entry_sp, int unwinds) {
    memcpy(o, pre, sizeof *o); o->cpu.mem = o; o->nio = 0; o->steps = 0; o->fail = 0; o->hook_impls = 0; o->rdset = NULL;
    if (tmpmap) memset(tmpmap, 0, size);
    o->execmap = tmpmap; o->exec_base = entry; o->exec_len = size; o->step_limit = limit;
    ladder_arm(o, cp, mode, ext, rpx);
    o->allow_unwind = unwinds; som_interp_run(o, ret_op, entry_sp);
    if (cp && mode) som_flush_events(o);
    o->execmap = NULL;
}
static void ladder_impl(const SomImpl *im, SomCtx *g, const SomCtx *pre, const Cap *cp, int mode, int ext, const SomRp *rpx, uint64_t limit, int hook) {
    memcpy(g, pre, sizeof *g); g->cpu.mem = g; g->nio = 0; g->steps = 0; g->fail = 0; g->hook_impls = hook; g->rdset = NULL; g->execmap = NULL; g->step_limit = limit;
    ladder_arm(g, cp, mode, ext, rpx);
    guarded(im, g);
    if (cp && mode) som_flush_events(g);
}

int main(int argc, char **argv) {
    const char *rom_path = NULL, *caps = NULL, *variant = "lift";
    uint64_t spent = 0, spent_fuzz = 0, spent_syn = 0, budget = getenv("SOM_STEP_BUDGET") ? strtoull(getenv("SOM_STEP_BUDGET"), 0, 10) : 40000000ull; /* interpreted instructions allowed for fuzz + synthetic states */
    /* every phase has its own step budget: long captures cannot starve the fuzz; each phase runs at least its floor of states
     * whatever the budget says (SOM_FUZZ_FLOOR / SOM_SYN_FLOOR) */
    unsigned fuzz_floor_env = getenv("SOM_FUZZ_FLOOR") ? atoi(getenv("SOM_FUZZ_FLOOR")) : 200, syn_floor_env = getenv("SOM_SYN_FLOOR") ? atoi(getenv("SOM_SYN_FLOOR")) : 50;
    uint32_t entry = 0, maxcaps = 64, nfuzz = 1000, ninsn = 0, size = 0, nsynth = 0;
    const char *basecaps = NULL;
    uint64_t seed = 1;
    int hook = 0, stop_first = 0, stopped = 0, base_given = 0;
    unsigned load_failed = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--rom")) rom_path = argv[++i];
        else if (!strcmp(argv[i], "--entry")) entry = strtoul(argv[++i], 0, 16);
        else if (!strcmp(argv[i], "--variant")) variant = argv[++i];
        else if (!strcmp(argv[i], "--caps")) caps = argv[++i];
        else if (!strcmp(argv[i], "--max-caps")) maxcaps = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--fuzz")) nfuzz = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--seed")) seed = strtoull(argv[++i], 0, 10);
        else if (!strcmp(argv[i], "--ninsn")) ninsn = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--size")) size = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--hook")) hook = 1;
        else if (!strcmp(argv[i], "--synthetic")) nsynth = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--base-caps")) { basecaps = argv[++i]; base_given = 1; }
        else if (!strcmp(argv[i], "--stop-first")) stop_first = 1; /* mutant runs: stop at the first real state mismatch */
    }
    for (int i = 1; i < argc; i++) if (!strcmp(argv[i], "--list")) {
        for (size_t k = 0; k < som_impl_count(); k++) { const SomImpl *p = som_impl_at(k); printf("%06X %s %d %d %u %u\n", p->addr, p->variant, p->m, p->x, p->size, p->ninsn); }
        return 0;
    }
    if (!rom_path || !entry) { fprintf(stderr, "usage\n"); return 2; }
    rng_s ^= seed * 0x9E3779B97F4A7C15ull;
    size_t rom_size; uint8_t *rom = read_file(rom_path, &rom_size);
    if (!rom) { fprintf(stderr, "rom\n"); return 2; }
    entry = som_norm(entry);
    dump_init();
    const SomImpl *im = som_find_impl(entry, variant);
    if (!im) { printf("{\"entry\":\"%06X\",\"variant\":\"%s\",\"verdict\":\"NO_IMPL\"}\n", entry, variant); return 1; }
    int strict = (im->flags & SOM_STRICT) != 0;
    const uint8_t stub_env = getenv("SOM_STUBCALLS") ? 1 : 0;   /* fuzz states run with every JSR/JSL of the routine abstracted to an immediate return (evidence run, see docs) */
    const SomImpl *const im_main = im;
    if (!size) size = im->size;
    if (!ninsn) ninsn = im->ninsn;

    /* gather captures */
    Cap *cs = NULL; size_t ncs = 0, tainted = 0, capacity = 0;
    if (caps) {
        char *list = strdup(caps);
        for (char *d = strtok(list, ","); d; d = strtok(NULL, ",")) {
            char pre[32]; snprintf(pre, sizeof pre, "cap_%06X_", entry);
            size_t nn; char **names = list_sorted(d, pre, &nn);
            for (size_t ni = 0; ni < nn; ni++) {
                char path[1024]; snprintf(path, sizeof path, "%s/%s", d, names[ni]);
                Cap tmp; memset(&tmp, 0, sizeof tmp);
                if (load_cap(path, &tmp)) { load_failed++; continue; }
                { const uint32_t he = som_norm(tmp.entry); if (he != entry) tmp.aim = som_find_impl(he, variant); }
                if (tmp.switched) { tmp.task = tmp.ret_op == 0x1B ? 1 : 2; tmp.ret_op = im->ret_op; } /* a TASK window stands in for the routine's own return opcode in the oracle */
                if (tmp.cont) { tmp.task = 2; if (tmp.endsw) tmp.ret_op = im->ret_op; } /* fuzz states derived from it end at the first return after the swap, replays jump to the resumed state */
                if (tmp.at_exit) tmp.ret_op = im->ret_op; /* an exit-address window ends at the address (ret opcode 4C is no return); the routine's own return still ends a run that gets there first */
                if (tmp.tainted) { tainted++; free(tmp.wram_pre); free(tmp.wram_post); free(tmp.io); continue; }
                if (ncs >= maxcaps) { free(tmp.wram_pre); free(tmp.wram_post); free(tmp.io); continue; }
                if (ncs == capacity) { capacity = capacity ? capacity * 2 : 16; cs = realloc(cs, capacity * sizeof *cs); }
                cs[ncs++] = tmp;
            }
            free_names(names, nn);
        }
        free(list);
    }
    unsigned fuzz_floor = nfuzz < fuzz_floor_env ? nfuzz : fuzz_floor_env, syn_floor = nsynth < syn_floor_env ? nsynth : syn_floor_env;
    SomCtx *pre = malloc(sizeof *pre), *o = malloc(sizeof *o), *g = malloc(sizeof *g), *snes = malloc(sizeof *snes), *o2 = malloc(sizeof *o2);
    uint8_t *execmap = size ? calloc(size, 1) : NULL;
    /* an instruction counts as covered only by a state whose result was compared with the implementation: the oracle writes into
     * `tmpmap`, merged into `execmap` once the comparison ran (runaways, declared-out-of-domain skips and spliced captures add nothing) */
    uint8_t *tmpmap = size ? calloc(size, 1) : NULL;
    uint8_t *rdset = calloc(SOM_WRAM_SIZE, 1), *fetchset = calloc(SOM_WRAM_SIZE, 1), *wrset = calloc(SOM_WRAM_SIZE, 1);
    uint8_t kset[256]; memset(kset, 0, sizeof kset);
    uint8_t *srdset = calloc(0x2000, 1); uint32_t hw_seen = 0; /* hardware state any oracle run of a capture read (bits as SomCtx.hw_rd_mask) */
    SomRp *corpus_rp[24] = {0};
    char msg[256], first_fail[512] = "";
    unsigned replayed = 0, suspect_skipped = 0, trunc_skipped = 0, forced_skipped = 0, badret_skipped = 0, quirk_skipped = 0, o_pass = 0, o_fail = 0, i_pass = 0, i_fail = 0, io_pass = 0, io_fail = 0;
    /* a state mismatch (the implementation ran to the end and left a different state) is told apart from a crash, a
     * watchdog stop or a declared failure: only mismatches count as evidence that a mutant is detected */
    unsigned i_mis = 0, i_crash = 0, f_mis = 0, f_crash = 0, s_mis = 0;
    uint8_t *cand_union = calloc(SOM_WRAM_SIZE, 1);
    uint32_t cov_traces = 0;
    /* an unwinder captured without the unwind rule (header bit 21) is usable only if its window is the routine's own: the capture
     * ends at an RTS/RTL with S = entry S, so once the routine has dropped its own return address (S above the entry S + return size at
     * an instruction boundary) that end is a return of some later callee, not the routine's: the window is dropped (unwind_dropped) */
    unsigned unwind_dropped = 0;
    /* The unwinding return of a routine can be at another depth than entry S + its own return size: C03F69 pops P, DB and D with PLP, PLB, PLD
     * (4 bytes) and only then runs its RTL, which returns to the caller's caller.  The depth is a fact of the routine's code (table in
     * unwind_pop[]), never inferred from captures; an unwound capture whose S after the call differs is a window of another kind and is dropped. */
    som_unwind_n = 0;
    if (im->flags & SOM_UNWINDS) for (size_t t = 0; t < sizeof unwind_pop / sizeof unwind_pop[0]; t++) if (unwind_pop[t].entry == entry) som_unwind_n = unwind_pop[t].n;
    if (im->flags & SOM_UNWINDS) {
        size_t w = 0;
        const unsigned rsz = im->ret_op == SOM_RTL ? 3 : 2;
        for (size_t k = 0; k < ncs; k++) {
            int drop = 0;
            if (cs[k].unwound && som_unwind_n && (uint16_t)(cs[k].post.s - cs[k].pre.s) != (uint16_t)(rsz + som_unwind_n)) drop = 1; /* ended at another return than the routine's own */
            if (!cs[k].unwound && !cs[k].at_exit) { /* an exit window of an unwinder is the routine's own window: the replay of the original pops past the return address by design */
                if (cs[k].badret) drop = 1;
                else {
                    ctx_from_cap_pre(o, &cs[k], rom, rom_size);
                    arm_events(o, &cs[k], 1);
                    o->allow_unwind = 1; som_interp_run(o, cs[k].ret_op, cs[k].pre.s);
                    som_flush_events(o);
                    if (o->sp_max >= (uint16_t)(cs[k].pre.s + rsz)) drop = 1;
                }
            }
            if (drop) { unwind_dropped++; free(cs[k].wram_pre); free(cs[k].wram_post); free(cs[k].io); continue; }
            cs[w++] = cs[k];
        }
        ncs = w;
    }
    /* A routine with TASK captures (header bit 22) swaps stacks.  A capture of it without the TASK rule that did not come back to the pushed
     * return address (badret) is a task window of the wrong kind: it ended where some other task resumed (e.g. at the routine's own
     * entry as a new task), which neither the oracle nor the C can be asked to follow.  The routine's windows are the TASK ones. */
    {
        int has_task = 0; for (size_t k = 0; k < ncs; k++) if (cs[k].task) has_task = 1;
        if (has_task) {
            size_t w = 0;
            for (size_t k = 0; k < ncs; k++) {
                if (!cs[k].task && cs[k].badret && !cs[k].cont) { unwind_dropped++; free(cs[k].wram_pre); free(cs[k].wram_post); free(cs[k].io); continue; }
                cs[w++] = cs[k];
            }
            ncs = w;
        }
    }
    /* a routine with mode 2 captures (window closed at the first return after the swap) does not stop at the swap: its mode 1 captures
     * (closed at the swap itself) are prefixes of the same runs, and the C code cannot be compared at a point inside straight-line code */
    {
        int has2 = 0; for (size_t k = 0; k < ncs; k++) if (cs[k].task == 2) has2 = 1;
        if (has2) {
            size_t w = 0;
            for (size_t k = 0; k < ncs; k++) {
                if (cs[k].task == 1) { unwind_dropped++; free(cs[k].wram_pre); free(cs[k].wram_post); free(cs[k].io); continue; }
                cs[w++] = cs[k];
            }
            ncs = w;
        }
    }
    /* a forced call whose window closed at another return opcode than the routine's own (an RTL window for an RTS routine, or the reverse) used the wrong calling
     * convention: it says nothing about real callers (the C routine ends at its own return opcode), and fuzz states derived from it would end at the wrong one too */
    if (!ladder_off()) {
        size_t w = 0;
        for (size_t k = 0; k < ncs; k++) {
            if (cs[k].forced && !cs[k].switched && !cs[k].at_exit && cs[k].ret_op != im->ret_op) { unwind_dropped++; free(cs[k].wram_pre); free(cs[k].wram_post); free(cs[k].io); continue; }
            cs[w++] = cs[k];
        }
        ncs = w;
    }
    ContRun cr_l = {0}, cr_o = {0}, cr_d = {0}, cr_g = {0};
    /* learn S at every recorded interrupt (needed by the deferred delivery) from one exact replay per capture */
    for (size_t k = 0; k < ncs; k++) {
        if (!cs[k].nint) continue;
        ctx_from_cap_pre(o, &cs[k], rom, rom_size);
        cont_attach(o, &cs[k], &cr_l, CONT_NONE, NULL, 1, 0, 0, 0);
        arm_events(o, &cs[k], 1);
        o->allow_unwind = 1; som_interp_run(o, cs[k].ret_op, cs[k].pre.s);
        som_flush_events(o);
    }
    for (size_t k = 0; k < ncs && !stopped && (k < 3 || spent < 2 * budget); k++) { /* long routines: the first traces always, more while the step budget lasts */
        Cap *cp = &cs[k];
        im = cp->aim ? cp->aim : im_main;
        replayed++;
        /* a forced call whose window closed at another return opcode than the routine's own (an RTL window for an RTS routine, or the reverse) used the wrong
         * calling convention: it says nothing about real callers, and the C routine cannot end where the window did */
        ctx_from_cap_post(snes, cp, rom, rom_size);
        ctx_from_cap_pre(o, cp, rom, rom_size);
        cont_attach(o, cp, &cr_o, CONT_VS_SNES, NULL, 1, 0, 0, 0);
        arm_events(o, cp, 1); /* exact: each interrupt lands after the instruction count the real run had reached */
        if (tmpmap) memset(tmpmap, 0, size);
        o->execmap = tmpmap; o->exec_base = entry; o->exec_len = size;
        if (getenv("SOM_TRACE_CAP") && strstr(cp->path, getenv("SOM_TRACE_CAP"))) { som_trace_left = getenv("SOM_TRACE_N") ? atoi(getenv("SOM_TRACE_N")) : 4000; fprintf(stderr, "--- oracle trace, capture %s\n", cp->path); }
        o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o, cp->ret_op, cp->pre.s);
        som_trace_left = 0;
        som_flush_events(o);
        spent += o->steps;
        o->execmap = NULL;
        hw_seen |= o->hw_rd_mask;
        if (cp->badret && !((im->flags & SOM_UNWINDS) && cp->unwound)) { /* an unwinder's own unwound capture ends elsewhere by design */
            int bad = o->fail;
            if (!bad) { cmp_math = 0; cmp_io_prefix = cp->io_truncated; bad = cmp_ctx(o, snes, 1, 0, 0, 0, cp->pre.s, msg, sizeof msg); cmp_math = 1; cmp_io_prefix = 0; }
            if (bad) { badret_skipped++; continue; } /* the real run left this call's frame and the oracle cannot follow: not a measurement of the routine */
        }
        if (o->fail && o->s9x_quirk) { quirk_skipped++; continue; } /* the oracle took the hardware's bank carry where Snes9x wraps */
        if (o->fail && cp->suspect) { suspect_skipped++; continue; } /* forced by an older core: spliced runs happen; kept only while the oracle reproduces them */
        if (o->fail && (cp->io_truncated || o->short_replay)) { trunc_skipped++; continue; } /* the old core stopped logging at 4096 events: the hardware reads after that point are unknown, the replay cannot be followed */
        if (o->fail) {
            o_fail++; if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "oracle ran away on %s", cp->path);
            if (getenv("SOM_IODIFF")) io_diverge(o, snes);
            continue;
        }
        cmp_math = 0; cmp_io_prefix = cp->io_truncated;
        int rc_o = cmp_ctx(o, snes, 1, 0, 0, 0, cp->pre.s, msg, sizeof msg);
        cmp_math = 1; cmp_io_prefix = 0;
        if (!rc_o && cr_o.mis) { rc_o = 1; snprintf(msg, sizeof msg, "%s", cr_o.msg); }
        if (rc_o && cp->suspect) { suspect_skipped++; continue; }
        if (rc_o && o->s9x_quirk) { quirk_skipped++; continue; }
        if (rc_o && o->ob_unknown && !cp->have_ob) { quirk_skipped++; if (getenv("SOM_DEBUG")) fprintf(stderr, "skipped: write-only PPU register read without a latch (%s)\n", cp->path); continue; } /* the oracle read a write-only PPU register and the capture has no open-bus latch: not a measurement */
        if (rc_o) {
            o_fail++; if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "oracle vs Snes9x %s: %s", cp->path, msg); if (getenv("SOM_LISTFAIL")) fprintf(stderr, "LISTFAIL oracle vs Snes9x %s: %s\n", cp->path, msg);
        } else o_pass++;
        SomCtx *expect = snes;
        int impl_mode = 2; /* the delivery mode of the C run: the one the original code needed to follow the real run */
        if (cp->nint && !rc_o) {
            /* the C routine cannot be interrupted between its statements: it is compared with the original code run under the
             * same deferred delivery (interrupts land when the code waits, the rest after the return) */
            ctx_from_cap_pre(o, cp, rom, rom_size);
            cont_attach(o, cp, &cr_d, CONT_SNAP, NULL, 1, 0, 0, 0);
            arm_events(o, cp, 2);
            o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o, cp->ret_op, cp->pre.s);
            som_flush_events(o);
            spent += o->steps;
            if (o->fail && !getenv("SOM_NO_ANCHOR")) { /* the deferred delivery drifted away from the real run: anchor each interrupt to the replayed read it followed */
                ctx_from_cap_pre(o, cp, rom, rom_size);
                cont_attach(o, cp, &cr_d, CONT_SNAP, NULL, 1, 0, 0, 0);
                arm_events(o, cp, 3);
                o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o, cp->ret_op, cp->pre.s);
                som_flush_events(o);
                spent += o->steps;
                impl_mode = 3;
            }
            if (o->fail) { o_fail++; o_pass--; if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "deferred oracle ran away on %s", cp->path); continue; }
            expect = o;
        }
        ctx_from_cap_pre(g, cp, rom, rom_size);
        cont_attach(g, cp, &cr_g, expect == snes ? CONT_VS_SNES : CONT_VS_SNAP, &cr_d, strict, im->live, im->stack_free, im->flags);
        arm_events(g, cp, impl_mode);
        g->hook_impls = hook;
        guarded(im, g);
        som_flush_events(g);
        if (g->fail && (g->fail != 3 || cr_g.idx > 0) && cp->nint && impl_mode == 2 && !rc_o && !getenv("SOM_NO_ANCHOR") && !ladder_off()) {
            /* the C run lost the deferred delivery (a wait loop in a callee that the interpreter runs while the C statements before it consumed the
             * recorded reads differently): both sides are repeated under the anchored delivery, the one the original code needed in the same position */
            ctx_from_cap_pre(o2, cp, rom, rom_size);
            arm_events(o2, cp, 3);
            o2->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o2, cp->ret_op, cp->pre.s);
            som_flush_events(o2);
            spent += o2->steps;
            if (!o2->fail) {
                ctx_from_cap_pre(g, cp, rom, rom_size);
                arm_events(g, cp, 3);
                g->hook_impls = hook;
                guarded(im, g);
                som_flush_events(g);
                if (!g->fail) { SomCtx *t = o; o = o2; o2 = t; expect = o; }
            }
        }
        if (g->fail == 3 && cp->forced) { forced_skipped++; continue; } /* a forced call chose an input outside the domain the C declares: says nothing about real callers */
        if (g->fail) { i_fail++; i_crash++; if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "impl failed (code %d, pc %02X:%04X) %s", g->fail, g->cpu.k, g->cpu.pc, cp->path); continue; }
        if (execmap) for (uint32_t i = 0; i < size; i++) execmap[i] |= tmpmap[i];
        cmp_math = 0; cmp_io_prefix = cp->io_truncated && expect == snes;
        int rc_i = cmp_ctx(g, expect, strict, im->live, im->stack_free, im->flags, cp->pre.s, msg, sizeof msg);
        cmp_math = 1; cmp_io_prefix = 0;
        if (!rc_i && cr_g.mis) { rc_i = 1; snprintf(msg, sizeof msg, "%s", cr_g.msg); }
        if (rc_i) {
            i_fail++; i_mis++; if (stop_first) stopped = 1;
            if (!first_fail[0]) { snprintf(first_fail, sizeof first_fail, "impl vs Snes9x %s: %s", cp->path, msg); ctx_from_cap_pre(pre, cp, rom, rom_size); dump_pair("trace", pre, g, expect); }
        } else i_pass++;
    }
    if (execmap) for (uint32_t i = 0; i < size; i++) cov_traces += execmap[i];
    unsigned exit_caps = 0, hw_states = 0;
    for (size_t k = 0; k < ncs; k++) if (cs[k].at_exit) { exit_caps++; exit_add(cs[k].exit_pc); }
    if (!getenv("SOM_STEP_BUDGET")) { /* the default budget follows the longest capture: windows of millions of steps cannot fit a fixed 40M */
        uint64_t mx = 0; for (size_t k = 0; k < ncs; k++) if (cs[k].steps > mx) mx = cs[k].steps;
        if (mx > 1900000) { uint64_t b = 40000000ull + 300 * mx; if (b > 6000000000ull) b = 6000000000ull; if (b > budget) budget = b; }
    }
    exit_use_union = n_exit_union > 0; exit_only_union = exit_caps > 0 && exit_caps == ncs; /* from here on every state stops at the exit addresses of the routine's exit-window captures */
    /* fuzz around the captured states */
    unsigned f_pass = 0, f_fail = 0, f_skip = 0;
    /* coverage-guided corpus: a fuzz state that made the original code execute an instruction no earlier state reached is kept,
     * and half of the later states are mutations of the kept ones (so a branch that needs several coordinated bytes is found
     * in steps).  Only the original code's execution (the oracle) decides what is new. */
    enum { CORPUS_MAX = 24 };
    /* the routine's own code bytes: compare constants and masks live there, so they are the values a branch condition needs */
    uint8_t kconst[4096]; unsigned nk = 0;
    if ((entry >> 16) >= 0xC0) for (uint32_t i = 0; i < size && nk < sizeof kconst; i++) { uint32_t off = (entry - 0xC00000u) + i; kconst[nk++] = rom[off % rom_size]; }
    SomCtx *corpus[CORPUS_MAX] = {0}; unsigned corpus_cap[CORPUS_MAX], ncorpus = 0, corpus_next = 0;
    /* the planned states run first; while states are still adding coverage in the last FUZZ_TAIL iterations the run goes on, up to
     * three times the plan (a routine whose coverage has levelled off costs nothing extra) */
    const unsigned FUZZ_TAIL = 600; unsigned last_gain = 0;
    const int i2s_env = dump_dir && getenv("SOM_FUZZ_I2S");
    const int brf_env = i2s_env && getenv("SOM_FUZZ_BRFLIP");
    int i2s = i2s_env, brf = brf_env; /* pass 2 (directed) turns both on for a routine whose instructions are not all reached */
    static SomBr brl[SOM_BRLOG_MAX], brl2[SOM_BRLOG_MAX]; static SomCmp cl2[SOM_CMPLOG_MAX];
    if (brf_env && !edgemap) edgemap = calloc(1u << 22, 1);
    brf_rom = rom; brf_rom_size = rom_size;
    unsigned hw_n = 0, dir_n = 0, dir_states = 0; uint64_t rng_saved = 0;
    for (int pass = 0; pass < 3; pass++) {
    if (pass == 2) {
        /* the directed pass: compare-guided and branch-flip mutations (the covsearch machinery) for a routine that still has instructions no state executed.  It runs after the
         * normal, hardware and synthetic-free passes on a private random sequence, so a routine that is fully covered before it keeps its evidence unchanged. */
        uint32_t cov_now = 0; if (execmap) for (uint32_t i = 0; i < size; i++) cov_now += execmap[i];
        const char *de = getenv("SOM_DIRFUZZ");
        if (de) dir_n = (unsigned)atoi(de);
        else if (cov_now < ninsn && nfuzz && !getenv("SOM_RT_LEGACY")) dir_n = nfuzz < 3000 ? nfuzz : 3000;
        if (!dir_n || stopped || !ncs) break;
        i2s = 1; brf = 1; if (!edgemap) edgemap = calloc(1u << 22, 1);
        rng_saved = rng_s; rng_s = 0xD1B54A32D192ED03ull ^ (seed * 0x9E3779B97F4A7C15ull);
        for (unsigned q = 0; q < CORPUS_MAX; q++) { rp_free(corpus_rp[q]); corpus_rp[q] = NULL; }
        ncorpus = 0; corpus_next = 0; last_gain = 0;
    }
    if (pass == 1) {
        /* the hardware-state pass: only for a routine that read replayed hardware, SRAM or DMA state and has not executed all its instructions yet */
        uint32_t cov_now = 0; if (execmap) for (uint32_t i = 0; i < size; i++) cov_now += execmap[i];
        const char *hwe = getenv("SOM_HWFUZZ");
        if (hwe) hw_n = (unsigned)atoi(hwe);
        else if (hw_seen && cov_now < ninsn && nfuzz) hw_n = nfuzz < 1500 ? nfuzz : 1500;
        if (!hw_n || stopped || !ncs) continue;
        rng_saved = rng_s; rng_s = hrng_s ^ (seed * 0x9E3779B97F4A7C15ull); /* private sequence: the synthetic states that follow are unchanged */
        for (unsigned q = 0; q < CORPUS_MAX; q++) { rp_free(corpus_rp[q]); corpus_rp[q] = NULL; }
        ncorpus = 0; corpus_next = 0; last_gain = 0;
    }
    for (unsigned it = pass ? (unsigned)ncs : 0; ncs && !stopped && (pass ? (it < ncs + (pass == 2 ? dir_n : hw_n) && spent_fuzz < 4 * budget) : ((it < nfuzz || (it < 3 * nfuzz && ((it - last_gain < FUZZ_TAIL && it >= ncs) || (f_pass < 200 && !ladder_off())))) && (spent_fuzz < budget || it < fuzz_floor))); it++) {
        if (pass == 1) hw_states++; else if (pass == 2) dir_states++;
        Cap *cp = &cs[it % ncs];
        int from_corpus = it >= ncs && ncorpus && rnd() % 2 == 0;
        unsigned cidx = from_corpus ? rnd() % ncorpus : 0;
        if (from_corpus) cp = &cs[corpus_cap[cidx]];
        im = cp->aim ? cp->aim : im_main;
        if (from_corpus) { memcpy(pre, corpus[cidx], sizeof *pre); pre->cpu.mem = pre; } else ctx_from_cap_pre(pre, cp, rom, rom_size);
        if (it >= ncs) {
            /* learn the read set of the unmutated state once per capture, then mutate it */
            memset(rdset, 0, SOM_WRAM_SIZE); memset(fetchset, 0, SOM_WRAM_SIZE); memset(wrset, 0, SOM_WRAM_SIZE);
            if (from_corpus) { memcpy(o, pre, sizeof *o); o->cpu.mem = o; o->nio = 0; o->steps = 0; o->fail = 0; o->hook_impls = 0; o->execmap = NULL; o->step_limit = lim_of(cp); }
            else ctx_from_cap_pre(o, cp, rom, rom_size);
            arm_events(o, cp, 2);
            o->rdset = rdset; o->fetchset = fetchset; o->wrset = wrset; o->kset = kset; o->srdset = srdset; memset(srdset, 0, 0x2000); o->hw_rd_mask = 0;
            SomCmp cl[SOM_CMPLOG_MAX]; unsigned ncl = 0;
            if (i2s) { o->cmplog = cl; o->ncmp = 0; o->lr[0] = o->lr[1] = -1; o->src[0] = o->src[1] = o->src[2] = -1; }
            if (brf) { som_shadow_reset(); o->brlog = brl; o->nbr = 0; memset(&o->lastset, 0, sizeof o->lastset); o->lastset.setk = 6; o->lastset.maddr = o->lastset.src = -1; }
            call_marker("learn", it);
            o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o, cp->ret_op, cp->pre.s);
            spent_fuzz += o->steps;
            o->rdset = NULL; o->fetchset = NULL; o->wrset = NULL; o->kset = NULL; o->srdset = NULL; hw_seen |= o->hw_rd_mask;
            if (i2s) { ncl = o->ncmp; o->cmplog = NULL; }
            SomBr *front[SOM_BRLOG_MAX]; unsigned nfront = 0, nfront_in = 0;
            if (brf) {
                o->brlog = NULL;
                for (uint32_t q = 0; q < o->nbr; q++) {
                    const SomBr *bq = &brl[q];
                    int dup = 0; for (unsigned w = 0; w < nfront && !dup; w++) dup = front[w]->pc == bq->pc;
                    if (!edge_seen(bq->pc, !bq->taken) && !dup && bq->setk != 6) {
                        front[nfront++] = (SomBr *)bq;
                    }
                }
                for (uint32_t q = 0; q < o->nbr; q++) edge_mark(brl[q].pc, brl[q].taken);
                /* frontier branches inside the routine first */
                for (unsigned w = 0; w < nfront; w++) {
                    uint32_t pn = som_norm(front[w]->pc);
                    if (pn >= entry && pn - entry < size) { SomBr *t = front[nfront_in]; front[nfront_in] = front[w]; front[w] = t; nfront_in++; }
                }
            }
            uint32_t cand[8192], nc = 0;
            for (uint32_t i = 0; i < SOM_WRAM_SIZE && nc < 8192; i++) if (rdset[i] && !fetchset[i] && !(i >= 0x0B00 && i < 0x0B31)) cand[nc++] = i; /* code decompressed to $7E:8000-D6D2 at boot: the bytes this run fetched as instructions are never mutated, data read there is */
            /* bytes the original code writes: a routine must produce the same result whatever those bytes held before (a dropped store
             * of the value they already held is otherwise invisible); mixed in at a low rate, as they are often far more than the read set */
            uint32_t nread = nc;
            for (uint32_t i = 0; i < SOM_WRAM_SIZE && nc < 8192 && !getenv("SOM_NO_WRSET"); i++) if (wrset[i] && !rdset[i] && !fetchset[i] && !(i >= 0x0B00 && i < 0x0B31)) cand[nc++] = i;
            /* coverage search only (SOM_FUZZ_FILL=1, captures_r5/covsearch.py): a strided fill of up to 64 bytes starting at a byte the run read,
             * with one value (0, $FF, a compare constant or a random byte): "every slot of a table is taken", "the table is empty" */
            if (dump_dir && getenv("SOM_FUZZ_FILL") && nc && rnd() % 3 == 0) {
                static const unsigned strides[] = { 1, 2, 3, 4, 5, 6, 8, 10, 12, 16, 32 };
                uint32_t a0 = cand[rnd() % nc]; unsigned st = strides[rnd() % 11], cnt = 2 + rnd() % 63; uint8_t v;
                switch (rnd() % 4) { case 0: v = 0; break; case 1: v = 0xFF; break; case 2: v = nk ? kconst[rnd() % nk] : 1; break; default: v = rnd() & 0xFF; }
                unsigned back = rnd() % 4 == 0 ? rnd() % 16 : 0;
                for (unsigned q = 0; q < cnt; q++) { uint32_t aa = a0 - back + (uint32_t)q * st; if (aa < SOM_WRAM_SIZE && !fetchset[aa] && !(aa >= 0x0B00 && aa < 0x0B31)) pre->wram[aa] = v; }
            }
            if (dump_dir && getenv("SOM_FUZZ_FILL") && rnd() % 5 == 0) { switch (rnd() % 4) { case 0: pre->cpu.v ^= 1; break; case 1: pre->cpu.n ^= 1; break; case 2: pre->cpu.z ^= 1; break; default: pre->cpu.c ^= 1; } }  /* flags are inputs too: CMP leaves V alone, callers pass it */
            if (dump_dir && getenv("SOM_FUZZ_FILL") && rnd() % 4 == 0) {   /* a register at a boundary value: counts that are zero, one, full */
                static const uint16_t sp[] = { 0, 0, 1, 2, 3, 4, 8, 0x10, 0x20, 0x80, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF };
                uint16_t v = sp[rnd() % 15];
                switch (rnd() % 3) { case 0: pre->cpu.a = pre->cpu.mf ? (pre->cpu.a & 0xFF00) | (v & 0xFF) : v; break; case 1: pre->cpu.x = v; break; default: pre->cpu.y = v; }
            }
            /* input-to-state (SOM_FUZZ_I2S=1): a compare the run executed shows which value the other side needs; write it into the WRAM bytes the
             * compared register was loaded from, or into the operand's bytes, (+0, +1, -1 for the two sides of a range check) */
            if (i2s && ncl) {
                unsigned nops = 1 + rnd() % 3;
                for (unsigned q = 0; q < nops; q++) {
                    const SomCmp *e = &cl[rnd() % ncl];
                    int dlt = (int)(rnd() % 3) - 1;
                    uint32_t aa; uint16_t v;
                    if (e->kind == 4 || rnd() % 5 == 0) {   /* arithmetic (signed overflow, carry): boundary values on either side */
                        static const uint16_t bv[] = { 0, 1, 2, 0x7F, 0x80, 0x81, 0xFF, 0x7FFF, 0x8000, 0x8001, 0xFFFF, 0xFFFE, 0x100, 0x7E, 0x40 };
                        int32_t tgt = (rnd() & 1 && e->src >= 0) ? e->src : e->maddr;
                        if (tgt < 0) tgt = e->src >= 0 ? e->src : e->maddr;
                        if (tgt < 0) continue;
                        aa = (uint32_t)tgt; v = bv[rnd() % 15];
                        if (aa >= SOM_WRAM_SIZE || fetchset[aa] || (aa >= 0x0B00 && aa < 0x0B31)) continue;
                        pre->wram[aa] = v & 0xFF;
                        if (e->wide && aa + 1 < SOM_WRAM_SIZE && !fetchset[aa + 1]) pre->wram[aa + 1] = v >> 8;
                        continue;
                    }
                    if (e->kind == 3) {
                        if (e->maddr < 0 && e->src < 0) continue;
                        if (rnd() & 1 && e->maddr >= 0) { aa = e->maddr; v = e->reg | (rnd() & 1 ? e->mem : 0); }
                        else if (e->src >= 0) { aa = e->src; v = rnd() & 1 ? e->mem | e->reg : (uint16_t)~e->mem; }
                        else continue;
                    } else if (rnd() & 1 && e->src >= 0) { aa = e->src; v = (uint16_t)(e->mem + dlt); }
                    else if (e->maddr >= 0) { aa = e->maddr; v = (uint16_t)(e->reg + dlt); }
                    else if (e->src >= 0) { aa = e->src; v = (uint16_t)(e->mem + dlt); }
                    else continue;
                    if (aa >= SOM_WRAM_SIZE || fetchset[aa] || (aa >= 0x0B00 && aa < 0x0B31)) continue;
                    pre->wram[aa] = v & 0xFF;
                    if (e->wide && aa + 1 < SOM_WRAM_SIZE && !fetchset[aa + 1]) pre->wram[aa + 1] = v >> 8;
                }
            }
            unsigned nm = 1 + rnd() % 6;
            if (rnd() % 8 == 0) nm += rnd() % 12;
            for (unsigned m = 0; m < nm && nc; m++) {
                uint32_t a = (nread < nc && (rnd() % 3 == 0 || !nread)) ? cand[nread + rnd() % (nc - nread)] : cand[rnd() % (nread ? nread : nc)];
                switch (rnd() % 10) {
                case 8: case 9: {
                    unsigned pick = nk ? rnd() % (nk + 64) : 64;
                    if (pick < nk) { pre->wram[a] = kconst[pick] + (int)(rnd() % 3) - 1; break; }
                    for (unsigned t = 0; t < 256; t++) { unsigned v = (rnd() & 0xFF); if (kset[v]) { pre->wram[a] = v + (int)(rnd() % 3) - 1; break; } }  /* operand bytes of the callees too */
                    break;
                }
                case 0: pre->wram[a] = rnd() & 0xFF; break;
                case 1: pre->wram[a] ^= 1u << (rnd() & 7); break;
                case 2: pre->wram[a]++; break;
                case 3: pre->wram[a]--; break;
                case 4: pre->wram[a] = 0; break;
                case 5: pre->wram[a] = 0xFF; break;
                case 6: pre->wram[a] = pre->wram[cand[rnd() % nc]]; break;  /* equal bytes: compares and indexes that pair two fields */
                default: pre->wram[a] += (int)(rnd() % 17) - 8; break;
                }
            }
            if (rnd() % 4 == 0) { pre->cpu.a = (pre->cpu.mf ? (pre->cpu.a & 0xFF00) | (rnd() & 0xFF) : rnd() & 0xFFFF); }
            if (strict) {
                if (rnd() % 6 == 0) { pre->cpu.x = pre->cpu.xf ? rnd() & 0xFF : rnd() & 0xFFFF; }
                if (rnd() % 6 == 0) { pre->cpu.y = pre->cpu.xf ? rnd() & 0xFF : rnd() & 0xFFFF; }
            } else {
                /* index registers stay inside the range seen in the traces (the contract's input domain) */
                if (rnd() % 3 == 0) { const Cap *t1 = &cs[rnd() % ncs]; pre->cpu.x = t1->pre.x; }
                if (rnd() % 3 == 0) { const Cap *t1 = &cs[rnd() % ncs]; pre->cpu.y = t1->pre.y; }
            }
            if (rnd() % 5 == 0) pre->cpu.c = rnd() & 1;
            if (brf && nfront && rnd() % 4 != 0) {   /* directed: flip one or two frontier branches (the ones in the routine first) */
                unsigned nflip = 1 + (rnd() % 4 == 0);
                for (unsigned q = 0; q < nflip; q++) {
                    unsigned pick = (nfront_in && rnd() % 3 != 0) ? rnd() % nfront_in : rnd() % nfront;
                    brf_flip(pre, fetchset, front[pick]);
                }
            }
            if (pre->cpu.xf) { pre->cpu.x &= 0xFF; pre->cpu.y &= 0xFF; } /* X/Y high bytes are zero while the index registers are 8 bit */
            if (pass == 1) hw_mutate(pre, srdset);
        }
        pre->stub_calls = stub_env;
        if (tmpmap) memset(tmpmap, 0, size);
        memcpy(o, pre, sizeof *o); o->cpu.mem = o; o->nio = 0; o->steps = 0; o->fail = 0; o->hook_impls = 0; o->rdset = NULL; o->execmap = tmpmap; o->exec_base = entry; o->exec_len = size; o->step_limit = fuzz_lim(cp);
        arm_events(o, cp, 2);
        if (brf) { som_shadow_reset(); o->cmplog = cl2; o->ncmp = 0; o->lr[0] = o->lr[1] = -1; o->src[0] = o->src[1] = o->src[2] = -1; o->brlog = brl2; o->nbr = 0; memset(&o->lastset, 0, sizeof o->lastset); o->lastset.setk = 6; o->lastset.maddr = o->lastset.src = -1; }
        if (getenv("SOM_TRACE_FUZZ") && (unsigned)atoi(getenv("SOM_TRACE_FUZZ")) == it) { som_trace_left = getenv("SOM_TRACE_N") ? atoi(getenv("SOM_TRACE_N")) : 4000; fprintf(stderr, "--- oracle trace, fuzz %u\n", it); if (getenv("SOM_PEEK")) { const unsigned pk = (unsigned)strtoul(getenv("SOM_PEEK"), 0, 16); fprintf(stderr, "PEEK %05X:", pk); for (unsigned q = 0; q < 16; q++) fprintf(stderr, " %02X", o->wram[(pk + q) & 0x1FFFF]); fprintf(stderr, "\n"); } }
        call_marker("oracle", it);
        o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; som_interp_run(o, cp->ret_op, cp->pre.s);
        som_trace_left = 0;
        som_flush_events(o);
        spent_fuzz += o->steps;
        o->execmap = NULL;
        unsigned egain = 0;
        if (brf) {
            o->cmplog = NULL; o->brlog = NULL;
            if (!o->fail) for (uint32_t q = 0; q < o->nbr; q++) if (!edge_seen(brl2[q].pc, brl2[q].taken)) { edge_mark(brl2[q].pc, brl2[q].taken); egain++; }
        }
        int fz_mode = 2, fz_ext = 0; SomRp *rpx = NULL; int rpx_done = 0;
        if (o->fail && !ladder_off()) {
            lad_try++;
            for (int l = 1; l <= 3 && o->fail; l++) {
                int md, ex;
                if (l >= 2 && !rpx_done) { rpx = rp_extend(pre->rp); rpx_done = 1; }
                if (!ladder_rule(l, cp, rpx, &md, &ex)) continue;
                ladder_oracle(o2, pre, cp, md, ex, rpx, tmpmap, entry, size, ladder_lim(fuzz_lim(cp)), cp->ret_op, cp->pre.s, (im->flags & SOM_UNWINDS) != 0);
                spent_fuzz += o2->steps;
                if (!o2->fail) { SomCtx *t = o; o = o2; o2 = t; fz_mode = md; fz_ext = ex; lad_ok++; }
            }
        }
        if (o->fail) { f_skip++; rp_free(rpx); continue; }
        dump_maybe(pre, tmpmap, size, entry, "f", it);
        memcpy(g, pre, sizeof *g); g->cpu.mem = g; g->nio = 0; g->steps = 0; g->fail = 0; g->hook_impls = hook; g->rdset = NULL; g->execmap = NULL; g->step_limit = lim_of(cp);
        ladder_arm(g, cp, fz_mode, fz_ext, rpx);
        if (getenv("SOM_TRACE_FUZZ_IMPL") && (unsigned)atoi(getenv("SOM_TRACE_FUZZ_IMPL")) == it) { som_trace_left = getenv("SOM_TRACE_N") ? atoi(getenv("SOM_TRACE_N")) : 4000; fprintf(stderr, "--- impl trace, fuzz %u\n", it); if (getenv("SOM_PEEK")) { const unsigned pk = (unsigned)strtoul(getenv("SOM_PEEK"), 0, 16); fprintf(stderr, "PEEK-IMPL %05X:", pk); for (unsigned q = 0; q < 16; q++) fprintf(stderr, " %02X", g->wram[(pk + q) & 0x1FFFF]); fprintf(stderr, "\n"); } }
        call_marker("impl", it);
        guarded(im, g);
        som_trace_left = 0;
        som_flush_events(g);
        if (g->fail && g->fail != 3 && !ladder_off()) {   /* the C run lost the wait that the oracle ended: both sides under the next rule */
            lad_try++;
            for (int l = 1; l <= 3 && g->fail && g->fail != 3; l++) {
                int md, ex;
                if (l >= 2 && !rpx_done) { rpx = rp_extend(pre->rp); rpx_done = 1; }
                if (!ladder_rule(l, cp, rpx, &md, &ex) || (md == fz_mode && ex == fz_ext) || (ex < fz_ext)) continue;
                ladder_oracle(o2, pre, cp, md, ex, rpx, tmpmap, entry, size, ladder_lim(fuzz_lim(cp)), cp->ret_op, cp->pre.s, (im->flags & SOM_UNWINDS) != 0);
                spent_fuzz += o2->steps;
                if (o2->fail) continue;
                ladder_impl(im, g, pre, cp, md, ex, rpx, ladder_lim(lim_of(cp)), hook);
                { SomCtx *t = o; o = o2; o2 = t; fz_mode = md; fz_ext = ex; if (!g->fail) lad_ok++; }
            }
        }
        rp_free(rpx); rpx = NULL;
        if (g->fail == 3) { f_skip++; continue; }   /* implementation declared the input out of its domain */
        if (execmap) {
            uint32_t gain = 0;
            for (uint32_t i = 0; i < size; i++) if (tmpmap[i] && !execmap[i]) { execmap[i] = 1; gain++; }
            if (gain) last_gain = it;
            if ((gain || (egain && rnd() % 2)) && it >= ncs) {   /* new instructions (or, in the branch-flip search, a new branch direction): keep the state */
                unsigned slot = ncorpus < CORPUS_MAX ? ncorpus++ : (corpus_next++ % CORPUS_MAX);
                if (!corpus[slot]) corpus[slot] = malloc(sizeof *pre);
                memcpy(corpus[slot], pre, sizeof *pre); corpus_cap[slot] = (unsigned)(cp - cs);
                if (pass == 1) { rp_free(corpus_rp[slot]); corpus_rp[slot] = rp_clone(pre->rp); corpus[slot]->rp = corpus_rp[slot]; }
            }
        }
        if (g->fail) { f_fail++; f_crash++; if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "fuzz %u (%s): impl failed (code %d, pc %02X:%04X S %04X)", it, cp->path, g->fail, g->cpu.k, g->cpu.pc, g->cpu.sp); continue; }
        if (getenv("SOM_TRACE_FUZZ") && (unsigned)atoi(getenv("SOM_TRACE_FUZZ")) == it) fprintf(stderr, "FZEND oracle fail %d steps %llu pc %02X:%04X S %04X mode %d ext %d | impl fail %d steps %llu pc %02X:%04X S %04X\n", o->fail, (unsigned long long)o->steps, o->cpu.k, o->cpu.pc, o->cpu.sp, fz_mode, fz_ext, g->fail, (unsigned long long)g->steps, g->cpu.k, g->cpu.pc, g->cpu.sp);
        if (cmp_ctx(g, o, strict, im->live, im->stack_free, im->flags, cp->pre.s, msg, sizeof msg)) {
            f_fail++; f_mis++; if (stop_first) stopped = 1; if (getenv("SOM_LISTFAIL")) fprintf(stderr, "LISTFAIL fuzz %u: %s\n", it, msg); dump_fail(pre, entry, "f", it);
            if (!first_fail[0]) { snprintf(first_fail, sizeof first_fail, "fuzz %u (%s): %s", it, cp->path, msg); dump_pair("fuzz", pre, g, o);
                if (getenv("SOM_DEBUG")) { SomCtx *t = malloc(sizeof *t); memcpy(t, pre, sizeof *t); t->cpu.mem = t; t->nio = 0; t->steps = 0; t->fail = 0; t->hook_impls = 0; t->rdset = NULL; t->execmap = NULL; t->wlog_n = 0; t->wlog_cap = 40; t->wlog = malloc(40 * 4); som_interp_run(t, cp->ret_op, cp->pre.s); for (uint32_t k = 0; k < t->wlog_n; k++) fprintf(stderr, "  oracle write %06X=%02X\n", t->wlog[k] >> 8, t->wlog[k] & 0xFF); free(t->wlog); free(t); } }
        } else f_pass++;
    }
    if (pass) rng_s = rng_saved;
    }
    unsigned s_pass = 0, s_fail = 0, s_skip = 0;
    size_t nb = 0;
    Cap *bases = NULL;
    if (nsynth && !stopped && (basecaps || !base_given)) {
        size_t nbn = 0; char **bnames = basecaps ? list_sorted(basecaps, "cap_", &nbn) : NULL;
        for (size_t bi = 0; bi < nbn && nb < 24; bi++) {
            char path[1024]; snprintf(path, sizeof path, "%s/%s", basecaps, bnames[bi]);
            Cap tmp; memset(&tmp, 0, sizeof tmp);
            if (load_cap(path, &tmp)) continue;
            bases = realloc(bases, (nb + 1) * sizeof *bases); bases[nb++] = tmp;
        }
        free_names(bnames, nbn);
        if (!base_given && !nb && ncs) { bases = malloc(ncs * sizeof *bases); memcpy(bases, cs, ncs * sizeof *bases); nb = ncs; } /* no base directory asked for: the routine's own states */
        im = im_main;
        for (unsigned it = 0; nb && !stopped && it < nsynth && (spent_syn < budget || it < syn_floor); it++) {
            Cap *bp = &bases[rnd() % nb];
            ctx_from_cap_pre(pre, bp, rom, rom_size);
            Cpu *r = &pre->cpu;
            r->k = (entry >> 16) & 0xFF; r->pc = entry & 0xFFFF; r->e = 0;
            r->mf = im->m < 0 ? (rnd() & 1) : im->m; r->xf = im->x < 0 ? (rnd() & 1) : im->x;
            if (ncs) { const Cap *tc = &cs[rnd() % ncs]; r->mf = (tc->pre.p >> 5) & 1; r->xf = (tc->pre.p >> 4) & 1; }
            r->d = 0; r->i = rnd() & 1; r->c = rnd() & 1; r->z = rnd() & 1; r->n = rnd() & 1; r->v = rnd() & 1;
            r->a = rnd() & 0xFFFF; r->x = rnd() & 0xFFFF; r->y = rnd() & 0xFFFF;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp = 0x1F00 + (rnd() % 0xC0);
            if (rnd() % 4 == 0) r->dp = (rnd() & 0x1F) << 8; /* sometimes a relocated direct page */
            unsigned nm = rnd() % 24;
            for (unsigned m = 0; m < nm; m++) pre->wram[rnd() % 0x2000] = rnd() & 0xFF;
            /* caller return address on the stack, as after JSR/JSL */
            uint16_t sp = r->sp;
            if (im->ret_op == SOM_RTI) { /* interrupt frame: PB, PCH, PCL, P (native mode) */
                pre->wram[sp & 0x1FFF] = 0xC0; sp--; pre->wram[sp & 0x1FFF] = 0x12; sp--; pre->wram[sp & 0x1FFF] = 0x34; sp--; pre->wram[sp & 0x1FFF] = rnd() & 0xCF; sp--;
            } else {
            if (im->ret_op == SOM_RTL) { pre->wram[sp & 0x1FFF] = 0xC0; sp--; }
            pre->wram[sp & 0x1FFF] = 0x12; sp--; pre->wram[sp & 0x1FFF] = 0x34; sp--;
            }
            r->sp = sp + (im->ret_op == SOM_RTL ? 3 : 2);
            r->sp = sp;
            uint16_t entry_sp = r->sp;
            memcpy(o, pre, sizeof *o); o->cpu.mem = o; o->nio = 0; o->steps = 0; o->fail = 0; o->hook_impls = 0; o->rdset = NULL; if (tmpmap) memset(tmpmap, 0, size); o->execmap = tmpmap; o->exec_base = entry; o->exec_len = size; o->step_limit = 300000; o->allow_unwind = (im->flags & SOM_UNWINDS) != 0; /* a routine that drops its own return address ends at the RTS of its caller's frame */
            if (getenv("SOM_TRACE_SYN") && (unsigned)atoi(getenv("SOM_TRACE_SYN")) == it) { som_trace_left = getenv("SOM_TRACE_N") ? atoi(getenv("SOM_TRACE_N")) : 4000; fprintf(stderr, "--- oracle trace, synthetic %u\n", it); }
            som_interp_run(o, im->ret_op, entry_sp);
            som_trace_left = 0;
            spent_syn += o->steps;
            o->execmap = NULL;
            SomRp *rpx = NULL; int sy_ext = 0;
            if (o->fail && !ladder_off() && (rpx = rp_extend(pre->rp))) {
                lad_try++;   /* the beam streams continue as a cycle of the recorded polls (see the ladder above) */
                ladder_oracle(o2, pre, NULL, 0, 1, rpx, tmpmap, entry, size, 300000, im->ret_op, entry_sp, (im->flags & SOM_UNWINDS) != 0);
                spent_syn += o2->steps;
                if (!o2->fail) { SomCtx *t = o; o = o2; o2 = t; sy_ext = 1; lad_ok++; }
            }
            if (o->fail) { s_skip++; rp_free(rpx); continue; }
            dump_maybe(pre, tmpmap, size, entry, "s", it);
            memcpy(g, pre, sizeof *g); g->cpu.mem = g; g->nio = 0; g->steps = 0; g->fail = 0; g->hook_impls = hook; g->rdset = NULL; g->execmap = NULL; g->step_limit = 300000;
            if (sy_ext) g->rp = rpx;
            guarded(im, g);
            if (g->fail && !sy_ext && !ladder_off() && (rpx = rp_extend(pre->rp))) {
                lad_try++;
                ladder_oracle(o2, pre, NULL, 0, 1, rpx, tmpmap, entry, size, 300000, im->ret_op, entry_sp, (im->flags & SOM_UNWINDS) != 0);
                spent_syn += o2->steps;
                if (!o2->fail) { ladder_impl(im, g, pre, NULL, 0, 1, rpx, 300000, hook); SomCtx *t = o; o = o2; o2 = t; if (!g->fail) lad_ok++; }
            }
            rp_free(rpx); rpx = NULL;
            if (g->fail) { s_skip++; continue; }
            if (execmap) for (uint32_t i = 0; i < size; i++) execmap[i] |= tmpmap[i];
            if (cmp_ctx(g, o, strict, im->live, im->stack_free, im->flags, entry_sp, msg, sizeof msg)) {
                s_fail++; s_mis++; if (stop_first) stopped = 1;
                if (!first_fail[0]) snprintf(first_fail, sizeof first_fail, "synthetic %u: %s", it, msg);
                if (getenv("SOM_DEBUG")) fprintf(stderr, "pre: A=%04X X=%04X Y=%04X S=%04X D=%04X DB=%02X P=%02X | lift: A=%04X X=%04X S=%04X pc=%04X P=%02X | oracle: A=%04X X=%04X S=%04X pc=%04X P=%02X\n", pre->cpu.a, pre->cpu.x, pre->cpu.y, pre->cpu.sp, pre->cpu.dp, pre->cpu.db, flags_of(&pre->cpu), g->cpu.a, g->cpu.x, g->cpu.sp, g->cpu.pc, flags_of(&g->cpu), o->cpu.a, o->cpu.x, o->cpu.sp, o->cpu.pc, flags_of(&o->cpu));
            } else s_pass++;
        }
    }
    uint32_t cov_all = 0;
    if (execmap) for (uint32_t i = 0; i < size; i++) cov_all += execmap[i];
    (void)cand_union; (void)io_pass; (void)io_fail;
    /* executed instruction starts as offsets from the entry (traces + fuzz + synthetic states) */
    size_t hcap = (size_t)size * 12 + 16, hl = 0; char *hitbuf = malloc(hcap); hitbuf[hl++] = '[';
    if (execmap) for (uint32_t i = 0; i < size; i++) if (execmap[i]) hl += snprintf(hitbuf + hl, 12, "%s%u", hl > 1 ? "," : "", i);
    hitbuf[hl++] = ']'; hitbuf[hl] = 0;
    /* synthetic states were asked for but there is no state to start from: refuse instead of silently testing nothing */
    int synth_err = nsynth && !nb && !stopped;
    if (synth_err && !first_fail[0]) snprintf(first_fail, sizeof first_fail, "synthetic states requested but no base captures found in '%s'", basecaps ? basecaps : "");
    const char *verdict = synth_err ? "SYNTH_NO_BASES" : (o_fail || i_fail || f_fail || s_fail) ? "FAIL" : ncs > badret_skipped + forced_skipped + trunc_skipped + suspect_skipped + quirk_skipped ? "PASS" : (s_pass ? "SYNTHETIC_ONLY" : "NO_TRACES");
    printf("{\"entry\":\"%06X\",\"variant\":\"%s\",\"strict\":%d,\"captures\":%zu,\"tainted_skipped\":%zu,\"badret_skipped\":%u,\"forced_skipped\":%u,\"trunc_skipped\":%u,\"suspect_skipped\":%u,\"unwind_dropped\":%u,\"quirk_skipped\":%u,\"exit_windows\":%u,\"hw_states\":%u,\"directed_states\":%u,\"replayed\":%u,\"load_failed\":%u,"
           "\"oracle_vs_snes9x\":{\"pass\":%u,\"fail\":%u},\"impl_vs_snes9x\":{\"pass\":%u,\"fail\":%u,\"mismatch\":%u,\"crash\":%u},"
           "\"fuzz\":{\"pass\":%u,\"fail\":%u,\"skipped\":%u,\"mismatch\":%u,\"crash\":%u},\"synthetic\":{\"pass\":%u,\"fail\":%u,\"skipped\":%u,\"mismatch\":%u,\"bases\":%zu},"
           "\"mismatches\":%u,\"seed\":%llu,\"insn_starts_hit_by_traces\":%u,\"insn_starts_hit_total\":%u,\"insns\":%u,\"hit\":%s,"
           "\"verdict\":\"%s\",\"first_fail\":\"%s\"}\n",
           entry, variant, strict, ncs, tainted, badret_skipped, forced_skipped, trunc_skipped, suspect_skipped, unwind_dropped, quirk_skipped, exit_caps, hw_states, dir_states, replayed, load_failed, o_pass, o_fail, i_pass, i_fail, i_mis, i_crash, f_pass, f_fail, f_skip, f_mis, f_crash,
           s_pass, s_fail, s_skip, s_mis, nb, i_mis + f_mis + s_mis, (unsigned long long)seed, cov_traces, cov_all, ninsn, hitbuf, verdict, first_fail);
    return (strcmp(verdict, "PASS") && strcmp(verdict, "SYNTHETIC_ONLY")) ? 1 : 0;
}
