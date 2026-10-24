#include "som_c.h"

/* C02ADF upload_native_saved_slot_text_rows_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/upload_native_saved_slot_text_rows_wrapper.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void upload_native_saved_slot_text_rows_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AE1, 0xC023BA); /* upload_native_menu_assembled_text_tiles */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02ADF, SOM_RTL, "gen", upload_native_saved_slot_text_rows_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 4, 2)
