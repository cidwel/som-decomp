#include "som_c.h"

/* C75D96 long_call_native_rendered_text_row_publication   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/long_call_native_rendered_text_row_publication.s
 * Documented in docs/ui-native-spell-item-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void long_call_native_rendered_text_row_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x5D98, 0xC75D9A); /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75D96, SOM_RTL, "gen", long_call_native_rendered_text_row_publication, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 4, 2)
