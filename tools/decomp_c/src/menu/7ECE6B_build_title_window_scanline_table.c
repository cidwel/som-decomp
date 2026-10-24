#include "som_c.h"

/* 7ECE6B build_title_window_scanline_table   [class B, 375 bytes, 185 instructions]
 * Source: src/boot/build_title_window_scanline_table.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void build_title_window_scanline_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_ce83 = 0;
    uint8_t a_hi_ce83 = 0;
    uint16_t x_ce83 = 0;
    uint16_t y_ce83 = 0;
    uint16_t direct_page_ce83 = 0;
    uint8_t a_ce92 = 0;
    uint8_t a_hi_ce92 = 0;
    uint16_t x_ce92 = 0;
    uint16_t y_ce92 = 0;
    uint16_t direct_page_ce92 = 0;
    uint8_t a_hi_cf21 = 0;
    uint16_t x_cf21 = 0;
    uint16_t y_cf21 = 0;
    bool carry_cf21 = 0;
    bool overflow_cf21 = 0;
    uint16_t direct_page_cf21 = 0;
    uint8_t data_bank_cf21 = 0;
    uint8_t a_cedd = 0;
    uint8_t a_hi_cedd = 0;
    uint16_t x_cedd = 0;
    uint16_t y_cedd = 0;
    bool carry_cedd = 0;
    bool overflow_cedd = 0;
    uint16_t direct_page_cedd = 0;
    uint8_t data_bank_cedd = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0B), x);
    uint16_t value = RAM16(0x0005 + (uint16_t)(sp0 - 0x0B));
    if ((uint16_t)(y << 1) >= value) {
        a_ce83 = (uint8_t)((uint16_t)(y << 1) - value);
        a_hi_ce83 = (uint16_t)((uint16_t)(y << 1) - value) >> 8;
        x_ce83 = x;
        y_ce83 = (uint16_t)(y << 1);
        direct_page_ce83 = (uint16_t)(sp0 - 0x0B);
        goto shared_CE83;
    }
    a_ce83 = 0;
    a_hi_ce83 = 0;
    x_ce83 = x;
    y_ce83 = (uint16_t)(y << 1);
    direct_page_ce83 = (uint16_t)(sp0 - 0x0B);
    shared_CE83:;
    BUS16_SET(c, (uint16_t)(direct_page_ce83 + 1), ((a_hi_ce83 << 8) | a_ce83) >> 1);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page_ce83 + 5));
    if ((uint16_t)(y_ce83 + value2) < 0x01C0) {
        a_ce92 = (uint8_t)(y_ce83 + value2);
        a_hi_ce92 = (uint16_t)(y_ce83 + value2) >> 8;
        x_ce92 = x_ce83;
        y_ce92 = y_ce83;
        direct_page_ce92 = direct_page_ce83;
        goto shared_CE92;
    }
    a_ce92 = 0xBF;
    a_hi_ce92 = 1;
    x_ce92 = x_ce83;
    y_ce92 = y_ce83;
    direct_page_ce92 = direct_page_ce83;
    goto shared_CE92;
    shared_CE92:;
    BUS16_SET(c, (uint16_t)(direct_page_ce92 + 3), ((a_hi_ce92 << 8) | a_ce92) >> 1);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page_ce92 + 1));
    BUS16_SET(c, (uint16_t)(direct_page_ce92 + 5), (uint16_t)((((a_hi_ce92 << 8) | a_ce92) >> 1) - value3));
    r->a = 0x2C;
    r->x = x_ce92;
    r->y = y_ce92;
    r->c = ((a_hi_ce92 << 8) | a_ce92) >> 1 >= value3;
    r->z = 0;
    r->n = 0;
    r->v = (((((a_hi_ce92 << 8) | a_ce92) >> 1) ^ value3) & ((((a_hi_ce92 << 8) | a_ce92) >> 1) ^ (uint16_t)((((a_hi_ce92 << 8) | a_ce92) >> 1) - value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = direct_page_ce92;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE9F, 0x7EC030); GUARD_JSR(c, sp_call, 0xCE9F); } /* allocate_ppu_register_entry */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    BUS16_SET(c, (uint16_t)(dp_ret + 7), x_ret);
    uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x030C);
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
    if (value5 == 0) {
        uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret);
        BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret, value6 | 0x11);
        a_hi_cf21 = a_all >> 8;
        x_cf21 = x_ret;
        y_cf21 = value4;
        carry_cf21 = carry_ret;
        overflow_cf21 = overflow_ret;
        direct_page_cf21 = dp_ret;
        data_bank_cf21 = db_ret;
        goto shared_CF21;
    }
    if (value5 < 0x80) {
        a_cedd = value5;
        a_hi_cedd = a_all >> 8;
        x_cedd = x_ret;
        y_cedd = value4;
        carry_cedd = value5 >= 0x80;
        overflow_cedd = overflow_ret;
        direct_page_cedd = dp_ret;
        data_bank_cedd = db_ret;
        goto shared_CEDD;
    }
    RAM8(0x0000 + sp0 - 0x0B) = value4 >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)value4;
    uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret);
    RAM8(0x0000 + sp0 - 0x0D) = value7 & 0xEE;
    r->a = a_all >> 8 << 8 | (value7 & 0xEE);
    r->y = value4;
    r->c = value5 >= 0x80;
    r->z = (value7 & 0xEE) == 0;
    r->n = value7 & 0xEE & 0x80;
    r->mf = 1;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCEB8, 0x7EC915); GUARD_JSR(c, sp_call, 0xCEB8); } /* allocate_copy_queue_record */
    r->sp += 14;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t x_ret3 = r->x;
    BUS8_SET(c, (db_ret2 << 0x10) + 5 + x_ret3, 0x7F);
    BUS8_SET(c, (db_ret2 << 0x10) + 6 + x_ret3, RAM8(0x0000 + sp0 - 0x0D));
    BUS8_SET(c, (db_ret2 << 0x10) + 4 + x_ret3, 2);
    uint16_t value9 = RAM16(0x0000 + sp0 - 0x0C);
    BUS16_SET(c, (db_ret2 << 0x10) + 1 + x_ret3, value9);
    r->a = value9;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCED2, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCED2); } /* append_copy_queue_record */
    r->sp += 13;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
    uint8_t value11 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value12 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
    a_cedd = (uint8_t)(value13 - 0x7F);
    a_hi_cedd = a_all3 >> 8;
    x_cedd = value10;
    y_cedd = (uint16_t)(((value12 << 8) | value11) + 2);
    carry_cedd = value13 >= 0x7F;
    overflow_cedd = ((value13 ^ 0x7F) & (value13 ^ (uint8_t)(value13 - 0x7F)) & 0x80) != 0;
    direct_page_cedd = dp_ret3;
    data_bank_cedd = db_ret3;
    goto shared_CEDD;
    shared_CF21:;
    uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page_cf21 + 5));
    if (value14 == 0) {
        RAM8(0x0000 + sp0 - 0x0B) = y_cf21 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y_cf21;
        r->a = (a_hi_cf21 << 8) | value14;
        r->x = x_cf21;
        r->y = y_cf21;
        r->c = carry_cf21;
        r->z = value14 == 0;
        r->n = value14 & 0x80;
        r->v = overflow_cf21;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_cf21;
        r->dp = direct_page_cf21;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCF81, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF81); } /* allocate_copy_queue_record */
        r->sp += 13;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
        BUS8_SET(c, (db_ret4 << 0x10) + 5 + x_ret4, 1);
        uint8_t value16 = BUS8_RDP(c, (db_ret4 << 0x10) + 2 + value15);
        BUS8_SET(c, (db_ret4 << 0x10) + 6 + x_ret4, value16);
        BUS8_SET(c, (db_ret4 << 0x10) + 7 + x_ret4, 0);
        BUS8_SET(c, (db_ret4 << 0x10) + 4 + x_ret4, 3);
        uint16_t value17 = RAM16(0x0000 + sp0 - 0x0C);
        BUS16_SET(c, (db_ret4 << 0x10) + 1 + x_ret4, value17);
        r->a = value17;
        r->y = value15;
        r->z = value17 == 0;
        r->n = value17 & 0x8000;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFA2, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCFA2); } /* append_copy_queue_record */
        r->sp += 13;
        uint16_t dp_ret5 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value18 = RAM8(0x0000 + sp0 - 0x0C);
        uint8_t value19 = RAM8(0x0000 + sp0 - 0x0B);
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 7));
        r->x = value20;
        r->y = (value19 << 8) | value18;
        r->z = value20 == 0;
        r->n = value20 & 0x8000;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFA8, 0x7EC097); GUARD_JSR(c, sp_call, 0xCFA8); } /* append_oneshot_ppu_entry */
        r->sp += 11;
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value21 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x030E);
        if (value21 != 0) {
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 1));
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 3));
            uint8_t value24 = RAM8(0x0000 + sp0 - 2);
            uint8_t value25 = RAM8(0x0000 + sp0 - 1);
            uint8_t value26 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
            r->x = value22;
            r->y = value23;
            r->c = value24 & 0x01;
            r->v = value24 & 0x40;
            r->mf = value24 & 0x20;
            r->xf = value24 & 0x10;
            r->dp = (value26 << 8) | value25;
            r->i = value24 & 0x04;
            r->d = value24 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = 5;
        r->x = value21;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFB5, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCFB5); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint8_t db_ret7 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret5 = r->x;
        BUS16_SET(c, (db_ret7 << 0x10) + 0x030E, x_ret5);
        uint16_t value27 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x030C);
        BUS16_SET(c, (db_ret7 << 0x10) + 2 + x_ret5, value27);
        BUS8_SET(c, (db_ret7 << 0x10) + x_ret5, 0);
        BUS8_SET(c, (db_ret7 << 0x10) + 1 + x_ret5, 0x2C);
        BUS8_SET(c, (db_ret7 << 0x10) + 4 + x_ret5, 0x7F);
        r->a = (value27 >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFD2, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCFD2); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        uint16_t dp_ret8 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 1));
        uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 3));
        uint8_t value30 = RAM8(0x0000 + sp0 - 2);
        uint8_t value31 = RAM8(0x0000 + sp0 - 1);
        uint8_t value32 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
        r->x = value28;
        r->y = value29;
        r->c = value30 & 0x01;
        r->v = value30 & 0x40;
        r->mf = value30 & 0x20;
        r->xf = value30 & 0x10;
        r->dp = (value32 << 8) | value31;
        r->i = value30 & 0x04;
        r->d = value30 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (value14 < 0x80) {
        RAM8(0x0000 + sp0 - 0x0B) = y_cf21 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y_cf21;
        RAM8(0x0000 + sp0 - 0x0D) = value14;
        uint8_t value33 = BUS8_RDP(c, (data_bank_cf21 << 0x10) + 2 + x_cf21);
        RAM8(0x0000 + sp0 - 0x0E) = value33 | 0x11;
        r->a = (a_hi_cf21 << 8) | (value33 | 0x11);
        r->x = x_cf21;
        r->y = y_cf21;
        r->c = value14 >= 0x80;
        r->z = (value33 | 0x11) == 0;
        r->n = (value33 | 0x11) & 0x80;
        r->v = overflow_cf21;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_cf21;
        r->dp = direct_page_cf21;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCF61, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF61); } /* allocate_copy_queue_record */
        r->sp += 15;
        uint8_t db_ret9 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t x_ret8 = r->x;
        BUS8_SET(c, (db_ret9 << 0x10) + 6 + x_ret8, RAM8(0x0000 + sp0 - 0x0E));
        BUS8_SET(c, (db_ret9 << 0x10) + 5 + x_ret8, RAM8(0x0000 + sp0 - 0x0D));
        BUS8_SET(c, (db_ret9 << 0x10) + 4 + x_ret8, 2);
        uint16_t value36 = RAM16(0x0000 + sp0 - 0x0C);
        BUS16_SET(c, (db_ret9 << 0x10) + 1 + x_ret8, value36);
        r->a = value36;
        r->z = value36 == 0;
        r->n = value36 & 0x8000;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCF7A, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCF7A); } /* append_copy_queue_record */
        r->sp += 13;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value37 = RAM8(0x0000 + sp0 - 0x0C);
        uint8_t value38 = RAM8(0x0000 + sp0 - 0x0B);
        RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(((value38 << 8) | value37) + 2) >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(((value38 << 8) | value37) + 2);
        r->y = (uint16_t)(((value38 << 8) | value37) + 2);
        r->z = (uint16_t)(((value38 << 8) | value37) + 2) == 0;
        r->n = (uint16_t)(((value38 << 8) | value37) + 2) & 0x8000;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCF81, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF81); } /* allocate_copy_queue_record */
        r->sp += 13;
        uint16_t dp_ret11 = r->dp;
        uint8_t db_ret11 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret9 = r->x;
        uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 7));
        BUS8_SET(c, (db_ret11 << 0x10) + 5 + x_ret9, 1);
        uint8_t value40 = BUS8_RDP(c, (db_ret11 << 0x10) + 2 + value39);
        BUS8_SET(c, (db_ret11 << 0x10) + 6 + x_ret9, value40);
        BUS8_SET(c, (db_ret11 << 0x10) + 7 + x_ret9, 0);
        BUS8_SET(c, (db_ret11 << 0x10) + 4 + x_ret9, 3);
        uint16_t value41 = RAM16(0x0000 + sp0 - 0x0C);
        BUS16_SET(c, (db_ret11 << 0x10) + 1 + x_ret9, value41);
        r->a = value41;
        r->y = value39;
        r->z = value41 == 0;
        r->n = value41 & 0x8000;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFA2, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCFA2); } /* append_copy_queue_record */
        r->sp += 13;
        uint16_t dp_ret12 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value42 = RAM8(0x0000 + sp0 - 0x0C);
        uint8_t value43 = RAM8(0x0000 + sp0 - 0x0B);
        uint16_t value44 = BUS16_RDP(c, (uint16_t)(dp_ret12 + 7));
        r->x = value44;
        r->y = (value43 << 8) | value42;
        r->z = value44 == 0;
        r->n = value44 & 0x8000;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFA8, 0x7EC097); GUARD_JSR(c, sp_call, 0xCFA8); } /* append_oneshot_ppu_entry */
        r->sp += 11;
        uint16_t dp_ret13 = r->dp;
        uint8_t db_ret13 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value45 = BUS16_RDP(c, (db_ret13 << 0x10) + 0x030E);
        if (value45 != 0) {
            uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 1));
            uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 3));
            uint8_t value48 = RAM8(0x0000 + sp0 - 2);
            uint8_t value49 = RAM8(0x0000 + sp0 - 1);
            uint8_t value50 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
            r->x = value46;
            r->y = value47;
            r->c = value48 & 0x01;
            r->v = value48 & 0x40;
            r->mf = value48 & 0x20;
            r->xf = value48 & 0x10;
            r->dp = (value50 << 8) | value49;
            r->i = value48 & 0x04;
            r->d = value48 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = 5;
        r->x = value45;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFB5, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCFB5); } /* allocate_transfer_descriptor */
        r->sp += 11;
        uint8_t db_ret14 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret10 = r->x;
        BUS16_SET(c, (db_ret14 << 0x10) + 0x030E, x_ret10);
        uint16_t value51 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x030C);
        BUS16_SET(c, (db_ret14 << 0x10) + 2 + x_ret10, value51);
        BUS8_SET(c, (db_ret14 << 0x10) + x_ret10, 0);
        BUS8_SET(c, (db_ret14 << 0x10) + 1 + x_ret10, 0x2C);
        BUS8_SET(c, (db_ret14 << 0x10) + 4 + x_ret10, 0x7F);
        r->a = (value51 >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFD2, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCFD2); } /* submit_transfer_or_program_hdma */
        r->sp += 11;
        uint16_t dp_ret15 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value52 = BUS16_RDP(c, (uint16_t)(dp_ret15 + 1));
        uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp_ret15 + 3));
        uint8_t value54 = RAM8(0x0000 + sp0 - 2);
        uint8_t value55 = RAM8(0x0000 + sp0 - 1);
        uint8_t value56 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
        r->x = value52;
        r->y = value53;
        r->c = value54 & 0x01;
        r->v = value54 & 0x40;
        r->mf = value54 & 0x20;
        r->xf = value54 & 0x10;
        r->dp = (value56 << 8) | value55;
        r->i = value54 & 0x04;
        r->d = value54 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0 - 0x0B) = y_cf21 >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y_cf21;
    uint8_t value57 = BUS8_RDP(c, (data_bank_cf21 << 0x10) + 2 + x_cf21);
    RAM8(0x0000 + sp0 - 0x0D) = value57 | 0x11;
    r->a = (a_hi_cf21 << 8) | (value57 | 0x11);
    r->x = x_cf21;
    r->y = y_cf21;
    r->c = value14 >= 0x80;
    r->z = (value57 | 0x11) == 0;
    r->n = (value57 | 0x11) & 0x80;
    r->v = overflow_cf21;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_cf21;
    r->dp = direct_page_cf21;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF32, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF32); } /* allocate_copy_queue_record */
    r->sp += 14;
    uint8_t db_ret16 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t x_ret13 = r->x;
    BUS8_SET(c, (db_ret16 << 0x10) + 6 + x_ret13, RAM8(0x0000 + sp0 - 0x0D));
    BUS8_SET(c, (db_ret16 << 0x10) + 5 + x_ret13, 0x7F);
    BUS8_SET(c, (db_ret16 << 0x10) + 4 + x_ret13, 2);
    uint16_t value59 = RAM16(0x0000 + sp0 - 0x0C);
    BUS16_SET(c, (db_ret16 << 0x10) + 1 + x_ret13, value59);
    r->a = value59;
    r->z = value59 == 0;
    r->n = value59 & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF4C, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCF4C); } /* append_copy_queue_record */
    r->sp += 13;
    uint16_t dp_ret17 = r->dp;
    uint8_t db_ret17 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all17 = r->a;
    uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret17 + 7));
    uint8_t value61 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value62 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value63 = BUS8_RDP(c, (uint16_t)(dp_ret17 + 5));
    RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(((value62 << 8) | value61) + 2) >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(((value62 << 8) | value61) + 2);
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)(value63 - 0x7F);
    uint8_t value64 = BUS8_RDP(c, (db_ret17 << 0x10) + 2 + value60);
    RAM8(0x0000 + sp0 - 0x0E) = value64 | 0x11;
    r->a = (a_all17 >> 8 << 8) | (value64 | 0x11);
    r->x = value60;
    r->y = (uint16_t)(((value62 << 8) | value61) + 2);
    r->c = value63 >= 0x7F;
    r->z = (value64 | 0x11) == 0;
    r->n = (value64 | 0x11) & 0x80;
    r->v = ((value63 ^ 0x7F) & (value63 ^ (uint8_t)(value63 - 0x7F)) & 0x80) != 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF61, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF61); } /* allocate_copy_queue_record */
    r->sp += 15;
    uint8_t db_ret18 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t x_ret15 = r->x;
    BUS8_SET(c, (db_ret18 << 0x10) + 6 + x_ret15, RAM8(0x0000 + sp0 - 0x0E));
    BUS8_SET(c, (db_ret18 << 0x10) + 5 + x_ret15, RAM8(0x0000 + sp0 - 0x0D));
    BUS8_SET(c, (db_ret18 << 0x10) + 4 + x_ret15, 2);
    uint16_t value67 = RAM16(0x0000 + sp0 - 0x0C);
    BUS16_SET(c, (db_ret18 << 0x10) + 1 + x_ret15, value67);
    r->a = value67;
    r->z = value67 == 0;
    r->n = value67 & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF7A, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCF7A); } /* append_copy_queue_record */
    r->sp += 13;
    if (r->xf != 0) { c->fail = 3; return; }
    uint8_t value68 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value69 = RAM8(0x0000 + sp0 - 0x0B);
    RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(((value69 << 8) | value68) + 2) >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(((value69 << 8) | value68) + 2);
    r->y = (uint16_t)(((value69 << 8) | value68) + 2);
    r->z = (uint16_t)(((value69 << 8) | value68) + 2) == 0;
    r->n = (uint16_t)(((value69 << 8) | value68) + 2) & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF81, 0x7EC915); GUARD_JSR(c, sp_call, 0xCF81); } /* allocate_copy_queue_record */
    r->sp += 13;
    uint16_t dp_ret20 = r->dp;
    uint8_t db_ret20 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret16 = r->x;
    uint16_t value70 = BUS16_RDP(c, (uint16_t)(dp_ret20 + 7));
    BUS8_SET(c, (db_ret20 << 0x10) + 5 + x_ret16, 1);
    uint8_t value71 = BUS8_RDP(c, (db_ret20 << 0x10) + 2 + value70);
    BUS8_SET(c, (db_ret20 << 0x10) + 6 + x_ret16, value71);
    BUS8_SET(c, (db_ret20 << 0x10) + 7 + x_ret16, 0);
    BUS8_SET(c, (db_ret20 << 0x10) + 4 + x_ret16, 3);
    uint16_t value72 = RAM16(0x0000 + sp0 - 0x0C);
    BUS16_SET(c, (db_ret20 << 0x10) + 1 + x_ret16, value72);
    r->a = value72;
    r->y = value70;
    r->z = value72 == 0;
    r->n = value72 & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFA2, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCFA2); } /* append_copy_queue_record */
    r->sp += 13;
    uint16_t dp_ret21 = r->dp;
    if (r->xf != 0) { c->fail = 3; return; }
    uint8_t value73 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value74 = RAM8(0x0000 + sp0 - 0x0B);
    uint16_t value75 = BUS16_RDP(c, (uint16_t)(dp_ret21 + 7));
    r->x = value75;
    r->y = (value74 << 8) | value73;
    r->z = value75 == 0;
    r->n = value75 & 0x8000;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFA8, 0x7EC097); GUARD_JSR(c, sp_call, 0xCFA8); } /* append_oneshot_ppu_entry */
    r->sp += 11;
    uint16_t dp_ret22 = r->dp;
    uint8_t db_ret22 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value76 = BUS16_RDP(c, (db_ret22 << 0x10) + 0x030E);
    if (value76 != 0) {
        uint16_t value77 = BUS16_RDP(c, (uint16_t)(dp_ret22 + 1));
        uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp_ret22 + 3));
        uint8_t value79 = RAM8(0x0000 + sp0 - 2);
        uint8_t value80 = RAM8(0x0000 + sp0 - 1);
        uint8_t value81 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
        r->x = value77;
        r->y = value78;
        r->c = value79 & 0x01;
        r->v = value79 & 0x40;
        r->mf = value79 & 0x20;
        r->xf = value79 & 0x10;
        r->dp = (value81 << 8) | value80;
        r->i = value79 & 0x04;
        r->d = value79 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = 5;
    r->x = value76;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFB5, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xCFB5); } /* allocate_transfer_descriptor */
    r->sp += 11;
    uint8_t db_ret23 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret17 = r->x;
    BUS16_SET(c, (db_ret23 << 0x10) + 0x030E, x_ret17);
    uint16_t value82 = BUS16_RDP(c, (db_ret23 << 0x10) + 0x030C);
    BUS16_SET(c, (db_ret23 << 0x10) + 2 + x_ret17, value82);
    BUS8_SET(c, (db_ret23 << 0x10) + x_ret17, 0);
    BUS8_SET(c, (db_ret23 << 0x10) + 1 + x_ret17, 0x2C);
    BUS8_SET(c, (db_ret23 << 0x10) + 4 + x_ret17, 0x7F);
    r->a = (value82 >> 8 << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFD2, 0x7E90DA); GUARD_JSR(c, sp_call, 0xCFD2); } /* submit_transfer_or_program_hdma */
    r->sp += 11;
    uint16_t dp_ret24 = r->dp;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value83 = BUS16_RDP(c, (uint16_t)(dp_ret24 + 1));
    uint16_t value84 = BUS16_RDP(c, (uint16_t)(dp_ret24 + 3));
    uint8_t value85 = RAM8(0x0000 + sp0 - 2);
    uint8_t value86 = RAM8(0x0000 + sp0 - 1);
    uint8_t value87 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x0B) + 8);
    r->x = value83;
    r->y = value84;
    r->c = value85 & 0x01;
    r->v = value85 & 0x40;
    r->mf = value85 & 0x20;
    r->xf = value85 & 0x10;
    r->dp = (value87 << 8) | value86;
    r->i = value85 & 0x04;
    r->d = value85 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_CEDD:;
    RAM8(0x0000 + sp0 - 0x0B) = y_cedd >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y_cedd;
    RAM8(0x0000 + sp0 - 0x0D) = a_cedd;
    uint8_t value88 = BUS8_RDP(c, (data_bank_cedd << 0x10) + 2 + x_cedd);
    RAM8(0x0000 + sp0 - 0x0E) = value88 & 0xEE;
    BUS8_SET(c, (data_bank_cedd << 0x10) + 2 + x_cedd, value88 & 0xEE);
    r->a = a_hi_cedd << 8 | (value88 & 0xEE);
    r->x = x_cedd;
    r->y = y_cedd;
    r->c = carry_cedd;
    r->z = (value88 & 0xEE) == 0;
    r->n = value88 & 0xEE & 0x80;
    r->v = overflow_cedd;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_cedd;
    r->dp = direct_page_cedd;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCEEA, 0x7EC915); GUARD_JSR(c, sp_call, 0xCEEA); } /* allocate_copy_queue_record */
    r->sp += 15;
    uint8_t db_ret25 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t x_ret20 = r->x;
    BUS8_SET(c, (db_ret25 << 0x10) + 6 + x_ret20, RAM8(0x0000 + sp0 - 0x0E));
    BUS8_SET(c, (db_ret25 << 0x10) + 5 + x_ret20, RAM8(0x0000 + sp0 - 0x0D));
    BUS8_SET(c, (db_ret25 << 0x10) + 4 + x_ret20, 2);
    uint16_t value91 = RAM16(0x0000 + sp0 - 0x0C);
    BUS16_SET(c, (db_ret25 << 0x10) + 1 + x_ret20, value91);
    r->a = value91;
    r->z = value91 == 0;
    r->n = value91 & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF03, 0x7EC95A); GUARD_JSR(c, sp_call, 0xCF03); } /* append_copy_queue_record */
    r->sp += 13;
    uint16_t dp_ret26 = r->dp;
    uint8_t db_ret26 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all26 = r->a;
    bool overflow_ret26 = r->v;
    uint16_t value92 = BUS16_RDP(c, (uint16_t)(dp_ret26 + 7));
    uint8_t value93 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value94 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value95 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 3));
    if (value95 < 0xDF) {
        a_hi_cf21 = a_all26 >> 8;
        x_cf21 = value92;
        y_cf21 = (uint16_t)(((value94 << 8) | value93) + 2);
        carry_cf21 = value95 >= 0xDF;
        overflow_cf21 = overflow_ret26;
        direct_page_cf21 = dp_ret26;
        data_bank_cf21 = db_ret26;
        goto shared_CF21;
    }
    uint8_t value96 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 5));
    if (value96 == 0) {
        a_hi_cf21 = a_all26 >> 8;
        x_cf21 = value92;
        y_cf21 = (uint16_t)(((value94 << 8) | value93) + 2);
        carry_cf21 = value95 >= 0xDF;
        overflow_cf21 = overflow_ret26;
        direct_page_cf21 = dp_ret26;
        data_bank_cf21 = db_ret26;
        goto shared_CF21;
    }
    uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 5));
    BUS8_SET(c, (uint16_t)(dp_ret26 + 5), (uint8_t)(value97 - 1));
    uint8_t value98 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 3));
    BUS8_SET(c, (uint16_t)(dp_ret26 + 3), (uint8_t)(value98 - 1));
    a_hi_cf21 = a_all26 >> 8;
    x_cf21 = value92;
    y_cf21 = (uint16_t)(((value94 << 8) | value93) + 2);
    carry_cf21 = value95 >= 0xDF;
    overflow_cf21 = overflow_ret26;
    direct_page_cf21 = dp_ret26;
    data_bank_cf21 = db_ret26;
    goto shared_CF21;
}
SOM_REGISTER(0x7ECE6B, SOM_RTS, "gen", build_title_window_scanline_table, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 15, 1, 0, 375, 185)
