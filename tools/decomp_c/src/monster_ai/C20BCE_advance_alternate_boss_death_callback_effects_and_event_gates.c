#include "som_c.h"

/* C20BCE advance_alternate_boss_death_callback_effects_and_event_gates   [class B, 67 bytes, 29 instructions]
 * Source: src/rom/advance_alternate_boss_death_callback_effects_and_event_gates.s
 * Documented in docs/boss-native-alternate-death.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void advance_alternate_boss_death_callback_effects_and_event_gates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 >= 0x80) {
        if (((RAM16(0x00D9) | RAM16(0x00DA) | RAM16(0x00DB)) & 0x80) != 0) {
            RETURN_RTS(c);
        }
        if ((RAM16(0x1D04) & 0x20) != 0) {
            RETURN_RTS(c);
        }
        uint16_t value7 = RAM16(0x0072 + value);
        bool m_flag;
        bool x_flag;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value7 == 0) {
            m_flag = 0;
            x_flag = 0;
            data_bank = 0x7E;
            direct_page = 0x0200;
        } else {
            r->a = value7;
            r->x = value;
            r->c = value2 >= 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0C0C, 0xC20C11); GUARD_JSR(c, sp_call, 0x0C0C); } /* mark_controller_and_request_numeric_boss_death_event */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            m_flag = m_ret;
            x_flag = x_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        r->mf = m_flag;
        r->xf = x_flag;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
    bool x_flag3;
    uint8_t a_hi2;
    uint16_t y2;
    bool overflow2;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if (value2 != 8) {
        x_flag3 = 0;
        a_hi2 = value2 >> 8;
        y2 = y;
        overflow2 = overflow;
        data_bank3 = 0x7E;
        direct_page3 = 0x0200;
    } else {
        uint16_t value8 = RAM16(0x0078 + value);
        bool m_flag2;
        bool x_flag2;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if (value8 == 0) {
            m_flag2 = 0;
            x_flag2 = 0;
            a_hi1 = value8 >> 8;
            x1 = value;
            y1 = y;
            carry1 = value2 >= 8;
            overflow1 = overflow;
            data_bank2 = 0x7E;
            direct_page2 = 0x0200;
        } else {
            r->a = value8;
            r->x = value;
            r->c = value2 >= 8;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0BE4, 0xC20BC9); GUARD_JSR(c, sp_call, 0x0BE4); } /* tail_call_selected_alternate_death_callback */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            m_flag2 = m_ret2;
            x_flag2 = x_ret3;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret4;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret2;
        }
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = m_flag2;
        r->xf = x_flag2;
        r->db = data_bank2;
        r->dp = direct_page2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0BE7, 0xC23A9A); GUARD_JSR(c, sp_call, 0x0BE7); } /* create_boss_terminal_visual_effect_pair */
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool overflow_ret3 = r->v;
        x_flag3 = x_ret5;
        a_hi2 = a_all3 >> 8;
        y2 = y_ret3;
        overflow2 = overflow_ret3;
        data_bank3 = data_bank2;
        direct_page3 = direct_page2;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->y = y2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = x_flag3;
    r->db = data_bank3;
    r->dp = direct_page3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0BEA, 0xC20C89); GUARD_JSR(c, sp_call, 0x0BEA); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20BCE, SOM_RTS, "gen", advance_alternate_boss_death_callback_effects_and_event_gates, 0, 0, 1, 0, 0, 67, 29)
