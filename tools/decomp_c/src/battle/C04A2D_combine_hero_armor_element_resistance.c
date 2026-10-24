#include "som_c.h"

/* C04A2D combine_hero_armor_element_resistance   [class A, 38 bytes, 18 instructions]
 * Source: src/rom/combine_hero_armor_element_resistance.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void combine_hero_armor_element_resistance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED6, value);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED6, value2);
    uint8_t value3;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED6, value3);
    RAM8(ACTOR_RESIST_ELEMENT + x) = value | value2 | value3;
    RAM8(0xE1A2 + x) = 0;
    RAM8(BATTLE_TEMP_A6) = value | value2 | value3;
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((value | value2 | value3) << 1) & 0x2A;
    RAM8(ACTOR_WEAK_ELEMENT + x) = (((RAM8(BATTLE_TEMP_A6) >> 1) & 0x15) | RAM8(BATTLE_TEMP_A4)) & 0x3F;
    RAM8(0xE1A0 + x) = 0;
    r->y = 0x3ED6;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04A2D, SOM_RTS, "hand", combine_hero_armor_element_resistance, 0, L_B | L_X | L_Y, 1, 1, 0, 38, 18)
