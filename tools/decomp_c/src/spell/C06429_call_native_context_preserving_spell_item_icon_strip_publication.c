#include "som_c.h"

/* C06429 call_native_context_preserving_spell_item_icon_strip_publication   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/call_native_context_preserving_spell_item_icon_strip_publication.s
 * Documented in docs/ui-native-spell-item-api.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void call_native_context_preserving_spell_item_icon_strip_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSL(c, 0x642C, 0xD0C856); /* publish_native_icon_strip_with_saved_menu_context */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC06429, SOM_RTL, "gen", call_native_context_preserving_spell_item_icon_strip_publication, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 5, 2)
