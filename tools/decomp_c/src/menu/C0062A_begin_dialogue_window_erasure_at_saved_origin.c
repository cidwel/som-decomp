#include "som_c.h"

/* C0062A begin_dialogue_window_erasure_at_saved_origin   [class C, 126 bytes, 49 instructions]
 * Source: src/rom/begin_dialogue_window_erasure_at_saved_origin.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void begin_dialogue_window_erasure_at_saved_origin(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_0644 = 0;
    uint16_t y_0644 = 0;
    bool overflow_0644 = 0;
    uint8_t a_hi_064b = 0;
    uint16_t y_064b = 0;
    bool overflow_064b = 0;
    uint16_t direct_page_064b = 0;
    uint8_t data_bank_064b = 0;
    uint8_t a_0652 = 0;
    uint8_t a_hi_0652 = 0;
    uint16_t y_0652 = 0;
    bool overflow_0652 = 0;
    uint16_t direct_page_0652 = 0;
    uint8_t data_bank_0652 = 0;
    uint8_t a_hi_0655 = 0;
    uint16_t y_0655 = 0;
    bool overflow_0655 = 0;
    uint16_t direct_page_0655 = 0;
    uint8_t data_bank_0655 = 0;
    uint8_t a_hi_0660 = 0;
    uint16_t x_0660 = 0;
    uint16_t y_0660 = 0;
    bool overflow_0660 = 0;
    uint16_t direct_page_0660 = 0;
    uint8_t data_bank_0660 = 0;
    uint8_t a_hi_0673 = 0;
    uint16_t y_0673 = 0;
    bool carry_0673 = 0;
    bool overflow_0673 = 0;
    uint16_t direct_page_0673 = 0;
    uint8_t data_bank_0673 = 0;
    uint8_t a_hi_0681 = 0;
    uint16_t x_0681 = 0;
    uint16_t y_0681 = 0;
    bool carry_0681 = 0;
    bool overflow_0681 = 0;
    uint16_t direct_page_0681 = 0;
    uint8_t data_bank_0681 = 0;
    uint8_t a_hi_067e = 0;
    uint16_t x_067e = 0;
    uint16_t y_067e = 0;
    bool carry_067e = 0;
    bool overflow_067e = 0;
    uint16_t direct_page_067e = 0;
    uint8_t data_bank_067e = 0;
    uint8_t a_hi_06812 = 0;
    uint8_t x_06812 = 0;
    uint8_t y_06812 = 0;
    bool carry_06812 = 0;
    bool overflow_06812 = 0;
    uint16_t direct_page_06812 = 0;
    uint8_t data_bank_06812 = 0;
    uint8_t a_hi_06813 = 0;
    uint8_t x_06813 = 0;
    uint8_t y_06813 = 0;
    bool carry_06813 = 0;
    bool overflow_06813 = 0;
    uint16_t direct_page_06813 = 0;
    uint8_t data_bank_06813 = 0;
    uint8_t a_hi_06814 = 0;
    uint16_t x_06814 = 0;
    uint16_t y_06814 = 0;
    bool carry_06814 = 0;
    bool overflow_06814 = 0;
    uint16_t direct_page_06814 = 0;
    uint8_t data_bank_06814 = 0;
    uint8_t a_hi_06552 = 0;
    uint8_t y_06552 = 0;
    bool overflow_06552 = 0;
    uint16_t direct_page_06552 = 0;
    uint8_t data_bank_06552 = 0;
    uint8_t a_hi_064b2 = 0;
    uint8_t y_064b2 = 0;
    bool overflow_064b2 = 0;
    uint16_t direct_page_064b2 = 0;
    uint8_t data_bank_064b2 = 0;
    uint8_t a_hi_06553 = 0;
    uint8_t y_06553 = 0;
    bool overflow_06553 = 0;
    uint16_t direct_page_06553 = 0;
    uint8_t data_bank_06553 = 0;
    uint8_t a_hi_064b3 = 0;
    uint8_t y_064b3 = 0;
    bool overflow_064b3 = 0;
    uint16_t direct_page_064b3 = 0;
    uint8_t data_bank_064b3 = 0;
    uint8_t a_hi_06554 = 0;
    uint16_t y_06554 = 0;
    bool overflow_06554 = 0;
    uint16_t direct_page_06554 = 0;
    uint8_t data_bank_06554 = 0;
    uint8_t a_hi_064b4 = 0;
    uint16_t y_064b4 = 0;
    bool overflow_064b4 = 0;
    uint16_t direct_page_064b4 = 0;
    uint8_t data_bank_064b4 = 0;
    uint8_t a_06522 = 0;
    uint8_t a_hi_06522 = 0;
    uint8_t y_06522 = 0;
    bool overflow_06522 = 0;
    uint16_t direct_page_06522 = 0;
    uint8_t data_bank_06522 = 0;
    uint8_t a_06523 = 0;
    uint8_t a_hi_06523 = 0;
    uint8_t y_06523 = 0;
    bool overflow_06523 = 0;
    uint16_t direct_page_06523 = 0;
    uint8_t data_bank_06523 = 0;
    uint8_t a_hi_06602 = 0;
    uint16_t x_06602 = 0;
    uint16_t y_06602 = 0;
    bool overflow_06602 = 0;
    uint16_t direct_page_06602 = 0;
    uint8_t data_bank_06602 = 0;
    uint8_t a_06524 = 0;
    uint8_t a_hi_06524 = 0;
    uint16_t y_06524 = 0;
    bool overflow_06524 = 0;
    uint16_t direct_page_06524 = 0;
    uint8_t data_bank_06524 = 0;
    RAM8(0xA157) = RAM8(0xA197);
    RAM8(0xA156) = RAM8(0xA196);
    a_hi_0644 = a_hi;
    y_0644 = y;
    overflow_0644 = overflow;
    RAM8(0xA163) = RAM8(0xA16B) >> 1;
    a_hi_064b = a_hi_0644;
    y_064b = y_0644;
    overflow_064b = overflow_0644;
    direct_page_064b = 0;
    data_bank_064b = 0x7E;
    goto shared_064B;
    shared_064B:;
    uint8_t value4 = BUS8_RDP(c, (data_bank_064b << 0x10) + 0xA16C);
    if (!(value4 & 0x01)) {
        a_0652 = value4 >> 1;
        a_hi_0652 = a_hi_064b;
        y_0652 = y_064b;
        overflow_0652 = overflow_064b;
        direct_page_0652 = direct_page_064b;
        data_bank_0652 = data_bank_064b;
        goto shared_0652;
    }
    a_0652 = (value4 >> 1) + 1;
    a_hi_0652 = a_hi_064b;
    y_0652 = y_064b;
    overflow_0652 = overflow_064b;
    direct_page_0652 = direct_page_064b;
    data_bank_0652 = data_bank_064b;
    goto shared_0652;
    shared_0652:;
    BUS8_SET(c, (data_bank_0652 << 0x10) + 0xA164, a_0652);
    a_hi_0655 = a_hi_0652;
    y_0655 = y_0652;
    overflow_0655 = overflow_0652;
    direct_page_0655 = direct_page_0652;
    data_bank_0655 = data_bank_0652;
    goto shared_0655;
    shared_0655:;
    uint8_t value5 = BUS8_RDP(c, (data_bank_0655 << 0x10) + 0xCFF8);
    if (value5 == 0) {
        a_hi_0660 = a_hi_0655;
        x_0660 = 0x0118;
        y_0660 = y_0655;
        overflow_0660 = overflow_0655;
        direct_page_0660 = direct_page_0655;
        data_bank_0660 = data_bank_0655;
        goto shared_0660;
    }
    a_hi_0660 = a_hi_0655;
    x_0660 = 0;
    y_0660 = y_0655;
    overflow_0660 = overflow_0655;
    direct_page_0660 = direct_page_0655;
    data_bank_0660 = data_bank_0655;
    goto shared_0660;
    shared_0660:;
    r->a = (a_hi_0660 << 8) | a;
    r->x = x_0660;
    r->y = y_0660;
    r->v = overflow_0660;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_0660;
    r->dp = direct_page_0660;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0662, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0662); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)(value6 + 1));
    uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xA164);
    if (value7 != 1) {
        a_hi_0673 = a_all >> 8;
        y_0673 = y_ret;
        carry_0673 = value7 >= 1;
        overflow_0673 = overflow_ret;
        direct_page_0673 = dp_ret;
        data_bank_0673 = db_ret;
        goto shared_0673;
    }
    uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16C);
    if (value8 & 0x01) {
        a_hi_0681 = a_all >> 8;
        x_0681 = x_ret;
        y_0681 = y_ret;
        carry_0681 = value8 & 0x01;
        overflow_0681 = overflow_ret;
        direct_page_0681 = dp_ret;
        data_bank_0681 = db_ret;
        goto shared_0681;
    }
    a_hi_0673 = a_all >> 8;
    y_0673 = y_ret;
    carry_0673 = value8 & 0x01;
    overflow_0673 = overflow_ret;
    direct_page_0673 = dp_ret;
    data_bank_0673 = db_ret;
    goto shared_0673;
    shared_0673:;
    uint8_t value9 = BUS8_RDP(c, (data_bank_0673 << 0x10) + 0xCFF8);
    if (value9 == 0) {
        a_hi_067e = a_hi_0673;
        x_067e = 0x0118;
        y_067e = y_0673;
        carry_067e = carry_0673;
        overflow_067e = overflow_0673;
        direct_page_067e = direct_page_0673;
        data_bank_067e = data_bank_0673;
        goto shared_067E;
    }
    a_hi_067e = a_hi_0673;
    x_067e = 0;
    y_067e = y_0673;
    carry_067e = carry_0673;
    overflow_067e = overflow_0673;
    direct_page_067e = direct_page_0673;
    data_bank_067e = data_bank_0673;
    goto shared_067E;
    shared_0681:;
    uint8_t value10 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA157);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA157, (uint8_t)(value10 + 1));
    uint8_t value11 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA164);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA164, (uint8_t)(value11 - 1));
    if ((uint8_t)(value11 - 1) != 0) {
        a_hi_0655 = a_hi_0681;
        y_0655 = (uint16_t)(y_0681 + 1);
        overflow_0655 = overflow_0681;
        direct_page_0655 = direct_page_0681;
        data_bank_0655 = data_bank_0681;
        goto shared_0655;
    }
    uint8_t value12 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA197);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA157, value12);
    uint8_t value13 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA156);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA156, (uint8_t)(value13 + 1));
    uint8_t value14 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA163);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA163, (uint8_t)(value14 - 1));
    if ((uint8_t)(value14 - 1) != 0) {
        a_hi_064b = a_hi_0681;
        y_064b = (uint16_t)(y_0681 + 1);
        overflow_064b = overflow_0681;
        direct_page_064b = direct_page_0681;
        data_bank_064b = data_bank_0681;
        goto shared_064B;
    }
    uint8_t value15 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA157);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA17D, value15);
    uint8_t value16 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA156);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA17C, value16);
    uint8_t value17 = BUS8_RDP(c, (data_bank_0681 << 0x10) + 0xA15F);
    BUS8_SET(c, (data_bank_0681 << 0x10) + 0xA15F, (uint8_t)(value17 + 1));
    r->a = (a_hi_0681 << 8) | value16;
    r->x = x_0681;
    r->y = (uint16_t)(y_0681 + 1);
    r->c = carry_0681;
    r->z = (uint8_t)(value17 + 1) == 0;
    r->n = (uint8_t)(value17 + 1) & 0x80;
    r->v = overflow_0681;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_0681;
    r->dp = direct_page_0681;
    RETURN_RTS(c);
    shared_067E:;
    r->a = (a_hi_067e << 8) | a;
    r->x = x_067e;
    r->y = y_067e;
    r->c = carry_067e;
    r->v = overflow_067e;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_067e;
    r->dp = direct_page_067e;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0680, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0680); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (m_ret) {
        if (x_ret2) {
            a_hi_06812 = a_all2 >> 8;
            x_06812 = (uint8_t)x_ret3;
            y_06812 = (uint8_t)y_ret2;
            carry_06812 = carry_ret2;
            overflow_06812 = overflow_ret2;
            direct_page_06812 = dp_ret2;
            data_bank_06812 = db_ret2;
            goto shared_0681_1;
        } else {
            a_hi_0681 = a_all2 >> 8;
            x_0681 = x_ret3;
            y_0681 = y_ret2;
            carry_0681 = carry_ret2;
            overflow_0681 = overflow_ret2;
            direct_page_0681 = dp_ret2;
            data_bank_0681 = db_ret2;
            goto shared_0681;
        }
    } else {
        if (x_ret2) {
            a_hi_06813 = a_all2 >> 8;
            x_06813 = (uint8_t)x_ret3;
            y_06813 = (uint8_t)y_ret2;
            carry_06813 = carry_ret2;
            overflow_06813 = overflow_ret2;
            direct_page_06813 = dp_ret2;
            data_bank_06813 = db_ret2;
            goto shared_0681_2;
        } else {
            a_hi_06814 = a_all2 >> 8;
            x_06814 = x_ret3;
            y_06814 = y_ret2;
            carry_06814 = carry_ret2;
            overflow_06814 = overflow_ret2;
            direct_page_06814 = dp_ret2;
            data_bank_06814 = db_ret2;
            goto shared_0681_3;
        }
    }
    shared_0681_1:;
    uint8_t value18 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA157);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA157, (uint8_t)(value18 + 1));
    uint8_t value19 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA164);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA164, (uint8_t)(value19 - 1));
    if ((uint8_t)(value19 - 1) != 0) {
        a_hi_06552 = a_hi_06812;
        y_06552 = (uint8_t)(y_06812 + 1);
        overflow_06552 = overflow_06812;
        direct_page_06552 = direct_page_06812;
        data_bank_06552 = data_bank_06812;
        goto shared_0655_1;
    }
    uint8_t value20 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA197);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA157, value20);
    uint8_t value21 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA156);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA156, (uint8_t)(value21 + 1));
    uint8_t value22 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA163);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA163, (uint8_t)(value22 - 1));
    if ((uint8_t)(value22 - 1) != 0) {
        a_hi_064b2 = a_hi_06812;
        y_064b2 = (uint8_t)(y_06812 + 1);
        overflow_064b2 = overflow_06812;
        direct_page_064b2 = direct_page_06812;
        data_bank_064b2 = data_bank_06812;
        goto shared_064B_1;
    }
    uint8_t value23 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA157);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA17D, value23);
    uint8_t value24 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA156);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA17C, value24);
    uint8_t value25 = BUS8_RDP(c, (data_bank_06812 << 0x10) + 0xA15F);
    BUS8_SET(c, (data_bank_06812 << 0x10) + 0xA15F, (uint8_t)(value25 + 1));
    r->a = (a_hi_06812 << 8) | value24;
    r->x = x_06812;
    r->y = (uint8_t)(y_06812 + 1);
    r->c = carry_06812;
    r->z = (uint8_t)(value25 + 1) == 0;
    r->n = (uint8_t)(value25 + 1) & 0x80;
    r->v = overflow_06812;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_06812;
    r->dp = direct_page_06812;
    RETURN_RTS(c);
    shared_0681_2:;
    uint16_t value26 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA157);
    BUS16_RMW_SET(c, (data_bank_06813 << 0x10) + 0xA157, (uint16_t)(value26 + 1));
    uint16_t value27 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA164);
    BUS16_RMW_SET(c, (data_bank_06813 << 0x10) + 0xA164, (uint16_t)(value27 - 1));
    if ((uint16_t)(value27 - 1) != 0) {
        a_hi_06553 = a_hi_06813;
        y_06553 = (uint8_t)(y_06813 + 1);
        overflow_06553 = overflow_06813;
        direct_page_06553 = direct_page_06813;
        data_bank_06553 = data_bank_06813;
        goto shared_0655_2;
    }
    uint16_t value28 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA197);
    BUS16_SET(c, (data_bank_06813 << 0x10) + 0xA157, value28);
    uint16_t value29 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA156);
    BUS16_RMW_SET(c, (data_bank_06813 << 0x10) + 0xA156, (uint16_t)(value29 + 1));
    uint16_t value30 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA163);
    BUS16_RMW_SET(c, (data_bank_06813 << 0x10) + 0xA163, (uint16_t)(value30 - 1));
    if ((uint16_t)(value30 - 1) != 0) {
        a_hi_064b3 = value28 >> 8;
        y_064b3 = (uint8_t)(y_06813 + 1);
        overflow_064b3 = overflow_06813;
        direct_page_064b3 = direct_page_06813;
        data_bank_064b3 = data_bank_06813;
        goto shared_064B_2;
    }
    uint16_t value31 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA157);
    BUS16_SET(c, (data_bank_06813 << 0x10) + 0xA17D, value31);
    uint16_t value32 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA156);
    BUS16_SET(c, (data_bank_06813 << 0x10) + 0xA17C, value32);
    uint16_t value33 = BUS16_RDP(c, (data_bank_06813 << 0x10) + 0xA15F);
    BUS16_RMW_SET(c, (data_bank_06813 << 0x10) + 0xA15F, (uint16_t)(value33 + 1));
    r->a = value32;
    r->x = x_06813;
    r->y = (uint8_t)(y_06813 + 1);
    r->c = carry_06813;
    r->z = (uint16_t)(value33 + 1) == 0;
    r->n = (uint16_t)(value33 + 1) & 0x8000;
    r->v = overflow_06813;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_06813;
    r->dp = direct_page_06813;
    RETURN_RTS(c);
    shared_0681_3:;
    uint16_t value34 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA157);
    BUS16_RMW_SET(c, (data_bank_06814 << 0x10) + 0xA157, (uint16_t)(value34 + 1));
    uint16_t value35 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA164);
    BUS16_RMW_SET(c, (data_bank_06814 << 0x10) + 0xA164, (uint16_t)(value35 - 1));
    if ((uint16_t)(value35 - 1) != 0) {
        a_hi_06554 = a_hi_06814;
        y_06554 = (uint16_t)(y_06814 + 1);
        overflow_06554 = overflow_06814;
        direct_page_06554 = direct_page_06814;
        data_bank_06554 = data_bank_06814;
        goto shared_0655_3;
    }
    uint16_t value36 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA197);
    BUS16_SET(c, (data_bank_06814 << 0x10) + 0xA157, value36);
    uint16_t value37 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA156);
    BUS16_RMW_SET(c, (data_bank_06814 << 0x10) + 0xA156, (uint16_t)(value37 + 1));
    uint16_t value38 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA163);
    BUS16_RMW_SET(c, (data_bank_06814 << 0x10) + 0xA163, (uint16_t)(value38 - 1));
    if ((uint16_t)(value38 - 1) != 0) {
        a_hi_064b4 = value36 >> 8;
        y_064b4 = (uint16_t)(y_06814 + 1);
        overflow_064b4 = overflow_06814;
        direct_page_064b4 = direct_page_06814;
        data_bank_064b4 = data_bank_06814;
        goto shared_064B_3;
    }
    uint16_t value39 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA157);
    BUS16_SET(c, (data_bank_06814 << 0x10) + 0xA17D, value39);
    uint16_t value40 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA156);
    BUS16_SET(c, (data_bank_06814 << 0x10) + 0xA17C, value40);
    uint16_t value41 = BUS16_RDP(c, (data_bank_06814 << 0x10) + 0xA15F);
    BUS16_RMW_SET(c, (data_bank_06814 << 0x10) + 0xA15F, (uint16_t)(value41 + 1));
    r->a = value40;
    r->x = x_06814;
    r->y = (uint16_t)(y_06814 + 1);
    r->c = carry_06814;
    r->z = (uint16_t)(value41 + 1) == 0;
    r->n = (uint16_t)(value41 + 1) & 0x8000;
    r->v = overflow_06814;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_06814;
    r->dp = direct_page_06814;
    RETURN_RTS(c);
    shared_0655_1:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_064B_1:;
    uint8_t value42 = BUS8_RDP(c, (data_bank_064b2 << 0x10) + 0xA16C);
    if (!(value42 & 0x01)) {
        a_06522 = value42 >> 1;
        a_hi_06522 = a_hi_064b2;
        y_06522 = y_064b2;
        overflow_06522 = overflow_064b2;
        direct_page_06522 = direct_page_064b2;
        data_bank_06522 = data_bank_064b2;
        goto shared_0652_1;
    }
    a_06522 = (value42 >> 1) + 1;
    a_hi_06522 = a_hi_064b2;
    y_06522 = y_064b2;
    overflow_06522 = overflow_064b2;
    direct_page_06522 = direct_page_064b2;
    data_bank_06522 = data_bank_064b2;
    goto shared_0652_1;
    shared_0655_2:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_064B_2:;
    uint16_t value43 = BUS16_RDP(c, (data_bank_064b3 << 0x10) + 0xA16C);
    if (!(value43 & 0x01)) {
        a_06523 = (uint8_t)(value43 >> 1);
        a_hi_06523 = value43 >> 1 >> 8;
        y_06523 = y_064b3;
        overflow_06523 = overflow_064b3;
        direct_page_06523 = direct_page_064b3;
        data_bank_06523 = data_bank_064b3;
        goto shared_0652_2;
    }
    a_06523 = (uint8_t)((value43 >> 1) + 1);
    a_hi_06523 = (value43 >> 1) + 1 >> 8;
    y_06523 = y_064b3;
    overflow_06523 = overflow_064b3;
    direct_page_06523 = direct_page_064b3;
    data_bank_06523 = data_bank_064b3;
    goto shared_0652_2;
    shared_0655_3:;
    uint16_t value44 = BUS16_RDP(c, (data_bank_06554 << 0x10) + 0xCFF8);
    if (value44 == 0) {
        a_hi_06602 = value44 >> 8;
        x_06602 = 0x0118;
        y_06602 = y_06554;
        overflow_06602 = overflow_06554;
        direct_page_06602 = direct_page_06554;
        data_bank_06602 = data_bank_06554;
        goto shared_0660_1;
    }
    a_hi_06602 = value44 >> 8;
    x_06602 = 0;
    y_06602 = y_06554;
    overflow_06602 = overflow_06554;
    direct_page_06602 = direct_page_06554;
    data_bank_06602 = data_bank_06554;
    goto shared_0660_1;
    shared_064B_3:;
    uint16_t value45 = BUS16_RDP(c, (data_bank_064b4 << 0x10) + 0xA16C);
    if (!(value45 & 0x01)) {
        a_06524 = (uint8_t)(value45 >> 1);
        a_hi_06524 = value45 >> 1 >> 8;
        y_06524 = y_064b4;
        overflow_06524 = overflow_064b4;
        direct_page_06524 = direct_page_064b4;
        data_bank_06524 = data_bank_064b4;
        goto shared_0652_3;
    }
    a_06524 = (uint8_t)((value45 >> 1) + 1);
    a_hi_06524 = (value45 >> 1) + 1 >> 8;
    y_06524 = y_064b4;
    overflow_06524 = overflow_064b4;
    direct_page_06524 = direct_page_064b4;
    data_bank_06524 = data_bank_064b4;
    goto shared_0652_3;
    shared_0652_1:;
    BUS8_SET(c, (data_bank_06522 << 0x10) + 0xA164, a_06522);
    a_hi_06552 = a_hi_06522;
    y_06552 = y_06522;
    overflow_06552 = overflow_06522;
    direct_page_06552 = direct_page_06522;
    data_bank_06552 = data_bank_06522;
    goto shared_0655_1;
    shared_0652_2:;
    BUS16_SET(c, (data_bank_06523 << 0x10) + 0xA164, (a_hi_06523 << 8) | a_06523);
    a_hi_06553 = a_hi_06523;
    y_06553 = y_06523;
    overflow_06553 = overflow_06523;
    direct_page_06553 = direct_page_06523;
    data_bank_06553 = data_bank_06523;
    goto shared_0655_2;
    shared_0660_1:;
    r->a = (a_hi_06602 << 8) | a;
    r->x = x_06602;
    r->y = y_06602;
    r->v = overflow_06602;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_06602;
    r->dp = direct_page_06602;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0662, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0662); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret3 = r->v;
    uint8_t value46 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, (uint8_t)(value46 + 1));
    uint8_t value47 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA164);
    if (value47 != 1) {
        a_hi_0673 = a_all3 >> 8;
        y_0673 = y_ret3;
        carry_0673 = value47 >= 1;
        overflow_0673 = overflow_ret3;
        direct_page_0673 = dp_ret3;
        data_bank_0673 = db_ret3;
        goto shared_0673;
    }
    uint8_t value48 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA16C);
    if (value48 & 0x01) {
        a_hi_0681 = a_all3 >> 8;
        x_0681 = x_ret4;
        y_0681 = y_ret3;
        carry_0681 = value48 & 0x01;
        overflow_0681 = overflow_ret3;
        direct_page_0681 = dp_ret3;
        data_bank_0681 = db_ret3;
        goto shared_0681;
    }
    a_hi_0673 = a_all3 >> 8;
    y_0673 = y_ret3;
    carry_0673 = value48 & 0x01;
    overflow_0673 = overflow_ret3;
    direct_page_0673 = dp_ret3;
    data_bank_0673 = db_ret3;
    goto shared_0673;
    shared_0652_3:;
    BUS16_SET(c, (data_bank_06524 << 0x10) + 0xA164, (a_hi_06524 << 8) | a_06524);
    a_hi_06554 = a_hi_06524;
    y_06554 = y_06524;
    overflow_06554 = overflow_06524;
    direct_page_06554 = direct_page_06524;
    data_bank_06554 = data_bank_06524;
    goto shared_0655_3;
}
SOM_REGISTER(0xC0062A, SOM_RTS, "gen", begin_dialogue_window_erasure_at_saved_origin, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 126, 49)
