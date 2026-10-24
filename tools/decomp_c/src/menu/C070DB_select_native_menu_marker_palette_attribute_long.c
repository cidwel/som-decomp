#include "som_c.h"

/* C070DB select_native_menu_marker_palette_attribute_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/select_native_menu_marker_palette_attribute_long.s
 * Documented in docs/event-menu-target-selector.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXY.
 */
static void select_native_menu_marker_palette_attribute_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x70DD, 0xC070E3); /* select_event_menu_oam_palette_attribute */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC070DB, SOM_RTL, "gen", select_native_menu_marker_palette_attribute_long, 0, L_A | L_B | L_X | L_Y, 1, 0, 0, 4, 2)
