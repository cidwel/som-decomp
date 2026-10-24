#include "som_c.h"

/* C8E8C0 calculate_spell_attack_roll   [class B, 208 bytes, 102 instructions]
 * Source: src/rom/calculate_spell_attack_roll.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void calculate_spell_attack_roll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0xE8C2, 0xC8E990); /* calculate_spell_magic_defence_roll */
    uint8_t value = RAM8(0x0391);
    RAM8(BATTLE_ACCURACY_WORK) = value >> 2;
    uint8_t value2 = BUS8(c, (RAM8(0x03DE) << 0x10) + RAM16(0x03DC) + 0x2ADB);
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    uint8_t battle_accuracy_work = RAM8(BATTLE_ACCURACY_WORK);
    uint8_t a1;
    if ((uint8_t)(value2 + battle_accuracy_work) < 0x63) {
        a1 = (uint8_t)(value2 + battle_accuracy_work);
    } else {
        a1 = 0x63;
    }
    RAM8(BATTLE_ACCURACY_WORK) = a1;
    RAM8(0x03D4) = (uint8_t)(RAM8(0x0396) + value);
    RAM8(0x03D5) = 0;
    uint8_t value4 = RAM8(0x039D);
    RAM8(0x03D0) = (uint8_t)(value4 + 2);
    r->y = battle_attacker_ptr;
    r->v = ((value4 ^ (uint8_t)(value4 + 2)) & ((uint8_t)(value4 + 2) ^ 2) & 0x80) != 0;
    r->mf = true;
    r->xf = false;
    JSL(c, 0xE8EE, 0xC054B2); /* multiply_byte_by_word_long_wrapper */
    uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
    uint8_t a2;
    uint8_t a_hi1;
    if (battle_mul_work >> 1 < 0x03E7) {
        a2 = (uint8_t)(battle_mul_work >> 1);
        a_hi1 = battle_mul_work >> 1 >> 8;
    } else {
        a2 = 0xE7;
        a_hi1 = 3;
    }
    RAM16_SET(BATTLE_DAMAGE, (a_hi1 << 8) | a2);
    r->a = (a_hi1 << 8) | 0x65;
    r->c = battle_mul_work >> 1 >= 0x03E7;
    r->z = false;
    r->n = false;
    r->mf = true;
    r->xf = false;
    JSL(c, 0xE905, 0xC03884); /* random_below_long_wrapper */
    uint16_t a_all3 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    uint8_t battle_accuracy_work2 = RAM8(BATTLE_ACCURACY_WORK);
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    if ((uint8_t)a_all3 >= battle_accuracy_work2) {
        RAM16_SET(BATTLE_TEMP_A8, RAM16(BATTLE_DAMAGE));
        RAM8(BATTLE_TEMP_A6) = battle_accuracy_work2;
        r->mf = true;
        r->xf = false;
        JSL(c, 0xE94A, 0xC05437); /* multiply_byte_word_divide_by_100_long_wrapper */
        uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
        RAM16_SET(BATTLE_DAMAGE, battle_temp_a4);
        a_hi2 = battle_temp_a4 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
    } else {
        uint8_t value5 = RAM8(ACTOR_DAMAGE_BONUS_ROOT + y_ret2);
        BUS8_SET(c, 0x004202, value5);
        BUS8_SET(c, 0x004203, value5);
        uint16_t value6 = BUS16(c, 0x004216);
        uint16_t battle_damage2 = RAM16(BATTLE_DAMAGE);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(value6 + battle_damage2));
        r->a = (uint16_t)(value6 + battle_damage2) >> 4;
        r->c = (uint16_t)(value6 + battle_damage2) >> 3 & 0x01;
        r->z = (uint16_t)(value6 + battle_damage2) >> 4 == 0;
        r->n = (uint16_t)(value6 + battle_damage2) >> 4 & 0x8000;
        r->v = ((value6 ^ (uint16_t)(value6 + battle_damage2)) & (battle_damage2 ^ (uint16_t)(value6 + battle_damage2)) & 0x8000) != 0;
        r->mf = true;
        r->xf = false;
        JSL(c, 0xE930, 0xC03884); /* random_below_long_wrapper */
        uint16_t a_all5 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        uint16_t battle_damage3 = RAM16(BATTLE_DAMAGE);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)((a_all5 & 0xFF) + battle_damage3));
        a_hi2 = (uint16_t)((a_all5 & 0xFF) + battle_damage3) >> 8;
        x1 = x_ret3;
        y1 = y_ret3;
    }
    RAM16_SET(BATTLE_TEMP_A4, RAM16(0x038F) & 0xFF);
    uint8_t a3 = 0;
    uint8_t a_hi3 = 0;
    bool overflow1 = 0;
    do {
        uint16_t battle_damage4 = RAM16(BATTLE_DAMAGE);
        RAM16_SET(BATTLE_TEMP_A4, (uint16_t)(RAM16(BATTLE_TEMP_A4) - 1));
        uint8_t a3_next = (uint8_t)(((a_hi3 << 8) | a3) + battle_damage4);
        uint8_t a_hi3_next = (uint16_t)(((a_hi3 << 8) | a3) + battle_damage4) >> 8;
        bool overflow1_next = ((((a_hi3 << 8) | a3) ^ (uint16_t)(((a_hi3 << 8) | a3) + battle_damage4)) & (battle_damage4 ^ (uint16_t)(((a_hi3 << 8) | a3) + battle_damage4)) & 0x8000) != 0;
        a3 = a3_next;
        a_hi3 = a_hi3_next;
        overflow1 = overflow1_next;
    } while (RAM16(BATTLE_TEMP_A4) != 0);
    BUS16_SET(c, 0x004204, ((a_hi3 << 8) | a3) >> 1);
    BUS8_SET(c, 0x004206, RAM8(0xE176 + y1));
    uint16_t value9 = BUS16(c, 0x004214);
    uint8_t a4;
    uint8_t a_hi4;
    if (value9 < 0x03E7) {
        a4 = (uint8_t)value9;
        a_hi4 = value9 >> 8;
    } else {
        a4 = 0xE7;
        a_hi4 = 3;
    }
    RAM16_SET(BATTLE_DAMAGE, (a_hi4 << 8) | a4);
    RAM16_SET(0x0396, (a_hi4 << 8) | a4);
    RAM8(0x039C) = (uint8_t)(((a_hi4 << 8) | a4) >> 2);
    r->a = ((a_hi4 << 8) | a4) >> 2;
    r->x = x1;
    r->y = y1;
    r->c = ((a_hi4 << 8) | a4) >> 1 & 0x01;
    r->z = ((a_hi4 << 8) | a4) >> 2 == 0;
    r->n = ((a_hi4 << 8) | a4) >> 2 & 0x8000;
    r->v = overflow1;
    r->mf = true;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E8C0, SOM_RTS, "hand", calculate_spell_attack_roll, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 208, 102)
