#include "som_c.h"

/* 7EA1A7 decode_signed_delta_or_zero_run   [class B, 59 bytes, 35 instructions]
 * Source: src/boot/decode_signed_delta_or_zero_run.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$05E1.  Callers read: ABXYCZNV.
 */
static void decode_signed_delta_or_zero_run(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t value = BUS8(c, 0x7F0007 + x);
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    if ((value & 0x80) != 0) {
        x_flag = 0;
        a1 = value;
        a_hi1 = a_hi;
        y1 = y;
    } else {
        r->a = (a_hi << 8) | value;
        r->z = (value & 0x80) == 0;
        r->n = value & 0x80;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA1BB, 0x7EA14E); GUARD_JSR(c, sp_call, 0xA1BB); } /* decode_bit_tree_symbol */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        BUS8_SET(c, 0x7F0007 + x, (uint8_t)a_all);
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
    }
    uint8_t a3;
    uint8_t a_hi3;
    if ((a1 & 0x80) == 0) {
        uint8_t a2;
        uint8_t a_hi2;
        if ((a1 & 0x40) == 0) {
            a2 = a1;
            a_hi2 = 0;
        } else {
            a2 = a1 | 0x80;
            a_hi2 = 0xFF;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    } else {
        BUS8_SET(c, 0x7F0007 + x, (uint8_t)(a1 - 1));
        a3 = 0;
        a_hi3 = 0;
    }
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | a3;
    r->y = y1;
    r->c = value3 & 0x01;
    r->z = ((value5 << 8) | value4) == 0;
    r->n = ((value5 << 8) | value4) & 0x8000;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->db = value2;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA1A7, SOM_RTS, "gen", decode_signed_delta_or_zero_run, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 59, 35)
