#include "som_c.h"

/* D3F747 reset_spell_frame_sprite_record   [class B, 88 bytes, 44 instructions]
 * Source: src/rom/reset_spell_frame_sprite_record.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01E4.  Callers read: YCV.
 */
static void reset_spell_frame_sprite_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01E4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 6) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_f792 = 0;
    uint8_t a_hi_f792 = 0;
    uint8_t x_f792 = 0;
    uint8_t y_f792 = 0;
    uint16_t direct_page_f792 = 0;
    uint8_t data_bank_f792 = 0;
    uint8_t a_f7922 = 0;
    uint8_t a_hi_f7922 = 0;
    uint8_t x_f7922 = 0;
    uint8_t y_f7922 = 0;
    uint16_t direct_page_f7922 = 0;
    uint8_t data_bank_f7922 = 0;
    uint8_t a_f7923 = 0;
    uint8_t a_hi_f7923 = 0;
    uint16_t x_f7923 = 0;
    uint16_t y_f7923 = 0;
    uint16_t direct_page_f7923 = 0;
    uint8_t data_bank_f7923 = 0;
    uint8_t a_f7924 = 0;
    uint8_t a_hi_f7924 = 0;
    uint16_t x_f7924 = 0;
    uint16_t y_f7924 = 0;
    uint16_t direct_page_f7924 = 0;
    uint8_t data_bank_f7924 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xE4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 6), x);
    RAM8(0x0004 + x) = 0xFF;
    RAM16_SET(0x0002 + x, 0xF000);
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 6);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF768, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF768); } /* draw_spell_entity_bounded_random_long */
    r->sp += 6;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value = RAM8(0x0001 + (uint16_t)(sp0 - 6));
        BUS16_SET(c, (db_ret << 0x10) + 6 + value, a_all);
        r->a = 4;
        r->x = value;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF774, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF774); } /* draw_spell_entity_bounded_random_long */
        r->sp += 6;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        RAM8(0x0000 + sp0 - 6) = a_all2 >> 8;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)a_all2;
        if (x_ret3) {
            uint8_t value2 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
            uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + value2);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value3, (uint16_t)((uint16_t)(a_all2 << 1) + 0x0144));
            uint8_t value4 = RAM8(0x0000 + sp0 - 7);
            uint8_t value5 = RAM8(0x0000 + sp0 - 6);
            if (((value5 << 8) | value4) < 3) {
                a_f792 = (uint8_t)((value5 << 8) | value4);
                a_hi_f792 = value5;
                x_f792 = value2;
                y_f792 = value3;
                direct_page_f792 = (uint16_t)(sp0 - 6);
                data_bank_f792 = db_ret2;
                goto shared_F792;
            }
            r->a = 3;
            r->x = value2;
            r->y = value3;
            r->c = ((value5 << 8) | value4) >= 3;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)(a_all2 << 1) ^ (uint16_t)((uint16_t)(a_all2 << 1) + 0x0144)) & ((uint16_t)((uint16_t)(a_all2 << 1) + 0x0144) ^ 0x0144) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF78F, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF78F); } /* draw_spell_entity_bounded_random_long */
            r->sp += 6;
            uint8_t db_ret3 = r->db;
            bool m_ret = r->mf;
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            if (x_ret5) {
                uint8_t value6 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret) {
                    a_f7922 = (uint8_t)a_all3;
                    a_hi_f7922 = a_all3 >> 8;
                    x_f7922 = value6;
                    y_f7922 = (uint8_t)y_ret3;
                    direct_page_f7922 = (uint16_t)(sp0 - 6);
                    data_bank_f7922 = db_ret3;
                    goto shared_F792_1;
                } else {
                    a_f792 = (uint8_t)a_all3;
                    a_hi_f792 = a_all3 >> 8;
                    x_f792 = value6;
                    y_f792 = (uint8_t)y_ret3;
                    direct_page_f792 = (uint16_t)(sp0 - 6);
                    data_bank_f792 = db_ret3;
                    goto shared_F792;
                }
            } else {
                uint16_t value7 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret) {
                    a_f7923 = (uint8_t)a_all3;
                    a_hi_f7923 = a_all3 >> 8;
                    x_f7923 = value7;
                    y_f7923 = y_ret3;
                    direct_page_f7923 = (uint16_t)(sp0 - 6);
                    data_bank_f7923 = db_ret3;
                    goto shared_F792_2;
                } else {
                    a_f7924 = (uint8_t)a_all3;
                    a_hi_f7924 = a_all3 >> 8;
                    x_f7924 = value7;
                    y_f7924 = y_ret3;
                    direct_page_f7924 = (uint16_t)(sp0 - 6);
                    data_bank_f7924 = db_ret3;
                    goto shared_F792_3;
                }
            }
        } else {
            uint16_t value8 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
            uint16_t value9 = BUS16_RDP(c, (db_ret2 << 0x10) + value8);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value9, (uint16_t)((uint16_t)(a_all2 << 1) + 0x0144));
            uint8_t value10 = RAM8(0x0000 + sp0 - 7);
            uint8_t value11 = RAM8(0x0000 + sp0 - 6);
            if (((value11 << 8) | value10) < 3) {
                a_f7924 = (uint8_t)((value11 << 8) | value10);
                a_hi_f7924 = value11;
                x_f7924 = value8;
                y_f7924 = value9;
                direct_page_f7924 = (uint16_t)(sp0 - 6);
                data_bank_f7924 = db_ret2;
                goto shared_F792_3;
            }
            r->a = 3;
            r->x = value8;
            r->y = value9;
            r->c = ((value11 << 8) | value10) >= 3;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)(a_all2 << 1) ^ (uint16_t)((uint16_t)(a_all2 << 1) + 0x0144)) & ((uint16_t)((uint16_t)(a_all2 << 1) + 0x0144) ^ 0x0144) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF78F, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF78F); } /* draw_spell_entity_bounded_random_long */
            r->sp += 6;
            uint8_t db_ret4 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t y_ret4 = r->y;
            if (x_ret7) {
                uint8_t value12 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret2) {
                    a_f7922 = (uint8_t)a_all4;
                    a_hi_f7922 = a_all4 >> 8;
                    x_f7922 = value12;
                    y_f7922 = (uint8_t)y_ret4;
                    direct_page_f7922 = (uint16_t)(sp0 - 6);
                    data_bank_f7922 = db_ret4;
                    goto shared_F792_1;
                } else {
                    a_f792 = (uint8_t)a_all4;
                    a_hi_f792 = a_all4 >> 8;
                    x_f792 = value12;
                    y_f792 = (uint8_t)y_ret4;
                    direct_page_f792 = (uint16_t)(sp0 - 6);
                    data_bank_f792 = db_ret4;
                    goto shared_F792;
                }
            } else {
                uint16_t value13 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret2) {
                    a_f7923 = (uint8_t)a_all4;
                    a_hi_f7923 = a_all4 >> 8;
                    x_f7923 = value13;
                    y_f7923 = y_ret4;
                    direct_page_f7923 = (uint16_t)(sp0 - 6);
                    data_bank_f7923 = db_ret4;
                    goto shared_F792_2;
                } else {
                    a_f7924 = (uint8_t)a_all4;
                    a_hi_f7924 = a_all4 >> 8;
                    x_f7924 = value13;
                    y_f7924 = y_ret4;
                    direct_page_f7924 = (uint16_t)(sp0 - 6);
                    data_bank_f7924 = db_ret4;
                    goto shared_F792_3;
                }
            }
        }
    } else {
        uint16_t value14 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
        BUS16_SET(c, (db_ret << 0x10) + 6 + value14, a_all);
        r->a = 4;
        r->x = value14;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF774, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF774); } /* draw_spell_entity_bounded_random_long */
        r->sp += 6;
        uint8_t db_ret5 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret9 = r->xf;
        uint16_t a_all5 = r->a;
        RAM8(0x0000 + sp0 - 6) = a_all5 >> 8;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)a_all5;
        if (x_ret9) {
            uint8_t value15 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
            uint8_t value16 = BUS8_RDP(c, (db_ret5 << 0x10) + value15);
            BUS16_SET(c, (db_ret5 << 0x10) + 6 + value16, (uint16_t)((uint16_t)(a_all5 << 1) + 0x0144));
            uint8_t value17 = RAM8(0x0000 + sp0 - 7);
            uint8_t value18 = RAM8(0x0000 + sp0 - 6);
            if (((value18 << 8) | value17) < 3) {
                a_f792 = (uint8_t)((value18 << 8) | value17);
                a_hi_f792 = value18;
                x_f792 = value15;
                y_f792 = value16;
                direct_page_f792 = (uint16_t)(sp0 - 6);
                data_bank_f792 = db_ret5;
                goto shared_F792;
            }
            r->a = 3;
            r->x = value15;
            r->y = value16;
            r->c = ((value18 << 8) | value17) >= 3;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)(a_all5 << 1) ^ (uint16_t)((uint16_t)(a_all5 << 1) + 0x0144)) & ((uint16_t)((uint16_t)(a_all5 << 1) + 0x0144) ^ 0x0144) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF78F, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF78F); } /* draw_spell_entity_bounded_random_long */
            r->sp += 6;
            uint8_t db_ret6 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret11 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t y_ret6 = r->y;
            if (x_ret11) {
                uint8_t value19 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret3) {
                    a_f7922 = (uint8_t)a_all6;
                    a_hi_f7922 = a_all6 >> 8;
                    x_f7922 = value19;
                    y_f7922 = (uint8_t)y_ret6;
                    direct_page_f7922 = (uint16_t)(sp0 - 6);
                    data_bank_f7922 = db_ret6;
                    goto shared_F792_1;
                } else {
                    a_f792 = (uint8_t)a_all6;
                    a_hi_f792 = a_all6 >> 8;
                    x_f792 = value19;
                    y_f792 = (uint8_t)y_ret6;
                    direct_page_f792 = (uint16_t)(sp0 - 6);
                    data_bank_f792 = db_ret6;
                    goto shared_F792;
                }
            } else {
                uint16_t value20 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret3) {
                    a_f7923 = (uint8_t)a_all6;
                    a_hi_f7923 = a_all6 >> 8;
                    x_f7923 = value20;
                    y_f7923 = y_ret6;
                    direct_page_f7923 = (uint16_t)(sp0 - 6);
                    data_bank_f7923 = db_ret6;
                    goto shared_F792_2;
                } else {
                    a_f7924 = (uint8_t)a_all6;
                    a_hi_f7924 = a_all6 >> 8;
                    x_f7924 = value20;
                    y_f7924 = y_ret6;
                    direct_page_f7924 = (uint16_t)(sp0 - 6);
                    data_bank_f7924 = db_ret6;
                    goto shared_F792_3;
                }
            }
        } else {
            uint16_t value21 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
            uint16_t value22 = BUS16_RDP(c, (db_ret5 << 0x10) + value21);
            BUS16_SET(c, (db_ret5 << 0x10) + 6 + value22, (uint16_t)((uint16_t)(a_all5 << 1) + 0x0144));
            uint8_t value23 = RAM8(0x0000 + sp0 - 7);
            uint8_t value24 = RAM8(0x0000 + sp0 - 6);
            if (((value24 << 8) | value23) < 3) {
                a_f7924 = (uint8_t)((value24 << 8) | value23);
                a_hi_f7924 = value24;
                x_f7924 = value21;
                y_f7924 = value22;
                direct_page_f7924 = (uint16_t)(sp0 - 6);
                data_bank_f7924 = db_ret5;
                goto shared_F792_3;
            }
            r->a = 3;
            r->x = value21;
            r->y = value22;
            r->c = ((value24 << 8) | value23) >= 3;
            r->z = 0;
            r->n = 0;
            r->v = (((uint16_t)(a_all5 << 1) ^ (uint16_t)((uint16_t)(a_all5 << 1) + 0x0144)) & ((uint16_t)((uint16_t)(a_all5 << 1) + 0x0144) ^ 0x0144) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF78F, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF78F); } /* draw_spell_entity_bounded_random_long */
            r->sp += 6;
            uint8_t db_ret7 = r->db;
            bool m_ret4 = r->mf;
            bool x_ret13 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t y_ret7 = r->y;
            if (x_ret13) {
                uint8_t value25 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret4) {
                    a_f7922 = (uint8_t)a_all7;
                    a_hi_f7922 = a_all7 >> 8;
                    x_f7922 = value25;
                    y_f7922 = (uint8_t)y_ret7;
                    direct_page_f7922 = (uint16_t)(sp0 - 6);
                    data_bank_f7922 = db_ret7;
                    goto shared_F792_1;
                } else {
                    a_f792 = (uint8_t)a_all7;
                    a_hi_f792 = a_all7 >> 8;
                    x_f792 = value25;
                    y_f792 = (uint8_t)y_ret7;
                    direct_page_f792 = (uint16_t)(sp0 - 6);
                    data_bank_f792 = db_ret7;
                    goto shared_F792;
                }
            } else {
                uint16_t value26 = RAM16(0x0001 + (uint16_t)(sp0 - 6));
                if (m_ret4) {
                    a_f7923 = (uint8_t)a_all7;
                    a_hi_f7923 = a_all7 >> 8;
                    x_f7923 = value26;
                    y_f7923 = y_ret7;
                    direct_page_f7923 = (uint16_t)(sp0 - 6);
                    data_bank_f7923 = db_ret7;
                    goto shared_F792_2;
                } else {
                    a_f7924 = (uint8_t)a_all7;
                    a_hi_f7924 = a_all7 >> 8;
                    x_f7924 = value26;
                    y_f7924 = y_ret7;
                    direct_page_f7924 = (uint16_t)(sp0 - 6);
                    data_bank_f7924 = db_ret7;
                    goto shared_F792_3;
                }
            }
        }
    }
    shared_F792:;
    BUS16_SET(c, (data_bank_f792 << 0x10) + 8 + x_f792, (a_hi_f792 << 8) | a_f792);
    RAM8(0x0000 + sp0 - 3) = a_f792;
    uint8_t value30 = RAM8(0x0000 + sp0 - 2);
    uint8_t value31 = RAM8(0x0000 + sp0 - 1);
    uint8_t value32 = RAM8(0x0000 + sp0);
    r->y = y_f792;
    r->c = value30 & 0x01;
    r->v = value30 & 0x40;
    r->mf = value30 & 0x20;
    r->xf = value30 & 0x10;
    r->db = data_bank_f792;
    r->dp = (value32 << 8) | value31;
    r->i = value30 & 0x04;
    r->d = value30 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_F792_1:;
    BUS8_SET(c, (data_bank_f7922 << 0x10) + 8 + x_f7922, a_f7922);
    RAM8(0x0000 + sp0 - 3) = a_f7922;
    uint8_t value36 = RAM8(0x0000 + sp0 - 2);
    uint8_t value37 = RAM8(0x0000 + sp0 - 1);
    uint8_t value38 = RAM8(0x0000 + sp0);
    r->y = y_f7922;
    r->c = value36 & 0x01;
    r->v = value36 & 0x40;
    r->mf = value36 & 0x20;
    r->xf = value36 & 0x10;
    r->db = data_bank_f7922;
    r->dp = (value38 << 8) | value37;
    r->i = value36 & 0x04;
    r->d = value36 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_F792_2:;
    BUS8_SET(c, (data_bank_f7923 << 0x10) + 8 + x_f7923, a_f7923);
    RAM8(0x0000 + sp0 - 3) = a_f7923;
    uint8_t value42 = RAM8(0x0000 + sp0 - 2);
    uint8_t value43 = RAM8(0x0000 + sp0 - 1);
    uint8_t value44 = RAM8(0x0000 + sp0);
    r->y = y_f7923;
    r->c = value42 & 0x01;
    r->v = value42 & 0x40;
    r->mf = value42 & 0x20;
    r->xf = value42 & 0x10;
    r->db = data_bank_f7923;
    r->dp = (value44 << 8) | value43;
    r->i = value42 & 0x04;
    r->d = value42 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_F792_3:;
    BUS16_SET(c, (data_bank_f7924 << 0x10) + 8 + x_f7924, (a_hi_f7924 << 8) | a_f7924);
    RAM8(0x0000 + sp0 - 3) = a_f7924;
    uint8_t value48 = RAM8(0x0000 + sp0 - 2);
    uint8_t value49 = RAM8(0x0000 + sp0 - 1);
    uint8_t value50 = RAM8(0x0000 + sp0);
    r->y = y_f7924;
    r->c = value48 & 0x01;
    r->v = value48 & 0x40;
    r->mf = value48 & 0x20;
    r->xf = value48 & 0x10;
    r->db = data_bank_f7924;
    r->dp = (value50 << 8) | value49;
    r->i = value48 & 0x04;
    r->d = value48 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F747, SOM_RTS, "gen", reset_spell_frame_sprite_record, 0, L_Y | L_C | L_V, 8, 0, 0, 88, 44)
