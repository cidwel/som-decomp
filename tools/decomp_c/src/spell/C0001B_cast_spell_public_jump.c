#include "som_c.h"

/* C0001B cast_spell_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/cast_spell_public_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void cast_spell_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03803, SOM_RTL); /* cast_spell_public_jump_mirror */
}
SOM_REGISTER(0xC0001B, SOM_RTL, "gen", cast_spell_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
