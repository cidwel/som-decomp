#include "som_c.h"

/* C0DB1E advance_all_automatic_map_layer_motion   [class B, 42 bytes, 21 instructions]
 * Source: src/rom/advance_all_automatic_map_layer_motion.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_all_automatic_map_layer_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0;
    uint8_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    uint8_t data_bank = 0;
    uint16_t direct_page = 0;
    for (;;) {
        uint8_t value = BUS8_RDP(c, (data_bank << 0x10) + 0x0A82 + x1);
        bool m_flag3;
        bool x_flag3;
        uint8_t a_hi4;
        uint16_t x4;
        uint16_t y4;
        uint8_t data_bank4;
        uint16_t direct_page4;
        if (value == 0) {
            m_flag3 = 1;
            x_flag3 = 1;
            a_hi4 = a_hi1;
            x4 = x1;
            y4 = y1;
            data_bank4 = data_bank;
            direct_page4 = direct_page;
        } else {
            bool m_flag2;
            bool x_flag2;
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            uint8_t data_bank3;
            uint16_t direct_page3;
            if (value != 1) {
                bool m_flag;
                bool x_flag;
                uint8_t a_hi2;
                uint16_t x2;
                uint16_t y2;
                uint8_t data_bank2;
                uint16_t direct_page2;
                if (value != 2) {
                    r->a = (a_hi1 << 8) | value;
                    r->x = x1;
                    r->y = y1;
                    r->c = value >= 2;
                    r->z = value == 2;
                    r->n = (uint8_t)(value - 2) & 0x80;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = data_bank;
                    r->dp = direct_page;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xDB3B, 0xC0DB48); GUARD_JSR(c, sp_call, 0xDB3B); } /* advance_sine_map_layer_motion */
                    bool m_ret = r->mf;
                    uint16_t a_all = r->a;
                    uint8_t x_ret = r->x;
                    uint8_t y_ret = r->y;
                    m_flag = m_ret;
                    x_flag = 1;
                    a_hi2 = a_all >> 8;
                    x2 = x_ret;
                    y2 = y_ret;
                    data_bank2 = data_bank;
                    direct_page2 = direct_page;
                } else {
                    r->a = (a_hi1 << 8) | value;
                    r->x = x1;
                    r->y = y1;
                    r->c = value >= 2;
                    r->z = value == 2;
                    r->n = (uint8_t)(value - 2) & 0x80;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = data_bank;
                    r->dp = direct_page;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xDB36, 0xC0DB9E); GUARD_JSR(c, sp_call, 0xDB36); } /* advance_linear_map_layer_motion */
                    uint16_t dp_ret = r->dp;
                    uint8_t db_ret = r->db;
                    bool m_ret2 = r->mf;
                    bool x_ret2 = r->xf;
                    uint16_t a_all2 = r->a;
                    uint16_t x_ret3 = r->x;
                    uint16_t y_ret2 = r->y;
                    m_flag = m_ret2;
                    x_flag = x_ret2;
                    a_hi2 = a_all2 >> 8;
                    x2 = x_ret3;
                    y2 = y_ret2;
                    data_bank2 = db_ret;
                    direct_page2 = dp_ret;
                }
                m_flag2 = m_flag;
                x_flag2 = x_flag;
                a_hi3 = a_hi2;
                x3 = x2;
                y3 = y2;
                data_bank3 = data_bank2;
                direct_page3 = direct_page2;
            } else {
                r->a = (a_hi1 << 8) | value;
                r->x = x1;
                r->y = y1;
                r->c = value >= 1;
                r->z = value == 1;
                r->n = (uint8_t)(value - 1) & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                r->db = data_bank;
                r->dp = direct_page;
                { const uint16_t sp_call = r->sp; JSR(c, 0xDB2D, 0xC0DB48); GUARD_JSR(c, sp_call, 0xDB2D); } /* advance_sine_map_layer_motion */
                bool m_ret3 = r->mf;
                uint16_t a_all3 = r->a;
                uint8_t x_ret4 = r->x;
                uint8_t y_ret3 = r->y;
                m_flag2 = m_ret3;
                x_flag2 = 1;
                a_hi3 = a_all3 >> 8;
                x3 = x_ret4;
                y3 = y_ret3;
                data_bank3 = data_bank;
                direct_page3 = direct_page;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a_hi4 = a_hi3;
            x4 = x3;
            y4 = y3;
            data_bank4 = data_bank3;
            direct_page4 = direct_page3;
        }
        a1 = (uint8_t)((uint8_t)x4 + 0x10);
        a_hi1 = a_hi4;
        x1 = (uint8_t)((a_hi4 << 8) | (uint8_t)((uint8_t)x4 + 0x10));
        y1 = (uint8_t)y4;
        carry1 = (uint8_t)((uint8_t)x4 + 0x10) >= 0x40;
        zero1 = (uint8_t)((uint8_t)x4 + 0x10) == 0x40;
        negative1 = (uint8_t)((uint8_t)((uint8_t)x4 + 0x10) - 0x40) & 0x80;
        overflow1 = (((uint8_t)x4 ^ (uint8_t)((uint8_t)x4 + 0x10)) & ((uint8_t)((uint8_t)x4 + 0x10) ^ 0x10) & 0x80) != 0;
        data_bank = data_bank4;
        direct_page = direct_page4;
        if (!(a1 < 0x40)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DB1E, SOM_RTS, "gen", advance_all_automatic_map_layer_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 42, 21)
