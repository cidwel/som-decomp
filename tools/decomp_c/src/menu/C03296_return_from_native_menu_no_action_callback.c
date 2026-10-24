#include "som_c.h"

/* C03296 return_from_native_menu_no_action_callback   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/return_from_native_menu_no_action_callback.s
 * Documented in docs/ui-native-loaded-game-title-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void return_from_native_menu_no_action_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03296, SOM_RTS, "gen", return_from_native_menu_no_action_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
