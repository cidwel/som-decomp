#include "som_c.h"

/* C04BBE reduce_and_clamp_actor_appearance_attributes   [class A, 57 bytes, 28 instructions]
 * Source: src/rom/reduce_and_clamp_actor_appearance_attributes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void reduce_and_clamp_actor_appearance_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if ((RAM8(ACTOR_STATUS + x) & 8) != 0) {
        RAM8(BATTLE_TEMP_A4) = RAM8(ACTOR_AGILITY + x) >> 4;
        RAM8(ACTOR_AGILITY + x) = (uint8_t)(RAM8(ACTOR_AGILITY + x) - RAM8(BATTLE_TEMP_A4));
    }
    RAM8(BATTLE_TEMP_A4) = 5;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    do {
        if (RAM8(ACTOR_STRENGTH + x1) > 0x63) {
            RAM8(ACTOR_STRENGTH + x1) = 0x63;
        }
        if (RAM8(ACTOR_STRENGTH + x1) <= 1) {
            RAM8(ACTOR_STRENGTH + x1) = 1;
        }
        RAM8(BATTLE_TEMP_A4)--;
        x1 = (uint16_t)(x1 + 1);
    } while (RAM8(BATTLE_TEMP_A4) != 0);
    uint16_t value6 = RAM16(0x03BD);
    r->a = (a_hi1 << 8) | a;
    r->x = value6;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04BBE, SOM_RTS, "gen", reduce_and_clamp_actor_appearance_attributes, 0, L_B | L_X | L_Y, 1, 1, 0, 57, 28)
