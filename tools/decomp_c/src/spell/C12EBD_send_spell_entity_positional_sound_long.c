#include "som_c.h"

/* C12EBD send_spell_entity_positional_sound_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/send_spell_entity_positional_sound_long.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void send_spell_entity_positional_sound_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EBF, 0xC1376A); GUARD_JSR(c, sp_call, 0x2EBF); } /* send_spell_entity_positional_sound */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EBD, SOM_RTL, "hand", send_spell_entity_positional_sound_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
