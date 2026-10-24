#include "som_c.h"

/* C12E7C release_spell_entity_heap_bank_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_spell_entity_heap_bank_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void release_spell_entity_heap_bank_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E7E, 0xC13D7D); GUARD_JSR(c, sp_call, 0x2E7E); } /* release_spell_entity_heap_with_saved_bank */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E7C, SOM_RTL, "gen", release_spell_entity_heap_bank_long, 0, 0, 1, -1, 0, 4, 2)
