#include "som_c.h"

/* C0324A reset_native_name_repeat_timer_on_new_direction   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/reset_native_name_repeat_timer_on_new_direction.s
 * Documented in docs/ui-native-name-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void reset_native_name_repeat_timer_on_new_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x324C, 0xC03269); /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t x_ret = r->x;
    if ((RAM8(0xA204 + x_ret) & 0x0F) == 0) {
        RAM8(0xA201) = 0xF2;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0324A, SOM_RTS, "gen", reset_native_name_repeat_timer_on_new_direction, 0, L_B | L_X | L_Y, 1, 1, 0, 16, 7)
