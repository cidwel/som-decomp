#include "som_c.h"

/* D9FDFD mark_native_inventory_descriptor_row_at_current_y   [class C, 11 bytes, 8 instructions]
 * Source: src/rom/mark_native_inventory_descriptor_row_at_current_y.s
 * Documented in docs/event-menu-inventory-masks.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void mark_native_inventory_descriptor_row_at_current_y(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    r->x = y;
    r->mf = 0;
    r->sp -= 3;
    JSR(c, 0xFE04, 0xD9FE08); /* set_native_inventory_descriptor_disabled_flag */
    r->sp += 3;
    r->x = x;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD9FDFD, SOM_RTS, "gen", mark_native_inventory_descriptor_row_at_current_y, 0, L_B | L_X | L_Y | L_V, 3, 1, 0, 11, 8)
