#include "som_c.h"

/* C0004B public_sale_ring_menu_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_sale_ring_menu_alias.s
 * Documented in docs/event-menu-shop-public.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void public_sale_ring_menu_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC06414, SOM_RTL); /* forward_native_sale_ring_menu_to_saved_context_entry */
}
SOM_REGISTER(0xC0004B, SOM_RTL, "gen", public_sale_ring_menu_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
