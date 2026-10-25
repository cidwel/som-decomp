#include "som_c.h"

/* C27C22 complete_native58_death_gate_and_numeric_event   [class B, 22 bytes, 10 instructions]
 * Source: src/rom/complete_native58_death_gate_and_numeric_event.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void complete_native58_death_gate_and_numeric_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x003E + value, 0);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7C29, 0xC20B50); GUARD_JSR(c, sp_call, 0x7C29); } /* wait_for_boss_death_controller_event_gates */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (!carry_ret) {
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x72 + value2);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool zero1;
            bool negative1;
            bool overflow1;
            uint8_t data_bank;
            uint16_t direct_page;
            if (value3 == 0) {
                m_flag = 1;
                x_flag = 1;
                a1 = value3;
                a_hi1 = a_all >> 8;
                x1 = value2;
                y1 = (uint8_t)y_ret;
                zero1 = value3 == 0;
                negative1 = value3 & 0x80;
                overflow1 = overflow_ret;
                data_bank = db_ret;
                direct_page = dp_ret;
            } else {
                r->a = (a_all >> 8 << 8) | value3;
                r->x = value2;
                r->y = (uint8_t)y_ret;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x7C35, 0xC20C11); GUARD_JSR(c, sp_call, 0x7C35); } /* mark_controller_and_request_numeric_boss_death_event */
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret2 = r->y;
                bool zero_ret2 = r->z;
                bool negative_ret2 = r->n;
                bool overflow_ret2 = r->v;
                m_flag = m_ret2;
                x_flag = x_ret3;
                a1 = (uint8_t)a_all2;
                a_hi1 = a_all2 >> 8;
                x1 = x_ret4;
                y1 = y_ret2;
                zero1 = zero_ret2;
                negative1 = negative_ret2;
                overflow1 = overflow_ret2;
                data_bank = db_ret2;
                direct_page = dp_ret2;
            }
            r->a = (a_hi1 << 8) | a1;
            r->x = x1;
            r->y = y1;
            r->c = 1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = m_flag;
            r->xf = x_flag;
            r->db = data_bank;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x72 + value2);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool zero2;
            bool negative2;
            bool overflow2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if (value4 == 0) {
                m_flag2 = 0;
                x_flag2 = 1;
                a2 = (uint8_t)value4;
                a_hi2 = value4 >> 8;
                x2 = value2;
                y2 = (uint8_t)y_ret;
                zero2 = value4 == 0;
                negative2 = value4 & 0x8000;
                overflow2 = overflow_ret;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            } else {
                r->a = value4;
                r->x = value2;
                r->y = (uint8_t)y_ret;
                r->z = value4 == 0;
                r->n = value4 & 0x8000;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x7C35, 0xC20C11); GUARD_JSR(c, sp_call, 0x7C35); } /* mark_controller_and_request_numeric_boss_death_event */
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                bool m_ret3 = r->mf;
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t x_ret6 = r->x;
                uint16_t y_ret3 = r->y;
                bool zero_ret3 = r->z;
                bool negative_ret3 = r->n;
                bool overflow_ret3 = r->v;
                m_flag2 = m_ret3;
                x_flag2 = x_ret5;
                a2 = (uint8_t)a_all3;
                a_hi2 = a_all3 >> 8;
                x2 = x_ret6;
                y2 = y_ret3;
                zero2 = zero_ret3;
                negative2 = negative_ret3;
                overflow2 = overflow_ret3;
                data_bank2 = db_ret3;
                direct_page2 = dp_ret3;
            }
            r->a = (a_hi2 << 8) | a2;
            r->x = x2;
            r->y = y2;
            r->c = 1;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow2;
            r->mf = m_flag2;
            r->xf = x_flag2;
            r->db = data_bank2;
            r->dp = direct_page2;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x72 + value5);
            bool m_flag3;
            bool x_flag3;
            uint8_t a3;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            bool zero3;
            bool negative3;
            bool overflow3;
            uint8_t data_bank3;
            uint16_t direct_page3;
            if (value6 == 0) {
                m_flag3 = 1;
                x_flag3 = 0;
                a3 = value6;
                a_hi3 = a_all >> 8;
                x3 = value5;
                y3 = y_ret;
                zero3 = value6 == 0;
                negative3 = value6 & 0x80;
                overflow3 = overflow_ret;
                data_bank3 = db_ret;
                direct_page3 = dp_ret;
            } else {
                r->a = (a_all >> 8 << 8) | value6;
                r->x = value5;
                r->z = value6 == 0;
                r->n = value6 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x7C35, 0xC20C11); GUARD_JSR(c, sp_call, 0x7C35); } /* mark_controller_and_request_numeric_boss_death_event */
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool m_ret4 = r->mf;
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t x_ret8 = r->x;
                uint16_t y_ret4 = r->y;
                bool zero_ret4 = r->z;
                bool negative_ret4 = r->n;
                bool overflow_ret4 = r->v;
                m_flag3 = m_ret4;
                x_flag3 = x_ret7;
                a3 = (uint8_t)a_all4;
                a_hi3 = a_all4 >> 8;
                x3 = x_ret8;
                y3 = y_ret4;
                zero3 = zero_ret4;
                negative3 = negative_ret4;
                overflow3 = overflow_ret4;
                data_bank3 = db_ret4;
                direct_page3 = dp_ret4;
            }
            r->a = (a_hi3 << 8) | a3;
            r->x = x3;
            r->y = y3;
            r->c = 1;
            r->z = zero3;
            r->n = negative3;
            r->v = overflow3;
            r->mf = m_flag3;
            r->xf = x_flag3;
            r->db = data_bank3;
            r->dp = direct_page3;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x72 + value5);
            bool m_flag4;
            bool x_flag4;
            uint8_t a4;
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            bool zero4;
            bool negative4;
            bool overflow4;
            uint8_t data_bank4;
            uint16_t direct_page4;
            if (value7 == 0) {
                m_flag4 = 0;
                x_flag4 = 0;
                a4 = (uint8_t)value7;
                a_hi4 = value7 >> 8;
                x4 = value5;
                y4 = y_ret;
                zero4 = value7 == 0;
                negative4 = value7 & 0x8000;
                overflow4 = overflow_ret;
                data_bank4 = db_ret;
                direct_page4 = dp_ret;
            } else {
                r->a = value7;
                r->x = value5;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x7C35, 0xC20C11); GUARD_JSR(c, sp_call, 0x7C35); } /* mark_controller_and_request_numeric_boss_death_event */
                uint16_t dp_ret5 = r->dp;
                uint8_t db_ret5 = r->db;
                bool m_ret5 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret10 = r->x;
                uint16_t y_ret5 = r->y;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret5 = r->v;
                m_flag4 = m_ret5;
                x_flag4 = x_ret9;
                a4 = (uint8_t)a_all5;
                a_hi4 = a_all5 >> 8;
                x4 = x_ret10;
                y4 = y_ret5;
                zero4 = zero_ret5;
                negative4 = negative_ret5;
                overflow4 = overflow_ret5;
                data_bank4 = db_ret5;
                direct_page4 = dp_ret5;
            }
            r->a = (a_hi4 << 8) | a4;
            r->x = x4;
            r->y = y4;
            r->c = 1;
            r->z = zero4;
            r->n = negative4;
            r->v = overflow4;
            r->mf = m_flag4;
            r->xf = x_flag4;
            r->db = data_bank4;
            r->dp = direct_page4;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC27C22, SOM_RTS, "gen", complete_native58_death_gate_and_numeric_event, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 22, 10)
