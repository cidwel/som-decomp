#include "som_c.h"

/* C051E7 calculate_physical_attack_roll   [class B, 256 bytes, 124 instructions]
 * Source: src/rom/calculate_physical_attack_roll.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void calculate_physical_attack_roll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if (RAM8(BATTLE_ATTACKER_SLOT) == 0) {
        uint8_t value = RAM8(0xCC76);
        if (value != 0) {
            RAM8(ACTOR_CHARGE_STAGE + y) = (uint8_t)(value + RAM8(ACTOR_CHARGE_STAGE + y));
        }
    }
    RAM8(0x03D4) = RAM8(ACTOR_ATTACK_POWER + y);
    RAM8(0x03D5) = 0;
    uint8_t value4 = RAM8(ACTOR_CHARGE_STAGE + y);
    RAM8(0x039D) = (uint8_t)(value4 << 1);
    RAM8(0x03D0) = (uint8_t)((uint8_t)(value4 << 1) + 4);
    { const uint16_t sp_call = r->sp; JSR(c, 0x520D, 0xC054B6); GUARD_JSR(c, sp_call, 0x520D); } /* multiply_byte_by_word */
    uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
    RAM16_SET(BATTLE_DAMAGE, battle_mul_work >> 2);
    BUS16_SET(c, 0x004204, battle_mul_work >> 2);
    RAM16_SET(BATTLE_TEMP_AE, battle_mul_work >> 4);
    uint16_t value5 = RAM16(ACTOR_BUFF_FLAGS + y);
    uint8_t a_hi2;
    if ((value5 & 0x80) == 0) {
        uint8_t a_hi1;
        if ((value5 & 0x40) == 0) {
            a_hi1 = value5 >> 8;
        } else {
            uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
            uint16_t battle_temp_ae = RAM16(BATTLE_TEMP_AE);
            RAM16_SET(BATTLE_DAMAGE, (uint16_t)(battle_damage + battle_temp_ae));
            a_hi1 = (uint16_t)(battle_damage + battle_temp_ae) >> 8;
        }
        a_hi2 = a_hi1;
    } else {
        uint16_t battle_damage2 = RAM16(BATTLE_DAMAGE);
        uint16_t battle_temp_ae2 = RAM16(BATTLE_TEMP_AE);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(battle_damage2 - battle_temp_ae2));
        a_hi2 = (uint16_t)(battle_damage2 - battle_temp_ae2) >> 8;
    }
    uint8_t value6 = RAM8(ACTOR_SABER_AND_CRIT_COUNTER + y);
    bool m_flag;
    uint8_t a_hi3;
    if ((value6 & 0x0F) == 0) {
        m_flag = 1;
        a_hi3 = a_hi2;
    } else {
        RAM8(BATTLE_TEMP_A4) = value6 & 0x0F;
        BUS8_SET(c, 0x004206, (uint8_t)(0x0A - RAM8(BATTLE_TEMP_A4)));
        uint16_t value7 = BUS16(c, 0x004214);
        uint16_t battle_damage3 = RAM16(BATTLE_DAMAGE);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(value7 + battle_damage3));
        m_flag = 0;
        a_hi3 = (uint16_t)(value7 + battle_damage3) >> 8;
    }
    RAM16_SET(BATTLE_TEMP_A4, RAM16(0x038F) & 0xFF);
    uint8_t a1 = 0;
    uint8_t a_hi4 = 0;
    bool overflow1 = 0;
    do {
        uint16_t battle_damage4 = RAM16(BATTLE_DAMAGE);
        RAM16_SET(BATTLE_TEMP_A4, (uint16_t)(RAM16(BATTLE_TEMP_A4) - 1));
        uint8_t a1_next = (uint8_t)(((a_hi4 << 8) | a1) + battle_damage4);
        uint8_t a_hi4_next = (uint16_t)(((a_hi4 << 8) | a1) + battle_damage4) >> 8;
        bool overflow1_next = ((((a_hi4 << 8) | a1) ^ (uint16_t)(((a_hi4 << 8) | a1) + battle_damage4)) & (battle_damage4 ^ (uint16_t)(((a_hi4 << 8) | a1) + battle_damage4)) & 0x8000) != 0;
        a1 = a1_next;
        a_hi4 = a_hi4_next;
        overflow1 = overflow1_next;
    } while (RAM16(BATTLE_TEMP_A4) != 0);
    uint8_t a2;
    uint8_t a_hi5;
    if (((a_hi4 << 8) | a1) >> 1 < 0x03E7) {
        a2 = (uint8_t)(((a_hi4 << 8) | a1) >> 1);
        a_hi5 = ((a_hi4 << 8) | a1) >> 1 >> 8;
    } else {
        a2 = 0xE7;
        a_hi5 = 3;
    }
    RAM16_SET(BATTLE_DAMAGE, (a_hi5 << 8) | a2);
    uint16_t value9 = RAM16(ACTOR_STATUS_HIGH + y);
    uint8_t a_hi6;
    if ((value9 & 2) == 0) {
        a_hi6 = value9 >> 8;
    } else {
        RAM16_SET(BATTLE_DAMAGE, 1);
        a_hi6 = 0;
    }
    r->a = (a_hi6 << 8) | 0x65;
    r->x = x;
    r->y = y;
    r->c = ((a_hi4 << 8) | a1) >> 1 >= 0x03E7;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5293, 0xC03884); GUARD_JSL(c, sp_call, 0x5293); } /* random_below_long_wrapper */
    bool m_ret = r->mf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (m_ret) {
        uint8_t battle_accuracy_work = RAM8(BATTLE_ACCURACY_WORK);
        bool x_flag;
        uint8_t a3;
        uint8_t a_hi7;
        uint16_t x1;
        uint16_t y1;
        bool overflow2;
        if ((uint8_t)a_all2 >= battle_accuracy_work) {
            RAM8(BATTLE_TEMP_A6) = battle_accuracy_work;
            RAM16_SET(BATTLE_TEMP_A8, RAM16(BATTLE_DAMAGE));
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x52D3, 0xC0543B); GUARD_JSR(c, sp_call, 0x52D3); } /* multiply_byte_word_divide_by_100 */
            bool x_ret3 = r->xf;
            bool overflow_ret3 = r->v;
            uint16_t battle_temp_a42 = RAM16(BATTLE_TEMP_A4);
            x_flag = x_ret3;
            a3 = (uint8_t)battle_temp_a42;
            a_hi7 = battle_temp_a42 >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            overflow2 = overflow_ret3;
        } else {
            uint8_t value10 = RAM8(ACTOR_DAMAGE_BONUS_ROOT + y_ret);
            BUS8_SET(c, 0x004202, value10);
            BUS8_SET(c, 0x004203, value10);
            uint16_t value11 = BUS16(c, 0x004216);
            uint16_t battle_damage6 = RAM16(BATTLE_DAMAGE);
            RAM16_SET(BATTLE_DAMAGE, (uint16_t)(value11 + battle_damage6));
            r->a = (uint16_t)(value11 + battle_damage6) >> 4;
            r->c = (uint16_t)(value11 + battle_damage6) >> 3 & 0x01;
            r->z = (uint16_t)(value11 + battle_damage6) >> 4 == 0;
            r->n = (uint16_t)(value11 + battle_damage6) >> 4 & 0x8000;
            r->v = ((value11 ^ (uint16_t)(value11 + battle_damage6)) & (battle_damage6 ^ (uint16_t)(value11 + battle_damage6)) & 0x8000) != 0;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x52BA, 0xC03884); GUARD_JSL(c, sp_call, 0x52BA); } /* random_below_long_wrapper */
            bool x_ret4 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            uint16_t battle_damage7 = RAM16(BATTLE_DAMAGE);
            x_flag = x_ret4;
            a3 = (uint8_t)((a_all4 & 0xFF) + battle_damage7);
            a_hi7 = (uint16_t)((a_all4 & 0xFF) + battle_damage7) >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            overflow2 = (((a_all4 & 0xFF) ^ (uint16_t)((a_all4 & 0xFF) + battle_damage7)) & (battle_damage7 ^ (uint16_t)((a_all4 & 0xFF) + battle_damage7)) & 0x8000) != 0;
        }
        uint8_t a4;
        uint8_t a_hi8;
        if (((a_hi7 << 8) | a3) < 0x03E7) {
            a4 = a3;
            a_hi8 = a_hi7;
        } else {
            a4 = 0xE7;
            a_hi8 = 3;
        }
        RAM16_SET(BATTLE_DAMAGE, (a_hi8 << 8) | a4);
        RAM16_SET(0x0396, (a_hi8 << 8) | a4);
        r->a = (a_hi8 << 8) | a4;
        r->x = x1;
        r->y = y1;
        r->c = ((a_hi7 << 8) | a3) >= 0x03E7;
        r->v = overflow2;
        r->mf = 1;
        r->xf = x_flag;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t battle_accuracy_work2 = RAM16(BATTLE_ACCURACY_WORK);
        bool x_flag2;
        uint8_t a5;
        uint8_t a_hi9;
        uint16_t x2;
        uint16_t y2;
        bool overflow3;
        if (a_all2 >= battle_accuracy_work2) {
            RAM16_SET(BATTLE_TEMP_A6, battle_accuracy_work2);
            RAM16_SET(BATTLE_TEMP_A8, RAM16(BATTLE_DAMAGE));
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x52D3, 0xC0543B); GUARD_JSR(c, sp_call, 0x52D3); } /* multiply_byte_word_divide_by_100 */
            bool x_ret6 = r->xf;
            bool overflow_ret5 = r->v;
            uint16_t battle_temp_a43 = RAM16(BATTLE_TEMP_A4);
            x_flag2 = x_ret6;
            a5 = (uint8_t)battle_temp_a43;
            a_hi9 = battle_temp_a43 >> 8;
            x2 = x_ret2;
            y2 = y_ret;
            overflow3 = overflow_ret5;
        } else {
            uint16_t value12 = RAM16(ACTOR_DAMAGE_BONUS_ROOT + y_ret);
            BUS16_SET(c, 0x004202, value12);
            BUS16_SET(c, 0x004203, value12);
            uint16_t value13 = BUS16(c, 0x004216);
            uint16_t battle_damage9 = RAM16(BATTLE_DAMAGE);
            RAM16_SET(BATTLE_DAMAGE, (uint16_t)(value13 + battle_damage9));
            r->a = (uint16_t)(value13 + battle_damage9) >> 4;
            r->c = (uint16_t)(value13 + battle_damage9) >> 3 & 0x01;
            r->z = (uint16_t)(value13 + battle_damage9) >> 4 == 0;
            r->n = (uint16_t)(value13 + battle_damage9) >> 4 & 0x8000;
            r->v = ((value13 ^ (uint16_t)(value13 + battle_damage9)) & (battle_damage9 ^ (uint16_t)(value13 + battle_damage9)) & 0x8000) != 0;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x52BA, 0xC03884); GUARD_JSL(c, sp_call, 0x52BA); } /* random_below_long_wrapper */
            bool x_ret7 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret3 = r->y;
            uint16_t battle_damage10 = RAM16(BATTLE_DAMAGE);
            x_flag2 = x_ret7;
            a5 = (uint8_t)((a_all6 & 0xFF) + battle_damage10);
            a_hi9 = (uint16_t)((a_all6 & 0xFF) + battle_damage10) >> 8;
            x2 = x_ret8;
            y2 = y_ret3;
            overflow3 = (((a_all6 & 0xFF) ^ (uint16_t)((a_all6 & 0xFF) + battle_damage10)) & (battle_damage10 ^ (uint16_t)((a_all6 & 0xFF) + battle_damage10)) & 0x8000) != 0;
        }
        uint8_t a6;
        uint8_t a_hi10;
        if (((a_hi9 << 8) | a5) < 0x03E7) {
            a6 = a5;
            a_hi10 = a_hi9;
        } else {
            a6 = 0xE7;
            a_hi10 = 3;
        }
        RAM16_SET(BATTLE_DAMAGE, (a_hi10 << 8) | a6);
        RAM16_SET(0x0396, (a_hi10 << 8) | a6);
        r->a = (a_hi10 << 8) | a6;
        r->x = x2;
        r->y = y2;
        r->c = ((a_hi9 << 8) | a5) >= 0x03E7;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag2;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC051E7, SOM_RTS, "gen", calculate_physical_attack_roll, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 256, 124)
