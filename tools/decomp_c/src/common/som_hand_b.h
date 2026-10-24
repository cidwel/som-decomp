/* Helpers for hand-written routines that call interpreted code (failing-b stream). Include after som_c.h. */
#ifndef SOM_HAND_B_H
#define SOM_HAND_B_H
#include "som_hand.h"

/* JSR whose callee may overwrite its own return address (only possible on fuzzed, impossible game states): the original
 * would resume elsewhere, so the state is declared outside the contract (fail = 3).  A callee that ran out of its step
 * budget (fail = 1) also ends the routine. */
#define JSR_CHK(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        JSR((c), (retpc), (target)); \
        if ((c)->fail) return; \
        if ((c)->wram[sp_ & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
    } while (0)

#define JSL_CHK(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        JSL((c), (retpc), (target)); \
        if ((c)->fail) return; \
        if ((c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 2) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
    } while (0)

/* Guards for a call made with the plain JSR/JSL macros (so the call stays visible to the mutation and delegation
 * checks):  { const uint16_t sp_call = r->sp; JSL(c, retpc, target); GUARD_JSL(c, sp_call, retpc); }
 * A callee that overwrote its own return address makes the original resume elsewhere, which the C cannot
 * reproduce: the state is outside the contract (fail = 3).  The _DB forms also reject a callee that came back with
 * another data bank (a PLB of stack residue), for routines whose C assumes the entry bank. */
#define GUARD_JSR(c, sp_, retpc) do { \
        if ((c)->wram[(sp_) & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)((sp_) - 1) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)
#define GUARD_JSL(c, sp_, retpc) do { \
        if ((c)->wram[(uint16_t)((sp_) - 1) & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)((sp_) - 2) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)
#define GUARD_JSR_DB(c, sp_, retpc, db_) do { if ((c)->cpu.db != (db_)) { (c)->fail = 3; return; } GUARD_JSR((c), (sp_), (retpc)); } while (0)
#define GUARD_JSL_DB(c, sp_, retpc, db_) do { if ((c)->cpu.db != (db_)) { (c)->fail = 3; return; } GUARD_JSL((c), (sp_), (retpc)); } while (0)

/* JSR_RA / JSL_RA: only the return address of the call is checked (wrappers that never use the data bank). */
#define JSR_RA(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        JSR((c), (retpc), (target)); \
        if ((c)->wram[sp_ & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)

#define JSL_RA(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        JSL((c), (retpc), (target)); \
        if ((c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 2) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)

/* Call variants for routines whose C assumes the data bank it was entered with: when the callee overwrote its own
 * return address the original resumes somewhere else, and when it returned with another data bank (a PLB of stack
 * residue) every absolute access that follows reads another bank.  Neither can be reproduced by the C, so such states
 * are outside the contract (fail = 3) whatever the interpreted callee did next. */
#define JSR_RET(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        const uint8_t db_ = (c)->cpu.db; \
        JSR((c), (retpc), (target)); \
        if ((c)->cpu.db != db_) { (c)->fail = 3; return; } \
        if ((c)->wram[sp_ & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)

#define JSL_RET(c, retpc, target) do { \
        const uint16_t sp_ = (c)->cpu.sp; \
        const uint8_t db_ = (c)->cpu.db; \
        JSL((c), (retpc), (target)); \
        if ((c)->cpu.db != db_) { (c)->fail = 3; return; } \
        if ((c)->wram[(uint16_t)(sp_ - 1) & 0x1FFFF] != (uint8_t)((retpc) >> 8) || (c)->wram[(uint16_t)(sp_ - 2) & 0x1FFFF] != (uint8_t)(retpc)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; \
    } while (0)

/* The status byte PHP pushes. */
static inline uint8_t hand_p_byte(const Cpu *r)
{
    return (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
}

/* Stack pulls that read the real bytes (a callee can have changed them).  The status byte restores every flag. */
static inline void hand_plb(SomCtx *c) { c->cpu.sp++; c->cpu.db = c->wram[c->cpu.sp & 0x1FFFF]; }
static inline void hand_plp(SomCtx *c) { c->cpu.sp++; som_pull_p(c, c->cpu.sp); }
static inline void hand_pld(SomCtx *c) { Cpu *r = &c->cpu; r->dp = (uint16_t)(c->wram[(r->sp + 1) & 0x1FFFF] | (c->wram[(r->sp + 2) & 0x1FFFF] << 8)); r->sp += 2; }

/* BUS16_SET/BUS16 re-evaluate their address expression for the second byte; when the first byte store changes the
 * operands of that expression (a pointer stored through itself) the second byte goes to the wrong place.  These
 * helpers evaluate the address once. */
static inline void bus16_set_once(SomCtx *c, uint32_t a, uint16_t v) { som_wr(c, a, v & 0xFF); som_wr(c, a + 1, v >> 8); }

/* N and Z of a 16-bit result; compare sets C as well (A - operand, no borrow = carry). */
static inline void hand_nz16(Cpu *r, uint16_t v) { r->z = v == 0; r->n = v >> 15; }
static inline void hand_cmp16(Cpu *r, uint16_t a, uint16_t b) { r->c = a >= b; hand_nz16(r, (uint16_t)(a - b)); }
static inline void hand_nz8(Cpu *r, uint8_t v) { r->z = v == 0; r->n = v >> 7; }
static inline void hand_cmp8(Cpu *r, uint8_t a, uint8_t b) { r->c = a >= b; hand_nz8(r, (uint8_t)(a - b)); }

/* Reads of unmapped bus addresses return the open bus (the last byte the CPU fetched), which a C routine does not
 * reproduce.  Natural game states never read them; fuzzed pointers can, so those states are declared out of contract. */
static inline int hand_rd_ok(uint32_t a)
{
    uint32_t bank = (a >> 16) & 0xFF, low = a & 0xFFFF;
    if (bank == 0x7E || bank == 0x7F) return 1;
    if (bank < 0x40 || (bank >= 0x80 && bank < 0xC0)) return low < 0x2000 || low >= 0x8000;
    return 1;
}
#define BUS8_OK(c, a, out) do { uint32_t a_ = (a); if (!hand_rd_ok(a_)) { (c)->fail = 3; return; } (out) = BUS8((c), a_); } while (0)
/* 16-bit bus read of a pointer-derived address; open-bus or hardware-register reads are outside the contract. */
#define BUS16_OK(c, a, out) do { uint32_t a_ = (a) & 0xFFFFFF; if (!hand_rd_ok(a_) || !hand_rd_ok((a_ + 1) & 0xFFFFFF)) { (c)->fail = 3; return; } (out) = BUS16((c), a_); } while (0)
static inline void hand_lda8(Cpu *r, uint8_t v) { r->a = (r->a & 0xFF00) | v; hand_nz8(r, v); }
/* ADC/SBC (binary mode) on 16-bit and 8-bit operands with all four flags updated, the carry coming from r->c. */
static inline uint16_t hand_adc16(Cpu *r, uint16_t a, uint16_t b)
{
    uint32_t sum = (uint32_t)a + b + r->c;
    uint16_t res = (uint16_t)sum;
    r->c = sum > 0xFFFF;
    r->v = (((a ^ res) & (b ^ res)) & 0x8000) != 0;
    hand_nz16(r, res);
    return res;
}
static inline uint16_t hand_sbc16(Cpu *r, uint16_t a, uint16_t b) { return hand_adc16(r, a, (uint16_t)~b); }
static inline uint8_t hand_adc8(Cpu *r, uint8_t a, uint8_t b)
{
    uint32_t sum = (uint32_t)a + b + r->c;
    uint8_t res = (uint8_t)sum;
    r->c = sum > 0xFF;
    r->v = (((a ^ res) & (b ^ res)) & 0x80) != 0;
    hand_nz8(r, res);
    return res;
}
static inline uint8_t hand_sbc8(Cpu *r, uint8_t a, uint8_t b) { return hand_adc8(r, a, (uint8_t)~b); }
/* Direct-page accesses of a routine that works for any D: bank 0, the address wraps at 16 bits, and a D above $1FFF
 * reaches hardware registers (the bus logs those accesses). */
static inline uint8_t dp_rd8(SomCtx *c, uint16_t off) { return som_rd(c, (uint16_t)(c->cpu.dp + off)); }
static inline void dp_wr8(SomCtx *c, uint16_t off, uint8_t v) { som_wr(c, (uint16_t)(c->cpu.dp + off), v); }
static inline uint16_t dp_rd16(SomCtx *c, uint16_t off) { return (uint16_t)(dp_rd8(c, off) | (dp_rd8(c, (uint16_t)(off + 1)) << 8)); }
static inline void dp_wr16(SomCtx *c, uint16_t off, uint16_t v) { dp_wr8(c, off, v & 0xFF); dp_wr8(c, (uint16_t)(off + 1), v >> 8); }

/* Direct-page 16-bit accesses stay in bank 0 and the second byte wraps at 0xFFFF (D + operand + index). */
static inline void bus16_dp_set(SomCtx *c, uint16_t a, uint16_t v) { som_wr(c, a, v & 0xFF); som_wr(c, (uint16_t)(a + 1), v >> 8); }
static inline uint16_t bus16_dp(SomCtx *c, uint16_t a) { return (uint16_t)(som_rd(c, a) | (som_rd(c, (uint16_t)(a + 1)) << 8)); }
/* The ROM assembles the code after a call for 16-bit A and index registers; a callee that returns in another width
 * makes the original run into its immediate operand as an opcode, which is outside the contract. */
#define HAND_REQUIRE_WIDE(c) do { if ((c)->cpu.mf || (c)->cpu.xf) { (c)->fail = 3; return; } } while (0)

/* LDA / STA with the accumulator width the code runs in (M flag), for routines whose widths follow the callees.
 * dp forms stay in bank 0 (D + operand, wrapping at 16 bits); abs forms take the full 24-bit address (DB + operand + index). */
static inline void hand_lda_dp(SomCtx *c, uint16_t off) { Cpu *r = &c->cpu; a_lda(r, r->mf ? dp_rd8(c, off) : dp_rd16(c, off)); }
static inline void hand_sta_dp(SomCtx *c, uint16_t off) { Cpu *r = &c->cpu; if (r->mf) dp_wr8(c, off, r->a & 0xFF); else dp_wr16(c, off, r->a); }
static inline int hand_lda_abs(SomCtx *c, uint32_t addr)   /* hardware and open-bus reads are outside the contract (fail = 3, returns 0) */
{
    Cpu *r = &c->cpu; addr &= 0xFFFFFF;
    if (!hand_rd_ok(addr) || (!r->mf && !hand_rd_ok((addr + 1) & 0xFFFFFF))) { c->fail = 3; return 0; }
    a_lda(r, r->mf ? BUS8(c, addr) : BUS16(c, addr));
    return 1;
}
static inline void hand_sta_abs(SomCtx *c, uint32_t addr) { Cpu *r = &c->cpu; if (r->mf) BUS8_SET(c, addr & 0xFFFFFF, r->a & 0xFF); else BUS16_SET(c, addr & 0xFFFFFF, r->a); }
static inline void hand_ldx_dp(SomCtx *c, uint16_t off) { Cpu *r = &c->cpu; a_ldx(r, r->xf ? dp_rd8(c, off) : dp_rd16(c, off)); }

/* Calls from a routine that must follow a callee which replaces its own return address.  The original then resumes at
 * the address it popped and runs on until this routine's own RTS (S == sp0 at that moment); the interpreter does the
 * same from the popped address.  A routine uses them by redefining I_JSR / I_JSL (so the JSR/JSL call sites stay
 * visible as calls):  #undef I_JSL / #define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)
 * with sp0 the stack pointer at entry.  A routine that ends with RTL redefines HAND_ROUTINE_RET as SOM_RTL. */
#define HAND_ROUTINE_RET SOM_RTS
#define HAND_AFTER_CALL_RESUME(c, ok, sp0) do { \
        if ((c)->fail || (c)->exited) return; /* exited: an exit-address window ended the call chain */ \
        if (!(ok) || (c)->unwound) { \
            if (!((c)->unwound && (c)->cpu.sp == (uint16_t)((sp0) + (HAND_ROUTINE_RET == SOM_RTL ? 3 : 2)))) { (c)->unwound = 0; som_interp_run((c), HAND_ROUTINE_RET, (sp0)); } \
            return; \
        } \
    } while (0)
#define HAND_JSR_RESUME(c, retpc, target, sp0) do { push16((c), (retpc)); som_call_nested((c), (target), SOM_RTS); \
        HAND_AFTER_CALL_RESUME((c), (c)->cpu.pc == (uint16_t)((retpc) + 1), (sp0)); } while (0)
#define HAND_JSL_RESUME(c, retpc, target, sp0) do { const uint8_t k_ = (c)->cpu.k; push8((c), k_); push16((c), (retpc)); \
        som_call_nested((c), (target), SOM_RTL); \
        HAND_AFTER_CALL_RESUME((c), (c)->cpu.pc == (uint16_t)((retpc) + 1) && (c)->cpu.k == k_, (sp0)); } while (0)

/* Pointer reads that land on unmapped bus addresses (banks 00-3F/80-BF, $2200-$3FFF and $4380-$5FFF) return the open bus,
 * which is the last byte the CPU read before the data byte.  For LDA [dp] / LDA [dp],Y that is the pointer's bank byte,
 * and the second byte of a 16-bit read sees the first one.  Registers and anything else the C does not model stay out
 * of contract.  LATCH is the byte on the bus when the read starts. */
static inline int hand_open_ok(uint32_t a)
{
    uint32_t bank = (a >> 16) & 0xFF, low = a & 0xFFFF;
    if (!(bank < 0x40 || (bank >= 0x80 && bank < 0xC0))) return 0;
    return (low >= 0x2200 && low < 0x4000) || (low >= 0x4380 && low < 0x6000);
}
static inline int hand_rd8_ptr(SomCtx *c, uint32_t a, uint8_t *latch, uint8_t *out)
{
    a &= 0xFFFFFF;
    if (hand_rd_ok(a)) *out = BUS8(c, a);
    else if (hand_open_ok(a)) *out = *latch;
    else return 0;
    *latch = *out;
    return 1;
}
#define BUS8_PTR(c, a, latch, out) do { uint8_t l_ = (uint8_t)(latch), v_; \
        if (!hand_rd8_ptr((c), (a), &l_, &v_)) { (c)->fail = 3; return; } (out) = v_; } while (0)
#define BUS16_PTR(c, a, latch, out) do { uint8_t l_ = (uint8_t)(latch), lo_, hi_; uint32_t a_ = (a) & 0xFFFFFF; \
        if (!hand_rd8_ptr((c), a_, &l_, &lo_) || !hand_rd8_ptr((c), (a_ + 1) & 0xFFFFFF, &l_, &hi_)) { (c)->fail = 3; return; } \
        (out) = (uint16_t)(lo_ | (hi_ << 8)); } while (0)

#endif
