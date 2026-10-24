#include "som_c.h"

/* 7E8B5D update_title_colour_at_offset7   [class B, 72 bytes, 33 instructions]
 * Source: src/boot/update_title_colour_at_offset7.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABYCV.
 */
static void update_title_colour_at_offset7(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint16_t value = RAM16(0x5DA0 + x);
    uint16_t value2 = RAM16(0x0042);
    if (value2 != 0) {
        RAM16_SET(0x0007 + value2, value);
    }
    uint16_t value4 = RAM16(0x5DE0 + RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    uint16_t value5 = RAM16(0x0046);
    if (value5 != 0) {
        RAM16_SET(0x0007 + value5, value4);
    }
    uint16_t value7 = RAM16(0x5E20 + RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    uint16_t value8 = RAM16(0x004A);
    if (value8 != 0) {
        RAM16_SET(0x0007 + value8, value7);
    }
    uint16_t value10 = RAM16(0x5E60 + RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    uint16_t value11 = RAM16(0x004E);
    if (value11 != 0) {
        RAM16_SET(0x0007 + value11, value10);
    }
    uint8_t value14 = RAM8(0x0000 + sp0 - 3);
    uint8_t value15 = RAM8(0x0000 + sp0 - 2);
    uint8_t value16 = RAM8(0x0000 + sp0 - 1);
    uint8_t value17 = RAM8(0x0000 + sp0);
    r->a = (value10 >> 8 << 8) | value14;
    r->c = value15 & 0x01;
    r->v = value15 & 0x40;
    r->mf = value15 & 0x20;
    r->xf = value15 & 0x10;
    r->dp = (value17 << 8) | value16;
    r->i = value15 & 0x04;
    r->d = value15 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8B5D, SOM_RTS, "gen", update_title_colour_at_offset7, 0, L_A | L_B | L_Y | L_C | L_V, 5, 1, 0, 72, 33)
