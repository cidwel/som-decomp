#include "som_c.h"

/* C04A75 derive_hero_armor_defenses_and_immunity   [class B, 138 bytes, 69 instructions]
 * Source: src/rom/derive_hero_armor_defenses_and_immunity.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void derive_hero_armor_defenses_and_immunity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(ACTOR_AGILITY + x);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED2, value2);
    uint8_t value3;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED2, value3);
    uint8_t value4;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED2, value4);
    RAM8(ACTOR_EVADE + x) = (uint8_t)((uint8_t)((uint8_t)((value >> 2) + value2) + value3) + value4);
    uint8_t value5 = RAM8(ACTOR_WISDOM + x);
    uint8_t value6;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED4, value6);
    uint8_t value7;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED4, value7);
    uint8_t value8;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED4, value8);
    RAM8(ACTOR_MAGIC_EVADE + x) = (uint8_t)((uint8_t)((uint8_t)((value5 >> 2) + value6) + value7) + value8);
    RAM8(0x03A5) = 0;
    RAM8(0x03A7) = 0;
    RAM8(0x03A9) = 0;
    RAM8(BATTLE_TEMP_A4) = RAM8(ACTOR_CONSTITUTION + x);
    uint8_t value10;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED1, value10);
    RAM8(BATTLE_TEMP_A6) = value10;
    uint8_t value11;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED1, value11);
    RAM8(BATTLE_TEMP_A8) = value11;
    uint8_t value12;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED1, value12);
    uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
    uint16_t battle_temp_a6 = RAM16(BATTLE_TEMP_A6);
    uint16_t battle_temp_a8 = RAM16(BATTLE_TEMP_A8);
    RAM16_SET(ACTOR_DEFENSE + x, (uint16_t)((uint16_t)((uint16_t)((((a_hi << 8) | value12) & 0xFF) + battle_temp_a4) + battle_temp_a6) + battle_temp_a8));
    RAM8(BATTLE_TEMP_A4) = RAM8(ACTOR_WISDOM + x);
    uint8_t value14;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED3, value14);
    RAM8(BATTLE_TEMP_A6) = value14;
    uint8_t value15;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED3, value15);
    RAM8(BATTLE_TEMP_A8) = value15;
    uint8_t value16;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED3, value16);
    RAM16_SET(ACTOR_MAGIC_DEFENSE + x, (uint16_t)((uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((uint16_t)((((a_hi << 8) | value12) & 0xFF) + battle_temp_a4) + battle_temp_a6) + battle_temp_a8) >> 8 << 8) | value16) & 0xFF) + RAM16(BATTLE_TEMP_A4)) + RAM16(BATTLE_TEMP_A6)) + RAM16(BATTLE_TEMP_A8)));
    uint16_t value17;
    BUS16_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED7, value17);
    uint16_t value18;
    BUS16_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED7, value18);
    uint16_t value19;
    BUS16_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED7, value19);
    RAM16_SET(ACTOR_STATUS_IMMUNITY + x, value17 | value18 | value19 | 0x0800);
    r->a = (r->a & 0x00FF) | (((value17 | value18 | value19 | 0x0800) >> 8) << 8);
    r->y = 0x3ED7;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04A75, SOM_RTS, "hand", derive_hero_armor_defenses_and_immunity, 0, L_B | L_X | L_Y, 1, 1, 0, 138, 69)
