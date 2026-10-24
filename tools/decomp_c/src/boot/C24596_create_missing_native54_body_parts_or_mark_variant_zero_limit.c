#include "som_c.h"

/* C24596 create_missing_native54_body_parts_or_mark_variant_zero_limit   [class B, 146 bytes, 55 instructions]
 * Source: src/rom/create_missing_native54_body_parts_or_mark_variant_zero_limit.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void create_missing_native54_body_parts_or_mark_variant_zero_limit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0042 + value);
    uint8_t a_hi6;
    uint16_t y6;
    bool overflow6;
    if (value2 != 0) {
        uint16_t value3 = RAM16(0xE800);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool overflow1;
        if ((value3 & 1) != 0) {
            a_hi1 = value3 >> 8;
            x1 = value;
            y1 = y;
            overflow1 = overflow;
        } else {
            r->a = 0;
            r->x = value;
            JSR(c, 0x45BA, 0xC24628); /* derive_native54_part_spawn_position_from_variant_and_offset */
            uint16_t x_ret = r->x;
            RAM16_SET(0x00B0 + x_ret, (uint16_t)(RAM16(0x00B0 + x_ret) + 1));
            r->x = 0x4AFB;
            r->y = 0x1811;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x45C6, 0xC20D53); /* allocate_boss_object_pool_slot */
            uint16_t x_ret2 = r->x;
            bool overflow_ret2 = r->v;
            RAM16_SET(0x002B + x_ret2, RAM16(0x0295));
            RAM16_SET(0x0032 + x_ret2, RAM16(0x0297));
            RAM16_SET(0x00A9 + x_ret2, 0);
            RAM16_SET(0x00B0 + x_ret2, RAM16(0x0287));
            RAM16_SET(0x0182 + x_ret2, 1);
            a_hi1 = 0;
            x1 = 1;
            y1 = 0x1811;
            overflow1 = overflow_ret2;
        }
        uint16_t value7 = RAM16(0xEA00);
        uint8_t a_hi2;
        uint16_t y2;
        bool overflow2;
        if ((value7 & 1) != 0) {
            a_hi2 = value7 >> 8;
            y2 = y1;
            overflow2 = overflow1;
        } else {
            r->a = 4;
            r->x = x1;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x45ED, 0xC24628); /* derive_native54_part_spawn_position_from_variant_and_offset */
            uint16_t x_ret3 = r->x;
            RAM16_SET(0x00B0 + x_ret3, (uint16_t)(RAM16(0x00B0 + x_ret3) + 1));
            r->x = 0x4AFB;
            r->y = 0x1911;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x45F9, 0xC20D53); /* allocate_boss_object_pool_slot */
            uint16_t x_ret4 = r->x;
            bool overflow_ret4 = r->v;
            RAM16_SET(0x002B + x_ret4, RAM16(0x0295));
            RAM16_SET(0x0032 + x_ret4, RAM16(0x0297));
            RAM16_SET(0x00A9 + x_ret4, 1);
            RAM16_SET(0x00B0 + x_ret4, RAM16(0x0287));
            RAM16_SET(0x0182 + x_ret4, 1);
            a_hi2 = 0;
            y2 = 0x1911;
            overflow2 = overflow_ret4;
        }
        a_hi6 = a_hi2;
        y6 = y2;
        overflow6 = overflow2;
    } else {
        uint16_t value11 = RAM16(0x00B0 + value);
        uint8_t a_hi5;
        uint16_t y5;
        bool overflow5;
        if (value11 < 2) {
            uint16_t value12 = RAM16(0xE800);
            uint8_t a_hi3;
            uint16_t x2;
            uint16_t y3;
            bool overflow3;
            if ((value12 & 1) != 0) {
                a_hi3 = value12 >> 8;
                x2 = value;
                y3 = y;
                overflow3 = overflow;
            } else {
                r->a = 0;
                r->x = value;
                JSR(c, 0x45BA, 0xC24628); /* derive_native54_part_spawn_position_from_variant_and_offset */
                uint16_t x_ret5 = r->x;
                RAM16_SET(0x00B0 + x_ret5, (uint16_t)(RAM16(0x00B0 + x_ret5) + 1));
                r->x = 0x4AFB;
                r->y = 0x1811;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x45C6, 0xC20D53); /* allocate_boss_object_pool_slot */
                uint16_t x_ret6 = r->x;
                bool overflow_ret6 = r->v;
                RAM16_SET(0x002B + x_ret6, RAM16(0x0295));
                RAM16_SET(0x0032 + x_ret6, RAM16(0x0297));
                RAM16_SET(0x00A9 + x_ret6, 0);
                RAM16_SET(0x00B0 + x_ret6, RAM16(0x0287));
                RAM16_SET(0x0182 + x_ret6, 1);
                a_hi3 = 0;
                x2 = 1;
                y3 = 0x1811;
                overflow3 = overflow_ret6;
            }
            uint16_t value16 = RAM16(0xEA00);
            uint8_t a_hi4;
            uint16_t y4;
            bool overflow4;
            if ((value16 & 1) != 0) {
                a_hi4 = value16 >> 8;
                y4 = y3;
                overflow4 = overflow3;
            } else {
                r->a = 4;
                r->x = x2;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x45ED, 0xC24628); /* derive_native54_part_spawn_position_from_variant_and_offset */
                uint16_t x_ret7 = r->x;
                RAM16_SET(0x00B0 + x_ret7, (uint16_t)(RAM16(0x00B0 + x_ret7) + 1));
                r->x = 0x4AFB;
                r->y = 0x1911;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x45F9, 0xC20D53); /* allocate_boss_object_pool_slot */
                uint16_t x_ret8 = r->x;
                bool overflow_ret8 = r->v;
                RAM16_SET(0x002B + x_ret8, RAM16(0x0295));
                RAM16_SET(0x0032 + x_ret8, RAM16(0x0297));
                RAM16_SET(0x00A9 + x_ret8, 1);
                RAM16_SET(0x00B0 + x_ret8, RAM16(0x0287));
                RAM16_SET(0x0182 + x_ret8, 1);
                a_hi4 = 0;
                y4 = 0x1911;
                overflow4 = overflow_ret8;
            }
            a_hi5 = a_hi4;
            y5 = y4;
            overflow5 = overflow4;
        } else {
            RAM16_SET(0x00BE + value, 1);
            a_hi5 = 0;
            y5 = y;
            overflow5 = overflow;
        }
        a_hi6 = a_hi5;
        y6 = y5;
        overflow6 = overflow5;
    }
    uint16_t value20 = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value20, 2);
    RAM16_SET(0x00B2 + value20, 1);
    RAM16_SET(OBJECT_AGE + value20, 0);
    r->a = 1;
    r->x = value20;
    r->y = y6;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    r->v = overflow6;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24596, SOM_RTS, "gen", create_missing_native54_body_parts_or_mark_variant_zero_limit, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 146, 55)
