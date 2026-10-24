#include "som_c.h"

/* C04203 process_actor_death_rewards_and_drop_conversion   [class B, 266 bytes, 115 instructions]
 * Source: src/rom/process_actor_death_rewards_and_drop_conversion.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void process_actor_death_rewards_and_drop_conversion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t a_hi_4260 = 0;
    uint16_t x_4260 = 0;
    uint16_t y_4260 = 0;
    bool carry_4260 = 0;
    bool overflow_4260 = 0;
    uint16_t direct_page_4260 = 0;
    uint8_t data_bank_4260 = 0;
    uint8_t a_hi_42602 = 0;
    uint8_t x_42602 = 0;
    uint8_t y_42602 = 0;
    bool carry_42602 = 0;
    bool overflow_42602 = 0;
    uint16_t direct_page_42602 = 0;
    uint8_t data_bank_42602 = 0;
    uint8_t a_hi_42a3 = 0;
    uint16_t x_42a3 = 0;
    uint16_t y_42a3 = 0;
    bool carry_42a3 = 0;
    bool overflow_42a3 = 0;
    uint16_t direct_page_42a3 = 0;
    uint8_t data_bank_42a3 = 0;
    uint8_t a_hi_42a4 = 0;
    uint8_t x_42a4 = 0;
    uint8_t y_42a4 = 0;
    bool carry_42a4 = 0;
    bool overflow_42a4 = 0;
    uint16_t direct_page_42a4 = 0;
    uint8_t data_bank_42a4 = 0;
    uint8_t a_hi_42a42 = 0;
    uint16_t x_42a42 = 0;
    uint16_t y_42a42 = 0;
    bool carry_42a42 = 0;
    bool overflow_42a42 = 0;
    uint16_t direct_page_42a42 = 0;
    uint8_t data_bank_42a42 = 0;
    uint8_t a_hi_42a32 = 0;
    uint8_t x_42a32 = 0;
    uint8_t y_42a32 = 0;
    bool carry_42a32 = 0;
    bool overflow_42a32 = 0;
    uint16_t direct_page_42a32 = 0;
    uint8_t data_bank_42a32 = 0;
    uint8_t a_hi_42ab = 0;
    uint8_t x_42ab = 0;
    uint8_t y_42ab = 0;
    bool carry_42ab = 0;
    bool overflow_42ab = 0;
    uint16_t direct_page_42ab = 0;
    uint8_t data_bank_42ab = 0;
    uint8_t a_hi_42ab2 = 0;
    uint16_t x_42ab2 = 0;
    uint16_t y_42ab2 = 0;
    bool carry_42ab2 = 0;
    bool overflow_42ab2 = 0;
    uint16_t direct_page_42ab2 = 0;
    uint8_t data_bank_42ab2 = 0;
    uint8_t a_hi_42f1 = 0;
    uint8_t x_42f1 = 0;
    uint8_t y_42f1 = 0;
    bool carry_42f1 = 0;
    bool overflow_42f1 = 0;
    uint16_t direct_page_42f1 = 0;
    uint8_t data_bank_42f1 = 0;
    uint8_t a_hi_42f12 = 0;
    uint16_t x_42f12 = 0;
    uint16_t y_42f12 = 0;
    bool carry_42f12 = 0;
    bool overflow_42f12 = 0;
    uint16_t direct_page_42f12 = 0;
    uint8_t data_bank_42f12 = 0;
    uint8_t a_42fd = 0;
    uint8_t a_hi_42fd = 0;
    uint8_t x_42fd = 0;
    uint8_t y_42fd = 0;
    bool carry_42fd = 0;
    bool overflow_42fd = 0;
    uint16_t direct_page_42fd = 0;
    uint8_t data_bank_42fd = 0;
    uint8_t a_42fd2 = 0;
    uint8_t a_hi_42fd2 = 0;
    uint16_t x_42fd2 = 0;
    uint16_t y_42fd2 = 0;
    bool carry_42fd2 = 0;
    bool overflow_42fd2 = 0;
    uint16_t direct_page_42fd2 = 0;
    uint8_t data_bank_42fd2 = 0;
    RAM8(ACTOR_GUARD_FLAGS + x) = 0;
    RAM8(ACTOR_BUFF_FLAGS + x) = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x420D, 0xC04315); GUARD_JSR(c, sp_call, 0x420D); } /* clear_six_actor_references_to_dead_actor */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if ((RAM8(ACTOR_KIND_FLAGS + x) & 0x40) == 0) {
        uint8_t value2 = RAM8(0xE1EC + x);
        if (value2 >= 3) {
            a_hi_4260 = a_all >> 8;
            x_4260 = x;
            y_4260 = y_ret;
            carry_4260 = value2 >= 3;
            overflow_4260 = overflow;
            direct_page_4260 = 0x0300;
            data_bank_4260 = 0x7E;
            goto shared_4260;
        }
        RAM8(BATTLE_ATTACKER_SLOT) = value2;
        RAM8(0x0384) = (uint8_t)(value2 << 1);
        uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
        r->a = (a_all >> 8 << 8) | (uint8_t)(value2 << 1);
        r->y = battle_attacker_ptr;
        r->c = value2 & 0x80;
        r->z = battle_attacker_ptr == 0;
        r->n = battle_attacker_ptr & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4257, 0xC04358); GUARD_JSR(c, sp_call, 0x4257); } /* distribute_dead_actor_weapon_experience */
        { const uint16_t sp_call = r->sp; JSR(c, 0x425A, 0xC0445B); GUARD_JSR(c, sp_call, 0x425A); } /* award_hero_experience_and_rebuild_each_level */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        uint16_t y_ret3 = r->y;
        { const uint16_t sp_call = r->sp; JSR(c, 0x425D, 0xC044F0); GUARD_JSR(c, sp_call, 0x425D); } /* add_dead_actor_gold_to_party_with_native_cap */
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        bool carry_ret4 = r->c;
        bool overflow_ret3 = r->v;
        if (x_ret5) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x85));
            a_hi_42602 = a_all4 >> 8;
            x_42602 = value3;
            y_42602 = (uint8_t)y_ret3;
            carry_42602 = carry_ret4;
            overflow_42602 = overflow_ret3;
            direct_page_42602 = dp_ret2;
            data_bank_42602 = db_ret2;
            goto shared_4260_1;
        } else {
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x85));
            a_hi_4260 = a_all4 >> 8;
            x_4260 = value4;
            y_4260 = y_ret3;
            carry_4260 = carry_ret4;
            overflow_4260 = overflow_ret3;
            direct_page_4260 = dp_ret2;
            data_bank_4260 = db_ret2;
            goto shared_4260;
        }
    }
    RAM8(0x0380) |= 0x80;
    RAM16_SET(0xE190, RAM16(0xE190) & 0x8200);
    RAM16_SET(0xE390, RAM16(0xE390) & 0x8200);
    RAM16_SET(0xE590, RAM16(0xE590) & 0x8200);
    RAM16_SET(ACTOR_STATUS + x, 0x8000);
    r->a = 0x8000;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4243, 0xC05D46); GUARD_JSL(c, sp_call, 0x4243); } /* clear_map_entry_party_effects */
    uint16_t dp_ret3 = r->dp;
    bool x_ret7 = r->xf;
    uint16_t y_ret4 = r->y;
    if (x_ret7) {
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x85));
        r->x = value9;
        r->y = (uint8_t)y_ret4;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x85));
        r->x = value10;
        r->xf = 0;
        RETURN_RTS(c);
    }
    shared_4260:;
    uint8_t value11 = BUS8_RDP(c, (data_bank_4260 << 0x10) + 0xE1FB + x_4260);
    if ((value11 & 0xC1) != 0) {
        a_hi_42a3 = a_hi_4260;
        x_42a3 = x_4260;
        y_42a3 = y_4260;
        carry_42a3 = carry_4260;
        overflow_42a3 = overflow_4260;
        direct_page_42a3 = direct_page_4260;
        data_bank_42a3 = data_bank_4260;
        goto shared_42A3;
    }
    BUS8_SET(c, (data_bank_4260 << 0x10) + 0xE191 + x_4260, 0x80);
    BUS8_SET(c, (data_bank_4260 << 0x10) + 0xE190 + x_4260, 0);
    uint8_t value12 = BUS8_RDP(c, (data_bank_4260 << 0x10) + 0xE1CA + x_4260);
    BUS8_SET(c, (data_bank_4260 << 0x10) + 0xE180 + x_4260, (uint8_t)(((value12 & 0x1E) >> 1) + 0xF9));
    BUS8_SET(c, (data_bank_4260 << 0x10) + 0xE1E3 + x_4260, 0);
    uint8_t value13 = BUS8_RDP(c, (data_bank_4260 << 0x10) + 0xE1FA + x_4260);
    BUS8_SET(c, (data_bank_4260 << 0x10) + 0xE1FA + x_4260, value13 | 7);
    r->a = (a_hi_4260 << 8) | (value13 | 7);
    r->x = x_4260;
    r->y = y_4260;
    r->c = ((value12 & 0x1E) >> 1) + 0xF9 > 0xFF;
    r->z = (value13 | 7) == 0;
    r->n = (value13 | 7) & 0x80;
    r->v = ((((value12 & 0x1E) >> 1) ^ (uint8_t)(((value12 & 0x1E) >> 1) + 0xF9)) & ((uint8_t)(((value12 & 0x1E) >> 1) + 0xF9) ^ 0xF9) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_4260;
    r->dp = direct_page_4260;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4289, 0xC8E301); GUARD_JSL(c, sp_call, 0x4289); } /* apply_actor_status_and_timers */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0x428C, 0xC038A0); GUARD_JSR(c, sp_call, 0x428C); } /* advance_additive_random_generator */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret11 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret7 = r->c;
    bool overflow_ret6 = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret4 + 0xA8), ((uint8_t)a_all7 & 0x3F) + 1);
    uint8_t value14 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xE1CE + x_ret12);
    BUS8_SET(c, (uint16_t)(dp_ret4 + 0xA4), value14);
    if ((value14 & 0x40) != 0) {
        if (x_ret11) {
            a_hi_42a4 = a_all7 >> 8;
            x_42a4 = (uint8_t)x_ret12;
            y_42a4 = (uint8_t)y_ret6;
            carry_42a4 = carry_ret7;
            overflow_42a4 = overflow_ret6;
            direct_page_42a4 = dp_ret4;
            data_bank_42a4 = db_ret4;
            goto shared_42A4;
        } else {
            a_hi_42a42 = a_all7 >> 8;
            x_42a42 = x_ret12;
            y_42a42 = y_ret6;
            carry_42a42 = carry_ret7;
            overflow_42a42 = overflow_ret6;
            direct_page_42a42 = dp_ret4;
            data_bank_42a42 = db_ret4;
            goto shared_42A4_1;
        }
    }
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0xA8));
    if ((value14 & 0x3F) >= value15) {
        if (x_ret11) {
            a_hi_42a4 = a_all7 >> 8;
            x_42a4 = (uint8_t)x_ret12;
            y_42a4 = (uint8_t)y_ret6;
            carry_42a4 = (value14 & 0x3F) >= value15;
            overflow_42a4 = overflow_ret6;
            direct_page_42a4 = dp_ret4;
            data_bank_42a4 = db_ret4;
            goto shared_42A4;
        } else {
            a_hi_42a42 = a_all7 >> 8;
            x_42a42 = x_ret12;
            y_42a42 = y_ret6;
            carry_42a42 = (value14 & 0x3F) >= value15;
            overflow_42a42 = overflow_ret6;
            direct_page_42a42 = dp_ret4;
            data_bank_42a42 = db_ret4;
            goto shared_42A4_1;
        }
    }
    if (x_ret11) {
        uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0x85));
        a_hi_42a32 = a_all7 >> 8;
        x_42a32 = value16;
        y_42a32 = (uint8_t)y_ret6;
        carry_42a32 = (value14 & 0x3F) >= value15;
        overflow_42a32 = overflow_ret6;
        direct_page_42a32 = dp_ret4;
        data_bank_42a32 = db_ret4;
        goto shared_42A3_1;
    } else {
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 0x85));
        a_hi_42a3 = a_all7 >> 8;
        x_42a3 = value17;
        y_42a3 = y_ret6;
        carry_42a3 = (value14 & 0x3F) >= value15;
        overflow_42a3 = overflow_ret6;
        direct_page_42a3 = dp_ret4;
        data_bank_42a3 = db_ret4;
        goto shared_42A3;
    }
    shared_4260_1:;
    uint8_t value18 = BUS8_RDP(c, (data_bank_42602 << 0x10) + 0xE1FB + x_42602);
    if ((value18 & 0xC1) != 0) {
        a_hi_42a32 = a_hi_42602;
        x_42a32 = x_42602;
        y_42a32 = y_42602;
        carry_42a32 = carry_42602;
        overflow_42a32 = overflow_42602;
        direct_page_42a32 = direct_page_42602;
        data_bank_42a32 = data_bank_42602;
        goto shared_42A3_1;
    }
    BUS8_SET(c, (data_bank_42602 << 0x10) + 0xE191 + x_42602, 0x80);
    BUS8_SET(c, (data_bank_42602 << 0x10) + 0xE190 + x_42602, 0);
    uint8_t value19 = BUS8_RDP(c, (data_bank_42602 << 0x10) + 0xE1CA + x_42602);
    BUS8_SET(c, (data_bank_42602 << 0x10) + 0xE180 + x_42602, (uint8_t)(((value19 & 0x1E) >> 1) + 0xF9));
    BUS8_SET(c, (data_bank_42602 << 0x10) + 0xE1E3 + x_42602, 0);
    uint8_t value20 = BUS8_RDP(c, (data_bank_42602 << 0x10) + 0xE1FA + x_42602);
    BUS8_SET(c, (data_bank_42602 << 0x10) + 0xE1FA + x_42602, value20 | 7);
    r->a = (a_hi_42602 << 8) | (value20 | 7);
    r->x = x_42602;
    r->y = y_42602;
    r->c = ((value19 & 0x1E) >> 1) + 0xF9 > 0xFF;
    r->z = (value20 | 7) == 0;
    r->n = (value20 | 7) & 0x80;
    r->v = ((((value19 & 0x1E) >> 1) ^ (uint8_t)(((value19 & 0x1E) >> 1) + 0xF9)) & ((uint8_t)(((value19 & 0x1E) >> 1) + 0xF9) ^ 0xF9) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_42602;
    r->dp = direct_page_42602;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4289, 0xC8E301); GUARD_JSL(c, sp_call, 0x4289); } /* apply_actor_status_and_timers */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0x428C, 0xC038A0); GUARD_JSR(c, sp_call, 0x428C); } /* advance_additive_random_generator */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret15 = r->xf;
    uint16_t a_all9 = r->a;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret9 = r->c;
    bool overflow_ret8 = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret5 + 0xA8), ((uint8_t)a_all9 & 0x3F) + 1);
    uint8_t value21 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xE1CE + x_ret16);
    BUS8_SET(c, (uint16_t)(dp_ret5 + 0xA4), value21);
    if ((value21 & 0x40) != 0) {
        if (x_ret15) {
            a_hi_42a4 = a_all9 >> 8;
            x_42a4 = (uint8_t)x_ret16;
            y_42a4 = (uint8_t)y_ret8;
            carry_42a4 = carry_ret9;
            overflow_42a4 = overflow_ret8;
            direct_page_42a4 = dp_ret5;
            data_bank_42a4 = db_ret5;
            goto shared_42A4;
        } else {
            a_hi_42a42 = a_all9 >> 8;
            x_42a42 = x_ret16;
            y_42a42 = y_ret8;
            carry_42a42 = carry_ret9;
            overflow_42a42 = overflow_ret8;
            direct_page_42a42 = dp_ret5;
            data_bank_42a42 = db_ret5;
            goto shared_42A4_1;
        }
    }
    uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 0xA8));
    if ((value21 & 0x3F) >= value22) {
        if (x_ret15) {
            a_hi_42a4 = a_all9 >> 8;
            x_42a4 = (uint8_t)x_ret16;
            y_42a4 = (uint8_t)y_ret8;
            carry_42a4 = (value21 & 0x3F) >= value22;
            overflow_42a4 = overflow_ret8;
            direct_page_42a4 = dp_ret5;
            data_bank_42a4 = db_ret5;
            goto shared_42A4;
        } else {
            a_hi_42a42 = a_all9 >> 8;
            x_42a42 = x_ret16;
            y_42a42 = y_ret8;
            carry_42a42 = (value21 & 0x3F) >= value22;
            overflow_42a42 = overflow_ret8;
            direct_page_42a42 = dp_ret5;
            data_bank_42a42 = db_ret5;
            goto shared_42A4_1;
        }
    }
    if (x_ret15) {
        uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 0x85));
        a_hi_42a32 = a_all9 >> 8;
        x_42a32 = value23;
        y_42a32 = (uint8_t)y_ret8;
        carry_42a32 = (value21 & 0x3F) >= value22;
        overflow_42a32 = overflow_ret8;
        direct_page_42a32 = dp_ret5;
        data_bank_42a32 = db_ret5;
        goto shared_42A3_1;
    } else {
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 0x85));
        a_hi_42a3 = a_all9 >> 8;
        x_42a3 = value24;
        y_42a3 = y_ret8;
        carry_42a3 = (value21 & 0x3F) >= value22;
        overflow_42a3 = overflow_ret8;
        direct_page_42a3 = dp_ret5;
        data_bank_42a3 = db_ret5;
        goto shared_42A3;
    }
    shared_42A3:;
    r->a = (a_hi_42a3 << 8) | (uint8_t)a;
    r->x = x_42a3;
    r->y = y_42a3;
    r->c = carry_42a3;
    r->v = overflow_42a3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_42a3;
    r->dp = direct_page_42a3;
    RETURN_RTS(c);
    shared_42A4:;
    uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_42a4 + 0xA4));
    if (!(value25 & 0x80)) {
        a_hi_42ab = a_hi_42a4;
        x_42ab = x_42a4;
        y_42ab = y_42a4;
        carry_42ab = carry_42a4;
        overflow_42ab = overflow_42a4;
        direct_page_42ab = direct_page_42a4;
        data_bank_42ab = data_bank_42a4;
        goto shared_42AB;
    }
    uint8_t value26 = BUS8_RDP(c, (data_bank_42a4 << 0x10) + 0xE182 + x_42a4);
    BUS8_SET(c, (data_bank_42a4 << 0x10) + 0xE182 + x_42a4, (uint8_t)(value26 - 1));
    a_hi_42ab = a_hi_42a4;
    x_42ab = x_42a4;
    y_42ab = y_42a4;
    carry_42ab = carry_42a4;
    overflow_42ab = overflow_42a4;
    direct_page_42ab = direct_page_42a4;
    data_bank_42ab = data_bank_42a4;
    goto shared_42AB;
    shared_42A4_1:;
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_42a42 + 0xA4));
    if (!(value27 & 0x80)) {
        a_hi_42ab2 = a_hi_42a42;
        x_42ab2 = x_42a42;
        y_42ab2 = y_42a42;
        carry_42ab2 = carry_42a42;
        overflow_42ab2 = overflow_42a42;
        direct_page_42ab2 = direct_page_42a42;
        data_bank_42ab2 = data_bank_42a42;
        goto shared_42AB_1;
    }
    uint8_t value28 = BUS8_RDP(c, (data_bank_42a42 << 0x10) + 0xE182 + x_42a42);
    BUS8_SET(c, (data_bank_42a42 << 0x10) + 0xE182 + x_42a42, (uint8_t)(value28 - 1));
    a_hi_42ab2 = a_hi_42a42;
    x_42ab2 = x_42a42;
    y_42ab2 = y_42a42;
    carry_42ab2 = carry_42a42;
    overflow_42ab2 = overflow_42a42;
    direct_page_42ab2 = direct_page_42a42;
    data_bank_42ab2 = data_bank_42a42;
    goto shared_42AB_1;
    shared_42A3_1:;
    r->a = (a_hi_42a32 << 8) | (uint8_t)a;
    r->x = x_42a32;
    r->y = y_42a32;
    r->c = carry_42a32;
    r->v = overflow_42a32;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_42a32;
    r->dp = direct_page_42a32;
    RETURN_RTS(c);
    shared_42AB:;
    BUS8_SET(c, (data_bank_42ab << 0x10) + 0xE1B1 + x_42ab, 0x80);
    BUS8_SET(c, (data_bank_42ab << 0x10) + 0xE1B0 + x_42ab, 0);
    uint8_t value29 = BUS8_RDP(c, (data_bank_42ab << 0x10) + 0xE1CF + x_42ab);
    if (value29 == 0) {
        r->a = (a_hi_42ab << 8) | 3;
        r->x = x_42ab;
        r->y = y_42ab;
        r->c = carry_42ab;
        r->z = 0;
        r->n = 0;
        r->v = overflow_42ab;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_42ab;
        r->dp = direct_page_42ab;
        { const uint16_t sp_call = r->sp; JSR(c, 0x42BF, 0xC03888); GUARD_JSR(c, sp_call, 0x42BF); } /* random_below_byte */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret17 = r->xf;
        uint16_t a_all10 = r->a;
        uint16_t x_ret18 = r->x;
        uint16_t y_ret9 = r->y;
        bool overflow_ret9 = r->v;
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)a_all10);
        uint8_t value30 = BUS8_RDP(c, (data_bank_42ab << 0x10) + 0xE181 + x_ret18);
        if (value30 < 0x0A) {
            if (x_ret17) {
                a_hi_42f1 = a_all10 >> 8;
                x_42f1 = (uint8_t)x_ret18;
                y_42f1 = (uint8_t)y_ret9;
                carry_42f1 = value30 >= 0x0A;
                overflow_42f1 = overflow_ret9;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all10 >> 8;
                x_42f12 = x_ret18;
                y_42f12 = y_ret9;
                carry_42f12 = value30 >= 0x0A;
                overflow_42f12 = overflow_ret9;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), 2);
        uint8_t value31 = BUS8_RDP(c, (data_bank_42ab << 0x10) + 0xE181 + x_ret18);
        if (value31 < 0x0F) {
            if (x_ret17) {
                a_hi_42f1 = a_all10 >> 8;
                x_42f1 = (uint8_t)x_ret18;
                y_42f1 = (uint8_t)y_ret9;
                carry_42f1 = value31 >= 0x0F;
                overflow_42f1 = overflow_ret9;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all10 >> 8;
                x_42f12 = x_ret18;
                y_42f12 = y_ret9;
                carry_42f12 = value31 >= 0x0F;
                overflow_42f12 = overflow_ret9;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page_42ab + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)(value32 + 1));
        if (value31 < 0x19) {
            if (x_ret17) {
                a_hi_42f1 = a_all10 >> 8;
                x_42f1 = (uint8_t)x_ret18;
                y_42f1 = (uint8_t)y_ret9;
                carry_42f1 = value31 >= 0x19;
                overflow_42f1 = overflow_ret9;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all10 >> 8;
                x_42f12 = x_ret18;
                y_42f12 = y_ret9;
                carry_42f12 = value31 >= 0x19;
                overflow_42f12 = overflow_ret9;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        uint8_t value33 = BUS8_RDP(c, (uint16_t)(direct_page_42ab + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)(value33 + 1));
        if (value31 < 0x1E) {
            if (x_ret17) {
                a_hi_42f1 = a_all10 >> 8;
                x_42f1 = (uint8_t)x_ret18;
                y_42f1 = (uint8_t)y_ret9;
                carry_42f1 = value31 >= 0x1E;
                overflow_42f1 = overflow_ret9;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all10 >> 8;
                x_42f12 = x_ret18;
                y_42f12 = y_ret9;
                carry_42f12 = value31 >= 0x1E;
                overflow_42f12 = overflow_ret9;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(direct_page_42ab + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)(value34 + 1));
        if (value31 < 0x24) {
            if (x_ret17) {
                a_hi_42f1 = a_all10 >> 8;
                x_42f1 = (uint8_t)x_ret18;
                y_42f1 = (uint8_t)y_ret9;
                carry_42f1 = value31 >= 0x24;
                overflow_42f1 = overflow_ret9;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all10 >> 8;
                x_42f12 = x_ret18;
                y_42f12 = y_ret9;
                carry_42f12 = value31 >= 0x24;
                overflow_42f12 = overflow_ret9;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        uint8_t value35 = BUS8_RDP(c, (uint16_t)(direct_page_42ab + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)(value35 + 1));
        r->a = (a_all10 >> 8 << 8) | value31;
        r->c = value31 >= 0x24;
        r->z = (uint8_t)(value35 + 1) == 0;
        r->n = (uint8_t)(value35 + 1) & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x42EA, 0xC038A0); GUARD_JSR(c, sp_call, 0x42EA); } /* advance_additive_random_generator */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret19 = r->xf;
        uint16_t a_all11 = r->a;
        uint16_t x_ret20 = r->x;
        uint16_t y_ret10 = r->y;
        bool overflow_ret10 = r->v;
        if ((uint8_t)a_all11 >= 0x20) {
            if (x_ret19) {
                a_hi_42f1 = a_all11 >> 8;
                x_42f1 = (uint8_t)x_ret20;
                y_42f1 = (uint8_t)y_ret10;
                carry_42f1 = (uint8_t)a_all11 >= 0x20;
                overflow_42f1 = overflow_ret10;
                direct_page_42f1 = direct_page_42ab;
                data_bank_42f1 = data_bank_42ab;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all11 >> 8;
                x_42f12 = x_ret20;
                y_42f12 = y_ret10;
                carry_42f12 = (uint8_t)a_all11 >= 0x20;
                overflow_42f12 = overflow_ret10;
                direct_page_42f12 = direct_page_42ab;
                data_bank_42f12 = data_bank_42ab;
                goto shared_42F1_1;
            }
        }
        uint8_t value36 = BUS8_RDP(c, (uint16_t)(direct_page_42ab + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab + 0xA4), (uint8_t)(value36 + 1));
        if (x_ret19) {
            a_hi_42f1 = a_all11 >> 8;
            x_42f1 = (uint8_t)x_ret20;
            y_42f1 = (uint8_t)y_ret10;
            carry_42f1 = (uint8_t)a_all11 >= 0x20;
            overflow_42f1 = overflow_ret10;
            direct_page_42f1 = direct_page_42ab;
            data_bank_42f1 = data_bank_42ab;
            goto shared_42F1;
        } else {
            a_hi_42f12 = a_all11 >> 8;
            x_42f12 = x_ret20;
            y_42f12 = y_ret10;
            carry_42f12 = (uint8_t)a_all11 >= 0x20;
            overflow_42f12 = overflow_ret10;
            direct_page_42f12 = direct_page_42ab;
            data_bank_42f12 = data_bank_42ab;
            goto shared_42F1_1;
        }
    }
    a_42fd = (uint8_t)(value29 - 1);
    a_hi_42fd = a_hi_42ab;
    x_42fd = x_42ab;
    y_42fd = y_42ab;
    carry_42fd = carry_42ab;
    overflow_42fd = overflow_42ab;
    direct_page_42fd = direct_page_42ab;
    data_bank_42fd = data_bank_42ab;
    goto shared_42FD;
    shared_42AB_1:;
    BUS8_SET(c, (data_bank_42ab2 << 0x10) + 0xE1B1 + x_42ab2, 0x80);
    BUS8_SET(c, (data_bank_42ab2 << 0x10) + 0xE1B0 + x_42ab2, 0);
    uint8_t value37 = BUS8_RDP(c, (data_bank_42ab2 << 0x10) + 0xE1CF + x_42ab2);
    if (value37 == 0) {
        r->a = (a_hi_42ab2 << 8) | 3;
        r->x = x_42ab2;
        r->y = y_42ab2;
        r->c = carry_42ab2;
        r->z = 0;
        r->n = 0;
        r->v = overflow_42ab2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_42ab2;
        r->dp = direct_page_42ab2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x42BF, 0xC03888); GUARD_JSR(c, sp_call, 0x42BF); } /* random_below_byte */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret21 = r->xf;
        uint16_t a_all12 = r->a;
        uint16_t x_ret22 = r->x;
        uint16_t y_ret11 = r->y;
        bool overflow_ret11 = r->v;
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)a_all12);
        uint8_t value38 = BUS8_RDP(c, (data_bank_42ab2 << 0x10) + 0xE181 + x_ret22);
        if (value38 < 0x0A) {
            if (x_ret21) {
                a_hi_42f1 = a_all12 >> 8;
                x_42f1 = (uint8_t)x_ret22;
                y_42f1 = (uint8_t)y_ret11;
                carry_42f1 = value38 >= 0x0A;
                overflow_42f1 = overflow_ret11;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all12 >> 8;
                x_42f12 = x_ret22;
                y_42f12 = y_ret11;
                carry_42f12 = value38 >= 0x0A;
                overflow_42f12 = overflow_ret11;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), 2);
        uint8_t value39 = BUS8_RDP(c, (data_bank_42ab2 << 0x10) + 0xE181 + x_ret22);
        if (value39 < 0x0F) {
            if (x_ret21) {
                a_hi_42f1 = a_all12 >> 8;
                x_42f1 = (uint8_t)x_ret22;
                y_42f1 = (uint8_t)y_ret11;
                carry_42f1 = value39 >= 0x0F;
                overflow_42f1 = overflow_ret11;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all12 >> 8;
                x_42f12 = x_ret22;
                y_42f12 = y_ret11;
                carry_42f12 = value39 >= 0x0F;
                overflow_42f12 = overflow_ret11;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        uint8_t value40 = BUS8_RDP(c, (uint16_t)(direct_page_42ab2 + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)(value40 + 1));
        if (value39 < 0x19) {
            if (x_ret21) {
                a_hi_42f1 = a_all12 >> 8;
                x_42f1 = (uint8_t)x_ret22;
                y_42f1 = (uint8_t)y_ret11;
                carry_42f1 = value39 >= 0x19;
                overflow_42f1 = overflow_ret11;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all12 >> 8;
                x_42f12 = x_ret22;
                y_42f12 = y_ret11;
                carry_42f12 = value39 >= 0x19;
                overflow_42f12 = overflow_ret11;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        uint8_t value41 = BUS8_RDP(c, (uint16_t)(direct_page_42ab2 + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)(value41 + 1));
        if (value39 < 0x1E) {
            if (x_ret21) {
                a_hi_42f1 = a_all12 >> 8;
                x_42f1 = (uint8_t)x_ret22;
                y_42f1 = (uint8_t)y_ret11;
                carry_42f1 = value39 >= 0x1E;
                overflow_42f1 = overflow_ret11;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all12 >> 8;
                x_42f12 = x_ret22;
                y_42f12 = y_ret11;
                carry_42f12 = value39 >= 0x1E;
                overflow_42f12 = overflow_ret11;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        uint8_t value42 = BUS8_RDP(c, (uint16_t)(direct_page_42ab2 + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)(value42 + 1));
        if (value39 < 0x24) {
            if (x_ret21) {
                a_hi_42f1 = a_all12 >> 8;
                x_42f1 = (uint8_t)x_ret22;
                y_42f1 = (uint8_t)y_ret11;
                carry_42f1 = value39 >= 0x24;
                overflow_42f1 = overflow_ret11;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all12 >> 8;
                x_42f12 = x_ret22;
                y_42f12 = y_ret11;
                carry_42f12 = value39 >= 0x24;
                overflow_42f12 = overflow_ret11;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        uint8_t value43 = BUS8_RDP(c, (uint16_t)(direct_page_42ab2 + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)(value43 + 1));
        r->a = (a_all12 >> 8 << 8) | value39;
        r->c = value39 >= 0x24;
        r->z = (uint8_t)(value43 + 1) == 0;
        r->n = (uint8_t)(value43 + 1) & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x42EA, 0xC038A0); GUARD_JSR(c, sp_call, 0x42EA); } /* advance_additive_random_generator */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret23 = r->xf;
        uint16_t a_all13 = r->a;
        uint16_t x_ret24 = r->x;
        uint16_t y_ret12 = r->y;
        bool overflow_ret12 = r->v;
        if ((uint8_t)a_all13 >= 0x20) {
            if (x_ret23) {
                a_hi_42f1 = a_all13 >> 8;
                x_42f1 = (uint8_t)x_ret24;
                y_42f1 = (uint8_t)y_ret12;
                carry_42f1 = (uint8_t)a_all13 >= 0x20;
                overflow_42f1 = overflow_ret12;
                direct_page_42f1 = direct_page_42ab2;
                data_bank_42f1 = data_bank_42ab2;
                goto shared_42F1;
            } else {
                a_hi_42f12 = a_all13 >> 8;
                x_42f12 = x_ret24;
                y_42f12 = y_ret12;
                carry_42f12 = (uint8_t)a_all13 >= 0x20;
                overflow_42f12 = overflow_ret12;
                direct_page_42f12 = direct_page_42ab2;
                data_bank_42f12 = data_bank_42ab2;
                goto shared_42F1_1;
            }
        }
        uint8_t value44 = BUS8_RDP(c, (uint16_t)(direct_page_42ab2 + 0xA4));
        BUS8_SET(c, (uint16_t)(direct_page_42ab2 + 0xA4), (uint8_t)(value44 + 1));
        if (x_ret23) {
            a_hi_42f1 = a_all13 >> 8;
            x_42f1 = (uint8_t)x_ret24;
            y_42f1 = (uint8_t)y_ret12;
            carry_42f1 = (uint8_t)a_all13 >= 0x20;
            overflow_42f1 = overflow_ret12;
            direct_page_42f1 = direct_page_42ab2;
            data_bank_42f1 = data_bank_42ab2;
            goto shared_42F1;
        } else {
            a_hi_42f12 = a_all13 >> 8;
            x_42f12 = x_ret24;
            y_42f12 = y_ret12;
            carry_42f12 = (uint8_t)a_all13 >= 0x20;
            overflow_42f12 = overflow_ret12;
            direct_page_42f12 = direct_page_42ab2;
            data_bank_42f12 = data_bank_42ab2;
            goto shared_42F1_1;
        }
    }
    a_42fd2 = (uint8_t)(value37 - 1);
    a_hi_42fd2 = a_hi_42ab2;
    x_42fd2 = x_42ab2;
    y_42fd2 = y_42ab2;
    carry_42fd2 = carry_42ab2;
    overflow_42fd2 = overflow_42ab2;
    direct_page_42fd2 = direct_page_42ab2;
    data_bank_42fd2 = data_bank_42ab2;
    goto shared_42FD_1;
    shared_42F1:;
    RAM8(0x0000 + sp0) = x_42f1;
    uint8_t value45 = BUS8_RDP(c, (uint16_t)(direct_page_42f1 + 0xA4));
    uint8_t value46 = BUS8(c, 0xC0430D + value45);
    a_42fd = value46;
    a_hi_42fd = 0;
    x_42fd = x_42f1;
    y_42fd = y_42f1;
    carry_42fd = carry_42f1;
    overflow_42fd = overflow_42f1;
    direct_page_42fd = direct_page_42f1;
    data_bank_42fd = data_bank_42f1;
    goto shared_42FD;
    shared_42F1_1:;
    RAM8(0x0000 + sp0) = x_42f12 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_42f12;
    uint8_t value47 = BUS8_RDP(c, (uint16_t)(direct_page_42f12 + 0xA4));
    uint8_t value48 = BUS8(c, 0xC0430D + value47);
    a_42fd2 = value48;
    a_hi_42fd2 = 0;
    x_42fd2 = x_42f12;
    y_42fd2 = y_42f12;
    carry_42fd2 = carry_42f12;
    overflow_42fd2 = overflow_42f12;
    direct_page_42fd2 = direct_page_42f12;
    data_bank_42fd2 = data_bank_42f12;
    goto shared_42FD_1;
    shared_42FD:;
    BUS8_SET(c, (data_bank_42fd << 0x10) + 0xE1C8 + x_42fd, a_42fd);
    uint8_t value49 = BUS8_RDP(c, (data_bank_42fd << 0x10) + 0xE1E7 + x_42fd);
    BUS8_SET(c, (data_bank_42fd << 0x10) + 0xE1CA + x_42fd, value49);
    BUS8_SET(c, (data_bank_42fd << 0x10) + 0xE181 + x_42fd, 0);
    BUS8_SET(c, (data_bank_42fd << 0x10) + 0xE184 + x_42fd, 0);
    r->a = (a_hi_42fd << 8) | value49;
    r->x = x_42fd;
    r->y = y_42fd;
    r->c = carry_42fd;
    r->v = overflow_42fd;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_42fd;
    r->dp = direct_page_42fd;
    RETURN_RTS(c);
    shared_42FD_1:;
    BUS8_SET(c, (data_bank_42fd2 << 0x10) + 0xE1C8 + x_42fd2, a_42fd2);
    uint8_t value50 = BUS8_RDP(c, (data_bank_42fd2 << 0x10) + 0xE1E7 + x_42fd2);
    BUS8_SET(c, (data_bank_42fd2 << 0x10) + 0xE1CA + x_42fd2, value50);
    BUS8_SET(c, (data_bank_42fd2 << 0x10) + 0xE181 + x_42fd2, 0);
    BUS8_SET(c, (data_bank_42fd2 << 0x10) + 0xE184 + x_42fd2, 0);
    r->a = (a_hi_42fd2 << 8) | value50;
    r->x = x_42fd2;
    r->y = y_42fd2;
    r->c = carry_42fd2;
    r->v = overflow_42fd2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_42fd2;
    r->dp = direct_page_42fd2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04203, SOM_RTS, "gen", process_actor_death_rewards_and_drop_conversion, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 266, 115)
