#include "som_c.h"

/* C02AAE construct_native_load_page_short_call_wrapper   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/construct_native_load_page_short_call_wrapper.s
 * Documented in docs/ui-native-loaded-game-menu-trajectory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void construct_native_load_page_short_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2AB1, 0xC75278); GUARD_JSL(c, sp_call, 0x2AB1); } /* construct_native_load_game_page_and_select_remembered_slot */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02AAE, SOM_RTS, "gen", construct_native_load_page_short_call_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
