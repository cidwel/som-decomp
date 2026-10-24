#include "som_c.h"

/* C20006 boss_selected_object_emission_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/boss_selected_object_emission_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXC.
 */
static void boss_selected_object_emission_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC2023A, SOM_RTL); /* emit_selected_boss_object_with_saved_context */
}
SOM_REGISTER(0xC20006, SOM_RTL, "gen", boss_selected_object_emission_public_jump, 0, L_A | L_B | L_X | L_C, 1, 0, 0, 3, 1)
