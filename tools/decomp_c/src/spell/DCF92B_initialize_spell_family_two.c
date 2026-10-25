#include "som_c.h"

/* DCF92B initialize_spell_family_two   [class B, 134 bytes, 65 instructions]
 * Source: src/rom/initialize_spell_family_two.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: nothing.
 */
static void initialize_spell_family_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01CC) { c->fail = 3; return; }
    if (r->d) { c->fail = 3; return; } /* binary ADC/SBC: entered with the decimal flag clear */
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    uint16_t direct_page_f9a5 = 0;
    uint8_t data_bank_f9a5 = 0;
    uint16_t direct_page_f9a52 = 0;
    uint8_t data_bank_f9a52 = 0;
    uint16_t direct_page_f9a53 = 0;
    uint8_t data_bank_f9a53 = 0;
    uint16_t direct_page_f9a54 = 0;
    uint8_t data_bank_f9a54 = 0;
    uint8_t a_hi_f97b = 0;
    uint8_t x_f97b = 0;
    uint8_t y_f97b = 0;
    bool carry_f97b = 0;
    bool overflow_f97b = 0;
    uint16_t direct_page_f97b = 0;
    uint8_t data_bank_f97b = 0;
    uint8_t a_hi_f97b2 = 0;
    uint16_t x_f97b2 = 0;
    uint16_t y_f97b2 = 0;
    bool carry_f97b2 = 0;
    bool overflow_f97b2 = 0;
    uint16_t direct_page_f97b2 = 0;
    uint8_t data_bank_f97b2 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xCC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0B), y);
    r->a = 0x40;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF947, 0xC12ED1); GUARD_JSL(c, sp_call, 0xF947); } /* draw_spell_entity_bounded_random_long */
    r->sp += 12;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
        if ((uint8_t)a_all != 0) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        r->x = (uint8_t)a_all;
        r->y = value;
        r->z = (uint8_t)a_all == 0;
        r->n = (uint8_t)a_all & 0x80;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF950, 0xD3FD3F); GUARD_JSL(c, sp_call, 0xF950); } /* initialize_spell_random_fallback_long */
        r->sp += 12;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        if (m_ret2) {
            if (x_ret3) {
                direct_page_f9a5 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a5 = db_ret;
                goto shared_F9A5;
            } else {
                direct_page_f9a52 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a52 = db_ret;
                goto shared_F9A5_1;
            }
        } else {
            if (x_ret3) {
                direct_page_f9a53 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a53 = db_ret;
                goto shared_F9A5_2;
            } else {
                direct_page_f9a54 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a54 = db_ret;
                goto shared_F9A5_3;
            }
        }
    } else {
        uint16_t value2 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0B));
        if (a_all != 0) {
            r->x = 0xF8D7;
            r->y = value2;
            r->z = 0;
            r->n = 1;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF959, 0xC12E90); GUARD_JSL(c, sp_call, 0xF959); } /* construct_spell_graphics_audio_resources_long */
            r->sp += 12;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret5 = r->xf;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            if (x_ret5) {
                RAM8(0x0007 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)x_ret6;
                uint8_t value3 = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
                BUS16_SET(c, (db_ret << 0x10) + 0x1A + value3, (uint8_t)x_ret6);
                BUS16_SET(c, (db_ret << 0x10) + 0x2A + value3, 0x010E);
                BUS16_SET(c, (db_ret << 0x10) + 0x1C + value3, 0x3711);
                BUS16_SET(c, (db_ret << 0x10) + 0x1E + value3, 0x345A);
                uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0x27 + value3);
                RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = value4;
                a_hi_f97b = 0x34;
                x_f97b = value3;
                y_f97b = (uint8_t)y_ret3;
                carry_f97b = carry_ret3;
                overflow_f97b = overflow_ret3;
                direct_page_f97b = (uint16_t)(sp0 - 0x0B);
                data_bank_f97b = db_ret;
                goto shared_F97B;
            } else {
                RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), x_ret6);
                uint16_t value5 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0B));
                BUS16_SET(c, (db_ret << 0x10) + 0x1A + value5, x_ret6);
                BUS16_SET(c, (db_ret << 0x10) + 0x2A + value5, 0x010E);
                BUS16_SET(c, (db_ret << 0x10) + 0x1C + value5, 0x3711);
                BUS16_SET(c, (db_ret << 0x10) + 0x1E + value5, 0x345A);
                uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x27 + value5);
                RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = value6;
                a_hi_f97b2 = 0x34;
                x_f97b2 = value5;
                y_f97b2 = y_ret3;
                carry_f97b2 = carry_ret3;
                overflow_f97b2 = overflow_ret3;
                direct_page_f97b2 = (uint16_t)(sp0 - 0x0B);
                data_bank_f97b2 = db_ret;
                goto shared_F97B_1;
            }
        }
        r->x = a_all;
        r->y = value2;
        r->z = a_all == 0;
        r->n = a_all & 0x8000;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF950, 0xD3FD3F); GUARD_JSL(c, sp_call, 0xF950); } /* initialize_spell_random_fallback_long */
        r->sp += 12;
        bool m_ret3 = r->mf;
        bool x_ret7 = r->xf;
        if (m_ret3) {
            if (x_ret7) {
                direct_page_f9a5 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a5 = db_ret;
                goto shared_F9A5;
            } else {
                direct_page_f9a52 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a52 = db_ret;
                goto shared_F9A5_1;
            }
        } else {
            if (x_ret7) {
                direct_page_f9a53 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a53 = db_ret;
                goto shared_F9A5_2;
            } else {
                direct_page_f9a54 = (uint16_t)(sp0 - 0x0B);
                data_bank_f9a54 = db_ret;
                goto shared_F9A5_3;
            }
        }
    }
    shared_F9A5:;
    LOOP_GUARD(loop_guard);
    uint8_t value7 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = value7;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    RETURN_RTS(c);
    shared_F9A5_1:;
    LOOP_GUARD(loop_guard);
    uint8_t value11 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value12 = RAM8(0x0000 + sp0 - 2);
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    r->mf = value12 & 0x20;
    r->xf = value12 & 0x10;
    r->db = value11;
    r->dp = (value14 << 8) | value13;
    r->i = value12 & 0x04;
    r->d = value12 & 0x08;
    RETURN_RTS(c);
    shared_F9A5_2:;
    LOOP_GUARD(loop_guard);
    uint8_t value15 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint8_t value18 = RAM8(0x0000 + sp0);
    r->mf = value16 & 0x20;
    r->xf = value16 & 0x10;
    r->db = value15;
    r->dp = (value18 << 8) | value17;
    r->i = value16 & 0x04;
    r->d = value16 & 0x08;
    RETURN_RTS(c);
    shared_F9A5_3:;
    LOOP_GUARD(loop_guard);
    uint8_t value19 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value20 = RAM8(0x0000 + sp0 - 2);
    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
    uint8_t value22 = RAM8(0x0000 + sp0);
    r->mf = value20 & 0x20;
    r->xf = value20 & 0x10;
    r->db = value19;
    r->dp = (value22 << 8) | value21;
    r->i = value20 & 0x04;
    r->d = value20 & 0x08;
    RETURN_RTS(c);
    shared_F97B:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (uint16_t)(direct_page_f97b + 4), x_f97b);
    uint8_t value23 = BUS8_RDP(c, (data_bank_f97b << 0x10) + x_f97b);
    uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_f97b + 7));
    r->a = (a_hi_f97b << 8) | value23;
    r->x = value24;
    r->y = y_f97b;
    r->c = carry_f97b;
    r->z = value24 == 0;
    r->n = value24 & 0x80;
    r->v = overflow_f97b;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_f97b;
    r->dp = direct_page_f97b;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF984, 0xDCF9B1); GUARD_JSR(c, sp_call, 0xF984); } /* construct_spell_family_two_object */
    r->sp += 12;
    uint8_t db_ret2 = r->db;
    bool x_ret9 = r->xf;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret5 = r->y;
    if (x_ret9) {
        uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_f97b + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value25, (uint8_t)x_ret10);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value25, 0x2C01);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value25, 0x2BFC);
        uint8_t value26 = BUS8_RDP(c, (uint16_t)(direct_page_f97b + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f97b + 1), (uint8_t)(value26 - 1));
        if ((uint8_t)(value26 - 1) != 0) {
            a_hi_f97b = value25 + 8 >> 8;
            x_f97b = (uint8_t)(value25 + 8);
            y_f97b = (uint8_t)y_ret5;
            carry_f97b = value25 + 8 > 0xFFFF;
            overflow_f97b = ((value25 ^ value25 + 8) & (value25 + 8 ^ 8) & 0x8000) != 0;
            data_bank_f97b = db_ret2;
            goto shared_F97B;
        }
        direct_page_f9a5 = direct_page_f97b;
        data_bank_f9a5 = db_ret2;
        goto shared_F9A5;
    } else {
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_f97b + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value27, x_ret10);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value27, 0x2C01);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value27, 0x2BFC);
        uint8_t value28 = BUS8_RDP(c, (uint16_t)(direct_page_f97b + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f97b + 1), (uint8_t)(value28 - 1));
        if ((uint8_t)(value28 - 1) != 0) {
            a_hi_f97b2 = (uint16_t)(value27 + 8) >> 8;
            x_f97b2 = (uint16_t)(value27 + 8);
            y_f97b2 = y_ret5;
            carry_f97b2 = value27 + 8 > 0xFFFF;
            overflow_f97b2 = ((value27 ^ (uint16_t)(value27 + 8)) & ((uint16_t)(value27 + 8) ^ 8) & 0x8000) != 0;
            direct_page_f97b2 = direct_page_f97b;
            data_bank_f97b2 = db_ret2;
            goto shared_F97B_1;
        }
        direct_page_f9a52 = direct_page_f97b;
        data_bank_f9a52 = db_ret2;
        goto shared_F9A5_1;
    }
    shared_F97B_1:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(direct_page_f97b2 + 4), x_f97b2);
    uint8_t value29 = BUS8_RDP(c, (data_bank_f97b2 << 0x10) + x_f97b2);
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_f97b2 + 7));
    r->a = (a_hi_f97b2 << 8) | value29;
    r->x = value30;
    r->y = y_f97b2;
    r->c = carry_f97b2;
    r->z = value30 == 0;
    r->n = value30 & 0x8000;
    r->v = overflow_f97b2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f97b2;
    r->dp = direct_page_f97b2;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF984, 0xDCF9B1); GUARD_JSR(c, sp_call, 0xF984); } /* construct_spell_family_two_object */
    r->sp += 12;
    uint8_t db_ret3 = r->db;
    bool x_ret11 = r->xf;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret6 = r->y;
    if (x_ret11) {
        uint8_t value31 = BUS8_RDP(c, (uint16_t)(direct_page_f97b2 + 4));
        BUS16_SET(c, (db_ret3 << 0x10) + 2 + value31, (uint8_t)x_ret12);
        BUS16_SET(c, (db_ret3 << 0x10) + 4 + value31, 0x2C01);
        BUS16_SET(c, (db_ret3 << 0x10) + 6 + value31, 0x2BFC);
        uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page_f97b2 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f97b2 + 1), (uint8_t)(value32 - 1));
        if ((uint8_t)(value32 - 1) != 0) {
            a_hi_f97b = value31 + 8 >> 8;
            x_f97b = (uint8_t)(value31 + 8);
            y_f97b = (uint8_t)y_ret6;
            carry_f97b = value31 + 8 > 0xFFFF;
            overflow_f97b = ((value31 ^ value31 + 8) & (value31 + 8 ^ 8) & 0x8000) != 0;
            direct_page_f97b = direct_page_f97b2;
            data_bank_f97b = db_ret3;
            goto shared_F97B;
        }
        direct_page_f9a5 = direct_page_f97b2;
        data_bank_f9a5 = db_ret3;
        goto shared_F9A5;
    } else {
        uint16_t value33 = BUS16_RDP(c, (uint16_t)(direct_page_f97b2 + 4));
        BUS16_SET(c, (db_ret3 << 0x10) + 2 + value33, x_ret12);
        BUS16_SET(c, (db_ret3 << 0x10) + 4 + value33, 0x2C01);
        BUS16_SET(c, (db_ret3 << 0x10) + 6 + value33, 0x2BFC);
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(direct_page_f97b2 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_f97b2 + 1), (uint8_t)(value34 - 1));
        if ((uint8_t)(value34 - 1) != 0) {
            a_hi_f97b2 = (uint16_t)(value33 + 8) >> 8;
            x_f97b2 = (uint16_t)(value33 + 8);
            y_f97b2 = y_ret6;
            carry_f97b2 = value33 + 8 > 0xFFFF;
            overflow_f97b2 = ((value33 ^ (uint16_t)(value33 + 8)) & ((uint16_t)(value33 + 8) ^ 8) & 0x8000) != 0;
            data_bank_f97b2 = db_ret3;
            goto shared_F97B_1;
        }
        direct_page_f9a52 = direct_page_f97b2;
        data_bank_f9a52 = db_ret3;
        goto shared_F9A5_1;
    }
}
SOM_REGISTER(0xDCF92B, SOM_RTS, "gen", initialize_spell_family_two, 0, 0, 13, 0, 0, 134, 65)
