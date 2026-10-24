#include "som_c.h"

/* C8EC3B queue_magic_absorb_spell   [class B, 122 bytes, 54 instructions]
 * Source: src/rom/queue_magic_absorb_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_magic_absorb_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(0xE1F8 + y) = 0x20;
    r->a = (a_hi << 8) | 0x20;
    r->x = battle_defender_ptr;
    JSR(c, 0xEC44, 0xC8E8A0); /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEC47, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    uint16_t y_ret2 = r->y;
    uint16_t value = RAM16(0x0396);
    uint16_t value2 = RAM16(0x0394);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        a1 = 0;
        a_hi1 = 0;
    }
    BUS16_SET(c, 0x004204, (a_hi1 << 8) | a1);
    BUS8_SET(c, 0x004206, 0x0A);
    if ((RAM8(ACTOR_MONSTER_TYPE + x_ret) & 0x40) != 0) {
        uint8_t value4 = BUS8(c, 0x004214);
        uint8_t a2;
        if (value4 != 0) {
            a2 = value4;
        } else {
            a2 = 1;
        }
        uint8_t value5 = RAM8(ACTOR_MP + y_ret2);
        uint8_t a3;
        if (a2 < value5) {
            a3 = a2;
        } else {
            a3 = value5;
        }
        RAM8(BATTLE_TEMP_A4) = a3;
        RAM8(ACTOR_PENDING_MP_DAMAGE + y_ret2) = (uint8_t)(RAM8(ACTOR_PENDING_MP_DAMAGE + y_ret2) + RAM8(BATTLE_TEMP_A4));
        uint8_t value7 = RAM8(ACTOR_PENDING_MP_HEAL + x_ret);
        uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
        RAM8(ACTOR_PENDING_MP_HEAL + x_ret) = (uint8_t)(value7 + battle_temp_a42);
        r->a = (a_hi1 << 8) | (uint8_t)(value7 + battle_temp_a42);
        r->c = value7 + battle_temp_a42 > 0xFF;
        r->z = (uint8_t)(value7 + battle_temp_a42) == 0;
        r->n = (uint8_t)(value7 + battle_temp_a42) & 0x80;
        r->v = ((value7 ^ (uint8_t)(value7 + battle_temp_a42)) & (battle_temp_a42 ^ (uint8_t)(value7 + battle_temp_a42)) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value8 = BUS8(c, 0x004214);
    uint8_t a4;
    if (value8 != 0) {
        a4 = value8;
    } else {
        a4 = 1;
    }
    uint8_t value9 = RAM8(ACTOR_MP + x_ret);
    uint8_t a5;
    if (a4 < value9) {
        a5 = a4;
    } else {
        a5 = value9;
    }
    RAM8(BATTLE_TEMP_A4) = a5;
    RAM8(ACTOR_PENDING_MP_DAMAGE + x_ret) = (uint8_t)(RAM8(ACTOR_PENDING_MP_DAMAGE + x_ret) + RAM8(BATTLE_TEMP_A4));
    uint8_t value11 = RAM8(ACTOR_PENDING_MP_HEAL + y_ret2);
    uint8_t battle_temp_a44 = RAM8(BATTLE_TEMP_A4);
    RAM8(ACTOR_PENDING_MP_HEAL + y_ret2) = (uint8_t)(value11 + battle_temp_a44);
    r->a = (a_hi1 << 8) | (uint8_t)(value11 + battle_temp_a44);
    r->c = value11 + battle_temp_a44 > 0xFF;
    r->z = (uint8_t)(value11 + battle_temp_a44) == 0;
    r->n = (uint8_t)(value11 + battle_temp_a44) & 0x80;
    r->v = ((value11 ^ (uint8_t)(value11 + battle_temp_a44)) & (battle_temp_a44 ^ (uint8_t)(value11 + battle_temp_a44)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EC3B, SOM_RTS, "gen", queue_magic_absorb_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 122, 54)
