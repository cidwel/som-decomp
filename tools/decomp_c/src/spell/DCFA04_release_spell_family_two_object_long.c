#include "som_c.h"
#include "som_hand_b.h"

/* DCFA04 release_spell_family_two_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_spell_family_two_object_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void release_spell_family_two_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFA06, 0xDCFA08); GUARD_JSR(c, sp_call, 0xFA06); } /* release_spell_family_two_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xDCFA04, SOM_RTL, "hand", release_spell_family_two_object_long, 0, 0, 1, 1, 0, 4, 2)
