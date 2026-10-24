#include "som_c.h"

/* D3FD43 initialize_spell_random_fallback   [class B, 122 bytes, 60 instructions]
 * Source: src/rom/initialize_spell_random_fallback.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void initialize_spell_random_fallback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_fd87 = 0;
    uint8_t x_fd87 = 0;
    uint8_t y_fd87 = 0;
    bool carry_fd87 = 0;
    bool overflow_fd87 = 0;
    uint16_t direct_page_fd87 = 0;
    uint8_t data_bank_fd87 = 0;
    uint8_t a_hi_fd872 = 0;
    uint16_t x_fd872 = 0;
    uint16_t y_fd872 = 0;
    bool carry_fd872 = 0;
    bool overflow_fd872 = 0;
    uint16_t direct_page_fd872 = 0;
    uint8_t data_bank_fd872 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM16_SET(0x8434, 1);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0B), y);
    r->a = 1;
    r->x = 0xFE72;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFD65, 0xC12E90); GUARD_JSL(c, sp_call, 0xFD65); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 12;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
        RAM16_SET(0x001A + value, (uint8_t)x_ret2);
        RAM16_SET(0x002A + value, 0);
        RAM16_SET(0x001C + value, 0x3711);
        RAM16_SET(0x001E + value, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0027 + value);
        a_hi_fd87 = 0x34;
        x_fd87 = value;
        y_fd87 = (uint8_t)y_ret;
        carry_fd87 = carry_ret;
        overflow_fd87 = overflow_ret;
        direct_page_fd87 = (uint16_t)(sp0 - 0x0B);
        data_bank_fd87 = 0x7E;
        goto shared_FD87;
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), x_ret2);
        uint16_t value3 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0B));
        RAM16_SET(0x001A + value3, x_ret2);
        RAM16_SET(0x002A + value3, 0);
        RAM16_SET(0x001C + value3, 0x3711);
        RAM16_SET(0x001E + value3, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0027 + value3);
        a_hi_fd872 = 0x34;
        x_fd872 = value3;
        y_fd872 = y_ret;
        carry_fd872 = carry_ret;
        overflow_fd872 = overflow_ret;
        direct_page_fd872 = (uint16_t)(sp0 - 0x0B);
        data_bank_fd872 = 0x7E;
        goto shared_FD87_1;
    }
    shared_FD87:;
    BUS8_SET(c, (uint16_t)(direct_page_fd87 + 4), x_fd87);
    uint8_t value5 = BUS8_RDP(c, (data_bank_fd87 << 0x10) + x_fd87);
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page_fd87 + 7));
    r->a = (a_hi_fd87 << 8) | value5;
    r->x = value6;
    r->y = y_fd87;
    r->c = carry_fd87;
    r->z = value6 == 0;
    r->n = value6 & 0x80;
    r->v = overflow_fd87;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_fd87;
    r->dp = direct_page_fd87;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD90, 0xD3FDBD); GUARD_JSR(c, sp_call, 0xFD90); } /* construct_spell_random_fallback_object */
    r->sp += 12;
    uint8_t db_ret = r->db;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    if (x_ret3) {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(direct_page_fd87 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value7, (uint8_t)x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value7, 0x481A);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value7, 0x4815);
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page_fd87 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_fd87 + 1), (uint8_t)(value8 - 1));
        if ((uint8_t)(value8 - 1) != 0) {
            a_hi_fd87 = value7 + 8 >> 8;
            x_fd87 = (uint8_t)(value7 + 8);
            y_fd87 = (uint8_t)y_ret2;
            carry_fd87 = value7 + 8 > 0xFFFF;
            overflow_fd87 = ((value7 ^ value7 + 8) & (value7 + 8 ^ 8) & 0x8000) != 0;
            data_bank_fd87 = db_ret;
            goto shared_FD87;
        }
        uint8_t value9 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->db = value9;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page_fd87 + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value13, x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value13, 0x481A);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value13, 0x4815);
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page_fd87 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_fd87 + 1), (uint8_t)(value14 - 1));
        if ((uint8_t)(value14 - 1) != 0) {
            a_hi_fd872 = (uint16_t)(value13 + 8) >> 8;
            x_fd872 = (uint16_t)(value13 + 8);
            y_fd872 = y_ret2;
            carry_fd872 = value13 + 8 > 0xFFFF;
            overflow_fd872 = ((value13 ^ (uint16_t)(value13 + 8)) & ((uint16_t)(value13 + 8) ^ 8) & 0x8000) != 0;
            direct_page_fd872 = direct_page_fd87;
            data_bank_fd872 = db_ret;
            goto shared_FD87_1;
        }
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
    }
    shared_FD87_1:;
    BUS16_SET(c, (uint16_t)(direct_page_fd872 + 4), x_fd872);
    uint8_t value19 = BUS8_RDP(c, (data_bank_fd872 << 0x10) + x_fd872);
    uint16_t value20 = BUS16_RDP(c, (uint16_t)(direct_page_fd872 + 7));
    r->a = (a_hi_fd872 << 8) | value19;
    r->x = value20;
    r->y = y_fd872;
    r->c = carry_fd872;
    r->z = value20 == 0;
    r->n = value20 & 0x8000;
    r->v = overflow_fd872;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_fd872;
    r->dp = direct_page_fd872;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD90, 0xD3FDBD); GUARD_JSR(c, sp_call, 0xFD90); } /* construct_spell_random_fallback_object */
    r->sp += 12;
    uint8_t db_ret2 = r->db;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    if (x_ret5) {
        uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page_fd872 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value21, (uint8_t)x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value21, 0x481A);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value21, 0x4815);
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_fd872 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_fd872 + 1), (uint8_t)(value22 - 1));
        if ((uint8_t)(value22 - 1) != 0) {
            a_hi_fd87 = value21 + 8 >> 8;
            x_fd87 = (uint8_t)(value21 + 8);
            y_fd87 = (uint8_t)y_ret3;
            carry_fd87 = value21 + 8 > 0xFFFF;
            overflow_fd87 = ((value21 ^ value21 + 8) & (value21 + 8 ^ 8) & 0x8000) != 0;
            direct_page_fd87 = direct_page_fd872;
            data_bank_fd87 = db_ret2;
            goto shared_FD87;
        }
        uint8_t value23 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value24 = RAM8(0x0000 + sp0 - 2);
        uint8_t value25 = RAM8(0x0000 + sp0 - 1);
        uint8_t value26 = RAM8(0x0000 + sp0);
        r->mf = value24 & 0x20;
        r->xf = value24 & 0x10;
        r->db = value23;
        r->dp = (value26 << 8) | value25;
        r->i = value24 & 0x04;
        r->d = value24 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_fd872 + 4));
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value27, x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value27, 0x481A);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value27, 0x4815);
        uint8_t value28 = BUS8_RDP(c, (uint16_t)(direct_page_fd872 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_fd872 + 1), (uint8_t)(value28 - 1));
        if ((uint8_t)(value28 - 1) != 0) {
            a_hi_fd872 = (uint16_t)(value27 + 8) >> 8;
            x_fd872 = (uint16_t)(value27 + 8);
            y_fd872 = y_ret3;
            carry_fd872 = value27 + 8 > 0xFFFF;
            overflow_fd872 = ((value27 ^ (uint16_t)(value27 + 8)) & ((uint16_t)(value27 + 8) ^ 8) & 0x8000) != 0;
            data_bank_fd872 = db_ret2;
            goto shared_FD87_1;
        }
        uint8_t value29 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value30 = RAM8(0x0000 + sp0 - 2);
        uint8_t value31 = RAM8(0x0000 + sp0 - 1);
        uint8_t value32 = RAM8(0x0000 + sp0);
        r->mf = value30 & 0x20;
        r->xf = value30 & 0x10;
        r->db = value29;
        r->dp = (value32 << 8) | value31;
        r->i = value30 & 0x04;
        r->d = value30 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3FD43, SOM_RTS, "gen", initialize_spell_random_fallback, 0, 0, 13, 1, 0, 122, 60)
