#include "som_c.h"

/* 7ECC16 set_timer_countdown   [class B, 45 bytes, 29 instructions]
 * Source: src/boot/set_timer_countdown.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCZNV.
 */
static void set_timer_countdown(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    BUS16_SET(c, 0x7F0002 + x, y);
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = y >> 8;
    RAM8(0x10000 + x) = 2;
    if (((uint8_t)y | RAM8(0x0001 + (uint16_t)(sp0 - 4))) == 0) {
        RAM8(0x10000 + x) = 1;
    }
    uint8_t value2 = RAM8(0x0000 + sp0 - 4);
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = ((uint8_t)y << 8) | value3;
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value2;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECC16, SOM_RTS, "gen", set_timer_countdown, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 0, 0, 45, 29)
