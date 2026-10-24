#include "som_c.h"

/* C00048 public_buy_ring_menu_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_buy_ring_menu_alias.s
 * Documented in docs/event-menu-shop-public.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void public_buy_ring_menu_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06411, SOM_RTL); /* forward_native_buy_ring_menu_to_saved_context_entry */
}
SOM_REGISTER(0xC00048, SOM_RTL, "gen", public_buy_ring_menu_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
