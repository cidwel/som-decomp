#include "som_c.h"

/* D0D275 publish_native_inventory_row_attribute_public_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/publish_native_inventory_row_attribute_public_wrapper.s
 * Documented in docs/event-menu-inventory-attributes.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void publish_native_inventory_row_attribute_public_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xD277, 0xD0D279); /* publish_native_inventory_owner_and_rotated_selection_attribute */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0D275, SOM_RTL, "gen", publish_native_inventory_row_attribute_public_wrapper, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 4, 2)
