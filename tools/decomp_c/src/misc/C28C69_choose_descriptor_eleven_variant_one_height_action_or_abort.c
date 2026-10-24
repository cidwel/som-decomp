#include "som_c.h"

/* C28C69 choose_descriptor_eleven_variant_one_height_action_or_abort   [class B, 72 bytes, 33 instructions]
 * Source: src/rom/choose_descriptor_eleven_variant_one_height_action_or_abort.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eleven_variant_one_height_action_or_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8C6D, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8C73, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 >= 4) {
        r->c = 1;
        r->z = a_all2 == 4;
        r->n = (uint16_t)(a_all2 - 4) & 0x8000;
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
        JSR(c, 0x8CA6, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t value4 = BUS16(c, 0xDCE5CB + (uint16_t)(a_all3 << 1));
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
        JSR(c, 0x8CA6, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all4 = r->a;
        uint16_t value5 = BUS16(c, 0xDCE5CB + (uint16_t)(a_all4 << 1));
        r->a = value5;
        r->x = (uint16_t)(a_all4 << 1);
        r->c = 0;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x0066 + x_ret2);
    if (value6 >= 0x80) {
        r->a = 0xF052;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->c = value6 >= 0x80;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8C93, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all5 = r->a;
    uint16_t value7 = BUS16(c, 0xDCE5D7 + (uint16_t)(a_all5 << 1));
    r->a = value7;
    r->x = (uint16_t)(a_all5 << 1);
    r->c = 0;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28C69, SOM_RTS, "gen", choose_descriptor_eleven_variant_one_height_action_or_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 72, 33)
