#include "som_c.h"

/* C2ACA8 publish_native_visual_effect_point_trail_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/publish_native_visual_effect_point_trail_long.s
 * Documented in docs/actor-visual-effect-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void publish_native_visual_effect_point_trail_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xACAA, 0xC2ACAC); /* append_or_retire_native_visual_effect_trail_points */
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2ACA8, SOM_RTL, "gen", publish_native_visual_effect_point_trail_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
