#include "som_c.h"

/* C77040 initialize_native_spell_item_icon_descriptor_cursor   [class A, 39 bytes, 15 instructions]
 * Source: src/rom/initialize_native_spell_item_icon_descriptor_cursor.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void initialize_native_spell_item_icon_descriptor_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA159) = 4;
    RAM8(0xA15A) = 1;
    RAM8(0xA15B) = 0;
    RAM8(0xA185) = 0;
    RAM8(0xA184) = 0;
    uint16_t value = BUS16(c, 0xC0640C);
    RAM16_SET(0xA178, value);
    RAM16_SET(0xA1C7, 0x3030);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    r->x = 0x3030;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC77040, SOM_RTS, "gen", initialize_native_spell_item_icon_descriptor_cursor, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 39, 15)
