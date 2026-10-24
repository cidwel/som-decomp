#include "som_c.h"

/* C2560B set_boss_target_velocity_to_speed_twelve   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/set_boss_target_velocity_to_speed_twelve.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_boss_target_velocity_to_speed_twelve(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x0C;
    JSR(c, 0x5610, 0xC23313); /* derive_boss_target_velocity_from_normalized_displacement */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2560B, SOM_RTS, "gen", set_boss_target_velocity_to_speed_twelve, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
