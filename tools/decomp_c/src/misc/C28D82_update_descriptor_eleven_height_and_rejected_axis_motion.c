#include "som_c.h"

/* C28D82 update_descriptor_eleven_height_and_rejected_axis_motion   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/update_descriptor_eleven_height_and_rejected_axis_motion.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void update_descriptor_eleven_height_and_rejected_axis_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8D84, 0xC28CFB); /* advance_descriptor_eleven_sine_height_with_fractional_carry */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8D87, 0xC236FF); /* move_boss_fractional_axes_with_terrain_party_rejection_and_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28D82, SOM_RTS, "gen", update_descriptor_eleven_height_and_rejected_axis_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
