#include "som_c.h"

/* C75D68 configure_and_render_two_native_saved_slot_text_rows   [class B, 46 bytes, 20 instructions]
 * Source: src/rom/configure_and_render_two_native_saved_slot_text_rows.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void configure_and_render_two_native_saved_slot_text_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = BUS16(c, 0xC75F87 + ((RAM16(0xA162) & 0xFF) << 1));
    uint16_t value3 = RAM16(0xA199);
    RAM16_SET(0xA18C, (uint16_t)(value2 + value3));
    RAM16_SET(0xA191, 0x0380);
    RAM16_SET(0xA199, 0x01C0);
    RAM8(0xA171) = 2;
    r->c = value2 + value3 > 0xFFFF;
    r->v = ((value2 ^ (uint16_t)(value2 + value3)) & (value3 ^ (uint16_t)(value2 + value3)) & 0x8000) != 0;
    JSR(c, 0x5D94, 0xC75D9A); /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75D68, SOM_RTS, "gen", configure_and_render_two_native_saved_slot_text_rows, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 46, 20)
