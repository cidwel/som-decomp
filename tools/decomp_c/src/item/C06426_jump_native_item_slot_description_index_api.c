#include "som_c.h"

/* C06426 jump_native_item_slot_description_index_api   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_native_item_slot_description_index_api.s
 * Documented in docs/ui-native-spell-item-api.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void jump_native_item_slot_description_index_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06481, SOM_RTL); /* query_native_item_slot_description_index_with_saved_context */
}
SOM_REGISTER(0xC06426, SOM_RTL, "gen", jump_native_item_slot_description_index_api, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 3, 1)
