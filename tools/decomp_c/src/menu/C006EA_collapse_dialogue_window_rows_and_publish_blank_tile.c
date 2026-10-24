#include "som_c.h"

/* C006EA collapse_dialogue_window_rows_and_publish_blank_tile   [class C, 246 bytes, 94 instructions]
 * Source: src/rom/collapse_dialogue_window_rows_and_publish_blank_tile.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void collapse_dialogue_window_rows_and_publish_blank_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_0748 = 0;
    uint16_t x_0748 = 0;
    uint16_t y_0748 = 0;
    bool carry_0748 = 0;
    bool overflow_0748 = 0;
    uint8_t data_bank_0748 = 0;
    uint8_t a_hi_0714 = 0;
    uint16_t x_0714 = 0;
    uint16_t y_0714 = 0;
    bool overflow_0714 = 0;
    uint8_t data_bank_0714 = 0;
    uint8_t a_hi_075a = 0;
    uint16_t x_075a = 0;
    uint16_t y_075a = 0;
    bool carry_075a = 0;
    bool overflow_075a = 0;
    uint16_t direct_page_075a = 0;
    uint8_t data_bank_075a = 0;
    uint8_t a_hi_075a2 = 0;
    uint8_t x_075a2 = 0;
    uint8_t y_075a2 = 0;
    bool carry_075a2 = 0;
    bool overflow_075a2 = 0;
    uint16_t direct_page_075a2 = 0;
    uint8_t data_bank_075a2 = 0;
    uint8_t a_hi_07a4 = 0;
    bool carry_07a4 = 0;
    bool overflow_07a4 = 0;
    uint16_t direct_page_07a4 = 0;
    uint8_t data_bank_07a4 = 0;
    uint8_t a_hi_07a42 = 0;
    bool carry_07a42 = 0;
    bool overflow_07a42 = 0;
    uint16_t direct_page_07a42 = 0;
    uint8_t data_bank_07a42 = 0;
    uint8_t a_0785 = 0;
    uint8_t a_hi_0785 = 0;
    uint8_t x_0785 = 0;
    uint8_t y_0785 = 0;
    bool carry_0785 = 0;
    bool overflow_0785 = 0;
    uint16_t direct_page_0785 = 0;
    uint8_t data_bank_0785 = 0;
    uint8_t a_07852 = 0;
    uint8_t a_hi_07852 = 0;
    uint16_t x_07852 = 0;
    uint16_t y_07852 = 0;
    bool carry_07852 = 0;
    bool overflow_07852 = 0;
    uint16_t direct_page_07852 = 0;
    uint8_t data_bank_07852 = 0;
    uint8_t a_hi_075a3 = 0;
    uint8_t x_075a3 = 0;
    uint8_t y_075a3 = 0;
    bool carry_075a3 = 0;
    bool overflow_075a3 = 0;
    uint16_t direct_page_075a3 = 0;
    uint8_t data_bank_075a3 = 0;
    uint8_t a_hi_075a4 = 0;
    uint16_t x_075a4 = 0;
    uint16_t y_075a4 = 0;
    bool carry_075a4 = 0;
    bool overflow_075a4 = 0;
    uint16_t direct_page_075a4 = 0;
    uint8_t data_bank_075a4 = 0;
    uint8_t a_hi_07a43 = 0;
    bool carry_07a43 = 0;
    bool overflow_07a43 = 0;
    uint16_t direct_page_07a43 = 0;
    uint8_t data_bank_07a43 = 0;
    uint8_t a_hi_07a44 = 0;
    bool carry_07a44 = 0;
    bool overflow_07a44 = 0;
    uint16_t direct_page_07a44 = 0;
    uint8_t data_bank_07a44 = 0;
    uint8_t a_07853 = 0;
    uint8_t a_hi_07853 = 0;
    uint8_t x_07853 = 0;
    uint8_t y_07853 = 0;
    bool carry_07853 = 0;
    bool overflow_07853 = 0;
    uint16_t direct_page_07853 = 0;
    uint8_t data_bank_07853 = 0;
    uint8_t a_07854 = 0;
    uint8_t a_hi_07854 = 0;
    uint16_t x_07854 = 0;
    uint16_t y_07854 = 0;
    bool carry_07854 = 0;
    bool overflow_07854 = 0;
    uint16_t direct_page_07854 = 0;
    uint8_t data_bank_07854 = 0;
    uint8_t a_07df = 0;
    uint8_t a_hi_07df = 0;
    uint16_t x_07df = 0;
    uint16_t y_07df = 0;
    bool carry_07df = 0;
    bool zero_07df = 0;
    bool negative_07df = 0;
    bool overflow_07df = 0;
    uint16_t direct_page_07df = 0;
    uint8_t data_bank_07df = 0;
    uint8_t a_07df2 = 0;
    uint8_t a_hi_07df2 = 0;
    uint16_t x_07df2 = 0;
    uint16_t y_07df2 = 0;
    bool carry_07df2 = 0;
    bool zero_07df2 = 0;
    bool negative_07df2 = 0;
    bool overflow_07df2 = 0;
    uint16_t direct_page_07df2 = 0;
    uint8_t data_bank_07df2 = 0;
    if (RAM8(0xA16D) != 0) {
        a_hi_0748 = a_hi;
        x_0748 = x;
        y_0748 = y;
        carry_0748 = carry;
        overflow_0748 = overflow;
        data_bank_0748 = 0x7E;
        goto shared_0748;
    }
    if (RAM8(0xA162) != 1) {
        a_hi_0714 = a_hi;
        x_0714 = x;
        y_0714 = y;
        overflow_0714 = overflow;
        data_bank_0714 = 0x7E;
        goto shared_0714;
    }
    RAM8(0x1D11) |= 8;
    RAM8(0x1D04) |= 5;
    RAM8(0x1D12) &= 0xDF;
    a_hi_0714 = a_hi;
    x_0714 = x;
    y_0714 = y;
    overflow_0714 = overflow;
    data_bank_0714 = 0x7E;
    shared_0714:;
    uint8_t value9 = RAM8(0x1D03);
    RAM8(0x0000 + sp0) = data_bank_0714;
    RAM8(0x0000 + sp0 - 1) = value9;
    uint8_t value10 = BUS8_RDP(c, (value9 << 0x10) + (uint16_t)(y_0714 + 1));
    r->a = (a_hi_0714 << 8) | value10;
    r->x = x_0714;
    r->y = (uint16_t)(y_0714 + 1);
    r->z = data_bank_0714 == 0;
    r->n = data_bank_0714 & 0x80;
    r->v = overflow_0714;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_0714;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0724, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0724); } /* select_dialogue_window_geometry_from_state */
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    RAM8(0x0000 + sp0) = (uint8_t)a_all;
    BUS8_SET(c, (db_ret << 0x10) + 0xA16D, 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (db_ret << 0x10) + 0xA166, value11);
    uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0xA164);
    BUS8_SET(c, (db_ret << 0x10) + 0xA168, (uint8_t)(value11 + value12));
    BUS8_SET(c, (db_ret << 0x10) + 0xA165, a_all >> 8);
    uint8_t value13 = BUS8_RDP(c, (db_ret << 0x10) + 0xA163);
    BUS8_SET(c, (db_ret << 0x10) + 0xA167, (uint8_t)((uint8_t)((a_all >> 8) + value13) + 1));
    uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16C);
    BUS8_SET(c, (db_ret << 0x10) + 0xA16C, (uint8_t)(value14 + 1));
    uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16C);
    BUS8_SET(c, (db_ret << 0x10) + 0xA16C, (uint8_t)(value15 + 1));
    a_hi_0748 = (uint8_t)(value11 + value12);
    x_0748 = x_ret;
    y_0748 = y_ret;
    carry_0748 = (a_all >> 8) + value13 > 0xFF;
    overflow_0748 = (((a_all >> 8) ^ (uint8_t)((a_all >> 8) + value13)) & (value13 ^ (uint8_t)((a_all >> 8) + value13)) & 0x80) != 0;
    data_bank_0748 = db_ret;
    goto shared_0748;
    shared_0748:;
    uint8_t value6 = BUS8_RDP(c, (data_bank_0748 << 0x10) + 0xA16C);
    BUS8_SET(c, (data_bank_0748 << 0x10) + 0xA164, value6);
    uint8_t value7 = BUS8_RDP(c, (data_bank_0748 << 0x10) + 0xA166);
    BUS8_SET(c, (data_bank_0748 << 0x10) + 0xA157, value7);
    uint8_t value8 = BUS8_RDP(c, (data_bank_0748 << 0x10) + 0xA165);
    BUS8_SET(c, (data_bank_0748 << 0x10) + 0xA156, value8);
    a_hi_075a = a_hi_0748;
    x_075a = x_0748;
    y_075a = y_0748;
    carry_075a = carry_0748;
    overflow_075a = overflow_0748;
    direct_page_075a = 0;
    data_bank_075a = data_bank_0748;
    goto shared_075A;
    shared_075A:;
    r->a = (a_hi_075a << 8) | a;
    r->x = x_075a;
    r->y = y_075a;
    r->c = carry_075a;
    r->v = overflow_075a;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_075a;
    r->dp = direct_page_075a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x075C, 0xC01BBD); GUARD_JSR(c, sp_call, 0x075C); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret2 = r->db;
    uint8_t value16 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA156, (uint8_t)(value16 + 1));
    r->z = (uint8_t)(value16 + 1) == 0;
    r->n = (uint8_t)(value16 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0762, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0762); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret2 = r->v;
    if (m_ret) {
        uint8_t value17 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value17 - 1));
        uint8_t value18 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, (uint8_t)(value18 + 1));
        uint8_t value19 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA164, (uint8_t)(value19 - 1));
        if ((uint8_t)(value19 - 1) != 0) {
            if (x_ret3) {
                a_hi_075a2 = a_all3 >> 8;
                x_075a2 = (uint8_t)x_ret4;
                y_075a2 = (uint8_t)y_ret3;
                carry_075a2 = carry_ret3;
                overflow_075a2 = overflow_ret2;
                direct_page_075a2 = dp_ret;
                data_bank_075a2 = db_ret3;
                goto shared_075A_1;
            } else {
                a_hi_075a = a_all3 >> 8;
                x_075a = x_ret4;
                y_075a = y_ret3;
                carry_075a = carry_ret3;
                overflow_075a = overflow_ret2;
                direct_page_075a = dp_ret;
                data_bank_075a = db_ret3;
                goto shared_075A;
            }
        }
        uint8_t value20 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA16C);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA164, value20);
        uint8_t value21 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA163, (uint8_t)(value21 - 1));
        if ((uint8_t)(value21 - 1) == 0) {
            if (x_ret3) {
                a_hi_07a4 = a_all3 >> 8;
                carry_07a4 = carry_ret3;
                overflow_07a4 = overflow_ret2;
                direct_page_07a4 = dp_ret;
                data_bank_07a4 = db_ret3;
                goto shared_07A4;
            } else {
                a_hi_07a42 = a_all3 >> 8;
                carry_07a42 = carry_ret3;
                overflow_07a42 = overflow_ret2;
                direct_page_07a42 = dp_ret;
                data_bank_07a42 = db_ret3;
                goto shared_07A4_1;
            }
        }
        uint8_t value22 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA166);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, value22);
        uint8_t value23 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, value23);
        if (x_ret3) {
            a_0785 = value23;
            a_hi_0785 = a_all3 >> 8;
            x_0785 = (uint8_t)x_ret4;
            y_0785 = (uint8_t)y_ret3;
            carry_0785 = carry_ret3;
            overflow_0785 = overflow_ret2;
            direct_page_0785 = dp_ret;
            data_bank_0785 = db_ret3;
            goto shared_0785;
        } else {
            a_07852 = value23;
            a_hi_07852 = a_all3 >> 8;
            x_07852 = x_ret4;
            y_07852 = y_ret3;
            carry_07852 = carry_ret3;
            overflow_07852 = overflow_ret2;
            direct_page_07852 = dp_ret;
            data_bank_07852 = db_ret3;
            goto shared_0785_1;
        }
    } else {
        uint16_t value24 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA156, (uint16_t)(value24 - 1));
        uint16_t value25 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA157, (uint16_t)(value25 + 1));
        uint16_t value26 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA164, (uint16_t)(value26 - 1));
        if ((uint16_t)(value26 - 1) != 0) {
            if (x_ret3) {
                a_hi_075a3 = a_all3 >> 8;
                x_075a3 = (uint8_t)x_ret4;
                y_075a3 = (uint8_t)y_ret3;
                carry_075a3 = carry_ret3;
                overflow_075a3 = overflow_ret2;
                direct_page_075a3 = dp_ret;
                data_bank_075a3 = db_ret3;
                goto shared_075A_2;
            } else {
                a_hi_075a4 = a_all3 >> 8;
                x_075a4 = x_ret4;
                y_075a4 = y_ret3;
                carry_075a4 = carry_ret3;
                overflow_075a4 = overflow_ret2;
                direct_page_075a4 = dp_ret;
                data_bank_075a4 = db_ret3;
                goto shared_075A_3;
            }
        }
        uint16_t value27 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA16C);
        BUS16_SET(c, (db_ret3 << 0x10) + 0xA164, value27);
        uint16_t value28 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA163, (uint16_t)(value28 - 1));
        if ((uint16_t)(value28 - 1) == 0) {
            if (x_ret3) {
                a_hi_07a43 = value27 >> 8;
                carry_07a43 = carry_ret3;
                overflow_07a43 = overflow_ret2;
                direct_page_07a43 = dp_ret;
                data_bank_07a43 = db_ret3;
                goto shared_07A4_2;
            } else {
                a_hi_07a44 = value27 >> 8;
                carry_07a44 = carry_ret3;
                overflow_07a44 = overflow_ret2;
                direct_page_07a44 = dp_ret;
                data_bank_07a44 = db_ret3;
                goto shared_07A4_3;
            }
        }
        uint16_t value29 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA166);
        BUS16_SET(c, (db_ret3 << 0x10) + 0xA157, value29);
        uint16_t value30 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA167);
        BUS16_SET(c, (db_ret3 << 0x10) + 0xA156, value30);
        if (x_ret3) {
            a_07853 = (uint8_t)value30;
            a_hi_07853 = value30 >> 8;
            x_07853 = (uint8_t)x_ret4;
            y_07853 = (uint8_t)y_ret3;
            carry_07853 = carry_ret3;
            overflow_07853 = overflow_ret2;
            direct_page_07853 = dp_ret;
            data_bank_07853 = db_ret3;
            goto shared_0785_2;
        } else {
            a_07854 = (uint8_t)value30;
            a_hi_07854 = value30 >> 8;
            x_07854 = x_ret4;
            y_07854 = y_ret3;
            carry_07854 = carry_ret3;
            overflow_07854 = overflow_ret2;
            direct_page_07854 = dp_ret;
            data_bank_07854 = db_ret3;
            goto shared_0785_3;
        }
    }
    shared_075A_1:;
    r->a = (a_hi_075a2 << 8) | a;
    r->x = x_075a2;
    r->y = y_075a2;
    r->c = carry_075a2;
    r->v = overflow_075a2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_075a2;
    r->dp = direct_page_075a2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x075C, 0xC01BBD); GUARD_JSR(c, sp_call, 0x075C); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret4 = r->db;
    uint8_t value31 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value31 + 1));
    r->z = (uint8_t)(value31 + 1) == 0;
    r->n = (uint8_t)(value31 + 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0762, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0762); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret5 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret6 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret4 = r->v;
    if (m_ret2) {
        uint8_t value32 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA156, (uint8_t)(value32 - 1));
        uint8_t value33 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA157, (uint8_t)(value33 + 1));
        uint8_t value34 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA164, (uint8_t)(value34 - 1));
        if ((uint8_t)(value34 - 1) != 0) {
            if (x_ret6) {
                a_hi_075a2 = a_all5 >> 8;
                x_075a2 = (uint8_t)x_ret7;
                y_075a2 = (uint8_t)y_ret5;
                carry_075a2 = carry_ret5;
                overflow_075a2 = overflow_ret4;
                direct_page_075a2 = dp_ret2;
                data_bank_075a2 = db_ret5;
                goto shared_075A_1;
            } else {
                a_hi_075a = a_all5 >> 8;
                x_075a = x_ret7;
                y_075a = y_ret5;
                carry_075a = carry_ret5;
                overflow_075a = overflow_ret4;
                direct_page_075a = dp_ret2;
                data_bank_075a = db_ret5;
                goto shared_075A;
            }
        }
        uint8_t value35 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA16C);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA164, value35);
        uint8_t value36 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA163, (uint8_t)(value36 - 1));
        if ((uint8_t)(value36 - 1) == 0) {
            if (x_ret6) {
                a_hi_07a4 = a_all5 >> 8;
                carry_07a4 = carry_ret5;
                overflow_07a4 = overflow_ret4;
                direct_page_07a4 = dp_ret2;
                data_bank_07a4 = db_ret5;
                goto shared_07A4;
            } else {
                a_hi_07a42 = a_all5 >> 8;
                carry_07a42 = carry_ret5;
                overflow_07a42 = overflow_ret4;
                direct_page_07a42 = dp_ret2;
                data_bank_07a42 = db_ret5;
                goto shared_07A4_1;
            }
        }
        uint8_t value37 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA166);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA157, value37);
        uint8_t value38 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA156, value38);
        if (x_ret6) {
            a_0785 = value38;
            a_hi_0785 = a_all5 >> 8;
            x_0785 = (uint8_t)x_ret7;
            y_0785 = (uint8_t)y_ret5;
            carry_0785 = carry_ret5;
            overflow_0785 = overflow_ret4;
            direct_page_0785 = dp_ret2;
            data_bank_0785 = db_ret5;
            goto shared_0785;
        } else {
            a_07852 = value38;
            a_hi_07852 = a_all5 >> 8;
            x_07852 = x_ret7;
            y_07852 = y_ret5;
            carry_07852 = carry_ret5;
            overflow_07852 = overflow_ret4;
            direct_page_07852 = dp_ret2;
            data_bank_07852 = db_ret5;
            goto shared_0785_1;
        }
    } else {
        uint16_t value39 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA156, (uint16_t)(value39 - 1));
        uint16_t value40 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA157, (uint16_t)(value40 + 1));
        uint16_t value41 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA164, (uint16_t)(value41 - 1));
        if ((uint16_t)(value41 - 1) != 0) {
            if (x_ret6) {
                a_hi_075a3 = a_all5 >> 8;
                x_075a3 = (uint8_t)x_ret7;
                y_075a3 = (uint8_t)y_ret5;
                carry_075a3 = carry_ret5;
                overflow_075a3 = overflow_ret4;
                direct_page_075a3 = dp_ret2;
                data_bank_075a3 = db_ret5;
                goto shared_075A_2;
            } else {
                a_hi_075a4 = a_all5 >> 8;
                x_075a4 = x_ret7;
                y_075a4 = y_ret5;
                carry_075a4 = carry_ret5;
                overflow_075a4 = overflow_ret4;
                direct_page_075a4 = dp_ret2;
                data_bank_075a4 = db_ret5;
                goto shared_075A_3;
            }
        }
        uint16_t value42 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA16C);
        BUS16_SET(c, (db_ret5 << 0x10) + 0xA164, value42);
        uint16_t value43 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA163, (uint16_t)(value43 - 1));
        if ((uint16_t)(value43 - 1) == 0) {
            if (x_ret6) {
                a_hi_07a43 = value42 >> 8;
                carry_07a43 = carry_ret5;
                overflow_07a43 = overflow_ret4;
                direct_page_07a43 = dp_ret2;
                data_bank_07a43 = db_ret5;
                goto shared_07A4_2;
            } else {
                a_hi_07a44 = value42 >> 8;
                carry_07a44 = carry_ret5;
                overflow_07a44 = overflow_ret4;
                direct_page_07a44 = dp_ret2;
                data_bank_07a44 = db_ret5;
                goto shared_07A4_3;
            }
        }
        uint16_t value44 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA166);
        BUS16_SET(c, (db_ret5 << 0x10) + 0xA157, value44);
        uint16_t value45 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA167);
        BUS16_SET(c, (db_ret5 << 0x10) + 0xA156, value45);
        if (x_ret6) {
            a_07853 = (uint8_t)value45;
            a_hi_07853 = value45 >> 8;
            x_07853 = (uint8_t)x_ret7;
            y_07853 = (uint8_t)y_ret5;
            carry_07853 = carry_ret5;
            overflow_07853 = overflow_ret4;
            direct_page_07853 = dp_ret2;
            data_bank_07853 = db_ret5;
            goto shared_0785_2;
        } else {
            a_07854 = (uint8_t)value45;
            a_hi_07854 = value45 >> 8;
            x_07854 = x_ret7;
            y_07854 = y_ret5;
            carry_07854 = carry_ret5;
            overflow_07854 = overflow_ret4;
            direct_page_07854 = dp_ret2;
            data_bank_07854 = db_ret5;
            goto shared_0785_3;
        }
    }
    shared_07A4:;
    BUS8_SET(c, (data_bank_07a4 << 0x10) + 0x9400, 0);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_07A4_1:;
    BUS8_SET(c, (data_bank_07a42 << 0x10) + 0x9400, 0);
    r->a = 0x1F;
    r->x = 0x9400;
    r->y = 0x9401;
    r->c = carry_07a42;
    r->z = 0;
    r->n = 0;
    r->v = overflow_07a42;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_07a42;
    r->dp = direct_page_07a42;
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    uint16_t y_moved = r->y;
    RAM16_SET(0x940E, 0xFF);
    RAM16_SET(0x1D06, 0x4900);
    RAM16_SET(0x1D08, 0x20);
    r->a = 7;
    r->x = 0x4900;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x07D0, 0xC00FFA); GUARD_JSR(c, sp_call, 0x07D0); } /* request_dialogue_transfer_and_conditional_window_flags */
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    RAM8(0xA15E)++;
    uint8_t value46 = RAM8(0xA16C);
    RAM8(0xA164) = (uint8_t)(value46 - 2);
    RAM8(0xA168)++;
    a_07df = (uint8_t)(value46 - 2);
    a_hi_07df = a_all6 >> 8;
    x_07df = 0x4900;
    y_07df = y_moved;
    carry_07df = carry_ret6;
    zero_07df = RAM8(0xA168) == 0;
    negative_07df = RAM8(0xA168) & 0x80;
    overflow_07df = overflow_07a42;
    direct_page_07df = direct_page_07a42;
    data_bank_07df = 0x7E;
    goto shared_07DF;
    shared_0785:;
    r->a = (a_hi_0785 << 8) | a_0785;
    r->x = x_0785;
    r->y = y_0785;
    r->c = carry_0785;
    r->v = overflow_0785;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_0785;
    r->dp = direct_page_0785;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0787, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0787); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret6 = r->db;
    uint8_t value47 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret6 << 0x10) + 0xA156, (uint8_t)(value47 - 1));
    r->z = (uint8_t)(value47 - 1) == 0;
    r->n = (uint8_t)(value47 - 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x078D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x078D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret3 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all8 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret7 = r->y;
    bool carry_ret8 = r->c;
    bool overflow_ret6 = r->v;
    if (m_ret3) {
        uint8_t value48 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA156, (uint8_t)(value48 + 1));
        uint8_t value49 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA157, (uint8_t)(value49 + 1));
        uint8_t value50 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA164, (uint8_t)(value50 - 1));
        if ((uint8_t)(value50 - 1) != 0) {
            a_07852 = (uint8_t)a_all8;
            a_hi_07852 = a_all8 >> 8;
            x_07852 = x_ret9;
            y_07852 = y_ret7;
            carry_07852 = carry_ret8;
            overflow_07852 = overflow_ret6;
            direct_page_07852 = dp_ret3;
            data_bank_07852 = db_ret7;
            goto shared_0785_1;
        }
        uint8_t value51 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA165);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA165, (uint8_t)(value51 + 1));
        uint8_t value52 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA167, (uint8_t)(value52 - 1));
        uint8_t value53 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret7 << 0x10) + 0xA163, (uint8_t)(value53 - 1));
        if ((uint8_t)(value53 - 1) != 0) {
            a_07df = (uint8_t)a_all8;
            a_hi_07df = a_all8 >> 8;
            x_07df = x_ret9;
            y_07df = y_ret7;
            carry_07df = carry_ret8;
            zero_07df = (uint8_t)(value53 - 1) == 0;
            negative_07df = (uint8_t)(value53 - 1) & 0x80;
            overflow_07df = overflow_ret6;
            direct_page_07df = dp_ret3;
            data_bank_07df = db_ret7;
            goto shared_07DF;
        }
        a_hi_07a42 = a_all8 >> 8;
        carry_07a42 = carry_ret8;
        overflow_07a42 = overflow_ret6;
        direct_page_07a42 = dp_ret3;
        data_bank_07a42 = db_ret7;
        goto shared_07A4_1;
    } else {
        uint16_t value54 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA156, (uint16_t)(value54 + 1));
        uint16_t value55 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA157, (uint16_t)(value55 + 1));
        uint16_t value56 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA164, (uint16_t)(value56 - 1));
        if ((uint16_t)(value56 - 1) != 0) {
            a_07854 = (uint8_t)a_all8;
            a_hi_07854 = a_all8 >> 8;
            x_07854 = x_ret9;
            y_07854 = y_ret7;
            carry_07854 = carry_ret8;
            overflow_07854 = overflow_ret6;
            direct_page_07854 = dp_ret3;
            data_bank_07854 = db_ret7;
            goto shared_0785_3;
        }
        uint16_t value57 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA165);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA165, (uint16_t)(value57 + 1));
        uint16_t value58 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA167);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA167, (uint16_t)(value58 - 1));
        uint16_t value59 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA163, (uint16_t)(value59 - 1));
        if ((uint16_t)(value59 - 1) != 0) {
            a_07df2 = (uint8_t)a_all8;
            a_hi_07df2 = a_all8 >> 8;
            x_07df2 = x_ret9;
            y_07df2 = y_ret7;
            carry_07df2 = carry_ret8;
            zero_07df2 = (uint16_t)(value59 - 1) == 0;
            negative_07df2 = (uint16_t)(value59 - 1) & 0x8000;
            overflow_07df2 = overflow_ret6;
            direct_page_07df2 = dp_ret3;
            data_bank_07df2 = db_ret7;
            goto shared_07DF_1;
        }
        a_hi_07a44 = a_all8 >> 8;
        carry_07a44 = carry_ret8;
        overflow_07a44 = overflow_ret6;
        direct_page_07a44 = dp_ret3;
        data_bank_07a44 = db_ret7;
        goto shared_07A4_3;
    }
    shared_0785_1:;
    r->a = (a_hi_07852 << 8) | a_07852;
    r->x = x_07852;
    r->y = y_07852;
    r->c = carry_07852;
    r->v = overflow_07852;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_07852;
    r->dp = direct_page_07852;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0787, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0787); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret8 = r->db;
    uint8_t value60 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret8 << 0x10) + 0xA156, (uint8_t)(value60 - 1));
    r->z = (uint8_t)(value60 - 1) == 0;
    r->n = (uint8_t)(value60 - 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x078D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x078D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret9 = r->db;
    bool m_ret4 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all10 = r->a;
    uint16_t x_ret11 = r->x;
    uint16_t y_ret9 = r->y;
    bool carry_ret10 = r->c;
    bool overflow_ret8 = r->v;
    if (m_ret4) {
        uint8_t value61 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA156, (uint8_t)(value61 + 1));
        uint8_t value62 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA157, (uint8_t)(value62 + 1));
        uint8_t value63 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA164, (uint8_t)(value63 - 1));
        if ((uint8_t)(value63 - 1) != 0) {
            a_07852 = (uint8_t)a_all10;
            a_hi_07852 = a_all10 >> 8;
            x_07852 = x_ret11;
            y_07852 = y_ret9;
            carry_07852 = carry_ret10;
            overflow_07852 = overflow_ret8;
            direct_page_07852 = dp_ret4;
            data_bank_07852 = db_ret9;
            goto shared_0785_1;
        }
        uint8_t value64 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA165);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA165, (uint8_t)(value64 + 1));
        uint8_t value65 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA167, (uint8_t)(value65 - 1));
        uint8_t value66 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret9 << 0x10) + 0xA163, (uint8_t)(value66 - 1));
        if ((uint8_t)(value66 - 1) != 0) {
            a_07df = (uint8_t)a_all10;
            a_hi_07df = a_all10 >> 8;
            x_07df = x_ret11;
            y_07df = y_ret9;
            carry_07df = carry_ret10;
            zero_07df = (uint8_t)(value66 - 1) == 0;
            negative_07df = (uint8_t)(value66 - 1) & 0x80;
            overflow_07df = overflow_ret8;
            direct_page_07df = dp_ret4;
            data_bank_07df = db_ret9;
            goto shared_07DF;
        }
        a_hi_07a42 = a_all10 >> 8;
        carry_07a42 = carry_ret10;
        overflow_07a42 = overflow_ret8;
        direct_page_07a42 = dp_ret4;
        data_bank_07a42 = db_ret9;
        goto shared_07A4_1;
    } else {
        uint16_t value67 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA156, (uint16_t)(value67 + 1));
        uint16_t value68 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA157, (uint16_t)(value68 + 1));
        uint16_t value69 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA164, (uint16_t)(value69 - 1));
        if ((uint16_t)(value69 - 1) != 0) {
            a_07854 = (uint8_t)a_all10;
            a_hi_07854 = a_all10 >> 8;
            x_07854 = x_ret11;
            y_07854 = y_ret9;
            carry_07854 = carry_ret10;
            overflow_07854 = overflow_ret8;
            direct_page_07854 = dp_ret4;
            data_bank_07854 = db_ret9;
            goto shared_0785_3;
        }
        uint16_t value70 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA165);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA165, (uint16_t)(value70 + 1));
        uint16_t value71 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA167);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA167, (uint16_t)(value71 - 1));
        uint16_t value72 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret9 << 0x10) + 0xA163, (uint16_t)(value72 - 1));
        if ((uint16_t)(value72 - 1) != 0) {
            a_07df2 = (uint8_t)a_all10;
            a_hi_07df2 = a_all10 >> 8;
            x_07df2 = x_ret11;
            y_07df2 = y_ret9;
            carry_07df2 = carry_ret10;
            zero_07df2 = (uint16_t)(value72 - 1) == 0;
            negative_07df2 = (uint16_t)(value72 - 1) & 0x8000;
            overflow_07df2 = overflow_ret8;
            direct_page_07df2 = dp_ret4;
            data_bank_07df2 = db_ret9;
            goto shared_07DF_1;
        }
        a_hi_07a44 = a_all10 >> 8;
        carry_07a44 = carry_ret10;
        overflow_07a44 = overflow_ret8;
        direct_page_07a44 = dp_ret4;
        data_bank_07a44 = db_ret9;
        goto shared_07A4_3;
    }
    shared_075A_2:;
    r->a = (a_hi_075a3 << 8) | a;
    r->x = x_075a3;
    r->y = y_075a3;
    r->c = carry_075a3;
    r->v = overflow_075a3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_075a3;
    r->dp = direct_page_075a3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x075C, 0xC01BBD); GUARD_JSR(c, sp_call, 0x075C); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret10 = r->db;
    uint8_t value73 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret10 << 0x10) + 0xA156, (uint8_t)(value73 + 1));
    r->z = (uint8_t)(value73 + 1) == 0;
    r->n = (uint8_t)(value73 + 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0762, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0762); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret11 = r->db;
    bool m_ret5 = r->mf;
    bool x_ret13 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t x_ret14 = r->x;
    uint16_t y_ret11 = r->y;
    bool carry_ret12 = r->c;
    bool overflow_ret10 = r->v;
    if (m_ret5) {
        uint8_t value74 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA156, (uint8_t)(value74 - 1));
        uint8_t value75 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA157, (uint8_t)(value75 + 1));
        uint8_t value76 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA164, (uint8_t)(value76 - 1));
        if ((uint8_t)(value76 - 1) != 0) {
            if (x_ret13) {
                a_hi_075a2 = a_all12 >> 8;
                x_075a2 = (uint8_t)x_ret14;
                y_075a2 = (uint8_t)y_ret11;
                carry_075a2 = carry_ret12;
                overflow_075a2 = overflow_ret10;
                direct_page_075a2 = dp_ret5;
                data_bank_075a2 = db_ret11;
                goto shared_075A_1;
            } else {
                a_hi_075a = a_all12 >> 8;
                x_075a = x_ret14;
                y_075a = y_ret11;
                carry_075a = carry_ret12;
                overflow_075a = overflow_ret10;
                direct_page_075a = dp_ret5;
                data_bank_075a = db_ret11;
                goto shared_075A;
            }
        }
        uint8_t value77 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA16C);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA164, value77);
        uint8_t value78 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA163, (uint8_t)(value78 - 1));
        if ((uint8_t)(value78 - 1) == 0) {
            if (x_ret13) {
                a_hi_07a4 = a_all12 >> 8;
                carry_07a4 = carry_ret12;
                overflow_07a4 = overflow_ret10;
                direct_page_07a4 = dp_ret5;
                data_bank_07a4 = db_ret11;
                goto shared_07A4;
            } else {
                a_hi_07a42 = a_all12 >> 8;
                carry_07a42 = carry_ret12;
                overflow_07a42 = overflow_ret10;
                direct_page_07a42 = dp_ret5;
                data_bank_07a42 = db_ret11;
                goto shared_07A4_1;
            }
        }
        uint8_t value79 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA166);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA157, value79);
        uint8_t value80 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret11 << 0x10) + 0xA156, value80);
        if (x_ret13) {
            a_0785 = value80;
            a_hi_0785 = a_all12 >> 8;
            x_0785 = (uint8_t)x_ret14;
            y_0785 = (uint8_t)y_ret11;
            carry_0785 = carry_ret12;
            overflow_0785 = overflow_ret10;
            direct_page_0785 = dp_ret5;
            data_bank_0785 = db_ret11;
            goto shared_0785;
        } else {
            a_07852 = value80;
            a_hi_07852 = a_all12 >> 8;
            x_07852 = x_ret14;
            y_07852 = y_ret11;
            carry_07852 = carry_ret12;
            overflow_07852 = overflow_ret10;
            direct_page_07852 = dp_ret5;
            data_bank_07852 = db_ret11;
            goto shared_0785_1;
        }
    } else {
        uint16_t value81 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0xA156, (uint16_t)(value81 - 1));
        uint16_t value82 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0xA157, (uint16_t)(value82 + 1));
        uint16_t value83 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0xA164, (uint16_t)(value83 - 1));
        if ((uint16_t)(value83 - 1) != 0) {
            if (x_ret13) {
                a_hi_075a3 = a_all12 >> 8;
                x_075a3 = (uint8_t)x_ret14;
                y_075a3 = (uint8_t)y_ret11;
                carry_075a3 = carry_ret12;
                overflow_075a3 = overflow_ret10;
                direct_page_075a3 = dp_ret5;
                data_bank_075a3 = db_ret11;
                goto shared_075A_2;
            } else {
                a_hi_075a4 = a_all12 >> 8;
                x_075a4 = x_ret14;
                y_075a4 = y_ret11;
                carry_075a4 = carry_ret12;
                overflow_075a4 = overflow_ret10;
                direct_page_075a4 = dp_ret5;
                data_bank_075a4 = db_ret11;
                goto shared_075A_3;
            }
        }
        uint16_t value84 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA16C);
        BUS16_SET(c, (db_ret11 << 0x10) + 0xA164, value84);
        uint16_t value85 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0xA163, (uint16_t)(value85 - 1));
        if ((uint16_t)(value85 - 1) == 0) {
            if (x_ret13) {
                a_hi_07a43 = value84 >> 8;
                carry_07a43 = carry_ret12;
                overflow_07a43 = overflow_ret10;
                direct_page_07a43 = dp_ret5;
                data_bank_07a43 = db_ret11;
                goto shared_07A4_2;
            } else {
                a_hi_07a44 = value84 >> 8;
                carry_07a44 = carry_ret12;
                overflow_07a44 = overflow_ret10;
                direct_page_07a44 = dp_ret5;
                data_bank_07a44 = db_ret11;
                goto shared_07A4_3;
            }
        }
        uint16_t value86 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA166);
        BUS16_SET(c, (db_ret11 << 0x10) + 0xA157, value86);
        uint16_t value87 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA167);
        BUS16_SET(c, (db_ret11 << 0x10) + 0xA156, value87);
        if (x_ret13) {
            a_07853 = (uint8_t)value87;
            a_hi_07853 = value87 >> 8;
            x_07853 = (uint8_t)x_ret14;
            y_07853 = (uint8_t)y_ret11;
            carry_07853 = carry_ret12;
            overflow_07853 = overflow_ret10;
            direct_page_07853 = dp_ret5;
            data_bank_07853 = db_ret11;
            goto shared_0785_2;
        } else {
            a_07854 = (uint8_t)value87;
            a_hi_07854 = value87 >> 8;
            x_07854 = x_ret14;
            y_07854 = y_ret11;
            carry_07854 = carry_ret12;
            overflow_07854 = overflow_ret10;
            direct_page_07854 = dp_ret5;
            data_bank_07854 = db_ret11;
            goto shared_0785_3;
        }
    }
    shared_075A_3:;
    r->a = (a_hi_075a4 << 8) | a;
    r->x = x_075a4;
    r->y = y_075a4;
    r->c = carry_075a4;
    r->v = overflow_075a4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_075a4;
    r->dp = direct_page_075a4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x075C, 0xC01BBD); GUARD_JSR(c, sp_call, 0x075C); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret12 = r->db;
    uint8_t value88 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret12 << 0x10) + 0xA156, (uint8_t)(value88 + 1));
    r->z = (uint8_t)(value88 + 1) == 0;
    r->n = (uint8_t)(value88 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0762, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0762); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret13 = r->db;
    bool m_ret6 = r->mf;
    bool x_ret16 = r->xf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret17 = r->x;
    uint16_t y_ret13 = r->y;
    bool carry_ret14 = r->c;
    bool overflow_ret12 = r->v;
    if (m_ret6) {
        uint8_t value89 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA156, (uint8_t)(value89 - 1));
        uint8_t value90 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA157, (uint8_t)(value90 + 1));
        uint8_t value91 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA164, (uint8_t)(value91 - 1));
        if ((uint8_t)(value91 - 1) != 0) {
            if (x_ret16) {
                a_hi_075a2 = a_all14 >> 8;
                x_075a2 = (uint8_t)x_ret17;
                y_075a2 = (uint8_t)y_ret13;
                carry_075a2 = carry_ret14;
                overflow_075a2 = overflow_ret12;
                direct_page_075a2 = dp_ret6;
                data_bank_075a2 = db_ret13;
                goto shared_075A_1;
            } else {
                a_hi_075a = a_all14 >> 8;
                x_075a = x_ret17;
                y_075a = y_ret13;
                carry_075a = carry_ret14;
                overflow_075a = overflow_ret12;
                direct_page_075a = dp_ret6;
                data_bank_075a = db_ret13;
                goto shared_075A;
            }
        }
        uint8_t value92 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA16C);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA164, value92);
        uint8_t value93 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA163, (uint8_t)(value93 - 1));
        if ((uint8_t)(value93 - 1) == 0) {
            if (x_ret16) {
                a_hi_07a4 = a_all14 >> 8;
                carry_07a4 = carry_ret14;
                overflow_07a4 = overflow_ret12;
                direct_page_07a4 = dp_ret6;
                data_bank_07a4 = db_ret13;
                goto shared_07A4;
            } else {
                a_hi_07a42 = a_all14 >> 8;
                carry_07a42 = carry_ret14;
                overflow_07a42 = overflow_ret12;
                direct_page_07a42 = dp_ret6;
                data_bank_07a42 = db_ret13;
                goto shared_07A4_1;
            }
        }
        uint8_t value94 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA166);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA157, value94);
        uint8_t value95 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret13 << 0x10) + 0xA156, value95);
        if (x_ret16) {
            a_0785 = value95;
            a_hi_0785 = a_all14 >> 8;
            x_0785 = (uint8_t)x_ret17;
            y_0785 = (uint8_t)y_ret13;
            carry_0785 = carry_ret14;
            overflow_0785 = overflow_ret12;
            direct_page_0785 = dp_ret6;
            data_bank_0785 = db_ret13;
            goto shared_0785;
        } else {
            a_07852 = value95;
            a_hi_07852 = a_all14 >> 8;
            x_07852 = x_ret17;
            y_07852 = y_ret13;
            carry_07852 = carry_ret14;
            overflow_07852 = overflow_ret12;
            direct_page_07852 = dp_ret6;
            data_bank_07852 = db_ret13;
            goto shared_0785_1;
        }
    } else {
        uint16_t value96 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret13 << 0x10) + 0xA156, (uint16_t)(value96 - 1));
        uint16_t value97 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret13 << 0x10) + 0xA157, (uint16_t)(value97 + 1));
        uint16_t value98 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret13 << 0x10) + 0xA164, (uint16_t)(value98 - 1));
        if ((uint16_t)(value98 - 1) != 0) {
            if (x_ret16) {
                a_hi_075a3 = a_all14 >> 8;
                x_075a3 = (uint8_t)x_ret17;
                y_075a3 = (uint8_t)y_ret13;
                carry_075a3 = carry_ret14;
                overflow_075a3 = overflow_ret12;
                direct_page_075a3 = dp_ret6;
                data_bank_075a3 = db_ret13;
                goto shared_075A_2;
            } else {
                a_hi_075a4 = a_all14 >> 8;
                x_075a4 = x_ret17;
                y_075a4 = y_ret13;
                carry_075a4 = carry_ret14;
                overflow_075a4 = overflow_ret12;
                direct_page_075a4 = dp_ret6;
                data_bank_075a4 = db_ret13;
                goto shared_075A_3;
            }
        }
        uint16_t value99 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA16C);
        BUS16_SET(c, (db_ret13 << 0x10) + 0xA164, value99);
        uint16_t value100 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret13 << 0x10) + 0xA163, (uint16_t)(value100 - 1));
        if ((uint16_t)(value100 - 1) == 0) {
            if (x_ret16) {
                a_hi_07a43 = value99 >> 8;
                carry_07a43 = carry_ret14;
                overflow_07a43 = overflow_ret12;
                direct_page_07a43 = dp_ret6;
                data_bank_07a43 = db_ret13;
                goto shared_07A4_2;
            } else {
                a_hi_07a44 = value99 >> 8;
                carry_07a44 = carry_ret14;
                overflow_07a44 = overflow_ret12;
                direct_page_07a44 = dp_ret6;
                data_bank_07a44 = db_ret13;
                goto shared_07A4_3;
            }
        }
        uint16_t value101 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA166);
        BUS16_SET(c, (db_ret13 << 0x10) + 0xA157, value101);
        uint16_t value102 = BUS16_RDP(c, (db_ret13 << 0x10) + 0xA167);
        BUS16_SET(c, (db_ret13 << 0x10) + 0xA156, value102);
        if (x_ret16) {
            a_07853 = (uint8_t)value102;
            a_hi_07853 = value102 >> 8;
            x_07853 = (uint8_t)x_ret17;
            y_07853 = (uint8_t)y_ret13;
            carry_07853 = carry_ret14;
            overflow_07853 = overflow_ret12;
            direct_page_07853 = dp_ret6;
            data_bank_07853 = db_ret13;
            goto shared_0785_2;
        } else {
            a_07854 = (uint8_t)value102;
            a_hi_07854 = value102 >> 8;
            x_07854 = x_ret17;
            y_07854 = y_ret13;
            carry_07854 = carry_ret14;
            overflow_07854 = overflow_ret12;
            direct_page_07854 = dp_ret6;
            data_bank_07854 = db_ret13;
            goto shared_0785_3;
        }
    }
    shared_07A4_2:;
    BUS16_SET(c, (data_bank_07a43 << 0x10) + 0x9400, 0);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_07A4_3:;
    BUS16_SET(c, (data_bank_07a44 << 0x10) + 0x9400, 0);
    r->a = 0x1F;
    r->x = 0x9400;
    r->y = 0x9401;
    r->c = carry_07a44;
    r->z = 0;
    r->n = 0;
    r->v = overflow_07a44;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_07a44;
    r->dp = direct_page_07a44;
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    uint16_t y_moved2 = r->y;
    RAM16_SET(0x940E, 0xFF);
    RAM16_SET(0x1D06, 0x4900);
    RAM16_SET(0x1D08, 0x20);
    r->a = 7;
    r->x = 0x4900;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x07D0, 0xC00FFA); GUARD_JSR(c, sp_call, 0x07D0); } /* request_dialogue_transfer_and_conditional_window_flags */
    uint16_t a_all15 = r->a;
    bool carry_ret15 = r->c;
    RAM8(0xA15E)++;
    uint8_t value103 = RAM8(0xA16C);
    RAM8(0xA164) = (uint8_t)(value103 - 2);
    RAM8(0xA168)++;
    a_07df = (uint8_t)(value103 - 2);
    a_hi_07df = a_all15 >> 8;
    x_07df = 0x4900;
    y_07df = y_moved2;
    carry_07df = carry_ret15;
    zero_07df = RAM8(0xA168) == 0;
    negative_07df = RAM8(0xA168) & 0x80;
    overflow_07df = overflow_07a44;
    direct_page_07df = direct_page_07a44;
    data_bank_07df = 0x7E;
    goto shared_07DF;
    shared_0785_2:;
    r->a = (a_hi_07853 << 8) | a_07853;
    r->x = x_07853;
    r->y = y_07853;
    r->c = carry_07853;
    r->v = overflow_07853;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_07853;
    r->dp = direct_page_07853;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0787, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0787); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret14 = r->db;
    uint8_t value104 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret14 << 0x10) + 0xA156, (uint8_t)(value104 - 1));
    r->z = (uint8_t)(value104 - 1) == 0;
    r->n = (uint8_t)(value104 - 1) & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x078D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x078D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret15 = r->db;
    bool m_ret7 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all17 = r->a;
    uint16_t x_ret19 = r->x;
    uint16_t y_ret15 = r->y;
    bool carry_ret17 = r->c;
    bool overflow_ret14 = r->v;
    if (m_ret7) {
        uint8_t value105 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA156, (uint8_t)(value105 + 1));
        uint8_t value106 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA157, (uint8_t)(value106 + 1));
        uint8_t value107 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA164, (uint8_t)(value107 - 1));
        if ((uint8_t)(value107 - 1) != 0) {
            a_07852 = (uint8_t)a_all17;
            a_hi_07852 = a_all17 >> 8;
            x_07852 = x_ret19;
            y_07852 = y_ret15;
            carry_07852 = carry_ret17;
            overflow_07852 = overflow_ret14;
            direct_page_07852 = dp_ret7;
            data_bank_07852 = db_ret15;
            goto shared_0785_1;
        }
        uint8_t value108 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA165);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA165, (uint8_t)(value108 + 1));
        uint8_t value109 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA167, (uint8_t)(value109 - 1));
        uint8_t value110 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret15 << 0x10) + 0xA163, (uint8_t)(value110 - 1));
        if ((uint8_t)(value110 - 1) != 0) {
            a_07df = (uint8_t)a_all17;
            a_hi_07df = a_all17 >> 8;
            x_07df = x_ret19;
            y_07df = y_ret15;
            carry_07df = carry_ret17;
            zero_07df = (uint8_t)(value110 - 1) == 0;
            negative_07df = (uint8_t)(value110 - 1) & 0x80;
            overflow_07df = overflow_ret14;
            direct_page_07df = dp_ret7;
            data_bank_07df = db_ret15;
            goto shared_07DF;
        }
        a_hi_07a42 = a_all17 >> 8;
        carry_07a42 = carry_ret17;
        overflow_07a42 = overflow_ret14;
        direct_page_07a42 = dp_ret7;
        data_bank_07a42 = db_ret15;
        goto shared_07A4_1;
    } else {
        uint16_t value111 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA156, (uint16_t)(value111 + 1));
        uint16_t value112 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA157, (uint16_t)(value112 + 1));
        uint16_t value113 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA164, (uint16_t)(value113 - 1));
        if ((uint16_t)(value113 - 1) != 0) {
            a_07854 = (uint8_t)a_all17;
            a_hi_07854 = a_all17 >> 8;
            x_07854 = x_ret19;
            y_07854 = y_ret15;
            carry_07854 = carry_ret17;
            overflow_07854 = overflow_ret14;
            direct_page_07854 = dp_ret7;
            data_bank_07854 = db_ret15;
            goto shared_0785_3;
        }
        uint16_t value114 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA165);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA165, (uint16_t)(value114 + 1));
        uint16_t value115 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA167);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA167, (uint16_t)(value115 - 1));
        uint16_t value116 = BUS16_RDP(c, (db_ret15 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0xA163, (uint16_t)(value116 - 1));
        if ((uint16_t)(value116 - 1) != 0) {
            a_07df2 = (uint8_t)a_all17;
            a_hi_07df2 = a_all17 >> 8;
            x_07df2 = x_ret19;
            y_07df2 = y_ret15;
            carry_07df2 = carry_ret17;
            zero_07df2 = (uint16_t)(value116 - 1) == 0;
            negative_07df2 = (uint16_t)(value116 - 1) & 0x8000;
            overflow_07df2 = overflow_ret14;
            direct_page_07df2 = dp_ret7;
            data_bank_07df2 = db_ret15;
            goto shared_07DF_1;
        }
        a_hi_07a44 = a_all17 >> 8;
        carry_07a44 = carry_ret17;
        overflow_07a44 = overflow_ret14;
        direct_page_07a44 = dp_ret7;
        data_bank_07a44 = db_ret15;
        goto shared_07A4_3;
    }
    shared_0785_3:;
    r->a = (a_hi_07854 << 8) | a_07854;
    r->x = x_07854;
    r->y = y_07854;
    r->c = carry_07854;
    r->v = overflow_07854;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_07854;
    r->dp = direct_page_07854;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0787, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0787); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret16 = r->db;
    uint8_t value117 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret16 << 0x10) + 0xA156, (uint8_t)(value117 - 1));
    r->z = (uint8_t)(value117 - 1) == 0;
    r->n = (uint8_t)(value117 - 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x078D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x078D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret17 = r->db;
    bool m_ret8 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all19 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret17 = r->y;
    bool carry_ret19 = r->c;
    bool overflow_ret16 = r->v;
    if (m_ret8) {
        uint8_t value118 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA156, (uint8_t)(value118 + 1));
        uint8_t value119 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA157, (uint8_t)(value119 + 1));
        uint8_t value120 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA164, (uint8_t)(value120 - 1));
        if ((uint8_t)(value120 - 1) != 0) {
            a_07852 = (uint8_t)a_all19;
            a_hi_07852 = a_all19 >> 8;
            x_07852 = x_ret21;
            y_07852 = y_ret17;
            carry_07852 = carry_ret19;
            overflow_07852 = overflow_ret16;
            direct_page_07852 = dp_ret8;
            data_bank_07852 = db_ret17;
            goto shared_0785_1;
        }
        uint8_t value121 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA165);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA165, (uint8_t)(value121 + 1));
        uint8_t value122 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA167);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA167, (uint8_t)(value122 - 1));
        uint8_t value123 = BUS8_RDP(c, (db_ret17 << 0x10) + 0xA163);
        BUS8_SET(c, (db_ret17 << 0x10) + 0xA163, (uint8_t)(value123 - 1));
        if ((uint8_t)(value123 - 1) != 0) {
            a_07df = (uint8_t)a_all19;
            a_hi_07df = a_all19 >> 8;
            x_07df = x_ret21;
            y_07df = y_ret17;
            carry_07df = carry_ret19;
            zero_07df = (uint8_t)(value123 - 1) == 0;
            negative_07df = (uint8_t)(value123 - 1) & 0x80;
            overflow_07df = overflow_ret16;
            direct_page_07df = dp_ret8;
            data_bank_07df = db_ret17;
            goto shared_07DF;
        }
        a_hi_07a42 = a_all19 >> 8;
        carry_07a42 = carry_ret19;
        overflow_07a42 = overflow_ret16;
        direct_page_07a42 = dp_ret8;
        data_bank_07a42 = db_ret17;
        goto shared_07A4_1;
    } else {
        uint16_t value124 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA156, (uint16_t)(value124 + 1));
        uint16_t value125 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA157, (uint16_t)(value125 + 1));
        uint16_t value126 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA164, (uint16_t)(value126 - 1));
        if ((uint16_t)(value126 - 1) != 0) {
            a_07854 = (uint8_t)a_all19;
            a_hi_07854 = a_all19 >> 8;
            x_07854 = x_ret21;
            y_07854 = y_ret17;
            carry_07854 = carry_ret19;
            overflow_07854 = overflow_ret16;
            direct_page_07854 = dp_ret8;
            data_bank_07854 = db_ret17;
            goto shared_0785_3;
        }
        uint16_t value127 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA165);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA165, (uint16_t)(value127 + 1));
        uint16_t value128 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA167);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA167, (uint16_t)(value128 - 1));
        uint16_t value129 = BUS16_RDP(c, (db_ret17 << 0x10) + 0xA163);
        BUS16_RMW_SET(c, (db_ret17 << 0x10) + 0xA163, (uint16_t)(value129 - 1));
        if ((uint16_t)(value129 - 1) != 0) {
            a_07df2 = (uint8_t)a_all19;
            a_hi_07df2 = a_all19 >> 8;
            x_07df2 = x_ret21;
            y_07df2 = y_ret17;
            carry_07df2 = carry_ret19;
            zero_07df2 = (uint16_t)(value129 - 1) == 0;
            negative_07df2 = (uint16_t)(value129 - 1) & 0x8000;
            overflow_07df2 = overflow_ret16;
            direct_page_07df2 = dp_ret8;
            data_bank_07df2 = db_ret17;
            goto shared_07DF_1;
        }
        a_hi_07a44 = a_all19 >> 8;
        carry_07a44 = carry_ret19;
        overflow_07a44 = overflow_ret16;
        direct_page_07a44 = dp_ret8;
        data_bank_07a44 = db_ret17;
        goto shared_07A4_3;
    }
    shared_07DF:;
    r->a = (a_hi_07df << 8) | a_07df;
    r->x = x_07df;
    r->y = y_07df;
    r->c = carry_07df;
    r->z = zero_07df;
    r->n = negative_07df;
    r->v = overflow_07df;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_07df;
    r->dp = direct_page_07df;
    RETURN_RTS(c);
    shared_07DF_1:;
    r->a = (a_hi_07df2 << 8) | a_07df2;
    r->x = x_07df2;
    r->y = y_07df2;
    r->c = carry_07df2;
    r->z = zero_07df2;
    r->n = negative_07df2;
    r->v = overflow_07df2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_07df2;
    r->dp = direct_page_07df2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC006EA, SOM_RTS, "gen", collapse_dialogue_window_rows_and_publish_blank_tile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 246, 94)
