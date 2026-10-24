#include "som_c.h"

/* 7EBC9A copy_palette_colours   [class B, 79 bytes, 52 instructions]
 * Source: src/boot/copy_palette_colours.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABYCV.
 */
static void copy_palette_colours(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7F;
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    RAM8(0x0005 + (uint16_t)(sp0 - 0x0A)) = value >> 8;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0A), y);
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0A), x);
    uint16_t value2 = RAM16(0x0006 + (uint16_t)(sp0 - 0x0A));
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0A), (RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) & 0x0F) + 1);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (uint16_t)(((value & 0xF0) >> 3) + value2);
    uint16_t y1 = 0;
    do {
        uint16_t value4;
        BUS16_OK(c, (RAM8(0x0005 + (uint16_t)(sp0 - 0x0A)) << 0x10) + RAM16(0x0003 + (uint16_t)(sp0 - 0x0A)) + y1, value4);
        RAM16_SET(0x10000 + x1, value4);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0A), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) - 1));
        a_hi1 = value4 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0001 + (uint16_t)(sp0 - 0x0A)) != 0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x0A) + 7);
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBC9A, SOM_RTS, "hand", copy_palette_colours, 0, L_A | L_B | L_Y | L_C | L_V, 13, 1, 0, 79, 52)
