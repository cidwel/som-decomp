#include "som_c.h"

/* 7E9793 publish_nine_native_title_particle_sprites_from_frame_offsets   [class B, 92 bytes, 45 instructions]
 * Source: src/boot/publish_nine_native_title_particle_sprites_from_frame_offsets.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: Y.
 */
static void publish_nine_native_title_particle_sprites_from_frame_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_97aa = 0;
    uint16_t x_97aa = 0;
    uint16_t y_97aa = 0;
    uint16_t direct_page_97aa = 0;
    uint8_t data_bank_97aa = 0;
    uint8_t a_hi_97aa2 = 0;
    uint8_t x_97aa2 = 0;
    uint8_t y_97aa2 = 0;
    uint16_t direct_page_97aa2 = 0;
    uint8_t data_bank_97aa2 = 0;
    uint8_t a_hi_97aa3 = 0;
    uint8_t x_97aa3 = 0;
    uint8_t y_97aa3 = 0;
    uint16_t direct_page_97aa3 = 0;
    uint8_t data_bank_97aa3 = 0;
    uint8_t a_hi_97aa4 = 0;
    uint16_t x_97aa4 = 0;
    uint16_t y_97aa4 = 0;
    uint16_t direct_page_97aa4 = 0;
    uint8_t data_bank_97aa4 = 0;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 1));
    uint16_t value2 = RAM16(0x5F26 + ((value & 0xFF) << 1));
    BUS16_SET(c, (uint16_t)(dp + 0x20), 9);
    a_hi_97aa = 0;
    x_97aa = 0;
    y_97aa = value2;
    direct_page_97aa = dp;
    data_bank_97aa = 0x7F;
    shared_97AA:;
    BUS16_SET(c, (uint16_t)(direct_page_97aa + 0x22), x_97aa);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page_97aa + 0x0C + x_97aa));
    uint16_t value4 = RAM16(0x5F26 + y_97aa);
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page_97aa + 7));
    BUS16_SET(c, (data_bank_97aa << 0x10) + 2 + value3, (uint16_t)((value4 & 0x3F) + value5));
    uint8_t value6 = RAM8(0x5F26 + y_97aa);
    uint8_t value7 = RAM8(0x5F26 + (uint16_t)(y_97aa + 1));
    uint8_t value8 = BUS8_RDP(c, direct_page_97aa);
    BUS8_SET(c, (data_bank_97aa << 0x10) + value3, (value6 ^ value7 ^ value8) & 0xC0);
    uint16_t value9 = RAM16(0x5F26 + (uint16_t)(y_97aa + 1));
    uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page_97aa + 0x0A));
    BUS16_SET(c, (data_bank_97aa << 0x10) + 4 + value3, (uint16_t)((value9 & 0x3F) + value10));
    RAM8(0x0000 + sp0 - 1) = (uint16_t)(y_97aa + 2) >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)(y_97aa + 2);
    r->a = (uint16_t)((value9 & 0x3F) + value10);
    r->x = value3;
    r->y = value3;
    r->c = (value9 & 0x3F) + value10 > 0xFFFF;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->v = (((value9 & 0x3F) ^ (uint16_t)((value9 & 0x3F) + value10)) & (value10 ^ (uint16_t)((value9 & 0x3F) + value10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_97aa;
    r->dp = direct_page_97aa;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x97E3); } /* publish_native_sprite_record_with_data_bank_7f */
    r->sp += 3;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value17 = RAM8(0x0000 + sp0 - 2);
        uint8_t value18 = RAM8(0x0000 + sp0 - 1);
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x22));
        if (m_ret) {
            uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x20));
            BUS8_SET(c, (uint16_t)(dp_ret + 0x20), (uint8_t)(value20 - 1));
            if ((uint8_t)(value20 - 1) != 0) {
                a_hi_97aa4 = a_all >> 8;
                x_97aa4 = (uint16_t)(value19 + 2);
                y_97aa4 = (value18 << 8) | value17;
                direct_page_97aa4 = dp_ret;
                data_bank_97aa4 = db_ret;
                goto shared_97AA_3;
            }
            uint8_t value21 = RAM8(0x0000 + sp0);
            r->y = (value18 << 8) | value17;
            r->mf = value21 & 0x20;
            r->xf = value21 & 0x10;
            r->i = value21 & 0x04;
            r->d = value21 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x20));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 0x20), (uint16_t)(value22 - 1));
            if ((uint16_t)(value22 - 1) != 0) {
                a_hi_97aa = a_all >> 8;
                x_97aa = (uint16_t)(value19 + 2);
                y_97aa = (value18 << 8) | value17;
                direct_page_97aa = dp_ret;
                data_bank_97aa = db_ret;
                goto shared_97AA;
            }
            uint8_t value23 = RAM8(0x0000 + sp0);
            r->y = (value18 << 8) | value17;
            r->mf = value23 & 0x20;
            r->xf = value23 & 0x10;
            r->i = value23 & 0x04;
            r->d = value23 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    shared_97AA_1:;
    BUS8_SET(c, (uint16_t)(direct_page_97aa2 + 0x22), x_97aa2);
    uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_97aa2 + 0x0C + x_97aa2));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_97AA_2:;
    BUS8_SET(c, (uint16_t)(direct_page_97aa3 + 0x22), x_97aa3);
    uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page_97aa3 + 0x0C + x_97aa3));
    uint16_t value27 = RAM16(0x5F26 + y_97aa3);
    uint16_t value28 = BUS16_RDP(c, (uint16_t)(direct_page_97aa3 + 7));
    BUS16_SET(c, (data_bank_97aa3 << 0x10) + 2 + (uint8_t)value26, (uint16_t)((value27 & 0x3F) + value28));
    uint8_t value29 = RAM8(0x5F26 + y_97aa3);
    uint8_t value30 = RAM8(0x5F26 + (uint8_t)(y_97aa3 + 1));
    uint8_t value31 = BUS8_RDP(c, direct_page_97aa3);
    BUS8_SET(c, (data_bank_97aa3 << 0x10) + (uint8_t)value26, (value29 ^ value30 ^ value31) & 0xC0);
    uint16_t value32 = RAM16(0x5F26 + (uint8_t)(y_97aa3 + 1));
    uint16_t value33 = BUS16_RDP(c, (uint16_t)(direct_page_97aa3 + 0x0A));
    BUS16_SET(c, (data_bank_97aa3 << 0x10) + 4 + (uint8_t)value26, (uint16_t)((value32 & 0x3F) + value33));
    RAM8(0x0000 + sp0 - 2) = (uint8_t)(y_97aa3 + 2);
    r->a = (uint16_t)((value32 & 0x3F) + value33);
    r->x = (uint8_t)value26;
    r->y = (uint8_t)value26;
    r->c = (value32 & 0x3F) + value33 > 0xFFFF;
    r->z = (uint8_t)value26 == 0;
    r->n = (uint8_t)value26 & 0x80;
    r->v = (((value32 & 0x3F) ^ (uint16_t)((value32 & 0x3F) + value33)) & (value33 ^ (uint16_t)((value32 & 0x3F) + value33)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_97aa3;
    r->dp = direct_page_97aa3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x97E3); } /* publish_native_sprite_record_with_data_bank_7f */
    r->sp += 3;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    if (x_ret3) {
        c->fail = 3;
        return;
    } else {
        uint8_t value40 = RAM8(0x0000 + sp0 - 2);
        uint8_t value41 = RAM8(0x0000 + sp0 - 1);
        uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x22));
        if (m_ret2) {
            uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x20));
            BUS8_SET(c, (uint16_t)(dp_ret2 + 0x20), (uint8_t)(value43 - 1));
            if ((uint8_t)(value43 - 1) != 0) {
                a_hi_97aa4 = a_all2 >> 8;
                x_97aa4 = (uint16_t)(value42 + 2);
                y_97aa4 = (value41 << 8) | value40;
                direct_page_97aa4 = dp_ret2;
                data_bank_97aa4 = db_ret2;
                goto shared_97AA_3;
            }
            uint8_t value44 = RAM8(0x0000 + sp0);
            r->y = (value41 << 8) | value40;
            r->mf = value44 & 0x20;
            r->xf = value44 & 0x10;
            r->i = value44 & 0x04;
            r->d = value44 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x20));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 0x20), (uint16_t)(value45 - 1));
            if ((uint16_t)(value45 - 1) != 0) {
                a_hi_97aa = a_all2 >> 8;
                x_97aa = (uint16_t)(value42 + 2);
                y_97aa = (value41 << 8) | value40;
                direct_page_97aa = dp_ret2;
                data_bank_97aa = db_ret2;
                goto shared_97AA;
            }
            uint8_t value46 = RAM8(0x0000 + sp0);
            r->y = (value41 << 8) | value40;
            r->mf = value46 & 0x20;
            r->xf = value46 & 0x10;
            r->i = value46 & 0x04;
            r->d = value46 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    shared_97AA_3:;
    BUS16_SET(c, (uint16_t)(direct_page_97aa4 + 0x22), x_97aa4);
    uint8_t value47 = BUS8_RDP(c, (uint16_t)(direct_page_97aa4 + 0x0C + x_97aa4));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7E9793, SOM_RTS, "gen", publish_nine_native_title_particle_sprites_from_frame_offsets, 0, L_Y, 3, 1, 0, 92, 45)
