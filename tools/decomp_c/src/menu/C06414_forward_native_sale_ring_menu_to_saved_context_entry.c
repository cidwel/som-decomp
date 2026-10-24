#include "som_c.h"

/* C06414 forward_native_sale_ring_menu_to_saved_context_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_sale_ring_menu_to_saved_context_entry.s
 * Documented in docs/event-menu-shop-public.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void forward_native_sale_ring_menu_to_saved_context_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0663E, SOM_RTL); /* enter_public_shop_sale_ring_or_exit_when_inventory_is_empty */
}
SOM_REGISTER(0xC06414, SOM_RTL, "gen", forward_native_sale_ring_menu_to_saved_context_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
