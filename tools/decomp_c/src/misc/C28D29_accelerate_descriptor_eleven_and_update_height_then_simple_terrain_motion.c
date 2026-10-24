#include "som_c.h"

/* C28D29 accelerate_descriptor_eleven_and_update_height_then_simple_terrain_motion   [class B, 25 bytes, 10 instructions]
 * Source: src/rom/accelerate_descriptor_eleven_and_update_height_then_simple_terrain_motion.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void accelerate_descriptor_eleven_and_update_height_then_simple_terrain_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x021A, 2);
    RAM16_SET(0x020D, 0xDC00);
    RAM16_SET(0x020C, 0xE5DB);
    r->a = 0xE5DB;
    JSR(c, 0x8D3A, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8D3D, 0xC28CFB); /* advance_descriptor_eleven_sine_height_with_fractional_carry */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8D40, 0xC23F4C); /* move_projectile_by_velocity_and_prepare_terrain */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28D29, SOM_RTS, "gen", accelerate_descriptor_eleven_and_update_height_then_simple_terrain_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 25, 10)
