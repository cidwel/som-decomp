#include "som_c.h"

/* C24235 choose_descriptor_six_phase_action_or_random_abort   [class B, 158 bytes, 74 instructions]
 * Source: src/rom/choose_descriptor_six_phase_action_or_random_abort.s
 * Documented in docs/boss-descriptor-six.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_six_phase_action_or_random_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    if (value != 0) {
        r->a = value;
        JSR(c, 0x428B, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
        uint16_t x_ret = r->x;
        r->a = RAM16(0x00A9 + x_ret);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4291, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all2 = r->a;
        if (a_all2 < 4) {
            r->a = 2;
            r->c = a_all2 >= 4;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x42AB, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all3 = r->a;
            uint16_t value3 = RAM16(0x0287);
            if ((a_all3 & 0xFF) != 0) {
                if ((a_all3 & 0xFF) != 1) {
                    r->a = 0xD4CD;
                    r->x = value3;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value4 = RAM16(0x00AB + value3);
                uint16_t value5 = BUS16(c, 0xDCE15E + (uint16_t)(value4 << 1));
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
            uint16_t value7 = BUS16(c, 0xDCE156 + (uint16_t)(value6 << 1));
            r->a = value7;
            r->x = (uint16_t)(value6 << 1);
            r->c = 0;
            r->z = value7 == 0;
            r->n = value7 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0;
        r->c = a_all2 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x429C, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret4 = r->z;
        if (!zero_ret4) {
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD4CB;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x423C, 0xC23FB5); /* request_descriptor_two_half_hp_phase_and_height */
    bool carry_ret5 = r->c;
    if (carry_ret5) {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x428B, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
        uint16_t x_ret5 = r->x;
        r->a = RAM16(0x00A9 + x_ret5);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4291, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all7 = r->a;
        if (a_all7 < 4) {
            r->a = 2;
            r->c = a_all7 >= 4;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x42AB, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all8 = r->a;
            uint16_t value9 = RAM16(0x0287);
            if ((a_all8 & 0xFF) != 0) {
                if ((a_all8 & 0xFF) != 1) {
                    r->a = 0xD4CD;
                    r->x = value9;
                    r->c = 0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value10 = RAM16(0x00AB + value9);
                uint16_t value11 = BUS16(c, 0xDCE15E + (uint16_t)(value10 << 1));
                r->a = value11;
                r->x = (uint16_t)(value10 << 1);
                r->c = 0;
                r->z = value11 == 0;
                r->n = value11 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value12 = RAM16(0x00AB + value9);
            uint16_t value13 = BUS16(c, 0xDCE156 + (uint16_t)(value12 << 1));
            r->a = value13;
            r->x = (uint16_t)(value12 << 1);
            r->c = 0;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0;
        r->c = a_all7 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x429C, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret9 = r->z;
        if (!zero_ret9) {
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD4CB;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4241, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret9 = r->x;
    r->a = RAM16(0x00A9 + x_ret9);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4247, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all11 = r->a;
    if (a_all11 < 4) {
        r->a = 2;
        r->c = a_all11 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4261, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all12 = r->a;
        uint16_t value15 = RAM16(0x0287);
        if ((a_all12 & 0xFF) != 0) {
            if ((a_all12 & 0xFF) != 1) {
                r->a = 0xD4B5;
                r->x = value15;
                r->c = 0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value16 = RAM16(0x00AB + value15);
            uint16_t value17 = BUS16(c, 0xDCE14E + (uint16_t)(value16 << 1));
            r->a = value17;
            r->x = (uint16_t)(value16 << 1);
            r->c = 0;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value18 = RAM16(0x00AB + value15);
        uint16_t value19 = BUS16(c, 0xDCE146 + (uint16_t)(value18 << 1));
        r->a = value19;
        r->x = (uint16_t)(value18 << 1);
        r->c = 0;
        r->z = value19 == 0;
        r->n = value19 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0;
    r->c = a_all11 >= 4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4252, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret13 = r->z;
    if (!zero_ret13) {
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD4B3;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24235, SOM_RTS, "gen", choose_descriptor_six_phase_action_or_random_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 158, 74)
