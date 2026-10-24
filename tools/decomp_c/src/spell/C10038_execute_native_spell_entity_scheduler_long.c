#include "som_c.h"

/* C10038 execute_native_spell_entity_scheduler_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/execute_native_spell_entity_scheduler_long.s
 * Documented in docs/actor-cast-entity-engine.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void execute_native_spell_entity_scheduler_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x003A, 0xC13B3C); /* execute_native_spell_entity_scheduler */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10038, SOM_RTL, "gen", execute_native_spell_entity_scheduler_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
