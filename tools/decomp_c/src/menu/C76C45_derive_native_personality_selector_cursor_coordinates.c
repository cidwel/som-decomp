#include "som_c.h"

/* C76C45 derive_native_personality_selector_cursor_coordinates   [class A, 19 bytes, 11 instructions]
 * Source: src/rom/derive_native_personality_selector_cursor_coordinates.s
 * Documented in docs/ui-native-personality-movement.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void derive_native_personality_selector_cursor_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA211);
    RAM8(0xA15A) = (uint8_t)((uint8_t)(value << 4) + 0x30);
    RAM8(0xA159) = 0xE3;
    r->c = (uint8_t)(value << 4) + 0x30 > 0xFF;
    r->v = (((uint8_t)(value << 4) ^ (uint8_t)((uint8_t)(value << 4) + 0x30)) & ((uint8_t)((uint8_t)(value << 4) + 0x30) ^ 0x30) & 0x80) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76C45, SOM_RTL, "gen", derive_native_personality_selector_cursor_coordinates, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 19, 11)
