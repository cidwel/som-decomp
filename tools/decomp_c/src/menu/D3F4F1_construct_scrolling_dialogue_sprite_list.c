#include "som_c.h"

/* D3F4F1 construct_scrolling_dialogue_sprite_list   [class B, 118 bytes, 60 instructions]
 * Source: src/rom/construct_scrolling_dialogue_sprite_list.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BX.
 */
static void construct_scrolling_dialogue_sprite_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_f529 = 0;
    uint8_t x_f529 = 0;
    uint8_t y_f529 = 0;
    bool carry_f529 = 0;
    bool overflow_f529 = 0;
    uint16_t direct_page_f529 = 0;
    uint8_t data_bank_f529 = 0;
    uint8_t a_hi_f5292 = 0;
    uint16_t x_f5292 = 0;
    uint16_t y_f5292 = 0;
    bool carry_f5292 = 0;
    bool overflow_f5292 = 0;
    uint16_t direct_page_f5292 = 0;
    uint8_t data_bank_f5292 = 0;
    uint8_t a_hi_f539 = 0;
    uint8_t x_f539 = 0;
    uint8_t y_f539 = 0;
    bool carry_f539 = 0;
    bool overflow_f539 = 0;
    uint16_t direct_page_f539 = 0;
    uint8_t data_bank_f539 = 0;
    uint8_t a_hi_f5392 = 0;
    uint16_t x_f5392 = 0;
    uint16_t y_f5392 = 0;
    bool carry_f5392 = 0;
    bool overflow_f5392 = 0;
    uint16_t direct_page_f5392 = 0;
    uint8_t data_bank_f5392 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    r->a = 0;
    r->x = 0x0112;
    r->c = (uint16_t)(sp0 - 5) >= 4;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF513, 0xC12E78); GUARD_JSL(c, sp_call, 0xF513); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 10;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (x_ret) {
        RAM8(0x0003 + (uint16_t)(sp0 - 9)) = (uint8_t)x_ret2;
        RAM16_SET(0x010C + (uint8_t)x_ret2, 0xFFFF);
        RAM16_SET(0x0110 + (uint8_t)x_ret2, 1);
        RAM8(0x0005 + (uint16_t)(sp0 - 9)) = (uint8_t)x_ret2;
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), 0x28);
        a_hi_f529 = 0;
        x_f529 = (uint8_t)x_ret2;
        y_f529 = (uint8_t)y_ret;
        carry_f529 = carry_ret;
        overflow_f529 = overflow_ret;
        direct_page_f529 = (uint16_t)(sp0 - 9);
        data_bank_f529 = 0x7E;
        goto shared_F529;
    } else {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x_ret2);
        RAM16_SET(0x010C + x_ret2, 0xFFFF);
        RAM16_SET(0x0110 + x_ret2, 1);
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), x_ret2);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), 0x28);
        a_hi_f5292 = 0;
        x_f5292 = x_ret2;
        y_f5292 = y_ret;
        carry_f5292 = carry_ret;
        overflow_f5292 = overflow_ret;
        direct_page_f5292 = (uint16_t)(sp0 - 9);
        data_bank_f5292 = 0x7E;
        goto shared_F529_1;
    }
    shared_F529:;
    r->a = 0x0F;
    r->x = x_f529;
    r->y = y_f529;
    r->c = carry_f529;
    r->z = 0;
    r->n = 0;
    r->v = overflow_f529;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_f529;
    r->dp = direct_page_f529;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF52F, 0xC12E80); GUARD_JSL(c, sp_call, 0xF52F); } /* activate_native_entity_sprite_long */
    r->sp += 10;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value2 - 1));
    if ((uint16_t)(value2 - 1) != 0) {
        if (x_ret3) {
            a_hi_f529 = a_all2 >> 8;
            x_f529 = (uint8_t)x_ret4;
            y_f529 = (uint8_t)y_ret2;
            carry_f529 = carry_ret2;
            overflow_f529 = overflow_ret2;
            direct_page_f529 = dp_ret;
            data_bank_f529 = db_ret;
            goto shared_F529;
        } else {
            a_hi_f5292 = a_all2 >> 8;
            x_f5292 = x_ret4;
            y_f5292 = y_ret2;
            carry_f5292 = carry_ret2;
            overflow_f5292 = overflow_ret2;
            direct_page_f5292 = dp_ret;
            data_bank_f5292 = db_ret;
            goto shared_F529_1;
        }
    }
    BUS16_SET(c, (uint16_t)(dp_ret + 1), 0x18);
    if (x_ret3) {
        a_hi_f539 = 0;
        x_f539 = (uint8_t)x_ret4;
        y_f539 = (uint8_t)y_ret2;
        carry_f539 = carry_ret2;
        overflow_f539 = overflow_ret2;
        direct_page_f539 = dp_ret;
        data_bank_f539 = db_ret;
        goto shared_F539;
    } else {
        a_hi_f5392 = 0;
        x_f5392 = x_ret4;
        y_f5392 = y_ret2;
        carry_f5392 = carry_ret2;
        overflow_f5392 = overflow_ret2;
        direct_page_f5392 = dp_ret;
        data_bank_f5392 = db_ret;
        goto shared_F539_1;
    }
    shared_F529_1:;
    r->a = 0x0F;
    r->x = x_f5292;
    r->y = y_f5292;
    r->c = carry_f5292;
    r->z = 0;
    r->n = 0;
    r->v = overflow_f5292;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_f5292;
    r->dp = direct_page_f5292;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF52F, 0xC12E80); GUARD_JSL(c, sp_call, 0xF52F); } /* activate_native_entity_sprite_long */
    r->sp += 10;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret5 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
    BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value3 - 1));
    if ((uint16_t)(value3 - 1) != 0) {
        if (x_ret5) {
            a_hi_f529 = a_all3 >> 8;
            x_f529 = (uint8_t)x_ret6;
            y_f529 = (uint8_t)y_ret3;
            carry_f529 = carry_ret3;
            overflow_f529 = overflow_ret3;
            direct_page_f529 = dp_ret2;
            data_bank_f529 = db_ret2;
            goto shared_F529;
        } else {
            a_hi_f5292 = a_all3 >> 8;
            x_f5292 = x_ret6;
            y_f5292 = y_ret3;
            carry_f5292 = carry_ret3;
            overflow_f5292 = overflow_ret3;
            direct_page_f5292 = dp_ret2;
            data_bank_f5292 = db_ret2;
            goto shared_F529_1;
        }
    }
    BUS16_SET(c, (uint16_t)(dp_ret2 + 1), 0x18);
    if (x_ret5) {
        a_hi_f539 = 0;
        x_f539 = (uint8_t)x_ret6;
        y_f539 = (uint8_t)y_ret3;
        carry_f539 = carry_ret3;
        overflow_f539 = overflow_ret3;
        direct_page_f539 = dp_ret2;
        data_bank_f539 = db_ret2;
        goto shared_F539;
    } else {
        a_hi_f5392 = 0;
        x_f5392 = x_ret6;
        y_f5392 = y_ret3;
        carry_f5392 = carry_ret3;
        overflow_f5392 = overflow_ret3;
        direct_page_f5392 = dp_ret2;
        data_bank_f5392 = db_ret2;
        goto shared_F539_1;
    }
    shared_F539:;
    r->a = 0x0F;
    r->x = x_f539;
    r->y = y_f539;
    r->c = carry_f539;
    r->z = 0;
    r->n = 0;
    r->v = overflow_f539;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_f539;
    r->dp = direct_page_f539;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF53F, 0xC12E80); GUARD_JSL(c, sp_call, 0xF53F); } /* activate_native_entity_sprite_long */
    r->sp += 10;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret7 = r->xf;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret4 = r->y;
    BUS16_SET(c, (db_ret3 << 0x10) + x_ret8, 0);
    if (x_ret7) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
        BUS16_SET(c, (db_ret3 << 0x10) + value4, (uint8_t)x_ret8);
        BUS8_SET(c, (uint16_t)(dp_ret3 + 5), (uint8_t)(value4 + 0x0A));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value5 - 1));
        if ((uint16_t)(value5 - 1) != 0) {
            a_hi_f539 = value4 + 0x0A >> 8;
            x_f539 = (uint8_t)(value4 + 0x0A);
            y_f539 = (uint8_t)y_ret4;
            carry_f539 = value4 + 0x0A > 0xFFFF;
            overflow_f539 = ((value4 ^ value4 + 0x0A) & (value4 + 0x0A ^ 0x0A) & 0x8000) != 0;
            direct_page_f539 = dp_ret3;
            data_bank_f539 = db_ret3;
            goto shared_F539;
        }
        uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint8_t value7 = RAM8(0x0000 + sp0 - 9);
        RAM16_SET(0x0000 + sp0 - 4, value4 + 0x0A);
        uint8_t value8 = RAM8(0x0000 + sp0 - 4);
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (value9 << 8) | value8;
        r->x = value6;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->db = value7;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
        BUS16_SET(c, (db_ret3 << 0x10) + value13, x_ret8);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 5), (uint16_t)(value13 + 0x0A));
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value14 - 1));
        if ((uint16_t)(value14 - 1) != 0) {
            a_hi_f5392 = (uint16_t)(value13 + 0x0A) >> 8;
            x_f5392 = (uint16_t)(value13 + 0x0A);
            y_f5392 = y_ret4;
            carry_f5392 = value13 + 0x0A > 0xFFFF;
            overflow_f5392 = ((value13 ^ (uint16_t)(value13 + 0x0A)) & ((uint16_t)(value13 + 0x0A) ^ 0x0A) & 0x8000) != 0;
            direct_page_f5392 = dp_ret3;
            data_bank_f5392 = db_ret3;
            goto shared_F539_1;
        }
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint8_t value16 = RAM8(0x0000 + sp0 - 9);
        RAM16_SET(0x0000 + sp0 - 4, (uint16_t)(value13 + 0x0A));
        uint8_t value17 = RAM8(0x0000 + sp0 - 4);
        uint8_t value18 = RAM8(0x0000 + sp0 - 3);
        uint8_t value19 = RAM8(0x0000 + sp0 - 2);
        uint8_t value20 = RAM8(0x0000 + sp0 - 1);
        uint8_t value21 = RAM8(0x0000 + sp0);
        r->a = (value18 << 8) | value17;
        r->x = value15;
        r->mf = value19 & 0x20;
        r->xf = value19 & 0x10;
        r->db = value16;
        r->dp = (value21 << 8) | value20;
        r->i = value19 & 0x04;
        r->d = value19 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    shared_F539_1:;
    r->a = 0x0F;
    r->x = x_f5392;
    r->y = y_f5392;
    r->c = carry_f5392;
    r->z = 0;
    r->n = 0;
    r->v = overflow_f5392;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_f5392;
    r->dp = direct_page_f5392;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF53F, 0xC12E80); GUARD_JSL(c, sp_call, 0xF53F); } /* activate_native_entity_sprite_long */
    r->sp += 10;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret9 = r->xf;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret5 = r->y;
    BUS16_SET(c, (db_ret4 << 0x10) + x_ret10, 0);
    if (x_ret9) {
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 5));
        BUS16_SET(c, (db_ret4 << 0x10) + value22, (uint8_t)x_ret10);
        BUS8_SET(c, (uint16_t)(dp_ret4 + 5), (uint8_t)(value22 + 0x0A));
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value23 - 1));
        if ((uint16_t)(value23 - 1) != 0) {
            a_hi_f539 = value22 + 0x0A >> 8;
            x_f539 = (uint8_t)(value22 + 0x0A);
            y_f539 = (uint8_t)y_ret5;
            carry_f539 = value22 + 0x0A > 0xFFFF;
            overflow_f539 = ((value22 ^ value22 + 0x0A) & (value22 + 0x0A ^ 0x0A) & 0x8000) != 0;
            direct_page_f539 = dp_ret4;
            data_bank_f539 = db_ret4;
            goto shared_F539;
        }
        uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint8_t value25 = RAM8(0x0000 + sp0 - 9);
        RAM16_SET(0x0000 + sp0 - 4, value22 + 0x0A);
        uint8_t value26 = RAM8(0x0000 + sp0 - 4);
        uint8_t value27 = RAM8(0x0000 + sp0 - 3);
        uint8_t value28 = RAM8(0x0000 + sp0 - 2);
        uint8_t value29 = RAM8(0x0000 + sp0 - 1);
        uint8_t value30 = RAM8(0x0000 + sp0);
        r->a = (value27 << 8) | value26;
        r->x = value24;
        r->mf = value28 & 0x20;
        r->xf = value28 & 0x10;
        r->db = value25;
        r->dp = (value30 << 8) | value29;
        r->i = value28 & 0x04;
        r->d = value28 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    } else {
        uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 5));
        BUS16_SET(c, (db_ret4 << 0x10) + value31, x_ret10);
        BUS16_SET(c, (uint16_t)(dp_ret4 + 5), (uint16_t)(value31 + 0x0A));
        uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value32 - 1));
        if ((uint16_t)(value32 - 1) != 0) {
            a_hi_f5392 = (uint16_t)(value31 + 0x0A) >> 8;
            x_f5392 = (uint16_t)(value31 + 0x0A);
            y_f5392 = y_ret5;
            carry_f5392 = value31 + 0x0A > 0xFFFF;
            overflow_f5392 = ((value31 ^ (uint16_t)(value31 + 0x0A)) & ((uint16_t)(value31 + 0x0A) ^ 0x0A) & 0x8000) != 0;
            direct_page_f5392 = dp_ret4;
            data_bank_f5392 = db_ret4;
            goto shared_F539_1;
        }
        uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint8_t value34 = RAM8(0x0000 + sp0 - 9);
        RAM16_SET(0x0000 + sp0 - 4, (uint16_t)(value31 + 0x0A));
        uint8_t value35 = RAM8(0x0000 + sp0 - 4);
        uint8_t value36 = RAM8(0x0000 + sp0 - 3);
        uint8_t value37 = RAM8(0x0000 + sp0 - 2);
        uint8_t value38 = RAM8(0x0000 + sp0 - 1);
        uint8_t value39 = RAM8(0x0000 + sp0);
        r->a = (value36 << 8) | value35;
        r->x = value33;
        r->mf = value37 & 0x20;
        r->xf = value37 & 0x10;
        r->db = value34;
        r->dp = (value39 << 8) | value38;
        r->i = value37 & 0x04;
        r->d = value37 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xD3F4F1, SOM_RTL, "gen", construct_scrolling_dialogue_sprite_list, 0, L_B | L_X, 12, 1, 0, 118, 60)
