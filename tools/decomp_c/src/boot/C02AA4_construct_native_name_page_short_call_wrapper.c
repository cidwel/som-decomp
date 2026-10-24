#include "som_c.h"

/* C02AA4 construct_native_name_page_short_call_wrapper   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/construct_native_name_page_short_call_wrapper.s
 * Documented in docs/ui-native-loaded-game-name-trajectory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void construct_native_name_page_short_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSL(c, 0x2AA7, 0xC75000); /* construct_native_hero_name_screen_with_party_graphics_and_cursor */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02AA4, SOM_RTS, "gen", construct_native_name_page_short_call_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
