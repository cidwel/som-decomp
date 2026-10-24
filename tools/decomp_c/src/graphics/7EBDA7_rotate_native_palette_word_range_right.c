#include "som_c.h"

/* 7EBDA7 rotate_native_palette_word_range_right   [class B, 90 bytes, 54 instructions]
 * Source: src/boot/rotate_native_palette_word_range_right.s
 * Documented in docs/source-recovery-parallel-palette-apis.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void rotate_native_palette_word_range_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
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
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = db;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), value & 0xFF);
    uint16_t value2 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF);
    uint16_t value3 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
    uint16_t x3;
    if ((uint16_t)(((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) - value3) == 0) {
        x3 = x;
    } else {
        uint16_t x2;
        if (((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) < value3) {
            x2 = x;
        } else {
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), (uint16_t)(((((uint8_t)value2 << 8) | (value2 >> 8)) & 0xFF) - value3));
            RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0005 + (uint16_t)(sp0 - 9)) << 1));
            uint16_t value5 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
            uint16_t value6 = BUS16(c, 0x7F0000 + (uint16_t)(x + value5));
            RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value6);
            uint8_t a_hi1 = value6 >> 8;
            uint16_t x1 = (uint16_t)(x + value5);
            do {
                uint16_t value7 = BUS16(c, 0x7F0000 + (uint16_t)(x1 - 2));
                BUS16_SET(c, 0x7F0002 + (uint16_t)(x1 - 2), value7);
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 9)) - 1));
                a_hi1 = value7 >> 8;
                x1 = (uint16_t)(x1 - 2);
            } while (RAM16(0x0003 + (uint16_t)(sp0 - 9)) != 0);
            BUS16_SET(c, 0x7F0000 + x1, RAM16(0x0005 + (uint16_t)(sp0 - 9)));
            x2 = x1;
        }
        x3 = x2;
    }
    uint8_t value9 = RAM8(0x0000 + sp0 - 9);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->x = x3;
    r->y = y;
    r->c = value10 & 0x01;
    r->z = ((value12 << 8) | value11) == 0;
    r->n = ((value12 << 8) | value11) & 0x8000;
    r->v = value10 & 0x40;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value9;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBDA7, SOM_RTS, "gen", rotate_native_palette_word_range_right, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 12, 1, 0, 90, 54)
