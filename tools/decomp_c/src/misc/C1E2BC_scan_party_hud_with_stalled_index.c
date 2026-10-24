#include "som_c.h"

/* C1E2BC scan_party_hud_with_stalled_index   [class B, 41 bytes, 21 instructions]
 * Source: src/rom/scan_party_hud_with_stalled_index.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void scan_party_hud_with_stalled_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint8_t a1 = 0x7E;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value = RAM8(0xE000 + x1);
            bool m_flag3;
            uint8_t a_hi4;
            uint16_t y4;
            if (value == 0) {
                m_flag3 = 1;
                a_hi4 = a_hi1;
                y4 = y1;
            } else {
                bool m_flag2;
                uint8_t a_hi3;
                uint16_t y3;
                if (value & 0x80) {
                    m_flag2 = 1;
                    a_hi3 = a_hi1;
                    y3 = y1;
                } else {
                    uint8_t value2 = RAM8(0xE02C + x1);
                    bool m_flag;
                    uint8_t a_hi2;
                    uint16_t y2;
                    if (value2 != 0) {
                        m_flag = 1;
                        a_hi2 = a_hi1;
                        y2 = y1;
                    } else {
                        r->a = (a_hi1 << 8) | value2;
                        r->x = x1;
                        r->y = y1;
                        r->c = carry1;
                        r->z = value2 == 0;
                        r->n = value2 & 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = dp;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xE2D6, 0xC1E2E5); GUARD_JSR(c, sp_call, 0xE2D6); } /* clear_party_hud_tilemap */
                        r->sp += 1;
                        uint16_t a_all = r->a;
                        uint16_t y_ret = r->y;
                        m_flag = 0;
                        a_hi2 = a_all >> 8;
                        y2 = y_ret;
                    }
                    m_flag2 = m_flag;
                    a_hi3 = a_hi2;
                    y3 = y2;
                }
                m_flag3 = m_flag2;
                a_hi4 = a_hi3;
                y4 = y3;
            }
            if ((uint16_t)(x1 + 0x0200) < 0x0600) {
                a1 = (uint8_t)(x1 + 0x0200);
                a_hi1 = (uint16_t)(x1 + 0x0200) >> 8;
                y1 = y4;
                carry1 = (uint16_t)(x1 + 0x0200) >= 0x0600;
                zero1 = (uint16_t)(x1 + 0x0200) == 0x0600;
                negative1 = (uint16_t)((uint16_t)(x1 + 0x0200) - 0x0600) & 0x8000;
                overflow1 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                first_pass = false;
                continue;
            }
            a1 = (uint8_t)(x1 + 0x0200);
            a_hi1 = (uint16_t)(x1 + 0x0200) >> 8;
            y1 = y4;
            carry1 = (uint16_t)(x1 + 0x0200) >= 0x0600;
            zero1 = (uint16_t)(x1 + 0x0200) == 0x0600;
            negative1 = (uint16_t)((uint16_t)(x1 + 0x0200) - 0x0600) & 0x8000;
            overflow1 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
            break;
        } else {
            uint16_t value3 = RAM16(0xE000 + x1);
            uint8_t a_hi7;
            uint16_t y7;
            if (value3 == 0) {
                a_hi7 = value3 >> 8;
                y7 = y1;
            } else {
                uint8_t a_hi6;
                uint16_t y6;
                if (value3 & 0x8000) {
                    a_hi6 = value3 >> 8;
                    y6 = y1;
                } else {
                    uint16_t value4 = RAM16(0xE02C + x1);
                    uint8_t a_hi5;
                    uint16_t y5;
                    if (value4 != 0) {
                        a_hi5 = value4 >> 8;
                        y5 = y1;
                    } else {
                        r->a = value4;
                        r->x = x1;
                        r->y = y1;
                        r->c = carry1;
                        r->z = value4 == 0;
                        r->n = value4 & 0x8000;
                        r->v = overflow1;
                        r->mf = 0;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = dp;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xE2D6, 0xC1E2E5); GUARD_JSR(c, sp_call, 0xE2D6); } /* clear_party_hud_tilemap */
                        r->sp += 1;
                        uint16_t a_all2 = r->a;
                        uint16_t y_ret2 = r->y;
                        a_hi5 = a_all2 >> 8;
                        y5 = y_ret2;
                    }
                    a_hi6 = a_hi5;
                    y6 = y5;
                }
                a_hi7 = a_hi6;
                y7 = y6;
            }
            if ((uint16_t)(x1 + 0x0200) < 0x0600) {
                a1 = (uint8_t)(x1 + 0x0200);
                a_hi1 = (uint16_t)(x1 + 0x0200) >> 8;
                y1 = y7;
                carry1 = (uint16_t)(x1 + 0x0200) >= 0x0600;
                zero1 = (uint16_t)(x1 + 0x0200) == 0x0600;
                negative1 = (uint16_t)((uint16_t)(x1 + 0x0200) - 0x0600) & 0x8000;
                overflow1 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
                continue;
            }
            a1 = (uint8_t)(x1 + 0x0200);
            a_hi1 = (uint16_t)(x1 + 0x0200) >> 8;
            y1 = y7;
            carry1 = (uint16_t)(x1 + 0x0200) >= 0x0600;
            zero1 = (uint16_t)(x1 + 0x0200) == 0x0600;
            negative1 = (uint16_t)((uint16_t)(x1 + 0x0200) - 0x0600) & 0x8000;
            overflow1 = ((x1 ^ (uint16_t)(x1 + 0x0200)) & ((uint16_t)(x1 + 0x0200) ^ 0x0200) & 0x8000) != 0;
            break;
        }
    }
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = value5;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E2BC, SOM_RTS, "gen", scan_party_hud_with_stalled_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 41, 21)
