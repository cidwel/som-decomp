#include "som_c.h"

/* 7EAAFF create_task_resources   [class B, 137 bytes, 71 instructions]
 * Source: src/boot/create_task_resources.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void create_task_resources(SomCtx *c)
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
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_ab45 = 0;
    uint8_t a_hi_ab45 = 0;
    uint16_t direct_page_ab45 = 0;
    uint8_t a_ab452 = 0;
    uint8_t a_hi_ab452 = 0;
    uint16_t direct_page_ab452 = 0;
    uint8_t a_hi_ab79 = 0;
    uint8_t x_ab79 = 0;
    uint8_t y_ab79 = 0;
    uint16_t direct_page_ab79 = 0;
    uint8_t data_bank_ab79 = 0;
    uint8_t a_hi_ab792 = 0;
    uint16_t x_ab792 = 0;
    uint16_t y_ab792 = 0;
    uint16_t direct_page_ab792 = 0;
    uint8_t data_bank_ab792 = 0;
    uint8_t a_hi_ab793 = 0;
    uint8_t x_ab793 = 0;
    uint8_t y_ab793 = 0;
    uint16_t direct_page_ab793 = 0;
    uint8_t data_bank_ab793 = 0;
    uint8_t a_hi_ab794 = 0;
    uint16_t x_ab794 = 0;
    uint16_t y_ab794 = 0;
    uint16_t direct_page_ab794 = 0;
    uint8_t data_bank_ab794 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x10) = 0;
    RAM8(0x0000 + sp0 - 0x11) = 0x0A;
    RAM8(0x0000 + sp0 - 0x12) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x13) = x >> 8;
    RAM8(0x0000 + sp0 - 0x14) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 0x15) = 0;
    RAM8(0x0000 + sp0 - 0x16) = (uint16_t)((uint16_t)(sp0 - 0x10) + 4) >> 8;
    RAM8(0x0000 + sp0 - 0x17) = (uint8_t)((uint16_t)(sp0 - 0x10) + 4);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x10) + 4);
    r->y = 0x0A;
    r->c = (uint16_t)(sp0 - 0x10) + 4 > 0xFFFF;
    r->z = (uint16_t)((uint16_t)(sp0 - 0x10) + 4) == 0;
    r->n = (uint16_t)((uint16_t)(sp0 - 0x10) + 4) & 0x8000;
    r->v = (((uint16_t)(sp0 - 0x10) ^ (uint16_t)((uint16_t)(sp0 - 0x10) + 4)) & ((uint16_t)((uint16_t)(sp0 - 0x10) + 4) ^ 4) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x10);
    r->sp -= 24;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB22, 0x7EC44E); GUARD_JSR(c, sp_call, 0xAB22); } /* copy_far_stack_arguments */
    r->sp += 24;
    uint16_t dp_ret = r->dp;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xA6);
        if (value2 == 0) {
            uint8_t value3 = RAM8(0x0000 + sp0 - 2);
            uint8_t value4 = RAM8(0x0000 + sp0 - 1);
            uint8_t value5 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x10) + 0x0D);
            r->x = value2;
            r->y = (uint8_t)y_ret;
            r->c = value3 & 0x01;
            r->v = value3 & 0x40;
            r->mf = value3 & 0x20;
            r->xf = value3 & 0x10;
            r->dp = (value5 << 8) | value4;
            r->i = value3 & 0x04;
            r->d = value3 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        BUS8_SET(c, (uint16_t)(dp_ret + 2), value2);
        uint8_t value6 = BUS8_RDP(c, (db << 0x10) + value2);
        BUS8_SET(c, (db << 0x10) + 0xA6, value6);
        BUS16_SET(c, (db << 0x10) + value2, 0);
        uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0x9E);
        uint8_t a1;
        if (value7 == 0) {
            a1 = 1;
        } else {
            uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 4 + value7);
            a1 = value8;
        }
        a_ab45 = a1;
        a_hi_ab45 = (uint16_t)((uint16_t)(sp0 - 0x18) + 8) >> 8;
        direct_page_ab45 = dp_ret;
        goto shared_AB45;
    } else {
        uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xA6);
        if (value9 == 0) {
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x10) + 0x0D);
            r->x = value9;
            r->c = value10 & 0x01;
            r->v = value10 & 0x40;
            r->mf = value10 & 0x20;
            r->xf = value10 & 0x10;
            r->dp = (value12 << 8) | value11;
            r->i = value10 & 0x04;
            r->d = value10 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 2), value9);
        uint16_t value13 = BUS16_RDP(c, (db << 0x10) + value9);
        BUS16_SET(c, (db << 0x10) + 0xA6, value13);
        BUS16_SET(c, (db << 0x10) + value9, 0);
        uint16_t value14 = BUS16_RDP(c, (db << 0x10) + 0x9E);
        uint8_t a2;
        if (value14 == 0) {
            a2 = 1;
        } else {
            uint8_t value15 = BUS8_RDP(c, (db << 0x10) + 4 + value14);
            a2 = value15;
        }
        a_ab452 = a2;
        a_hi_ab452 = (uint16_t)((uint16_t)(sp0 - 0x18) + 8) >> 8;
        direct_page_ab452 = dp_ret;
        goto shared_AB45_1;
    }
    shared_AB45:;
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 2));
    BUS8_SET(c, (db << 0x10) + 5 + value16, a_ab45);
    uint8_t value17 = BUS8_RDP(c, (db << 0x10) + 5 + value16);
    r->a = ((uint16_t)(direct_page_ab45 + 4) >> 8 << 8) | value17;
    r->x = value16;
    r->y = (uint8_t)(direct_page_ab45 + 4);
    r->c = direct_page_ab45 + 4 > 0xFFFF;
    r->z = value17 == 0;
    r->n = value17 & 0x80;
    r->v = ((direct_page_ab45 ^ (uint16_t)(direct_page_ab45 + 4)) & ((uint16_t)(direct_page_ab45 + 4) ^ 4) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = direct_page_ab45;
    r->sp -= 16;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB59, 0x7EAA77); GUARD_JSR(c, sp_call, 0xAB59); } /* allocate_task_id_and_stack_page */
    r->sp += 16;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 7));
    BUS8_SET(c, (db_ret << 0x10) + 3 + x_ret4, value18);
    BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret4, 8);
    uint8_t value19 = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret4);
    r->a = (a_all2 >> 8 << 8) | value19;
    r->z = value19 == 0;
    r->n = value19 & 0x80;
    r->mf = 0;
    r->sp -= 16;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB6B, 0x7ECB86); GUARD_JSR(c, sp_call, 0xAB6B); } /* allocate_timer_registration */
    r->sp += 16;
    uint8_t db_ret2 = r->db;
    bool m_ret = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    if (m_ret) {
        if (x_ret5) {
            uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 2));
            BUS8_SET(c, (db_ret2 << 0x10) + 0x0C + value20, (uint8_t)x_ret6);
            uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 0x0C));
            bool m_flag;
            bool x_flag;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            if (value21 == 0) {
                m_flag = 1;
                x_flag = 1;
                a_hi1 = a_all3 >> 8;
                x1 = value21;
                y1 = (uint8_t)y_ret3;
            } else {
                r->a = (a_all3 >> 8 << 8) | (uint8_t)x_ret6;
                r->x = value21;
                r->y = (uint8_t)y_ret3;
                r->z = value21 == 0;
                r->n = value21 & 0x80;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t x_ret8 = r->x;
                uint16_t y_ret4 = r->y;
                m_flag = 0;
                x_flag = x_ret7;
                a_hi1 = a_all4 >> 8;
                x1 = x_ret8;
                y1 = y_ret4;
            }
            if (m_flag) {
                if (x_flag) {
                    a_hi_ab79 = a_hi1;
                    x_ab79 = (uint8_t)x1;
                    y_ab79 = (uint8_t)y1;
                    direct_page_ab79 = direct_page_ab45;
                    data_bank_ab79 = db_ret2;
                    goto shared_AB79;
                } else {
                    a_hi_ab792 = a_hi1;
                    x_ab792 = x1;
                    y_ab792 = y1;
                    direct_page_ab792 = direct_page_ab45;
                    data_bank_ab792 = db_ret2;
                    goto shared_AB79_1;
                }
            } else {
                if (x_flag) {
                    a_hi_ab793 = a_hi1;
                    x_ab793 = (uint8_t)x1;
                    y_ab793 = (uint8_t)y1;
                    direct_page_ab793 = direct_page_ab45;
                    data_bank_ab793 = db_ret2;
                    goto shared_AB79_2;
                } else {
                    a_hi_ab794 = a_hi1;
                    x_ab794 = x1;
                    y_ab794 = y1;
                    direct_page_ab794 = direct_page_ab45;
                    data_bank_ab794 = db_ret2;
                    goto shared_AB79_3;
                }
            }
        } else {
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page_ab45 + 2));
            BUS8_SET(c, (db_ret2 << 0x10) + 0x0C + value22, (uint8_t)x_ret6);
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page_ab45 + 0x0C));
            bool m_flag2;
            bool x_flag2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            if (value23 == 0) {
                m_flag2 = 1;
                x_flag2 = 0;
                a_hi2 = a_all3 >> 8;
                x2 = value23;
                y2 = y_ret3;
            } else {
                r->a = (a_all3 >> 8 << 8) | (uint8_t)x_ret6;
                r->x = value23;
                r->z = value23 == 0;
                r->n = value23 & 0x8000;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret9 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret10 = r->x;
                uint16_t y_ret5 = r->y;
                m_flag2 = 0;
                x_flag2 = x_ret9;
                a_hi2 = a_all5 >> 8;
                x2 = x_ret10;
                y2 = y_ret5;
            }
            if (m_flag2) {
                if (x_flag2) {
                    a_hi_ab79 = a_hi2;
                    x_ab79 = (uint8_t)x2;
                    y_ab79 = (uint8_t)y2;
                    direct_page_ab79 = direct_page_ab45;
                    data_bank_ab79 = db_ret2;
                    goto shared_AB79;
                } else {
                    a_hi_ab792 = a_hi2;
                    x_ab792 = x2;
                    y_ab792 = y2;
                    direct_page_ab792 = direct_page_ab45;
                    data_bank_ab792 = db_ret2;
                    goto shared_AB79_1;
                }
            } else {
                if (x_flag2) {
                    a_hi_ab793 = a_hi2;
                    x_ab793 = (uint8_t)x2;
                    y_ab793 = (uint8_t)y2;
                    direct_page_ab793 = direct_page_ab45;
                    data_bank_ab793 = db_ret2;
                    goto shared_AB79_2;
                } else {
                    a_hi_ab794 = a_hi2;
                    x_ab794 = x2;
                    y_ab794 = y2;
                    direct_page_ab794 = direct_page_ab45;
                    data_bank_ab794 = db_ret2;
                    goto shared_AB79_3;
                }
            }
        }
    } else {
        if (x_ret5) {
            uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 2));
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0C + value24, (uint8_t)x_ret6);
            uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_ab45 + 0x0C));
            bool x_flag3;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            if (value25 == 0) {
                x_flag3 = 1;
                a_hi3 = 0;
                x3 = value25;
                y3 = (uint8_t)y_ret3;
            } else {
                r->a = (uint8_t)x_ret6;
                r->x = value25;
                r->y = (uint8_t)y_ret3;
                r->z = value25 == 0;
                r->n = value25 & 0x80;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret11 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t x_ret12 = r->x;
                uint16_t y_ret6 = r->y;
                x_flag3 = x_ret11;
                a_hi3 = a_all6 >> 8;
                x3 = x_ret12;
                y3 = y_ret6;
            }
            if (x_flag3) {
                a_hi_ab793 = a_hi3;
                x_ab793 = (uint8_t)x3;
                y_ab793 = (uint8_t)y3;
                direct_page_ab793 = direct_page_ab45;
                data_bank_ab793 = db_ret2;
                goto shared_AB79_2;
            } else {
                a_hi_ab794 = a_hi3;
                x_ab794 = x3;
                y_ab794 = y3;
                direct_page_ab794 = direct_page_ab45;
                data_bank_ab794 = db_ret2;
                goto shared_AB79_3;
            }
        } else {
            uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page_ab45 + 2));
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0C + value26, x_ret6);
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_ab45 + 0x0C));
            bool x_flag4;
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            if (value27 == 0) {
                x_flag4 = 0;
                a_hi4 = x_ret6 >> 8;
                x4 = value27;
                y4 = y_ret3;
            } else {
                r->a = x_ret6;
                r->x = value27;
                r->z = value27 == 0;
                r->n = value27 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret13 = r->xf;
                uint16_t a_all7 = r->a;
                uint16_t x_ret14 = r->x;
                uint16_t y_ret7 = r->y;
                x_flag4 = x_ret13;
                a_hi4 = a_all7 >> 8;
                x4 = x_ret14;
                y4 = y_ret7;
            }
            if (x_flag4) {
                a_hi_ab793 = a_hi4;
                x_ab793 = (uint8_t)x4;
                y_ab793 = (uint8_t)y4;
                direct_page_ab793 = direct_page_ab45;
                data_bank_ab793 = db_ret2;
                goto shared_AB79_2;
            } else {
                a_hi_ab794 = a_hi4;
                x_ab794 = x4;
                y_ab794 = y4;
                direct_page_ab794 = direct_page_ab45;
                data_bank_ab794 = db_ret2;
                goto shared_AB79_3;
            }
        }
    }
    shared_AB45_1:;
    uint16_t value28 = BUS16_RDP(c, (uint16_t)(direct_page_ab452 + 2));
    BUS8_SET(c, (db << 0x10) + 5 + value28, a_ab452);
    uint8_t value29 = BUS8_RDP(c, (db << 0x10) + 5 + value28);
    r->a = ((uint16_t)(direct_page_ab452 + 4) >> 8 << 8) | value29;
    r->x = value28;
    r->y = (uint16_t)(direct_page_ab452 + 4);
    r->c = direct_page_ab452 + 4 > 0xFFFF;
    r->z = value29 == 0;
    r->n = value29 & 0x80;
    r->v = ((direct_page_ab452 ^ (uint16_t)(direct_page_ab452 + 4)) & ((uint16_t)(direct_page_ab452 + 4) ^ 4) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = direct_page_ab452;
    r->sp -= 16;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB59, 0x7EAA77); GUARD_JSR(c, sp_call, 0xAB59); } /* allocate_task_id_and_stack_page */
    r->sp += 16;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all8 = r->a;
    uint16_t x_ret16 = r->x;
    uint8_t value30 = BUS8_RDP(c, (uint16_t)(direct_page_ab452 + 7));
    BUS8_SET(c, (db_ret3 << 0x10) + 3 + x_ret16, value30);
    BUS8_SET(c, (db_ret3 << 0x10) + 2 + x_ret16, 8);
    uint8_t value31 = BUS8_RDP(c, (db_ret3 << 0x10) + 4 + x_ret16);
    r->a = (a_all8 >> 8 << 8) | value31;
    r->z = value31 == 0;
    r->n = value31 & 0x80;
    r->mf = 0;
    r->sp -= 16;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAB6B, 0x7ECB86); GUARD_JSR(c, sp_call, 0xAB6B); } /* allocate_timer_registration */
    r->sp += 16;
    uint8_t db_ret4 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret17 = r->xf;
    uint16_t a_all9 = r->a;
    uint16_t x_ret18 = r->x;
    uint16_t y_ret9 = r->y;
    if (m_ret2) {
        if (x_ret17) {
            uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page_ab452 + 2));
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0C + value32, (uint8_t)x_ret18);
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(direct_page_ab452 + 0x0C));
            bool m_flag3;
            bool x_flag5;
            uint8_t a_hi5;
            uint16_t x5;
            uint16_t y5;
            if (value33 == 0) {
                m_flag3 = 1;
                x_flag5 = 1;
                a_hi5 = a_all9 >> 8;
                x5 = value33;
                y5 = (uint8_t)y_ret9;
            } else {
                r->a = (a_all9 >> 8 << 8) | (uint8_t)x_ret18;
                r->x = value33;
                r->y = (uint8_t)y_ret9;
                r->z = value33 == 0;
                r->n = value33 & 0x80;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret19 = r->xf;
                uint16_t a_all10 = r->a;
                uint16_t x_ret20 = r->x;
                uint16_t y_ret10 = r->y;
                m_flag3 = 0;
                x_flag5 = x_ret19;
                a_hi5 = a_all10 >> 8;
                x5 = x_ret20;
                y5 = y_ret10;
            }
            if (m_flag3) {
                if (x_flag5) {
                    a_hi_ab79 = a_hi5;
                    x_ab79 = (uint8_t)x5;
                    y_ab79 = (uint8_t)y5;
                    direct_page_ab79 = direct_page_ab452;
                    data_bank_ab79 = db_ret4;
                    goto shared_AB79;
                } else {
                    a_hi_ab792 = a_hi5;
                    x_ab792 = x5;
                    y_ab792 = y5;
                    direct_page_ab792 = direct_page_ab452;
                    data_bank_ab792 = db_ret4;
                    goto shared_AB79_1;
                }
            } else {
                if (x_flag5) {
                    a_hi_ab793 = a_hi5;
                    x_ab793 = (uint8_t)x5;
                    y_ab793 = (uint8_t)y5;
                    direct_page_ab793 = direct_page_ab452;
                    data_bank_ab793 = db_ret4;
                    goto shared_AB79_2;
                } else {
                    a_hi_ab794 = a_hi5;
                    x_ab794 = x5;
                    y_ab794 = y5;
                    direct_page_ab794 = direct_page_ab452;
                    data_bank_ab794 = db_ret4;
                    goto shared_AB79_3;
                }
            }
        } else {
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(direct_page_ab452 + 2));
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0C + value34, (uint8_t)x_ret18);
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(direct_page_ab452 + 0x0C));
            bool m_flag4;
            bool x_flag6;
            uint8_t a_hi6;
            uint16_t x6;
            uint16_t y6;
            if (value35 == 0) {
                m_flag4 = 1;
                x_flag6 = 0;
                a_hi6 = a_all9 >> 8;
                x6 = value35;
                y6 = y_ret9;
            } else {
                r->a = (a_all9 >> 8 << 8) | (uint8_t)x_ret18;
                r->x = value35;
                r->z = value35 == 0;
                r->n = value35 & 0x8000;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret21 = r->xf;
                uint16_t a_all11 = r->a;
                uint16_t x_ret22 = r->x;
                uint16_t y_ret11 = r->y;
                m_flag4 = 0;
                x_flag6 = x_ret21;
                a_hi6 = a_all11 >> 8;
                x6 = x_ret22;
                y6 = y_ret11;
            }
            if (m_flag4) {
                if (x_flag6) {
                    a_hi_ab79 = a_hi6;
                    x_ab79 = (uint8_t)x6;
                    y_ab79 = (uint8_t)y6;
                    direct_page_ab79 = direct_page_ab452;
                    data_bank_ab79 = db_ret4;
                    goto shared_AB79;
                } else {
                    a_hi_ab792 = a_hi6;
                    x_ab792 = x6;
                    y_ab792 = y6;
                    direct_page_ab792 = direct_page_ab452;
                    data_bank_ab792 = db_ret4;
                    goto shared_AB79_1;
                }
            } else {
                if (x_flag6) {
                    a_hi_ab793 = a_hi6;
                    x_ab793 = (uint8_t)x6;
                    y_ab793 = (uint8_t)y6;
                    direct_page_ab793 = direct_page_ab452;
                    data_bank_ab793 = db_ret4;
                    goto shared_AB79_2;
                } else {
                    a_hi_ab794 = a_hi6;
                    x_ab794 = x6;
                    y_ab794 = y6;
                    direct_page_ab794 = direct_page_ab452;
                    data_bank_ab794 = db_ret4;
                    goto shared_AB79_3;
                }
            }
        }
    } else {
        if (x_ret17) {
            uint8_t value36 = BUS8_RDP(c, (uint16_t)(direct_page_ab452 + 2));
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0C + value36, (uint8_t)x_ret18);
            uint8_t value37 = BUS8_RDP(c, (uint16_t)(direct_page_ab452 + 0x0C));
            bool x_flag7;
            uint8_t a_hi7;
            uint16_t x7;
            uint16_t y7;
            if (value37 == 0) {
                x_flag7 = 1;
                a_hi7 = 0;
                x7 = value37;
                y7 = (uint8_t)y_ret9;
            } else {
                r->a = (uint8_t)x_ret18;
                r->x = value37;
                r->y = (uint8_t)y_ret9;
                r->z = value37 == 0;
                r->n = value37 & 0x80;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret23 = r->xf;
                uint16_t a_all12 = r->a;
                uint16_t x_ret24 = r->x;
                uint16_t y_ret12 = r->y;
                x_flag7 = x_ret23;
                a_hi7 = a_all12 >> 8;
                x7 = x_ret24;
                y7 = y_ret12;
            }
            if (x_flag7) {
                a_hi_ab793 = a_hi7;
                x_ab793 = (uint8_t)x7;
                y_ab793 = (uint8_t)y7;
                direct_page_ab793 = direct_page_ab452;
                data_bank_ab793 = db_ret4;
                goto shared_AB79_2;
            } else {
                a_hi_ab794 = a_hi7;
                x_ab794 = x7;
                y_ab794 = y7;
                direct_page_ab794 = direct_page_ab452;
                data_bank_ab794 = db_ret4;
                goto shared_AB79_3;
            }
        } else {
            uint16_t value38 = BUS16_RDP(c, (uint16_t)(direct_page_ab452 + 2));
            BUS16_SET(c, (db_ret4 << 0x10) + 0x0C + value38, x_ret18);
            uint16_t value39 = BUS16_RDP(c, (uint16_t)(direct_page_ab452 + 0x0C));
            bool x_flag8;
            uint8_t a_hi8;
            uint16_t x8;
            uint16_t y8;
            if (value39 == 0) {
                x_flag8 = 0;
                a_hi8 = x_ret18 >> 8;
                x8 = value39;
                y8 = y_ret9;
            } else {
                r->a = x_ret18;
                r->x = value39;
                r->z = value39 == 0;
                r->n = value39 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 16;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAB78, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xAB78); } /* allocate_and_fill_bytes */
                r->sp += 16;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret25 = r->xf;
                uint16_t a_all13 = r->a;
                uint16_t x_ret26 = r->x;
                uint16_t y_ret13 = r->y;
                x_flag8 = x_ret25;
                a_hi8 = a_all13 >> 8;
                x8 = x_ret26;
                y8 = y_ret13;
            }
            if (x_flag8) {
                a_hi_ab793 = a_hi8;
                x_ab793 = (uint8_t)x8;
                y_ab793 = (uint8_t)y8;
                direct_page_ab793 = direct_page_ab452;
                data_bank_ab793 = db_ret4;
                goto shared_AB79_2;
            } else {
                a_hi_ab794 = a_hi8;
                x_ab794 = x8;
                y_ab794 = y8;
                direct_page_ab794 = direct_page_ab452;
                data_bank_ab794 = db_ret4;
                goto shared_AB79_3;
            }
        }
    }
    shared_AB79:;
    uint8_t value40 = BUS8_RDP(c, (uint16_t)(direct_page_ab79 + 2));
    BUS8_SET(c, (data_bank_ab79 << 0x10) + 8 + value40, x_ab79);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_AB79_1:;
    uint16_t value41 = BUS16_RDP(c, (uint16_t)(direct_page_ab792 + 2));
    BUS8_SET(c, (data_bank_ab792 << 0x10) + 8 + value41, (uint8_t)x_ab792);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_AB79_2:;
    uint8_t value42 = BUS8_RDP(c, (uint16_t)(direct_page_ab793 + 2));
    BUS16_SET(c, (data_bank_ab793 << 0x10) + 8 + value42, x_ab793);
    uint8_t value43 = RAM8(0x0000 + sp0 - 2);
    uint8_t value44 = RAM8(0x0000 + sp0 - 1);
    uint8_t value45 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x10) + 0x0D);
    r->x = value42;
    r->y = y_ab793;
    r->c = value43 & 0x01;
    r->v = value43 & 0x40;
    r->mf = value43 & 0x20;
    r->xf = value43 & 0x10;
    r->db = data_bank_ab793;
    r->dp = (value45 << 8) | value44;
    r->i = value43 & 0x04;
    r->d = value43 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_AB79_3:;
    uint16_t value46 = BUS16_RDP(c, (uint16_t)(direct_page_ab794 + 2));
    BUS16_SET(c, (data_bank_ab794 << 0x10) + 8 + value46, x_ab794);
    uint8_t value47 = RAM8(0x0000 + sp0 - 2);
    uint8_t value48 = RAM8(0x0000 + sp0 - 1);
    uint8_t value49 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x10) + 0x0D);
    r->x = value46;
    r->y = y_ab794;
    r->c = value47 & 0x01;
    r->v = value47 & 0x40;
    r->mf = value47 & 0x20;
    r->xf = value47 & 0x10;
    r->db = data_bank_ab794;
    r->dp = (value49 << 8) | value48;
    r->i = value47 & 0x04;
    r->d = value47 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAAFF, SOM_RTS, "gen", create_task_resources, 0, L_B | L_X | L_Y | L_C | L_V, 24, -1, 0, 137, 71)
