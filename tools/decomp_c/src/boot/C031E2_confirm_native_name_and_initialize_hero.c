#include "som_c.h"

/* C031E2 confirm_native_name_and_initialize_hero   [class B, 46 bytes, 18 instructions]
 * Source: src/rom/confirm_native_name_and_initialize_hero.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void confirm_native_name_and_initialize_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x31E4, 0xC03269); GUARD_JSR(c, sp_call, 0x31E4); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t value = RAM8(0xA204 + x_ret);
    bool m_flag3;
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero3;
    bool negative3;
    bool overflow3;
    uint8_t data_bank3;
    uint16_t direct_page2;
    if ((value & 0x10) != 0) {
        m_flag3 = 1;
        x_flag3 = 0;
        a3 = value & 0x10;
        a_hi3 = a_all >> 8;
        x3 = x_ret;
        y3 = y;
        carry3 = carry_ret;
        zero3 = (value & 0x10) == 0;
        negative3 = value & 0x10 & 0x80;
        overflow3 = overflow;
        data_bank3 = 0x7E;
        direct_page2 = 0;
    } else {
        uint8_t value2 = RAM8(0xA1CC);
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero2;
        bool negative2;
        bool overflow2;
        uint8_t data_bank2;
        uint16_t direct_page;
        if (value2 == 0) {
            r->a = (a_all >> 8 << 8) | 3;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x320E, 0xC029D2); GUARD_JSR(c, sp_call, 0x320E); } /* expand_local_audio_preset_and_send_four_byte_request */
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            bool overflow_ret = r->v;
            m_flag2 = m_ret;
            x_flag2 = x_ret2;
            a2 = (uint8_t)a_all2;
            a_hi2 = a_all2 >> 8;
            x2 = x_ret3;
            y2 = y_ret;
            carry2 = carry_ret2;
            zero2 = zero_ret2;
            negative2 = negative_ret2;
            overflow2 = overflow_ret;
            data_bank2 = db_ret;
            direct_page = 0;
        } else {
            r->a = (a_all >> 8 << 8) | value2;
            r->z = value2 == 0;
            r->n = value2 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x31F4, 0xC7507F); GUARD_JSL(c, sp_call, 0x31F4); } /* store_entered_hero_name_and_initialize_party_record */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret2 = r->db;
            { const uint16_t sp_call = r->sp; JSL(c, 0x31F8, 0xC75162); GUARD_JSL(c, sp_call, 0x31F8); } /* compare_native_name_against_other_party_members */
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all4 = r->a;
            uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA171);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow1;
            uint8_t data_bank;
            if (value3 == 0) {
                r->a = (a_all4 >> 8 << 8) | 3;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x320E, 0xC029D2); GUARD_JSR(c, sp_call, 0x320E); } /* expand_local_audio_preset_and_send_four_byte_request */
                uint8_t db_ret3 = r->db;
                bool m_ret3 = r->mf;
                bool x_ret8 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret9 = r->x;
                uint16_t y_ret4 = r->y;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret4 = r->v;
                m_flag = m_ret3;
                x_flag = x_ret8;
                a1 = (uint8_t)a_all5;
                a_hi1 = a_all5 >> 8;
                x1 = x_ret9;
                y1 = y_ret4;
                carry1 = carry_ret5;
                zero1 = zero_ret5;
                negative1 = negative_ret5;
                overflow1 = overflow_ret4;
                data_bank = db_ret3;
            } else {
                r->a = (a_all4 >> 8 << 8) | 7;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x3202, 0xC029D2); GUARD_JSR(c, sp_call, 0x3202); } /* expand_local_audio_preset_and_send_four_byte_request */
                uint8_t db_ret4 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret10 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t x_ret11 = r->x;
                uint16_t y_ret5 = r->y;
                bool carry_ret6 = r->c;
                bool overflow_ret5 = r->v;
                uint8_t value4 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA20A);
                BUS8_SET(c, (db_ret4 << 0x10) + 0xA20A, value4 | 1);
                m_flag = 1;
                x_flag = x_ret10;
                a1 = 1;
                a_hi1 = a_all6 >> 8;
                x1 = x_ret11;
                y1 = y_ret5;
                carry1 = carry_ret6;
                zero1 = (value4 & 1) == 0;
                negative1 = 0;
                overflow1 = overflow_ret5;
                data_bank = db_ret4;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            zero2 = zero1;
            negative2 = negative1;
            overflow2 = overflow1;
            data_bank2 = data_bank;
            direct_page = dp_ret;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero3 = zero2;
        negative3 = negative2;
        overflow3 = overflow2;
        data_bank3 = data_bank2;
        direct_page2 = direct_page;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow3;
    r->mf = m_flag3;
    r->xf = x_flag3;
    r->db = data_bank3;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC031E2, SOM_RTS, "gen", confirm_native_name_and_initialize_hero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 46, 18)
