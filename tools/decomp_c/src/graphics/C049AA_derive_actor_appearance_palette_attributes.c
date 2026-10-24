#include "som_c.h"

/* C049AA derive_actor_appearance_palette_attributes   [class B, 98 bytes, 49 instructions]
 * Source: src/rom/derive_actor_appearance_palette_attributes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void derive_actor_appearance_palette_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(BATTLE_TEMP_A4) = RAM8(ACTOR_AGILITY + x) >> 2;
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1007, value2);
    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
    uint8_t a1;
    if ((uint8_t)(value2 + battle_temp_a4) < 0x63) {
        a1 = (uint8_t)(value2 + battle_temp_a4);
    } else {
        a1 = 0x63;
    }
    RAM8(ACTOR_ACCURACY + x) = a1;
    uint8_t value3;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1008, value3);
    RAM8(ACTOR_ATTACK_POWER + x) = (uint8_t)(value3 + RAM8(ACTOR_STRENGTH + x));
    uint16_t value5 = RAM16(0xCC78);
    uint8_t a_hi2;
    if (value5 != 0) {
        a_hi2 = value5 >> 8;
    } else {
        uint8_t value6 = RAM8(ACTOR_SABER_HITS_LEFT + x);
        uint8_t a_hi1;
        if (value6 != 0) {
            a_hi1 = value5 >> 8;
        } else {
            RAM8(ACTOR_WEAPON_FLAGS + x) = 0;
            uint16_t value7;
            BUS16_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1009, value7);
            RAM16_SET(ACTOR_INFLICTED_STATUS + x, value7);
            a_hi1 = value7 >> 8;
        }
        a_hi2 = a_hi1;
    }
    uint8_t value8;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1005, value8);
    RAM8(ACTOR_WEAPON_MASK + x) = value8;
    uint8_t value9;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1000, value9);
    RAM8(BATTLE_TEMP_A4) = value9;
    r->a = (r->a & 0x00FF) | (a_hi2 << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC049AA, SOM_RTS, "hand", derive_actor_appearance_palette_attributes, 0, L_B | L_X | L_Y, 2, 1, 0, 98, 49)
