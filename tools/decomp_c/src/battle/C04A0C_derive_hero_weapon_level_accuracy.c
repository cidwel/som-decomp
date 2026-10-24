#include "som_c.h"

/* C04A0C derive_hero_weapon_level_accuracy   [class A, 33 bytes, 16 instructions]
 * Source: src/rom/derive_hero_weapon_level_accuracy.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void derive_hero_weapon_level_accuracy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(ACTOR_WEAPON_LEVEL + x);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((uint8_t)(value << 1) + value);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1006, value2);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((uint8_t)((uint8_t)(value << 1) + value) + value2);
    if (RAM8(0xE1E4 + x) > 4) {
        RAM8(BATTLE_TEMP_A4) >>= 1;
    }
    RAM8(ACTOR_CRIT_BASE + x) = RAM8(BATTLE_TEMP_A4);
    r->y = 0x1006;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04A0C, SOM_RTS, "hand", derive_hero_weapon_level_accuracy, 0, L_B | L_X | L_Y, 1, 1, 0, 33, 16)
