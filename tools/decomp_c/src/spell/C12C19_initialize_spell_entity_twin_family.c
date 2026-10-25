#include "som_c.h"

/* C12C19 initialize_spell_entity_twin_family   [class B, 174 bytes, 84 instructions]
 * Source: src/rom/initialize_spell_entity_twin_family.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: nothing.
 */
static void initialize_spell_entity_twin_family(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0xA > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_2c5d = 0;
    uint16_t x_2c5d = 0;
    uint16_t y_2c5d = 0;
    bool carry_2c5d = 0;
    bool zero_2c5d = 0;
    bool negative_2c5d = 0;
    bool overflow_2c5d = 0;
    uint16_t direct_page_2c5d = 0;
    uint8_t a_hi_2c8b = 0;
    uint8_t x_2c8b = 0;
    uint8_t y_2c8b = 0;
    bool overflow_2c8b = 0;
    uint16_t direct_page_2c8b = 0;
    uint8_t data_bank_2c8b = 0;
    uint8_t a_hi_2c8b2 = 0;
    uint16_t x_2c8b2 = 0;
    uint16_t y_2c8b2 = 0;
    bool overflow_2c8b2 = 0;
    uint16_t direct_page_2c8b2 = 0;
    uint8_t data_bank_2c8b2 = 0;
    uint8_t a_2c96 = 0;
    uint8_t a_hi_2c96 = 0;
    uint8_t y_2c96 = 0;
    bool carry_2c96 = 0;
    bool overflow_2c96 = 0;
    uint16_t direct_page_2c96 = 0;
    uint8_t data_bank_2c96 = 0;
    uint8_t a_2c962 = 0;
    uint8_t a_hi_2c962 = 0;
    uint16_t y_2c962 = 0;
    bool carry_2c962 = 0;
    bool overflow_2c962 = 0;
    uint16_t direct_page_2c962 = 0;
    uint8_t data_bank_2c962 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xCC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0D), y);
    RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = 0;
    RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = 0xFF;
    uint8_t value = RAM8(0x0025 + y);
    if (value == 1) {
        a_hi_2c5d = (uint16_t)(sp0 - 0x0D) >> 8;
        x_2c5d = 0xFAFD;
        y_2c5d = y;
        carry_2c5d = value >= 1;
        zero_2c5d = value == 1;
        negative_2c5d = (uint8_t)(value - 1) & 0x80;
        overflow_2c5d = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
        direct_page_2c5d = (uint16_t)(sp0 - 0x0D);
        goto shared_2C5D;
    }
    if (value == 3) {
        a_hi_2c5d = (uint16_t)(sp0 - 0x0D) >> 8;
        x_2c5d = 0xFB0D;
        y_2c5d = y;
        carry_2c5d = value >= 3;
        zero_2c5d = value == 3;
        negative_2c5d = (uint8_t)(value - 3) & 0x80;
        overflow_2c5d = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
        direct_page_2c5d = (uint16_t)(sp0 - 0x0D);
        goto shared_2C5D;
    }
    if (RAM8(0x002C + y) == 0) {
        RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = 1;
        uint8_t value3 = RAM8(0x0029 + y);
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = (value3 & 0x1E) >> 1;
        a_hi_2c5d = (uint16_t)(sp0 - 0x0D) >> 8;
        x_2c5d = 0xFB1D;
        y_2c5d = y;
        carry_2c5d = value3 & 0x1E & 0x01;
        zero_2c5d = 0;
        negative_2c5d = 1;
        overflow_2c5d = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
        direct_page_2c5d = (uint16_t)(sp0 - 0x0D);
        goto shared_2C5D;
    }
    a_hi_2c5d = (uint16_t)(sp0 - 0x0D) >> 8;
    x_2c5d = 0xFB2D;
    y_2c5d = y;
    carry_2c5d = value >= 3;
    zero_2c5d = 0;
    negative_2c5d = 1;
    overflow_2c5d = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    direct_page_2c5d = (uint16_t)(sp0 - 0x0D);
    shared_2C5D:;
    LOOP_GUARD(loop_guard);
    r->x = x_2c5d;
    r->y = y_2c5d;
    r->c = carry_2c5d;
    r->z = zero_2c5d;
    r->n = negative_2c5d;
    r->v = overflow_2c5d;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_2c5d;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2C60, 0xC12E90); GUARD_JSL(c, sp_call, 0x2C60); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 14;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    bool overflow_ret = r->v;
    if (x_ret) {
        BUS8_SET(c, (uint16_t)(direct_page_2c5d + 7), (uint8_t)x_ret2);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page_2c5d + 2));
        if (m_ret) {
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(direct_page_2c5d + 0x0A));
            RAM8(0x002C + value4) = value5;
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page_2c5d + 2));
            RAM16_SET(0x001A + value6, (uint8_t)x_ret2);
            RAM16_SET(0x002A + value6, 0);
            RAM16_SET(0x001C + value6, 0x3711);
            RAM16_SET(0x001E + value6, 0x345A);
            BUS8_SET(c, (uint16_t)(direct_page_2c5d + 1), RAM8(0x0027 + value6));
            a_hi_2c8b = 0x34;
            x_2c8b = value6;
            y_2c8b = value4;
            overflow_2c8b = overflow_ret;
            direct_page_2c8b = direct_page_2c5d;
            data_bank_2c8b = 0x7E;
            goto shared_2C8B;
        } else {
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(direct_page_2c5d + 0x0A));
            RAM16_SET(0x002C + value4, value8);
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(direct_page_2c5d + 2));
            RAM16_SET(0x001A + value9, (uint8_t)x_ret2);
            RAM16_SET(0x002A + value9, 0);
            RAM16_SET(0x001C + value9, 0x3711);
            RAM16_SET(0x001E + value9, 0x345A);
            BUS8_SET(c, (uint16_t)(direct_page_2c5d + 1), RAM8(0x0027 + value9));
            a_hi_2c8b = 0x34;
            x_2c8b = value9;
            y_2c8b = value4;
            overflow_2c8b = overflow_ret;
            direct_page_2c8b = direct_page_2c5d;
            data_bank_2c8b = 0x7E;
            goto shared_2C8B;
        }
    } else {
        BUS16_SET(c, (uint16_t)(direct_page_2c5d + 7), x_ret2);
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page_2c5d + 2));
        if (m_ret) {
            uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page_2c5d + 0x0A));
            RAM8(0x002C + value11) = value12;
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page_2c5d + 2));
            RAM16_SET(0x001A + value13, x_ret2);
            RAM16_SET(0x002A + value13, 0);
            RAM16_SET(0x001C + value13, 0x3711);
            RAM16_SET(0x001E + value13, 0x345A);
            BUS8_SET(c, (uint16_t)(direct_page_2c5d + 1), RAM8(0x0027 + value13));
            a_hi_2c8b2 = 0x34;
            x_2c8b2 = value13;
            y_2c8b2 = value11;
            overflow_2c8b2 = overflow_ret;
            direct_page_2c8b2 = direct_page_2c5d;
            data_bank_2c8b2 = 0x7E;
            goto shared_2C8B_1;
        } else {
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_2c5d + 0x0A));
            RAM16_SET(0x002C + value11, value15);
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_2c5d + 2));
            RAM16_SET(0x001A + value16, x_ret2);
            RAM16_SET(0x002A + value16, 0);
            RAM16_SET(0x001C + value16, 0x3711);
            RAM16_SET(0x001E + value16, 0x345A);
            BUS8_SET(c, (uint16_t)(direct_page_2c5d + 1), RAM8(0x0027 + value16));
            a_hi_2c8b2 = 0x34;
            x_2c8b2 = value16;
            y_2c8b2 = value11;
            overflow_2c8b2 = overflow_ret;
            direct_page_2c8b2 = direct_page_2c5d;
            data_bank_2c8b2 = 0x7E;
            goto shared_2C8B_1;
        }
    }
    shared_2C8B:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (uint16_t)(direct_page_2c8b + 4), x_2c8b);
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page_2c8b + 9));
    if (value18 != 0xFF) {
        a_2c96 = value18;
        a_hi_2c96 = a_hi_2c8b;
        y_2c96 = y_2c8b;
        carry_2c96 = value18 >= 0xFF;
        overflow_2c96 = overflow_2c8b;
        direct_page_2c96 = direct_page_2c8b;
        data_bank_2c96 = data_bank_2c8b;
        goto shared_2C96;
    }
    uint8_t value19 = BUS8_RDP(c, (data_bank_2c8b << 0x10) + x_2c8b);
    a_2c96 = value19;
    a_hi_2c96 = a_hi_2c8b;
    y_2c96 = y_2c8b;
    carry_2c96 = value18 >= 0xFF;
    overflow_2c96 = overflow_2c8b;
    direct_page_2c96 = direct_page_2c8b;
    data_bank_2c96 = data_bank_2c8b;
    goto shared_2C96;
    shared_2C8B_1:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(direct_page_2c8b2 + 4), x_2c8b2);
    uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page_2c8b2 + 9));
    if (value20 != 0xFF) {
        a_2c962 = value20;
        a_hi_2c962 = a_hi_2c8b2;
        y_2c962 = y_2c8b2;
        carry_2c962 = value20 >= 0xFF;
        overflow_2c962 = overflow_2c8b2;
        direct_page_2c962 = direct_page_2c8b2;
        data_bank_2c962 = data_bank_2c8b2;
        goto shared_2C96_1;
    }
    uint8_t value21 = BUS8_RDP(c, (data_bank_2c8b2 << 0x10) + x_2c8b2);
    a_2c962 = value21;
    a_hi_2c962 = a_hi_2c8b2;
    y_2c962 = y_2c8b2;
    carry_2c962 = value20 >= 0xFF;
    overflow_2c962 = overflow_2c8b2;
    direct_page_2c962 = direct_page_2c8b2;
    data_bank_2c962 = data_bank_2c8b2;
    goto shared_2C96_1;
    shared_2C96:;
    LOOP_GUARD(loop_guard);
    uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_2c96 + 7));
    r->a = (a_hi_2c96 << 8) | a_2c96;
    r->x = value22;
    r->y = y_2c96;
    r->c = carry_2c96;
    r->z = value22 == 0;
    r->n = value22 & 0x80;
    r->v = overflow_2c96;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_2c96;
    r->dp = direct_page_2c96;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2C9A, 0xC12CC7); GUARD_JSR(c, sp_call, 0x2C9A); } /* construct_spell_entity_twin_sprite_object */
    r->sp += 14;
    uint8_t db_ret = r->db;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    if (x_ret3) {
        uint8_t value23 = BUS8_RDP(c, (uint16_t)(direct_page_2c96 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value23, (uint8_t)x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value23, 0x2C10);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value23, 0x2C0B);
        uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_2c96 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_2c96 + 1), (uint8_t)(value24 - 1));
        if ((uint8_t)(value24 - 1) != 0) {
            a_hi_2c8b = value23 + 8 >> 8;
            x_2c8b = (uint8_t)(value23 + 8);
            y_2c8b = (uint8_t)y_ret2;
            overflow_2c8b = ((value23 ^ value23 + 8) & (value23 + 8 ^ 8) & 0x8000) != 0;
            direct_page_2c8b = direct_page_2c96;
            data_bank_2c8b = db_ret;
            goto shared_2C8B;
        }
        uint8_t value25 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value26 = RAM8(0x0000 + sp0 - 2);
        uint8_t value27 = RAM8(0x0000 + sp0 - 1);
        uint8_t value28 = RAM8(0x0000 + sp0);
        r->mf = value26 & 0x20;
        r->xf = value26 & 0x10;
        r->db = value25;
        r->dp = (value28 << 8) | value27;
        r->i = value26 & 0x04;
        r->d = value26 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value29 = BUS16_RDP(c, (uint16_t)(direct_page_2c96 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value29, x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value29, 0x2C10);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value29, 0x2C0B);
        uint8_t value30 = BUS8_RDP(c, (uint16_t)(direct_page_2c96 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_2c96 + 1), (uint8_t)(value30 - 1));
        if ((uint8_t)(value30 - 1) != 0) {
            a_hi_2c8b2 = (uint16_t)(value29 + 8) >> 8;
            x_2c8b2 = (uint16_t)(value29 + 8);
            y_2c8b2 = y_ret2;
            overflow_2c8b2 = ((value29 ^ (uint16_t)(value29 + 8)) & ((uint16_t)(value29 + 8) ^ 8) & 0x8000) != 0;
            direct_page_2c8b2 = direct_page_2c96;
            data_bank_2c8b2 = db_ret;
            goto shared_2C8B_1;
        }
        uint8_t value31 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value32 = RAM8(0x0000 + sp0 - 2);
        uint8_t value33 = RAM8(0x0000 + sp0 - 1);
        uint8_t value34 = RAM8(0x0000 + sp0);
        r->mf = value32 & 0x20;
        r->xf = value32 & 0x10;
        r->db = value31;
        r->dp = (value34 << 8) | value33;
        r->i = value32 & 0x04;
        r->d = value32 & 0x08;
        RETURN_RTS(c);
    }
    shared_2C96_1:;
    LOOP_GUARD(loop_guard);
    uint16_t value35 = BUS16_RDP(c, (uint16_t)(direct_page_2c962 + 7));
    r->a = (a_hi_2c962 << 8) | a_2c962;
    r->x = value35;
    r->y = y_2c962;
    r->c = carry_2c962;
    r->z = value35 == 0;
    r->n = value35 & 0x8000;
    r->v = overflow_2c962;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_2c962;
    r->dp = direct_page_2c962;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2C9A, 0xC12CC7); GUARD_JSR(c, sp_call, 0x2C9A); } /* construct_spell_entity_twin_sprite_object */
    r->sp += 14;
    uint8_t db_ret2 = r->db;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    if (x_ret5) {
        uint8_t value36 = BUS8_RDP(c, (uint16_t)(direct_page_2c962 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value36, (uint8_t)x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value36, 0x2C10);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value36, 0x2C0B);
        uint8_t value37 = BUS8_RDP(c, (uint16_t)(direct_page_2c962 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_2c962 + 1), (uint8_t)(value37 - 1));
        if ((uint8_t)(value37 - 1) != 0) {
            a_hi_2c8b = value36 + 8 >> 8;
            x_2c8b = (uint8_t)(value36 + 8);
            y_2c8b = (uint8_t)y_ret3;
            overflow_2c8b = ((value36 ^ value36 + 8) & (value36 + 8 ^ 8) & 0x8000) != 0;
            direct_page_2c8b = direct_page_2c962;
            data_bank_2c8b = db_ret2;
            goto shared_2C8B;
        }
        uint8_t value38 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value39 = RAM8(0x0000 + sp0 - 2);
        uint8_t value40 = RAM8(0x0000 + sp0 - 1);
        uint8_t value41 = RAM8(0x0000 + sp0);
        r->mf = value39 & 0x20;
        r->xf = value39 & 0x10;
        r->db = value38;
        r->dp = (value41 << 8) | value40;
        r->i = value39 & 0x04;
        r->d = value39 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value42 = BUS16_RDP(c, (uint16_t)(direct_page_2c962 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value42, x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value42, 0x2C10);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value42, 0x2C0B);
        uint8_t value43 = BUS8_RDP(c, (uint16_t)(direct_page_2c962 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_2c962 + 1), (uint8_t)(value43 - 1));
        if ((uint8_t)(value43 - 1) != 0) {
            a_hi_2c8b2 = (uint16_t)(value42 + 8) >> 8;
            x_2c8b2 = (uint16_t)(value42 + 8);
            y_2c8b2 = y_ret3;
            overflow_2c8b2 = ((value42 ^ (uint16_t)(value42 + 8)) & ((uint16_t)(value42 + 8) ^ 8) & 0x8000) != 0;
            direct_page_2c8b2 = direct_page_2c962;
            data_bank_2c8b2 = db_ret2;
            goto shared_2C8B_1;
        }
        uint8_t value44 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value45 = RAM8(0x0000 + sp0 - 2);
        uint8_t value46 = RAM8(0x0000 + sp0 - 1);
        uint8_t value47 = RAM8(0x0000 + sp0);
        r->mf = value45 & 0x20;
        r->xf = value45 & 0x10;
        r->db = value44;
        r->dp = (value47 << 8) | value46;
        r->i = value45 & 0x04;
        r->d = value45 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC12C19, SOM_RTS, "gen", initialize_spell_entity_twin_family, 0, 0, 15, 0, 0, 174, 84)
