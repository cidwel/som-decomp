#include "som_c.h"

/* C136B3 spell_entity_resource_noop   [class A, 9 bytes, 7 instructions]
 * Source: src/rom/spell_entity_resource_noop.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void spell_entity_resource_noop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC136B3, SOM_RTS, "gen", spell_entity_resource_noop, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 9, 7)
