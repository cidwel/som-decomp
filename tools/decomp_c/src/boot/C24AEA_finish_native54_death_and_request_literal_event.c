#include "som_c.h"

/* C24AEA finish_native54_death_and_request_literal_event   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/finish_native54_death_and_request_literal_event.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_native54_death_and_request_literal_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint64_t loop_guard = 0;
    uint8_t a_4afa = 0;
    uint8_t a_hi_4afa = 0;
    uint8_t x_4afa = 0;
    uint8_t y_4afa = 0;
    bool carry_4afa = 0;
    bool zero_4afa = 0;
    bool negative_4afa = 0;
    bool overflow_4afa = 0;
    uint16_t direct_page_4afa = 0;
    uint8_t data_bank_4afa = 0;
    uint8_t a_4afa2 = 0;
    uint8_t a_hi_4afa2 = 0;
    uint16_t x_4afa2 = 0;
    uint16_t y_4afa2 = 0;
    bool carry_4afa2 = 0;
    bool zero_4afa2 = 0;
    bool negative_4afa2 = 0;
    bool overflow_4afa2 = 0;
    uint16_t direct_page_4afa2 = 0;
    uint8_t data_bank_4afa2 = 0;
    uint8_t a_4afa3 = 0;
    uint8_t a_hi_4afa3 = 0;
    uint8_t x_4afa3 = 0;
    uint8_t y_4afa3 = 0;
    bool carry_4afa3 = 0;
    bool zero_4afa3 = 0;
    bool negative_4afa3 = 0;
    bool overflow_4afa3 = 0;
    uint16_t direct_page_4afa3 = 0;
    uint8_t data_bank_4afa3 = 0;
    uint8_t a_4afa4 = 0;
    uint8_t a_hi_4afa4 = 0;
    uint16_t x_4afa4 = 0;
    uint16_t y_4afa4 = 0;
    bool carry_4afa4 = 0;
    bool zero_4afa4 = 0;
    bool negative_4afa4 = 0;
    bool overflow_4afa4 = 0;
    uint16_t direct_page_4afa4 = 0;
    uint8_t data_bank_4afa4 = 0;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4AEE, 0xC20B50); GUARD_JSR(c, sp_call, 0x4AEE); } /* wait_for_boss_death_controller_event_gates */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    if (!carry_ret) {
        if (m_ret) {
            if (x_ret) {
                a_4afa = (uint8_t)a_all;
                a_hi_4afa = a_all >> 8;
                x_4afa = (uint8_t)x_ret2;
                y_4afa = (uint8_t)y_ret;
                carry_4afa = carry_ret;
                zero_4afa = zero_ret;
                negative_4afa = negative_ret;
                overflow_4afa = overflow_ret;
                direct_page_4afa = dp_ret;
                data_bank_4afa = db_ret;
                goto shared_4AFA;
            } else {
                a_4afa2 = (uint8_t)a_all;
                a_hi_4afa2 = a_all >> 8;
                x_4afa2 = x_ret2;
                y_4afa2 = y_ret;
                carry_4afa2 = carry_ret;
                zero_4afa2 = zero_ret;
                negative_4afa2 = negative_ret;
                overflow_4afa2 = overflow_ret;
                direct_page_4afa2 = dp_ret;
                data_bank_4afa2 = db_ret;
                goto shared_4AFA_1;
            }
        } else {
            if (x_ret) {
                a_4afa3 = (uint8_t)a_all;
                a_hi_4afa3 = a_all >> 8;
                x_4afa3 = (uint8_t)x_ret2;
                y_4afa3 = (uint8_t)y_ret;
                carry_4afa3 = carry_ret;
                zero_4afa3 = zero_ret;
                negative_4afa3 = negative_ret;
                overflow_4afa3 = overflow_ret;
                direct_page_4afa3 = dp_ret;
                data_bank_4afa3 = db_ret;
                goto shared_4AFA_2;
            } else {
                a_4afa4 = (uint8_t)a_all;
                a_hi_4afa4 = a_all >> 8;
                x_4afa4 = x_ret2;
                y_4afa4 = y_ret;
                carry_4afa4 = carry_ret;
                zero_4afa4 = zero_ret;
                negative_4afa4 = negative_ret;
                overflow_4afa4 = overflow_ret;
                direct_page_4afa4 = dp_ret;
                data_bank_4afa4 = db_ret;
                goto shared_4AFA_3;
            }
        }
    }
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x72 + value2);
            r->a = (a_all >> 8 << 8) | value3;
            r->x = value2;
            r->y = (uint8_t)y_ret;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4AF8, 0xC20C11); GUARD_JSR(c, sp_call, 0x4AF8); } /* mark_controller_and_request_numeric_boss_death_event */
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
            if (m_ret2) {
                if (x_ret3) {
                    a_4afa = (uint8_t)a_all2;
                    a_hi_4afa = a_all2 >> 8;
                    x_4afa = (uint8_t)x_ret4;
                    y_4afa = (uint8_t)y_ret2;
                    carry_4afa = 1;
                    zero_4afa = zero_ret2;
                    negative_4afa = negative_ret2;
                    overflow_4afa = overflow_ret2;
                    direct_page_4afa = dp_ret2;
                    data_bank_4afa = db_ret2;
                    goto shared_4AFA;
                } else {
                    a_4afa2 = (uint8_t)a_all2;
                    a_hi_4afa2 = a_all2 >> 8;
                    x_4afa2 = x_ret4;
                    y_4afa2 = y_ret2;
                    carry_4afa2 = 1;
                    zero_4afa2 = zero_ret2;
                    negative_4afa2 = negative_ret2;
                    overflow_4afa2 = overflow_ret2;
                    direct_page_4afa2 = dp_ret2;
                    data_bank_4afa2 = db_ret2;
                    goto shared_4AFA_1;
                }
            } else {
                if (x_ret3) {
                    a_4afa3 = (uint8_t)a_all2;
                    a_hi_4afa3 = a_all2 >> 8;
                    x_4afa3 = (uint8_t)x_ret4;
                    y_4afa3 = (uint8_t)y_ret2;
                    carry_4afa3 = 1;
                    zero_4afa3 = zero_ret2;
                    negative_4afa3 = negative_ret2;
                    overflow_4afa3 = overflow_ret2;
                    direct_page_4afa3 = dp_ret2;
                    data_bank_4afa3 = db_ret2;
                    goto shared_4AFA_2;
                } else {
                    a_4afa4 = (uint8_t)a_all2;
                    a_hi_4afa4 = a_all2 >> 8;
                    x_4afa4 = x_ret4;
                    y_4afa4 = y_ret2;
                    carry_4afa4 = 1;
                    zero_4afa4 = zero_ret2;
                    negative_4afa4 = negative_ret2;
                    overflow_4afa4 = overflow_ret2;
                    direct_page_4afa4 = dp_ret2;
                    data_bank_4afa4 = db_ret2;
                    goto shared_4AFA_3;
                }
            }
        } else {
            uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x72 + value2);
            r->a = value4;
            r->x = value2;
            r->y = (uint8_t)y_ret;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4AF8, 0xC20C11); GUARD_JSR(c, sp_call, 0x4AF8); } /* mark_controller_and_request_numeric_boss_death_event */
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
            if (m_ret3) {
                if (x_ret5) {
                    a_4afa = (uint8_t)a_all3;
                    a_hi_4afa = a_all3 >> 8;
                    x_4afa = (uint8_t)x_ret6;
                    y_4afa = (uint8_t)y_ret3;
                    carry_4afa = 1;
                    zero_4afa = zero_ret3;
                    negative_4afa = negative_ret3;
                    overflow_4afa = overflow_ret3;
                    direct_page_4afa = dp_ret3;
                    data_bank_4afa = db_ret3;
                    goto shared_4AFA;
                } else {
                    a_4afa2 = (uint8_t)a_all3;
                    a_hi_4afa2 = a_all3 >> 8;
                    x_4afa2 = x_ret6;
                    y_4afa2 = y_ret3;
                    carry_4afa2 = 1;
                    zero_4afa2 = zero_ret3;
                    negative_4afa2 = negative_ret3;
                    overflow_4afa2 = overflow_ret3;
                    direct_page_4afa2 = dp_ret3;
                    data_bank_4afa2 = db_ret3;
                    goto shared_4AFA_1;
                }
            } else {
                if (x_ret5) {
                    a_4afa3 = (uint8_t)a_all3;
                    a_hi_4afa3 = a_all3 >> 8;
                    x_4afa3 = (uint8_t)x_ret6;
                    y_4afa3 = (uint8_t)y_ret3;
                    carry_4afa3 = 1;
                    zero_4afa3 = zero_ret3;
                    negative_4afa3 = negative_ret3;
                    overflow_4afa3 = overflow_ret3;
                    direct_page_4afa3 = dp_ret3;
                    data_bank_4afa3 = db_ret3;
                    goto shared_4AFA_2;
                } else {
                    a_4afa4 = (uint8_t)a_all3;
                    a_hi_4afa4 = a_all3 >> 8;
                    x_4afa4 = x_ret6;
                    y_4afa4 = y_ret3;
                    carry_4afa4 = 1;
                    zero_4afa4 = zero_ret3;
                    negative_4afa4 = negative_ret3;
                    overflow_4afa4 = overflow_ret3;
                    direct_page_4afa4 = dp_ret3;
                    data_bank_4afa4 = db_ret3;
                    goto shared_4AFA_3;
                }
            }
        }
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x72 + value5);
            r->a = (a_all >> 8 << 8) | value6;
            r->x = value5;
            r->z = value6 == 0;
            r->n = value6 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4AF8, 0xC20C11); GUARD_JSR(c, sp_call, 0x4AF8); } /* mark_controller_and_request_numeric_boss_death_event */
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
            if (m_ret4) {
                if (x_ret7) {
                    a_4afa = (uint8_t)a_all4;
                    a_hi_4afa = a_all4 >> 8;
                    x_4afa = (uint8_t)x_ret8;
                    y_4afa = (uint8_t)y_ret4;
                    carry_4afa = 1;
                    zero_4afa = zero_ret4;
                    negative_4afa = negative_ret4;
                    overflow_4afa = overflow_ret4;
                    direct_page_4afa = dp_ret4;
                    data_bank_4afa = db_ret4;
                    goto shared_4AFA;
                } else {
                    a_4afa2 = (uint8_t)a_all4;
                    a_hi_4afa2 = a_all4 >> 8;
                    x_4afa2 = x_ret8;
                    y_4afa2 = y_ret4;
                    carry_4afa2 = 1;
                    zero_4afa2 = zero_ret4;
                    negative_4afa2 = negative_ret4;
                    overflow_4afa2 = overflow_ret4;
                    direct_page_4afa2 = dp_ret4;
                    data_bank_4afa2 = db_ret4;
                    goto shared_4AFA_1;
                }
            } else {
                if (x_ret7) {
                    a_4afa3 = (uint8_t)a_all4;
                    a_hi_4afa3 = a_all4 >> 8;
                    x_4afa3 = (uint8_t)x_ret8;
                    y_4afa3 = (uint8_t)y_ret4;
                    carry_4afa3 = 1;
                    zero_4afa3 = zero_ret4;
                    negative_4afa3 = negative_ret4;
                    overflow_4afa3 = overflow_ret4;
                    direct_page_4afa3 = dp_ret4;
                    data_bank_4afa3 = db_ret4;
                    goto shared_4AFA_2;
                } else {
                    a_4afa4 = (uint8_t)a_all4;
                    a_hi_4afa4 = a_all4 >> 8;
                    x_4afa4 = x_ret8;
                    y_4afa4 = y_ret4;
                    carry_4afa4 = 1;
                    zero_4afa4 = zero_ret4;
                    negative_4afa4 = negative_ret4;
                    overflow_4afa4 = overflow_ret4;
                    direct_page_4afa4 = dp_ret4;
                    data_bank_4afa4 = db_ret4;
                    goto shared_4AFA_3;
                }
            }
        } else {
            uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x72 + value5);
            r->a = value7;
            r->x = value5;
            r->z = value7 == 0;
            r->n = value7 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4AF8, 0xC20C11); GUARD_JSR(c, sp_call, 0x4AF8); } /* mark_controller_and_request_numeric_boss_death_event */
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
            if (m_ret5) {
                if (x_ret9) {
                    a_4afa = (uint8_t)a_all5;
                    a_hi_4afa = a_all5 >> 8;
                    x_4afa = (uint8_t)x_ret10;
                    y_4afa = (uint8_t)y_ret5;
                    carry_4afa = 1;
                    zero_4afa = zero_ret5;
                    negative_4afa = negative_ret5;
                    overflow_4afa = overflow_ret5;
                    direct_page_4afa = dp_ret5;
                    data_bank_4afa = db_ret5;
                    goto shared_4AFA;
                } else {
                    a_4afa2 = (uint8_t)a_all5;
                    a_hi_4afa2 = a_all5 >> 8;
                    x_4afa2 = x_ret10;
                    y_4afa2 = y_ret5;
                    carry_4afa2 = 1;
                    zero_4afa2 = zero_ret5;
                    negative_4afa2 = negative_ret5;
                    overflow_4afa2 = overflow_ret5;
                    direct_page_4afa2 = dp_ret5;
                    data_bank_4afa2 = db_ret5;
                    goto shared_4AFA_1;
                }
            } else {
                if (x_ret9) {
                    a_4afa3 = (uint8_t)a_all5;
                    a_hi_4afa3 = a_all5 >> 8;
                    x_4afa3 = (uint8_t)x_ret10;
                    y_4afa3 = (uint8_t)y_ret5;
                    carry_4afa3 = 1;
                    zero_4afa3 = zero_ret5;
                    negative_4afa3 = negative_ret5;
                    overflow_4afa3 = overflow_ret5;
                    direct_page_4afa3 = dp_ret5;
                    data_bank_4afa3 = db_ret5;
                    goto shared_4AFA_2;
                } else {
                    a_4afa4 = (uint8_t)a_all5;
                    a_hi_4afa4 = a_all5 >> 8;
                    x_4afa4 = x_ret10;
                    y_4afa4 = y_ret5;
                    carry_4afa4 = 1;
                    zero_4afa4 = zero_ret5;
                    negative_4afa4 = negative_ret5;
                    overflow_4afa4 = overflow_ret5;
                    direct_page_4afa4 = dp_ret5;
                    data_bank_4afa4 = db_ret5;
                    goto shared_4AFA_3;
                }
            }
        }
    }
    shared_4AFA:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_4afa << 8) | a_4afa;
    r->x = x_4afa;
    r->y = y_4afa;
    r->c = carry_4afa;
    r->z = zero_4afa;
    r->n = negative_4afa;
    r->v = overflow_4afa;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_4afa;
    r->dp = direct_page_4afa;
    RETURN_RTS(c);
    shared_4AFA_1:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_4afa2 << 8) | a_4afa2;
    r->x = x_4afa2;
    r->y = y_4afa2;
    r->c = carry_4afa2;
    r->z = zero_4afa2;
    r->n = negative_4afa2;
    r->v = overflow_4afa2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_4afa2;
    r->dp = direct_page_4afa2;
    RETURN_RTS(c);
    shared_4AFA_2:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_4afa3 << 8) | a_4afa3;
    r->x = x_4afa3;
    r->y = y_4afa3;
    r->c = carry_4afa3;
    r->z = zero_4afa3;
    r->n = negative_4afa3;
    r->v = overflow_4afa3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_4afa3;
    r->dp = direct_page_4afa3;
    RETURN_RTS(c);
    shared_4AFA_3:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_4afa4 << 8) | a_4afa4;
    r->x = x_4afa4;
    r->y = y_4afa4;
    r->c = carry_4afa4;
    r->z = zero_4afa4;
    r->n = negative_4afa4;
    r->v = overflow_4afa4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_4afa4;
    r->dp = direct_page_4afa4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24AEA, SOM_RTS, "gen", finish_native54_death_and_request_literal_event, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 17, 8)
