/* Helpers for the literal hand rewrites of the failing-routine stream (round 6).  Include after som_c.h. */
#ifndef SOM_HAND_D_H
#define SOM_HAND_D_H
#include "som_hand_b.h"

/* The code that follows a call is assembled for a fixed register width: a callee that comes back in another width would
 * make the original decode the immediate operands differently, which the C cannot follow (outside the contract). */
#define REQUIRE_M8(c) do { if (!(c)->cpu.mf) { (c)->fail = 3; return; } } while (0)
#define REQUIRE_M16(c) do { if ((c)->cpu.mf) { (c)->fail = 3; return; } } while (0)
#define REQUIRE_X16(c) do { if ((c)->cpu.xf) { (c)->fail = 3; return; } } while (0)
#define REQUIRE_X8(c) do { if (!(c)->cpu.xf) { (c)->fail = 3; return; } } while (0)
#define REQUIRE_M8X16(c) do { if (!(c)->cpu.mf || (c)->cpu.xf) { (c)->fail = 3; return; } } while (0)
#define REQUIRE_M16X16(c) do { if ((c)->cpu.mf || (c)->cpu.xf) { (c)->fail = 3; return; } } while (0)

/* JSR / JSL for routines that expect their callees to come back normally: a callee that overwrote its own return address, or
 * that dropped frames of its caller (a stack switch of a cooperative task), would make the original resume elsewhere, which
 * the C cannot follow.  Such states are outside the contract (fail = 3). */
#define CALL_JSR(c, retpc, target) do { push16((c), (retpc)); som_call_nested((c), (target), SOM_RTS); \
        if ((c)->unwound) { if (!(c)->exited) (c)->fail = 3; return; } /* an exit-address window ends the call chain here (rt/somrt.h) */ \
        if (!(c)->fail && (c)->cpu.pc != (uint16_t)((retpc) + 1)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; } while (0)
#define CALL_JSL(c, retpc, target) do { const uint8_t k_call_ = (c)->cpu.k; push8((c), k_call_); push16((c), (retpc)); \
        som_call_nested((c), (target), SOM_RTL); \
        if ((c)->unwound) { if (!(c)->exited) (c)->fail = 3; return; } /* an exit-address window ends the call chain here (rt/somrt.h) */ \
        if (!(c)->fail && ((c)->cpu.pc != (uint16_t)((retpc) + 1) || (c)->cpu.k != k_call_)) { (c)->fail = 3; return; } \
        if ((c)->fail) return; } while (0)

/* The same, and the callee must return with the data bank it was called with (a PLB of stack residue would make every absolute
 * access that follows read another bank, which the C does not follow). */
#define CALL_DB_JSR(c, retpc, target) do { const uint8_t db_call_ = (c)->cpu.db; CALL_JSR((c), (retpc), (target)); if ((c)->cpu.db != db_call_) { (c)->fail = 3; return; } } while (0)
#define CALL_DB_JSL(c, retpc, target) do { const uint8_t db_call_ = (c)->cpu.db; CALL_JSL((c), (retpc), (target)); if ((c)->cpu.db != db_call_) { (c)->fail = 3; return; } } while (0)
/* The hand rewrites that include this header write their calls as JSR(c, ret, target) / JSL(c, ret, target) like the generated
 * routines (so the mutation tool recognises them) and get the data-bank-checked version. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_DB_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_DB_JSL((c), (retpc), (target))

/* Read-modify-write of a byte / word of WRAM with the flags of the instruction. */
#define RAM8_RMW(op, addr) do { const uint32_t a_ = (addr); RAM8(a_) = (uint8_t)op(&(c)->cpu, RAM8(a_)); } while (0)
#define RAM16_RMW(op, addr) do { const uint32_t a_ = (addr); RAM16_SET(a_, op(&(c)->cpu, RAM16(a_))); } while (0)

/* LDA [dp],Y: the long pointer at D + off, plus Y; a read of an unmapped address returns the pointer's bank byte (the last byte
 * on the bus); anything else the C does not model is outside the contract (returns 0 with fail = 3). */
static inline int hand_ily8(SomCtx *c, uint16_t off, uint8_t *out)
{
    uint32_t p = dp_rd16(c, off) | ((uint32_t)dp_rd8(c, (uint16_t)(off + 2)) << 16);
    uint8_t latch = p >> 16;
    if (!hand_rd8_ptr(c, (p + c->cpu.y) & 0xFFFFFF, &latch, out)) { c->fail = 3; return 0; }
    return 1;
}
static inline int hand_ily16(SomCtx *c, uint16_t off, uint16_t *out)
{
    uint32_t p = dp_rd16(c, off) | ((uint32_t)dp_rd8(c, (uint16_t)(off + 2)) << 16);
    uint32_t a = (p + c->cpu.y) & 0xFFFFFF;
    uint8_t latch = p >> 16, lo, hi;
    if (!hand_rd8_ptr(c, a, &latch, &lo) || !hand_rd8_ptr(c, (a + 1) & 0xFFFFFF, &latch, &hi)) { c->fail = 3; return 0; }
    *out = (uint16_t)(lo | (hi << 8));
    return 1;
}
#define LDA_ILY8(c, off, out) do { uint8_t v_; if (!hand_ily8((c), (off), &v_)) return; (out) = v_; } while (0)
#define LDA_ILY16(c, off, out) do { uint16_t v_; if (!hand_ily16((c), (off), &v_)) return; (out) = v_; } while (0)

/* (dp),Y effective address: the 16-bit pointer at D + off in the data bank, plus Y (24-bit sum). */
static inline uint32_t hand_idy(SomCtx *c, uint16_t off) { return (((uint32_t)c->cpu.db << 16) + dp_rd16(c, off) + c->cpu.y) & 0xFFFFFF; }

/* Instruction-exact memory operations, written like the assembly: OP(c, MODE, operand).  MODE is the 65816 addressing mode
 * (DP, DPX, DPY, IDP, IDX, IDY, IDL, ILY, SR, ISY, ABS, ABX, ABY, ABL, ALX), the width follows the M / X flags at run time and
 * the effective address uses the live D and DB registers.  The semantics are the ones of rt/somlift.h. */
#define H_ADR_DP(c, o, lo, hi) ADR_DP(&(c)->cpu, o, lo, hi)
#define H_ADR_DPX(c, o, lo, hi) ADR_DPX(&(c)->cpu, o, lo, hi)
#define H_ADR_DPY(c, o, lo, hi) ADR_DPY(&(c)->cpu, o, lo, hi)
#define H_ADR_IDP(c, o, lo, hi) ADR_IDP(c, o, lo, hi)
#define H_ADR_IDX(c, o, lo, hi) ADR_IDX(c, o, lo, hi)
#define H_ADR_IDY(c, o, lo, hi) ADR_IDY(c, o, lo, hi)
#define H_ADR_IDL(c, o, lo, hi) ADR_IDL(c, o, lo, hi)
#define H_ADR_ILY(c, o, lo, hi) ADR_ILY(c, o, lo, hi)
#define H_ADR_SR(c, o, lo, hi) ADR_SR(&(c)->cpu, o, lo, hi)
#define H_ADR_ISY(c, o, lo, hi) ADR_ISY(c, o, lo, hi)
#define H_ADR_ABS(c, o, lo, hi) ADR_ABS(&(c)->cpu, o, lo, hi)
#define H_ADR_ABX(c, o, lo, hi) ADR_ABX(&(c)->cpu, o, lo, hi)
#define H_ADR_ABY(c, o, lo, hi) ADR_ABY(&(c)->cpu, o, lo, hi)
#define H_ADR_ABL(c, o, lo, hi) ADR_ABL(&(c)->cpu, o, lo, hi)
#define H_ADR_ALX(c, o, lo, hi) ADR_ALX(&(c)->cpu, o, lo, hi)
/* The data bus keeps the last byte that crossed it: a read of an unmapped address (write-only register, open bus) returns it.
 * The interpreter sees it through its own operand fetches, so a literal rewrite sets it the way the instruction would have
 * left it: the last operand byte of the instruction (the high byte of an absolute address, the bank byte of a long address,
 * the direct-page offset), and afterwards the byte that was read or written.  Pointer modes keep the latch of their pointer
 * reads (the address macros read the pointer through the same bus). */
#define H_LATCH_DP(c, o) ((c)->open_bus = (uint8_t)(o))
#define H_LATCH_DPX(c, o) ((c)->open_bus = (uint8_t)(o))
#define H_LATCH_DPY(c, o) ((c)->open_bus = (uint8_t)(o))
#define H_LATCH_SR(c, o) ((c)->open_bus = (uint8_t)(o))
#define H_LATCH_ABS(c, o) ((c)->open_bus = (uint8_t)((o) >> 8))
#define H_LATCH_ABX(c, o) ((c)->open_bus = (uint8_t)((o) >> 8))
#define H_LATCH_ABY(c, o) ((c)->open_bus = (uint8_t)((o) >> 8))
#define H_LATCH_ABL(c, o) ((c)->open_bus = (uint8_t)((o) >> 16))
#define H_LATCH_ALX(c, o) ((c)->open_bus = (uint8_t)((o) >> 16))
#define H_LATCH_IDP(c, o) ((void)0)
#define H_LATCH_IDX(c, o) ((void)0)
#define H_LATCH_IDY(c, o) ((void)0)
#define H_LATCH_IDL(c, o) ((void)0)
#define H_LATCH_ILY(c, o) ((void)0)
#define H_LATCH_ISY(c, o) ((void)0)
#define H_LOAD(c, MODE, o, apply, rd) do { uint32_t lo_, hi_; H_ADR_##MODE(c, o, lo_, hi_); H_LATCH_##MODE(c, o); \
        apply(&(c)->cpu, rd((c), lo_, hi_)); } while (0)
#define LDA(c, MODE, o) H_LOAD(c, MODE, o, a_lda, rdm)
#define LDX(c, MODE, o) H_LOAD(c, MODE, o, a_ldx, rdx)
#define LDY(c, MODE, o) H_LOAD(c, MODE, o, a_ldy, rdx)
#define ADC(c, MODE, o) H_LOAD(c, MODE, o, a_adc, rdm)
#define SBC(c, MODE, o) H_LOAD(c, MODE, o, a_sbc, rdm)
#define AND(c, MODE, o) H_LOAD(c, MODE, o, a_and, rdm)
#define ORA(c, MODE, o) H_LOAD(c, MODE, o, a_ora, rdm)
#define EOR(c, MODE, o) H_LOAD(c, MODE, o, a_eor, rdm)
#define CMP(c, MODE, o) H_LOAD(c, MODE, o, a_cmp, rdm)
#define BIT(c, MODE, o) H_LOAD(c, MODE, o, a_bit, rdm)
#define CPX(c, MODE, o) H_LOAD(c, MODE, o, a_cpx, rdx)
#define CPY(c, MODE, o) H_LOAD(c, MODE, o, a_cpy, rdx)
#define H_STORE(c, MODE, o, wr, v) do { uint32_t lo_, hi_; H_ADR_##MODE(c, o, lo_, hi_); H_LATCH_##MODE(c, o); wr((c), lo_, hi_, (v)); } while (0)
#define STA(c, MODE, o) H_STORE(c, MODE, o, wrm, (c)->cpu.a)
#define STX(c, MODE, o) H_STORE(c, MODE, o, wrx, (c)->cpu.x)
#define STY(c, MODE, o) H_STORE(c, MODE, o, wrx, (c)->cpu.y)
#define STZ(c, MODE, o) H_STORE(c, MODE, o, wrm, 0)
#define H_RMW(c, MODE, o, fn) do { uint32_t lo_, hi_; H_ADR_##MODE(c, o, lo_, hi_); H_LATCH_##MODE(c, o); RMW(c, fn, lo_, hi_); } while (0)
#define INC(c, MODE, o) H_RMW(c, MODE, o, m_inc)
#define DEC(c, MODE, o) H_RMW(c, MODE, o, m_dec)
#define ASL(c, MODE, o) H_RMW(c, MODE, o, m_asl)
#define LSR(c, MODE, o) H_RMW(c, MODE, o, m_lsr)
#define ROL(c, MODE, o) H_RMW(c, MODE, o, m_rol)
#define ROR(c, MODE, o) H_RMW(c, MODE, o, m_ror)
#define TSB(c, MODE, o) H_RMW(c, MODE, o, m_tsb)
#define TRB(c, MODE, o) H_RMW(c, MODE, o, m_trb)
#endif
