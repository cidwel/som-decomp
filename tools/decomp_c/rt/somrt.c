#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "somrt.h"

uint32_t som_norm(uint32_t a) {
    uint32_t bank = a >> 16, low = a & 0xFFFF;
    if (low >= 0x8000) {
        if (bank < 0x40) return ((bank | 0xC0) << 16) | low;
        if (bank >= 0x80 && bank < 0xC0) return ((bank - 0x80 + 0xC0) << 16) | low;
    }
    return a;
}

int som_is_exit(const SomCtx *c, uint32_t addr) {
    if (!c->nexit) return 0;
    addr = som_norm(addr);
    for (unsigned i = 0; i < c->nexit; i++) if (c->exit_addr[i] == addr) return 1;
    return 0;
}

static SomImpl *impls;
static size_t n_impls, cap_impls;

void som_register(const SomImpl *impl) {
    if (n_impls == cap_impls) { cap_impls = cap_impls ? cap_impls * 2 : 64; impls = realloc(impls, cap_impls * sizeof *impls); }
    impls[n_impls++] = *impl;
}
size_t som_impl_count(void) { return n_impls; }
const SomImpl *som_impl_at(size_t i) { return &impls[i]; }
const SomImpl *som_find_impl(uint32_t addr, const char *variant) {
    addr = som_norm(addr);
    for (size_t i = 0; i < n_impls; i++)
        if (impls[i].addr == addr && (!variant || !strcmp(impls[i].variant, variant))) return &impls[i];
    return NULL;
}

static void deliver_next(SomCtx *c);
/* SOM_RT_LEGACY=1 switches the r10 harness changes off (end rule for non-unwinders, runaway bound on replay reads) so one binary can be run both ways for a regression comparison */
static int rt_legacy(void) { static int v = -1; if (v < 0) v = getenv("SOM_RT_LEGACY") ? 1 : 0; return v; }
static void som_calltrace_state(const SomCtx *c);
static int som_calltrace_on(void);
/* the interrupt handler being executed reads the values the real handler read, in the recorded order */
static uint8_t handler_read(SomCtx *c, uint32_t low) {
    const SomEvent *e = c->hev;
    uint32_t i = c->hq_i;
    while (i < e->nhq && (e->hq[i].addr & 0xFFFF) != low) i++;
    if (i >= e->nhq) { c->handler_bad++; return c->open_bus; }
    if (i != c->hq_i) { c->handler_bad++; c->hq_i = i; c->hq_rep = 0; }
    uint8_t v = e->hq[i].val;
    if (++c->hq_rep >= e->hq[i].reps) { c->hq_i++; c->hq_rep = 0; }
    return v;
}
static uint8_t rp_read(SomCtx *c, uint32_t low, int *hit) {
    *hit = 0;
    if (!c->rp) return 0;
    if (!((low >= 0x2134 && low <= 0x213F) || (low >= 0x2140 && low <= 0x2143) || (low >= 0x4210 && low <= 0x421F) || low == 0x4016 || low == 0x4017)) return 0;
    unsigned ix = som_rp_index(low);
    *hit = 1;
    if (c->in_handler) return handler_read(c, low);
    if (!c->peek) {
        /* an interrupt the real run took between two polls lands between the same two polls here */
        while ((c->ev_mode == 2 || c->ev_mode == 3) && c->ev_next < c->ev_n && c->ev[c->ev_next].hwat <= c->rp_count) deliver_next(c);
        if (getenv("SOM_RPDUMP") && c->rp_run[ix] == 0 && c->rp_off[ix] == 0) { for (unsigned q = 0; q < c->rp->n[ix]; q++) fprintf(stderr, "RUN %04X[%u] val %02X reps %u\n", low, q, c->rp->run[ix][q].val, c->rp->run[ix][q].reps); }
        c->rp_count++;
        c->hw_rd_mask |= 1;
        c->last_read_steps = c->ev_steps;
        if (c->rp_run[ix] >= c->rp->n[ix] && ++c->rp_over > 4000000 && c->stop_hook && !rt_legacy()) c->stop_hook(); /* a C loop polling a register whose recorded reads are used up: a runaway, stopped long before the watchdog's 2 s */
        if (c->v1log && c->dma_rd && c->rp_run[ix] >= c->rp->n[ix] && low != 0x2140) { c->short_replay = 1; c->fail = 4; }
        if (c->rp_run[ix] < c->rp->n[ix]) {
            const SomRpRun *ru = &c->rp->run[ix][c->rp_run[ix]];
            c->rp_last[ix] = ru->val;
            if (++c->rp_off[ix] >= ru->reps) { c->rp_run[ix]++; c->rp_off[ix] = 0; }
        } else if (low >= 0x2140 && low <= 0x2143) c->rp_last[ix] = c->apu_out[low - 0x2140];
        else if (getenv("SOM_DEBUG") && c->rp_run[ix] == c->rp->n[ix] && c->rp_off[ix] == 0) { c->rp_off[ix] = 1; fprintf(stderr, "replay of %04X exhausted at %02X:%04X after %llu insns (last value %02X, rp_count %u, next event %u of %u hwat %u)\n", low, c->cpu.k, c->cpu.pc, (unsigned long long)c->ev_steps, c->rp_last[ix], c->rp_count, c->ev_next, c->ev_n, c->ev_next < c->ev_n ? c->ev[c->ev_next].hwat : 0); }
        if (getenv("SOM_RPTRACE") && c->ev_steps < (unsigned long long)atoll(getenv("SOM_RPTRACE"))) fprintf(stderr, "RP %04X at %02X:%04X insns %llu -> %02X (event %u of %u)\n", low, c->cpu.k, c->cpu.pc, (unsigned long long)c->ev_steps, c->rp_last[ix], c->ev_next, c->ev_n);
        c->wepoch++; /* a polled hardware value is progress: never mistaken for a spin */
        if (c->have_ppu_ob) { /* the PPU open-bus latches follow the values the PPUs return (capture trailer SCP5) */
            const uint8_t vv = c->rp_last[ix];
            if (low == 0x2134 || low == 0x2135 || low == 0x2136 || low == 0x2138 || low == 0x2139 || low == 0x213A || low == 0x213E) c->ppu_ob1 = vv;
            else if (low == 0x213B || low == 0x213C || low == 0x213D || low == 0x213F) c->ppu_ob2 = vv;
        }
    }
    return c->rp_last[ix];
}

/* Branch-flip search: provenance carried through WRAM stores.  A store of a register records where that register's value came from (src) and, for a
 * ROM read, the pointer or index behind it (prov); a later load of the stored byte inherits both, so a value that a callee copied through memory
 * still points at the entry byte (or the ROM table index) that decides it.  Any other write to the byte forgets the record. */
static uint8_t *shd_set; static int32_t *shd_src; static SomProv *shd_pv; static uint32_t *shd_dirty; static uint32_t shd_nd;
static void shd_init(void) {
    if (shd_set) return;
    shd_set = calloc(SOM_WRAM_SIZE, 1); shd_src = calloc(SOM_WRAM_SIZE, sizeof *shd_src); shd_pv = calloc(SOM_WRAM_SIZE, sizeof *shd_pv); shd_dirty = malloc(SOM_WRAM_SIZE * sizeof *shd_dirty);
}
void som_shadow_reset(void) {
    shd_init();
    for (uint32_t i = 0; i < shd_nd; i++) shd_set[shd_dirty[i]] = 0;
    shd_nd = 0;
}
static void shd_clear(uint32_t o) { if (shd_set && shd_set[o] == 1) shd_set[o] = 2; }
static void shd_put(uint32_t o, int32_t src, const SomProv *pv) {
    o &= 0x1FFFF;
    if (!shd_set[o]) shd_dirty[shd_nd++] = o;   /* 2 = cleared but still listed for the reset */
    shd_set[o] = 1; shd_src[o] = src; shd_pv[o] = pv ? *pv : (SomProv){ 0 };
}

uint8_t som_rd(SomCtx *c, uint32_t adr) {
    adr &= 0xFFFFFF;
    if (c->cmplog && !c->peek) { c->ea[1] = c->ea[0]; c->ea[0] = adr; }
    uint32_t bank = adr >> 16, low = adr & 0xFFFF;
    if (bank == 0x7E || bank == 0x7F) {
        uint32_t o = ((bank & 1) << 16) | low;
        if (c->rdset) c->rdset[o] = 1;
        if (c->cmplog && !c->peek) { c->lr[1] = c->lr[0]; c->lr[0] = (int32_t)o; }
        return c->wram[o];
    }
    if (bank < 0x40 || (bank >= 0x80 && bank < 0xC0)) {
        if (low < 0x2000) { if (c->rdset) c->rdset[low] = 1; if (c->cmplog && !c->peek) { c->lr[1] = c->lr[0]; c->lr[0] = (int32_t)low; } return c->wram[low]; }
        if (low < 0x6000) {
            uint8_t v = c->open_bus;
            int hit = 0;
            if (low == 0x2180) {
                if (c->wram_dma) v = c->open_bus;
                else { v = c->wram[c->wmadd & 0x1FFFF]; if (!c->peek) c->wmadd = (c->wmadd + 1) & 0x1FFFF; }
            }
            else if (low >= 0x4214 && low <= 0x4217) {
                v = low == 0x4214 ? c->rddiv & 0xFF : low == 0x4215 ? c->rddiv >> 8 : low == 0x4216 ? c->rdmpy & 0xFF : c->rdmpy >> 8;
                if (c->v1log && c->rp && !c->peek && !c->in_handler) { /* format-1 capture: the math unit's inputs may predate the capture, so every result byte whose inputs are unknown comes from the real run's next read of that register */
                    unsigned ix = som_rp_index(low);
                    uint8_t rv = 0; int have = 0;
                    if (c->rp_run[ix] < c->rp->n[ix]) {
                        const SomRpRun *ru = &c->rp->run[ix][c->rp_run[ix]];
                        rv = ru->val; have = 1;
                        if (++c->rp_off[ix] >= ru->reps) { c->rp_run[ix]++; c->rp_off[ix] = 0; }
                    }
                    if (c->rd_unk & (1u << (low - 0x4214))) {
                        v = have ? rv : 0;
                        if (low == 0x4214) c->rddiv = (c->rddiv & 0xFF00) | v; else if (low == 0x4215) c->rddiv = (c->rddiv & 0x00FF) | (v << 8);
                        else if (low == 0x4216) c->rdmpy = (c->rdmpy & 0xFF00) | v; else c->rdmpy = (c->rdmpy & 0x00FF) | (v << 8);
                        c->rd_unk &= ~(1u << (low - 0x4214));
                    }
                }
                else if (c->rd_unk & (1u << (low - 0x4214))) { /* left over from before the capture: the real run's first read of the register tells what it held */
                    unsigned ix = som_rp_index(low);
                    v = c->rp && c->rp->n[ix] ? c->rp->run[ix][0].val : 0;
                    if (!c->peek) {
                        if (low == 0x4214) c->rddiv = (c->rddiv & 0xFF00) | v; else if (low == 0x4215) c->rddiv = (c->rddiv & 0x00FF) | (v << 8);
                        else if (low == 0x4216) c->rdmpy = (c->rdmpy & 0xFF00) | v; else c->rdmpy = (c->rdmpy & 0x00FF) | (v << 8);
                        c->rd_unk &= ~(1u << (low - 0x4214));
                    }
                }
                if (c->rp && !c->peek && getenv("SOM_MATHCHK")) { /* diagnostic: compare with the value the real run read */
                    unsigned ix = som_rp_index(low);
                    if (c->rp_run[ix] < c->rp->n[ix]) {
                        const SomRpRun *ru = &c->rp->run[ix][c->rp_run[ix]];
                        if (ru->val != v) fprintf(stderr, "MATH %04X read %02X recorded %02X (wrmpya %02X wrdiv %04X) at %02X:%04X\n", low, v, ru->val, c->wrmpya, c->wrdiv, c->cpu.k, c->cpu.pc);
                        if (++c->rp_off[ix] >= ru->reps) { c->rp_run[ix]++; c->rp_off[ix] = 0; }
                    }
                }
            }
            else if (low >= 0x4300 && low < 0x4380) { if (!c->peek) c->hw_rd_mask |= 4; v = c->wram_dma ? c->open_bus : c->dmareg[low - 0x4300]; }
            else {
                uint8_t r = rp_read(c, low, &hit);
                if (hit) v = r;
                else if (low >= 0x2100 && low < 0x2134 && c->have_ppu_ob) v = c->ppu_ob1;
                else if (low >= 0x2100 && low < 0x2134) { c->ob_unknown = 1; v = c->open_bus; }
                else if (low < 0x2134 || (low >= 0x2144 && low < 0x2180) || (low >= 0x2181 && low < 0x4016)) v = c->open_bus;
            }
            return v;
        }
        if (low < 0x8000) {
            if ((bank & 0x3F) < 0x20) return c->open_bus;
            const uint32_t si = (low - 0x6000) & 0x1FFF;
            if (!c->peek) { c->hw_rd_mask |= 2; if (c->srdset) c->srdset[si] = 1; }
            return c->sram[si];
        }
    }
    uint32_t off;
    if (bank >= 0xC0) off = ((bank - 0xC0) << 16) | low;
    else if (bank >= 0x40 && bank < 0x7E) off = ((bank - 0x40) << 16) | low;
    else if (low >= 0x8000) off = ((bank & 0x3F) << 16) | low;
    else return c->open_bus;
    return c->rom[(off & 0x1FFFFF) % c->rom_size];
}

/* B-bus ($21xx) write as the DMA unit and the CPU see it: only the registers with a CPU-visible effect are modelled */
static void b_write(SomCtx *c, uint32_t low, uint8_t v) {
    if (low >= 0x2140 && low <= 0x2143) c->apu_out[low - 0x2140] = v;
    if (c->wram_dma && low >= 0x2180 && low <= 0x2183) return; /* a transfer whose source is WRAM cannot reach the WRAM port */
    if (low == 0x2180) { if (c->wram[c->wmadd & 0x1FFFF] != v) c->wepoch++; c->wram[c->wmadd & 0x1FFFF] = v; c->wmadd = (c->wmadd + 1) & 0x1FFFF; }
    else if (low == 0x2181) c->wmadd = (c->wmadd & 0x1FF00) | v;
    else if (low == 0x2182) c->wmadd = (c->wmadd & 0x100FF) | ((uint32_t)v << 8);
    else if (low == 0x2183) c->wmadd = (c->wmadd & 0x0FFFF) | ((uint32_t)(v & 1) << 16);
}

static uint8_t b_read(SomCtx *c, uint32_t low) {
    if (low == 0x2180) {
        if (c->wram_dma) return c->open_bus;
        uint8_t v = c->wram[c->wmadd & 0x1FFFF]; c->wmadd = (c->wmadd + 1) & 0x1FFFF; return v;
    }
    int hit;
    uint8_t r = rp_read(c, low, &hit);
    if (!hit && low >= 0x2100 && low < 0x2134) { /* write-only PPU register: the PPU1 latch, not the CPU bus */
        if (c->have_ppu_ob) return c->ppu_ob1;
        c->ob_unknown = 1; /* a capture without the latch trailer: the value cannot be known */
    }
    return hit ? r : c->open_bus;
}

/* General-purpose DMA ($420B), executed at once like the capture core does.  A-bus reads go through the normal bus. */
static void run_dma(SomCtx *c, uint8_t mask) {
    static const uint8_t pat[8][4] = { {0,0,0,0}, {0,1,0,1}, {0,0,0,0}, {0,0,1,1}, {0,1,2,3}, {0,1,0,1}, {0,0,0,0}, {0,0,1,1} };
    static const uint8_t len[8] = { 1, 2, 1, 4, 4, 4, 1, 4 };
    for (int ch = 0; ch < 8; ch++) {
        if (!(mask & (1u << ch))) continue;
        uint8_t *d = &c->dmareg[ch * 16];
        uint8_t dmap = d[0];
        unsigned mode = dmap & 7, bbad = d[1];
        uint16_t a = d[2] | (d[3] << 8);
        uint8_t abank = d[4];
        uint32_t count = d[5] | (d[6] << 8);
        if (!count) count = 0x10000;
        int inc = (dmap & 8) ? 0 : (dmap & 0x10) ? -1 : 1;
        int reverse = (dmap & 0x80) != 0;
        if ((abank == 0x7E || abank == 0x7F) && bbad == 0x80 && !reverse) {
            /* WRAM -> $2180 does nothing; the A address still advances */
            a = (uint16_t)(a + (inc ? inc * (int)count : 0));
            d[2] = a & 0xFF; d[3] = a >> 8; d[5] = d[6] = 0;
            continue;
        }
        if (getenv("SOM_TRACE_DMA")) fprintf(stderr, "DMA ch%d dmap=%02X b=%02X a=%02X:%04X n=%u wmadd=%05X\n", ch, dmap, bbad, abank, a, count, c->wmadd);
        c->wram_dma = (abank == 0x7E || abank == 0x7F || (!(abank & 0x40) && a < 0x2000));
        c->peek++;
        unsigned n = 0;
        while (count) {
            uint32_t reg = 0x2100 + bbad + pat[mode][n & 3];
            if (!reverse) {
                uint8_t v = som_rd(c, ((uint32_t)abank << 16) | a);
                b_write(c, reg, v);
            } else {
                c->peek--; /* the B-bus reads are part of the recorded stream (the capture core logs them) */
                c->dma_rd++;
                uint8_t v = b_read(c, reg);
                c->dma_rd--;
                c->peek++;
                if (c->short_replay) break;
                som_wr(c, ((uint32_t)abank << 16) | a, v);
            }
            a = (uint16_t)(a + inc);
            count--; n++;
        }
        c->peek--;
        c->wram_dma = 0;
        d[2] = a & 0xFF; d[3] = a >> 8; d[5] = d[6] = 0;
        (void)len;
    }
}

void som_wr(SomCtx *c, uint32_t adr, uint8_t v) {
    adr &= 0xFFFFFF;
    if (c->wlog && c->wlog_n < c->wlog_cap) c->wlog[c->wlog_n++] = (adr << 8) | v;
    uint32_t bank = adr >> 16, low = adr & 0xFFFF;
    {
        static long watch = -2;
        if (watch == -2) watch = getenv("SOM_WATCH") ? strtol(getenv("SOM_WATCH"), 0, 16) : -1;
        if (watch >= 0 && !c->peek && (((bank & 0xFE) == 0x7E && (long)(((bank & 1) << 16) | low) == watch) || (bank < 0x40 && low < 0x2000 && (long)low == watch)))
            fprintf(stderr, "WATCH write %02X to %05lX at %02X:%04X steps %llu\n", v, watch, c->cpu.k, c->cpu.pc, (unsigned long long)c->steps);
    }
    if (bank == 0x7E || bank == 0x7F) { uint32_t o = ((bank & 1) << 16) | low; if (c->wrset) c->wrset[o] = 1; if (c->wram[o] != v) c->wepoch++; c->wram[o] = v; if (c->brlog) { if (c->nlw < 2) c->lw[c->nlw] = (int32_t)o; c->nlw++; shd_clear(o); } return; }
    if (bank < 0x40 || (bank >= 0x80 && bank < 0xC0)) {
        if (low < 0x2000) { if (c->wrset) c->wrset[low] = 1; if (c->wram[low] != v) c->wepoch++; c->wram[low] = v; if (c->brlog) { if (c->nlw < 2) c->lw[c->nlw] = (int32_t)low; c->nlw++; shd_clear(low); } return; }
        c->wepoch++;
        if (low < 0x6000) {
            if (!c->peek && !c->in_handler && c->nio < SOM_MAX_IO) c->io[c->nio++] = (SomIo){ adr, v, 1, c->cpu.pc };
            if (getenv("SOM_TRACE_IO")) fprintf(stderr, "IOW %06X=%02X\n", adr, v);
            if (low >= 0x2100 && low < 0x2200) b_write(c, low, v);
            else if (low == 0x4202) { c->wrmpya = v; c->wm_unk = 0; }
            else if (low == 0x4203) {
                c->rdmpy = (uint16_t)(c->wrmpya * v);
                if (c->wm_unk && c->v1log) c->rd_unk |= 0xC; else c->rd_unk &= ~0xC; /* the multiplicand predates the capture: the product is what the real run reads next */
            }
            else if (low == 0x4204) { c->wrdiv = (c->wrdiv & 0xFF00) | v; c->wd_unk &= ~1; }
            else if (low == 0x4205) { c->wrdiv = (c->wrdiv & 0x00FF) | ((uint16_t)v << 8); c->wd_unk &= ~2; }
            else if (low == 0x4206) {
                c->rd_unk = c->wd_unk && c->v1log ? 0xF : 0; /* the dividend predates the capture: quotient and remainder come from the real run's reads */
                if (v) { c->rddiv = c->wrdiv / v; c->rdmpy = c->wrdiv % v; }
                else { c->rddiv = 0xFFFF; c->rdmpy = c->wrdiv; }
            }
            else if (low == 0x420B) { if (!c->wram_dma && !c->peek) { c->open_bus = v; run_dma(c, v); } } /* the byte just written is on the data bus when the transfer starts: unmapped B-bus reads return it (Snes9x OpenBus) */ /* a B-to-A transfer aimed at $420B must not start itself (unbounded recursion) */
            else if (low == 0x420C) c->hdmaen = v;
            else if (low >= 0x4300 && low < 0x4380 && !c->wram_dma) {
                c->dmareg[low - 0x4300] = v;
                if ((low & 0xF) == 0xB) c->dmareg[(low - 0x4300) | 0xF] = v;
                else if ((low & 0xF) == 0xF) c->dmareg[(low - 0x4300) & ~0xFu | 0xB] = v;
            }
            return;
        }
        if (low < 0x8000) { if ((bank & 0x3F) >= 0x20) { if (c->sram[(low - 0x6000) & 0x1FFF] != v) c->wepoch++; c->sram[(low - 0x6000) & 0x1FFF] = v; c->sram_wr[(low - 0x6000) & 0x1FFF] = 1; } return; }
    }
}

/* Execute the interrupt handler from its vector on the oracle's own CPU, feeding it the reads the real handler made.  The
 * WRAM the handler leaves behind is the recorded delta (authoritative); the registers come from the execution, which is
 * trusted only when it reproduces the recorded delta exactly (otherwise the interrupted code resumes unchanged). */
static void run_handler(SomCtx *c, const SomEvent *e) {
    Cpu *r = &c->cpu;
    const Cpu saved = *r;
    static uint8_t *snap, *mark;
    if (!snap) { snap = malloc(SOM_WRAM_SIZE); mark = malloc(SOM_WRAM_SIZE); }
    memcpy(snap, c->wram, SOM_WRAM_SIZE);
    const uint64_t io_n = c->nio;
    c->in_handler = 1; c->hev = e; c->hq_i = 0; c->hq_rep = 0;
    c->peek++; /* the handler's reads are logged by the real run, not part of the routine's list */
    c->peek--;
    r->waiting = false; r->intWanted = true; r->nmiWanted = e->kind == 0; r->irqWanted = e->kind != 0;
    cpu_runOpcode(r); /* takes the interrupt: pushes K, PC, P and jumps to the vector */
    r->irqWanted = r->nmiWanted = r->intWanted = false; /* LakeSnes never clears the IRQ line: left set, the main run would take the IRQ again after the RTI */
    const uint16_t s_in = r->sp;
    int ok = 1;
    for (uint32_t n = 0;; n++) {
        if (n > 400000) { ok = 0; break; }
        c->peek++;
        uint8_t op = som_rd(c, ((uint32_t)r->k << 16) | r->pc);
        c->peek--;
        if (op == 0x00 || op == 0x02 || op == 0xDB || op == 0xCB) { ok = 0; break; }
        const int is_rti = op == 0x40 && r->sp == s_in;
        cpu_runOpcode(r);
        if (is_rti) break;
    }
    c->in_handler = 0;
    c->nio = io_n < c->nio ? io_n : c->nio;
    if (ok) { /* did the execution reproduce the recorded WRAM delta? */
        memset(mark, 0, SOM_WRAM_SIZE);
        for (uint32_t i = 0; i < e->ndelta; i++) mark[e->delta[i] & 0x1FFFF] = 1;
        for (uint32_t i = 0; i < SOM_WRAM_SIZE && ok; i++) {
            if (c->wram[i] != snap[i] && !mark[i]) ok = 0;
        }
        for (uint32_t i = 0; i < e->ndelta && ok; i++) if (c->wram[e->delta[i] & 0x1FFFF] != (e->delta[i] >> 24)) ok = 0;
    }
    c->handler_runs++;
    if (!ok && getenv("SOM_EVCHECK")) {
        int shown = 0;
        for (uint32_t i = 0; i < e->ndelta && shown < 12; i++) { uint32_t o = e->delta[i] & 0x1FFFF; if (c->wram[o] != (e->delta[i] >> 24)) { fprintf(stderr, "  recorded %05X: %02X -> %02X, emulated handler left %02X\n", o, snap[o], e->delta[i] >> 24, c->wram[o]); shown++; } }
        for (uint32_t i = 0; i < SOM_WRAM_SIZE && shown < 24; i++) if (c->wram[i] != snap[i] && !mark[i]) { fprintf(stderr, "  emulated handler also changed %05X: %02X -> %02X\n", i, snap[i], c->wram[i]); shown++; }
        fprintf(stderr, "  handler left pc %02X:%04X sp %04X (entry sp %04X) after reads %u/%u\n", r->k, r->pc, r->sp, s_in, c->hq_i, e->nhq);
    }
    if (getenv("SOM_EVCHECK")) fprintf(stderr, "EVCHECK handler %u: %s (reads left %u of %u, bad %u) regs %s\n", c->ev_next - 1, ok ? "reproduces the recorded WRAM delta" : "DIFFERS from the recorded WRAM delta",
                                       e->nhq - c->hq_i, e->nhq, c->handler_bad,
                                       (r->pc == saved.pc && r->k == saved.k && r->sp == saved.sp && r->a == saved.a && r->x == saved.x && r->y == saved.y && r->dp == saved.dp && r->db == saved.db) ? "unchanged" : "CHANGED");
    memcpy(c->wram, snap, SOM_WRAM_SIZE);
    for (uint32_t i = 0; i < e->ndelta; i++) c->wram[e->delta[i] & 0x1FFFF] = e->delta[i] >> 24;
    if (ok) c->handler_ok++;
    else { *r = saved; r->mem = c; }  /* the execution is not trusted: resume as before the interrupt */
}

/* Deliver one recorded interrupt: the handler's WRAM writes and the hardware state it left */
void som_deliver_event(SomCtx *c, const SomEvent *e) {
    if (c->ev_mode == 1) { SomEvent *w = (SomEvent *)e; w->sp = c->cpu.sp; w->sp_ok = 1; w->lag = (uint32_t)(c->ev_steps - c->last_read_steps); }
    if (c->ev_mode == 1 && getenv("SOM_EVCHECK") && c->rp_count != e->hwat) fprintf(stderr, "EVCHECK event %u: oracle consumed %u replayed reads, the capture %u, at %02X:%04X after %llu insns\n", c->ev_next - 1, c->rp_count, e->hwat, c->cpu.k, c->cpu.pc, (unsigned long long)c->ev_steps);
    if (c->ev_mode == 1 && c->run_handlers && e->nhq) run_handler(c, e);
    else for (uint32_t i = 0; i < e->ndelta; i++) {
        uint32_t off = e->delta[i] & 0x1FFFF;
        /* delivered at another point of the routine, the handler's pushes would overwrite live stack: only exact mode keeps them */
        if ((c->ev_mode == 2 || c->ev_mode == 3) && e->sp_ok && e->kind != 2 && off >= 0x100 && off <= e->sp) continue;
        c->wram[off] = e->delta[i] >> 24;
    }
    if (e->has_hw) { c->wmadd = e->wmadd; c->wrmpya = e->wrmpya; c->wrdiv = e->wrdiv; c->rddiv = e->rddiv; c->rdmpy = e->rdmpy; memcpy(c->dmareg, e->dma, 0x80); c->hdmaen = e->hdmaen; }
    c->wepoch++;
}

static uint8_t h_read(void *mem, uint32_t adr) { SomCtx *c = (SomCtx *)mem; uint8_t v = som_rd(c, adr); c->open_bus = v; return v; }
static void h_write(void *mem, uint32_t adr, uint8_t v) { SomCtx *c = (SomCtx *)mem; som_wr(c, adr, v); c->open_bus = v; }
static void h_idle(void *mem, bool waiting) { (void)mem; (void)waiting; }

void som_ctx_init(SomCtx *c, const uint8_t *rom, size_t rom_size) {
    memset(c, 0, sizeof *c);
    c->rom = rom;
    c->rom_size = rom_size;
    c->cpu.mem = c;
    c->cpu.read = h_read;
    c->cpu.write = h_write;
    c->cpu.idle = h_idle;
    c->step_limit = 4000000;
}

static int is_jump_op(uint8_t op) {
    return op == 0x20 || op == 0x22 || op == 0x4C || op == 0x5C || op == 0x6C || op == 0x7C || op == 0xDC || op == 0xFC;
}

/* Interrupts recorded by the capture.  Exact mode delivers each one after the number of routine instructions the real run
 * had completed; deferred mode delivers the next one when the code can make no progress (the same register state twice
 * with no write in between, or WAI) and the rest after the routine returned. */
static void deliver_next(SomCtx *c) {
    if (c->ev_next < c->ev_n) { if (getenv("SOM_DEBUG")) fprintf(stderr, "event %u delivered mode %d at pc %02X:%04X after %llu insns\n", c->ev_next, c->ev_mode, c->cpu.k, c->cpu.pc, (unsigned long long)c->ev_steps); som_deliver_event(c, &c->ev[c->ev_next++]); }
}

static int spin_check(SomCtx *c) {
    Cpu *r = &c->cpu;
    uint32_t pc = ((uint32_t)r->k << 16) | r->pc;
    uint8_t p = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    unsigned h = (pc * 2654435761u ^ r->a * 40503u ^ r->x * 69069u ^ r->y * 1103515245u ^ r->sp) >> 7 & 63;
    typeof(c->spin[0]) *e = &c->spin[h];
    if (e->epoch == c->wepoch && e->pc == pc && e->a == r->a && e->x == r->x && e->y == r->y && e->s == r->sp && e->d == r->dp && e->p == p && e->db == r->db) {
        e->epoch = ~0ull;
        return 1;
    }
    *e = (typeof(*e)){ pc, r->a, r->x, r->y, r->sp, r->dp, p, r->db, c->wepoch };
    return 0;
}

int som_trace_left = -1; /* instructions still to trace on stderr (SOM_TRACE, or armed by difftest for one fuzz iteration) */

/* coverage-search compare log (SomCtx.cmplog): called after every interpreted instruction */
static void cmp_note(SomCtx *c, uint8_t op, uint32_t pc, uint16_t a, uint16_t x, uint16_t y, uint8_t mf, uint8_t xf) {
    const int la = (op == 0xA9 || op == 0xA5 || op == 0xB5 || op == 0xAD || op == 0xBD || op == 0xB9 || op == 0xAF || op == 0xBF || op == 0xA1 || op == 0xB1 || op == 0xB2 || op == 0xA7 || op == 0xB7 || op == 0xA3 || op == 0xB3);
    const int lx = (op == 0xA2 || op == 0xA6 || op == 0xB6 || op == 0xAE || op == 0xBE), ly = (op == 0xA0 || op == 0xA4 || op == 0xB4 || op == 0xAC || op == 0xBC);
    int32_t lo = c->lr[0] >= 0 && c->lr[1] >= 0 && c->lr[1] + 1 == c->lr[0] ? c->lr[1] : c->lr[0];
    if (la) c->src[0] = (op == 0xA9) ? -1 : lo;
    else if (lx) c->src[1] = (op == 0xA2) ? -1 : lo;
    else if (ly) c->src[2] = (op == 0xA0) ? -1 : lo;
    else if (op == 0xAA) c->src[1] = c->src[0]; else if (op == 0xA8) c->src[2] = c->src[0];
    else if (op == 0x8A) c->src[0] = c->src[1]; else if (op == 0x98) c->src[0] = c->src[2];
    else if (op == 0x9B) c->src[2] = c->src[1]; else if (op == 0xBB) c->src[1] = c->src[2];
    else if (op == 0x68 || op == 0x7A || op == 0xFA) c->src[op == 0x68 ? 0 : op == 0xFA ? 1 : 2] = -1;
    if (c->brlog && (la || lx || ly) && op != 0xA9 && op != 0xA2 && op != 0xA0 && lo >= 0 && shd_set && shd_set[lo] == 1) c->src[la ? 0 : lx ? 1 : 2] = shd_src[lo];
    int kind = -1;
    switch (op) {
    case 0xC9: case 0xC5: case 0xD5: case 0xCD: case 0xDD: case 0xD9: case 0xCF: case 0xDF: case 0xC1: case 0xD1: case 0xD2: case 0xC7: case 0xD7: case 0xC3: case 0xD3: kind = 0; break;
    case 0xE0: case 0xE4: case 0xEC: kind = 1; break;
    case 0xC0: case 0xC4: case 0xCC: kind = 2; break;
    case 0x24: case 0x2C: case 0x34: case 0x3C: case 0x89: case 0x04: case 0x0C: case 0x14: case 0x1C: case 0x25: case 0x2D: case 0x35: case 0x3D: case 0x39: kind = 3; break;
    case 0x69: case 0x65: case 0x75: case 0x6D: case 0x7D: case 0x79: case 0x6F: case 0x7F: case 0x61: case 0x71: case 0x72: case 0x67: case 0x77: case 0x63: case 0x73:
    case 0xE9: case 0xE5: case 0xF5: case 0xED: case 0xFD: case 0xF9: case 0xEF: case 0xFF: case 0xE1: case 0xF1: case 0xF2: case 0xE7: case 0xF7: case 0xE3: case 0xF3: kind = 4; break;
    default: return;
    }
    if (c->ncmp >= SOM_CMPLOG_MAX) return;
    const int wide = kind == 0 || kind == 3 || kind == 4 ? !mf : !xf;
    SomCmp *e = &c->cmplog[c->ncmp];
    e->pc = pc; e->kind = kind; e->wide = wide;
    e->reg = kind == 1 ? x : kind == 2 ? y : a;
    e->src = c->src[kind == 1 ? 1 : kind == 2 ? 2 : 0];
    const int imm = op == 0xC9 || op == 0xE0 || op == 0xC0 || op == 0x89 || op == 0x69 || op == 0xE9;
    if (imm) {
        c->peek++; e->mem = som_rd(c, pc + 1) | (wide ? som_rd(c, pc + 2) << 8 : 0); c->peek--;
        e->maddr = -1;
    } else if (c->lr[0] >= 0) {
        e->maddr = (wide && c->lr[1] >= 0 && c->lr[1] + 1 == c->lr[0]) ? c->lr[1] : c->lr[0];
        e->mem = c->wram[e->maddr] | (wide ? c->wram[(e->maddr + 1) & 0x1FFFF] << 8 : 0);
    } else { e->maddr = -2; e->mem = 0; }   /* operand outside WRAM (ROM table, hardware register) */
    c->ncmp++;
}

/* ROM provenance (branch-flip search): a register loaded from ROM has no WRAM byte that can change its value, but the pointer or the index the
 * address came from can.  Tracks that for A, X and Y; copies of a register (TAX, TYA ...) carry it along, anything else that writes the register clears it. */
static int is_rom_addr(uint32_t ea) {
    const uint32_t bank = ea >> 16, low = ea & 0xFFFF;
    if (bank == 0x7E || bank == 0x7F) return 0;
    if (bank < 0x40 || (bank >= 0x80 && bank < 0xC0)) return low >= 0x8000;
    return 1;
}

static int prov_note(SomCtx *c, uint8_t op, uint32_t pc, uint16_t pre_x, uint16_t pre_y) {
    const Cpu *r = &c->cpu;
    int dst = -1, wide = 0;
    switch (op) {
    case 0xA1: case 0xB1: case 0xB2: case 0xA7: case 0xB7: case 0xAD: case 0xBD: case 0xB9: case 0xAF: case 0xBF: dst = 0; wide = !r->mf; break;
    case 0xAE: case 0xBE: dst = 1; wide = !r->xf; break;
    case 0xAC: case 0xBC: dst = 2; wide = !r->xf; break;
    case 0xAA: c->prov[1] = c->prov[0]; return 1;
    case 0xA8: c->prov[2] = c->prov[0]; return 1;
    case 0x8A: c->prov[0] = c->prov[1]; return 1;
    case 0x98: c->prov[0] = c->prov[2]; return 1;
    case 0x9B: c->prov[2] = c->prov[1]; return 1;
    case 0xBB: c->prov[1] = c->prov[2]; return 1;
    default: return 0;
    }
    SomProv *pv = &c->prov[dst];
    pv->valid = 0;
    if (c->lr[0] >= 0) {   /* the byte came from WRAM (src tracks it); a value stored there from a ROM read keeps its provenance */
        const int32_t lo = c->lr[1] >= 0 && c->lr[1] + 1 == c->lr[0] ? c->lr[1] : c->lr[0];
        if (shd_set && shd_set[lo] == 1 && shd_pv[lo].valid && dst >= 0) *pv = shd_pv[lo];
        return 1;
    }
    if (c->ea[0] == 0xFFFFFFFFu) return 1;   /* there was no data read */
    const uint32_t ea = (wide && c->ea[1] != 0xFFFFFFFFu && c->ea[1] + 1 == c->ea[0]) ? c->ea[1] : c->ea[0];
    if (!is_rom_addr(ea)) return 1;
    c->peek++;
    const uint8_t d8 = som_rd(c, (pc & 0xFF0000u) | ((pc + 1) & 0xFFFFu));
    c->peek--;
    SomProv v = { 1, 0, (uint8_t)wide, 0, 0, 0, 0, ea, 0, -1, -1 };
    const uint16_t D = r->dp;
    switch (op) {
    case 0xA1: v.kind = 1; v.plen = 2; v.iv = 0; v.ptr = (uint16_t)(D + d8 + pre_x); break;
    case 0xB1: v.kind = 1; v.plen = 2; v.iv = r->xf ? (pre_y & 0xFF) : pre_y; v.ptr = (uint16_t)(D + d8); break;
    case 0xB2: v.kind = 1; v.plen = 2; v.iv = 0; v.ptr = (uint16_t)(D + d8); break;
    case 0xA7: v.kind = 1; v.plen = 3; v.iv = 0; v.ptr = (uint16_t)(D + d8); break;
    case 0xB7: v.kind = 1; v.plen = 3; v.iv = r->xf ? (pre_y & 0xFF) : pre_y; v.ptr = (uint16_t)(D + d8); break;
    case 0xBD: case 0xBC: case 0xBF: v.kind = 2; v.idxreg = 1; v.iw = !r->xf; v.base = ea - (r->xf ? (pre_x & 0xFF) : pre_x); v.idxsrc = c->src[1]; break;
    case 0xB9: case 0xBE: v.kind = 2; v.idxreg = 2; v.iw = !r->xf; v.base = ea - (r->xf ? (pre_y & 0xFF) : pre_y); v.idxsrc = c->src[2]; break;
    default: return 1;   /* absolute / long loads from ROM are constants */
    }
    if (v.kind == 1 && (v.ptr < 0 || v.ptr >= 0x1FFE)) return 1;   /* the pointer must live in the low-RAM mirror */
    *pv = v;
    return 1;
}

/* branch-flip search (SomCtx.brlog): called after cmp_note for every interpreted instruction.  Keeps the flag setter that decides the next
 * conditional branch and logs every conditional branch with it. */
static void brf_note(SomCtx *c, uint8_t op, uint32_t pc, uint32_t pre_ncmp, uint16_t pre_x, uint16_t pre_y) {
    const Cpu *r = &c->cpu;
    if ((op & 0x1F) == 0x10) {
        if (c->nbr >= SOM_BRLOG_MAX) return;
        SomBr *b = &c->brlog[c->nbr++];
        *b = c->lastset;
        b->pc = pc; b->op = op;
        b->taken = (uint16_t)r->pc != (uint16_t)(pc + 2);
        b->fz = r->z; b->fn = r->n; b->fc = r->c; b->fv = r->v;
        return;
    }
    {   /* stores: carry the register's origin into the bytes written */
        int sr = -1;
        switch (op) {
        case 0x85: case 0x95: case 0x8D: case 0x9D: case 0x99: case 0x81: case 0x91: case 0x92: case 0x87: case 0x97: case 0x83: case 0x93: case 0x8F: case 0x9F: sr = 0; break;
        case 0x86: case 0x96: case 0x8E: sr = 1; break;
        case 0x84: case 0x94: case 0x8C: sr = 2; break;
        default: break;
        }
        if (sr >= 0 && shd_set && c->nlw >= 1 && c->nlw <= 2) {
            for (uint32_t i = 0; i < c->nlw; i++) {
                const int32_t s0 = c->src[sr];
                shd_put((uint32_t)c->lw[i], s0 >= 0 ? s0 + (int32_t)i : -1, i == 0 ? &c->prov[sr] : NULL);
            }
        }
    }
    const int pdone = prov_note(c, op, pc, pre_x, pre_y);
    if (c->ncmp != pre_ncmp) {
        const SomCmp *e = &c->cmplog[c->ncmp - 1];
        c->lastset = (SomBr){ pc, op, 0, e->kind, e->wide, e->reg, e->mem, e->maddr, e->src, 0, 0, 0, 0, {0} };
        c->lastset.pv = c->prov[e->kind == 1 ? 1 : e->kind == 2 ? 2 : 0];
        if (e->kind == 4) c->prov[0].valid = 0;   /* ADC / SBC wrote A */
        return;
    }
    int rg = -1, wide = 0;   /* register holding the result: 0 A, 1 X, 2 Y, 3 memory operand */
    switch (op) {
    case 0xA9: case 0xA5: case 0xB5: case 0xAD: case 0xBD: case 0xB9: case 0xAF: case 0xBF: case 0xA1: case 0xB1: case 0xB2: case 0xA7: case 0xB7: case 0xA3: case 0xB3:
    case 0x29: case 0x25: case 0x35: case 0x2D: case 0x3D: case 0x39: case 0x2F: case 0x3F: case 0x21: case 0x31: case 0x32: case 0x27: case 0x37: case 0x23: case 0x33:
    case 0x09: case 0x05: case 0x15: case 0x0D: case 0x1D: case 0x19: case 0x0F: case 0x1F: case 0x01: case 0x11: case 0x12: case 0x07: case 0x17: case 0x03: case 0x13:
    case 0x49: case 0x45: case 0x55: case 0x4D: case 0x5D: case 0x59: case 0x4F: case 0x5F: case 0x41: case 0x51: case 0x52: case 0x47: case 0x57: case 0x43: case 0x53:
    case 0x1A: case 0x3A: case 0x0A: case 0x4A: case 0x2A: case 0x6A: case 0x8A: case 0x98: case 0x68: case 0x3B: case 0x7B: case 0xEB: rg = 0; wide = !r->mf; break;
    case 0xA2: case 0xA6: case 0xB6: case 0xAE: case 0xBE: case 0xE8: case 0xCA: case 0xAA: case 0xBA: case 0xBB: case 0xFA: rg = 1; wide = !r->xf; break;
    case 0xA0: case 0xA4: case 0xB4: case 0xAC: case 0xBC: case 0xC8: case 0x88: case 0xA8: case 0x9B: case 0x7A: rg = 2; wide = !r->xf; break;
    case 0xE6: case 0xF6: case 0xEE: case 0xFE: case 0xC6: case 0xD6: case 0xCE: case 0xDE: case 0x06: case 0x16: case 0x0E: case 0x1E: case 0x46: case 0x56: case 0x4E: case 0x5E:
    case 0x26: case 0x36: case 0x2E: case 0x3E: case 0x66: case 0x76: case 0x6E: case 0x7E: rg = 3; wide = !r->mf; break;
    case 0x18: case 0x38: case 0xB8: case 0x58: case 0x78: case 0xD8: case 0xF8: case 0xC2: case 0xE2: case 0x28: case 0xFB: case 0x2B: case 0xAB: {
        c->lastset = (SomBr){ pc, op, 0, 6, 0, 0, 0, -1, -1, 0, 0, 0, 0, {0} };
        return;
    }
    default: return;
    }
    if (!pdone && rg >= 0 && rg <= 2) c->prov[rg].valid = 0;   /* the register was written by something that is not a ROM load or a copy */
    SomBr *l = &c->lastset;
    *l = (SomBr){ pc, op, 0, 5, (uint8_t)wide, rg == 0 ? r->a : rg == 1 ? r->x : rg == 2 ? r->y : 0, 0, -1, -1, 0, 0, 0, 0, {0} };
    if (rg >= 0 && rg <= 2) l->pv = c->prov[rg];
    if (rg == 3) { l->src = l->maddr = c->lr[0] >= 0 && wide && c->lr[1] >= 0 && c->lr[1] + 1 == c->lr[0] ? c->lr[1] : c->lr[0]; }
    else {
        l->src = c->src[rg];
        const int memop = (op & 0x1F) != 0x09 && (op & 0x1F) != 0x0A && (op & 0x1F) != 0x1A && op != 0xA9 && op != 0xA2 && op != 0xA0;
        l->maddr = memop && c->lr[0] >= 0 ? (wide && c->lr[1] >= 0 && c->lr[1] + 1 == c->lr[0] ? c->lr[1] : c->lr[0]) : -1;
    }
}

int som_unwind_n; /* bytes popped by the unwinding RTS/RTL of the routine under test when it is not its own return size (0 = default), set by difftest from the captures (header bit 21) */
#define SOM_UNW_N(op) (som_unwind_n ? (uint16_t)som_unwind_n : (uint16_t)((op) == SOM_RTS ? 2 : 3))
static int frame_clobbered(SomCtx *c, uint16_t entry_sp, uint8_t fr0, uint8_t fr1) {
    if (getenv("SOM_NO_FRAMECHK")) return 0;
    c->peek++; const int d = som_rd(c, (uint16_t)(entry_sp + 1)) != fr0 || som_rd(c, (uint16_t)(entry_sp + 2)) != fr1; c->peek--;
    return d;
}
void som_interp_run(SomCtx *c, uint8_t ret_op, uint16_t entry_sp) {
    Cpu *r = &c->cpu;
    int trace = som_trace_left;
    /* an unwinder that dropped its own return address (S >= entry S + return size) continues in its caller's frame: a return of a callee
     * it calls afterwards, at S = entry S, is that callee's own and does not end the call */
    int dropped = 0, depth = 0, sw_here = 0;
    uint16_t last_sp = r->sp; /* the stack pointer before the previous instruction: a jump of 0x100 or more is a task switch */
    /* return address bytes of the call at entry; a return at entry S from a nested call (depth > 0) after they were overwritten is a return of some other
     * routine into garbage, not the end of this one: the original keeps running, so does the oracle (it then ends by its limits and the state is skipped) */
    uint8_t fr0, fr1; c->peek++; fr0 = som_rd(c, (uint16_t)(entry_sp + 1)); fr1 = som_rd(c, (uint16_t)(entry_sp + 2)); c->peek--;
    if (trace < 0) trace = som_trace_left = getenv("SOM_TRACE") ? atoi(getenv("SOM_TRACE")) : 0;
    for (;;) {
        if (trace > 0 && som_trace_left-- > 0) fprintf(stderr, "T %02X:%04X op=%02X A=%04X X=%04X Y=%04X S=%04X D=%04X DB=%02X\n", r->k, r->pc, som_rd(c, ((uint32_t)r->k << 16) | r->pc), r->a, r->x, r->y, r->sp, r->dp, r->db);
        if (c->short_replay) return;
        if (c->nexit && som_exit_arrive(c, ((uint32_t)r->k << 16) | r->pc)) { c->exited = 1; if (getenv("SOM_DEBUG")) fprintf(stderr, "exit address reached at %02X:%04X S %04X entry_sp %04X routine_ret %02X\n", r->k, r->pc, r->sp, entry_sp, c->routine_ret); return; } /* an exit-address window ends before the instruction at the address */
        if (++c->steps > c->step_limit) { c->fail = 1; if (getenv("SOM_DEBUG")) fprintf(stderr, "oracle step limit at %02X:%04X\n", r->k, r->pc); return; }
        if (c->ev_mode == 1) {
            while (c->ev_next < c->ev_n && c->ev[c->ev_next].at <= c->ev_steps) deliver_next(c);
            c->ev_steps++;
        } else if (c->ev_mode == 3) {
            while (c->ev_next < c->ev_n && c->ev[c->ev_next].hwat == c->rp_count && c->ev_steps - c->last_read_steps >= c->ev[c->ev_next].lag) deliver_next(c);
            c->ev_steps++;
        }
        if (c->task_mode && !c->switched) { /* the capture closes (mode 1) or the call changes its end rule (mode 2) at the first boundary where S differs from the window's entry S by 0x100 or more */
            const int d = (int)r->sp - (int)c->task_s;
            if (d >= 0x100 || d <= -0x100 || (c->cont && (r->sp >> 8) != (c->task_s >> 8))) { /* continuation windows: another stack page is another task (adjacent task stacks can be less than 0x100 apart) */
                c->switched = 1;
                if (c->task_mode == 1) { c->unwound = 1; return; }
                sw_here = 1; depth = 0; /* mode 2: the call ends at the first RTS/RTL that returns past the stack the switch started */
            }
        }
        if (!(sw_here && c->cont) && ((int)r->sp - (int)last_sp >= 0x100 || (int)last_sp - (int)r->sp >= 0x100)) { depth = 0; dropped = 0; } /* continuation windows count the call depth of the swap-out window like the capture core (no reset at the stack changes inside the swapper) */ /* another task's frames: the call depth and the dropped-frame state of the first stack mean nothing there */
        last_sp = r->sp;
        if (r->sp > c->sp_max) c->sp_max = r->sp;
        c->peek++;
        uint8_t op = som_rd(c, ((uint32_t)r->k << 16) | r->pc);
        c->peek--;
        if ((op == 0xAE || op == 0xBE || op == 0xAC || op == 0xBC) && !r->xf) { /* Snes9x wraps the high byte of a 16-bit LDX/LDY inside the bank (the hardware, and this oracle, carry into the next one) */
            c->peek++;
            const uint32_t ea = ((uint32_t)r->db << 16) + (som_rd(c, ((uint32_t)r->k << 16) | (uint16_t)(r->pc + 1)) | (som_rd(c, ((uint32_t)r->k << 16) | (uint16_t)(r->pc + 2)) << 8)) + (op == 0xBE ? r->y : op == 0xBC ? r->x : 0);
            c->peek--;
            if ((ea & 0xFFFF) == 0xFFFF) c->s9x_quirk = 1;
        }
        if (c->kset) { uint32_t pa = ((uint32_t)r->k << 16) | r->pc; c->peek++; c->kset[som_rd(c, pa + 1)] = 1; c->kset[som_rd(c, pa + 2)] = 1; c->peek--; }
        if (c->fetchset && (r->k == 0x7E || r->k == 0x7F)) for (unsigned q = 0; q < 4; q++) c->fetchset[(((uint32_t)r->k & 1) << 16) | ((r->pc + q) & 0xFFFF)] = 1;
        if (c->execmap) { uint32_t pcx = ((uint32_t)r->k << 16) | r->pc; pcx = som_norm(pcx); if (pcx >= c->exec_base && pcx - c->exec_base < c->exec_len) c->execmap[pcx - c->exec_base] = 1; }
        if (sw_here && (op == SOM_RTS || op == SOM_RTL) && depth == 0) {
            cpu_runOpcode(r);
            if (c->cont && c->cont->jump(c, c->cont->user)) { sw_here = 0; depth = 0; dropped = 0; last_sp = r->sp; c->rti_ok = 1; continue; } /* continuation capture: the task was resumed, the run goes on from there */
            c->unwound = 1; return;
        }
        if (c->allow_unwind && r->sp >= (uint16_t)(entry_sp + SOM_UNW_N(ret_op)) && r->sp < (uint16_t)(entry_sp + 0x100)) dropped = 1;
        if (!sw_here && !(c->exit_only && !c->c_run) && ((op == ret_op && ((r->sp == entry_sp && !(dropped && depth > 0) && !(depth > 0 && frame_clobbered(c, entry_sp, fr0, fr1))) || (c->allow_unwind && r->sp == (uint16_t)(entry_sp + SOM_UNW_N(ret_op)))))
            || (c->allow_unwind && c->routine_ret && op == c->routine_ret && r->sp == c->routine_sp && !(dropped && depth > 0))
            /* a routine that is not an unwinder ends at its own RTS/RTL at its entry S, wherever that return is reached from (a callee that smashed its own
             * return address and ran on, a tail callee that pops the routine's pushes): the original code ends there, so does every nested run */
            || (!rt_legacy() && !c->routine_unw && c->routine_ret && op == c->routine_ret && r->sp == c->routine_sp)
            /* a callee run for the C routine that popped its own return address and the routine's (nonlocal exit): the RTS that returns into the routine's
             * caller runs at routine S + the routine's unwinding pop, the same place where the original ends (end rule above, seen from the nested run) */
            || (c->allow_unwind && c->routine_ret && op == c->routine_ret && r->sp == (uint16_t)(c->routine_sp + SOM_UNW_N(c->routine_ret))))) {  /* nested returns of callees run normally */
            if (r->sp != entry_sp) c->unwound = 1; /* the callee dropped its own return address (PLA, PLA) and returned to our caller */
            if (getenv("SOM_DEBUG")) fprintf(stderr, "run ends at the return rule: op %02X at %02X:%04X S %04X entry_sp %04X depth %d dropped %d allow %d routine_ret %02X routine_sp %04X\n", op, r->k, r->pc, r->sp, entry_sp, depth, dropped, c->allow_unwind, c->routine_ret, c->routine_sp);
            cpu_runOpcode(r);
            return;
        }
        if (getenv("SOM_RETTRACE") && (op == 0x60 || op == 0x6B || op == 0x40)) fprintf(stderr, "RET op %02X at %02X:%04X S %04X entry_sp %04X depth %d dropped %d allow %d\n", op, r->k, r->pc, r->sp, entry_sp, depth, dropped, c->allow_unwind);
        if (op == 0xCB && c->ev_next < c->ev_n && c->ev_mode) { /* WAI: sleeps until the interrupt the capture saw */
            r->pc++;
            deliver_next(c);
            continue;
        }
        if (op == 0x00 || op == 0x02 || op == 0xCB || op == 0xDB || (op == 0x40 && !c->rti_ok && !c->cont)) { c->fail = 1; if (getenv("SOM_DEBUG")) fprintf(stderr, "oracle stopped on opcode %02X at %02X:%04X (S %04X entry_sp %04X depth %d allow %d routine_ret %02X routine_sp %04X dropped %d)\n", op, r->k, r->pc, r->sp, entry_sp, depth, c->allow_unwind, c->routine_ret, c->routine_sp, dropped); return; }
        uint32_t before = ((uint32_t)r->k << 16) | r->pc;
        if (c->cmplog) { c->lr[0] = c->lr[1] = -1; c->ea[0] = c->ea[1] = 0xFFFFFFFFu; c->nlw = 0; }
        const uint16_t pre_a = r->a, pre_x = r->x, pre_y = r->y; const uint8_t pre_mf = r->mf, pre_xf = r->xf;
        const uint32_t pre_ncmp = c->ncmp;
        cpu_runOpcode(r);
        if ((op == 0x20 || op == 0x22 || op == 0xFC) && som_calltrace_on()) { fprintf(stderr, "ICALL %02X%04X from %06X sp %04X ev %u/%u", r->k, r->pc, before, r->sp, c->ev_next, c->ev_n); som_calltrace_state(c); }
        if (c->cmplog) cmp_note(c, op, before, pre_a, pre_x, pre_y, pre_mf, pre_xf);
        if (c->brlog && c->cmplog) brf_note(c, op, before, pre_ncmp, pre_x, pre_y);
        if (c->stub_calls && depth == 0 && (op == 0x20 || op == 0x22 || op == 0xFC)) { /* callee abstracted: the call returns at once (push then pull of the return address, as JSR followed by RTS/RTL) */
            const int lng = op == 0x22; uint16_t l, h; uint8_t bk = r->k;
            r->sp++; if (r->e) r->sp = (r->sp & 0xFF) | 0x100; l = som_rd(c, r->sp);
            r->sp++; if (r->e) r->sp = (r->sp & 0xFF) | 0x100; h = som_rd(c, r->sp);
            r->pc = (uint16_t)((l | (h << 8)) + 1);
            if (lng) { r->sp++; if (r->e) r->sp = (r->sp & 0xFF) | 0x100; bk = som_rd(c, r->sp); r->k = bk; }
            c->stub_n++;
            continue;
        }
        if (op == 0x20 || op == 0x22 || op == 0xFC) depth++; else if ((op == 0x60 || op == 0x6B) && depth > 0) depth--;
        if ((c->ev_mode == 2 || c->ev_mode == 3) && c->ev_next < c->ev_n && op != 0x60 && op != 0x6B && ((((uint32_t)r->k << 16) | r->pc) <= before) && spin_check(c)) deliver_next(c);
        if (c->hook_impls && is_jump_op(op)) {
            const SomImpl *im = som_find_impl(((uint32_t)r->k << 16) | r->pc, NULL);
            if (im && im->ret_op == ((op == 0x22 || op == 0x5C || op == 0xDC) ? SOM_RTL : SOM_RTS)) {
                im->fn(c);
                if (op == 0x20 || op == 0x22 || op == 0xFC) { if (depth > 0) depth--; }
                if (op == 0x4C || op == 0x5C || op == 0x6C || op == 0x7C || op == 0xDC) return;
            }
        }
    }
}

uint8_t *som_poll_hook(SomCtx *c, uint32_t off) {
    if ((c->ev_mode == 2 || c->ev_mode == 3) && c->ev_next < c->ev_n && ++c->pollctr > 2000000) { c->pollctr = 0; deliver_next(c); }
    __asm__ volatile("" ::: "memory");
    return &c->wram[off & 0x1FFFF];
}

/* A pure wait on one address (read after read of the same byte with the same value, no other polled access in between) is the spin the interpreter detects
 * on its second pass: the recorded interrupt lands after 256 such reads instead of after 2,000,000 accesses (a wait that needs one interrupt per iteration
 * would otherwise spend the 2 s watchdog on a few hundred of them).  The state does not change during the wait, so the delivery point is equivalent. */
void som_poll_spin(SomCtx *c, uint32_t a, uint8_t v) {
    static int off = -1; if (off < 0) off = getenv("SOM_POLLSPIN") ? 0 : 1; /* opt-in: the default changed verdicts of C01D97, C0ABB3, C1CAE7 (hwA-r15-ab2, poll1, poll2) */
    if (off || !(c->ev_mode == 2 || c->ev_mode == 3) || c->ev_next >= c->ev_n) return;
    if (c->pr_seq + 1 == c->pollctr && c->pr_addr == a && c->pr_val == v) {
        if (++c->pr_n >= 256) { c->pollctr = 0; c->pr_n = 0; c->pr_seq = ~0ull - 1; deliver_next(c); return; }
    } else { c->pr_addr = a; c->pr_val = v; c->pr_n = 0; }
    c->pr_seq = c->pollctr;
}

/* after the routine returned: interrupts that never landed inside it are delivered now */
void som_flush_events(SomCtx *c) {
    c->ev_inside = c->ev_next; c->ev_inside_valid = 1;
    if (getenv("SOM_EVCHECK") && c->ev_mode == 1) fprintf(stderr, "EVCHECK %u handlers run, %u reproduce the recorded delta, %u read mismatches\n", c->handler_runs, c->handler_ok, c->handler_bad);
    if (getenv("SOM_DEBUG") && c->rp && c->ev_mode == 1) {
        for (unsigned ix = 0; ix < 0x300; ix++) {
            uint64_t left = 0;
            for (uint32_t r = c->rp_run[ix]; r < c->rp->n[ix]; r++) left += c->rp->run[ix][r].reps;
            left -= c->rp_off[ix] && c->rp_run[ix] < c->rp->n[ix] ? c->rp_off[ix] : 0;
            if (left) fprintf(stderr, "replay leftover reg %04X: %llu reads unused\n", ix >= 0x200 ? 0x4000 + (ix & 0xFF) : 0x2100 + (ix & 0xFF), (unsigned long long)left);
        }
    }
    if (getenv("SOM_DEBUG")) fprintf(stderr, "flush: mode %d ran %llu insns, %u of %u events delivered\n", c->ev_mode, (unsigned long long)c->ev_steps, c->ev_next, c->ev_n);
    c->run_handlers = 0; /* the routine has returned: the rest of the interrupts are applied as recorded */
    while (c->ev_next < c->ev_n) deliver_next(c);
}

/* WAI of generated C: the processor sleeps until the next interrupt the capture recorded and that interrupt is delivered now (the interpreter does the same at
 * opcode $CB).  With no event left in a deferred mode the original would sleep forever: the C run ends as a failed run, like the oracle's `fail = 1`. */
void som_wai(SomCtx *c) {
    if ((c->ev_mode == 2 || c->ev_mode == 3) && c->ev_next < c->ev_n) { deliver_next(c); c->wepoch++; return; }
    c->fail = 1;
    if (c->stop_hook) c->stop_hook();
}

/* mode 2: a C routine that swapped the stack itself (an inline TCS) is past the switch when it calls out: the callee is an ordinary call */
static void task_lazy_switch(SomCtx *c) {
    if (c->task_mode == 2 && !c->switched) {
        const int d = (int)c->cpu.sp - (int)c->task_s;
        if (d >= 0x100 || d <= -0x100 || (c->cont && (c->cpu.sp >> 8) != (c->task_s >> 8))) c->switched = 1;
    }
}

void som_task_note(SomCtx *c) { task_lazy_switch(c); }

/* SOM_CALLTRACE: registers and a hash of WRAM at a call, printed by the C runs (call_impl) and by the interpreter at JSR/JSL alike, so two runs can be compared call by call */
static void som_calltrace_state(const SomCtx *c) {
    uint64_t h = 1469598103934665603ull;
    for (uint32_t i = 0; i < SOM_WRAM_SIZE; i++) h = (h ^ c->wram[i]) * 1099511628211ull;
    const Cpu *r = &c->cpu;
    fprintf(stderr, " A=%04X X=%04X Y=%04X D=%04X DB=%02X M%d X%d wram=%016llx\n", r->a, r->x, r->y, r->dp, r->db, r->mf, r->xf, (unsigned long long)h);
}

static int som_calltrace_on(void) { static int v = -1; if (v < 0) v = getenv("SOM_ICALLTRACE") ? 1 : 0; return v; }
static void call_impl(SomCtx *c, uint32_t target, uint8_t ret_op, int allow_unwind) {
    task_lazy_switch(c);
    if (getenv("SOM_CALLTRACE")) { fprintf(stderr, "CALL %06X ret %02X sp %04X allow %d ev %u/%u k %02X", target, ret_op, c->cpu.sp, allow_unwind, c->ev_next, c->ev_n, c->cpu.k); som_calltrace_state(c); }
    if ((c->ev_mode == 2 || c->ev_mode == 3) && c->ev_next < c->ev_n && !c->hook_impls) {
        /* a C routine that keeps calling the same code with nothing changed in between is waiting for an interrupt */
        const uint8_t save_k = c->cpu.k; const uint16_t save_pc = c->cpu.pc; /* the probe must not leave the caller in the callee's bank mirror ($C0 for $00): later JSR/PHK/JSL would run and push the wrong bank */
        c->cpu.k = (target >> 16) & 0xFF; c->cpu.pc = target & 0xFFFF;
        const int spinning = spin_check(c);
        c->cpu.k = save_k; c->cpu.pc = save_pc;
        if (spinning) deliver_next(c);
    }
    const SomImpl *im = c->hook_impls ? som_find_impl(target, NULL) : NULL;
    /* a JSR keeps the bank it runs in when the target is its bank mirror ($00 and $C0 hold the same code) */
    const uint8_t tbank = (target >> 16) & 0xFF;
    const uint8_t nbank = (allow_unwind && ret_op == SOM_RTS && ((c->cpu.k ^ tbank) & 0x3F) == 0) ? c->cpu.k : tbank;
    if (c->nexit && c->exit_need <= 1 && som_is_exit(c, ((uint32_t)nbank << 16) | (target & 0xFFFF))) { /* the call goes to an exit address: the window ends here, at the target, return address already pushed */
        c->cpu.k = nbank; c->cpu.pc = target & 0xFFFF; c->exited = 1; c->unwound = 1;
        return;
    }
    if (im && im->ret_op == ret_op) {
        const uint16_t psp = c->routine_sp; const uint8_t pret = c->routine_ret;
        const uint16_t esp = c->cpu.sp;
        c->cpu.k = nbank; c->cpu.pc = target & 0xFFFF; im->fn(c);
        c->routine_sp = psp; c->routine_ret = pret;
        if (c->switched && c->cont && c->cont->jump(c, c->cont->user)) { c->rti_ok = 1; /* a C routine that swapped the task returned: continuation capture, the task was resumed */ }
        /* a C routine that left the stack above its own return address dropped frames of its caller: the caller must return at once */
        if (allow_unwind) c->unwound = c->switched || c->cpu.sp != (uint16_t)(esp + (ret_op == SOM_RTS ? 2 : 3));
        return;
    }
    c->cpu.k = nbank;
    c->cpu.pc = target & 0xFFFF;
    const int prev_allow = c->allow_unwind;
    c->unwound = 0;
    c->allow_unwind = allow_unwind;
    som_interp_run(c, ret_op, c->cpu.sp);
    c->allow_unwind = prev_allow;
    if (c->exited) c->unwound = 1; /* a callee reached an exit address: the whole call chain ends there */
}

/* Tail call made with `depth` bytes of the caller's own pushes still on the stack: the callee pops them and returns to our
 * caller, so the call ends at the stack pointer the routine was entered with. */
void som_call_frame(SomCtx *c, uint32_t target, uint8_t ret_op, uint16_t depth) {
    task_lazy_switch(c);
    const uint16_t entry_sp = (uint16_t)(c->cpu.sp + depth);
    c->cpu.k = (target >> 16) & 0xFF;
    c->cpu.pc = target & 0xFFFF;
    if (c->nexit && c->exit_need <= 1 && som_is_exit(c, target)) { c->exited = 1; c->unwound = 1; return; }
    const int prev_allow = c->allow_unwind;
    c->unwound = 0;
    c->allow_unwind = 0;
    som_interp_run(c, ret_op, entry_sp);
    c->allow_unwind = prev_allow;
    if (c->exited) c->unwound = 1;
}

/* Tail call: the callee returns to our caller, so it runs exactly like the original code would. */
void som_call(SomCtx *c, uint32_t target, uint8_t ret_op) { call_impl(c, target, ret_op, 0); }

/* JSR/JSL from a C routine: a callee that drops its own return address and returns to our caller ends the call with
 * c->unwound set, and the C routine returns immediately. */
void som_call_nested(SomCtx *c, uint32_t target, uint8_t ret_op) { call_impl(c, target, ret_op, 1); }
