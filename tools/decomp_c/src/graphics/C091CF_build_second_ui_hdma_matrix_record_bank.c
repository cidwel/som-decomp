#include "som_c.h"

/* C091CF build_second_ui_hdma_matrix_record_bank   [class B, 205 bytes, 103 instructions]
 * Source: src/rom/build_second_ui_hdma_matrix_record_bank.s
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: BYCV.
 */
static void build_second_ui_hdma_matrix_record_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 7));
    BUS16_SET(c, (db << 0x10) + 0x1700, value);
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = x;
    bool carry1 = carry;
    for (;;) {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 4));
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 6));
        BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(value2 + value3 + carry1));
        if (value2 + value3 + carry1 > 0xFFFF) {
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 8));
            BUS16_RMW_SET(c, (uint16_t)(dp + 8), (uint16_t)(value4 + 1));
        }
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 7));
        BUS16_SET(c, (db << 0x10) + 0x1700 + x1, value5);
        uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0x4214);
        BUS8_SET(c, (db << 0x10) + 0x4202, value6);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0x35));
        BUS8_SET(c, (db << 0x10) + 0x4203, value7);
        uint16_t value8 = BUS16_RDP(c, dp);
        BUS16_RMW_SET(c, dp, (uint16_t)(value8 + 1));
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0x34));
        uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0x4216);
        BUS8_SET(c, (db << 0x10) + 0x4203, value9);
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0x4B));
        uint8_t a1;
        uint8_t a_hi2;
        if (!(value11 & 0x8000)) {
            a1 = (uint8_t)(value10 >> 6);
            a_hi2 = value10 >> 6 >> 8;
        } else {
            a1 = (uint8_t)((value10 >> 6) ^ 0xFFFF);
            a_hi2 = ((value10 >> 6) ^ 0xFFFF) >> 8;
        }
        BUS16_SET(c, (db << 0x10) + 0x1400 + x1, (a_hi2 << 8) | a1);
        uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0x4216);
        uint8_t value13 = BUS8_RDP(c, dp);
        BUS8_SET(c, (db << 0x10) + 0x4206, value13);
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 0x4B));
        uint8_t a_hi4;
        uint8_t x3;
        if (!(value14 & 0x4000)) {
            BUS16_SET(c, (db << 0x10) + 0x1600 + x1, value12 >> 6);
            BUS16_SET(c, (db << 0x10) + 0x1500 + x1, (value12 >> 6) ^ 0xFFFF);
            if ((uint8_t)(x1 + 2) != 0) {
                a_hi1 = ((value12 >> 6) ^ 0xFFFF) >> 8;
                x1 = (uint8_t)(x1 + 2);
                carry1 = value12 >> 5 & 0x01;
                continue;
            }
            a_hi4 = ((value12 >> 6) ^ 0xFFFF) >> 8;
            x3 = (uint8_t)(x1 + 2);
        } else {
            BUS16_SET(c, (db << 0x10) + 0x1500 + x1, value12 >> 6);
            BUS16_SET(c, (db << 0x10) + 0x1600 + x1, (value12 >> 6) ^ 0xFFFF);
            if ((uint8_t)(x1 + 2) != 0) {
                a_hi1 = ((value12 >> 6) ^ 0xFFFF) >> 8;
                x1 = (uint8_t)(x1 + 2);
                carry1 = value12 >> 5 & 0x01;
                continue;
            }
            uint8_t a_hi3;
            uint8_t x2;
            if ((uint8_t)(x1 + 2) == 0) {
                a_hi3 = ((value12 >> 6) ^ 0xFFFF) >> 8;
                x2 = (uint8_t)(x1 + 2);
            } else {
                BUS16_SET(c, (db << 0x10) + 0x1600 + (uint8_t)(x1 + 2), (value12 >> 6) ^ 0xFFFF);
                BUS16_SET(c, (db << 0x10) + 0x1500 + (uint8_t)(x1 + 2), (value12 >> 6) ^ 0xFFFF ^ 0xFFFF);
                if ((uint8_t)(x1 + 4) != 0) {
                    a_hi1 = ((value12 >> 6) ^ 0xFFFF ^ 0xFFFF) >> 8;
                    x1 = (uint8_t)(x1 + 4);
                    carry1 = value12 >> 5 & 0x01;
                    continue;
                }
                a_hi3 = ((value12 >> 6) ^ 0xFFFF ^ 0xFFFF) >> 8;
                x2 = (uint8_t)(x1 + 4);
            }
            a_hi4 = a_hi3;
            x3 = x2;
        }
        a_hi1 = a_hi4;
        x1 = x3;
        carry1 = value12 >> 5 & 0x01;
        break;
    }
    uint8_t a_hi5 = a_hi1;
    uint8_t x4 = x1;
    uint8_t y1 = 0;
    bool carry2 = carry1;
    bool overflow1 = 0;
    for (;;) {
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp + 4));
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp + 6));
        BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(value15 + value16 + carry2));
        if (value15 + value16 + carry2 > 0xFFFF) {
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 8));
            BUS16_RMW_SET(c, (uint16_t)(dp + 8), (uint16_t)(value17 + 1));
        }
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 7));
        BUS16_SET(c, (db << 0x10) + 0x0DC0 + x4, value18);
        uint8_t value19 = BUS8_RDP(c, (db << 0x10) + 0x4214);
        BUS8_SET(c, (db << 0x10) + 0x4202, value19);
        uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 0x35));
        BUS8_SET(c, (db << 0x10) + 0x4203, value20);
        uint16_t value21 = BUS16_RDP(c, dp);
        BUS16_RMW_SET(c, dp, (uint16_t)(value21 + 1));
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 0x34));
        uint16_t value23 = BUS16_RDP(c, (db << 0x10) + 0x4216);
        BUS8_SET(c, (db << 0x10) + 0x4203, value22);
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp + 0x4B));
        uint8_t a2;
        uint8_t a_hi6;
        if (!(value24 & 0x8000)) {
            a2 = (uint8_t)(value23 >> 6);
            a_hi6 = value23 >> 6 >> 8;
        } else {
            a2 = (uint8_t)((value23 >> 6) ^ 0xFFFF);
            a_hi6 = ((value23 >> 6) ^ 0xFFFF) >> 8;
        }
        BUS16_SET(c, (db << 0x10) + 0x0D00 + x4, (a_hi6 << 8) | a2);
        uint16_t value25 = BUS16_RDP(c, (db << 0x10) + 0x4216);
        uint8_t value26 = BUS8_RDP(c, dp);
        BUS8_SET(c, (db << 0x10) + 0x4206, value26);
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp + 0x4B));
        if (!(value27 & 0x4000)) {
            BUS16_SET(c, (db << 0x10) + 0x0D80 + x4, value25 >> 6);
            BUS16_SET(c, (db << 0x10) + 0x0D40 + x4, (value25 >> 6) ^ 0xFFFF);
            uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
            if ((uint8_t)(x4 + 2) < value28) {
                uint8_t a_hi5_next = ((value25 >> 6) ^ 0xFFFF) >> 8;
                uint8_t x4_next = (uint8_t)(x4 + 2);
                uint8_t y1_next = value26;
                bool carry2_next = (uint8_t)(x4 + 2) >= value28;
                bool overflow1_next = value27 & 0x4000;
                a_hi5 = a_hi5_next;
                x4 = x4_next;
                y1 = y1_next;
                carry2 = carry2_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi5_next3 = ((value25 >> 6) ^ 0xFFFF) >> 8;
            uint8_t x4_next3 = (uint8_t)(x4 + 2);
            uint8_t y1_next3 = value26;
            bool carry2_next3 = (uint8_t)(x4 + 2) >= value28;
            bool overflow1_next3 = value27 & 0x4000;
            a_hi5 = a_hi5_next3;
            x4 = x4_next3;
            y1 = y1_next3;
            carry2 = carry2_next3;
            overflow1 = overflow1_next3;
            break;
        }
        BUS16_SET(c, (db << 0x10) + 0x0D40 + x4, value25 >> 6);
        BUS16_SET(c, (db << 0x10) + 0x0D80 + x4, (value25 >> 6) ^ 0xFFFF);
        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
        if ((uint8_t)(x4 + 2) < value29) {
            uint8_t a_hi5_next2 = ((value25 >> 6) ^ 0xFFFF) >> 8;
            uint8_t x4_next2 = (uint8_t)(x4 + 2);
            uint8_t y1_next2 = value26;
            bool carry2_next2 = (uint8_t)(x4 + 2) >= value29;
            bool overflow1_next2 = value27 & 0x4000;
            a_hi5 = a_hi5_next2;
            x4 = x4_next2;
            y1 = y1_next2;
            carry2 = carry2_next2;
            overflow1 = overflow1_next2;
            continue;
        }
        r->a = (value25 >> 6) ^ 0xFFFF;
        r->y = value26;
        r->c = (uint8_t)(x4 + 2) >= value29;
        r->v = value27 & 0x4000;
        RETURN_RTS(c);
    }
    r->a = (a_hi5 << 8) | (uint8_t)a;
    r->y = y1;
    r->c = carry2;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC091CF, SOM_RTS, "gen", build_second_ui_hdma_matrix_record_bank, 0, L_B | L_Y | L_C | L_V, 1, 0, 1, 205, 103)
