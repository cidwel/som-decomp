#include "som_c.h"

/* C263AC steer_native_boss_toward_nearest_target_with_capped_acceleration   [class B, 40 bytes, 16 instructions]
 * Source: src/rom/steer_native_boss_toward_nearest_target_with_capped_acceleration.s
 * Documented in docs/boss-native-target-steering.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void steer_native_boss_toward_nearest_target_with_capped_acceleration(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x63AE, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x63B6, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    uint16_t value2 = RAM16(0x0287);
    RAM16_SET(0x00AB + value2, a_all2);
    RAM16_SET(0x021A, 4);
    RAM16_SET(0x020D, 0xDC00);
    RAM16_SET(0x020C, 0xE2F3);
    r->a = 0xE2F3;
    r->x = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x63CD, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
    r->a = RAM16(0x02C5);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x63D2, 0xC20A47); /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC263AC, SOM_RTS, "gen", steer_native_boss_toward_nearest_target_with_capped_acceleration, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 40, 16)
