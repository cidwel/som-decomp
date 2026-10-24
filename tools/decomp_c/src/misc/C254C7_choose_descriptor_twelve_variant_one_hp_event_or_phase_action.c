#include "som_c.h"

/* C254C7 choose_descriptor_twelve_variant_one_hp_event_or_phase_action   [class B, 166 bytes, 72 instructions]
 * Source: src/rom/choose_descriptor_twelve_variant_one_hp_event_or_phase_action.s
 * Documented in docs/boss-descriptor-twelve.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_twelve_variant_one_hp_event_or_phase_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00BE + value);
    if (value2 != 0) {
        if (RAM16(0x007E + value) != 0) {
            r->a = 2;
            r->x = value;
            JSR(c, 0x5542, 0xC2300B); /* draw_boss_frame_random_number */
            bool zero_ret = r->z;
            if (zero_ret) {
                uint16_t value4 = RAM16(0x0287);
                RAM16_SET(0x0034 + value4, RAM16(0x0034 + value4) & 0xFF0F);
                r->a = 0xDB48;
                r->x = value4;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value6 = RAM16(0x0287);
            uint16_t value7 = RAM16(0x0034 + value6);
            if ((value7 & 0x60) != 0) {
                RAM16_SET(0x0034 + value6, value7 & 0xFF0F);
                r->a = 0xDB48;
                r->x = value6;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 2;
            r->x = value6;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5554, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all2 = r->a;
            uint16_t value8 = BUS16(c, 0xDCE274 + (uint16_t)(a_all2 << 1));
            r->a = value8;
            r->x = (uint16_t)(a_all2 << 1);
            r->c = 0;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 3;
        r->x = value;
        JSR(c, 0x54EF, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret3 = r->z;
        if (!zero_ret3) {
            uint16_t value9 = RAM16(0x0287);
            r->a = RAM16(0x00A9 + value9);
            r->x = value9;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5512, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
            uint16_t a_all4 = r->a;
            if (a_all4 >= 3) {
                r->a = 1;
                r->c = a_all4 >= 3;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5534, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all5 = r->a;
                uint16_t value11 = BUS16(c, 0xDCE26C + (uint16_t)(a_all5 << 1));
                r->a = value11;
                r->x = (uint16_t)(a_all5 << 1);
                r->c = 0;
                r->z = value11 == 0;
                r->n = value11 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = RAM16(0x00A9 + RAM16(0x0287));
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x551F, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
            uint16_t a_all6 = r->a;
            if (a_all6 < 3) {
                r->a = 0xDB26;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (a_all6 < 7) {
                r->a = 1;
                r->c = a_all6 >= 7;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5534, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all7 = r->a;
                uint16_t value14 = BUS16(c, 0xDCE26C + (uint16_t)(a_all7 << 1));
                r->a = value14;
                r->x = (uint16_t)(a_all7 << 1);
                r->c = 0;
                r->z = value14 == 0;
                r->n = value14 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xDB26;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value15 = RAM16(0x0287);
        RAM16_SET(0x0034 + value15, RAM16(0x0034 + value15) & 0xFF0F);
        r->a = 1;
        r->x = value15;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5502, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all8 = r->a;
        uint16_t value17 = BUS16(c, 0xDCE270 + (uint16_t)(a_all8 << 1));
        r->a = value17;
        r->x = (uint16_t)(a_all8 << 1);
        r->c = 0;
        r->z = value17 == 0;
        r->n = value17 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value2;
    JSR(c, 0x54D0, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
    uint16_t a_all9 = r->a;
    uint16_t value18 = RAM16(0x0287);
    if (a_all9 < 3) {
        if (RAM16(0x007E + value18) != 0) {
            r->a = 2;
            r->x = value18;
            r->c = a_all9 >= 3;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5542, 0xC2300B); /* draw_boss_frame_random_number */
            bool zero_ret10 = r->z;
            if (zero_ret10) {
                uint16_t value20 = RAM16(0x0287);
                RAM16_SET(0x0034 + value20, RAM16(0x0034 + value20) & 0xFF0F);
                r->a = 0xDB48;
                r->x = value20;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value22 = RAM16(0x0287);
            uint16_t value23 = RAM16(0x0034 + value22);
            if ((value23 & 0x60) != 0) {
                RAM16_SET(0x0034 + value22, value23 & 0xFF0F);
                r->a = 0xDB48;
                r->x = value22;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 2;
            r->x = value22;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5554, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all11 = r->a;
            uint16_t value24 = BUS16(c, 0xDCE274 + (uint16_t)(a_all11 << 1));
            r->a = value24;
            r->x = (uint16_t)(a_all11 << 1);
            r->c = 0;
            r->z = value24 == 0;
            r->n = value24 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 3;
        r->x = value18;
        r->c = a_all9 >= 3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x54EF, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret12 = r->z;
        if (!zero_ret12) {
            uint16_t value25 = RAM16(0x0287);
            r->a = RAM16(0x00A9 + value25);
            r->x = value25;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x5512, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
            uint16_t a_all13 = r->a;
            if (a_all13 >= 3) {
                r->a = 1;
                r->c = a_all13 >= 3;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5534, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all14 = r->a;
                uint16_t value27 = BUS16(c, 0xDCE26C + (uint16_t)(a_all14 << 1));
                r->a = value27;
                r->x = (uint16_t)(a_all14 << 1);
                r->c = 0;
                r->z = value27 == 0;
                r->n = value27 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = RAM16(0x00A9 + RAM16(0x0287));
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x551F, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
            uint16_t a_all15 = r->a;
            if (a_all15 < 3) {
                r->a = 0xDB26;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (a_all15 < 7) {
                r->a = 1;
                r->c = a_all15 >= 7;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x5534, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all16 = r->a;
                uint16_t value30 = BUS16(c, 0xDCE26C + (uint16_t)(a_all16 << 1));
                r->a = value30;
                r->x = (uint16_t)(a_all16 << 1);
                r->c = 0;
                r->z = value30 == 0;
                r->n = value30 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xDB26;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value31 = RAM16(0x0287);
        RAM16_SET(0x0034 + value31, RAM16(0x0034 + value31) & 0xFF0F);
        r->a = 1;
        r->x = value31;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5502, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all17 = r->a;
        uint16_t value33 = BUS16(c, 0xDCE270 + (uint16_t)(a_all17 << 1));
        r->a = value33;
        r->x = (uint16_t)(a_all17 << 1);
        r->c = 0;
        r->z = value33 == 0;
        r->n = value33 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x00BE + value18, 1);
    r->a = 0xDB38;
    r->x = value18;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC254C7, SOM_RTS, "gen", choose_descriptor_twelve_variant_one_hp_event_or_phase_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 166, 72)
