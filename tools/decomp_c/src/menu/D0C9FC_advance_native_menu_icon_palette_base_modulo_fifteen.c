#include "som_c.h"

/* D0C9FC advance_native_menu_icon_palette_base_modulo_fifteen   [class A, 20 bytes, 10 instructions]
 * Source: src/rom/advance_native_menu_icon_palette_base_modulo_fifteen.s
 * Documented in docs/event-menu-icon-upload.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXY.
 */
static void advance_native_menu_icon_palette_base_modulo_fifteen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1810);
    uint8_t a1;
    if ((uint8_t)(value + 5) < 0x0F) {
        a1 = (uint8_t)(value + 5);
    } else {
        a1 = 0;
    }
    RAM8(0x1810) = a1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0C9FC, SOM_RTS, "gen", advance_native_menu_icon_palette_base_modulo_fifteen, 0, L_B | L_X | L_Y, 1, 0, 0, 20, 10)
