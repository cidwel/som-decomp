#include "som_c.h"

/* C06409 jump_native_spell_item_icon_strip_api   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_native_spell_item_icon_strip_api.s
 * Documented in docs/ui-native-spell-item-api.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void jump_native_spell_item_icon_strip_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06429, SOM_RTL); /* call_native_context_preserving_spell_item_icon_strip_publication */
}
SOM_REGISTER(0xC06409, SOM_RTL, "gen", jump_native_spell_item_icon_strip_api, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
