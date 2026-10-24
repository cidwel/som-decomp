#include "som_c.h"

/* C12E8C hide_burst_child_sprite_through_native_long_call_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/hide_burst_child_sprite_through_native_long_call_wrapper.s
 * Documented in docs/actor-sound-sprite-public-wrappers.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void hide_burst_child_sprite_through_native_long_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E8E, 0xC14090); GUARD_JSR(c, sp_call, 0x2E8E); } /* hide_spell_entity_sprite_oam_entry */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E8C, SOM_RTL, "gen", hide_burst_child_sprite_through_native_long_call_wrapper, 0, 0, 1, -1, 0, 4, 2)
