/* Instruction semantics used by mechanically lifted routines (tools/decomp_c/lift.py).
 * Behaviour mirrors the LakeSnes 65816 core (MIT licence, (c) angelo_wf and contributors) without cycle timing;
 * the lifted code is verified against Snes9x captures and that core by tools/decomp_c/rt/difftest.c.
 */
#ifndef SOMLIFT_H
#define SOMLIFT_H
#include "somrt.h"

static inline uint16_t rd16(SomCtx *c, uint32_t lo, uint32_t hi) { uint8_t l = som_rd(c, lo); return l | ((uint16_t)som_rd(c, hi) << 8); }
static inline void wr16(SomCtx *c, uint32_t lo, uint32_t hi, uint16_t v) { som_wr(c, lo, v & 0xFF); som_wr(c, hi, v >> 8); }
static inline void wr16r(SomCtx *c, uint32_t lo, uint32_t hi, uint16_t v) { som_wr(c, hi, v >> 8); som_wr(c, lo, v & 0xFF); }

static inline void zn(Cpu *r, uint16_t v, bool byte) {
    if (byte) { r->z = (v & 0xFF) == 0; r->n = v & 0x80; } else { r->z = v == 0; r->n = v & 0x8000; }
}
static inline uint8_t getflags(Cpu *r) {
    return (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
}
static inline void setflags(Cpu *r, uint8_t val) {
    r->n = val & 0x80; r->v = val & 0x40; r->mf = val & 0x20; r->xf = val & 0x10; r->d = val & 8; r->i = val & 4; r->z = val & 2; r->c = val & 1;
    if (r->e) { r->mf = true; r->xf = true; r->sp = (r->sp & 0xFF) | 0x100; }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
}

/* stack */
static inline void push8(SomCtx *c, uint8_t v) { Cpu *r = &c->cpu; som_wr(c, r->sp, v); r->sp--; if (r->e) r->sp = (r->sp & 0xFF) | 0x100; }
static inline uint8_t pull8(SomCtx *c) { Cpu *r = &c->cpu; r->sp++; if (r->e) r->sp = (r->sp & 0xFF) | 0x100; return som_rd(c, r->sp); }
static inline void push16(SomCtx *c, uint16_t v) { push8(c, v >> 8); push8(c, v & 0xFF); }
static inline uint16_t pull16(SomCtx *c) { uint8_t l = pull8(c); return l | ((uint16_t)pull8(c) << 8); }

/* effective addresses: each sets lo/hi */
#define ADR_DP(r, o, lo, hi) do { lo = ((r)->dp + (o)) & 0xFFFF; hi = ((r)->dp + (o) + 1) & 0xFFFF; } while (0)
#define ADR_DPX(r, o, lo, hi) do { lo = ((r)->dp + (o) + (r)->x) & 0xFFFF; hi = ((r)->dp + (o) + (r)->x + 1) & 0xFFFF; } while (0)
#define ADR_DPY(r, o, lo, hi) do { lo = ((r)->dp + (o) + (r)->y) & 0xFFFF; hi = ((r)->dp + (o) + (r)->y + 1) & 0xFFFF; } while (0)
#define ADR_IDP(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint16_t p_ = rd16(c, ((r_)->dp + (o)) & 0xFFFF, ((r_)->dp + (o) + 1) & 0xFFFF); lo = ((uint32_t)r_->db << 16) + p_; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_IDX(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint16_t p_ = rd16(c, (r_->dp + (o) + r_->x) & 0xFFFF, (r_->dp + (o) + r_->x + 1) & 0xFFFF); lo = ((uint32_t)r_->db << 16) + p_; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_IDY(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint16_t p_ = rd16(c, (r_->dp + (o)) & 0xFFFF, (r_->dp + (o) + 1) & 0xFFFF); lo = (((uint32_t)r_->db << 16) + p_ + r_->y) & 0xFFFFFF; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_IDL(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint32_t p_ = rd16(c, (r_->dp + (o)) & 0xFFFF, (r_->dp + (o) + 1) & 0xFFFF); p_ |= (uint32_t)som_rd(c, (r_->dp + (o) + 2) & 0xFFFF) << 16; lo = p_; hi = (p_ + 1) & 0xFFFFFF; } while (0)
#define ADR_ILY(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint32_t p_ = rd16(c, (r_->dp + (o)) & 0xFFFF, (r_->dp + (o) + 1) & 0xFFFF); p_ |= (uint32_t)som_rd(c, (r_->dp + (o) + 2) & 0xFFFF) << 16; lo = (p_ + r_->y) & 0xFFFFFF; hi = (p_ + r_->y + 1) & 0xFFFFFF; } while (0)
#define ADR_SR(r, o, lo, hi) do { lo = ((r)->sp + (o)) & 0xFFFF; hi = ((r)->sp + (o) + 1) & 0xFFFF; } while (0)
#define ADR_ISY(c, o, lo, hi) do { Cpu *r_ = &(c)->cpu; uint16_t p_ = rd16(c, (r_->sp + (o)) & 0xFFFF, (r_->sp + (o) + 1) & 0xFFFF); lo = (((uint32_t)r_->db << 16) + p_ + r_->y) & 0xFFFFFF; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_ABS(r, a, lo, hi) do { lo = ((uint32_t)(r)->db << 16) + (a); hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_ABX(r, a, lo, hi) do { lo = (((uint32_t)(r)->db << 16) + (a) + (r)->x) & 0xFFFFFF; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_ABY(r, a, lo, hi) do { lo = (((uint32_t)(r)->db << 16) + (a) + (r)->y) & 0xFFFFFF; hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_ABL(r, a, lo, hi) do { lo = (a); hi = (lo + 1) & 0xFFFFFF; } while (0)
#define ADR_ALX(r, a, lo, hi) do { lo = ((a) + (r)->x) & 0xFFFFFF; hi = (lo + 1) & 0xFFFFFF; } while (0)

/* operand reads by accumulator / index width */
static inline uint16_t rdm(SomCtx *c, uint32_t lo, uint32_t hi) { return c->cpu.mf ? som_rd(c, lo) : rd16(c, lo, hi); }
static inline uint16_t rdx(SomCtx *c, uint32_t lo, uint32_t hi) { return c->cpu.xf ? som_rd(c, lo) : rd16(c, lo, hi); }
static inline void wrm(SomCtx *c, uint32_t lo, uint32_t hi, uint16_t v) { if (c->cpu.mf) som_wr(c, lo, v); else wr16(c, lo, hi, v); }
static inline void wrx(SomCtx *c, uint32_t lo, uint32_t hi, uint16_t v) { if (c->cpu.xf) som_wr(c, lo, v); else wr16(c, lo, hi, v); }
static inline void wrmr(SomCtx *c, uint32_t lo, uint32_t hi, uint16_t v) { if (c->cpu.mf) som_wr(c, lo, v); else wr16r(c, lo, hi, v); }

/* ALU on an already fetched operand */
static inline void a_and(Cpu *r, uint16_t v) { if (r->mf) r->a = (r->a & 0xFF00) | ((r->a & v) & 0xFF); else r->a &= v; zn(r, r->a, r->mf); }
static inline void a_ora(Cpu *r, uint16_t v) { if (r->mf) r->a = (r->a & 0xFF00) | ((r->a | v) & 0xFF); else r->a |= v; zn(r, r->a, r->mf); }
static inline void a_eor(Cpu *r, uint16_t v) { if (r->mf) r->a = (r->a & 0xFF00) | ((r->a ^ v) & 0xFF); else r->a ^= v; zn(r, r->a, r->mf); }
static inline void a_adc(Cpu *r, uint16_t value) {
    if (r->mf) {
        value &= 0xFF; int result;
        if (r->d) { result = (r->a & 0xF) + (value & 0xF) + r->c; if (result > 9) result = ((result + 6) & 0xF) + 0x10; result = (r->a & 0xF0) + (value & 0xF0) + result; }
        else result = (r->a & 0xFF) + value + r->c;
        r->v = (r->a & 0x80) == (value & 0x80) && (value & 0x80) != (result & 0x80);
        if (r->d && result > 0x9F) result += 0x60;
        r->c = result > 0xFF; r->a = (r->a & 0xFF00) | (result & 0xFF);
    } else {
        int result;
        if (r->d) {
            result = (r->a & 0xF) + (value & 0xF) + r->c; if (result > 9) result = ((result + 6) & 0xF) + 0x10;
            result = (r->a & 0xF0) + (value & 0xF0) + result; if (result > 0x9F) result = ((result + 0x60) & 0xFF) + 0x100;
            result = (r->a & 0xF00) + (value & 0xF00) + result; if (result > 0x9FF) result = ((result + 0x600) & 0xFFF) + 0x1000;
            result = (r->a & 0xF000) + (value & 0xF000) + result;
        } else result = r->a + value + r->c;
        r->v = (r->a & 0x8000) == (value & 0x8000) && (value & 0x8000) != (result & 0x8000);
        if (r->d && result > 0x9FFF) result += 0x6000;
        r->c = result > 0xFFFF; r->a = result;
    }
    zn(r, r->a, r->mf);
}
static inline void a_sbc(Cpu *r, uint16_t v) {
    if (r->mf) {
        uint8_t value = (v & 0xFF) ^ 0xFF; int result;
        if (r->d) { result = (r->a & 0xF) + (value & 0xF) + r->c; if (result < 0x10) result = (result - 6) & ((result - 6 < 0) ? 0xF : 0x1F); result = (r->a & 0xF0) + (value & 0xF0) + result; }
        else result = (r->a & 0xFF) + value + r->c;
        r->v = (r->a & 0x80) == (value & 0x80) && (value & 0x80) != (result & 0x80);
        if (r->d && result < 0x100) result -= 0x60;
        r->c = result > 0xFF; r->a = (r->a & 0xFF00) | (result & 0xFF);
    } else {
        uint16_t value = v ^ 0xFFFF; int result;
        if (r->d) {
            result = (r->a & 0xF) + (value & 0xF) + r->c; if (result < 0x10) result = (result - 6) & ((result - 6 < 0) ? 0xF : 0x1F);
            result = (r->a & 0xF0) + (value & 0xF0) + result; if (result < 0x100) result = (result - 0x60) & ((result - 0x60 < 0) ? 0xFF : 0x1FF);
            result = (r->a & 0xF00) + (value & 0xF00) + result; if (result < 0x1000) result = (result - 0x600) & ((result - 0x600 < 0) ? 0xFFF : 0x1FFF);
            result = (r->a & 0xF000) + (value & 0xF000) + result;
        } else result = r->a + value + r->c;
        r->v = (r->a & 0x8000) == (value & 0x8000) && (value & 0x8000) != (result & 0x8000);
        if (r->d && result < 0x10000) result -= 0x6000;
        r->c = result > 0xFFFF; r->a = result;
    }
    zn(r, r->a, r->mf);
}
static inline void a_cmpr(Cpu *r, uint16_t reg, bool byte, uint16_t v) {
    int result;
    if (byte) { result = (reg & 0xFF) + ((v & 0xFF) ^ 0xFF) + 1; r->c = result > 0xFF; }
    else { result = reg + (v ^ 0xFFFF) + 1; r->c = result > 0xFFFF; }
    zn(r, result, byte);
}
#define a_cmp(r, v) a_cmpr(r, (r)->a, (r)->mf, v)
#define a_cpx(r, v) a_cmpr(r, (r)->x, (r)->xf, v)
#define a_cpy(r, v) a_cmpr(r, (r)->y, (r)->xf, v)
static inline void a_bit(Cpu *r, uint16_t v) {
    if (r->mf) { v &= 0xFF; r->z = ((r->a & 0xFF) & v) == 0; r->n = v & 0x80; r->v = v & 0x40; }
    else { r->z = (r->a & v) == 0; r->n = v & 0x8000; r->v = v & 0x4000; }
}
static inline void a_biti(Cpu *r, uint16_t v) { if (r->mf) r->z = ((r->a & 0xFF) & (v & 0xFF)) == 0; else r->z = (r->a & v) == 0; }
static inline void a_lda(Cpu *r, uint16_t v) { if (r->mf) r->a = (r->a & 0xFF00) | (v & 0xFF); else r->a = v; zn(r, r->a, r->mf); }
static inline void a_ldx(Cpu *r, uint16_t v) { r->x = r->xf ? (v & 0xFF) : v; zn(r, r->x, r->xf); }
static inline void a_ldy(Cpu *r, uint16_t v) { r->y = r->xf ? (v & 0xFF) : v; zn(r, r->y, r->xf); }

/* read-modify-write value transforms: return the written value */
static inline uint16_t m_asl(Cpu *r, uint16_t v) { int res = (r->mf ? (v & 0xFF) : v) << 1; r->c = res & (r->mf ? 0x100 : 0x10000); zn(r, res, r->mf); return res; }
static inline uint16_t m_lsr(Cpu *r, uint16_t v) { if (r->mf) v &= 0xFF; r->c = v & 1; int res = v >> 1; zn(r, res, r->mf); return res; }
static inline uint16_t m_rol(Cpu *r, uint16_t v) { int res = ((r->mf ? (v & 0xFF) : v) << 1) | r->c; r->c = res & (r->mf ? 0x100 : 0x10000); zn(r, res, r->mf); return res; }
static inline uint16_t m_ror(Cpu *r, uint16_t v) { if (r->mf) v &= 0xFF; bool carry = v & 1; int res = (v >> 1) | (r->c << (r->mf ? 7 : 15)); zn(r, res, r->mf); r->c = carry; return res; }
static inline uint16_t m_inc(Cpu *r, uint16_t v) { int res = (r->mf ? (v & 0xFF) : v) + 1; zn(r, res, r->mf); return res; }
static inline uint16_t m_dec(Cpu *r, uint16_t v) { int res = (r->mf ? (v & 0xFF) : v) - 1; zn(r, res, r->mf); return res; }
static inline uint16_t m_tsb(Cpu *r, uint16_t v) { if (r->mf) v &= 0xFF; r->z = (r->a & v & (r->mf ? 0xFF : 0xFFFF)) == 0; return v | r->a; }
static inline uint16_t m_trb(Cpu *r, uint16_t v) { if (r->mf) v &= 0xFF; r->z = (r->a & v & (r->mf ? 0xFF : 0xFFFF)) == 0; return v & ~r->a; }
#define RMW(c, fn, lo, hi) do { Cpu *r_ = &(c)->cpu; uint16_t v_ = rdm(c, lo, hi); v_ = fn(r_, v_); wrmr(c, lo, hi, v_); } while (0)

/* accumulator and implied forms */
static inline void i_asla(Cpu *r) { if (r->mf) { r->c = r->a & 0x80; r->a = (r->a & 0xFF00) | ((r->a << 1) & 0xFF); } else { r->c = r->a & 0x8000; r->a <<= 1; } zn(r, r->a, r->mf); }
static inline void i_lsra(Cpu *r) { r->c = r->a & 1; if (r->mf) r->a = (r->a & 0xFF00) | ((r->a >> 1) & 0x7F); else r->a >>= 1; zn(r, r->a, r->mf); }
static inline void i_rola(Cpu *r) { int res = (r->a << 1) | r->c; if (r->mf) { r->c = res & 0x100; r->a = (r->a & 0xFF00) | (res & 0xFF); } else { r->c = res & 0x10000; r->a = res; } zn(r, r->a, r->mf); }
static inline void i_rora(Cpu *r) { bool carry = r->a & 1; if (r->mf) r->a = (r->a & 0xFF00) | ((r->a >> 1) & 0x7F) | (r->c << 7); else r->a = (r->a >> 1) | (r->c << 15); r->c = carry; zn(r, r->a, r->mf); }
static inline void i_inca(Cpu *r) { if (r->mf) r->a = (r->a & 0xFF00) | ((r->a + 1) & 0xFF); else r->a++; zn(r, r->a, r->mf); }
static inline void i_deca(Cpu *r) { if (r->mf) r->a = (r->a & 0xFF00) | ((r->a - 1) & 0xFF); else r->a--; zn(r, r->a, r->mf); }
static inline void i_inx(Cpu *r) { r->x = r->xf ? (r->x + 1) & 0xFF : (uint16_t)(r->x + 1); zn(r, r->x, r->xf); }
static inline void i_iny(Cpu *r) { r->y = r->xf ? (r->y + 1) & 0xFF : (uint16_t)(r->y + 1); zn(r, r->y, r->xf); }
static inline void i_dex(Cpu *r) { r->x = r->xf ? (r->x - 1) & 0xFF : (uint16_t)(r->x - 1); zn(r, r->x, r->xf); }
static inline void i_dey(Cpu *r) { r->y = r->xf ? (r->y - 1) & 0xFF : (uint16_t)(r->y - 1); zn(r, r->y, r->xf); }
static inline void i_tax(Cpu *r) { r->x = r->xf ? (r->a & 0xFF) : r->a; zn(r, r->x, r->xf); }
static inline void i_tay(Cpu *r) { r->y = r->xf ? (r->a & 0xFF) : r->a; zn(r, r->y, r->xf); }
static inline void i_txa(Cpu *r) { if (r->mf) r->a = (r->a & 0xFF00) | (r->x & 0xFF); else r->a = r->x; zn(r, r->a, r->mf); }
static inline void i_tya(Cpu *r) { if (r->mf) r->a = (r->a & 0xFF00) | (r->y & 0xFF); else r->a = r->y; zn(r, r->a, r->mf); }
static inline void i_txy(Cpu *r) { r->y = r->xf ? (r->x & 0xFF) : r->x; zn(r, r->y, r->xf); }
static inline void i_tyx(Cpu *r) { r->x = r->xf ? (r->y & 0xFF) : r->y; zn(r, r->x, r->xf); }
static inline void i_tsx(Cpu *r) { r->x = r->xf ? (r->sp & 0xFF) : r->sp; zn(r, r->x, r->xf); }
static inline void i_txs(Cpu *r) { r->sp = r->x; }
static inline void i_tcs(Cpu *r) { r->sp = r->a; }
static inline void i_tsc(Cpu *r) { r->a = r->sp; zn(r, r->a, false); }
static inline void i_tcd(Cpu *r) { r->dp = r->a; zn(r, r->dp, false); }
static inline void i_tdc(Cpu *r) { r->a = r->dp; zn(r, r->a, false); }
static inline void i_xba(Cpu *r) { uint8_t lo = r->a & 0xFF, hi = r->a >> 8; r->a = (lo << 8) | hi; zn(r, hi, true); }
static inline void i_xce(Cpu *r) { bool t = r->c; r->c = r->e; r->e = t; setflags(r, getflags(r)); }
static inline void i_pha(SomCtx *c) { Cpu *r = &c->cpu; if (r->mf) push8(c, r->a); else push16(c, r->a); }
static inline void i_pla(SomCtx *c) { Cpu *r = &c->cpu; if (r->mf) r->a = (r->a & 0xFF00) | pull8(c); else r->a = pull16(c); zn(r, r->a, r->mf); }
static inline void i_phx(SomCtx *c) { Cpu *r = &c->cpu; if (r->xf) push8(c, r->x); else push16(c, r->x); }
static inline void i_plx(SomCtx *c) { Cpu *r = &c->cpu; if (r->xf) r->x = pull8(c); else r->x = pull16(c); zn(r, r->x, r->xf); }
static inline void i_phy(SomCtx *c) { Cpu *r = &c->cpu; if (r->xf) push8(c, r->y); else push16(c, r->y); }
static inline void i_ply(SomCtx *c) { Cpu *r = &c->cpu; if (r->xf) r->y = pull8(c); else r->y = pull16(c); zn(r, r->y, r->xf); }
static inline void i_php(SomCtx *c) { push8(c, getflags(&c->cpu)); }
static inline void i_plp(SomCtx *c) { setflags(&c->cpu, pull8(c)); }
static inline void i_phd(SomCtx *c) { push16(c, c->cpu.dp); }
static inline void i_pld(SomCtx *c) { c->cpu.dp = pull16(c); zn(&c->cpu, c->cpu.dp, false); }
static inline void i_phb(SomCtx *c) { push8(c, c->cpu.db); }
static inline void i_plb(SomCtx *c) { c->cpu.db = pull8(c); zn(&c->cpu, c->cpu.db, true); }
static inline void i_phk(SomCtx *c) { push8(c, c->cpu.k); }
static inline void i_rep(Cpu *r, uint8_t m) { setflags(r, getflags(r) & ~m); }
static inline void i_sep(Cpu *r, uint8_t m) { setflags(r, getflags(r) | m); }
/* MVN/MVP: whole block in one step; A holds count-1 */
static inline void i_mvn(SomCtx *c, uint8_t src, uint8_t dst) {
    Cpu *r = &c->cpu; r->db = dst;
    do { som_wr(c, ((uint32_t)dst << 16) | r->y, som_rd(c, ((uint32_t)src << 16) | r->x)); r->a--; r->x++; r->y++; if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; } } while (r->a != 0xFFFF);
}
static inline void i_mvp(SomCtx *c, uint8_t src, uint8_t dst) {
    Cpu *r = &c->cpu; r->db = dst;
    do { som_wr(c, ((uint32_t)dst << 16) | r->y, som_rd(c, ((uint32_t)src << 16) | r->x)); r->a--; r->x--; r->y--; if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; } } while (r->a != 0xFFFF);
}
/* control flow */
static inline void i_rts(SomCtx *c) { Cpu *r = &c->cpu; r->pc = pull16(c) + 1; }
static inline void i_rti(SomCtx *c) { Cpu *r = &c->cpu; setflags(r, pull8(c)); r->pc = pull16(c); if (!r->e) r->k = pull8(c); }
static inline void i_rtl(SomCtx *c) { Cpu *r = &c->cpu; r->pc = pull16(c) + 1; r->k = pull8(c); }
/* a callee that unwinds (drops its return address and returns to our caller) has already left this routine: return at once */
/* A callee that returns anywhere else than behind the call (it replaced its own return address) leaves the input domain of a C routine: fail = 3 */
#define I_JSR(c, retpc, target) do { push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rts(c); } else { som_call_nested(c, (target), SOM_RTS); if ((c)->unwound) return; } \
    if (!(c)->fail && (c)->cpu.pc != (uint16_t)((retpc) + 1)) { (c)->fail = 3; return; } } while (0)
#define I_JSL(c, retpc, target) do { const uint8_t k_ = (c)->cpu.k; push8(c, k_); push16(c, (retpc)); if ((c)->stub_calls) { (c)->stub_n++; i_rtl(c); } else { som_call_nested(c, (target), SOM_RTL); if ((c)->unwound) return; } \
    if (!(c)->fail && ((c)->cpu.pc != (uint16_t)((retpc) + 1) || (c)->cpu.k != k_)) { (c)->fail = 3; return; } } while (0)
static inline void i_unsupported(SomCtx *c) { c->fail = 1; }
#endif
