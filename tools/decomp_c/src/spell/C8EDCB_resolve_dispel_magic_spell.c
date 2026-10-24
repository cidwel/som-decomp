#include "som_c.h"

/* C8EDCB resolve_dispel_magic_spell   [class B, 236 bytes, 107 instructions]
 * Source: src/rom/resolve_dispel_magic_spell.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_dispel_magic_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t a_hi_ee08 = 0;
    uint8_t x_ee08 = 0;
    uint8_t y_ee08 = 0;
    uint8_t a_hi_ee082 = 0;
    uint16_t x_ee082 = 0;
    uint16_t y_ee082 = 0;
    uint8_t a_hi_ede4 = 0;
    uint8_t x_ede4 = 0;
    uint8_t y_ede4 = 0;
    bool carry_ede4 = 0;
    bool overflow_ede4 = 0;
    uint8_t a_hi_ede42 = 0;
    uint16_t x_ede42 = 0;
    uint16_t y_ede42 = 0;
    bool carry_ede42 = 0;
    bool overflow_ede42 = 0;
    uint8_t a_ee1c = 0;
    uint8_t a_hi_ee1c = 0;
    uint8_t x_ee1c = 0;
    uint8_t y_ee1c = 0;
    uint8_t a_ee1c2 = 0;
    uint8_t a_hi_ee1c2 = 0;
    uint16_t x_ee1c2 = 0;
    uint16_t y_ee1c2 = 0;
    uint8_t a_hi_ee8d = 0;
    uint8_t x_ee8d = 0;
    uint8_t y_ee8d = 0;
    bool carry_ee8d = 0;
    bool overflow_ee8d = 0;
    uint8_t a_hi_ee8d2 = 0;
    uint16_t x_ee8d2 = 0;
    uint16_t y_ee8d2 = 0;
    bool carry_ee8d2 = 0;
    bool overflow_ee8d2 = 0;
    uint8_t a_ee2a = 0;
    uint8_t a_hi_ee2a = 0;
    uint8_t x_ee2a = 0;
    uint8_t y_ee2a = 0;
    bool zero_ee2a = 0;
    uint8_t a_ee2a2 = 0;
    uint8_t a_hi_ee2a2 = 0;
    uint16_t x_ee2a2 = 0;
    uint16_t y_ee2a2 = 0;
    bool zero_ee2a2 = 0;
    uint8_t a_hi_ee9a = 0;
    uint8_t x_ee9a = 0;
    uint8_t y_ee9a = 0;
    bool carry_ee9a = 0;
    bool overflow_ee9a = 0;
    uint8_t a_hi_ee9a2 = 0;
    uint16_t x_ee9a2 = 0;
    uint16_t y_ee9a2 = 0;
    bool carry_ee9a2 = 0;
    bool overflow_ee9a2 = 0;
    uint8_t a_ee2e = 0;
    uint8_t a_hi_ee2e = 0;
    uint8_t x_ee2e = 0;
    uint8_t y_ee2e = 0;
    uint8_t a_ee2e2 = 0;
    uint8_t a_hi_ee2e2 = 0;
    uint16_t x_ee2e2 = 0;
    uint16_t y_ee2e2 = 0;
    uint8_t a_hi_eeab = 0;
    uint8_t x_eeab = 0;
    uint8_t y_eeab = 0;
    bool carry_eeab = 0;
    bool overflow_eeab = 0;
    uint16_t direct_page_eeab = 0;
    uint8_t data_bank_eeab = 0;
    uint8_t a_hi_eeab2 = 0;
    uint16_t x_eeab2 = 0;
    uint16_t y_eeab2 = 0;
    bool carry_eeab2 = 0;
    bool overflow_eeab2 = 0;
    uint16_t direct_page_eeab2 = 0;
    uint8_t data_bank_eeab2 = 0;
    uint8_t a_ee3b = 0;
    uint8_t a_hi_ee3b = 0;
    uint8_t x_ee3b = 0;
    uint8_t y_ee3b = 0;
    bool zero_ee3b = 0;
    uint8_t a_ee3b2 = 0;
    uint8_t a_hi_ee3b2 = 0;
    uint16_t x_ee3b2 = 0;
    uint16_t y_ee3b2 = 0;
    bool zero_ee3b2 = 0;
    uint8_t a_eeb6 = 0;
    uint8_t a_hi_eeb6 = 0;
    uint8_t x_eeb6 = 0;
    uint8_t y_eeb6 = 0;
    bool carry_eeb6 = 0;
    bool zero_eeb6 = 0;
    bool negative_eeb6 = 0;
    bool overflow_eeb6 = 0;
    uint16_t direct_page_eeb6 = 0;
    uint8_t data_bank_eeb6 = 0;
    uint8_t a_eeb62 = 0;
    uint8_t a_hi_eeb62 = 0;
    uint16_t x_eeb62 = 0;
    uint16_t y_eeb62 = 0;
    bool carry_eeb62 = 0;
    bool zero_eeb62 = 0;
    bool negative_eeb62 = 0;
    bool overflow_eeb62 = 0;
    uint16_t direct_page_eeb62 = 0;
    uint8_t data_bank_eeb62 = 0;
    uint8_t a_ee3f = 0;
    uint8_t a_hi_ee3f = 0;
    uint8_t x_ee3f = 0;
    uint8_t y_ee3f = 0;
    uint8_t a_ee3f2 = 0;
    uint8_t a_hi_ee3f2 = 0;
    uint16_t x_ee3f2 = 0;
    uint16_t y_ee3f2 = 0;
    uint8_t a_ee4c = 0;
    uint8_t a_hi_ee4c = 0;
    uint8_t x_ee4c = 0;
    uint8_t y_ee4c = 0;
    bool zero_ee4c = 0;
    uint8_t a_ee4c2 = 0;
    uint8_t a_hi_ee4c2 = 0;
    uint16_t x_ee4c2 = 0;
    uint16_t y_ee4c2 = 0;
    bool zero_ee4c2 = 0;
    uint8_t a_ee50 = 0;
    uint8_t a_hi_ee50 = 0;
    uint8_t x_ee50 = 0;
    uint8_t y_ee50 = 0;
    uint8_t a_ee502 = 0;
    uint8_t a_hi_ee502 = 0;
    uint16_t x_ee502 = 0;
    uint16_t y_ee502 = 0;
    uint8_t a_ee5d = 0;
    uint8_t a_hi_ee5d = 0;
    uint8_t x_ee5d = 0;
    uint8_t y_ee5d = 0;
    bool zero_ee5d = 0;
    uint8_t a_ee5d2 = 0;
    uint8_t a_hi_ee5d2 = 0;
    uint16_t x_ee5d2 = 0;
    uint16_t y_ee5d2 = 0;
    bool zero_ee5d2 = 0;
    uint8_t a_ee61 = 0;
    uint8_t a_hi_ee61 = 0;
    uint8_t x_ee61 = 0;
    uint8_t y_ee61 = 0;
    uint8_t a_ee612 = 0;
    uint8_t a_hi_ee612 = 0;
    uint16_t x_ee612 = 0;
    uint16_t y_ee612 = 0;
    uint8_t a_ee77 = 0;
    uint8_t a_hi_ee77 = 0;
    uint8_t x_ee77 = 0;
    uint8_t y_ee77 = 0;
    uint8_t a_ee772 = 0;
    uint8_t a_hi_ee772 = 0;
    uint16_t x_ee772 = 0;
    uint16_t y_ee772 = 0;
    uint8_t a_ee8a = 0;
    uint8_t a_hi_ee8a = 0;
    uint8_t x_ee8a = 0;
    uint8_t y_ee8a = 0;
    bool carry_ee8a = 0;
    bool overflow_ee8a = 0;
    uint8_t a_ee8a2 = 0;
    uint8_t a_hi_ee8a2 = 0;
    uint16_t x_ee8a2 = 0;
    uint16_t y_ee8a2 = 0;
    bool carry_ee8a2 = 0;
    bool overflow_ee8a2 = 0;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(ACTOR_CHARGE_STAGE + battle_defender_ptr) = 0;
    r->x = battle_defender_ptr;
    r->z = battle_defender_ptr == 0;
    r->n = battle_defender_ptr & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEDD2, 0xC8E8A0); GUARD_JSR(c, sp_call, 0xEDD2); } /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEDD5, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xEDD5); } /* calculate_spell_attack_roll */
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    RAM8(0xE1FA + x_ret2) |= 4;
    uint8_t value2 = RAM8(0x039D);
    if (value2 != 8) {
        if (value2 < 4) {
            if (x_ret) {
                a_hi_ee08 = a_all2 >> 8;
                x_ee08 = (uint8_t)x_ret2;
                y_ee08 = (uint8_t)y_ret2;
                goto shared_EE08;
            } else {
                a_hi_ee082 = a_all2 >> 8;
                x_ee082 = x_ret2;
                y_ee082 = y_ret2;
                goto shared_EE08_1;
            }
        }
        uint8_t value3 = RAM8(0xE176 + y_ret2);
        if (value3 != 1) {
            if (x_ret) {
                a_hi_ee08 = a_all2 >> 8;
                x_ee08 = (uint8_t)x_ret2;
                y_ee08 = (uint8_t)y_ret2;
                goto shared_EE08;
            } else {
                a_hi_ee082 = a_all2 >> 8;
                x_ee082 = x_ret2;
                y_ee082 = y_ret2;
                goto shared_EE08_1;
            }
        }
        if (x_ret) {
            a_hi_ede4 = a_all2 >> 8;
            x_ede4 = (uint8_t)x_ret2;
            y_ede4 = (uint8_t)y_ret2;
            carry_ede4 = value3 >= 1;
            overflow_ede4 = overflow_ret2;
            goto shared_EDE4;
        } else {
            a_hi_ede42 = a_all2 >> 8;
            x_ede42 = x_ret2;
            y_ede42 = y_ret2;
            carry_ede42 = value3 >= 1;
            overflow_ede42 = overflow_ret2;
            goto shared_EDE4_1;
        }
    }
    if (x_ret) {
        a_hi_ede4 = a_all2 >> 8;
        x_ede4 = (uint8_t)x_ret2;
        y_ede4 = (uint8_t)y_ret2;
        carry_ede4 = value2 >= 8;
        overflow_ede4 = overflow_ret2;
        goto shared_EDE4;
    } else {
        a_hi_ede42 = a_all2 >> 8;
        x_ede42 = x_ret2;
        y_ede42 = y_ret2;
        carry_ede42 = value2 >= 8;
        overflow_ede42 = overflow_ret2;
        goto shared_EDE4_1;
    }
    shared_EE08:;
    RAM16_SET(BATTLE_TEMP_A4, RAM16(ACTOR_MAGIC_DEFENSE + x_ee08) >> 1);
    uint16_t value5 = RAM16(0x0396);
    uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
    if (value5 >> 2 >= battle_temp_a4) {
        a_ee1c = (uint8_t)((value5 >> 2) - battle_temp_a4);
        a_hi_ee1c = (uint16_t)((value5 >> 2) - battle_temp_a4) >> 8;
        x_ee1c = x_ee08;
        y_ee1c = y_ee08;
        goto shared_EE1C;
    }
    a_ee1c = 0;
    a_hi_ee1c = 0;
    x_ee1c = x_ee08;
    y_ee1c = y_ee08;
    goto shared_EE1C;
    shared_EE08_1:;
    RAM16_SET(BATTLE_TEMP_A4, RAM16(ACTOR_MAGIC_DEFENSE + x_ee082) >> 1);
    uint16_t value7 = RAM16(0x0396);
    uint16_t battle_temp_a42 = RAM16(BATTLE_TEMP_A4);
    if (value7 >> 2 >= battle_temp_a42) {
        a_ee1c2 = (uint8_t)((value7 >> 2) - battle_temp_a42);
        a_hi_ee1c2 = (uint16_t)((value7 >> 2) - battle_temp_a42) >> 8;
        x_ee1c2 = x_ee082;
        y_ee1c2 = y_ee082;
        goto shared_EE1C_1;
    }
    a_ee1c2 = 0;
    a_hi_ee1c2 = 0;
    x_ee1c2 = x_ee082;
    y_ee1c2 = y_ee082;
    goto shared_EE1C_1;
    shared_EDE4:;
    RAM8(0xE1B7 + x_ede4) = 1;
    RAM8(0xE1BA + x_ede4) = 1;
    RAM8(0xE1BB + x_ede4) = 1;
    RAM8(0xE1BC + x_ede4) = 1;
    RAM8(ACTOR_SABER_HITS_LEFT + x_ede4) = 0;
    RAM8(0xE1B8 + x_ede4) = 0;
    a_hi_ee8d = a_hi_ede4;
    x_ee8d = x_ede4;
    y_ee8d = y_ede4;
    carry_ee8d = carry_ede4;
    overflow_ee8d = overflow_ede4;
    goto shared_EE8D;
    shared_EDE4_1:;
    RAM8(0xE1B7 + x_ede42) = 1;
    RAM8(0xE1BA + x_ede42) = 1;
    RAM8(0xE1BB + x_ede42) = 1;
    RAM8(0xE1BC + x_ede42) = 1;
    RAM8(ACTOR_SABER_HITS_LEFT + x_ede42) = 0;
    RAM8(0xE1B8 + x_ede42) = 0;
    a_hi_ee8d2 = a_hi_ede42;
    x_ee8d2 = x_ede42;
    y_ee8d2 = y_ede42;
    carry_ee8d2 = carry_ede42;
    overflow_ee8d2 = overflow_ede42;
    goto shared_EE8D_1;
    shared_EE1C:;
    RAM8(BATTLE_TEMP_A4) = a_ee1c;
    uint8_t value8 = RAM8(0xE1B7 + x_ee1c);
    uint8_t battle_temp_a43 = RAM8(BATTLE_TEMP_A4);
    if (value8 >= battle_temp_a43) {
        a_ee2a = (uint8_t)(value8 - battle_temp_a43);
        a_hi_ee2a = a_hi_ee1c;
        x_ee2a = x_ee1c;
        y_ee2a = y_ee1c;
        zero_ee2a = (uint8_t)(value8 - battle_temp_a43) == 0;
        goto shared_EE2A;
    }
    a_ee2a = 0;
    a_hi_ee2a = a_hi_ee1c;
    x_ee2a = x_ee1c;
    y_ee2a = y_ee1c;
    zero_ee2a = 1;
    goto shared_EE2A;
    shared_EE1C_1:;
    RAM8(BATTLE_TEMP_A4) = a_ee1c2;
    uint8_t value9 = RAM8(0xE1B7 + x_ee1c2);
    uint8_t battle_temp_a44 = RAM8(BATTLE_TEMP_A4);
    if (value9 >= battle_temp_a44) {
        a_ee2a2 = (uint8_t)(value9 - battle_temp_a44);
        a_hi_ee2a2 = a_hi_ee1c2;
        x_ee2a2 = x_ee1c2;
        y_ee2a2 = y_ee1c2;
        zero_ee2a2 = (uint8_t)(value9 - battle_temp_a44) == 0;
        goto shared_EE2A_1;
    }
    a_ee2a2 = 0;
    a_hi_ee2a2 = a_hi_ee1c2;
    x_ee2a2 = x_ee1c2;
    y_ee2a2 = y_ee1c2;
    zero_ee2a2 = 1;
    goto shared_EE2A_1;
    shared_EE8D:;
    if (RAM8(0xE1B8 + x_ee8d) != 0) {
        a_hi_ee9a = a_hi_ee8d;
        x_ee9a = x_ee8d;
        y_ee9a = y_ee8d;
        carry_ee9a = carry_ee8d;
        overflow_ee9a = overflow_ee8d;
        goto shared_EE9A;
    }
    RAM8(ACTOR_GUARD_FLAGS + x_ee8d) &= 0xBF;
    a_hi_ee9a = a_hi_ee8d;
    x_ee9a = x_ee8d;
    y_ee9a = y_ee8d;
    carry_ee9a = carry_ee8d;
    overflow_ee9a = overflow_ee8d;
    goto shared_EE9A;
    shared_EE8D_1:;
    if (RAM8(0xE1B8 + x_ee8d2) != 0) {
        a_hi_ee9a2 = a_hi_ee8d2;
        x_ee9a2 = x_ee8d2;
        y_ee9a2 = y_ee8d2;
        carry_ee9a2 = carry_ee8d2;
        overflow_ee9a2 = overflow_ee8d2;
        goto shared_EE9A_1;
    }
    RAM8(ACTOR_GUARD_FLAGS + x_ee8d2) &= 0xBF;
    a_hi_ee9a2 = a_hi_ee8d2;
    x_ee9a2 = x_ee8d2;
    y_ee9a2 = y_ee8d2;
    carry_ee9a2 = carry_ee8d2;
    overflow_ee9a2 = overflow_ee8d2;
    goto shared_EE9A_1;
    shared_EE2A:;
    if (!zero_ee2a) {
        a_ee2e = a_ee2a;
        a_hi_ee2e = a_hi_ee2a;
        x_ee2e = x_ee2a;
        y_ee2e = y_ee2a;
        goto shared_EE2E;
    }
    a_ee2e = 1;
    a_hi_ee2e = a_hi_ee2a;
    x_ee2e = x_ee2a;
    y_ee2e = y_ee2a;
    goto shared_EE2E;
    shared_EE2A_1:;
    if (!zero_ee2a2) {
        a_ee2e2 = a_ee2a2;
        a_hi_ee2e2 = a_hi_ee2a2;
        x_ee2e2 = x_ee2a2;
        y_ee2e2 = y_ee2a2;
        goto shared_EE2E_1;
    }
    a_ee2e2 = 1;
    a_hi_ee2e2 = a_hi_ee2a2;
    x_ee2e2 = x_ee2a2;
    y_ee2e2 = y_ee2a2;
    goto shared_EE2E_1;
    shared_EE9A:;
    if (RAM8(ACTOR_SABER_HITS_LEFT + x_ee9a) != 0) {
        a_hi_eeab = a_hi_ee9a;
        x_eeab = x_ee9a;
        y_eeab = y_ee9a;
        carry_eeab = carry_ee9a;
        overflow_eeab = overflow_ee9a;
        direct_page_eeab = 0x0300;
        data_bank_eeab = 0x7E;
        goto shared_EEAB;
    }
    uint8_t value15 = RAM8(0xE1FA + x_ee9a);
    RAM8(0xE1FA + x_ee9a) = value15 | 4;
    r->a = (a_hi_ee9a << 8) | (value15 | 4);
    r->x = x_ee9a;
    r->y = y_ee9a;
    r->c = carry_ee9a;
    r->z = (value15 | 4) == 0;
    r->n = (value15 | 4) & 0x80;
    r->v = overflow_ee9a;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEEAA, 0xC04530); GUARD_JSL(c, sp_call, 0xEEAA); } /* rebuild_actor_attributes_native */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret3 = r->v;
    if (x_ret3) {
        a_hi_eeab = a_all3 >> 8;
        x_eeab = (uint8_t)x_ret4;
        y_eeab = (uint8_t)y_ret3;
        carry_eeab = carry_ret2;
        overflow_eeab = overflow_ret3;
        direct_page_eeab = dp_ret;
        data_bank_eeab = db_ret;
        goto shared_EEAB;
    } else {
        a_hi_eeab2 = a_all3 >> 8;
        x_eeab2 = x_ret4;
        y_eeab2 = y_ret3;
        carry_eeab2 = carry_ret2;
        overflow_eeab2 = overflow_ret3;
        direct_page_eeab2 = dp_ret;
        data_bank_eeab2 = db_ret;
        goto shared_EEAB_1;
    }
    shared_EE9A_1:;
    if (RAM8(ACTOR_SABER_HITS_LEFT + x_ee9a2) != 0) {
        a_hi_eeab2 = a_hi_ee9a2;
        x_eeab2 = x_ee9a2;
        y_eeab2 = y_ee9a2;
        carry_eeab2 = carry_ee9a2;
        overflow_eeab2 = overflow_ee9a2;
        direct_page_eeab2 = 0x0300;
        data_bank_eeab2 = 0x7E;
        goto shared_EEAB_1;
    }
    uint8_t value17 = RAM8(0xE1FA + x_ee9a2);
    RAM8(0xE1FA + x_ee9a2) = value17 | 4;
    r->a = (a_hi_ee9a2 << 8) | (value17 | 4);
    r->x = x_ee9a2;
    r->y = y_ee9a2;
    r->c = carry_ee9a2;
    r->z = (value17 | 4) == 0;
    r->n = (value17 | 4) & 0x80;
    r->v = overflow_ee9a2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEEAA, 0xC04530); GUARD_JSL(c, sp_call, 0xEEAA); } /* rebuild_actor_attributes_native */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret5 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret4 = r->v;
    if (x_ret5) {
        a_hi_eeab = a_all4 >> 8;
        x_eeab = (uint8_t)x_ret6;
        y_eeab = (uint8_t)y_ret4;
        carry_eeab = carry_ret3;
        overflow_eeab = overflow_ret4;
        direct_page_eeab = dp_ret2;
        data_bank_eeab = db_ret2;
        goto shared_EEAB;
    } else {
        a_hi_eeab2 = a_all4 >> 8;
        x_eeab2 = x_ret6;
        y_eeab2 = y_ret4;
        carry_eeab2 = carry_ret3;
        overflow_eeab2 = overflow_ret4;
        direct_page_eeab2 = dp_ret2;
        data_bank_eeab2 = db_ret2;
        goto shared_EEAB_1;
    }
    shared_EE2E:;
    RAM8(0xE1B7 + x_ee2e) = a_ee2e;
    uint8_t value18 = RAM8(0xE1BA + x_ee2e);
    uint8_t battle_temp_a45 = RAM8(BATTLE_TEMP_A4);
    if (value18 >= battle_temp_a45) {
        a_ee3b = (uint8_t)(value18 - battle_temp_a45);
        a_hi_ee3b = a_hi_ee2e;
        x_ee3b = x_ee2e;
        y_ee3b = y_ee2e;
        zero_ee3b = (uint8_t)(value18 - battle_temp_a45) == 0;
        goto shared_EE3B;
    }
    a_ee3b = 0;
    a_hi_ee3b = a_hi_ee2e;
    x_ee3b = x_ee2e;
    y_ee3b = y_ee2e;
    zero_ee3b = 1;
    goto shared_EE3B;
    shared_EE2E_1:;
    RAM8(0xE1B7 + x_ee2e2) = a_ee2e2;
    uint8_t value19 = RAM8(0xE1BA + x_ee2e2);
    uint8_t battle_temp_a46 = RAM8(BATTLE_TEMP_A4);
    if (value19 >= battle_temp_a46) {
        a_ee3b2 = (uint8_t)(value19 - battle_temp_a46);
        a_hi_ee3b2 = a_hi_ee2e2;
        x_ee3b2 = x_ee2e2;
        y_ee3b2 = y_ee2e2;
        zero_ee3b2 = (uint8_t)(value19 - battle_temp_a46) == 0;
        goto shared_EE3B_1;
    }
    a_ee3b2 = 0;
    a_hi_ee3b2 = a_hi_ee2e2;
    x_ee3b2 = x_ee2e2;
    y_ee3b2 = y_ee2e2;
    zero_ee3b2 = 1;
    goto shared_EE3B_1;
    shared_EEAB:;
    uint8_t value20 = BUS8_RDP(c, (data_bank_eeab << 0x10) + 0xE1B1 + x_eeab);
    if ((value20 & 0x40) == 0) {
        a_eeb6 = value20;
        a_hi_eeb6 = a_hi_eeab;
        x_eeb6 = x_eeab;
        y_eeb6 = y_eeab;
        carry_eeb6 = carry_eeab;
        zero_eeb6 = (value20 & 0x40) == 0;
        negative_eeb6 = value20 & 0x80;
        overflow_eeb6 = overflow_eeab;
        direct_page_eeb6 = direct_page_eeab;
        data_bank_eeb6 = data_bank_eeab;
        goto shared_EEB6;
    }
    r->a = (a_hi_eeab << 8) | value20;
    r->x = x_eeab;
    r->y = y_eeab;
    r->c = carry_eeab;
    r->z = (value20 & 0x40) == 0;
    r->n = value20 & 0x80;
    r->v = overflow_eeab;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_eeab;
    r->dp = direct_page_eeab;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEEB5, 0xC05BB6); GUARD_JSL(c, sp_call, 0xEEB5); } /* enqueue_wall_expiration_notice */
    uint16_t a_all5 = r->a;
    uint8_t x_ret7 = r->x;
    uint8_t y_ret5 = r->y;
    bool carry_ret4 = r->c;
    bool zero_ret5 = r->z;
    bool negative_ret5 = r->n;
    a_eeb6 = (uint8_t)a_all5;
    a_hi_eeb6 = a_all5 >> 8;
    x_eeb6 = x_ret7;
    y_eeb6 = y_ret5;
    carry_eeb6 = carry_ret4;
    zero_eeb6 = zero_ret5;
    negative_eeb6 = negative_ret5;
    overflow_eeb6 = overflow_eeab;
    direct_page_eeb6 = direct_page_eeab;
    data_bank_eeb6 = data_bank_eeab;
    goto shared_EEB6;
    shared_EEAB_1:;
    uint8_t value21 = BUS8_RDP(c, (data_bank_eeab2 << 0x10) + 0xE1B1 + x_eeab2);
    if ((value21 & 0x40) == 0) {
        a_eeb62 = value21;
        a_hi_eeb62 = a_hi_eeab2;
        x_eeb62 = x_eeab2;
        y_eeb62 = y_eeab2;
        carry_eeb62 = carry_eeab2;
        zero_eeb62 = (value21 & 0x40) == 0;
        negative_eeb62 = value21 & 0x80;
        overflow_eeb62 = overflow_eeab2;
        direct_page_eeb62 = direct_page_eeab2;
        data_bank_eeb62 = data_bank_eeab2;
        goto shared_EEB6_1;
    }
    r->a = (a_hi_eeab2 << 8) | value21;
    r->x = x_eeab2;
    r->y = y_eeab2;
    r->c = carry_eeab2;
    r->z = (value21 & 0x40) == 0;
    r->n = value21 & 0x80;
    r->v = overflow_eeab2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_eeab2;
    r->dp = direct_page_eeab2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEEB5, 0xC05BB6); GUARD_JSL(c, sp_call, 0xEEB5); } /* enqueue_wall_expiration_notice */
    uint16_t a_all6 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret5 = r->c;
    bool zero_ret6 = r->z;
    bool negative_ret6 = r->n;
    a_eeb62 = (uint8_t)a_all6;
    a_hi_eeb62 = a_all6 >> 8;
    x_eeb62 = x_ret8;
    y_eeb62 = y_ret6;
    carry_eeb62 = carry_ret5;
    zero_eeb62 = zero_ret6;
    negative_eeb62 = negative_ret6;
    overflow_eeb62 = overflow_eeab2;
    direct_page_eeb62 = direct_page_eeab2;
    data_bank_eeb62 = data_bank_eeab2;
    goto shared_EEB6_1;
    shared_EE3B:;
    if (!zero_ee3b) {
        a_ee3f = a_ee3b;
        a_hi_ee3f = a_hi_ee3b;
        x_ee3f = x_ee3b;
        y_ee3f = y_ee3b;
        goto shared_EE3F;
    }
    a_ee3f = 1;
    a_hi_ee3f = a_hi_ee3b;
    x_ee3f = x_ee3b;
    y_ee3f = y_ee3b;
    goto shared_EE3F;
    shared_EE3B_1:;
    if (!zero_ee3b2) {
        a_ee3f2 = a_ee3b2;
        a_hi_ee3f2 = a_hi_ee3b2;
        x_ee3f2 = x_ee3b2;
        y_ee3f2 = y_ee3b2;
        goto shared_EE3F_1;
    }
    a_ee3f2 = 1;
    a_hi_ee3f2 = a_hi_ee3b2;
    x_ee3f2 = x_ee3b2;
    y_ee3f2 = y_ee3b2;
    goto shared_EE3F_1;
    shared_EEB6:;
    r->a = (a_hi_eeb6 << 8) | a_eeb6;
    r->x = x_eeb6;
    r->y = y_eeb6;
    r->c = carry_eeb6;
    r->z = zero_eeb6;
    r->n = negative_eeb6;
    r->v = overflow_eeb6;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_eeb6;
    r->dp = direct_page_eeb6;
    RETURN_RTS(c);
    shared_EEB6_1:;
    r->a = (a_hi_eeb62 << 8) | a_eeb62;
    r->x = x_eeb62;
    r->y = y_eeb62;
    r->c = carry_eeb62;
    r->z = zero_eeb62;
    r->n = negative_eeb62;
    r->v = overflow_eeb62;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_eeb62;
    r->dp = direct_page_eeb62;
    RETURN_RTS(c);
    shared_EE3F:;
    RAM8(0xE1BA + x_ee3f) = a_ee3f;
    uint8_t value22 = RAM8(0xE1BB + x_ee3f);
    uint8_t battle_temp_a47 = RAM8(BATTLE_TEMP_A4);
    if (value22 >= battle_temp_a47) {
        a_ee4c = (uint8_t)(value22 - battle_temp_a47);
        a_hi_ee4c = a_hi_ee3f;
        x_ee4c = x_ee3f;
        y_ee4c = y_ee3f;
        zero_ee4c = (uint8_t)(value22 - battle_temp_a47) == 0;
        goto shared_EE4C;
    }
    a_ee4c = 0;
    a_hi_ee4c = a_hi_ee3f;
    x_ee4c = x_ee3f;
    y_ee4c = y_ee3f;
    zero_ee4c = 1;
    goto shared_EE4C;
    shared_EE3F_1:;
    RAM8(0xE1BA + x_ee3f2) = a_ee3f2;
    uint8_t value23 = RAM8(0xE1BB + x_ee3f2);
    uint8_t battle_temp_a48 = RAM8(BATTLE_TEMP_A4);
    if (value23 >= battle_temp_a48) {
        a_ee4c2 = (uint8_t)(value23 - battle_temp_a48);
        a_hi_ee4c2 = a_hi_ee3f2;
        x_ee4c2 = x_ee3f2;
        y_ee4c2 = y_ee3f2;
        zero_ee4c2 = (uint8_t)(value23 - battle_temp_a48) == 0;
        goto shared_EE4C_1;
    }
    a_ee4c2 = 0;
    a_hi_ee4c2 = a_hi_ee3f2;
    x_ee4c2 = x_ee3f2;
    y_ee4c2 = y_ee3f2;
    zero_ee4c2 = 1;
    goto shared_EE4C_1;
    shared_EE4C:;
    if (!zero_ee4c) {
        a_ee50 = a_ee4c;
        a_hi_ee50 = a_hi_ee4c;
        x_ee50 = x_ee4c;
        y_ee50 = y_ee4c;
        goto shared_EE50;
    }
    a_ee50 = 1;
    a_hi_ee50 = a_hi_ee4c;
    x_ee50 = x_ee4c;
    y_ee50 = y_ee4c;
    goto shared_EE50;
    shared_EE4C_1:;
    if (!zero_ee4c2) {
        a_ee502 = a_ee4c2;
        a_hi_ee502 = a_hi_ee4c2;
        x_ee502 = x_ee4c2;
        y_ee502 = y_ee4c2;
        goto shared_EE50_1;
    }
    a_ee502 = 1;
    a_hi_ee502 = a_hi_ee4c2;
    x_ee502 = x_ee4c2;
    y_ee502 = y_ee4c2;
    goto shared_EE50_1;
    shared_EE50:;
    RAM8(0xE1BB + x_ee50) = a_ee50;
    uint8_t value24 = RAM8(0xE1BC + x_ee50);
    uint8_t battle_temp_a49 = RAM8(BATTLE_TEMP_A4);
    if (value24 >= battle_temp_a49) {
        a_ee5d = (uint8_t)(value24 - battle_temp_a49);
        a_hi_ee5d = a_hi_ee50;
        x_ee5d = x_ee50;
        y_ee5d = y_ee50;
        zero_ee5d = (uint8_t)(value24 - battle_temp_a49) == 0;
        goto shared_EE5D;
    }
    a_ee5d = 0;
    a_hi_ee5d = a_hi_ee50;
    x_ee5d = x_ee50;
    y_ee5d = y_ee50;
    zero_ee5d = 1;
    goto shared_EE5D;
    shared_EE50_1:;
    RAM8(0xE1BB + x_ee502) = a_ee502;
    uint8_t value25 = RAM8(0xE1BC + x_ee502);
    uint8_t battle_temp_a410 = RAM8(BATTLE_TEMP_A4);
    if (value25 >= battle_temp_a410) {
        a_ee5d2 = (uint8_t)(value25 - battle_temp_a410);
        a_hi_ee5d2 = a_hi_ee502;
        x_ee5d2 = x_ee502;
        y_ee5d2 = y_ee502;
        zero_ee5d2 = (uint8_t)(value25 - battle_temp_a410) == 0;
        goto shared_EE5D_1;
    }
    a_ee5d2 = 0;
    a_hi_ee5d2 = a_hi_ee502;
    x_ee5d2 = x_ee502;
    y_ee5d2 = y_ee502;
    zero_ee5d2 = 1;
    goto shared_EE5D_1;
    shared_EE5D:;
    if (!zero_ee5d) {
        a_ee61 = a_ee5d;
        a_hi_ee61 = a_hi_ee5d;
        x_ee61 = x_ee5d;
        y_ee61 = y_ee5d;
        goto shared_EE61;
    }
    a_ee61 = 1;
    a_hi_ee61 = a_hi_ee5d;
    x_ee61 = x_ee5d;
    y_ee61 = y_ee5d;
    goto shared_EE61;
    shared_EE5D_1:;
    if (!zero_ee5d2) {
        a_ee612 = a_ee5d2;
        a_hi_ee612 = a_hi_ee5d2;
        x_ee612 = x_ee5d2;
        y_ee612 = y_ee5d2;
        goto shared_EE61_1;
    }
    a_ee612 = 1;
    a_hi_ee612 = a_hi_ee5d2;
    x_ee612 = x_ee5d2;
    y_ee612 = y_ee5d2;
    goto shared_EE61_1;
    shared_EE61:;
    RAM8(0xE1BC + x_ee61) = a_ee61;
    uint8_t battle_defender_ptr2 = RAM8(BATTLE_DEFENDER_PTR);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((uint8_t)(RAM8(0x039D) + 1) << 2);
    uint8_t value27 = RAM8(ACTOR_SABER_HITS_LEFT + battle_defender_ptr2);
    uint8_t battle_temp_a411 = RAM8(BATTLE_TEMP_A4);
    if (!((uint8_t)(value27 - battle_temp_a411) & 0x80)) {
        a_ee77 = (uint8_t)(value27 - battle_temp_a411);
        a_hi_ee77 = a_hi_ee61;
        x_ee77 = battle_defender_ptr2;
        y_ee77 = y_ee61;
        goto shared_EE77;
    }
    a_ee77 = 0;
    a_hi_ee77 = a_hi_ee61;
    x_ee77 = battle_defender_ptr2;
    y_ee77 = y_ee61;
    goto shared_EE77;
    shared_EE61_1:;
    RAM8(0xE1BC + x_ee612) = a_ee612;
    uint16_t battle_defender_ptr3 = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((uint8_t)(RAM8(0x039D) + 1) << 2);
    uint8_t value29 = RAM8(ACTOR_SABER_HITS_LEFT + battle_defender_ptr3);
    uint8_t battle_temp_a412 = RAM8(BATTLE_TEMP_A4);
    if (!((uint8_t)(value29 - battle_temp_a412) & 0x80)) {
        a_ee772 = (uint8_t)(value29 - battle_temp_a412);
        a_hi_ee772 = a_hi_ee612;
        x_ee772 = battle_defender_ptr3;
        y_ee772 = y_ee612;
        goto shared_EE77_1;
    }
    a_ee772 = 0;
    a_hi_ee772 = a_hi_ee612;
    x_ee772 = battle_defender_ptr3;
    y_ee772 = y_ee612;
    goto shared_EE77_1;
    shared_EE77:;
    RAM8(ACTOR_SABER_HITS_LEFT + x_ee77) = a_ee77;
    RAM8(BATTLE_TEMP_A4) = (uint8_t)(RAM8(0x039D) + 2);
    uint8_t value31 = RAM8(0xE1B8 + x_ee77);
    uint8_t battle_temp_a413 = RAM8(BATTLE_TEMP_A4);
    if (!((uint8_t)(value31 - battle_temp_a413) & 0x80)) {
        a_ee8a = (uint8_t)(value31 - battle_temp_a413);
        a_hi_ee8a = a_hi_ee77;
        x_ee8a = x_ee77;
        y_ee8a = y_ee77;
        carry_ee8a = value31 >= battle_temp_a413;
        overflow_ee8a = ((value31 ^ battle_temp_a413) & (value31 ^ (uint8_t)(value31 - battle_temp_a413)) & 0x80) != 0;
        goto shared_EE8A;
    }
    a_ee8a = 0;
    a_hi_ee8a = a_hi_ee77;
    x_ee8a = x_ee77;
    y_ee8a = y_ee77;
    carry_ee8a = value31 >= battle_temp_a413;
    overflow_ee8a = ((value31 ^ battle_temp_a413) & (value31 ^ (uint8_t)(value31 - battle_temp_a413)) & 0x80) != 0;
    goto shared_EE8A;
    shared_EE77_1:;
    RAM8(ACTOR_SABER_HITS_LEFT + x_ee772) = a_ee772;
    RAM8(BATTLE_TEMP_A4) = (uint8_t)(RAM8(0x039D) + 2);
    uint8_t value33 = RAM8(0xE1B8 + x_ee772);
    uint8_t battle_temp_a414 = RAM8(BATTLE_TEMP_A4);
    if (!((uint8_t)(value33 - battle_temp_a414) & 0x80)) {
        a_ee8a2 = (uint8_t)(value33 - battle_temp_a414);
        a_hi_ee8a2 = a_hi_ee772;
        x_ee8a2 = x_ee772;
        y_ee8a2 = y_ee772;
        carry_ee8a2 = value33 >= battle_temp_a414;
        overflow_ee8a2 = ((value33 ^ battle_temp_a414) & (value33 ^ (uint8_t)(value33 - battle_temp_a414)) & 0x80) != 0;
        goto shared_EE8A_1;
    }
    a_ee8a2 = 0;
    a_hi_ee8a2 = a_hi_ee772;
    x_ee8a2 = x_ee772;
    y_ee8a2 = y_ee772;
    carry_ee8a2 = value33 >= battle_temp_a414;
    overflow_ee8a2 = ((value33 ^ battle_temp_a414) & (value33 ^ (uint8_t)(value33 - battle_temp_a414)) & 0x80) != 0;
    goto shared_EE8A_1;
    shared_EE8A:;
    RAM8(0xE1B8 + x_ee8a) = a_ee8a;
    a_hi_ee8d = a_hi_ee8a;
    x_ee8d = x_ee8a;
    y_ee8d = y_ee8a;
    carry_ee8d = carry_ee8a;
    overflow_ee8d = overflow_ee8a;
    goto shared_EE8D;
    shared_EE8A_1:;
    RAM8(0xE1B8 + x_ee8a2) = a_ee8a2;
    a_hi_ee8d2 = a_hi_ee8a2;
    x_ee8d2 = x_ee8a2;
    y_ee8d2 = y_ee8a2;
    carry_ee8d2 = carry_ee8a2;
    overflow_ee8d2 = overflow_ee8a2;
    goto shared_EE8D_1;
}
SOM_REGISTER(0xC8EDCB, SOM_RTS, "gen", resolve_dispel_magic_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 236, 107)
