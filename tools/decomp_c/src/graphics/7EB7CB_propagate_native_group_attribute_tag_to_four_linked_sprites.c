#include "som_c.h"

/* 7EB7CB propagate_native_group_attribute_tag_to_four_linked_sprites   [class B, 57 bytes, 38 instructions]
 * Source: src/boot/propagate_native_group_attribute_tag_to_four_linked_sprites.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void propagate_native_group_attribute_tag_to_four_linked_sprites(SomCtx *c)
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
    if ((uint32_t)(uint16_t)((uint16_t)(sp0 - 5) + 1) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = db;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint8_t value = BUS8(c, 0x7F000B + x);
    uint8_t a_hi1;
    uint16_t x2;
    uint16_t y2;
    if ((uint8_t)((a_hi << 8) | a) == value) {
        a_hi1 = a_hi;
        x2 = x;
        y2 = y;
    } else {
        BUS8_SET(c, 0x7F000B + x, (uint8_t)((a_hi << 8) | a));
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = 4;
        uint16_t x1 = x;
        uint16_t y1 = y;
        do {
            uint16_t value2 = BUS16(c, 0x7F0000 + x1);
            BUS8_SET(c, 0x7F000B + value2, (uint8_t)((a_hi << 8) | a) >> 2);
            RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1))--;
            x1 = (uint16_t)(x1 + 2);
            y1 = value2;
        } while (RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) != 0);
        RAM8(0x102D0) = 1;
        a_hi1 = 4;
        x2 = x1;
        y2 = y1;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 4);
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value4;
    r->x = x2;
    r->y = y2;
    r->c = value5 & 0x01;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value3;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB7CB, SOM_RTS, "gen", propagate_native_group_attribute_tag_to_four_linked_sprites, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 57, 38)
