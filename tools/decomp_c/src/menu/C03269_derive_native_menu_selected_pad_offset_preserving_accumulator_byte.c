#include "som_c.h"

/* C03269 derive_native_menu_selected_pad_offset_preserving_accumulator_byte   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/derive_native_menu_selected_pad_offset_preserving_accumulator_byte.s
 * Documented in docs/ui-native-loaded-game-menu-input.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void derive_native_menu_selected_pad_offset_preserving_accumulator_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x19FD);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->x = (uint8_t)(value << 1);
    r->c = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03269, SOM_RTS, "gen", derive_native_menu_selected_pad_offset_preserving_accumulator_byte, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 8)
