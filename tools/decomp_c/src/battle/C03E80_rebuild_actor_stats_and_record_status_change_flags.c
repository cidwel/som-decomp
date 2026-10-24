#include "som_c.h"

/* C03E80 rebuild_actor_stats_and_record_status_change_flags   [class B, 136 bytes, 56 instructions]
 * Source: src/rom/rebuild_actor_stats_and_record_status_change_flags.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void rebuild_actor_stats_and_record_status_change_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE1FA + x);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 5) == 0) {
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = x;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM8(ACTOR_SABER_HITS_LEFT + x) = 0;
        r->a = (a_hi << 8) | value;
        r->z = (value & 5) == 0;
        r->n = value & 0x80;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3E8F, 0xC04530); GUARD_JSL(c, sp_call, 0x3E8F); } /* rebuild_actor_attributes_native */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FA + x1);
    if ((value2 & 2) == 0) {
        if (x_flag) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (a_hi1 << 8) | value2;
            r->x = x1;
            r->y = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
    }
    uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FB + x1);
    if ((value3 & 0x40) != 0) {
        if (x_flag) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (a_hi1 << 8) | value3;
            r->x = x1;
            r->y = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
    }
    uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 0xE190 + x1);
    uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 0xE19E + x1);
    if (x_flag) {
        uint8_t a_hi3;
        if (!((uint8_t)(value4 ^ value5) & 0x80)) {
            a_hi3 = (value4 ^ value5) >> 8;
        } else {
            uint16_t value6 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1FA + (uint8_t)x1);
            uint8_t a_hi2;
            if (!(value6 & 0x8000)) {
                a_hi2 = value6 >> 8;
            } else {
                uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1B1 + (uint8_t)x1);
                BUS16_SET(c, (data_bank << 0x10) + 0xE1B1 + (uint8_t)x1, value7 | 8);
                a_hi2 = (value7 | 8) >> 8;
            }
            a_hi3 = a_hi2;
        }
        uint16_t value8 = BUS16_RDP(c, (data_bank << 0x10) + 0xE190 + (uint8_t)x1);
        BUS16_SET(c, (uint16_t)(direct_page + 0xAC), (uint8_t)(value4 ^ value5) & value8);
        uint8_t a_hi4;
        if (((uint8_t)(value4 ^ value5) & value8 & 0x4160) == 0) {
            a_hi4 = 0;
        } else {
            uint16_t value9 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1);
            BUS16_SET(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1, value9 | 2);
            a_hi4 = (value9 | 2) >> 8;
        }
        uint16_t value10 = BUS16_RDP(c, (data_bank << 0x10) + 0xE02C + (uint8_t)x1);
        bool m_flag3;
        uint8_t a_hi5;
        if ((value10 & 0x0F) != 0) {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAC));
            bool m_flag;
            if ((value11 & 0x4160) == 0) {
                m_flag = 0;
            } else {
                uint8_t value12 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1);
                BUS8_SET(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1, value12 | 8);
                m_flag = 1;
            }
            m_flag3 = m_flag;
            a_hi5 = value11 >> 8;
        } else {
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAC));
            bool m_flag2;
            if ((value13 & 0x5760) == 0) {
                m_flag2 = 0;
            } else {
                uint8_t value14 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1);
                BUS8_SET(c, (data_bank << 0x10) + 0xE1FB + (uint8_t)x1, value14 | 8);
                m_flag2 = 1;
            }
            m_flag3 = m_flag2;
            a_hi5 = value13 >> 8;
        }
        uint16_t value15 = BUS16_RDP(c, (data_bank << 0x10) + 0xE190 + (uint8_t)x1);
        BUS16_SET(c, (data_bank << 0x10) + 0xE19E + (uint8_t)x1, value15);
        r->a = value15;
        r->x = (uint8_t)x1;
        r->y = (uint8_t)(value4 ^ value5);
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    } else {
        uint8_t a_hi7;
        if (!((value4 ^ value5) & 0x8000)) {
            a_hi7 = (value4 ^ value5) >> 8;
        } else {
            uint16_t value16 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1FA + x1);
            uint8_t a_hi6;
            if (!(value16 & 0x8000)) {
                a_hi6 = value16 >> 8;
            } else {
                uint16_t value17 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1B1 + x1);
                BUS16_SET(c, (data_bank << 0x10) + 0xE1B1 + x1, value17 | 8);
                a_hi6 = (value17 | 8) >> 8;
            }
            a_hi7 = a_hi6;
        }
        uint16_t value18 = BUS16_RDP(c, (data_bank << 0x10) + 0xE190 + x1);
        BUS16_SET(c, (uint16_t)(direct_page + 0xAC), (value4 ^ value5) & value18);
        uint8_t a_hi8;
        if (((value4 ^ value5) & value18 & 0x4160) == 0) {
            a_hi8 = ((value4 ^ value5) & value18) >> 8;
        } else {
            uint16_t value19 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1FB + x1);
            BUS16_SET(c, (data_bank << 0x10) + 0xE1FB + x1, value19 | 2);
            a_hi8 = (value19 | 2) >> 8;
        }
        uint16_t value20 = BUS16_RDP(c, (data_bank << 0x10) + 0xE02C + x1);
        bool m_flag6;
        uint8_t a_hi9;
        if ((value20 & 0x0F) != 0) {
            uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAC));
            bool m_flag4;
            if ((value21 & 0x4160) == 0) {
                m_flag4 = 0;
            } else {
                uint8_t value22 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FB + x1);
                BUS8_SET(c, (data_bank << 0x10) + 0xE1FB + x1, value22 | 8);
                m_flag4 = 1;
            }
            m_flag6 = m_flag4;
            a_hi9 = value21 >> 8;
        } else {
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAC));
            bool m_flag5;
            if ((value23 & 0x5760) == 0) {
                m_flag5 = 0;
            } else {
                uint8_t value24 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1FB + x1);
                BUS8_SET(c, (data_bank << 0x10) + 0xE1FB + x1, value24 | 8);
                m_flag5 = 1;
            }
            m_flag6 = m_flag5;
            a_hi9 = value23 >> 8;
        }
        uint16_t value25 = BUS16_RDP(c, (data_bank << 0x10) + 0xE190 + x1);
        BUS16_SET(c, (data_bank << 0x10) + 0xE19E + x1, value25);
        r->a = value25;
        r->x = x1;
        r->y = value4 ^ value5;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC03E80, SOM_RTS, "gen", rebuild_actor_stats_and_record_status_change_flags, 0, L_B | L_X | L_Y, 1, 1, 0, 136, 56)
