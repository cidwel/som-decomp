#include "som_c.h"

/* C23FD9 choose_descriptor_two_phase_action_or_random_abort   [class B, 170 bytes, 80 instructions]
 * Source: src/rom/choose_descriptor_two_phase_action_or_random_abort.s
 * Documented in docs/boss-descriptor-two.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_two_phase_action_or_random_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    if (value != 0) {
        r->a = value;
        JSR(c, 0x4035, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
        uint16_t x_ret = r->x;
        r->a = RAM16(0x00A9 + x_ret);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x403B, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all2 = r->a;
        if (a_all2 < 4) {
            r->a = 2;
            r->c = a_all2 >= 4;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4055, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all3 = r->a;
            uint16_t value3 = RAM16(0x0287);
            if ((a_all3 & 0xFF) != 0) {
                if ((a_all3 & 0xFF) != 1) {
                    uint16_t value4 = RAM16(0x00AB + value3);
                    uint16_t value5 = BUS16(c, 0xDCE0A0 + (uint16_t)(value4 << 1));
                    r->a = value5;
                    r->x = (uint16_t)(value4 << 1);
                    r->c = 0;
                    r->z = value5 == 0;
                    r->n = value5 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value6 = RAM16(0x00AB + value3);
                uint16_t value7 = BUS16(c, 0xDCE098 + (uint16_t)(value6 << 1));
                r->a = value7;
                r->x = (uint16_t)(value6 << 1);
                r->c = 0;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value8 = RAM16(0x00AB + value3);
            uint16_t value9 = BUS16(c, 0xDCE090 + (uint16_t)(value8 << 1));
            r->a = value9;
            r->x = (uint16_t)(value8 << 1);
            r->c = 0;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0;
        r->c = a_all2 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4046, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret4 = r->z;
        if (!zero_ret4) {
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD270;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x3FE0, 0xC23FB5); /* request_descriptor_two_half_hp_phase_and_height */
    bool carry_ret5 = r->c;
    if (carry_ret5) {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4035, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
        uint16_t x_ret5 = r->x;
        r->a = RAM16(0x00A9 + x_ret5);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x403B, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all7 = r->a;
        if (a_all7 < 4) {
            r->a = 2;
            r->c = a_all7 >= 4;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4055, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all8 = r->a;
            uint16_t value11 = RAM16(0x0287);
            if ((a_all8 & 0xFF) != 0) {
                if ((a_all8 & 0xFF) != 1) {
                    uint16_t value12 = RAM16(0x00AB + value11);
                    uint16_t value13 = BUS16(c, 0xDCE0A0 + (uint16_t)(value12 << 1));
                    r->a = value13;
                    r->x = (uint16_t)(value12 << 1);
                    r->c = 0;
                    r->z = value13 == 0;
                    r->n = value13 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value14 = RAM16(0x00AB + value11);
                uint16_t value15 = BUS16(c, 0xDCE098 + (uint16_t)(value14 << 1));
                r->a = value15;
                r->x = (uint16_t)(value14 << 1);
                r->c = 0;
                r->z = value15 == 0;
                r->n = value15 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value16 = RAM16(0x00AB + value11);
            uint16_t value17 = BUS16(c, 0xDCE090 + (uint16_t)(value16 << 1));
            r->a = value17;
            r->x = (uint16_t)(value16 << 1);
            r->c = 0;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0;
        r->c = a_all7 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4046, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret9 = r->z;
        if (!zero_ret9) {
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD270;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3FE5, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret9 = r->x;
    r->a = RAM16(0x00A9 + x_ret9);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3FEB, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all11 = r->a;
    if (a_all11 < 4) {
        r->a = 2;
        r->c = a_all11 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4005, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all12 = r->a;
        uint16_t value19 = RAM16(0x0287);
        if ((a_all12 & 0xFF) != 0) {
            if ((a_all12 & 0xFF) != 1) {
                uint16_t value20 = RAM16(0x00AB + value19);
                uint16_t value21 = BUS16(c, 0xDCE088 + (uint16_t)(value20 << 1));
                r->a = value21;
                r->x = (uint16_t)(value20 << 1);
                r->c = 0;
                r->z = value21 == 0;
                r->n = value21 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value22 = RAM16(0x00AB + value19);
            uint16_t value23 = BUS16(c, 0xDCE080 + (uint16_t)(value22 << 1));
            r->a = value23;
            r->x = (uint16_t)(value22 << 1);
            r->c = 0;
            r->z = value23 == 0;
            r->n = value23 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value24 = RAM16(0x00AB + value19);
        uint16_t value25 = BUS16(c, 0xDCE078 + (uint16_t)(value24 << 1));
        r->a = value25;
        r->x = (uint16_t)(value24 << 1);
        r->c = 0;
        r->z = value25 == 0;
        r->n = value25 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0;
    r->c = a_all11 >= 4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3FF6, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret13 = r->z;
    if (!zero_ret13) {
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD25C;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23FD9, SOM_RTS, "gen", choose_descriptor_two_phase_action_or_random_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 170, 80)
