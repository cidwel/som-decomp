#include "som_c.h"

/* C75369 render_nine_native_save_confirmation_description_rows   [class A, 29 bytes, 12 instructions]
 * Source: src/rom/render_nine_native_save_confirmation_description_rows.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void render_nine_native_save_confirmation_description_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA18C, 0x70C0);
    RAM16_SET(0xA191, 0x0300);
    RAM16_SET(0xA199, 0x0180);
    RAM8(0xA171) = 9;
    JSR(c, 0x5384, 0xC75D9A); /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75369, SOM_RTS, "gen", render_nine_native_save_confirmation_description_rows, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 29, 12)
