#include "som_c.h"

/* 7EA14E decode_bit_tree_symbol   [class B, 89 bytes, 47 instructions]
 * Source: src/boot/decode_bit_tree_symbol.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$05E1.  Callers read: ABXY.
 */
static void decode_bit_tree_symbol(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16(c, 0x7F0000 + x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), value);
    uint16_t value2 = BUS16(c, 0x7F0002 + x);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value2);
    uint16_t value3 = RAM16(0x1008A);
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t y1 = value3;
    for (;;) {
        uint16_t value4 = BUS16(c, 0x7F0006 + x);
        uint8_t a_hi2;
        if ((value4 & 0xFF) != 0) {
            a_hi2 = value4 >> 8;
        } else {
            BUS16_SET(c, 0x7F0006 + x, (uint16_t)(value4 + 0x10));
            uint16_t value5 = BUS16_RDL(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)), RAM8(0x0003 + (uint16_t)(sp0 - 7)));
            BUS16_SET(c, 0x7F0004 + x, ((uint8_t)value5 << 8) | (value5 >> 8));
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) + 1));
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) + 1));
            a_hi2 = (uint8_t)value5;
        }
        BUS16_SET(c, 0x7F0006 + x, (uint16_t)(BUS16(c, 0x7F0006 + x) - 1));
        uint16_t value6 = BUS16(c, 0x7F0004 + x);
        BUS16_SET(c, 0x7F0004 + x, (uint16_t)(BUS16(c, 0x7F0004 + x) << 1));
        uint16_t y2;
        if (!(value6 & 0x8000)) {
            y2 = y1;
        } else {
            y2 = (uint16_t)(y1 + 2);
        }
        uint16_t value7 = BUS16(c, 0x7F0000 + y2);
        uint16_t value8 = BUS16(c, 0x7F0000 + value7);
        a1 = (uint8_t)value8;
        a_hi1 = value8 >> 8;
        y1 = value7;
        if (!((value8 & 0xFF00) != 0)) break;
    }
    BUS16_SET(c, 0x7F0000 + x, RAM16(0x0001 + (uint16_t)(sp0 - 7)));
    RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi1 << 8) | a1);
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value13;
    r->x = x;
    r->y = (a_hi1 << 8) | a1;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA14E, SOM_RTS, "gen", decode_bit_tree_symbol, 0, L_A | L_B | L_X | L_Y, 7, 1, 0, 89, 47)
