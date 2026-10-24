#include "som_c.h"

/* 7EA090 build_colour_binary_tree   [class B, 158 bytes, 97 instructions]
 * Source: src/boot/build_colour_binary_tree.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$05F1.  Callers read: AB.
 */
static void build_colour_binary_tree(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x10) = 0x7F;
    RAM8(0x0000 + sp0 - 0x11) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x12) = 0x7F;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x10), value);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x10), x);
    uint16_t value2 = BUS16(c, (RAM8(0x0003 + (uint16_t)(sp0 - 0x10)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 0x10)));
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x10), ((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) + 1);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x10), (((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF);
    uint16_t value3 = RAM16(0x1008A);
    RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), (uint16_t)(value3 + 0x03FC));
    uint8_t a_hi1 = (uint16_t)(value3 + 0x03FC) >> 8;
    uint16_t x1 = value3;
    uint16_t y1 = 2;
    do {
        RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x10), x1);
        uint16_t value4 = BUS16(c, (RAM8(0x0003 + (uint16_t)(sp0 - 0x10)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 0x10)) + y1);
        RAM16_SET(0x000C + (uint16_t)(sp0 - 0x10), value4);
        uint16_t value5 = RAM16(0x0008 + (uint16_t)(sp0 - 0x10));
        uint16_t value6 = RAM16(0x000A + (uint16_t)(sp0 - 0x10));
        uint8_t a1;
        uint8_t a_hi2;
        if ((uint16_t)(((value4 & 0xFF) + 1 << 1 << 1) + value5) < value6) {
            a1 = (uint8_t)(((value4 & 0xFF) + 1 << 1 << 1) + value5);
            a_hi2 = (uint16_t)(((value4 & 0xFF) + 1 << 1 << 1) + value5) >> 8;
        } else {
            a1 = (uint8_t)(((uint16_t)((uint16_t)(((value4 & 0xFF) + 1 << 1 << 1) + value5) - value6) >> 1) + value6);
            a_hi2 = (uint16_t)(((uint16_t)((uint16_t)(((value4 & 0xFF) + 1 << 1 << 1) + value5) - value6) >> 1) + value6) >> 8;
        }
        RAM16_SET(0x10000 + x1, (a_hi2 << 8) | a1);
        uint16_t value7 = RAM16(0x000D + (uint16_t)(sp0 - 0x10));
        uint16_t value8 = RAM16(0x0008 + (uint16_t)(sp0 - 0x10));
        uint16_t value9 = RAM16(0x000A + (uint16_t)(sp0 - 0x10));
        uint8_t a2;
        uint8_t a_hi3;
        if ((uint16_t)(((value7 & 0xFF) + 1 << 1 << 1) + value8) < value9) {
            a2 = (uint8_t)(((value7 & 0xFF) + 1 << 1 << 1) + value8);
            a_hi3 = (uint16_t)(((value7 & 0xFF) + 1 << 1 << 1) + value8) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)((uint16_t)(((value7 & 0xFF) + 1 << 1 << 1) + value8) - value9) >> 1) + value9);
            a_hi3 = (uint16_t)(((uint16_t)((uint16_t)(((value7 & 0xFF) + 1 << 1 << 1) + value8) - value9) >> 1) + value9) >> 8;
        }
        RAM16_SET(0x10002 + x1, (a_hi3 << 8) | a2);
        RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x0004 + (uint16_t)(sp0 - 0x10)) - 1));
        uint8_t a_hi1_next = (uint16_t)(x1 + 4) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 4);
        uint16_t y1_next = (uint16_t)(y1 + 2);
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
    } while (RAM16(0x0004 + (uint16_t)(sp0 - 0x10)) != 0);
    uint16_t value10 = RAM16(0x0006 + (uint16_t)(sp0 - 0x10));
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x10), value10);
    uint16_t value11 = RAM16(0x000A + (uint16_t)(sp0 - 0x10));
    uint8_t a_hi4 = value10 >> 8;
    uint16_t x2 = value11;
    uint16_t y2 = y1;
    for (;;) {
        uint16_t value12 = BUS16(c, (RAM8(0x0003 + (uint16_t)(sp0 - 0x10)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 0x10)) + y2);
        RAM16_SET(0x10000 + x2, value12 & 0xFF);
        RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x0004 + (uint16_t)(sp0 - 0x10)) - 1));
        a_hi4 = 0;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 1);
        if (!(RAM16(0x0004 + (uint16_t)(sp0 - 0x10)) != a_hi4)) break;
    }
    uint16_t value13 = BUS16(c, (RAM8(0x0003 + (uint16_t)(sp0 - 0x10)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 0x10)));
    RAM16_SET(0x0000 + sp0 - 4, value13);
    uint8_t value14 = RAM8(0x0000 + sp0 - 4);
    uint8_t value15 = RAM8(0x0000 + sp0 - 3);
    uint8_t value16 = RAM8(0x0000 + sp0 - 1);
    uint8_t value17 = RAM8(0x0000 + sp0);
    r->a = (value15 << 8) | value14;
    r->dp = (value17 << 8) | value16;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA090, SOM_RTS, "gen", build_colour_binary_tree, 0, L_A | L_B, 19, 0, 0, 158, 97)
