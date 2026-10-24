#include "som_c.h"

/* C251DC choose_descriptor_fourteen_phase_zero_target_action   [class B, 108 bytes, 50 instructions]
 * Source: src/rom/choose_descriptor_fourteen_phase_zero_target_action.s
 * Documented in docs/boss-descriptor-fourteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_fourteen_phase_zero_target_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x51DE, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    if ((RAM16(0x007E + x_ret) & 0x8000) == 0) {
        r->a = RAM16(0x00A9 + x_ret);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5204, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all2 = r->a;
        if (a_all2 < 4) {
            uint16_t value3 = RAM16(0x0287);
            if ((RAM16(0x01B1 + value3) & 0x40) != 0) {
                uint16_t value5 = RAM16(0x00A9 + value3);
                if (RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000)) != 0) {
                    r->a = 1;
                    r->x = value3;
                    r->y = (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000);
                    r->c = (uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000 > 0xFFFF;
                    r->v = (((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    JSR(c, 0x5240, 0xC2300B); /* draw_boss_frame_random_number */
                    uint16_t a_all3 = r->a;
                    r->a = 0xD902;
                    r->x = (uint16_t)(a_all3 << 1);
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->x = value3;
                r->y = (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000);
                r->c = (uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000 > 0xFFFF;
                r->v = (((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5232, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all4 = r->a;
                uint16_t value7 = BUS16(c, 0xC2DADA + (uint16_t)(a_all4 << 1));
                r->a = value7;
                r->x = (uint16_t)(a_all4 << 1);
                r->c = 0;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xD906;
            r->x = value3;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD908;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (RAM16(0x00AB + x_ret) != 1) {
        r->a = RAM16(0x00A9 + x_ret);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5204, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all5 = r->a;
        if (a_all5 < 4) {
            uint16_t value10 = RAM16(0x0287);
            if ((RAM16(0x01B1 + value10) & 0x40) != 0) {
                uint16_t value12 = RAM16(0x00A9 + value10);
                if (RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000)) != 0) {
                    r->a = 1;
                    r->x = value10;
                    r->y = (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000);
                    r->c = (uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000 > 0xFFFF;
                    r->v = (((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    JSR(c, 0x5240, 0xC2300B); /* draw_boss_frame_random_number */
                    uint16_t a_all6 = r->a;
                    r->a = 0xD902;
                    r->x = (uint16_t)(a_all6 << 1);
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->x = value10;
                r->y = (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000);
                r->c = (uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000 > 0xFFFF;
                r->v = (((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value12 << 8) | (value12 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5232, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all7 = r->a;
                uint16_t value14 = BUS16(c, 0xC2DADA + (uint16_t)(a_all7 << 1));
                r->a = value14;
                r->x = (uint16_t)(a_all7 << 1);
                r->c = 0;
                r->z = value14 == 0;
                r->n = value14 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xD906;
            r->x = value10;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD908;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x51F4, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all8 = r->a;
    uint16_t x_ret8 = r->x;
    if (a_all8 >= 2) {
        r->a = RAM16(0x00A9 + x_ret8);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5204, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all9 = r->a;
        if (a_all9 < 4) {
            uint16_t value17 = RAM16(0x0287);
            if ((RAM16(0x01B1 + value17) & 0x40) != 0) {
                uint16_t value19 = RAM16(0x00A9 + value17);
                if (RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000)) != 0) {
                    r->a = 1;
                    r->x = value17;
                    r->y = (uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000);
                    r->c = (uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000 > 0xFFFF;
                    r->v = (((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    JSR(c, 0x5240, 0xC2300B); /* draw_boss_frame_random_number */
                    uint16_t a_all10 = r->a;
                    r->a = 0xD902;
                    r->x = (uint16_t)(a_all10 << 1);
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 1;
                r->x = value17;
                r->y = (uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000);
                r->c = (uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000 > 0xFFFF;
                r->v = (((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value19 << 8) | (value19 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5232, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all11 = r->a;
                uint16_t value21 = BUS16(c, 0xC2DADA + (uint16_t)(a_all11 << 1));
                r->a = value21;
                r->x = (uint16_t)(a_all11 << 1);
                r->c = 0;
                r->z = value21 == 0;
                r->n = value21 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xD906;
            r->x = value17;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD908;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD916;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC251DC, SOM_RTS, "gen", choose_descriptor_fourteen_phase_zero_target_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 108, 50)
