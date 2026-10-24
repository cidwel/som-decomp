#include "som_c.h"

/* C04B90 apply_single_armor_attribute_flags   [class A, 46 bytes, 23 instructions]
 * Source: src/rom/apply_single_armor_attribute_flags.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void apply_single_armor_attribute_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(BATTLE_TEMP_A4) = a;
    RAM8(BATTLE_TEMP_A6) = 4;
    RAM8(0x03AA) = 5;
    if ((RAM8(BATTLE_TEMP_A4) & RAM8(0x0040)) != 0) {
        RAM8(0x03AA) = 0xFE;
    }
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    do {
        if ((RAM8(BATTLE_TEMP_A4) & 0x10) != 0) {
            RAM8(ACTOR_STRENGTH + x1) = (uint8_t)(RAM8(0x03AA) + RAM8(ACTOR_STRENGTH + x1));
        }
        RAM8(BATTLE_TEMP_A4) <<= 1;
        RAM8(BATTLE_TEMP_A6)--;
        x1 = (uint16_t)(x1 + 1);
    } while (RAM8(BATTLE_TEMP_A6) != 0);
    uint16_t value4 = RAM16(0x03BD);
    r->a = (a_hi1 << 8) | a;
    r->x = value4;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04B90, SOM_RTS, "gen", apply_single_armor_attribute_flags, 0, L_B | L_X | L_Y, 1, 1, 0, 46, 23)
