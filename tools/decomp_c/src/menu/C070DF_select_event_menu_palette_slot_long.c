#include "som_c.h"

/* C070DF select_event_menu_palette_slot_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/select_event_menu_palette_slot_long.s
 * Documented in docs/event-menu-palette-graphics.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXV.
 */
static void select_event_menu_palette_slot_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x70E1, 0xC070EC); /* select_event_menu_palette_slot */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC070DF, SOM_RTL, "gen", select_event_menu_palette_slot_long, 0, L_A | L_B | L_X | L_V, 1, 0, 0, 4, 2)
