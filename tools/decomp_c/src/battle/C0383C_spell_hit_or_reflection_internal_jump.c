#include "som_c.h"

/* C0383C spell_hit_or_reflection_internal_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/spell_hit_or_reflection_internal_jump.s
 * Documented in docs/actor-cast-spell-reflection.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXCV.
 */
static void spell_hit_or_reflection_internal_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03866, SOM_RTL); /* spell_hit_or_reflection_native_long_jump */
}
SOM_REGISTER(0xC0383C, SOM_RTL, "gen", spell_hit_or_reflection_internal_jump, 0, L_A | L_B | L_X | L_C | L_V, 1, 0, 0, 3, 1)
