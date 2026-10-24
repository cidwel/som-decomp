#include "som_c.h"

/* C1B877 search_native_vertical_detour_after_horizontal_motion   [class B, 130 bytes, 64 instructions]
 * Source: src/rom/search_native_vertical_detour_after_horizontal_motion.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void search_native_vertical_detour_after_horizontal_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0008);
    uint8_t value2 = RAM8(0x0006);
    uint8_t a3;
    if (value2 & 0x80) {
        uint8_t a1;
        if (!((uint8_t)((value & 0x7F) - 1) & 0x80)) {
            a1 = (uint8_t)((value & 0x7F) - 1);
        } else {
            a1 = (uint8_t)((uint8_t)((value & 0x7F) - 1) + RAM8(0x009C));
        }
        a3 = a1;
    } else {
        uint8_t value4 = RAM8(0x009C);
        uint8_t a2;
        if ((value & 0x7F) + 1 < value4) {
            a2 = (value & 0x7F) + 1;
        } else {
            a2 = (uint8_t)((value & 0x7F) + 1 - value4 - ((value & 0x7F) + 1 >= value4 ^ 1));
        }
        a3 = a2;
    }
    uint8_t a4;
    if (!(value & 0x80)) {
        a4 = a3;
    } else {
        a4 = a3 | 0x80;
    }
    RAM8(0x0002) = a4;
    RAM8(0x0005) = 1;
    uint8_t value5 = RAM8(0xE02E + x);
    RAM8(0xE02E + x) = value5 ^ 1;
    if ((value5 ^ 1) & 0x01) {
        r->a = (a_hi << 8) | ((value5 ^ 1) >> 1);
        r->c = (value5 ^ 1) & 0x01;
        r->z = (value5 ^ 1) >> 1 == 0;
        r->n = (value5 ^ 1) >> 1 & 0x80;
        r->v = value & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8CA, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8CA); } /* probe_native_detour_tile_up */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool carry_ret = r->c;
        if (!carry_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 0xE007 + x, 0x83);
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
            BUS8_SET(c, (uint16_t)(dp_ret + 5), (uint8_t)(value6 << 1));
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
            BUS8_SET(c, (db_ret << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) + 8));
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) + 8));
            r->c = (uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) + 8 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value6 << 2) + value7 + ((uint8_t)(value6 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret) {
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
            BUS8_SET(c, (uint16_t)(dp_ret + 5), (uint8_t)(value8 + 1));
            r->z = (uint8_t)(value8 + 1) == 0;
            r->n = (uint8_t)(value8 + 1) & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8D1, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D1); } /* probe_native_detour_tile_up */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool carry_ret2 = r->c;
            if (!carry_ret2) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xE007 + x, 0x83);
                uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 5), (uint8_t)(value9 << 1));
                uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
                BUS8_SET(c, (db_ret2 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value9 << 2) + value10 + ((uint8_t)(value9 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret2) {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 5), (uint8_t)(value11 + 1));
                r->z = (uint8_t)(value11 + 1) == 0;
                r->n = (uint8_t)(value11 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8D8, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D8); } /* probe_native_detour_tile_up */
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                bool m_ret3 = r->mf;
                bool carry_ret3 = r->c;
                if (!carry_ret3) {
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xE007 + x, 0x83);
                    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 5), (uint8_t)(value12 << 1));
                    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value12 << 2) + value13 + ((uint8_t)(value12 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret3) {
                    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 5), (uint8_t)(value14 + 1));
                    r->z = (uint8_t)(value14 + 1) == 0;
                    r->n = (uint8_t)(value14 + 1) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret4 = r->dp;
                    uint8_t db_ret4 = r->db;
                    bool carry_ret4 = r->c;
                    if (!carry_ret4) {
                        BUS8_SET(c, (db_ret4 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret4 + 5), (uint8_t)(value15 << 1));
                        uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 5));
                        BUS8_SET(c, (db_ret4 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value15 << 2) + value16 + ((uint8_t)(value15 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 5), (uint16_t)(value17 + 1));
                    r->z = (uint16_t)(value17 + 1) == 0;
                    r->n = (uint16_t)(value17 + 1) & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret5 = r->dp;
                    uint8_t db_ret5 = r->db;
                    bool carry_ret5 = r->c;
                    if (!carry_ret5) {
                        BUS8_SET(c, (db_ret5 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret5 + 5), (uint8_t)(value18 << 1));
                        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 5));
                        BUS8_SET(c, (db_ret5 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value18 << 2) + value19 + ((uint8_t)(value18 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 5), (uint16_t)(value20 + 1));
                r->z = (uint16_t)(value20 + 1) == 0;
                r->n = (uint16_t)(value20 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8D8, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D8); } /* probe_native_detour_tile_up */
                uint16_t dp_ret6 = r->dp;
                uint8_t db_ret6 = r->db;
                bool m_ret6 = r->mf;
                bool carry_ret6 = r->c;
                if (!carry_ret6) {
                    BUS8_SET(c, (db_ret6 << 0x10) + 0xE007 + x, 0x83);
                    uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret6 + 5), (uint8_t)(value21 << 1));
                    uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                    BUS8_SET(c, (db_ret6 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value21 << 2) + value22 + ((uint8_t)(value21 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret6) {
                    uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret6 + 5), (uint8_t)(value23 + 1));
                    r->z = (uint8_t)(value23 + 1) == 0;
                    r->n = (uint8_t)(value23 + 1) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret7 = r->dp;
                    uint8_t db_ret7 = r->db;
                    bool carry_ret7 = r->c;
                    if (!carry_ret7) {
                        BUS8_SET(c, (db_ret7 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret7 + 5), (uint8_t)(value24 << 1));
                        uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 5));
                        BUS8_SET(c, (db_ret7 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value24 << 2) + value25 + ((uint8_t)(value24 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 5));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret6 + 5), (uint16_t)(value26 + 1));
                    r->z = (uint16_t)(value26 + 1) == 0;
                    r->n = (uint16_t)(value26 + 1) & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret8 = r->dp;
                    uint8_t db_ret8 = r->db;
                    bool carry_ret8 = r->c;
                    if (!carry_ret8) {
                        BUS8_SET(c, (db_ret8 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret8 + 5), (uint8_t)(value27 << 1));
                        uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 5));
                        BUS8_SET(c, (db_ret8 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value27 << 2) + value28 + ((uint8_t)(value27 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value29 + 1));
            r->z = (uint16_t)(value29 + 1) == 0;
            r->n = (uint16_t)(value29 + 1) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8D1, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D1); } /* probe_native_detour_tile_up */
            uint16_t dp_ret9 = r->dp;
            uint8_t db_ret9 = r->db;
            bool m_ret9 = r->mf;
            bool carry_ret9 = r->c;
            if (!carry_ret9) {
                BUS8_SET(c, (db_ret9 << 0x10) + 0xE007 + x, 0x83);
                uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret9 + 5), (uint8_t)(value30 << 1));
                uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
                BUS8_SET(c, (db_ret9 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value30 << 2) + value31 + ((uint8_t)(value30 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret9) {
                uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret9 + 5), (uint8_t)(value32 + 1));
                r->z = (uint8_t)(value32 + 1) == 0;
                r->n = (uint8_t)(value32 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8D8, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D8); } /* probe_native_detour_tile_up */
                uint16_t dp_ret10 = r->dp;
                uint8_t db_ret10 = r->db;
                bool m_ret10 = r->mf;
                bool carry_ret10 = r->c;
                if (!carry_ret10) {
                    BUS8_SET(c, (db_ret10 << 0x10) + 0xE007 + x, 0x83);
                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret10 + 5), (uint8_t)(value33 << 1));
                    uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                    BUS8_SET(c, (db_ret10 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value33 << 2) + value34 + ((uint8_t)(value33 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret10) {
                    uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret10 + 5), (uint8_t)(value35 + 1));
                    r->z = (uint8_t)(value35 + 1) == 0;
                    r->n = (uint8_t)(value35 + 1) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret11 = r->dp;
                    uint8_t db_ret11 = r->db;
                    bool carry_ret11 = r->c;
                    if (!carry_ret11) {
                        BUS8_SET(c, (db_ret11 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret11 + 5), (uint8_t)(value36 << 1));
                        uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 5));
                        BUS8_SET(c, (db_ret11 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value36 << 2) + value37 + ((uint8_t)(value36 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret10 + 5));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret10 + 5), (uint16_t)(value38 + 1));
                    r->z = (uint16_t)(value38 + 1) == 0;
                    r->n = (uint16_t)(value38 + 1) & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret12 = r->dp;
                    uint8_t db_ret12 = r->db;
                    bool carry_ret12 = r->c;
                    if (!carry_ret12) {
                        BUS8_SET(c, (db_ret12 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret12 + 5), (uint8_t)(value39 << 1));
                        uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 5));
                        BUS8_SET(c, (db_ret12 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value39 << 2) + value40 + ((uint8_t)(value39 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret9 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret9 + 5), (uint16_t)(value41 + 1));
                r->z = (uint16_t)(value41 + 1) == 0;
                r->n = (uint16_t)(value41 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8D8, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8D8); } /* probe_native_detour_tile_up */
                uint16_t dp_ret13 = r->dp;
                uint8_t db_ret13 = r->db;
                bool m_ret13 = r->mf;
                bool carry_ret13 = r->c;
                if (!carry_ret13) {
                    BUS8_SET(c, (db_ret13 << 0x10) + 0xE007 + x, 0x83);
                    uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret13 + 5), (uint8_t)(value42 << 1));
                    uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                    BUS8_SET(c, (db_ret13 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value42 << 2) + value43 + ((uint8_t)(value42 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret13) {
                    uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret13 + 5), (uint8_t)(value44 + 1));
                    r->z = (uint8_t)(value44 + 1) == 0;
                    r->n = (uint8_t)(value44 + 1) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret14 = r->dp;
                    uint8_t db_ret14 = r->db;
                    bool carry_ret14 = r->c;
                    if (!carry_ret14) {
                        BUS8_SET(c, (db_ret14 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret14 + 5), (uint8_t)(value45 << 1));
                        uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 5));
                        BUS8_SET(c, (db_ret14 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value45 << 2) + value46 + ((uint8_t)(value45 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 5));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret13 + 5), (uint16_t)(value47 + 1));
                    r->z = (uint16_t)(value47 + 1) == 0;
                    r->n = (uint16_t)(value47 + 1) & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB8DF, 0xC1B8F9); GUARD_JSR(c, sp_call, 0xB8DF); } /* probe_native_detour_tile_up */
                    uint16_t dp_ret15 = r->dp;
                    uint8_t db_ret15 = r->db;
                    bool carry_ret15 = r->c;
                    if (!carry_ret15) {
                        BUS8_SET(c, (db_ret15 << 0x10) + 0xE007 + x, 0x83);
                        uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 5));
                        BUS8_SET(c, (uint16_t)(dp_ret15 + 5), (uint8_t)(value48 << 1));
                        uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 5));
                        BUS8_SET(c, (db_ret15 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) + 8));
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) + 8));
                        r->c = (uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) + 8 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value48 << 2) + value49 + ((uint8_t)(value48 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
    }
    r->a = (a_hi << 8) | ((value5 ^ 1) >> 1);
    r->c = (value5 ^ 1) & 0x01;
    r->z = (value5 ^ 1) >> 1 == 0;
    r->n = (value5 ^ 1) >> 1 & 0x80;
    r->v = value & 0x40;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB8A9, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8A9); } /* probe_native_detour_tile_down_with_shared_probe */
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret16 = r->db;
    bool m_ret16 = r->mf;
    bool carry_ret16 = r->c;
    if (!carry_ret16) {
        BUS8_SET(c, (db_ret16 << 0x10) + 0xE007 + x, 3);
        uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 5));
        BUS8_SET(c, (uint16_t)(dp_ret16 + 5), (uint8_t)(value50 << 1));
        uint8_t value51 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 5));
        BUS8_SET(c, (db_ret16 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 8));
        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 8));
        r->c = (uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 8 > 0xFF;
        r->v = (((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (m_ret16) {
        uint8_t value52 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 5));
        BUS8_SET(c, (uint16_t)(dp_ret16 + 5), (uint8_t)(value52 + 1));
        r->z = (uint8_t)(value52 + 1) == 0;
        r->n = (uint8_t)(value52 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8B0, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B0); } /* probe_native_detour_tile_down_with_shared_probe */
        uint16_t dp_ret17 = r->dp;
        uint8_t db_ret17 = r->db;
        bool m_ret17 = r->mf;
        bool carry_ret17 = r->c;
        if (!carry_ret17) {
            BUS8_SET(c, (db_ret17 << 0x10) + 0xE007 + x, 3);
            uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp_ret17 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret17 + 5), (uint8_t)(value53 << 1));
            uint8_t value54 = BUS8_RDP(c, (uint16_t)(dp_ret17 + 5));
            BUS8_SET(c, (db_ret17 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) + 8));
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) + 8));
            r->c = (uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) + 8 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value53 << 2) + value54 + ((uint8_t)(value53 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret17) {
            uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp_ret17 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret17 + 5), (uint8_t)(value55 + 1));
            r->z = (uint8_t)(value55 + 1) == 0;
            r->n = (uint8_t)(value55 + 1) & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8B7, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B7); } /* probe_native_detour_tile_down_with_shared_probe */
            uint16_t dp_ret18 = r->dp;
            uint8_t db_ret18 = r->db;
            bool m_ret18 = r->mf;
            bool carry_ret18 = r->c;
            if (!carry_ret18) {
                BUS8_SET(c, (db_ret18 << 0x10) + 0xE007 + x, 3);
                uint8_t value56 = BUS8_RDP(c, (uint16_t)(dp_ret18 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret18 + 5), (uint8_t)(value56 << 1));
                uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp_ret18 + 5));
                BUS8_SET(c, (db_ret18 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value56 << 2) + value57 + ((uint8_t)(value56 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret18) {
                uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp_ret18 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret18 + 5), (uint8_t)(value58 + 1));
                r->z = (uint8_t)(value58 + 1) == 0;
                r->n = (uint8_t)(value58 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret19 = r->dp;
                uint8_t db_ret19 = r->db;
                bool carry_ret19 = r->c;
                if (!carry_ret19) {
                    BUS8_SET(c, (db_ret19 << 0x10) + 0xE007 + x, 3);
                    uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp_ret19 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret19 + 5), (uint8_t)(value59 << 1));
                    uint8_t value60 = BUS8_RDP(c, (uint16_t)(dp_ret19 + 5));
                    BUS8_SET(c, (db_ret19 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value59 << 2) + value60 + ((uint8_t)(value59 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret18 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret18 + 5), (uint16_t)(value61 + 1));
                r->z = (uint16_t)(value61 + 1) == 0;
                r->n = (uint16_t)(value61 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret20 = r->dp;
                uint8_t db_ret20 = r->db;
                bool carry_ret20 = r->c;
                if (!carry_ret20) {
                    BUS8_SET(c, (db_ret20 << 0x10) + 0xE007 + x, 3);
                    uint8_t value62 = BUS8_RDP(c, (uint16_t)(dp_ret20 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret20 + 5), (uint8_t)(value62 << 1));
                    uint8_t value63 = BUS8_RDP(c, (uint16_t)(dp_ret20 + 5));
                    BUS8_SET(c, (db_ret20 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value62 << 2) + value63 + ((uint8_t)(value62 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp_ret17 + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret17 + 5), (uint16_t)(value64 + 1));
            r->z = (uint16_t)(value64 + 1) == 0;
            r->n = (uint16_t)(value64 + 1) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8B7, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B7); } /* probe_native_detour_tile_down_with_shared_probe */
            uint16_t dp_ret21 = r->dp;
            uint8_t db_ret21 = r->db;
            bool m_ret21 = r->mf;
            bool carry_ret21 = r->c;
            if (!carry_ret21) {
                BUS8_SET(c, (db_ret21 << 0x10) + 0xE007 + x, 3);
                uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp_ret21 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret21 + 5), (uint8_t)(value65 << 1));
                uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret21 + 5));
                BUS8_SET(c, (db_ret21 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value65 << 2) + value66 + ((uint8_t)(value65 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret21) {
                uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp_ret21 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret21 + 5), (uint8_t)(value67 + 1));
                r->z = (uint8_t)(value67 + 1) == 0;
                r->n = (uint8_t)(value67 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret22 = r->dp;
                uint8_t db_ret22 = r->db;
                bool carry_ret22 = r->c;
                if (!carry_ret22) {
                    BUS8_SET(c, (db_ret22 << 0x10) + 0xE007 + x, 3);
                    uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp_ret22 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret22 + 5), (uint8_t)(value68 << 1));
                    uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret22 + 5));
                    BUS8_SET(c, (db_ret22 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value68 << 2) + value69 + ((uint8_t)(value68 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value70 = BUS16_RDP(c, (uint16_t)(dp_ret21 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret21 + 5), (uint16_t)(value70 + 1));
                r->z = (uint16_t)(value70 + 1) == 0;
                r->n = (uint16_t)(value70 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret23 = r->dp;
                uint8_t db_ret23 = r->db;
                bool carry_ret23 = r->c;
                if (!carry_ret23) {
                    BUS8_SET(c, (db_ret23 << 0x10) + 0xE007 + x, 3);
                    uint8_t value71 = BUS8_RDP(c, (uint16_t)(dp_ret23 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret23 + 5), (uint8_t)(value71 << 1));
                    uint8_t value72 = BUS8_RDP(c, (uint16_t)(dp_ret23 + 5));
                    BUS8_SET(c, (db_ret23 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value71 << 2) + value72 + ((uint8_t)(value71 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp_ret16 + 5));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret16 + 5), (uint16_t)(value73 + 1));
        r->z = (uint16_t)(value73 + 1) == 0;
        r->n = (uint16_t)(value73 + 1) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8B0, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B0); } /* probe_native_detour_tile_down_with_shared_probe */
        uint16_t dp_ret24 = r->dp;
        uint8_t db_ret24 = r->db;
        bool m_ret24 = r->mf;
        bool carry_ret24 = r->c;
        if (!carry_ret24) {
            BUS8_SET(c, (db_ret24 << 0x10) + 0xE007 + x, 3);
            uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp_ret24 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret24 + 5), (uint8_t)(value74 << 1));
            uint8_t value75 = BUS8_RDP(c, (uint16_t)(dp_ret24 + 5));
            BUS8_SET(c, (db_ret24 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) + 8));
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) + 8));
            r->c = (uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) + 8 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value74 << 2) + value75 + ((uint8_t)(value74 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret24) {
            uint8_t value76 = BUS8_RDP(c, (uint16_t)(dp_ret24 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret24 + 5), (uint8_t)(value76 + 1));
            r->z = (uint8_t)(value76 + 1) == 0;
            r->n = (uint8_t)(value76 + 1) & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8B7, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B7); } /* probe_native_detour_tile_down_with_shared_probe */
            uint16_t dp_ret25 = r->dp;
            uint8_t db_ret25 = r->db;
            bool m_ret25 = r->mf;
            bool carry_ret25 = r->c;
            if (!carry_ret25) {
                BUS8_SET(c, (db_ret25 << 0x10) + 0xE007 + x, 3);
                uint8_t value77 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret25 + 5), (uint8_t)(value77 << 1));
                uint8_t value78 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 5));
                BUS8_SET(c, (db_ret25 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value77 << 2) + value78 + ((uint8_t)(value77 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret25) {
                uint8_t value79 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret25 + 5), (uint8_t)(value79 + 1));
                r->z = (uint8_t)(value79 + 1) == 0;
                r->n = (uint8_t)(value79 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret26 = r->dp;
                uint8_t db_ret26 = r->db;
                bool carry_ret26 = r->c;
                if (!carry_ret26) {
                    BUS8_SET(c, (db_ret26 << 0x10) + 0xE007 + x, 3);
                    uint8_t value80 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret26 + 5), (uint8_t)(value80 << 1));
                    uint8_t value81 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 5));
                    BUS8_SET(c, (db_ret26 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value80 << 2) + value81 + ((uint8_t)(value80 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value82 = BUS16_RDP(c, (uint16_t)(dp_ret25 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret25 + 5), (uint16_t)(value82 + 1));
                r->z = (uint16_t)(value82 + 1) == 0;
                r->n = (uint16_t)(value82 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret27 = r->dp;
                uint8_t db_ret27 = r->db;
                bool carry_ret27 = r->c;
                if (!carry_ret27) {
                    BUS8_SET(c, (db_ret27 << 0x10) + 0xE007 + x, 3);
                    uint8_t value83 = BUS8_RDP(c, (uint16_t)(dp_ret27 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret27 + 5), (uint8_t)(value83 << 1));
                    uint8_t value84 = BUS8_RDP(c, (uint16_t)(dp_ret27 + 5));
                    BUS8_SET(c, (db_ret27 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value83 << 2) + value84 + ((uint8_t)(value83 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value85 = BUS16_RDP(c, (uint16_t)(dp_ret24 + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret24 + 5), (uint16_t)(value85 + 1));
            r->z = (uint16_t)(value85 + 1) == 0;
            r->n = (uint16_t)(value85 + 1) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB8B7, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8B7); } /* probe_native_detour_tile_down_with_shared_probe */
            uint16_t dp_ret28 = r->dp;
            uint8_t db_ret28 = r->db;
            bool m_ret28 = r->mf;
            bool carry_ret28 = r->c;
            if (!carry_ret28) {
                BUS8_SET(c, (db_ret28 << 0x10) + 0xE007 + x, 3);
                uint8_t value86 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret28 + 5), (uint8_t)(value86 << 1));
                uint8_t value87 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 5));
                BUS8_SET(c, (db_ret28 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) + 8));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) + 8));
                r->c = (uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) + 8 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value86 << 2) + value87 + ((uint8_t)(value86 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret28) {
                uint8_t value88 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret28 + 5), (uint8_t)(value88 + 1));
                r->z = (uint8_t)(value88 + 1) == 0;
                r->n = (uint8_t)(value88 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret29 = r->dp;
                uint8_t db_ret29 = r->db;
                bool carry_ret29 = r->c;
                if (!carry_ret29) {
                    BUS8_SET(c, (db_ret29 << 0x10) + 0xE007 + x, 3);
                    uint8_t value89 = BUS8_RDP(c, (uint16_t)(dp_ret29 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret29 + 5), (uint8_t)(value89 << 1));
                    uint8_t value90 = BUS8_RDP(c, (uint16_t)(dp_ret29 + 5));
                    BUS8_SET(c, (db_ret29 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value89 << 2) + value90 + ((uint8_t)(value89 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value91 = BUS16_RDP(c, (uint16_t)(dp_ret28 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret28 + 5), (uint16_t)(value91 + 1));
                r->z = (uint16_t)(value91 + 1) == 0;
                r->n = (uint16_t)(value91 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB8BE, 0xC1B90A); GUARD_JSR(c, sp_call, 0xB8BE); } /* probe_native_detour_tile_down_with_shared_probe */
                uint16_t dp_ret30 = r->dp;
                uint8_t db_ret30 = r->db;
                bool carry_ret30 = r->c;
                if (!carry_ret30) {
                    BUS8_SET(c, (db_ret30 << 0x10) + 0xE007 + x, 3);
                    uint8_t value92 = BUS8_RDP(c, (uint16_t)(dp_ret30 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret30 + 5), (uint8_t)(value92 << 1));
                    uint8_t value93 = BUS8_RDP(c, (uint16_t)(dp_ret30 + 5));
                    BUS8_SET(c, (db_ret30 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) + 8));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) + 8));
                    r->c = (uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) + 8 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) + 8)) & ((uint8_t)((uint8_t)((uint8_t)(value92 << 2) + value93 + ((uint8_t)(value92 << 1) >> 7)) + 8) ^ 8) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0xC1B877, SOM_RTS, "gen", search_native_vertical_detour_after_horizontal_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 130, 64)
