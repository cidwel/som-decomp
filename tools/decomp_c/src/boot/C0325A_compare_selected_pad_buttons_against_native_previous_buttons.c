#include "som_c.h"

/* C0325A compare_selected_pad_buttons_against_native_previous_buttons   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/compare_selected_pad_buttons_against_native_previous_buttons.s
 * Documented in docs/ui-native-loaded-game-title-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void compare_selected_pad_buttons_against_native_previous_buttons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x19FD);
    uint8_t value2 = RAM8(0x0043 + (uint8_t)(value << 1));
    uint8_t value3 = RAM8(0xA204 + (uint8_t)(value << 1));
    r->a = value2;
    r->x = (uint8_t)(value << 1);
    r->c = value2 >= value3;
    r->z = value2 == value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0325A, SOM_RTS, "gen", compare_selected_pad_buttons_against_native_previous_buttons, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 15, 8)
