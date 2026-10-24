#include "som_c.h"

/* C0445B award_hero_experience_and_rebuild_each_level   [class B, 149 bytes, 65 instructions]
 * Source: src/rom/award_hero_experience_and_rebuild_each_level.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void award_hero_experience_and_rebuild_each_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0384) = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0x0300;
    for (;;) {
        uint16_t value = BUS16_RDP(c, (uint16_t)(direct_page + 0x83));
        uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0xE000 + value);
        if (value2 != 1) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page + 0x84));
            BUS8_SET(c, (uint16_t)(direct_page + 0x84), (uint8_t)(value3 - 1));
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 0x84));
            BUS8_SET(c, (uint16_t)(direct_page + 0x84), (uint8_t)(value4 - 1));
            if (!((uint8_t)(value4 - 1) & 0x80)) {
                carry1 = value2 >= 1;
                continue;
            }
            r->a = (a_hi1 << 8) | value2;
            r->y = y1;
            r->c = value2 >= 1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
        uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 0xE182 + value);
        if (value5 == 0) {
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page + 0x84));
            BUS8_SET(c, (uint16_t)(direct_page + 0x84), (uint8_t)(value6 - 1));
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(direct_page + 0x84));
            BUS8_SET(c, (uint16_t)(direct_page + 0x84), (uint8_t)(value7 - 1));
            if (!((uint8_t)(value7 - 1) & 0x80)) {
                y1 = value5;
                carry1 = value2 >= 1;
                continue;
            }
            r->a = (a_hi1 << 8) | value2;
            r->y = value5;
            r->c = value2 >= 1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(direct_page + 0x85));
        uint16_t value9 = BUS16_RDP(c, (data_bank << 0x10) + 0xE18D + value8);
        uint16_t value10 = BUS16_RDP(c, (data_bank << 0x10) + 0xE18D + value);
        BUS16_SET(c, (uint16_t)(direct_page + 0xD0), (uint16_t)(value9 + value10));
        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0xE18F + value);
        BUS8_SET(c, (uint16_t)(direct_page + 0xD2), (uint8_t)(value11 + (value9 + value10 > 0xFFFF)));
        r->a = ((uint16_t)(value9 + value10) >> 8 << 8) | (uint8_t)(value11 + (value9 + value10 > 0xFFFF));
        r->x = value;
        r->y = value8;
        r->c = value11 + (value9 + value10 > 0xFFFF) > 0xFF;
        r->z = (uint8_t)(value11 + (value9 + value10 > 0xFFFF)) == 0;
        r->n = (uint8_t)(value11 + (value9 + value10 > 0xFFFF)) & 0x80;
        r->v = ((uint8_t)(value11 + (value9 + value10 > 0xFFFF)) & (value11 ^ (uint8_t)(value11 + (value9 + value10 > 0xFFFF))) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0x448E, 0xC039A4); GUARD_JSR(c, sp_call, 0x448E); } /* cap_combat_24bit_value_at_9999999 */
        bool carry_ret = r->c;
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 0xD0));
        BUS16_SET(c, (data_bank << 0x10) + 0xE18D + value, value12);
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page + 0xD2));
        BUS8_SET(c, (data_bank << 0x10) + 0xE18F + value, value13);
        uint8_t a_hi2 = value12 >> 8;
        uint16_t x1 = value;
        uint16_t y2 = value8;
        bool carry2 = carry_ret;
        bool overflow2 = ((uint8_t)(value11 + (value9 + value10 > 0xFFFF)) & (value11 ^ (uint8_t)(value11 + (value9 + value10 > 0xFFFF))) & 0x80) != 0;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            uint8_t value14 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
            bool m_flag3;
            uint8_t a_hi5;
            bool carry5;
            if (value14 == 0x62) {
                m_flag3 = 1;
                a_hi5 = a_hi2;
                carry5 = value14 >= 0x62;
            } else {
                uint8_t value15 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE17F + x1);
                uint8_t value16 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE18F + x1);
                bool m_flag2;
                uint8_t a_hi4;
                bool carry4;
                if (value15 == value16) {
                    if (value15 < value16) {
                        uint8_t value17 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                        BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value17 + 1));
                        r->a = (a_hi2 << 8) | (uint8_t)(value17 + 1);
                        r->x = x1;
                        r->y = y2;
                        r->c = value15 >= value16;
                        r->z = (uint8_t)(value17 + 1) == 0;
                        r->n = (uint8_t)(value17 + 1) & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank2;
                        r->dp = direct_page2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                        uint16_t dp_ret = r->dp;
                        uint8_t db_ret = r->db;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                        uint16_t a_all3 = r->a;
                        r->a = (a_all3 >> 8 << 8) | 0xAF;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                        bool x_ret5 = r->xf;
                        uint16_t x_ret6 = r->x;
                        uint16_t y_ret3 = r->y;
                        bool carry_ret4 = r->c;
                        bool overflow_ret3 = r->v;
                        uint16_t value18 = BUS16_RDP(c, (db_ret << 0x10) + 0xE184 + x_ret6);
                        BUS16_SET(c, (db_ret << 0x10) + 0xE182 + x_ret6, value18);
                        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x80));
                        BUS8_SET(c, (uint16_t)(dp_ret + 0x80), value19 | 0x40);
                        if (x_ret5 != 0) { c->fail = 3; return; }
                        a_hi2 = value18 >> 8;
                        x1 = x_ret6;
                        y2 = y_ret3;
                        carry2 = carry_ret4;
                        overflow2 = overflow_ret3;
                        data_bank2 = db_ret;
                        direct_page2 = dp_ret;
                        continue;
                    }
                    uint16_t value20 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE17D + x1);
                    uint16_t value21 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE18D + x1);
                    if (value20 == value21) {
                        uint8_t value22 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                        BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value22 + 1));
                        r->a = (value20 >> 8 << 8) | (uint8_t)(value22 + 1);
                        r->x = x1;
                        r->y = y2;
                        r->c = value20 >= value21;
                        r->z = (uint8_t)(value22 + 1) == 0;
                        r->n = (uint8_t)(value22 + 1) & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank2;
                        r->dp = direct_page2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                        uint16_t a_all6 = r->a;
                        r->a = (a_all6 >> 8 << 8) | 0xAF;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                        bool x_ret11 = r->xf;
                        uint16_t x_ret12 = r->x;
                        uint16_t y_ret6 = r->y;
                        bool carry_ret7 = r->c;
                        bool overflow_ret6 = r->v;
                        uint16_t value23 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE184 + x_ret12);
                        BUS16_SET(c, (db_ret2 << 0x10) + 0xE182 + x_ret12, value23);
                        uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x80));
                        BUS8_SET(c, (uint16_t)(dp_ret2 + 0x80), value24 | 0x40);
                        if (x_ret11 != 0) { c->fail = 3; return; }
                        a_hi2 = value23 >> 8;
                        x1 = x_ret12;
                        y2 = y_ret6;
                        carry2 = carry_ret7;
                        overflow2 = overflow_ret6;
                        data_bank2 = db_ret2;
                        direct_page2 = dp_ret2;
                        continue;
                    }
                    if (value20 < value21) {
                        uint8_t value25 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                        BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value25 + 1));
                        r->a = (value20 >> 8 << 8) | (uint8_t)(value25 + 1);
                        r->x = x1;
                        r->y = y2;
                        r->c = value20 >= value21;
                        r->z = (uint8_t)(value25 + 1) == 0;
                        r->n = (uint8_t)(value25 + 1) & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank2;
                        r->dp = direct_page2;
                        { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                        uint16_t dp_ret3 = r->dp;
                        uint8_t db_ret3 = r->db;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                        uint16_t a_all9 = r->a;
                        r->a = (a_all9 >> 8 << 8) | 0xAF;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                        bool x_ret17 = r->xf;
                        uint16_t x_ret18 = r->x;
                        uint16_t y_ret9 = r->y;
                        bool carry_ret10 = r->c;
                        bool overflow_ret9 = r->v;
                        uint16_t value26 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE184 + x_ret18);
                        BUS16_SET(c, (db_ret3 << 0x10) + 0xE182 + x_ret18, value26);
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x80));
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x80), value27 | 0x40);
                        if (x_ret17 != 0) { c->fail = 3; return; }
                        a_hi2 = value26 >> 8;
                        x1 = x_ret18;
                        y2 = y_ret9;
                        carry2 = carry_ret10;
                        overflow2 = overflow_ret9;
                        data_bank2 = db_ret3;
                        direct_page2 = dp_ret3;
                        continue;
                    }
                    m_flag2 = 0;
                    a_hi4 = value20 >> 8;
                    carry4 = value20 >= value21;
                } else {
                    bool m_flag;
                    uint8_t a_hi3;
                    bool carry3;
                    if (value15 >= value16) {
                        m_flag = 1;
                        a_hi3 = a_hi2;
                        carry3 = value15 >= value16;
                    } else {
                        if (value15 < value16) {
                            uint8_t value28 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                            BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value28 + 1));
                            r->a = (a_hi2 << 8) | (uint8_t)(value28 + 1);
                            r->x = x1;
                            r->y = y2;
                            r->c = value15 >= value16;
                            r->z = (uint8_t)(value28 + 1) == 0;
                            r->n = (uint8_t)(value28 + 1) & 0x80;
                            r->v = overflow2;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = data_bank2;
                            r->dp = direct_page2;
                            { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                            uint16_t dp_ret4 = r->dp;
                            uint8_t db_ret4 = r->db;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                            uint16_t a_all12 = r->a;
                            r->a = (a_all12 >> 8 << 8) | 0xAF;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                            bool x_ret23 = r->xf;
                            uint16_t x_ret24 = r->x;
                            uint16_t y_ret12 = r->y;
                            bool carry_ret13 = r->c;
                            bool overflow_ret12 = r->v;
                            uint16_t value29 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xE184 + x_ret24);
                            BUS16_SET(c, (db_ret4 << 0x10) + 0xE182 + x_ret24, value29);
                            uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0x80));
                            BUS8_SET(c, (uint16_t)(dp_ret4 + 0x80), value30 | 0x40);
                            if (x_ret23 != 0) { c->fail = 3; return; }
                            a_hi2 = value29 >> 8;
                            x1 = x_ret24;
                            y2 = y_ret12;
                            carry2 = carry_ret13;
                            overflow2 = overflow_ret12;
                            data_bank2 = db_ret4;
                            direct_page2 = dp_ret4;
                            continue;
                        }
                        uint16_t value31 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE17D + x1);
                        uint16_t value32 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE18D + x1);
                        if (value31 == value32) {
                            uint8_t value33 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                            BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value33 + 1));
                            r->a = (value31 >> 8 << 8) | (uint8_t)(value33 + 1);
                            r->x = x1;
                            r->y = y2;
                            r->c = value31 >= value32;
                            r->z = (uint8_t)(value33 + 1) == 0;
                            r->n = (uint8_t)(value33 + 1) & 0x80;
                            r->v = overflow2;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = data_bank2;
                            r->dp = direct_page2;
                            { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                            uint16_t dp_ret5 = r->dp;
                            uint8_t db_ret5 = r->db;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                            uint16_t a_all15 = r->a;
                            r->a = (a_all15 >> 8 << 8) | 0xAF;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                            bool x_ret29 = r->xf;
                            uint16_t x_ret30 = r->x;
                            uint16_t y_ret15 = r->y;
                            bool carry_ret16 = r->c;
                            bool overflow_ret15 = r->v;
                            uint16_t value34 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xE184 + x_ret30);
                            BUS16_SET(c, (db_ret5 << 0x10) + 0xE182 + x_ret30, value34);
                            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 0x80));
                            BUS8_SET(c, (uint16_t)(dp_ret5 + 0x80), value35 | 0x40);
                            if (x_ret29 != 0) { c->fail = 3; return; }
                            a_hi2 = value34 >> 8;
                            x1 = x_ret30;
                            y2 = y_ret15;
                            carry2 = carry_ret16;
                            overflow2 = overflow_ret15;
                            data_bank2 = db_ret5;
                            direct_page2 = dp_ret5;
                            continue;
                        }
                        if (value31 < value32) {
                            uint8_t value36 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE181 + x1);
                            BUS8_SET(c, (data_bank2 << 0x10) + 0xE181 + x1, (uint8_t)(value36 + 1));
                            r->a = (value31 >> 8 << 8) | (uint8_t)(value36 + 1);
                            r->x = x1;
                            r->y = y2;
                            r->c = value31 >= value32;
                            r->z = (uint8_t)(value36 + 1) == 0;
                            r->n = (uint8_t)(value36 + 1) & 0x80;
                            r->v = overflow2;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = data_bank2;
                            r->dp = direct_page2;
                            { const uint16_t sp_call = r->sp; JSL(c, 0x44C8, 0xC04530); GUARD_JSL(c, sp_call, 0x44C8); } /* rebuild_actor_attributes_native */
                            uint16_t dp_ret6 = r->dp;
                            uint8_t db_ret6 = r->db;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44CB, 0xC05B20); GUARD_JSR(c, sp_call, 0x44CB); } /* enqueue_actor_level_up_notice */
                            uint16_t a_all18 = r->a;
                            r->a = (a_all18 >> 8 << 8) | 0xAF;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x44D0, 0xC0398D); GUARD_JSR(c, sp_call, 0x44D0); } /* send_combat_sound_with_fixed_parameter_fifteen */
                            bool x_ret35 = r->xf;
                            uint16_t x_ret36 = r->x;
                            uint16_t y_ret18 = r->y;
                            bool carry_ret19 = r->c;
                            bool overflow_ret18 = r->v;
                            uint16_t value37 = BUS16_RDP(c, (db_ret6 << 0x10) + 0xE184 + x_ret36);
                            BUS16_SET(c, (db_ret6 << 0x10) + 0xE182 + x_ret36, value37);
                            uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x80));
                            BUS8_SET(c, (uint16_t)(dp_ret6 + 0x80), value38 | 0x40);
                            if (x_ret35 != 0) { c->fail = 3; return; }
                            a_hi2 = value37 >> 8;
                            x1 = x_ret36;
                            y2 = y_ret18;
                            carry2 = carry_ret19;
                            overflow2 = overflow_ret18;
                            data_bank2 = db_ret6;
                            direct_page2 = dp_ret6;
                            continue;
                        }
                        m_flag = 0;
                        a_hi3 = value31 >> 8;
                        carry3 = value31 >= value32;
                    }
                    m_flag2 = m_flag;
                    a_hi4 = a_hi3;
                    carry4 = carry3;
                }
                m_flag3 = m_flag2;
                a_hi5 = a_hi4;
                carry5 = carry4;
            }
            a_hi2 = a_hi5;
            carry2 = carry5;
            break;
        }
        uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page2 + 0x84));
        BUS8_SET(c, (uint16_t)(direct_page2 + 0x84), (uint8_t)(value39 - 1));
        uint8_t value40 = BUS8_RDP(c, (uint16_t)(direct_page2 + 0x84));
        BUS8_SET(c, (uint16_t)(direct_page2 + 0x84), (uint8_t)(value40 - 1));
        if ((uint8_t)(value40 - 1) & 0x80) {
            a_hi1 = a_hi2;
            y1 = y2;
            carry1 = carry2;
            overflow1 = overflow2;
            data_bank = data_bank2;
            direct_page = direct_page2;
            break;
        }
        a_hi1 = a_hi2;
        y1 = y2;
        carry1 = carry2;
        overflow1 = overflow2;
        data_bank = data_bank2;
        direct_page = direct_page2;
        continue;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0445B, SOM_RTS, "gen", award_hero_experience_and_rebuild_each_level, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 149, 65)
