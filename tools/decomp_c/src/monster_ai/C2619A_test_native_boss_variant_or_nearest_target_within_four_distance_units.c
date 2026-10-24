#include "som_c.h"

/* C2619A test_native_boss_variant_or_nearest_target_within_four_distance_units   [class B, 23 bytes, 11 instructions]
 * Source: src/rom/test_native_boss_variant_or_nearest_target_within_four_distance_units.s
 * Documented in docs/boss-native-target-steering.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void test_native_boss_variant_or_nearest_target_within_four_distance_units(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0042 + x);
    if (value != 0) {
        r->a = value;
        r->c = 1;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x61A1, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x61A7, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    if (a_all2 < 4) {
        r->c = 1;
        r->z = a_all2 == 4;
        r->n = (uint16_t)(a_all2 - 4) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->c = 0;
    r->z = a_all2 == 4;
    r->n = (uint16_t)(a_all2 - 4) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2619A, SOM_RTS, "gen", test_native_boss_variant_or_nearest_target_within_four_distance_units, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 11)
