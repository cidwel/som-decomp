#include "som_c.h"

/* C12ED9 append_spell_entity_transient_register_record_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/append_spell_entity_transient_register_record_long.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void append_spell_entity_transient_register_record_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EDB, 0xC14514); GUARD_JSR(c, sp_call, 0x2EDB); } /* append_spell_entity_transient_register_record */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12ED9, SOM_RTL, "gen", append_spell_entity_transient_register_record_long, 0, 0, 1, 1, 0, 4, 2)
