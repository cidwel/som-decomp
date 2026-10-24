#include "som_c.h"

/* C260CE choose_descriptor_five_target_hold_or_hp_fallback   [class B, 162 bytes, 71 instructions]
 * Source: src/rom/choose_descriptor_five_target_hold_or_hp_fallback.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_five_target_hold_or_hp_fallback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    JSR(c, 0x60D2, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = false;
    r->xf = false;
    JSR(c, 0x60D8, 0xC208BC); /* derive_clamped_target_distance_minus_one */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 >= 2) {
        if (a_all2 >= 4) {
            r->c = a_all2 >= 4;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            if (a_all3 < 2) {
                r->c = true;
                r->z = a_all3 == 2;
                r->n = (uint16_t)(a_all3 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret3) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        r->a = RAM16(0x00A9 + x_ret2);
        r->mf = false;
        r->xf = false;
        JSR(c, 0x6105, 0xC23A63); /* compare_target_axis_proximity_with_literal_early_return */
        uint16_t x_ret4 = r->x;
        bool carry_ret4 = r->c;
        if (carry_ret4) {
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all5 = r->a;
            uint16_t x_ret5 = r->x;
            if (a_all5 < 2) {
                r->c = true;
                r->z = a_all5 == 2;
                r->n = (uint16_t)(a_all5 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret5) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value5 = RAM16(0x0020 + x_ret4);
        if (value5 < 0x40) {
            r->a = value5;
            r->c = value5 >= 0x40;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all6 = r->a;
            uint16_t x_ret6 = r->x;
            if (a_all6 < 2) {
                r->c = true;
                r->z = a_all6 == 2;
                r->n = (uint16_t)(a_all6 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret6) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        if (value5 >= 0xC0) {
            r->a = value5;
            r->c = value5 >= 0xC0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all7 = r->a;
            uint16_t x_ret7 = r->x;
            if (a_all7 < 2) {
                r->c = true;
                r->z = a_all7 == 2;
                r->n = (uint16_t)(a_all7 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret7) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value8 = RAM16(0x0022 + x_ret4);
        if (value8 < 0x40) {
            r->a = value8;
            r->c = value8 >= 0x40;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all8 = r->a;
            uint16_t x_ret8 = r->x;
            if (a_all8 < 2) {
                r->c = true;
                r->z = a_all8 == 2;
                r->n = (uint16_t)(a_all8 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret8) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        if (value8 >= 0xA0) {
            r->a = value8;
            r->c = value8 >= 0xA0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all9 = r->a;
            uint16_t x_ret9 = r->x;
            if (a_all9 < 2) {
                r->c = true;
                r->z = a_all9 == 2;
                r->n = (uint16_t)(a_all9 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret9) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value11 = RAM16(0x00A9 + x_ret4);
        uint16_t value12 = RAM16(0x000B + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000));
        uint16_t value13 = RAM16(0x000B + x_ret4);
        if (value12 != value13) {
            r->a = value12;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000);
            r->c = value12 >= value13;
            r->v = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all10 = r->a;
            uint16_t x_ret10 = r->x;
            if (a_all10 < 2) {
                r->c = true;
                r->z = a_all10 == 2;
                r->n = (uint16_t)(a_all10 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret10) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value15 = RAM16(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000));
        if (value15 != 0) {
            r->a = value15;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000);
            r->c = value12 >= value13;
            r->v = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all11 = r->a;
            uint16_t x_ret11 = r->x;
            if (a_all11 < 2) {
                r->c = true;
                r->z = a_all11 == 2;
                r->n = (uint16_t)(a_all11 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret11) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value17 = RAM16(0x000E + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000));
        if (value17 != 0) {
            r->a = value17;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000);
            r->c = value12 >= value13;
            r->v = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all12 = r->a;
            uint16_t x_ret12 = r->x;
            if (a_all12 < 2) {
                r->c = true;
                r->z = a_all12 == 2;
                r->n = (uint16_t)(a_all12 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret12) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value19 = RAM16(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000));
        if (value19 == 0x24) {
            r->a = value19;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000);
            r->c = value19 >= 0x24;
            r->v = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all13 = r->a;
            uint16_t x_ret13 = r->x;
            if (a_all13 < 2) {
                r->c = true;
                r->z = a_all13 == 2;
                r->n = (uint16_t)(a_all13 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret13) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        RAM16_SET(0x007E + x_ret4, 2);
        uint16_t value21 = RAM16(0x00AB + x_ret4);
        uint16_t value22 = BUS16(c, 0xDCE29A + (uint16_t)(value21 << 1));
        r->a = value22;
        r->x = (uint16_t)(value21 << 1);
        r->y = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000);
        r->c = false;
        r->z = value22 == 0;
        r->n = value22 & 0x8000;
        r->v = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = false;
        r->xf = false;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->c = a_all2 >= 2;
    r->mf = false;
    r->xf = false;
    JSR(c, 0x60E3, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret14 = r->z;
    if (!zero_ret14) {
        uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
        r->a = RAM16(0x00A9 + current_object_dp02);
        r->x = current_object_dp02;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x60FA, 0xC208BC); /* derive_clamped_target_distance_minus_one */
        uint16_t a_all15 = r->a;
        uint16_t x_ret15 = r->x;
        if (a_all15 >= 4) {
            r->c = a_all15 >= 4;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all16 = r->a;
            uint16_t x_ret16 = r->x;
            if (a_all16 < 2) {
                r->c = true;
                r->z = a_all16 == 2;
                r->n = (uint16_t)(a_all16 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret16) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        r->a = RAM16(0x00A9 + x_ret15);
        r->mf = false;
        r->xf = false;
        JSR(c, 0x6105, 0xC23A63); /* compare_target_axis_proximity_with_literal_early_return */
        uint16_t x_ret17 = r->x;
        bool carry_ret17 = r->c;
        if (carry_ret17) {
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all18 = r->a;
            uint16_t x_ret18 = r->x;
            if (a_all18 < 2) {
                r->c = true;
                r->z = a_all18 == 2;
                r->n = (uint16_t)(a_all18 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret18) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value27 = RAM16(0x0020 + x_ret17);
        if (value27 < 0x40) {
            r->a = value27;
            r->c = value27 >= 0x40;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all19 = r->a;
            uint16_t x_ret19 = r->x;
            if (a_all19 < 2) {
                r->c = true;
                r->z = a_all19 == 2;
                r->n = (uint16_t)(a_all19 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret19) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        if (value27 >= 0xC0) {
            r->a = value27;
            r->c = value27 >= 0xC0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all20 = r->a;
            uint16_t x_ret20 = r->x;
            if (a_all20 < 2) {
                r->c = true;
                r->z = a_all20 == 2;
                r->n = (uint16_t)(a_all20 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret20) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value30 = RAM16(0x0022 + x_ret17);
        if (value30 < 0x40) {
            r->a = value30;
            r->c = value30 >= 0x40;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all21 = r->a;
            uint16_t x_ret21 = r->x;
            if (a_all21 < 2) {
                r->c = true;
                r->z = a_all21 == 2;
                r->n = (uint16_t)(a_all21 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret21) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        if (value30 >= 0xA0) {
            r->a = value30;
            r->c = value30 >= 0xA0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all22 = r->a;
            uint16_t x_ret22 = r->x;
            if (a_all22 < 2) {
                r->c = true;
                r->z = a_all22 == 2;
                r->n = (uint16_t)(a_all22 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret22) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value33 = RAM16(0x00A9 + x_ret17);
        uint16_t value34 = RAM16(0x000B + (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000));
        uint16_t value35 = RAM16(0x000B + x_ret17);
        if (value34 != value35) {
            r->a = value34;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000);
            r->c = value34 >= value35;
            r->v = (((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all23 = r->a;
            uint16_t x_ret23 = r->x;
            if (a_all23 < 2) {
                r->c = true;
                r->z = a_all23 == 2;
                r->n = (uint16_t)(a_all23 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret23) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value37 = RAM16(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000));
        if (value37 != 0) {
            r->a = value37;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000);
            r->c = value34 >= value35;
            r->v = (((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all24 = r->a;
            uint16_t x_ret24 = r->x;
            if (a_all24 < 2) {
                r->c = true;
                r->z = a_all24 == 2;
                r->n = (uint16_t)(a_all24 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret24) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value39 = RAM16(0x000E + (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000));
        if (value39 != 0) {
            r->a = value39;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000);
            r->c = value34 >= value35;
            r->v = (((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all25 = r->a;
            uint16_t x_ret25 = r->x;
            if (a_all25 < 2) {
                r->c = true;
                r->z = a_all25 == 2;
                r->n = (uint16_t)(a_all25 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret25) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        uint16_t value41 = RAM16(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000));
        if (value41 == 0x24) {
            r->a = value41;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000);
            r->c = value41 >= 0x24;
            r->v = (((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->mf = false;
            r->xf = false;
            JSR(c, 0x6159, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
            uint16_t a_all26 = r->a;
            uint16_t x_ret26 = r->x;
            if (a_all26 < 2) {
                r->c = true;
                r->z = a_all26 == 2;
                r->n = (uint16_t)(a_all26 - 2) & 0x8000;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            if (RAM16(0x0042 + x_ret26) != 0) {
                r->a = 0xDD92;
                r->c = false;
                r->z = false;
                r->n = true;
                r->mf = false;
                r->xf = false;
                RETURN_RTS(c);
            }
            r->a = 0xDD84;
            r->c = false;
            r->z = false;
            r->n = true;
            r->mf = false;
            r->xf = false;
            RETURN_RTS(c);
        }
        RAM16_SET(0x007E + x_ret17, 2);
        uint16_t value43 = RAM16(0x00AB + x_ret17);
        uint16_t value44 = BUS16(c, 0xDCE29A + (uint16_t)(value43 << 1));
        r->a = value44;
        r->x = (uint16_t)(value43 << 1);
        r->y = (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000);
        r->c = false;
        r->z = value44 == 0;
        r->n = value44 & 0x8000;
        r->v = (((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value33 << 8) | (value33 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = false;
        r->xf = false;
        RETURN_RTS(c);
    }
    uint16_t value45 = RAM16(0x00AB + RAM16(CURRENT_OBJECT_DP0 + dp));
    uint16_t value46 = BUS16(c, 0xDCE27A + (uint16_t)(value45 << 1));
    r->a = value46;
    r->x = (uint16_t)(value45 << 1);
    r->c = false;
    r->z = value46 == 0;
    r->n = value46 & 0x8000;
    r->mf = false;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC260CE, SOM_RTS, "hand", choose_descriptor_five_target_hold_or_hp_fallback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 162, 71)
