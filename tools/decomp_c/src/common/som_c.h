/* Common definitions for the readable C routines of tools/decomp_c/src.
 *
 * A routine is a function `static void name(SomCtx *c)` that starts in the entry state of the original code (return
 * address already pushed) and ends with RETURN_RTS / RETURN_RTL.  Registers live in c->cpu (`r`); a routine reads
 * the inputs it needs once and writes back only what its callers read (see the header comment of each file).
 * Memory is the 128 KiB WRAM image (`ram`, offsets $7E:0000-$7F:FFFF) or, for ROM, SRAM and hardware, the bus.
 */
#ifndef SOM_C_H
#define SOM_C_H
#include "somlift.h"
#include "wram_names.h"

/* data bank / register assumptions are checked, not silently trusted; fail = 3 means "input outside the contract" */
static inline int hand_require(SomCtx *c, int db, int m, int x) {
    Cpu *r = &c->cpu;
    if ((db >= 0 && r->db != db) || (m >= 0 && r->mf != m) || (x >= 0 && r->xf != x)) { c->fail = 3; return 0; }
    return 1;
}

/* WRAM access; offsets wrap at 128 KiB like the linear $7E:0000-$7F:FFFF space */
#ifdef SOM_POLL_HOOK
/* test builds of routines that wait for an interrupt: every WRAM access goes through the harness, which can deliver the
 * recorded interrupt when the C code spins on memory (see rt/somrt.c som_poll_hook) */
#define RAM8(off) (*som_poll_hook(c, (off)))
#define RAM16(off) ((uint16_t)(*som_poll_hook(c, (off)) | (*som_poll_hook(c, (off) + 1) << 8)))
#define RAM16_SET(off, v) do { uint16_t v_ = (v); uint32_t o_ = (off); *som_poll_hook(c, o_) = v_ & 0xFF; *som_poll_hook(c, o_ + 1) = v_ >> 8; } while (0)
/* a wait on a WRAM byte through the bus helpers (computed or direct-page-relative address) spins the same way */
static inline uint8_t som_rd_polled(SomCtx *c, uint32_t a) { (void)som_poll_hook(c, 0); const uint8_t v = som_rd(c, a); som_poll_spin(c, a, v); return v; }
#define som_rd(c, a) som_rd_polled((c), (a))
#else
#define RAM8(off) ram[(off) & 0x1FFFF]
#define RAM16(off) ((uint16_t)(ram[(off) & 0x1FFFF] | (ram[((off) + 1) & 0x1FFFF] << 8)))
#define RAM16_SET(off, v) do { uint16_t v_ = (v); uint32_t o_ = (off); ram[o_ & 0x1FFFF] = v_ & 0xFF; ram[(o_ + 1) & 0x1FFFF] = v_ >> 8; } while (0)
#endif
/* bus access (ROM, SRAM, hardware registers; every access is logged for the I/O comparison) */
/* A constant address is read as written.  A computed one (indexed) can land on the open bus, whose value is the last byte the
 * CPU fetched and which the C model does not track: such an input is outside the contract (fail = 3), see gen_rd_ok below. */
static inline int gen_rd_ok(uint32_t a);
static inline uint8_t som_bus8(SomCtx *c, uint32_t a) { a &= 0xFFFFFF; if (!gen_rd_ok(a)) { c->fail = 3; return 0; } return som_rd(c, a); }
#define BUS8(c, a) (__builtin_constant_p(a) ? som_rd((c), (a)) : som_bus8((c), (a)))
static inline uint16_t som_bus16(SomCtx *c, uint32_t a) { return (uint16_t)(som_rd(c, a) | (som_rd(c, a + 1) << 8)); }
static inline uint16_t som_bus16c(SomCtx *c, uint32_t a) { a &= 0xFFFFFF; uint32_t a1 = (a + 1) & 0xFFFFFF; if (!gen_rd_ok(a) || !gen_rd_ok(a1)) { c->fail = 3; return 0; } return som_bus16(c, a); }
#define BUS16(c, a) (__builtin_constant_p(a) ? som_bus16((c), (a)) : som_bus16c((c), (a)))
#define BUS8_SET(c, a, v) som_wr((c), (a), (v))
/* 16-bit read-modify-write stores the high byte first */
#define BUS16_RMW_SET(c, a, v) do { uint16_t v_ = (v); uint32_t ba_ = (a); som_wr((c), ba_ + 1, v_ >> 8); som_wr((c), ba_, v_ & 0xFF); } while (0)
/* the address expression is evaluated once: the first byte store may change the memory it was computed from */
#define BUS16_SET(c, a, v) do { uint16_t v_ = (v); uint32_t ba_ = (a); som_wr((c), ba_, v_ & 0xFF); som_wr((c), ba_ + 1, v_ >> 8); } while (0)

/* Reads through a computed address (generated routines).  A pointer the routine did not set up can aim at bus addresses that
 * the C model does not reproduce (open bus, unmodelled registers); such inputs are outside the contract (fail = 3, 0 is
 * returned).  For LDA [dp] / LDA [dp],Y the open bus is the pointer's bank byte (RDL: `latch`); the second byte of a
 * 16-bit read sees the first one. */
static inline int gen_rd_ok(uint32_t a)
{
    uint32_t bank = (a >> 16) & 0xFF, low = a & 0xFFFF;
    if (bank == 0x7E || bank == 0x7F || (bank >= 0x40 && bank < 0x7E) || bank >= 0xC0) return 1;
    if (low < 0x2000 || low >= 0x8000) return 1;
    if (low >= 0x6000) return (bank & 0x3F) >= 0x20;   /* SRAM */
    return (low >= 0x2134 && low <= 0x2143) || low == 0x2180 || low == 0x4016 || low == 0x4017 ||
           (low >= 0x4210 && low <= 0x421F) || (low >= 0x4300 && low < 0x4380);
}
static inline int gen_open_ok(uint32_t a)
{
    uint32_t bank = (a >> 16) & 0xFF, low = a & 0xFFFF;
    return (bank < 0x40 || (bank >= 0x80 && bank < 0xC0)) && ((low >= 0x2200 && low < 0x4000) || (low >= 0x4380 && low < 0x6000));
}
static inline uint8_t som_rdl8(SomCtx *c, uint32_t a, uint8_t latch)
{
    a &= 0xFFFFFF;
    if (gen_rd_ok(a)) return som_rd(c, a);
    if (gen_open_ok(a)) return latch;
    c->fail = 3;
    return 0;
}
#define BUS8_RDP(c, a) som_rdl8((c), (a), 0)
#define BUS8_RDL(c, a, latch) som_rdl8((c), (a), (uint8_t)(latch))
static inline uint16_t som_rdl16(SomCtx *c, uint32_t a, uint8_t latch, int has_latch)
{
    a &= 0xFFFFFF;
    uint32_t a1 = (a + 1) & 0xFFFFFF;
    if (!has_latch && (!gen_rd_ok(a) || !gen_rd_ok(a1))) { c->fail = 3; return 0; }
    uint8_t lo = som_rdl8(c, a, latch);
    uint8_t hi = som_rdl8(c, a1, lo);
    return (uint16_t)(lo | (hi << 8));
}
#define BUS16_RDP(c, a) som_rdl16((c), (a), 0, 0)
#define BUS16_RDL(c, a, latch) som_rdl16((c), (a), (uint8_t)(latch), 1)

/* generated loops stop once they ran more iterations than the step limit of the run (see gen_c.loop_guard_line) */
#ifdef SOM_POLL_HOOK
/* the poll hook lets a spinning loop burn 2,000,000 accesses before it delivers the next recorded interrupt */
#define LOOP_GUARD(g) do { if (++(g) > c->step_limit + 2100000ull * (c->ev_n + 1)) { c->fail = 1; return; } } while (0)
#else
#define LOOP_GUARD(g) do { if (++(g) > c->step_limit) { c->fail = 1; return; } } while (0)
#endif

/* register helpers */
#define SET_A8(r, v) ((r)->a = ((r)->a & 0xFF00) | ((v) & 0xFF))


/* ADC / SBC in decimal mode, bit for bit like the interpreted core (carry and overflow come back through pointers) */
static inline uint8_t SOM_ADC8_DEC(uint8_t a, uint8_t v, int c, bool *co, bool *vo) {
    int result = (a & 0xf) + (v & 0xf) + c;
    if (result > 0x9) result = ((result + 0x6) & 0xf) + 0x10;
    result = (a & 0xf0) + (v & 0xf0) + result;
    *vo = (a & 0x80) == (v & 0x80) && (v & 0x80) != (result & 0x80);
    if (result > 0x9f) result += 0x60;
    *co = result > 0xff;
    return (uint8_t)result;
}
static inline uint8_t SOM_SBC8_DEC(uint8_t a, uint8_t v0, int c, bool *co, bool *vo) {
    uint8_t v = v0 ^ 0xff;
    int result = (a & 0xf) + (v & 0xf) + c;
    if (result < 0x10) result = (result - 0x6) & ((result - 0x6 < 0) ? 0xf : 0x1f);
    result = (a & 0xf0) + (v & 0xf0) + result;
    *vo = (a & 0x80) == (v & 0x80) && (v & 0x80) != (result & 0x80);
    if (result < 0x100) result -= 0x60;
    *co = result > 0xff;
    return (uint8_t)result;
}
static inline uint16_t SOM_ADC16_DEC(uint16_t a, uint16_t v, int c, bool *co, bool *vo) {
    int result = (a & 0xf) + (v & 0xf) + c;
    if (result > 0x9) result = ((result + 0x6) & 0xf) + 0x10;
    result = (a & 0xf0) + (v & 0xf0) + result;
    if (result > 0x9f) result = ((result + 0x60) & 0xff) + 0x100;
    result = (a & 0xf00) + (v & 0xf00) + result;
    if (result > 0x9ff) result = ((result + 0x600) & 0xfff) + 0x1000;
    result = (a & 0xf000) + (v & 0xf000) + result;
    *vo = (a & 0x8000) == (v & 0x8000) && (v & 0x8000) != (result & 0x8000);
    if (result > 0x9fff) result += 0x6000;
    *co = result > 0xffff;
    return (uint16_t)result;
}
static inline uint16_t SOM_SBC16_DEC(uint16_t a, uint16_t v0, int c, bool *co, bool *vo) {
    uint16_t v = v0 ^ 0xffff;
    int result = (a & 0xf) + (v & 0xf) + c;
    if (result < 0x10) result = (result - 0x6) & ((result - 0x6 < 0) ? 0xf : 0x1f);
    result = (a & 0xf0) + (v & 0xf0) + result;
    if (result < 0x100) result = (result - 0x60) & ((result - 0x60 < 0) ? 0xff : 0x1ff);
    result = (a & 0xf00) + (v & 0xf00) + result;
    if (result < 0x1000) result = (result - 0x600) & ((result - 0x600 < 0) ? 0xfff : 0x1fff);
    result = (a & 0xf000) + (v & 0xf000) + result;
    *vo = (a & 0x8000) == (v & 0x8000) && (v & 0x8000) != (result & 0x8000);
    if (result < 0x10000) result -= 0x6000;
    *co = result > 0xffff;
    return (uint16_t)result;
}

/* ADC / SBC whose decimal flag is only known at run time (a callee may have set it): binary result when d == 0, BCD result otherwise */
static inline uint8_t SOM_ADC8_AUTO(int d, uint8_t a, uint8_t v, int c, bool *co, bool *vo) {
    if (d) return SOM_ADC8_DEC(a, v, c, co, vo);
    const unsigned full = (unsigned)a + v + c; const uint8_t res = (uint8_t)full;
    *co = full > 0xFF; *vo = ((a ^ res) & (v ^ res) & 0x80) != 0; return res;
}
static inline uint8_t SOM_SBC8_AUTO(int d, uint8_t a, uint8_t v, int c, bool *co, bool *vo) {
    if (d) return SOM_SBC8_DEC(a, v, c, co, vo);
    const int diff = (int)a - v - (1 - c); const uint8_t res = (uint8_t)diff;
    *co = diff >= 0; *vo = ((a ^ v) & (a ^ res) & 0x80) != 0; return res;
}
static inline uint16_t SOM_ADC16_AUTO(int d, uint16_t a, uint16_t v, int c, bool *co, bool *vo) {
    if (d) return SOM_ADC16_DEC(a, v, c, co, vo);
    const unsigned full = (unsigned)a + v + c; const uint16_t res = (uint16_t)full;
    *co = full > 0xFFFF; *vo = ((a ^ res) & (v ^ res) & 0x8000) != 0; return res;
}
static inline uint16_t SOM_SBC16_AUTO(int d, uint16_t a, uint16_t v, int c, bool *co, bool *vo) {
    if (d) return SOM_SBC16_DEC(a, v, c, co, vo);
    const int diff = (int)a - v - (1 - c); const uint16_t res = (uint16_t)diff;
    *co = diff >= 0; *vo = ((a ^ v) & (a ^ res) & 0x8000) != 0; return res;
}

/* calls and returns (the 65816 JSR/JSL/RTS/RTL, including the return address bytes on the stack) */
#define JSR(c, retpc, target) I_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) I_JSL((c), (retpc), (target))
/* JSR/JSL to a subroutine translated in the same file: the same return-address protocol, a direct C call instead of the dispatcher */
#define JSR_LOCAL(c, retpc, fn) do { push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rts(c); } else { fn(c); if ((c)->unwound) return; } } while (0)
#define JSL_LOCAL(c, retpc, fn) do { push8(c, (c)->cpu.k); push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rtl(c); } else { fn(c); if ((c)->unwound) return; } } while (0)
/* JSR/JSL to a local subroutine, with the frame bookkeeping of a callee that drops return addresses.  After the call, c->unwound
 * means some callee below returned past its own caller.  SP tells where it ended: at the SP of the call (the callee returned to
 * this routine, which goes on), at this routine's own return (the caller of this routine goes on), or above (it keeps unwinding). */
#define JSR_SUB(c, retpc, fn, sp_in, rsz) do { const uint16_t sp_b_ = (c)->cpu.sp; push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rts(c); } else fn(c); \
        if ((c)->unwound) { if ((c)->cpu.sp == sp_b_) (c)->unwound = 0; \
            else { if ((c)->cpu.sp == (uint16_t)((sp_in) + (rsz))) (c)->unwound = 0; return; } } } while (0)
#define JSL_SUB(c, retpc, fn, sp_in, rsz) do { const uint16_t sp_b_ = (c)->cpu.sp; push8(c, (c)->cpu.k); push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rtl(c); } else fn(c); \
        if ((c)->unwound) { if ((c)->cpu.sp == sp_b_) (c)->unwound = 0; \
            else { if ((c)->cpu.sp == (uint16_t)((sp_in) + (rsz))) (c)->unwound = 0; return; } } } while (0)
#define RETURN_RTS(c) do { i_rts(c); return; } while (0)
#define RETURN_RTL(c) do { i_rtl(c); return; } while (0)
#define RETURN_RTI(c) do { i_rti(c); return; } while (0)
#define TAIL_CALL(c, target, ret) do { som_call((c), (target), (ret)); return; } while (0)
/* tail call to a computed target: the target may drop its caller's return address and return to the caller's caller */
#define TAIL_CALL_DYN(c, target, ret) do { som_call_nested((c), (target), (ret)); return; } while (0)
/* tail call with `depth` bytes of this routine's own pushes left on the stack for the callee to pop */
#define TAIL_CALL_FRAME(c, target, ret, depth) do { (c)->cpu.sp -= (depth); som_call_frame((c), (target), (ret), (depth)); return; } while (0)
/* call guards and the other helpers shared by generated and hand-corrected routines */
#include "som_hand_b.h"
#endif
