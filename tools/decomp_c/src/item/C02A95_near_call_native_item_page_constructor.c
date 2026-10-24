#include "som_c.h"

/* C02A95 near_call_native_item_page_constructor   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/near_call_native_item_page_constructor.s
 * Documented in docs/ui-native-spell-item-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void near_call_native_item_page_constructor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2A98, 0xC76304); GUARD_JSL(c, sp_call, 0x2A98); } /* construct_native_spell_or_item_page_from_selected_description */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02A95, SOM_RTS, "gen", near_call_native_item_page_constructor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
