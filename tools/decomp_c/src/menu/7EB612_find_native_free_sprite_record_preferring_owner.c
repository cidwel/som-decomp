#include "som_c.h"

/* 7EB612 find_native_free_sprite_record_preferring_owner   [class B, 95 bytes, 55 instructions]
 * Source: src/boot/find_native_free_sprite_record_preferring_owner.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BXY.
 */
static void find_native_free_sprite_record_preferring_owner(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)((uint16_t)(sp0 - 5) + 1) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    uint16_t value = RAM16(0x102C8);
    uint8_t a_hi6;
    uint16_t x8;
    uint16_t y8;
    if (value == 0) {
        a_hi6 = a_hi;
        x8 = value;
        y8 = y;
    } else {
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)((a_hi << 8) | a);
        uint8_t a_hi1 = (uint16_t)(value + 0x0800) >> 8;
        uint16_t x1 = (uint16_t)(value + 0x0800);
        uint16_t y1 = 0x80;
        for (;;) {
            uint8_t value2 = BUS8(c, 0x7F0008 + (uint16_t)(x1 - 0x10));
            uint8_t a_hi5;
            uint16_t x7;
            uint16_t y7;
            if (value2 != 0) {
                if ((uint16_t)(y1 - 1) != 0) {
                    uint8_t a_hi1_next = (uint16_t)(x1 - 0x10) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 - 0x10);
                    uint16_t y1_next = (uint16_t)(y1 - 1);
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    continue;
                }
                uint8_t a_hi2 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0800) >> 8;
                uint16_t x2 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0800);
                uint16_t y2 = 0x80;
                for (;;) {
                    uint8_t value3 = BUS8(c, 0x7F0008 + (uint16_t)(x2 - 0x10));
                    uint16_t x3;
                    uint16_t y3;
                    if (value3 == 0) {
                        x3 = (uint16_t)(x2 - 0x10);
                        y3 = y2;
                    } else {
                        if ((uint16_t)(y2 - 1) != 0) {
                            uint8_t a_hi2_next = (uint16_t)(x2 - 0x10) >> 8;
                            uint16_t x2_next = (uint16_t)(x2 - 0x10);
                            uint16_t y2_next = (uint16_t)(y2 - 1);
                            a_hi2 = a_hi2_next;
                            x2 = x2_next;
                            y2 = y2_next;
                            continue;
                        }
                        x3 = 0;
                        y3 = (uint16_t)(y2 - 1);
                    }
                    uint8_t a_hi2_next2 = (uint16_t)(x2 - 0x10) >> 8;
                    uint16_t x2_next2 = x3;
                    uint16_t y2_next2 = y3;
                    a_hi2 = a_hi2_next2;
                    x2 = x2_next2;
                    y2 = y2_next2;
                    break;
                }
                a_hi5 = a_hi2;
                x7 = x2;
                y7 = y2;
            } else {
                uint8_t value4 = BUS8(c, 0x7F000B + (uint16_t)(x1 - 0x10));
                uint8_t value5 = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
                uint8_t a_hi4;
                uint16_t x6;
                uint16_t y6;
                if (value4 == value5) {
                    a_hi4 = (uint16_t)(x1 - 0x10) >> 8;
                    x6 = (uint16_t)(x1 - 0x10);
                    y6 = y1;
                } else {
                    if ((uint16_t)(y1 - 1) != 0) {
                        uint8_t a_hi1_next2 = (uint16_t)(x1 - 0x10) >> 8;
                        uint16_t x1_next2 = (uint16_t)(x1 - 0x10);
                        uint16_t y1_next2 = (uint16_t)(y1 - 1);
                        a_hi1 = a_hi1_next2;
                        x1 = x1_next2;
                        y1 = y1_next2;
                        continue;
                    }
                    uint8_t a_hi3 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0800) >> 8;
                    uint16_t x4 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0800);
                    uint16_t y4 = 0x80;
                    for (;;) {
                        uint8_t value6 = BUS8(c, 0x7F0008 + (uint16_t)(x4 - 0x10));
                        uint16_t x5;
                        uint16_t y5;
                        if (value6 == 0) {
                            x5 = (uint16_t)(x4 - 0x10);
                            y5 = y4;
                        } else {
                            if ((uint16_t)(y4 - 1) != 0) {
                                uint8_t a_hi3_next = (uint16_t)(x4 - 0x10) >> 8;
                                uint16_t x4_next = (uint16_t)(x4 - 0x10);
                                uint16_t y4_next = (uint16_t)(y4 - 1);
                                a_hi3 = a_hi3_next;
                                x4 = x4_next;
                                y4 = y4_next;
                                continue;
                            }
                            x5 = 0;
                            y5 = (uint16_t)(y4 - 1);
                        }
                        uint8_t a_hi3_next2 = (uint16_t)(x4 - 0x10) >> 8;
                        uint16_t x4_next2 = x5;
                        uint16_t y4_next2 = y5;
                        a_hi3 = a_hi3_next2;
                        x4 = x4_next2;
                        y4 = y4_next2;
                        break;
                    }
                    a_hi4 = a_hi3;
                    x6 = x4;
                    y6 = y4;
                }
                a_hi5 = a_hi4;
                x7 = x6;
                y7 = y6;
            }
            a_hi1 = a_hi5;
            x1 = x7;
            y1 = y7;
            break;
        }
        a_hi6 = a_hi1;
        x8 = x1;
        y8 = y1;
    }
    r->a = (a_hi6 << 8) | RAM8(0x0000 + sp0 - 3);
    r->x = x8;
    r->y = y8;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB612, SOM_RTS, "gen", find_native_free_sprite_record_preferring_owner, 0, L_B | L_X | L_Y, 5, 1, 0, 95, 55)
