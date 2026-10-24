#include "som_c.h"

/* D3F79F expand_and_render_spell_frame_group   [class B, 146 bytes, 76 instructions]
 * Source: src/rom/expand_and_render_spell_frame_group.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void expand_and_render_spell_frame_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_f7f7 = 0;
    uint16_t x_f7f7 = 0;
    uint16_t y_f7f7 = 0;
    bool carry_f7f7 = 0;
    bool zero_f7f7 = 0;
    bool negative_f7f7 = 0;
    bool overflow_f7f7 = 0;
    uint16_t direct_page_f7f7 = 0;
    uint8_t data_bank_f7f7 = 0;
    uint8_t a_hi_f7cc = 0;
    uint16_t x_f7cc = 0;
    uint16_t y_f7cc = 0;
    uint16_t direct_page_f7cc = 0;
    uint8_t x_f827 = 0;
    uint8_t y_f827 = 0;
    uint16_t direct_page_f827 = 0;
    uint8_t data_bank_f827 = 0;
    uint8_t a_hi_f80a = 0;
    uint8_t x_f80a = 0;
    uint16_t direct_page_f80a = 0;
    uint8_t data_bank_f80a = 0;
    uint16_t x_f8272 = 0;
    uint16_t y_f8272 = 0;
    uint16_t direct_page_f8272 = 0;
    uint8_t data_bank_f8272 = 0;
    uint8_t a_hi_f80a2 = 0;
    uint16_t x_f80a2 = 0;
    uint16_t direct_page_f80a2 = 0;
    uint8_t data_bank_f80a2 = 0;
    uint8_t a_f7da = 0;
    uint8_t a_hi_f7da = 0;
    uint16_t y_f7da = 0;
    uint16_t direct_page_f7da = 0;
    uint8_t a_hi_f7f72 = 0;
    uint8_t x_f7f72 = 0;
    uint8_t y_f7f72 = 0;
    bool carry_f7f72 = 0;
    bool zero_f7f72 = 0;
    bool negative_f7f72 = 0;
    bool overflow_f7f72 = 0;
    uint16_t direct_page_f7f72 = 0;
    uint8_t data_bank_f7f72 = 0;
    uint8_t a_hi_f7f73 = 0;
    uint8_t x_f7f73 = 0;
    uint8_t y_f7f73 = 0;
    bool carry_f7f73 = 0;
    bool zero_f7f73 = 0;
    bool negative_f7f73 = 0;
    bool overflow_f7f73 = 0;
    uint16_t direct_page_f7f73 = 0;
    uint8_t data_bank_f7f73 = 0;
    uint8_t a_hi_f7f74 = 0;
    uint16_t x_f7f74 = 0;
    uint16_t y_f7f74 = 0;
    bool carry_f7f74 = 0;
    bool zero_f7f74 = 0;
    bool negative_f7f74 = 0;
    bool overflow_f7f74 = 0;
    uint16_t direct_page_f7f74 = 0;
    uint8_t data_bank_f7f74 = 0;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0B), x);
    RAM16_SET(0x010C + x, (uint16_t)(RAM16(0x010C + x) - 1));
    if (RAM16(0x010C + x) != 0) {
        a_hi_f7f7 = (uint16_t)(sp0 - 0x0B) >> 8;
        x_f7f7 = x;
        y_f7f7 = y;
        carry_f7f7 = (uint16_t)(sp0 - 3) >= 8;
        zero_f7f7 = RAM16(0x010C + x) == 0;
        negative_f7f7 = RAM16(0x010C + x) & 0x8000;
        overflow_f7f7 = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
        direct_page_f7f7 = (uint16_t)(sp0 - 0x0B);
        data_bank_f7f7 = 0x7E;
        goto shared_F7F7;
    }
    RAM16_SET(0x010C + x, RAM16(0x010E + x));
    uint16_t value2 = RAM16(0x0108 + x);
    if (value2 >= 0x18) {
        a_hi_f7cc = value2 >> 8;
        x_f7cc = x;
        y_f7cc = y;
        direct_page_f7cc = (uint16_t)(sp0 - 0x0B);
        goto shared_F7CC;
    }
    RAM16_SET(0x0108 + x, (uint16_t)(value2 + 1));
    a_hi_f7cc = (uint16_t)(value2 + 1) >> 8;
    x_f7cc = x;
    y_f7cc = y;
    direct_page_f7cc = (uint16_t)(sp0 - 0x0B);
    shared_F7CC:;
    uint16_t value7 = RAM16(0x010A + x_f7cc);
    if (value7 < RAM16(0x0108 + x_f7cc)) {
        a_f7da = (uint8_t)value7;
        a_hi_f7da = value7 >> 8;
        y_f7da = y_f7cc;
        direct_page_f7da = direct_page_f7cc;
        goto shared_F7DA;
    }
    RAM16_SET(0x010A + x_f7cc, 0);
    a_f7da = 0;
    a_hi_f7da = 0;
    y_f7da = y_f7cc;
    direct_page_f7da = direct_page_f7cc;
    goto shared_F7DA;
    shared_F7F7:;
    r->x = x_f7f7;
    r->y = y_f7f7;
    r->c = carry_f7f7;
    r->z = zero_f7f7;
    r->n = negative_f7f7;
    r->v = overflow_f7f7;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_f7f7;
    r->dp = direct_page_f7f7;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF7F9, 0xD3F6C9); GUARD_JSR(c, sp_call, 0xF7F9); } /* refresh_spell_frame_random_velocity_groups */
    r->sp += 12;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page_f7f7 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f7 + 7), value3 + 0xF0);
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x0108 + value3);
        if (value4 == 0) {
            x_f827 = value3;
            y_f827 = (uint8_t)y_ret;
            direct_page_f827 = direct_page_f7f7;
            data_bank_f827 = db_ret;
            goto shared_F827;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f7 + 1), value4);
        a_hi_f80a = value4 >> 8;
        x_f80a = value3;
        direct_page_f80a = direct_page_f7f7;
        data_bank_f80a = db_ret;
        goto shared_F80A;
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page_f7f7 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f7 + 7), (uint16_t)(value5 + 0xF0));
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x0108 + value5);
        if (value6 == 0) {
            x_f8272 = value5;
            y_f8272 = y_ret;
            direct_page_f8272 = direct_page_f7f7;
            data_bank_f8272 = db_ret;
            goto shared_F827_1;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f7 + 1), value6);
        a_hi_f80a2 = value6 >> 8;
        x_f80a2 = value5;
        direct_page_f80a2 = direct_page_f7f7;
        data_bank_f80a2 = db_ret;
        goto shared_F80A_1;
    }
    shared_F827:;
    uint8_t value9 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
    r->x = x_f827;
    r->y = y_f827;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value9;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_F80A:;
    BUS8_SET(c, (uint16_t)(direct_page_f80a + 5), x_f80a);
    uint16_t value13 = BUS16_RDP(c, (data_bank_f80a << 0x10) + 8 + x_f80a);
    uint16_t value14 = BUS16_RDP(c, (data_bank_f80a << 0x10) + 8 + x_f80a);
    uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_f80a + 7));
    r->a = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15);
    r->x = x_f80a;
    r->y = (uint8_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15);
    r->c = (uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15 > 0xFFFF;
    r->z = (uint8_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15) == 0;
    r->n = (uint8_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15) & 0x80;
    r->v = (((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15)) & (value15 ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value13 << 1) + value14) << 1) + value15)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_f80a;
    r->dp = direct_page_f80a;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF81B, 0xD3F683); GUARD_JSR(c, sp_call, 0xF81B); } /* advance_and_publish_spell_frame_sprite */
    r->sp += 12;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t y_ret2 = r->y;
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
    if (x_ret3) {
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value17 - 1));
        if ((uint16_t)(value17 - 1) != 0) {
            a_hi_f80a = (uint16_t)(value16 + 0x0A) >> 8;
            x_f80a = (uint8_t)(value16 + 0x0A);
            direct_page_f80a = dp_ret;
            data_bank_f80a = db_ret2;
            goto shared_F80A;
        }
        x_f827 = (uint8_t)(value16 + 0x0A);
        y_f827 = (uint8_t)y_ret2;
        direct_page_f827 = dp_ret;
        data_bank_f827 = db_ret2;
        goto shared_F827;
    } else {
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value18 - 1));
        if ((uint16_t)(value18 - 1) != 0) {
            a_hi_f80a2 = (uint16_t)(value16 + 0x0A) >> 8;
            x_f80a2 = (uint16_t)(value16 + 0x0A);
            direct_page_f80a2 = dp_ret;
            data_bank_f80a2 = db_ret2;
            goto shared_F80A_1;
        }
        x_f8272 = (uint16_t)(value16 + 0x0A);
        y_f8272 = y_ret2;
        direct_page_f8272 = dp_ret;
        data_bank_f8272 = db_ret2;
        goto shared_F827_1;
    }
    shared_F827_1:;
    uint8_t value19 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value20 = RAM8(0x0000 + sp0 - 2);
    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
    uint8_t value22 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
    r->x = x_f8272;
    r->y = y_f8272;
    r->mf = value20 & 0x20;
    r->xf = value20 & 0x10;
    r->db = value19;
    r->dp = (value22 << 8) | value21;
    r->i = value20 & 0x04;
    r->d = value20 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_F80A_1:;
    BUS16_SET(c, (uint16_t)(direct_page_f80a2 + 5), x_f80a2);
    uint16_t value23 = BUS16_RDP(c, (data_bank_f80a2 << 0x10) + 8 + x_f80a2);
    uint16_t value24 = BUS16_RDP(c, (data_bank_f80a2 << 0x10) + 8 + x_f80a2);
    uint16_t value25 = BUS16_RDP(c, (uint16_t)(direct_page_f80a2 + 7));
    r->a = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25);
    r->x = x_f80a2;
    r->y = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25);
    r->c = (uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25 > 0xFFFF;
    r->z = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25) == 0;
    r->n = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25) & 0x8000;
    r->v = (((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25)) & (value25 ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value23 << 1) + value24) << 1) + value25)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_f80a2;
    r->dp = direct_page_f80a2;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF81B, 0xD3F683); GUARD_JSR(c, sp_call, 0xF81B); } /* advance_and_publish_spell_frame_sprite */
    r->sp += 12;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret5 = r->xf;
    uint16_t y_ret3 = r->y;
    uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
    if (x_ret5) {
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value27 - 1));
        if ((uint16_t)(value27 - 1) != 0) {
            a_hi_f80a = (uint16_t)(value26 + 0x0A) >> 8;
            x_f80a = (uint8_t)(value26 + 0x0A);
            direct_page_f80a = dp_ret2;
            data_bank_f80a = db_ret3;
            goto shared_F80A;
        }
        x_f827 = (uint8_t)(value26 + 0x0A);
        y_f827 = (uint8_t)y_ret3;
        direct_page_f827 = dp_ret2;
        data_bank_f827 = db_ret3;
        goto shared_F827;
    } else {
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value28 - 1));
        if ((uint16_t)(value28 - 1) != 0) {
            a_hi_f80a2 = (uint16_t)(value26 + 0x0A) >> 8;
            x_f80a2 = (uint16_t)(value26 + 0x0A);
            direct_page_f80a2 = dp_ret2;
            data_bank_f80a2 = db_ret3;
            goto shared_F80A_1;
        }
        x_f8272 = (uint16_t)(value26 + 0x0A);
        y_f8272 = y_ret3;
        direct_page_f8272 = dp_ret2;
        data_bank_f8272 = db_ret3;
        goto shared_F827_1;
    }
    shared_F7DA:;
    BUS16_SET(c, 0x004202, (a_f7da << 8) | 0x0A);
    RAM8(0x0000 + sp0 - 0x0C) = a_f7da;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)((a_f7da << 8) | 0x0A);
    uint16_t value29 = BUS16(c, 0x004216);
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_f7da + 3));
    r->a = (uint16_t)(value29 + value30);
    r->x = (uint16_t)(value29 + value30);
    r->y = y_f7da;
    r->c = value29 + value30 > 0xFFFF;
    r->z = (uint16_t)(value29 + value30) == 0;
    r->n = (uint16_t)(value29 + value30) & 0x8000;
    r->v = ((value29 ^ (uint16_t)(value29 + value30)) & (value30 ^ (uint16_t)(value29 + value30)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_f7da;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF7F1, 0xD3F747); GUARD_JSR(c, sp_call, 0xF7F1); } /* reset_spell_frame_sprite_record */
    r->sp += 12;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret = r->mf;
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (x_ret7) {
        uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 3));
        if (m_ret) {
            uint8_t value32 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x010A + value31);
            BUS8_SET(c, (db_ret4 << 0x10) + 0x010A + value31, (uint8_t)(value32 + 1));
            a_hi_f7f72 = a_all4 >> 8;
            x_f7f72 = value31;
            y_f7f72 = (uint8_t)y_ret4;
            carry_f7f72 = carry_ret4;
            zero_f7f72 = (uint8_t)(value32 + 1) == 0;
            negative_f7f72 = (uint8_t)(value32 + 1) & 0x80;
            overflow_f7f72 = overflow_ret4;
            direct_page_f7f72 = dp_ret3;
            data_bank_f7f72 = db_ret4;
            goto shared_F7F7_1;
        } else {
            uint16_t value33 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x010A + value31);
            BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0x010A + value31, (uint16_t)(value33 + 1));
            a_hi_f7f73 = a_all4 >> 8;
            x_f7f73 = value31;
            y_f7f73 = (uint8_t)y_ret4;
            carry_f7f73 = carry_ret4;
            zero_f7f73 = (uint16_t)(value33 + 1) == 0;
            negative_f7f73 = (uint16_t)(value33 + 1) & 0x8000;
            overflow_f7f73 = overflow_ret4;
            direct_page_f7f73 = dp_ret3;
            data_bank_f7f73 = db_ret4;
            goto shared_F7F7_2;
        }
    } else {
        uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        if (m_ret) {
            uint8_t value35 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x010A + value34);
            BUS8_SET(c, (db_ret4 << 0x10) + 0x010A + value34, (uint8_t)(value35 + 1));
            a_hi_f7f74 = a_all4 >> 8;
            x_f7f74 = value34;
            y_f7f74 = y_ret4;
            carry_f7f74 = carry_ret4;
            zero_f7f74 = (uint8_t)(value35 + 1) == 0;
            negative_f7f74 = (uint8_t)(value35 + 1) & 0x80;
            overflow_f7f74 = overflow_ret4;
            direct_page_f7f74 = dp_ret3;
            data_bank_f7f74 = db_ret4;
            goto shared_F7F7_3;
        } else {
            uint16_t value36 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x010A + value34);
            BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0x010A + value34, (uint16_t)(value36 + 1));
            a_hi_f7f7 = a_all4 >> 8;
            x_f7f7 = value34;
            y_f7f7 = y_ret4;
            carry_f7f7 = carry_ret4;
            zero_f7f7 = (uint16_t)(value36 + 1) == 0;
            negative_f7f7 = (uint16_t)(value36 + 1) & 0x8000;
            overflow_f7f7 = overflow_ret4;
            direct_page_f7f7 = dp_ret3;
            data_bank_f7f7 = db_ret4;
            goto shared_F7F7;
        }
    }
    shared_F7F7_1:;
    r->x = x_f7f72;
    r->y = y_f7f72;
    r->c = carry_f7f72;
    r->z = zero_f7f72;
    r->n = negative_f7f72;
    r->v = overflow_f7f72;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_f7f72;
    r->dp = direct_page_f7f72;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF7F9, 0xD3F6C9); GUARD_JSR(c, sp_call, 0xF7F9); } /* refresh_spell_frame_random_velocity_groups */
    r->sp += 12;
    uint8_t db_ret5 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret9 = r->xf;
    uint16_t y_ret5 = r->y;
    if (x_ret9) {
        uint8_t value37 = BUS8_RDP(c, (uint16_t)(direct_page_f7f72 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f72 + 7), value37 + 0xF0);
        uint16_t value38 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0108 + value37);
        if (value38 == 0) {
            x_f827 = value37;
            y_f827 = (uint8_t)y_ret5;
            direct_page_f827 = direct_page_f7f72;
            data_bank_f827 = db_ret5;
            goto shared_F827;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f72 + 1), value38);
        a_hi_f80a = value38 >> 8;
        x_f80a = value37;
        direct_page_f80a = direct_page_f7f72;
        data_bank_f80a = db_ret5;
        goto shared_F80A;
    } else {
        uint16_t value39 = BUS16_RDP(c, (uint16_t)(direct_page_f7f72 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f72 + 7), (uint16_t)(value39 + 0xF0));
        uint16_t value40 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0108 + value39);
        if (value40 == 0) {
            x_f8272 = value39;
            y_f8272 = y_ret5;
            direct_page_f8272 = direct_page_f7f72;
            data_bank_f8272 = db_ret5;
            goto shared_F827_1;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f72 + 1), value40);
        a_hi_f80a2 = value40 >> 8;
        x_f80a2 = value39;
        direct_page_f80a2 = direct_page_f7f72;
        data_bank_f80a2 = db_ret5;
        goto shared_F80A_1;
    }
    shared_F7F7_2:;
    r->x = x_f7f73;
    r->y = y_f7f73;
    r->c = carry_f7f73;
    r->z = zero_f7f73;
    r->n = negative_f7f73;
    r->v = overflow_f7f73;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_f7f73;
    r->dp = direct_page_f7f73;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF7F9, 0xD3F6C9); GUARD_JSR(c, sp_call, 0xF7F9); } /* refresh_spell_frame_random_velocity_groups */
    r->sp += 12;
    uint8_t db_ret6 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret11 = r->xf;
    uint16_t y_ret6 = r->y;
    if (x_ret11) {
        uint8_t value41 = BUS8_RDP(c, (uint16_t)(direct_page_f7f73 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f73 + 7), value41 + 0xF0);
        uint16_t value42 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x0108 + value41);
        if (value42 == 0) {
            x_f827 = value41;
            y_f827 = (uint8_t)y_ret6;
            direct_page_f827 = direct_page_f7f73;
            data_bank_f827 = db_ret6;
            goto shared_F827;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f73 + 1), value42);
        a_hi_f80a = value42 >> 8;
        x_f80a = value41;
        direct_page_f80a = direct_page_f7f73;
        data_bank_f80a = db_ret6;
        goto shared_F80A;
    } else {
        uint16_t value43 = BUS16_RDP(c, (uint16_t)(direct_page_f7f73 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f73 + 7), (uint16_t)(value43 + 0xF0));
        uint16_t value44 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x0108 + value43);
        if (value44 == 0) {
            x_f8272 = value43;
            y_f8272 = y_ret6;
            direct_page_f8272 = direct_page_f7f73;
            data_bank_f8272 = db_ret6;
            goto shared_F827_1;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f73 + 1), value44);
        a_hi_f80a2 = value44 >> 8;
        x_f80a2 = value43;
        direct_page_f80a2 = direct_page_f7f73;
        data_bank_f80a2 = db_ret6;
        goto shared_F80A_1;
    }
    shared_F7F7_3:;
    r->x = x_f7f74;
    r->y = y_f7f74;
    r->c = carry_f7f74;
    r->z = zero_f7f74;
    r->n = negative_f7f74;
    r->v = overflow_f7f74;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f7f74;
    r->dp = direct_page_f7f74;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF7F9, 0xD3F6C9); GUARD_JSR(c, sp_call, 0xF7F9); } /* refresh_spell_frame_random_velocity_groups */
    r->sp += 12;
    uint8_t db_ret7 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret13 = r->xf;
    uint16_t y_ret7 = r->y;
    if (x_ret13) {
        uint8_t value45 = BUS8_RDP(c, (uint16_t)(direct_page_f7f74 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f74 + 7), value45 + 0xF0);
        uint16_t value46 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0108 + value45);
        if (value46 == 0) {
            x_f827 = value45;
            y_f827 = (uint8_t)y_ret7;
            direct_page_f827 = direct_page_f7f74;
            data_bank_f827 = db_ret7;
            goto shared_F827;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f74 + 1), value46);
        a_hi_f80a = value46 >> 8;
        x_f80a = value45;
        direct_page_f80a = direct_page_f7f74;
        data_bank_f80a = db_ret7;
        goto shared_F80A;
    } else {
        uint16_t value47 = BUS16_RDP(c, (uint16_t)(direct_page_f7f74 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_f7f74 + 7), (uint16_t)(value47 + 0xF0));
        uint16_t value48 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0108 + value47);
        if (value48 == 0) {
            x_f8272 = value47;
            y_f8272 = y_ret7;
            direct_page_f8272 = direct_page_f7f74;
            data_bank_f8272 = db_ret7;
            goto shared_F827_1;
        }
        BUS16_SET(c, (uint16_t)(direct_page_f7f74 + 1), value48);
        a_hi_f80a2 = value48 >> 8;
        x_f80a2 = value47;
        direct_page_f80a2 = direct_page_f7f74;
        data_bank_f80a2 = db_ret7;
        goto shared_F80A_1;
    }
}
SOM_REGISTER(0xD3F79F, SOM_RTL, "gen", expand_and_render_spell_frame_group, 0, L_B | L_X | L_Y, 14, 1, 0, 146, 76)
