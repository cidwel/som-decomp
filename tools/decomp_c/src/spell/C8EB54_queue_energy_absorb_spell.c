#include "som_c.h"

/* C8EB54 queue_energy_absorb_spell   [class B, 75 bytes, 33 instructions]
 * Source: src/rom/queue_energy_absorb_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_energy_absorb_spell(SomCtx *c)
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
    JSR(c, 0xEB5D, 0xC8E8A0); /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEB60, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t a_all2 = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret2 = r->y;
    uint8_t value = RAM8(ACTOR_MONSTER_TYPE + x_ret);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((value & 0x20) == 0) {
        a_hi1 = a_all2 >> 8;
        x1 = x_ret;
        y1 = y_ret2;
    } else {
        uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
        r->a = (a_all2 >> 8 << 8) | value;
        r->x = battle_attacker_ptr;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xEB70, 0xC8E990); /* calculate_spell_magic_defence_roll */
        uint16_t a_all3 = r->a;
        uint16_t battle_attacker_ptr2 = RAM16(BATTLE_ATTACKER_PTR);
        uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
        a_hi1 = a_all3 >> 8;
        x1 = battle_attacker_ptr2;
        y1 = battle_defender_ptr2;
    }
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    uint16_t value2 = RAM16(0x0394);
    uint8_t a1;
    uint8_t a_hi2;
    bool zero1;
    if (!((uint16_t)(battle_damage - value2) & 0x8000)) {
        a1 = (uint8_t)(battle_damage - value2);
        a_hi2 = (uint16_t)(battle_damage - value2) >> 8;
        zero1 = (uint16_t)(battle_damage - value2) == 0;
    } else {
        a1 = 1;
        a_hi2 = 0;
        zero1 = 0;
    }
    uint8_t a2;
    uint8_t a_hi3;
    if (!zero1) {
        a2 = a1;
        a_hi3 = a_hi2;
    } else {
        a2 = 1;
        a_hi3 = 0;
    }
    uint16_t value3 = RAM16(ACTOR_HP + x1);
    uint8_t a3;
    uint8_t a_hi4;
    if (((a_hi3 << 8) | a2) < value3) {
        a3 = a2;
        a_hi4 = a_hi3;
    } else {
        a3 = (uint8_t)value3;
        a_hi4 = value3 >> 8;
    }
    RAM16_SET(BATTLE_TEMP_A4, (a_hi4 << 8) | a3);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x1, (a_hi4 << 8) | a3);
    uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
    uint16_t value4 = RAM16(ACTOR_PENDING_HP_HEAL + y1);
    RAM16_SET(ACTOR_PENDING_HP_HEAL + y1, (uint16_t)(battle_temp_a4 + value4));
    r->a = (uint16_t)(battle_temp_a4 + value4);
    r->x = x1;
    r->y = y1;
    r->c = battle_temp_a4 + value4 > 0xFFFF;
    r->z = (uint16_t)(battle_temp_a4 + value4) == 0;
    r->n = (uint16_t)(battle_temp_a4 + value4) & 0x8000;
    r->v = ((battle_temp_a4 ^ (uint16_t)(battle_temp_a4 + value4)) & (value4 ^ (uint16_t)(battle_temp_a4 + value4)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EB54, SOM_RTS, "gen", queue_energy_absorb_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 75, 33)
