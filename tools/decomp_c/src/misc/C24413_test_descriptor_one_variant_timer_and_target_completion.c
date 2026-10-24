#include "som_c.h"

/* C24413 test_descriptor_one_variant_timer_and_target_completion   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/test_descriptor_one_variant_timer_and_target_completion.s
 * Documented in docs/boss-mutable-descriptor-dispatch.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void test_descriptor_one_variant_timer_and_target_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0042 + x);
    if (value == 0) {
        r->a = value;
        r->c = 1;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(OBJECT_AGE + x);
    if (value2 < 0x18) {
        r->a = value2;
        r->c = 0;
        r->z = value2 == 0x18;
        r->n = (uint16_t)(value2 - 0x18) & 0x8000;
        RETURN_RTS(c);
    }
    if (value2 >= 0x3C) {
        r->a = value2;
        r->c = 1;
        r->z = value2 == 0x3C;
        r->n = (uint16_t)(value2 - 0x3C) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->c = value2 >= 0x3C;
    JSR(c, 0x4427, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x442D, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    if (a_all2 >= 5) {
        r->c = 0;
        r->z = a_all2 == 5;
        r->n = (uint16_t)(a_all2 - 5) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->c = 1;
    r->z = a_all2 == 5;
    r->n = (uint16_t)(a_all2 - 5) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24413, SOM_RTS, "gen", test_descriptor_one_variant_timer_and_target_completion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 36, 16)
