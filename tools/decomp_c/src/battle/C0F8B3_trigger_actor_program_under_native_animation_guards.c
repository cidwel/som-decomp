#include "som_c.h"

/* C0F8B3 trigger_actor_program_under_native_animation_guards   [class B, 59 bytes, 26 instructions]
 * Source: src/rom/trigger_actor_program_under_native_animation_guards.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void trigger_actor_program_under_native_animation_guards(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0052);
    uint8_t value2 = RAM8(0x00FF);
    uint8_t value3 = RAM8(0x00F1);
    bool m_flag9;
    bool x_flag9;
    uint16_t x9;
    uint16_t y9;
    bool carry9;
    bool overflow9;
    uint8_t data_bank9;
    uint16_t direct_page9;
    if ((value | value2 | value3) != 0) {
        m_flag9 = 1;
        x_flag9 = 0;
        x9 = x;
        y9 = y;
        carry9 = carry;
        overflow9 = overflow;
        data_bank9 = 0x7E;
        direct_page9 = 0;
    } else {
        uint8_t value4 = RAM8(0x00E8);
        bool m_flag8;
        bool x_flag8;
        uint16_t x8;
        uint16_t y8;
        bool carry8;
        bool overflow8;
        uint8_t data_bank8;
        uint16_t direct_page8;
        if ((value4 & 4) != 0) {
            m_flag8 = 1;
            x_flag8 = 0;
            x8 = x;
            y8 = y;
            carry8 = carry;
            overflow8 = overflow;
            data_bank8 = 0x7E;
            direct_page8 = 0;
        } else {
            uint8_t value5 = RAM8(0xE000 + x);
            bool m_flag7;
            bool x_flag7;
            uint16_t x7;
            uint16_t y7;
            bool carry7;
            bool overflow7;
            uint8_t data_bank7;
            uint16_t direct_page7;
            if (value5 & 0x80) {
                m_flag7 = 1;
                x_flag7 = 0;
                x7 = x;
                y7 = y;
                carry7 = carry;
                overflow7 = overflow;
                data_bank7 = 0x7E;
                direct_page7 = 0;
            } else {
                bool m_flag6;
                bool x_flag6;
                uint16_t x6;
                uint16_t y6;
                bool carry6;
                bool overflow6;
                uint8_t data_bank6;
                uint16_t direct_page6;
                if (x >= 0x0600) {
                    uint8_t value6 = RAM8(0xE044 + x);
                    bool m_flag2;
                    bool x_flag2;
                    uint16_t x2;
                    uint16_t y2;
                    bool carry2;
                    bool overflow2;
                    uint8_t data_bank2;
                    uint16_t direct_page2;
                    if (value6 & 0x80) {
                        m_flag2 = 1;
                        x_flag2 = 0;
                        x2 = x;
                        y2 = y;
                        carry2 = x >= 0x0600;
                        overflow2 = overflow;
                        data_bank2 = 0x7E;
                        direct_page2 = 0;
                    } else {
                        uint16_t value7 = RAM16(0x003A);
                        bool m_flag;
                        bool x_flag;
                        uint16_t x1;
                        uint16_t y1;
                        bool carry1;
                        bool overflow1;
                        uint8_t data_bank;
                        uint16_t direct_page;
                        if (x == value7) {
                            m_flag = 1;
                            x_flag = 0;
                            x1 = x;
                            y1 = y;
                            carry1 = x >= value7;
                            overflow1 = overflow;
                            data_bank = 0x7E;
                            direct_page = 0;
                        } else {
                            r->a = (a_hi << 8) | value6;
                            r->c = x >= value7;
                            r->z = x == value7;
                            r->n = (uint16_t)(x - value7) & 0x8000;
                            { const uint16_t sp_call = r->sp; JSL(c, 0xF8EC, 0x01D942); GUARD_JSL(c, sp_call, 0xF8EC); } /* advance_actor_program_before_current_action_dispatch */
                            uint16_t dp_ret = r->dp;
                            uint8_t db_ret = r->db;
                            bool m_ret = r->mf;
                            bool x_ret = r->xf;
                            uint16_t x_ret2 = r->x;
                            uint16_t y_ret = r->y;
                            bool carry_ret = r->c;
                            bool overflow_ret = r->v;
                            m_flag = m_ret;
                            x_flag = x_ret;
                            x1 = x_ret2;
                            y1 = y_ret;
                            carry1 = carry_ret;
                            overflow1 = overflow_ret;
                            data_bank = db_ret;
                            direct_page = dp_ret;
                        }
                        m_flag2 = m_flag;
                        x_flag2 = x_flag;
                        x2 = x1;
                        y2 = y1;
                        carry2 = carry1;
                        overflow2 = overflow1;
                        data_bank2 = data_bank;
                        direct_page2 = direct_page;
                    }
                    m_flag6 = m_flag2;
                    x_flag6 = x_flag2;
                    x6 = x2;
                    y6 = y2;
                    carry6 = carry2;
                    overflow6 = overflow2;
                    data_bank6 = data_bank2;
                    direct_page6 = direct_page2;
                } else {
                    uint8_t value8 = RAM8(0xE00F + x);
                    bool m_flag5;
                    bool x_flag5;
                    uint16_t x5;
                    uint16_t y5;
                    bool carry5;
                    bool overflow5;
                    uint8_t data_bank5;
                    uint16_t direct_page5;
                    if (value8 != 0) {
                        m_flag5 = 1;
                        x_flag5 = 0;
                        x5 = x;
                        y5 = y;
                        carry5 = x >= 0x0600;
                        overflow5 = overflow;
                        data_bank5 = 0x7E;
                        direct_page5 = 0;
                    } else {
                        uint8_t value9 = RAM8(ACTOR_STATUS_HIGH + x);
                        bool m_flag4;
                        bool x_flag4;
                        uint16_t x4;
                        uint16_t y4;
                        bool carry4;
                        bool overflow4;
                        uint8_t data_bank4;
                        uint16_t direct_page4;
                        if (value9 & 0x80) {
                            m_flag4 = 1;
                            x_flag4 = 0;
                            x4 = x;
                            y4 = y;
                            carry4 = x >= 0x0600;
                            overflow4 = overflow;
                            data_bank4 = 0x7E;
                            direct_page4 = 0;
                        } else {
                            uint8_t value10 = RAM8(0x004E);
                            bool m_flag3;
                            bool x_flag3;
                            uint16_t x3;
                            uint16_t y3;
                            bool carry3;
                            bool overflow3;
                            uint8_t data_bank3;
                            uint16_t direct_page3;
                            if (!(value10 & 0x80)) {
                                r->a = (a_hi << 8) | value9;
                                r->c = x >= 0x0600;
                                r->z = (value9 & value10) == 0;
                                r->n = value10 & 0x80;
                                r->v = value10 & 0x40;
                                { const uint16_t sp_call = r->sp; JSL(c, 0xF8EC, 0x01D942); GUARD_JSL(c, sp_call, 0xF8EC); } /* advance_actor_program_before_current_action_dispatch */
                                uint16_t dp_ret2 = r->dp;
                                uint8_t db_ret2 = r->db;
                                bool m_ret2 = r->mf;
                                bool x_ret3 = r->xf;
                                uint16_t x_ret4 = r->x;
                                uint16_t y_ret2 = r->y;
                                bool carry_ret2 = r->c;
                                bool overflow_ret2 = r->v;
                                m_flag3 = m_ret2;
                                x_flag3 = x_ret3;
                                x3 = x_ret4;
                                y3 = y_ret2;
                                carry3 = carry_ret2;
                                overflow3 = overflow_ret2;
                                data_bank3 = db_ret2;
                                direct_page3 = dp_ret2;
                            } else {
                                RAM8(0xE067 + x) = 0;
                                m_flag3 = 1;
                                x_flag3 = 0;
                                x3 = x;
                                y3 = y;
                                carry3 = x >= 0x0600;
                                overflow3 = value10 & 0x40;
                                data_bank3 = 0x7E;
                                direct_page3 = 0;
                            }
                            m_flag4 = m_flag3;
                            x_flag4 = x_flag3;
                            x4 = x3;
                            y4 = y3;
                            carry4 = carry3;
                            overflow4 = overflow3;
                            data_bank4 = data_bank3;
                            direct_page4 = direct_page3;
                        }
                        m_flag5 = m_flag4;
                        x_flag5 = x_flag4;
                        x5 = x4;
                        y5 = y4;
                        carry5 = carry4;
                        overflow5 = overflow4;
                        data_bank5 = data_bank4;
                        direct_page5 = direct_page4;
                    }
                    m_flag6 = m_flag5;
                    x_flag6 = x_flag5;
                    x6 = x5;
                    y6 = y5;
                    carry6 = carry5;
                    overflow6 = overflow5;
                    data_bank6 = data_bank5;
                    direct_page6 = direct_page5;
                }
                m_flag7 = m_flag6;
                x_flag7 = x_flag6;
                x7 = x6;
                y7 = y6;
                carry7 = carry6;
                overflow7 = overflow6;
                data_bank7 = data_bank6;
                direct_page7 = direct_page6;
            }
            m_flag8 = m_flag7;
            x_flag8 = x_flag7;
            x8 = x7;
            y8 = y7;
            carry8 = carry7;
            overflow8 = overflow7;
            data_bank8 = data_bank7;
            direct_page8 = direct_page7;
        }
        m_flag9 = m_flag8;
        x_flag9 = x_flag8;
        x9 = x8;
        y9 = y8;
        carry9 = carry8;
        overflow9 = overflow8;
        data_bank9 = data_bank8;
        direct_page9 = direct_page8;
    }
    r->x = x9;
    r->y = y9;
    r->c = carry9;
    r->v = overflow9;
    r->mf = m_flag9;
    r->xf = x_flag9;
    r->db = data_bank9;
    r->dp = direct_page9;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F8B3, SOM_RTS, "gen", trigger_actor_program_under_native_animation_guards, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 59, 26)
