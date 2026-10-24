#include "som_c.h"

/* C00063 jump_native_spell_skill_percentage_api   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_native_spell_skill_percentage_api.s
 * Documented in docs/actor-spell-skill-percentage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABCV.
 */
static void jump_native_spell_skill_percentage_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0384B, SOM_RTL); /* jump_native_spell_skill_percentage_query */
}
SOM_REGISTER(0xC00063, SOM_RTL, "gen", jump_native_spell_skill_percentage_api, 0, L_A | L_B | L_C | L_V, 1, 1, 0, 3, 1)
