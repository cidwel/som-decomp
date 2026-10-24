#include "som_c.h"

/* C06411 forward_native_buy_ring_menu_to_saved_context_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_buy_ring_menu_to_saved_context_entry.s
 * Documented in docs/event-menu-shop-public.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void forward_native_buy_ring_menu_to_saved_context_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    TAIL_CALL(c, 0xC06617, SOM_RTL); /* enter_public_shop_buy_ring_and_restore_saved_party_categories */
}
SOM_REGISTER(0xC06411, SOM_RTL, "hand", forward_native_buy_ring_menu_to_saved_context_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 3, 1)
