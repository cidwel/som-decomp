#include "som_c.h"

/* C28C2E choose_descriptor_eleven_variant_zero_action_or_distance_abort   [class B, 59 bytes, 27 instructions]
 * Source: src/rom/choose_descriptor_eleven_variant_zero_action_or_distance_abort.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eleven_variant_zero_action_or_distance_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8C32, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8C38, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 >= 6) {
        r->c = 1;
        r->z = a_all2 == 6;
        r->n = (uint16_t)(a_all2 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x00AB + x_ret2);
    if (value3 < 1) {
        r->a = 2;
        r->c = value3 >= 1;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8C5E, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t value4 = BUS16(c, 0xDCE5C5 + (uint16_t)(a_all3 << 1));
        r->a = value4;
        r->x = (uint16_t)(a_all3 << 1);
        r->c = 0;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (value3 >= 4) {
        r->a = 2;
        r->c = value3 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x8C5E, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all4 = r->a;
        uint16_t value5 = BUS16(c, 0xDCE5C5 + (uint16_t)(a_all4 << 1));
        r->a = value5;
        r->x = (uint16_t)(a_all4 << 1);
        r->c = 0;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->c = value3 >= 4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8C50, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all5 = r->a;
    uint16_t value6 = BUS16(c, 0xDCE5D7 + (uint16_t)(a_all5 << 1));
    r->a = value6;
    r->x = (uint16_t)(a_all5 << 1);
    r->c = 0;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28C2E, SOM_RTS, "gen", choose_descriptor_eleven_variant_zero_action_or_distance_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 59, 27)
