#include "som_c.h"

/* C12E90 construct_spell_graphics_audio_resources_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/construct_spell_graphics_audio_resources_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: XYCV.
 */
static void construct_spell_graphics_audio_resources_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E92, 0xC137E7); GUARD_JSR(c, sp_call, 0x2E92); } /* construct_spell_entity_graphics_audio_resources */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E90, SOM_RTL, "hand", construct_spell_graphics_audio_resources_long, 0, L_X | L_Y | L_C | L_V, 1, -1, 0, 4, 2)
