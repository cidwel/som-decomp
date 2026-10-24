#include "som_c.h"

/* D0C8FB publish_native_menu_icon_grid_or_equipment_preview   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/publish_native_menu_icon_grid_or_equipment_preview.s
 * Documented in docs/event-menu-icon-grid.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void publish_native_menu_icon_grid_or_equipment_preview(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1810) = 0xFB;
    r->x = 0x1880;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC909, 0xD0C90B); GUARD_JSR(c, sp_call, 0xC909); } /* select_three_row_equipment_preview_or_twelve_icon_grid */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0C8FB, SOM_RTL, "gen", publish_native_menu_icon_grid_or_equipment_preview, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 16, 7)
