#include "som_c.h"

/* C770BA advance_native_two_column_spell_item_icon_positions   [class A, 31 bytes, 15 instructions]
 * Source: src/rom/advance_native_two_column_spell_item_icon_positions.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_native_two_column_spell_item_icon_positions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA15A) = 0x11;
    uint8_t value = RAM8(0xA185);
    uint8_t a1;
    if ((value & 1) == 0) {
        a1 = value;
    } else {
        RAM8(0xA15A) = 1;
        uint8_t value2 = RAM8(0xA159);
        RAM8(0xA159) = (uint8_t)(value2 + 4);
        a1 = (uint8_t)(value2 + 4);
    }
    RAM8(0xA185)++;
    SET_A8(r, a1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC770BA, SOM_RTS, "gen", advance_native_two_column_spell_item_icon_positions, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 31, 15)
