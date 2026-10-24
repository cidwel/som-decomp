#include "som_c.h"

/* C0640E forward_native_one_tile_menu_icon_conversion   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_one_tile_menu_icon_conversion.s
 * Documented in docs/event-menu-single-icon.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void forward_native_one_tile_menu_icon_conversion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0642E, SOM_RTL); /* call_native_one_tile_menu_icon_conversion_long */
}
SOM_REGISTER(0xC0640E, SOM_RTL, "gen", forward_native_one_tile_menu_icon_conversion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
