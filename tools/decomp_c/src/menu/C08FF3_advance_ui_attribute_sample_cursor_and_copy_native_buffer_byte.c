#include "som_c.h"

/* C08FF3 advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte.s
 * Documented in docs/ui-native-ui-frame-radial.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x008A);
    RAM16_SET(0x008A, (uint16_t)(value + 0x2D) & 0x03FF);
    RAM8(0xEC00 + ((uint16_t)(value + 0x2D) & 0x03FF)) = RAM8(0xE800 + ((uint16_t)(value + 0x2D) & 0x03FF));
    r->x = (uint16_t)(value + 0x2D) & 0x03FF;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08FF3, SOM_RTS, "gen", advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte, 0, L_X | L_Y, 1, 1, 0, 23, 11)
