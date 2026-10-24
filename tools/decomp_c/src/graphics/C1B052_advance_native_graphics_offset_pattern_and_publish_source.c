#include "som_c.h"

/* C1B052 advance_native_graphics_offset_pattern_and_publish_source   [class B, 154 bytes, 74 instructions]
 * Source: src/rom/advance_native_graphics_offset_pattern_and_publish_source.s
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BXYCV.
 */
static void advance_native_graphics_offset_pattern_and_publish_source(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x8003 + x);
    if (value & 0x80) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x8000 + x);
        uint8_t a10;
        uint8_t a_hi6;
        uint8_t y3;
        if (value2 & 0x80) {
            uint8_t a5;
            uint8_t a_hi4;
            uint8_t y1;
            if ((uint8_t)(value2 << 1) & 0x80) {
                uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                uint8_t a2;
                uint8_t a_hi2;
                if (value3 != 0) {
                    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                    BUS16_SET(c, (db << 0x10) + 0x8006 + x, (uint16_t)(value4 + 0x80) & 0x01FF);
                    a2 = (uint8_t)((uint16_t)(value4 + 0x80) & 0x01FF);
                    a_hi2 = ((uint16_t)(value4 + 0x80) & 0x01FF) >> 8;
                } else {
                    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x8001 + x);
                    uint8_t a1;
                    uint8_t a_hi1;
                    if (!(value5 & 0x80)) {
                        BUS8_SET(c, (db << 0x10) + 0x8001 + x, (uint8_t)(value5 - 1));
                        a1 = 0;
                        a_hi1 = 0;
                    } else {
                        uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0xF5));
                        BUS8_SET(c, (db << 0x10) + 0x8001 + x, (uint8_t)(value6 + value7 + (value2 >> 7)) & 0x7F);
                        uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                        BUS16_SET(c, (db << 0x10) + 0x8006 + x, (uint16_t)(value8 + 0x80) & 0x01FF);
                        a1 = (uint8_t)((uint16_t)(value8 + 0x80) & 0x01FF);
                        a_hi1 = ((uint16_t)(value8 + 0x80) & 0x01FF) >> 8;
                    }
                    a2 = a1;
                    a_hi2 = a_hi1;
                }
                a5 = a2;
                a_hi4 = a_hi2;
                y1 = y;
            } else {
                uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0x8001 + x);
                uint8_t a3;
                if ((uint8_t)(value9 + 1) < 3) {
                    a3 = (uint8_t)(value9 + 1);
                } else {
                    a3 = 0;
                }
                BUS8_SET(c, (db << 0x10) + 0x8001 + x, a3);
                uint8_t a4;
                uint8_t a_hi3;
                if ((uint8_t)((a_hi << 8) | value9) != 2) {
                    uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                    a4 = (uint8_t)(value10 + 0x80);
                    a_hi3 = (uint16_t)(value10 + 0x80) >> 8;
                } else {
                    uint16_t value11 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                    a4 = (uint8_t)(value11 - 0x80);
                    a_hi3 = (uint16_t)(value11 - 0x80) >> 8;
                }
                BUS16_SET(c, (db << 0x10) + 0x8006 + x, ((a_hi3 << 8) | a4) & 0x01FF);
                a5 = (uint8_t)(((a_hi3 << 8) | a4) & 0x01FF);
                a_hi4 = (((a_hi3 << 8) | a4) & 0x01FF) >> 8;
                y1 = (uint8_t)((a_hi << 8) | value9);
            }
            a10 = a5;
            a_hi6 = a_hi4;
            y3 = y1;
        } else {
            uint8_t a9;
            uint8_t a_hi5;
            uint8_t y2;
            if ((uint8_t)(value2 << 1) & 0x80) {
                uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0x8001 + x);
                uint8_t a6;
                if ((uint8_t)(value12 + 1) < 6) {
                    a6 = (uint8_t)(value12 + 1);
                } else {
                    a6 = 0;
                }
                BUS8_SET(c, (db << 0x10) + 0x8001 + x, a6);
                uint8_t a8;
                if ((uint8_t)((a_hi << 8) | value12) < 4) {
                    a8 = (uint8_t)((a_hi << 8) | value12);
                } else {
                    uint8_t a7;
                    if ((uint8_t)((a_hi << 8) | value12) != 4) {
                        a7 = 1;
                    } else {
                        a7 = 2;
                    }
                    a8 = a7;
                }
                a9 = (uint8_t)((((((a_hi << 8) | a8) & 3) << 8) | 0) >> 1);
                a_hi5 = (((((a_hi << 8) | a8) & 3) << 8) | 0) >> 1 >> 8;
                y2 = (uint8_t)((a_hi << 8) | value12);
            } else {
                uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0x8006 + x);
                BUS16_SET(c, (db << 0x10) + 0x8006 + x, (uint16_t)(value13 + 0x80) & 0x01FF);
                a9 = (uint8_t)((uint16_t)(value13 + 0x80) & 0x01FF);
                a_hi5 = ((uint16_t)(value13 + 0x80) & 0x01FF) >> 8;
                y2 = y;
            }
            a10 = a9;
            a_hi6 = a_hi5;
            y3 = y2;
        }
        uint16_t value14 = BUS16_RDP(c, (db << 0x10) + 0x8002 + x);
        BUS16_SET(c, (uint16_t)(dp + 0x92), (uint16_t)(((a_hi6 << 8) | a10) + value14));
        uint16_t value15 = BUS16_RDP(c, (db << 0x10) + 0x8004 + x);
        BUS16_SET(c, (uint16_t)(dp + 0x96), value15);
        r->a = (r->a & 0x00FF) | ((value15 >> 8) << 8);
        r->y = y3;
        r->c = ((a_hi6 << 8) | a10) + value14 > 0xFFFF;
        r->v = ((((a_hi6 << 8) | a10) ^ (uint16_t)(((a_hi6 << 8) | a10) + value14)) & (value14 ^ (uint16_t)(((a_hi6 << 8) | a10) + value14)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (uint16_t)(dp + 0x92), 0);
    BUS8_SET(c, (uint16_t)(dp + 0x93), 0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B052, SOM_RTS, "gen", advance_native_graphics_offset_pattern_and_publish_source, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 154, 74)
