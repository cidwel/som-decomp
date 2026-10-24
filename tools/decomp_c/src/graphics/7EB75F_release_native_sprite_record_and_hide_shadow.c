#include "som_c.h"

/* 7EB75F release_native_sprite_record_and_hide_shadow   [class A, 39 bytes, 20 instructions]
 * Source: src/boot/release_native_sprite_record_and_hide_shadow.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06E6.  Callers read: BXYCV.
 */
static void release_native_sprite_record_and_hide_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06E6) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xE6;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    BUS16_SET(c, 0x7F0002 + x, 0xFFF0);
    BUS16_SET(c, 0x7F0004 + x, 0);
    BUS16_SET(c, 0x7F0008 + x, 0);
    uint16_t value = BUS16(c, 0x7F000A + x);
    uint16_t value2 = RAM16(0x102CC);
    BUS8_SET(c, 0x7F0001 + (uint16_t)(((value & 0xFF) << 1 << 1) + value2), 0xF0);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = ((uint16_t)(((value & 0xFF) << 1 << 1) + value2) >> 8 << 8) | 0xF0;
    r->x = (uint16_t)(((value & 0xFF) << 1 << 1) + value2);
    r->c = value3 & 0x01;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB75F, SOM_RTS, "gen", release_native_sprite_record_and_hide_shadow, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 39, 20)
