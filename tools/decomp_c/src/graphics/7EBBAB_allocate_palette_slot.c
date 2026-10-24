#include "som_c.h"

/* 7EBBAB allocate_palette_slot   [class B, 60 bytes, 37 instructions]
 * Source: src/boot/allocate_palette_slot.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BXCV.
 */
static void allocate_palette_slot(SomCtx *c)
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
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    uint16_t value = RAM16(0x102D2);
    uint8_t a_hi1 = (uint16_t)(((((a_hi << 8) | a) & 0x0F) << 1 << 1 << 1 << 1 << 1) + value) >> 8;
    uint16_t x1 = (uint16_t)(((((a_hi << 8) | a) & 0x0F) << 1 << 1 << 1 << 1 << 1) + value);
    uint16_t y1 = 8;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x7F0000 + x1);
        uint8_t a_hi2;
        uint16_t x2;
        if ((value2 & 0x8000) != 0) {
            BUS16_SET(c, 0x7F0000 + x1, 0);
            a_hi2 = 0x80;
            x2 = x1;
        } else {
            if ((uint16_t)(y1 - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x20) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x20);
                uint16_t y1_next = (uint16_t)(y1 - 1);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                continue;
            }
            a_hi2 = (uint16_t)(x1 + 0x20) >> 8;
            x2 = 0;
        }
        a_hi1 = a_hi2;
        x1 = x2;
        break;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->c = value4 & 0x01;
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
SOM_REGISTER(0x7EBBAB, SOM_RTS, "gen", allocate_palette_slot, 0, L_B | L_X | L_C | L_V, 6, 1, 0, 60, 37)
