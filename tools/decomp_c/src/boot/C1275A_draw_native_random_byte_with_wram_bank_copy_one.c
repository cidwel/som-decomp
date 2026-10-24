#include "som_c.h"

/* C1275A draw_native_random_byte_with_wram_bank_copy_one   [class A, 21 bytes, 15 instructions]
 * Source: src/rom/draw_native_random_byte_with_wram_bank_copy_one.s
 * Documented in docs/source-recovery-parallel-random-byte-copies.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void draw_native_random_byte_with_wram_bank_copy_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    r->z = a == 0;
    r->n = a & 0x80;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x276A, 0xC00018); GUARD_JSL(c, sp_call, 0x276A); } /* public_random_byte_jump */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->z = ((value4 << 8) | value3) == 0;
    r->n = ((value4 << 8) | value3) & 0x8000;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1275A, SOM_RTS, "gen", draw_native_random_byte_with_wram_bank_copy_one, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 21, 15)
