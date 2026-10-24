#include "som_c.h"

/* C26DFB choose_descriptor_eight_state_from_phase_bits_direction_and_rng   [class B, 135 bytes, 60 instructions]
 * Source: src/rom/choose_descriptor_eight_state_from_phase_bits_direction_and_rng.s
 * Documented in docs/boss-descriptor-eight.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eight_state_from_phase_bits_direction_and_rng(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    if ((value & 1) != 0) {
        r->a = value;
        JSR(c, 0x6E37, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
        uint16_t x_ret = r->x;
        if ((RAM16(0x007E + x_ret) & 0x8000) != 0) {
            uint16_t value5 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value6 = BUS16(c, 0xDCE481 + (uint16_t)(value5 << 1));
            if (value6 == 0) {
                r->a = 1;
                r->x = (uint16_t)(value5 << 1);
                r->c = value5 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x6E7A, 0xC2300B); /* draw_boss_frame_random_number */
                uint16_t a_all2 = r->a;
                uint16_t value7 = BUS16(c, 0xDCE475 + (uint16_t)(a_all2 << 1));
                r->a = value7;
                r->x = (uint16_t)(a_all2 << 1);
                r->c = a_all2 & 0x8000;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = value6;
            r->x = (uint16_t)(value5 << 1);
            r->c = value5 & 0x8000;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6E45, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret3 = r->z;
        if (zero_ret3) {
            r->a = 0xE860;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value9 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value10 = BUS16(c, 0xDCE479 + (uint16_t)(value9 << 1));
        if (value10 == 0) {
            r->a = 1;
            r->x = (uint16_t)(value9 << 1);
            r->c = value9 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x6E5B, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all4 = r->a;
            uint16_t value11 = BUS16(c, 0xDCE471 + (uint16_t)(a_all4 << 1));
            r->a = value11;
            r->x = (uint16_t)(a_all4 << 1);
            r->c = a_all4 & 0x8000;
            r->z = value11 == 0;
            r->n = value11 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = value10;
        r->x = (uint16_t)(value9 << 1);
        r->c = value9 & 0x8000;
        r->z = value10 == 0;
        r->n = value10 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 4;
    JSR(c, 0x6E08, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret5 = r->z;
    if (zero_ret5) {
        r->a = 0xE85C;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6E0F, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret6 = r->x;
    r->a = RAM16(0x00A9 + x_ret6);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6E15, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all7 = r->a;
    uint16_t x_ret7 = r->x;
    if (a_all7 >= 8) {
        uint16_t value14 = RAM16(0x00AB + x_ret7);
        uint16_t value15 = BUS16(c, 0xDCE469 + (uint16_t)(value14 << 1));
        r->a = value15;
        r->x = (uint16_t)(value14 << 1);
        r->c = value14 & 0x8000;
        r->z = value15 == 0;
        r->n = value15 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value16 = RAM16(0x00AB + x_ret7);
    uint16_t value17 = BUS16(c, 0xDCE461 + (uint16_t)(value16 << 1));
    r->a = value17;
    r->x = (uint16_t)(value16 << 1);
    r->c = value16 & 0x8000;
    r->z = value17 == 0;
    r->n = value17 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26DFB, SOM_RTS, "gen", choose_descriptor_eight_state_from_phase_bits_direction_and_rng, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 135, 60)
