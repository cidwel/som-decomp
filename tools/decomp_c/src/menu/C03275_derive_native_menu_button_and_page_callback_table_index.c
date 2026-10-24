#include "som_c.h"

/* C03275 derive_native_menu_button_and_page_callback_table_index   [class A, 33 bytes, 17 instructions]
 * Source: src/rom/derive_native_menu_button_and_page_callback_table_index.s
 * Documented in docs/ui-native-loaded-game-menu-input.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void derive_native_menu_button_and_page_callback_table_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA209);
    RAM8(0xA173) = value;
    uint8_t value2 = RAM8(0xA173);
    uint8_t value3 = RAM8(0xA202);
    r->a = (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF)) << 1;
    r->x = (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF)) << 1;
    r->c = (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF)) & 0x8000;
    r->z = (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF)) << 1 == 0;
    r->n = (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF)) << 1 & 0x8000;
    r->v = (((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF))) & (value3 ^ (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF)) + value3 + ((uint8_t)((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF)) + value2 + ((uint8_t)((uint8_t)(value << 3) + value2) + value2 + ((uint8_t)(value << 3) + value2 > 0xFF) > 0xFF) > 0xFF))) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03275, SOM_RTS, "gen", derive_native_menu_button_and_page_callback_table_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 33, 17)
