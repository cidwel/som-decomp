#include "som_c.h"

/* 7ECC57 mark_timer_waiting   [class A, 33 bytes, 19 instructions]
 * Source: src/boot/mark_timer_waiting.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXCZNV.
 */
static void mark_timer_waiting(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x10000 + x) = 2;
    uint8_t value = BUS8(c, 0x7F0002 + x);
    uint8_t value2 = BUS8(c, 0x7F0003 + x);
    uint8_t a1;
    if ((value | value2) != 0) {
        a1 = value | value2;
    } else {
        RAM8(0x10000 + x) = 1;
        a1 = 1;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi << 8) | a1;
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECC57, SOM_RTS, "gen", mark_timer_waiting, 0, L_A | L_B | L_X | L_C | L_Z | L_N | L_V, 5, 1, 0, 33, 19)
