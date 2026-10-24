#include "som_c.h"

/* C13F71 find_free_spell_entity_sprite_instance   [class B, 95 bytes, 55 instructions]
 * Source: src/rom/find_free_spell_entity_sprite_instance.s
 * Documented in docs/actor-cast-entity-sprite-instances.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void find_free_spell_entity_sprite_instance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
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
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    uint16_t value = RAM16(0x841A);
    uint16_t x8;
    uint16_t y8;
    if (value == 0) {
        x8 = value;
        y8 = y;
    } else {
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)((a_hi << 8) | a);
        uint8_t a_hi1 = (uint16_t)(value + 0x0400) >> 8;
        uint16_t x1 = (uint16_t)(value + 0x0400);
        uint16_t y1 = 0x40;
        for (;;) {
            uint8_t value2 = RAM8(0x0008 + (uint16_t)(x1 - 0x10));
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
                uint8_t a_hi2 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0400) >> 8;
                uint16_t x2 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0400);
                uint16_t y2 = 0x40;
                for (;;) {
                    uint8_t value3 = RAM8(0x0008 + (uint16_t)(x2 - 0x10));
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
                x7 = x2;
                y7 = y2;
            } else {
                uint8_t value4 = RAM8(0x000B + (uint16_t)(x1 - 0x10));
                uint8_t value5 = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
                uint16_t x6;
                uint16_t y6;
                if (value4 == value5) {
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
                    uint8_t a_hi3 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0400) >> 8;
                    uint16_t x4 = (uint16_t)((uint16_t)(x1 - 0x10) + 0x0400);
                    uint16_t y4 = 0x40;
                    for (;;) {
                        uint8_t value6 = RAM8(0x0008 + (uint16_t)(x4 - 0x10));
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
                    x6 = x4;
                    y6 = y4;
                }
                x7 = x6;
                y7 = y6;
            }
            x1 = x7;
            y1 = y7;
            break;
        }
        x8 = x1;
        y8 = y1;
    }
    r->x = x8;
    r->y = y8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13F71, SOM_RTS, "gen", find_free_spell_entity_sprite_instance, 0, L_X | L_Y, 5, 1, 0, 95, 55)
