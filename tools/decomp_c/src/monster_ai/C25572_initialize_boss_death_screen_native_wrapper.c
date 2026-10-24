#include "som_c.h"

/* C25572 initialize_boss_death_screen_native_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_boss_death_screen_native_wrapper.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_boss_death_screen_native_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5574, 0xC20B14); GUARD_JSR(c, sp_call, 0x5574); } /* prepare_boss_death_palettes_graphics_and_selected_actor */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25572, SOM_RTS, "hand", initialize_boss_death_screen_native_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
