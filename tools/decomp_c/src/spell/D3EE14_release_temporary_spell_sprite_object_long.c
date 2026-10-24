#include "som_c.h"
#include "som_hand_b.h"

/* D3EE14 release_temporary_spell_sprite_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_temporary_spell_sprite_object_long.s
 * Documented in docs/actor-cast-entity-sprite-objects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void release_temporary_spell_sprite_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEE16, 0xD3EE18); GUARD_JSR(c, sp_call, 0xEE16); } /* release_temporary_spell_sprite_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3EE14, SOM_RTL, "hand", release_temporary_spell_sprite_object_long, 0, 0, 1, 1, 0, 4, 2)
