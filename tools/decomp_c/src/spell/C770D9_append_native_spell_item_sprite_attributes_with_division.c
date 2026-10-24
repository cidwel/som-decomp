#include "som_c.h"

/* C770D9 append_native_spell_item_sprite_attributes_with_division   [class B, 80 bytes, 38 instructions]
 * Source: src/rom/append_native_spell_item_sprite_attributes_with_division.s
 * Documented in docs/ui-native-spell-item-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void append_native_spell_item_sprite_attributes_with_division(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x004204, RAM8(0xA184));
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004206, 3);
    uint8_t value2 = RAM8(0xA15B);
    RAM8(0x9C00 + (uint8_t)(value2 << 2)) = (uint8_t)(RAM8(0xA15A) << 3);
    RAM8(0x9C00 + (uint8_t)(value2 << 2) + 1) = (uint8_t)(RAM8(0xA159) << 3);
    uint16_t value5 = BUS16(c, 0x004214);
    uint16_t value6 = RAM16(0xA1C7);
    RAM16_SET(0x9C00 + (uint8_t)(value2 << 2) + 2, (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0x0800 + ((((uint8_t)value5 << 8) | (value5 >> 8)) >> 0x0F)) | value6);
    RAM16_SET(0xA1C7, (uint16_t)(RAM16(0xA1C7) + 1));
    RAM16_SET(0xA1C7, (uint16_t)(RAM16(0xA1C7) + 1));
    RAM8(0xA184)++;
    RAM8(0xA15B)++;
    r->a = (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0x0800 + ((((uint8_t)value5 << 8) | (value5 >> 8)) >> 0x0F)) | value6;
    r->x = (uint8_t)(value2 << 2) + 4;
    r->c = (uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0x0800 + ((((uint8_t)value5 << 8) | (value5 >> 8)) >> 0x0F) > 0xFFFF;
    r->v = (((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0x0800 + ((((uint8_t)value5 << 8) | (value5 >> 8)) >> 0x0F))) & ((uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0x0800 + ((((uint8_t)value5 << 8) | (value5 >> 8)) >> 0x0F)) ^ 0x0800) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC770D9, SOM_RTS, "gen", append_native_spell_item_sprite_attributes_with_division, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 80, 38)
