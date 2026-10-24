#include "som_c.h"

/* C03989 send_combat_sound_through_native_long_call_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/send_combat_sound_through_native_long_call_wrapper.s
 * Documented in docs/actor-sound-sprite-public-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: B.
 */
static void send_combat_sound_through_native_long_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x398B, 0xC0398D); GUARD_JSR(c, sp_call, 0x398B); } /* send_combat_sound_with_fixed_parameter_fifteen */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC03989, SOM_RTL, "gen", send_combat_sound_through_native_long_call_wrapper, 0, L_B, 1, 1, 0, 4, 2)
