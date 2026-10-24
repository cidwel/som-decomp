#include "som_c.h"

/* C2000C boss_alternating_object_emission_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/boss_alternating_object_emission_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void boss_alternating_object_emission_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC20250, SOM_RTL); /* emit_alternating_boss_objects_with_saved_context */
}
SOM_REGISTER(0xC2000C, SOM_RTL, "gen", boss_alternating_object_emission_public_jump, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
