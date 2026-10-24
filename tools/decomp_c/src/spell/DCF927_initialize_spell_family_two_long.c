#include "som_c.h"

/* DCF927 initialize_spell_family_two_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_family_two_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_family_two_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF929, 0xDCF92B); GUARD_JSR(c, sp_call, 0xF929); } /* initialize_spell_family_two */
    RETURN_RTL(c);
}
SOM_REGISTER(0xDCF927, SOM_RTL, "gen", initialize_spell_family_two_long, 0, 0, 1, 1, 0, 4, 2)
