#include "som_c.h"

/* C23DDB choose_descriptor_zero_variant_one_action   [class B, 75 bytes, 35 instructions]
 * Source: src/rom/choose_descriptor_zero_variant_one_action.s
 * Documented in docs/boss-descriptor-zero.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_zero_variant_one_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3DDF, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3DE5, 0xC208BC); /* derive_clamped_target_distance_minus_one */
    uint16_t a_all2 = r->a;
    if (a_all2 < 3) {
        if (a_all2 < 2) {
            uint16_t value4 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value5 = BUS16(c, 0xDCE010 + (uint16_t)(value4 << 1));
            r->a = value5;
            r->x = (uint16_t)(value4 << 1);
            r->c = 0;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 1;
        r->c = a_all2 >= 2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3E10, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t value6 = BUS16(c, 0xDCE024 + (uint16_t)(a_all3 << 1));
        r->a = value6;
        r->x = (uint16_t)(a_all3 << 1);
        r->c = 0;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->c = a_all2 >= 3;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3DF0, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret4 = r->z;
    if (zero_ret4) {
        r->a = 1;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3DFD, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all5 = r->a;
        uint16_t value7 = BUS16(c, 0xDCE020 + (uint16_t)(a_all5 << 1));
        r->a = value7;
        r->x = (uint16_t)(a_all5 << 1);
        r->c = 0;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD0BA;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23DDB, SOM_RTS, "gen", choose_descriptor_zero_variant_one_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 75, 35)
