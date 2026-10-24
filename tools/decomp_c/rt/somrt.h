/* T3 differential-test runtime: a bus model, an instruction-level oracle (LakeSnes 65816 core, MIT licence)
 * and the registry/dispatch used by C implementations of 65816 routines.
 *
 * Convention: a C implementation of a routine runs from the entry state (return address already pushed by
 * the caller, as in the original) to the point just after its RTS/RTL, exactly like the original code.
 */
#ifndef SOMRT_H
#define SOMRT_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cpu.h"

#define SOM_RTS 0x60
#define SOM_RTL 0x6B
#define SOM_RTI 0x40
#define SOM_WRAM_SIZE 0x20000u
#define SOM_MAX_IO 131072
#define SOM_MAX_EVENTS 64
#define SOM_MAX_DELTA 65536

typedef struct SomCtx SomCtx;
/* one executed compare / bit test: kind 0 CMP, 1 CPX, 2 CPY, 3 BIT/TSB/TRB/AND-style test; wide = 16 bit operands; reg = register value, mem = operand value;
 * maddr = WRAM offset of the memory operand (-1 immediate), src = WRAM offset the register was loaded from (-1 unknown) */
typedef struct SomCmp { uint32_t pc; uint8_t kind, wide; uint16_t reg, mem; int32_t maddr, src; } SomCmp;
#define SOM_CMPLOG_MAX 512
/* branch-flip search (difftest SOM_FUZZ_BRFLIP): one executed conditional branch with the flag setter that decided it.
 * setk: 0 CMP, 1 CPX, 2 CPY, 3 BIT/AND-style test, 4 ADC/SBC (same meaning as SomCmp.kind), 5 load/logic/inc/dec/shift/transfer result
 * (reg = result), 6 none known (flag set by CLC/SEC/REP/SEP/PLP...).  src/maddr as in SomCmp; fz/fn/fc/fv = flags when the branch ran. */
/* where a register's value was read from when it came from ROM (so no WRAM byte can be changed to alter it): kind 1 = through a direct-page
 * pointer (ptr = WRAM offset of its low byte, plen bytes, iv = the index added), kind 2 = from a table indexed by X or Y (base = address of
 * index 0, idxsrc = WRAM offset the index was loaded from or -1, idxreg 1 X / 2 Y, iw = index is 16 bit); ea = the address that was read */
typedef struct SomProv { uint8_t valid, kind, wide, plen, idxreg, iw; uint16_t iv; uint32_t ea, base; int32_t ptr, idxsrc; } SomProv;
typedef struct SomBr { uint32_t pc; uint8_t op, taken, setk, wide; uint16_t reg, mem; int32_t maddr, src; uint8_t fz, fn, fc, fv; SomProv pv; } SomBr;
#define SOM_BRLOG_MAX 2048
void som_shadow_reset(void); /* branch-flip search: forget the values tracked through WRAM stores */
typedef void (*SomFn)(SomCtx *);

typedef struct { uint32_t addr; uint8_t val; uint8_t write; uint16_t pc; /* PC when logged (diagnostics only) */ } SomIo;
/* recorded hardware reads of one register, run-length coded: the values the real run saw, in order */
typedef struct { uint8_t val; uint32_t reps; } SomRpRun;
typedef struct { SomRpRun *run[0x300]; uint32_t n[0x300]; } SomRp;
/* one interrupt (NMI/IRQ handler run) the capture took inside the routine: bytes of WRAM it changed and the hardware
 * state it left behind (mul/div unit, WRAM port address) */
typedef struct SomHRead { uint32_t addr; uint8_t val; uint32_t reps; } SomHRead;
typedef struct {
    uint32_t at;         /* instructions of the routine completed before the interrupt */
    uint32_t hwat;       /* replayed hardware reads (polls) the routine had consumed before it */
    uint32_t ndelta;
    const uint32_t *delta; /* (value << 24) | WRAM offset */
    uint8_t has_hw;
    uint32_t wmadd; uint8_t wrmpya; uint16_t wrdiv, rddiv, rdmpy;
    uint8_t dma[0x80], hdmaen;
    uint32_t kind;       /* 0 NMI, 1 IRQ, 2 scenario WRAM write by the capture driver (delta only): the capture core's interrupt kind */
    uint32_t lag;        /* instructions run since the last replayed read when the exact replay delivered it (learned) */
    const struct SomHRead *hq; uint32_t nhq; /* the reads the real handler made, in order: the handler is executed with them */
    uint16_t sp; uint8_t sp_ok; /* S when the interrupt was taken (learned from the exact replay): the handler's own pushes below it are dead stack */
} SomEvent;

/* live-out register bits for non-strict implementations */
enum { L_A = 1, L_X = 2, L_Y = 4, L_C = 8, L_Z = 16, L_N = 32, L_V = 64, L_B = 128, L_ALL = 255 };
enum { SOM_STRICT = 1, SOM_HWMATH_PURE = 2, SOM_UNWINDS = 4 /* the routine drops its own return address: the oracle stops at the unwinding return */,
       SOM_POLLS = 8 /* built with SOM_POLL_HOOK (waits on WRAM for an interrupt): the interrupts taken before the return are part of the compared state */ };
#ifdef SOM_POLL_HOOK
#define SOM_POLLS_FLAG SOM_POLLS
#else
#define SOM_POLLS_FLAG 0
#endif

typedef struct {
    uint32_t addr;       /* normalised entry address (C0-FF bank) */
    uint8_t ret_op;      /* SOM_RTS or SOM_RTL */
    const char *variant; /* "lift", "hand", ... */
    SomFn fn;
    uint32_t flags;      /* SOM_STRICT: compare every register, flag and stack byte */
    uint32_t live;       /* L_* mask compared when not strict */
    uint32_t stack_free; /* bytes below the entry S that may differ when not strict */
    int8_t m, x;         /* accumulator/index width flags at entry (1 = 8 bit, -1 unknown) */
    uint16_t size, ninsn; /* routine extent in bytes and instruction count (0 when unknown) */
} SomImpl;

/* Continuation windows (capture header bit 23, difftest.c): a replayed capture that spans task switches.  When a run reaches the end of a swap-out window (the first
 * RTS/RTL at depth 0 on the new stack, the state a "swret" capture closes at), `jump` compares the run with the capture's state there and loads the state the capture
 * had when the task was resumed; it returns 1 when it did, and the run goes on as the resumed task (SomCtx.switched and .unwound are cleared by it). */
typedef struct SomCont { void *user; int (*jump)(SomCtx *c, void *user); } SomCont;

struct SomCtx {
    Cpu cpu;
    uint8_t wram[SOM_WRAM_SIZE];
    uint8_t sram[0x8000];
    const uint8_t *rom;
    size_t rom_size;
    uint32_t wmadd;
    uint8_t wrmpya;
    uint16_t wrdiv, rddiv, rdmpy;
    uint8_t v1log;       /* the hardware log of this state comes from a format-1 capture (reverse-DMA reads were logged only once per transfer) */
    uint8_t dma_rd;      /* inside the B-bus read loop of a DMA */
    uint8_t short_replay; /* a DMA wanted more reads than the format-1 log holds: the capture cannot be replayed */
    uint8_t wd_unk, wm_unk; /* format-1 capture without a hardware snapshot: bit 0/1 = dividend byte, wm_unk = multiplicand not written since entry */
    uint8_t rd_unk;      /* bit n: math result byte $4214+n has no defined value yet (format-1 capture without a hardware snapshot): the first recorded read supplies it */
    SomIo io[SOM_MAX_IO];
    uint32_t nio;
    uint8_t *rdset;      /* optional 128 KiB map of WRAM bytes read */
    uint8_t *kset;       /* optional 256-entry set of the operand bytes that executed instructions carry (compare constants, masks) */
    struct SomCmp *cmplog; /* optional (coverage search): compares and bit tests the run executed, with the WRAM bytes the compared registers were loaded from */
    uint32_t ncmp;
    struct SomBr *brlog; /* optional (branch-flip search, needs cmplog too): conditional branches the run executed */
    uint32_t nbr;
    struct SomBr lastset; /* the flag setter that decides the next conditional branch */
    uint32_t ea[2];      /* addresses of the last two data reads (0xFFFFFFFF none), like lr but for every address space */
    struct SomProv prov[3]; /* ROM provenance of A, X, Y (branch-flip search) */
    int32_t lr[2];       /* WRAM offsets of the last two data reads (-1 none): the operand of the instruction that just ran */
    int32_t src[3];      /* WRAM offset a register was loaded from (A, X, Y), -1 unknown */
    int32_t lw[2]; uint32_t nlw; /* WRAM offsets of the first two data writes of the instruction that just ran (branch-flip search only) */
    uint8_t *wrset;      /* optional 128 KiB map of WRAM bytes written */
    uint8_t *srdset;     /* optional 8 KiB map of SRAM bytes read */
    uint32_t hw_rd_mask; /* hardware state the run read (outside peeks and interrupt handlers): 1 replayed register, 2 SRAM, 4 DMA channel register */
    uint8_t *fetchset;   /* optional 128 KiB map of WRAM bytes fetched as instructions (each fetch marks 4 bytes) */
    int peek;            /* suppress I/O logging while peeking */
    int hook_impls;      /* dispatch to registered implementations for callees */
    int fail;            /* interpreter ran away or hit an unsupported state */
    int allow_unwind;    /* inside som_call: an RTS/RTL executed after the callee dropped its own return address ends the call */
    uint16_t routine_sp; /* S of the routine under test at its entry and its return opcode (0 = none): a callee returning through it ends the routine */
    uint8_t routine_ret;
    uint32_t rp_over;    /* replayed reads taken after the recorded ones of their register were used up */
    void (*stop_hook)(void); /* set by difftest: ends the run of the C routine under test (siglongjmp to the watchdog) */
    uint8_t routine_unw; /* the routine under test is an unwinder (SOM_UNWINDS): it may drop its own return address, so the rule above needs the dropped-frame bookkeeping */
    uint16_t sp_max;     /* highest S seen at an instruction boundary of the top-level run (difftest: did the routine drop its own return address?) */
    int s9x_quirk;       /* the run executed a 16-bit LDX/LDY that reads across a bank boundary: Snes9x wraps it, so a capture is no reference there */
    const SomCont *cont; /* continuation capture being replayed (NULL = none), see SomCont */
    uint8_t task_mode;   /* TASK capture: the call ends where S leaves the entry S by 0x100 or more (cooperative task switch), see somrt.c */
    uint8_t switched;    /* the task switch happened: unwound is set too, so every C caller returns at once */
    uint16_t task_s;     /* entry S of a TASK window */
    uint8_t stub_calls;  /* difftest SOM_STUBCALLS: every JSR/JSL of the routine under test returns at once (oracle and C alike), callee effects abstracted */
    uint32_t stub_n;
    int unwound;         /* set by som_call when the callee returned past its own caller (the C routine must return at once) */
    /* exit-address windows (capture header bit 20, "exit=ADDR"): the run ends, before the instruction runs, when control reaches one of these
     * normalised addresses.  A call, tail jump or interpreted instruction at an exit address sets `exited` (and `unwound`, so the C routine returns at once) */
    uint32_t exit_addr[8]; uint8_t nexit; uint8_t exited; uint32_t exit_need, exit_seen; /* "exit=ADDR@N" window: the run ends at the N-th arrival at the exit address (0 or 1: the first) */
    uint8_t c_run; /* set while a C routine runs on this context (guarded()) */
    uint8_t exit_only; /* replay of an exit-address window: the top-level oracle run (c_run == 0) ends at the exit address only, no return opcode ends it (the routine may reset S so that a callee's RTS looks like its own); the C run's nested calls keep the return rule */
    uint64_t steps;
    uint64_t step_limit;
    uint32_t *wlog;      /* optional: records (address << 8 | value) of WRAM writes */
    uint32_t wlog_n, wlog_cap;
    uint8_t *execmap;    /* optional: marks executed instruction starts in [exec_base, exec_base + exec_len) */
    uint32_t exec_base, exec_len;
    /* replay of the hardware reads recorded by the Snes9x capture (APU ports, PPU status, $4210-$421F): the same
     * sequence of values the real run saw, so wait loops on hardware terminate identically */
    const SomRp *rp;
    uint32_t rp_run[0x300], rp_off[0x300];
    uint8_t rp_last[0x300];
    int has_sram;        /* the SRAM image is meaningful (taken from the capture) and takes part in comparisons */
    uint8_t apu_out[4];  /* last value written to $2140-$2143: the APU handshake echoes it once the recorded reads are used up */
    uint8_t dmareg[0x80]; /* $4300-$437F: DMA/HDMA channel registers (readable, A-bus pointer and count are updated by a transfer) */
    uint8_t hdmaen;      /* $420C */
    uint8_t open_bus;    /* last byte seen on the data bus by the interpreter: write-only registers read back as this */
    uint8_t ppu_ob1, ppu_ob2; int have_ppu_ob, ob_unknown, rti_ok; /* PPU1/PPU2 open-bus latches from the capture (trailer SCP5): write-only $2100-$2133 read back ppu_ob1 */
    int wram_dma;        /* a DMA with a WRAM source is running: $2180-$2183 ignore the transfer */
    /* interrupts the real run took during the capture (see difftest.c): handler effects delivered to the interpreter */
    const SomEvent *ev;  /* events of the capture, in order */
    uint32_t ev_n, ev_next;
    int ev_mode;         /* 0 none, 1 exact: at the recorded instruction count, 2 deferred: when the code spins or when it returns,
                          * 3 anchored: right after the same replayed read, as many instructions later as the exact replay needed */
    uint64_t ev_steps;   /* instructions executed since the first event check (exact mode) */
    uint32_t rp_count;   /* replayed hardware reads consumed so far */
    uint64_t last_read_steps; /* ev_steps when the last replayed read completed */
    uint32_t ev_inside; uint8_t ev_inside_valid; /* interrupts delivered before the run returned (set by som_flush_events) */
    uint64_t pollctr;    /* RAM accesses made by the C routine since the last interrupt delivery (SOM_POLL_HOOK builds) */
    uint64_t wepoch;     /* incremented by every memory or hardware write: spin detection */
    struct { uint32_t pc; uint16_t a, x, y, s, d; uint8_t p, db; uint64_t epoch; } spin[64];
    uint8_t sram_wr[0x8000]; /* SRAM bytes written (diagnostics) */
    /* exact mode runs the interrupt handler itself (from the vector) with the hardware reads the real handler made */
    int in_handler;      /* a handler is running: its I/O writes are not part of the routine's write list */
    const SomEvent *hev; uint32_t hq_i, hq_rep; /* handler read queue position */
    int run_handlers;    /* exact mode: deliver interrupts by executing the handler (disabled for deliveries after the routine returned) */
    uint32_t handler_runs, handler_ok, handler_bad; /* diagnostics */
};

/* index of the replay stream of a register: $2100-$21FF -> 0x00-0xFF, $4210-$421F -> 0x210-0x21F, $4016/$4017 -> 0x2F6/0x2F7 */
static inline unsigned som_rp_index(uint32_t low) { return low == 0x4016 || low == 0x4017 ? 0x2F0 + (low & 0xF) : low >= 0x4000 ? 0x200 + (low & 0xFF) : (low & 0xFF); }
void som_deliver_event(SomCtx *c, const SomEvent *e);
void som_flush_events(SomCtx *c);
uint8_t *som_poll_hook(SomCtx *c, uint32_t off);
void som_wai(SomCtx *c); /* WAI: deliver the next recorded interrupt; no event left = failed run */
void som_ctx_init(SomCtx *c, const uint8_t *rom, size_t rom_size);
uint8_t som_rd(SomCtx *c, uint32_t adr);
void som_wr(SomCtx *c, uint32_t adr, uint8_t v);
uint32_t som_norm(uint32_t a);
int som_is_exit(const SomCtx *c, uint32_t addr);

void som_register(const SomImpl *impl);
const SomImpl *som_find_impl(uint32_t addr, const char *variant);
size_t som_impl_count(void);
const SomImpl *som_impl_at(size_t i);

/* Run original code from c->cpu.k:pc until the matching RTS/RTL (S == entry_sp) has executed. */
extern int som_trace_left;
extern int som_unwind_n;
void som_interp_run(SomCtx *c, uint8_t ret_op, uint16_t entry_sp);
int som_is_exit(const SomCtx *c, uint32_t addr);
/* A C routine that spins in place at the original address `addr` (a branch to itself, `for (;;) {}`) asks here whether the capture window ends at that address:
 * if it does the call is over, with K:PC set as the interpreter would have left them.  Usage in a spin: `for (;;) { if (som_spin_exit(c, 0x7ED46E)) return; }` */
/* one arrival of the control flow at `addr` (the instruction is about to run): true when the window ends here */
static inline int som_exit_arrive(SomCtx *c, uint32_t addr) {
    if (!c->nexit || !som_is_exit(c, addr)) return 0;
    return ++c->exit_seen >= (c->exit_need ? c->exit_need : 1u);
}
static inline int som_spin_exit(SomCtx *c, uint32_t addr) {
    if (!som_exit_arrive(c, addr)) return 0;
    c->cpu.k = (uint8_t)(addr >> 16); c->cpu.pc = (uint16_t)addr; c->exited = 1;
    return 1;
}
/* Call target as the 65816 would after the caller pushed the return address. */
void som_call(SomCtx *c, uint32_t target, uint8_t ret_op);
void som_call_nested(SomCtx *c, uint32_t target, uint8_t ret_op);
void som_call_frame(SomCtx *c, uint32_t target, uint8_t ret_op, uint16_t depth);
/* TASK windows (mode 2): call right after a stack swap (TCS) so that the swap is latched like the oracle does, even if S comes back within 0x100 of the entry S before the return */
void som_task_note(SomCtx *c);

#define SOM_REGISTER(ADDR, RET, VARIANT, FN, FLAGS, LIVE, STACKFREE, M, X, SIZE, NINSN) \
    static void __attribute__((constructor)) som_reg_##FN(void) { \
        static const SomImpl d = { ADDR, RET, VARIANT, FN, (FLAGS) | SOM_POLLS_FLAG, LIVE, STACKFREE, M, X, SIZE, NINSN }; som_register(&d); }

#endif
