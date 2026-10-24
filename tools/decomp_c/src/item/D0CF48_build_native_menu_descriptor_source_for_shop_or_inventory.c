#include "som_c.h"

/* D0CF48 build_native_menu_descriptor_source_for_shop_or_inventory   [class A, 25 bytes, 11 instructions]
 * Source: src/rom/build_native_menu_descriptor_source_for_shop_or_inventory.s
 * Documented in docs/event-menu-inventory-builder.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void build_native_menu_descriptor_source_for_shop_or_inventory(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x182E, 0);
    RAM8(RING_CURSOR) = 0;
    if (RAM8(0x1847) == 1) {
        r->mf = 1;
        JSR(c, 0xCF5F, 0xD0CF61); /* build_shop_menu_descriptor_list_and_apply_native_row_order */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTL(c);
    }
    r->mf = 1;
    JSR(c, 0xCF5B, 0xD0CF9C); /* build_native_inventory_descriptors_apply_status_masks_and_rotate */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CF48, SOM_RTL, "gen", build_native_menu_descriptor_source_for_shop_or_inventory, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 25, 11)
