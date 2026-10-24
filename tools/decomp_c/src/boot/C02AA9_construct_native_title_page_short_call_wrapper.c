#include "som_c.h"

/* C02AA9 construct_native_title_page_short_call_wrapper   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/construct_native_title_page_short_call_wrapper.s
 * Documented in docs/ui-native-loaded-game-menu-trajectory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void construct_native_title_page_short_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2AAC, 0xC75229); GUARD_JSL(c, sp_call, 0x2AAC); } /* construct_native_title_load_selection_from_validated_saved_slots */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02AA9, SOM_RTS, "hand", construct_native_title_page_short_call_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
