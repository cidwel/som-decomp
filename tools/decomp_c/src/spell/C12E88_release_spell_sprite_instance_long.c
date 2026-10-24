#include "som_c.h"

/* C12E88 release_spell_sprite_instance_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_spell_sprite_instance_long.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void release_spell_sprite_instance_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E8A, 0xC140E5); GUARD_JSR(c, sp_call, 0x2E8A); } /* release_spell_entity_sprite_instance */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E88, SOM_RTL, "hand", release_spell_sprite_instance_long, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
