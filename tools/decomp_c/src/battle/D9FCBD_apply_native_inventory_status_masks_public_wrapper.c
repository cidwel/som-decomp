#include "som_c.h"

/* D9FCBD apply_native_inventory_status_masks_public_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/apply_native_inventory_status_masks_public_wrapper.s
 * Documented in docs/event-menu-inventory-masks.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void apply_native_inventory_status_masks_public_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xFCBF, 0xD9FCC1); /* dispatch_native_inventory_status_masks_by_mode_and_category */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD9FCBD, SOM_RTL, "gen", apply_native_inventory_status_masks_public_wrapper, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 4, 2)
