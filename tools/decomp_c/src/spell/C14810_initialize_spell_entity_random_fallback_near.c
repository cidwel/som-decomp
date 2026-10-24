#include "som_c.h"

/* C14810 initialize_spell_entity_random_fallback_near   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_random_fallback_near.s
 * Documented in docs/actor-entity-initializer-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_random_fallback_near(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4813, 0xD3FD3F); GUARD_JSL(c, sp_call, 0x4813); } /* initialize_spell_random_fallback_long */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14810, SOM_RTS, "gen", initialize_spell_entity_random_fallback_near, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
