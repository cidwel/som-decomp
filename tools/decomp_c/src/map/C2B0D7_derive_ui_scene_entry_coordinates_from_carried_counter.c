#include "som_c.h"

/* C2B0D7 derive_ui_scene_entry_coordinates_from_carried_counter   [class B, 51 bytes, 19 instructions]
 * Source: src/rom/derive_ui_scene_entry_coordinates_from_carried_counter.s
 * Documented in docs/ui-native-ui-entry-prefix.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void derive_ui_scene_entry_coordinates_from_carried_counter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    uint16_t value = RAM16(0x0126);
    RAM16_SET(0x0126, (uint16_t)(value + 0x37 + carry));
    uint8_t a1;
    uint8_t a_hi1;
    if (((uint16_t)(value + 0x37 + carry) & 0xFF) < 0x80) {
        a1 = (uint16_t)(value + 0x37 + carry) & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)(((uint16_t)(value + 0x37 + carry) & 0xFF) ^ 0xFF7F);
        a_hi1 = (((uint16_t)(value + 0x37 + carry) & 0xFF) ^ 0xFF7F) >> 8;
    }
    uint16_t value2 = RAM16(0x00FA);
    RAM16_SET(0x0128, (uint16_t)(((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80)) & 0x0FFF);
    uint16_t value3 = RAM16(0x0126);
    uint16_t value4 = RAM16(0x00FC);
    RAM16_SET(0x012A, (uint16_t)((((value3 & 0x7F) | 0x0100) ^ 0xFFFF) + value4 + (((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80) > 0xFFFF)) & 0x0FFF);
    r->a = (uint16_t)((((value3 & 0x7F) | 0x0100) ^ 0xFFFF) + value4 + (((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80) > 0xFFFF)) & 0x0FFF;
    r->c = (((value3 & 0x7F) | 0x0100) ^ 0xFFFF) + value4 + (((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80) > 0xFFFF) > 0xFFFF;
    r->v = ((((value3 & 0x7F) | 0x0100) ^ 0xFFFF ^ (uint16_t)((((value3 & 0x7F) | 0x0100) ^ 0xFFFF) + value4 + (((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80) > 0xFFFF))) & (value4 ^ (uint16_t)((((value3 & 0x7F) | 0x0100) ^ 0xFFFF) + value4 + (((a_hi1 << 8) | a1) + value2 + (((uint16_t)(value + 0x37 + carry) & 0xFF) >= 0x80) > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B0D7, SOM_RTL, "gen", derive_ui_scene_entry_coordinates_from_carried_counter, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 51, 19)
