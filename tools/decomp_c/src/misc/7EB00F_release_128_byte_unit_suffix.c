#include "som_c.h"

/* 7EB00F release_128_byte_unit_suffix   [class B, 114 bytes, 64 instructions]
 * Source: src/boot/release_128_byte_unit_suffix.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BXY.
 */
static void release_128_byte_unit_suffix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
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
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), x);
    uint16_t x5;
    if (x == 0) {
        x5 = x;
    } else {
        uint16_t x4;
        if ((x & 0x7F) != 0) {
            x4 = x;
        } else {
            uint16_t value = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            RAM8(0x0001 + (uint16_t)(sp0 - 9)) = (uint8_t)(value >> 7);
            uint8_t value2 = RAM8(0x100C4 + ((value >> 7) & 0xFF));
            RAM8(0x0004 + (uint16_t)(sp0 - 9)) = value2;
            uint16_t x3;
            if (value2 == 0) {
                x3 = (value >> 7) & 0xFF;
            } else {
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = RAM8(0x100C4 + ((value >> 7) & 0xFF));
                RAM8(0x0000 + sp0 - 9) = 0;
                RAM8(0x0000 + sp0 - 0x0A) = (value >> 7) & 0xFF;
                uint16_t x1 = (value >> 7) & 0xFF;
                do {
                    BUS8_SET(c, 0x7F00C4 + x1, 0);
                    BUS8_SET(c, 0x7F01C4 + x1, 0);
                    RAM8(0x0006 + (uint16_t)(sp0 - 9))--;
                    x1 = (uint16_t)(x1 + 1);
                } while (RAM8(0x0006 + (uint16_t)(sp0 - 9)) != 0);
                uint8_t value4 = RAM8(0x0000 + sp0 - 0x0A);
                uint8_t value5 = RAM8(0x0000 + sp0 - 9);
                uint8_t a_hi1 = 0;
                uint16_t x2 = (value5 << 8) | value4;
                for (;;) {
                    uint8_t value7 = BUS8(c, 0x7F00C4 + (uint16_t)(x2 - 1));
                    uint8_t value8 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                    if ((uint8_t)(value7 - value8) != 0) {
                        if (value7 >= value8) {
                            BUS8_SET(c, 0x7F00C4 + (uint16_t)(x2 - 1), (uint8_t)(value7 - value8));
                            x2 = (uint16_t)(x2 - 1);
                            continue;
                        }
                    }
                    x2 = (uint16_t)(x2 - 1);
                    break;
                }
                uint8_t value9 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                if (value9 < RAM8(0x100C2)) {
                    RAM8(0x100C2) = value9;
                }
                x3 = x2;
            }
            x4 = x3;
        }
        x5 = x4;
    }
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->x = x5;
    r->y = y;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB00F, SOM_RTS, "gen", release_128_byte_unit_suffix, 0, L_B | L_X | L_Y, 11, 1, 0, 114, 64)
