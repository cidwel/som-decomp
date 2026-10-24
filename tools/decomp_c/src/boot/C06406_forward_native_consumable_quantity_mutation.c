#include "som_c.h"

/* C06406 forward_native_consumable_quantity_mutation   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_consumable_quantity_mutation.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void forward_native_consumable_quantity_mutation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC078C3, SOM_RTL); /* change_native_consumable_quantity_and_compact_depleted_inventory */
}
SOM_REGISTER(0xC06406, SOM_RTL, "gen", forward_native_consumable_quantity_mutation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
