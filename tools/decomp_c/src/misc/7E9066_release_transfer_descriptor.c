#include "som_c.h"

/* 7E9066 release_transfer_descriptor   [class B, 116 bytes, 57 instructions]
 * Source: src/boot/release_transfer_descriptor.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void release_transfer_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t a_hi5;
    uint16_t x2;
    uint16_t y4;
    if (x == 0) {
        a_hi5 = a >> 8;
        x2 = x;
        y4 = y;
    } else {
        uint8_t value = BUS8(c, 0x7F000D + x);
        uint8_t a_hi3;
        uint16_t y3;
        bool overflow3;
        if (value == 0) {
            a_hi3 = a >> 8;
            y3 = y;
            overflow3 = overflow;
        } else {
            uint8_t a_hi2;
            uint16_t y2;
            bool overflow2;
            if (value == 0x20) {
                uint16_t value2 = RAM16(0x10068);
                uint8_t value3 = RAM8(0x10000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2));
                uint8_t a2;
                if ((uint8_t)(value3 - 1) == 1) {
                    a2 = 0;
                } else {
                    uint8_t a1;
                    if ((uint8_t)(value3 - 1) >= 1) {
                        a1 = (uint8_t)(value3 - 1);
                    } else {
                        a1 = 0;
                    }
                    a2 = a1;
                }
                RAM8(0x10000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) = a2;
                a_hi2 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2) >> 8;
                y2 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2);
                overflow2 = (((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) & (value2 ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) & 0x8000) != 0;
            } else {
                uint8_t a_hi1;
                uint16_t y1;
                bool overflow1;
                if (value >= 0x20) {
                    a_hi1 = a >> 8;
                    y1 = y;
                    overflow1 = overflow;
                } else {
                    uint16_t value4 = RAM16(0x10068);
                    uint8_t value5 = RAM8(0x10000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4));
                    uint8_t a4;
                    if ((uint8_t)(value5 - 1) == 1) {
                        a4 = 0;
                    } else {
                        uint8_t a3;
                        if ((uint8_t)(value5 - 1) >= 1) {
                            a3 = (uint8_t)(value5 - 1);
                        } else {
                            a3 = 0;
                        }
                        a4 = a3;
                    }
                    RAM8(0x10000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) = a4;
                    a_hi1 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4) >> 8;
                    y1 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4);
                    overflow1 = (((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) & (value4 ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) & 0x8000) != 0;
                }
                a_hi2 = a_hi1;
                y2 = y1;
                overflow2 = overflow1;
            }
            a_hi3 = a_hi2;
            y3 = y2;
            overflow3 = overflow2;
        }
        uint8_t value6 = BUS8(c, 0x7F000F + x);
        uint8_t a_hi4;
        uint16_t x1;
        if (value6 != 5) {
            a_hi4 = a_hi3;
            x1 = x;
        } else {
            uint8_t value7 = BUS8(c, 0x7F0009 + x);
            RAM8(0x10070) = (value7 ^ 0xFF) & RAM8(0x10070);
            uint8_t value9 = BUS8(c, 0x7F0009 + x);
            RAM8(0x0000 + sp0 - 4) = x >> 8;
            RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
            r->x = ((a_hi3 << 8) | value9) & 0xFF;
            r->y = y3;
            r->c = value6 >= 5;
            r->z = (((a_hi3 << 8) | value9) & 0xFF) == 0;
            r->n = ((a_hi3 << 8) | value9) & 0xFF & 0x8000;
            r->v = overflow3;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x90BB, 0x7EC365); GUARD_JSR(c, sp_call, 0x90BB); } /* find_native_highest_set_bit_or_byte_ff */
            r->sp += 6;
            uint16_t a_all = r->a;
            RAM8(0x10072 + (a_all & 7)) = 0;
            uint8_t value10 = RAM8(0x0000 + sp0 - 5);
            uint8_t value11 = RAM8(0x0000 + sp0 - 4);
            uint8_t value12 = BUS8(c, 0x7F0009 + ((value11 << 8) | value10));
            if (value12 == 1) {
                RAM8(0x1007A) = 0;
                RAM8(0x1007B) = 0;
            }
            a_hi4 = 0;
            x1 = (value11 << 8) | value10;
        }
        BUS8_SET(c, 0x7F000F + x1, 0);
        a_hi5 = a_hi4;
        x2 = x1;
        y4 = y3;
    }
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (a_hi5 << 8) | (uint8_t)a;
    r->x = x2;
    r->y = y4;
    r->c = value14 & 0x01;
    r->v = value14 & 0x40;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = value13;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9066, SOM_RTS, "gen", release_transfer_descriptor, 0, L_B | L_X | L_Y | L_C | L_V, 6, 0, 0, 116, 57)
