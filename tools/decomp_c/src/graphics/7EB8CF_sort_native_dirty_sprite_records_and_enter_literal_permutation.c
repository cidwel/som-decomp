#include "som_c.h"

/* 7EB8CF sort_native_dirty_sprite_records_and_enter_literal_permutation   [class B, 122 bytes, 67 instructions]
 * Source: src/boot/sort_native_dirty_sprite_records_and_enter_literal_permutation.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void sort_native_dirty_sprite_records_and_enter_literal_permutation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    uint8_t value = RAM8(0x102D0);
    bool m_flag2;
    bool x_flag2;
    uint16_t x4;
    uint16_t y3;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value == 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        x4 = x;
        y3 = y;
        data_bank2 = 0x7F;
        direct_page2 = (uint16_t)(sp0 - 9);
    } else {
        RAM8(0x102D0) = 0;
        r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 0;
        r->x = 0x0100;
        r->c = (uint16_t)(sp0 - 3) >= 6;
        r->z = 1;
        r->n = 0;
        r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
        r->db = 0x7F;
        r->dp = (uint16_t)(sp0 - 9);
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB8F0, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xB8F0); } /* allocate_and_fill_bytes */
        r->sp += 10;
        bool m_ret = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool m_flag;
        bool x_flag;
        uint16_t x3;
        uint16_t y2;
        uint8_t data_bank;
        uint16_t direct_page;
        if (x_ret == 0) {
            m_flag = m_ret;
            x_flag = 0;
            x3 = x_ret;
            y2 = y_ret;
            data_bank = 0x7F;
            direct_page = (uint16_t)(sp0 - 9);
        } else {
            RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x_ret);
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), 0x20);
            uint16_t value2 = RAM16(0x102C8);
            uint8_t a_hi1 = 0;
            uint16_t x1 = value2;
            do {
                uint16_t value3 = BUS16(c, 0x7F000A + x1);
                BUS16_SET(c, 0x7F0000 + (uint16_t)((value3 >> 2) + RAM16(0x0003 + (uint16_t)(sp0 - 9))), x1);
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 9)) - 1));
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x10);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
            } while (RAM16(0x0001 + (uint16_t)(sp0 - 9)) != 0);
            uint16_t value5 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
            RAM8(0x0001 + (uint16_t)(sp0 - 9)) = 0x80;
            uint8_t a_hi2 = a_hi1;
            uint16_t x2 = (uint16_t)(value5 - 2);
            uint16_t y1 = 0;
            bool carry1 = 0;
            bool overflow1 = 0;
            for (;;) {
                uint16_t value6 = BUS16(c, 0x7F0000 + (uint16_t)(x2 + 2));
                if (value6 == 0) {
                    x2 = (uint16_t)(x2 + 2);
                    y1 = value6;
                    continue;
                }
                uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                BUS8_SET(c, 0x7F0009 + value6, (uint8_t)(value7 - 4));
                RAM8(0x0001 + (uint16_t)(sp0 - 9)) = (uint8_t)(value7 - 4);
                x2 = (uint16_t)(x2 + 2);
                y1 = value6;
                carry1 = value7 >= 4;
                overflow1 = ((value7 ^ 4) & (value7 ^ (uint8_t)(value7 - 4)) & 0x80) != 0;
                if (!((uint8_t)(value7 - 4) != 0)) break;
            }
            uint16_t value8 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
            r->a = (a_hi2 << 8) | a;
            r->x = value8;
            r->y = y1;
            r->c = carry1;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB939, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB939); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 10;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB93C, 0x7EB840); GUARD_JSR(c, sp_call, 0xB93C); } /* begin_and_repeat_native_sprite_permutation_with_shared_counter */
            r->sp += 10;
            bool m_ret3 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            m_flag = m_ret3;
            x_flag = x_ret4;
            x3 = x_ret5;
            y2 = y_ret2;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        x4 = x3;
        y3 = y2;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value9 = RAM8(0x0000 + sp0 - 9);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->x = x4;
    r->y = y3;
    r->c = value10 & 0x01;
    r->z = ((value12 << 8) | value11) == 0;
    r->n = ((value12 << 8) | value11) & 0x8000;
    r->v = value10 & 0x40;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value9;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB8CF, SOM_RTS, "gen", sort_native_dirty_sprite_records_and_enter_literal_permutation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 11, 1, 0, 122, 67)
