#include "som_c.h"

/* C02ACB construct_native_menu_page_long_call_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/construct_native_menu_page_long_call_wrapper.s
 * Documented in docs/ui-native-loaded-game-menu-pages.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void construct_native_menu_page_long_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2ACD, 0xC021DB); /* construct_native_menu_page_with_saved_slots_and_real_text_publication */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02ACB, SOM_RTL, "gen", construct_native_menu_page_long_call_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 4, 2)
