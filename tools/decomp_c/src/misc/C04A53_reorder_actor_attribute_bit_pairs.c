#include "som_c.h"

/* C04A53 reorder_actor_attribute_bit_pairs   [class A, 34 bytes, 16 instructions]
 * Source: src/rom/reorder_actor_attribute_bit_pairs.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void reorder_actor_attribute_bit_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(ACTOR_ELEMENT_RESIST_MASK + x);
    RAM8(BATTLE_TEMP_A6) = value;
    RAM8(ACTOR_RESIST_ELEMENT + x) = value;
    RAM8(0xE1A2 + x) = 0;
    uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)(battle_temp_a6 << 1) & 0x2A;
    RAM8(ACTOR_WEAK_ELEMENT + x) = (((battle_temp_a6 >> 1) & 0x15) | RAM8(BATTLE_TEMP_A4)) & 0x3F;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04A53, SOM_RTS, "gen", reorder_actor_attribute_bit_pairs, 0, L_B | L_X | L_Y, 1, 1, 0, 34, 16)
