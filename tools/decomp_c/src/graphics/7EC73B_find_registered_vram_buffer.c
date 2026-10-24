#include "som_c.h"

/* 7EC73B find_registered_vram_buffer   [class B, 50 bytes, 30 instructions]
 * Source: src/boot/find_registered_vram_buffer.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void find_registered_vram_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 4);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x);
    uint16_t value = RAM16(0x102F4);
    uint8_t a_hi1 = 0;
    uint16_t x1 = value;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x7F0002 + x1);
        uint16_t value3 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        uint8_t a_hi2;
        uint16_t x2;
        if (value2 == value3) {
            a_hi2 = value2 >> 8;
            x2 = x1;
        } else {
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) - 1));
            if (RAM16(0x0001 + (uint16_t)(sp0 - 7)) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 8) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 8);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                continue;
            }
            a_hi2 = (uint16_t)(x1 + 8) >> 8;
            x2 = 0;
        }
        a_hi1 = a_hi2;
        x1 = x2;
        break;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->x = x1;
    r->y = y;
    r->c = value8 & 0x01;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC73B, SOM_RTS, "gen", find_registered_vram_buffer, 0, L_B | L_X | L_Y | L_C | L_V, 7, 0, 0, 50, 30)
