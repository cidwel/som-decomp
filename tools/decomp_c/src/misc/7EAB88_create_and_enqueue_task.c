#include "som_c.h"

/* 7EAB88 create_and_enqueue_task   [class A, 37 bytes, 24 instructions]
 * Source: src/boot/create_and_enqueue_task.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void create_and_enqueue_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_aba8 = 0;
    uint8_t a_hi_aba8 = 0;
    uint8_t x_aba8 = 0;
    uint8_t y_aba8 = 0;
    uint16_t direct_page_aba8 = 0;
    uint8_t data_bank_aba8 = 0;
    uint8_t a_aba82 = 0;
    uint8_t a_hi_aba82 = 0;
    uint16_t x_aba82 = 0;
    uint16_t y_aba82 = 0;
    uint16_t direct_page_aba82 = 0;
    uint8_t data_bank_aba82 = 0;
    uint8_t a_aba83 = 0;
    uint8_t a_hi_aba83 = 0;
    uint8_t x_aba83 = 0;
    uint8_t y_aba83 = 0;
    uint16_t direct_page_aba83 = 0;
    uint8_t data_bank_aba83 = 0;
    uint8_t a_aba84 = 0;
    uint8_t a_hi_aba84 = 0;
    uint16_t x_aba84 = 0;
    uint16_t y_aba84 = 0;
    uint16_t direct_page_aba84 = 0;
    uint8_t data_bank_aba84 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = (((((uint8_t)a >> 7 << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint8_t)a == 0) << 1) | carry;
    r->z = (uint8_t)a == 0;
    r->n = (uint8_t)a & 0x80;
    r->mf = 0;
    r->db = 0x7F;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB9B, 0x7EAAFF); GUARD_JSR(c, sp_call, 0xAB9B); } /* create_task_resources */
    r->sp += 5;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (m_ret) {
        if (x_ret) {
            if ((uint8_t)x_ret2 == 0) {
                a_aba8 = (uint8_t)x_ret2;
                a_hi_aba8 = a_all >> 8;
                x_aba8 = (uint8_t)x_ret2;
                y_aba8 = (uint8_t)y_ret;
                direct_page_aba8 = dp;
                data_bank_aba8 = db_ret;
                goto shared_ABA8;
            }
            r->a = (a_all >> 8 << 8) | (uint8_t)x_ret2;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)y_ret;
            r->z = (uint8_t)x_ret2 == 0;
            r->n = (uint8_t)x_ret2 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xABA1, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xABA1); } /* enqueue_task_by_priority */
            r->sp += 5;
            uint16_t dp_ret = r->dp;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            if (m_ret2) {
                uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret4);
                uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS8_SET(c, (db_ret << 0x10) + 0x9A, (uint8_t)(value2 + 1));
                if (x_ret3) {
                    a_aba8 = value;
                    a_hi_aba8 = a_all2 >> 8;
                    x_aba8 = (uint8_t)x_ret4;
                    y_aba8 = (uint8_t)y_ret2;
                    direct_page_aba8 = dp_ret;
                    data_bank_aba8 = db_ret;
                    goto shared_ABA8;
                } else {
                    a_aba82 = value;
                    a_hi_aba82 = a_all2 >> 8;
                    x_aba82 = x_ret4;
                    y_aba82 = y_ret2;
                    direct_page_aba82 = dp_ret;
                    data_bank_aba82 = db_ret;
                    goto shared_ABA8_1;
                }
            } else {
                uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret4);
                uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x9A, (uint16_t)(value4 + 1));
                if (x_ret3) {
                    a_aba83 = (uint8_t)value3;
                    a_hi_aba83 = value3 >> 8;
                    x_aba83 = (uint8_t)x_ret4;
                    y_aba83 = (uint8_t)y_ret2;
                    direct_page_aba83 = dp_ret;
                    data_bank_aba83 = db_ret;
                    goto shared_ABA8_2;
                } else {
                    a_aba84 = (uint8_t)value3;
                    a_hi_aba84 = value3 >> 8;
                    x_aba84 = x_ret4;
                    y_aba84 = y_ret2;
                    direct_page_aba84 = dp_ret;
                    data_bank_aba84 = db_ret;
                    goto shared_ABA8_3;
                }
            }
        } else {
            if ((uint8_t)x_ret2 == 0) {
                a_aba82 = (uint8_t)x_ret2;
                a_hi_aba82 = a_all >> 8;
                x_aba82 = x_ret2;
                y_aba82 = y_ret;
                direct_page_aba82 = dp;
                data_bank_aba82 = db_ret;
                goto shared_ABA8_1;
            }
            r->a = (a_all >> 8 << 8) | (uint8_t)x_ret2;
            r->z = (uint8_t)x_ret2 == 0;
            r->n = (uint8_t)x_ret2 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xABA1, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xABA1); } /* enqueue_task_by_priority */
            r->sp += 5;
            uint16_t dp_ret2 = r->dp;
            bool m_ret3 = r->mf;
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            if (m_ret3) {
                uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret6);
                uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS8_SET(c, (db_ret << 0x10) + 0x9A, (uint8_t)(value6 + 1));
                if (x_ret5) {
                    a_aba8 = value5;
                    a_hi_aba8 = a_all3 >> 8;
                    x_aba8 = (uint8_t)x_ret6;
                    y_aba8 = (uint8_t)y_ret3;
                    direct_page_aba8 = dp_ret2;
                    data_bank_aba8 = db_ret;
                    goto shared_ABA8;
                } else {
                    a_aba82 = value5;
                    a_hi_aba82 = a_all3 >> 8;
                    x_aba82 = x_ret6;
                    y_aba82 = y_ret3;
                    direct_page_aba82 = dp_ret2;
                    data_bank_aba82 = db_ret;
                    goto shared_ABA8_1;
                }
            } else {
                uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret6);
                uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x9A, (uint16_t)(value8 + 1));
                if (x_ret5) {
                    a_aba83 = (uint8_t)value7;
                    a_hi_aba83 = value7 >> 8;
                    x_aba83 = (uint8_t)x_ret6;
                    y_aba83 = (uint8_t)y_ret3;
                    direct_page_aba83 = dp_ret2;
                    data_bank_aba83 = db_ret;
                    goto shared_ABA8_2;
                } else {
                    a_aba84 = (uint8_t)value7;
                    a_hi_aba84 = value7 >> 8;
                    x_aba84 = x_ret6;
                    y_aba84 = y_ret3;
                    direct_page_aba84 = dp_ret2;
                    data_bank_aba84 = db_ret;
                    goto shared_ABA8_3;
                }
            }
        }
    } else {
        if (x_ret) {
            if ((uint8_t)x_ret2 == 0) {
                a_aba83 = (uint8_t)x_ret2;
                a_hi_aba83 = 0;
                x_aba83 = (uint8_t)x_ret2;
                y_aba83 = (uint8_t)y_ret;
                direct_page_aba83 = dp;
                data_bank_aba83 = db_ret;
                goto shared_ABA8_2;
            }
            r->a = (uint8_t)x_ret2;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)y_ret;
            r->z = (uint8_t)x_ret2 == 0;
            r->n = (uint8_t)x_ret2 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xABA1, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xABA1); } /* enqueue_task_by_priority */
            r->sp += 5;
            uint16_t dp_ret3 = r->dp;
            bool m_ret4 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret4 = r->y;
            if (m_ret4) {
                uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret8);
                uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS8_SET(c, (db_ret << 0x10) + 0x9A, (uint8_t)(value10 + 1));
                if (x_ret7) {
                    a_aba8 = value9;
                    a_hi_aba8 = a_all4 >> 8;
                    x_aba8 = (uint8_t)x_ret8;
                    y_aba8 = (uint8_t)y_ret4;
                    direct_page_aba8 = dp_ret3;
                    data_bank_aba8 = db_ret;
                    goto shared_ABA8;
                } else {
                    a_aba82 = value9;
                    a_hi_aba82 = a_all4 >> 8;
                    x_aba82 = x_ret8;
                    y_aba82 = y_ret4;
                    direct_page_aba82 = dp_ret3;
                    data_bank_aba82 = db_ret;
                    goto shared_ABA8_1;
                }
            } else {
                uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret8);
                uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x9A, (uint16_t)(value12 + 1));
                if (x_ret7) {
                    a_aba83 = (uint8_t)value11;
                    a_hi_aba83 = value11 >> 8;
                    x_aba83 = (uint8_t)x_ret8;
                    y_aba83 = (uint8_t)y_ret4;
                    direct_page_aba83 = dp_ret3;
                    data_bank_aba83 = db_ret;
                    goto shared_ABA8_2;
                } else {
                    a_aba84 = (uint8_t)value11;
                    a_hi_aba84 = value11 >> 8;
                    x_aba84 = x_ret8;
                    y_aba84 = y_ret4;
                    direct_page_aba84 = dp_ret3;
                    data_bank_aba84 = db_ret;
                    goto shared_ABA8_3;
                }
            }
        } else {
            if (x_ret2 == 0) {
                a_aba84 = (uint8_t)x_ret2;
                a_hi_aba84 = x_ret2 >> 8;
                x_aba84 = x_ret2;
                y_aba84 = y_ret;
                direct_page_aba84 = dp;
                data_bank_aba84 = db_ret;
                goto shared_ABA8_3;
            }
            r->a = x_ret2;
            r->z = x_ret2 == 0;
            r->n = x_ret2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xABA1, 0x7EA8D6); GUARD_JSR(c, sp_call, 0xABA1); } /* enqueue_task_by_priority */
            r->sp += 5;
            uint16_t dp_ret4 = r->dp;
            bool m_ret5 = r->mf;
            bool x_ret9 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret5 = r->y;
            if (m_ret5) {
                uint8_t value13 = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret10);
                uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS8_SET(c, (db_ret << 0x10) + 0x9A, (uint8_t)(value14 + 1));
                if (x_ret9) {
                    a_aba8 = value13;
                    a_hi_aba8 = a_all5 >> 8;
                    x_aba8 = (uint8_t)x_ret10;
                    y_aba8 = (uint8_t)y_ret5;
                    direct_page_aba8 = dp_ret4;
                    data_bank_aba8 = db_ret;
                    goto shared_ABA8;
                } else {
                    a_aba82 = value13;
                    a_hi_aba82 = a_all5 >> 8;
                    x_aba82 = x_ret10;
                    y_aba82 = y_ret5;
                    direct_page_aba82 = dp_ret4;
                    data_bank_aba82 = db_ret;
                    goto shared_ABA8_1;
                }
            } else {
                uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret10);
                uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0x9A);
                BUS16_RMW_SET(c, (db_ret << 0x10) + 0x9A, (uint16_t)(value16 + 1));
                if (x_ret9) {
                    a_aba83 = (uint8_t)value15;
                    a_hi_aba83 = value15 >> 8;
                    x_aba83 = (uint8_t)x_ret10;
                    y_aba83 = (uint8_t)y_ret5;
                    direct_page_aba83 = dp_ret4;
                    data_bank_aba83 = db_ret;
                    goto shared_ABA8_2;
                } else {
                    a_aba84 = (uint8_t)value15;
                    a_hi_aba84 = value15 >> 8;
                    x_aba84 = x_ret10;
                    y_aba84 = y_ret5;
                    direct_page_aba84 = dp_ret4;
                    data_bank_aba84 = db_ret;
                    goto shared_ABA8_3;
                }
            }
        }
    }
    shared_ABA8:;
    uint8_t value17 = RAM8(0x0000 + sp0 - 4);
    uint8_t value18 = RAM8(0x0000 + sp0 - 3);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->a = (a_hi_aba8 << 8) | a_aba8;
    r->x = x_aba8 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
    r->y = y_aba8 & 0xFFFF - ((value17 >> 4) & 1) * 0xFF00;
    r->c = value19 & 0x01;
    r->z = ((value21 << 8) | value20) == 0;
    r->n = ((value21 << 8) | value20) & 0x8000;
    r->v = value19 & 0x40;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = value18;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_ABA8_1:;
    uint8_t value22 = RAM8(0x0000 + sp0 - 4);
    uint8_t value23 = RAM8(0x0000 + sp0 - 3);
    uint8_t value24 = RAM8(0x0000 + sp0 - 2);
    uint8_t value25 = RAM8(0x0000 + sp0 - 1);
    uint8_t value26 = RAM8(0x0000 + sp0);
    r->a = (a_hi_aba82 << 8) | a_aba82;
    r->x = x_aba82 & 0xFFFF - ((value22 >> 4) & 1) * 0xFF00;
    r->y = y_aba82 & 0xFFFF - ((value22 >> 4) & 1) * 0xFF00;
    r->c = value24 & 0x01;
    r->z = ((value26 << 8) | value25) == 0;
    r->n = ((value26 << 8) | value25) & 0x8000;
    r->v = value24 & 0x40;
    r->mf = value24 & 0x20;
    r->xf = value24 & 0x10;
    r->db = value23;
    r->dp = (value26 << 8) | value25;
    r->i = value24 & 0x04;
    r->d = value24 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_ABA8_2:;
    uint8_t value27 = RAM8(0x0000 + sp0 - 4);
    uint8_t value28 = RAM8(0x0000 + sp0 - 3);
    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
    uint8_t value31 = RAM8(0x0000 + sp0);
    r->a = (a_hi_aba83 << 8) | a_aba83;
    r->x = x_aba83 & 0xFFFF - ((value27 >> 4) & 1) * 0xFF00;
    r->y = y_aba83 & 0xFFFF - ((value27 >> 4) & 1) * 0xFF00;
    r->c = value29 & 0x01;
    r->z = ((value31 << 8) | value30) == 0;
    r->n = ((value31 << 8) | value30) & 0x8000;
    r->v = value29 & 0x40;
    r->mf = value29 & 0x20;
    r->xf = value29 & 0x10;
    r->db = value28;
    r->dp = (value31 << 8) | value30;
    r->i = value29 & 0x04;
    r->d = value29 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_ABA8_3:;
    uint8_t value32 = RAM8(0x0000 + sp0 - 4);
    uint8_t value33 = RAM8(0x0000 + sp0 - 3);
    uint8_t value34 = RAM8(0x0000 + sp0 - 2);
    uint8_t value35 = RAM8(0x0000 + sp0 - 1);
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->a = (a_hi_aba84 << 8) | a_aba84;
    r->x = x_aba84 & 0xFFFF - ((value32 >> 4) & 1) * 0xFF00;
    r->y = y_aba84 & 0xFFFF - ((value32 >> 4) & 1) * 0xFF00;
    r->c = value34 & 0x01;
    r->z = ((value36 << 8) | value35) == 0;
    r->n = ((value36 << 8) | value35) & 0x8000;
    r->v = value34 & 0x40;
    r->mf = value34 & 0x20;
    r->xf = value34 & 0x10;
    r->db = value33;
    r->dp = (value36 << 8) | value35;
    r->i = value34 & 0x04;
    r->d = value34 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAB88, SOM_RTS, "gen", create_and_enqueue_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, -1, 0, 37, 24)
