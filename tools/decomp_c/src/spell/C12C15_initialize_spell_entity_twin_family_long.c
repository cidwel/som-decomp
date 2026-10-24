#include "som_c.h"

/* C12C15 initialize_spell_entity_twin_family_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_twin_family_long.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_entity_twin_family_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2C17, 0xC12C19); GUARD_JSR(c, sp_call, 0x2C17); } /* initialize_spell_entity_twin_family */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12C15, SOM_RTL, "gen", initialize_spell_entity_twin_family_long, 0, 0, 1, 1, 0, 4, 2)
