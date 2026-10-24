#include "som_c.h"

/* C76057 publish_three_native_settings_color_cursor_coordinates   [class A, 42 bytes, 22 instructions]
 * Source: src/rom/publish_three_native_settings_color_cursor_coordinates.s
 * Documented in docs/ui-native-settings-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void publish_three_native_settings_color_cursor_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA159) = 0x20;
    uint8_t a1 = 3;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 1;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0xA159);
        RAM8(0x9C00 + x1) = value;
        RAM8(0xA159) = (uint8_t)(value + 0x10);
        RAM8(0x9C00 + (uint16_t)(x1 + 1)) = 0x20;
        RAM8(0x9C00 + (uint16_t)(x1 + 2)) = 0x20;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = 0x20;
        x1 = (uint16_t)(x1 + 4);
        carry1 = value + 0x10 > 0xFF;
        overflow1 = ((value ^ (uint8_t)(value + 0x10)) & ((uint8_t)(value + 0x10) ^ 0x10) & 0x80) != 0;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76057, SOM_RTS, "gen", publish_three_native_settings_color_cursor_coordinates, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 42, 22)
