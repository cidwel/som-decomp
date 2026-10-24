#include "som_c.h"

/* C013A0 advance_dialogue_tile_progress_or_complete_line   [class B, 93 bytes, 39 instructions]
 * Source: src/rom/advance_dialogue_tile_progress_or_complete_line.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_dialogue_tile_progress_or_complete_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    { const uint16_t sp_call = r->sp; JSR(c, 0x13A2, 0xC013FD); GUARD_JSR(c, sp_call, 0x13A2); } /* publish_dialogue_tile_pair_and_advance_cursor */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    bool overflow_ret = r->v;
    RAM8(0xA181)++;
    RAM8(0xA1D0)++;
    uint8_t value = RAM8(0xA16A);
    uint8_t value2 = RAM8(0xA181);
    bool m_flag3;
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x3;
    bool carry3;
    bool overflow3;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if (value == value2) {
        RAM8(0x1D00) |= 1;
        RAM8(0xA17D) = RAM8(0xA197);
        RAM8(0xA17C) = (uint8_t)(RAM8(0xA17C) + 2);
        RAM8(0xA15D)++;
        uint16_t value6 = RAM16(0xA17E);
        RAM16_SET(0xA18C, (uint16_t)((uint16_t)(value6 << 3) + 0x4000));
        r->a = (uint16_t)((uint16_t)(value6 << 3) + 0x4000);
        r->c = (uint16_t)(value6 << 3) + 0x4000 > 0xFFFF;
        r->z = (uint16_t)((uint16_t)(value6 << 3) + 0x4000) == 0;
        r->n = (uint16_t)((uint16_t)(value6 << 3) + 0x4000) & 0x8000;
        r->v = (((uint16_t)(value6 << 3) ^ (uint16_t)((uint16_t)(value6 << 3) + 0x4000)) & ((uint16_t)((uint16_t)(value6 << 3) + 0x4000) ^ 0x4000) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x13FB, 0xC0197C); GUARD_JSR(c, sp_call, 0x13FB); } /* external */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        bool carry_ret2 = r->c;
        m_flag3 = m_ret;
        x_flag3 = x_ret3;
        a_hi3 = a_all2 >> 8;
        x3 = x_ret4;
        carry3 = carry_ret2;
        overflow3 = (((uint16_t)(value6 << 3) ^ (uint16_t)((uint16_t)(value6 << 3) + 0x4000)) & ((uint16_t)((uint16_t)(value6 << 3) + 0x4000) ^ 0x4000) & 0x8000) != 0;
        data_bank3 = db_ret;
        direct_page3 = dp_ret;
    } else {
        uint8_t value7 = RAM8(0xA1CE);
        bool m_flag2;
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t x2;
        bool carry2;
        bool overflow2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if ((value7 & 0x80) == 0) {
            uint8_t value8 = RAM8(0xA1D0);
            if ((value7 & 0x7F) == value8) {
                RAM8(0xA15D)++;
            }
            m_flag2 = 1;
            x_flag2 = x_ret;
            a_hi2 = a_all >> 8;
            x2 = x_ret2;
            carry2 = (value7 & 0x7F) >= value8;
            overflow2 = overflow_ret;
            data_bank2 = 0x7E;
            direct_page2 = 0;
        } else {
            uint8_t value9 = RAM8(0xA1D0);
            bool m_flag;
            bool x_flag;
            uint8_t a_hi1;
            uint16_t x1;
            bool carry1;
            bool overflow1;
            uint8_t data_bank;
            uint16_t direct_page;
            if ((value7 & 0x7F) == value9) {
                RAM8(0x1D00) |= 1;
                RAM8(0xA17D) = RAM8(0xA197);
                RAM8(0xA17C) = (uint8_t)(RAM8(0xA17C) + 2);
                RAM8(0xA15D)++;
                uint16_t value13 = RAM16(0xA17E);
                RAM16_SET(0xA18C, (uint16_t)((uint16_t)(value13 << 3) + 0x4000));
                r->a = (uint16_t)((uint16_t)(value13 << 3) + 0x4000);
                r->c = (uint16_t)(value13 << 3) + 0x4000 > 0xFFFF;
                r->z = (uint16_t)((uint16_t)(value13 << 3) + 0x4000) == 0;
                r->n = (uint16_t)((uint16_t)(value13 << 3) + 0x4000) & 0x8000;
                r->v = (((uint16_t)(value13 << 3) ^ (uint16_t)((uint16_t)(value13 << 3) + 0x4000)) & ((uint16_t)((uint16_t)(value13 << 3) + 0x4000) ^ 0x4000) & 0x8000) != 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x13FB, 0xC0197C); GUARD_JSR(c, sp_call, 0x13FB); } /* external */
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t x_ret6 = r->x;
                bool carry_ret3 = r->c;
                m_flag = m_ret2;
                x_flag = x_ret5;
                a_hi1 = a_all3 >> 8;
                x1 = x_ret6;
                carry1 = carry_ret3;
                overflow1 = (((uint16_t)(value13 << 3) ^ (uint16_t)((uint16_t)(value13 << 3) + 0x4000)) & ((uint16_t)((uint16_t)(value13 << 3) + 0x4000) ^ 0x4000) & 0x8000) != 0;
                data_bank = db_ret2;
                direct_page = dp_ret2;
            } else {
                m_flag = 1;
                x_flag = x_ret;
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                carry1 = (value7 & 0x7F) >= value9;
                overflow1 = overflow_ret;
                data_bank = 0x7E;
                direct_page = 0;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            x2 = x1;
            carry2 = carry1;
            overflow2 = overflow1;
            data_bank2 = data_bank;
            direct_page2 = direct_page;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x3 = x2;
        carry3 = carry2;
        overflow3 = overflow2;
        data_bank3 = data_bank2;
        direct_page3 = direct_page2;
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x3;
    r->c = carry3;
    r->v = overflow3;
    r->mf = m_flag3;
    r->xf = x_flag3;
    r->db = data_bank3;
    r->dp = direct_page3;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC013A0, SOM_RTS, "gen", advance_dialogue_tile_progress_or_complete_line, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 93, 39)
