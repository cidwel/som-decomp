#include "som_c.h"

/* C0F124 compute_native_wrapped_partner_steering_velocity   [class B, 138 bytes, 76 instructions]
 * Source: src/rom/compute_native_wrapped_partner_steering_velocity.s
 * Documented in docs/actor-party-obstacle-detour.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XCV.
 */
static void compute_native_wrapped_partner_steering_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0006, 0);
    uint16_t value = RAM16(0x001C);
    uint16_t value2 = RAM16(0x000C);
    uint8_t a1;
    uint8_t a_hi1;
    uint8_t x1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
        x1 = 0;
    } else {
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
        x1 = 0x80;
    }
    uint16_t value3 = RAM16(0x00C0);
    uint8_t a2;
    uint8_t a_hi2;
    uint8_t x2;
    if ((uint16_t)(((a_hi1 << 8) | a1) << 1) < value3) {
        a2 = (uint8_t)(((a_hi1 << 8) | a1) << 1);
        a_hi2 = (uint16_t)(((a_hi1 << 8) | a1) << 1) >> 8;
        x2 = x1;
    } else {
        RAM16_SET(0x0000, (uint16_t)(((a_hi1 << 8) | a1) << 1));
        uint16_t value4 = RAM16(0x0000);
        a2 = (uint8_t)((uint16_t)(value3 << 1) - value4);
        a_hi2 = (uint16_t)((uint16_t)(value3 << 1) - value4) >> 8;
        x2 = x1 ^ 0x80;
    }
    uint16_t value5 = RAM16(0x0018);
    bool m_flag2;
    uint8_t a_hi4;
    if ((uint16_t)(((a_hi2 << 8) | a2) - value5) & 0x8000) {
        m_flag2 = 0;
        a_hi4 = (uint16_t)(((a_hi2 << 8) | a2) - value5) >> 8;
    } else {
        bool m_flag;
        uint8_t a_hi3;
        if ((uint16_t)(((a_hi2 << 8) | a2) - value5) == 0) {
            m_flag = 0;
            a_hi3 = (uint16_t)(((a_hi2 << 8) | a2) - value5) >> 8;
        } else {
            uint8_t a4;
            if ((uint16_t)(((a_hi2 << 8) | a2) - value5) >> 1 < 4) {
                a4 = (uint8_t)((uint16_t)(((a_hi2 << 8) | a2) - value5) >> 1);
            } else {
                uint8_t value6 = RAM8(0x0016);
                uint8_t a3;
                if (value6 >= 3) {
                    a3 = value6;
                } else {
                    a3 = 3;
                }
                a4 = a3;
            }
            uint8_t a5;
            if (x2 < 0x80) {
                a5 = a4;
            } else {
                a5 = a4 | 0x80;
            }
            RAM8(0x0006) = a5;
            m_flag = 1;
            a_hi3 = (uint16_t)(((a_hi2 << 8) | a2) - value5) >> 1 >> 8;
        }
        m_flag2 = m_flag;
        a_hi4 = a_hi3;
    }
    uint16_t value7 = RAM16(0x001E);
    uint16_t value8 = RAM16(0x000E);
    uint8_t a6;
    uint8_t a_hi5;
    uint8_t x3;
    if (!((uint16_t)(value7 - value8) & 0x8000)) {
        a6 = (uint8_t)(value7 - value8);
        a_hi5 = (uint16_t)(value7 - value8) >> 8;
        x3 = 0;
    } else {
        a6 = (uint8_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1);
        a_hi5 = (uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) >> 8;
        x3 = 0x80;
    }
    uint16_t value9 = RAM16(0x00C2);
    uint8_t a7;
    uint8_t a_hi6;
    uint8_t x4;
    if ((uint16_t)(((a_hi5 << 8) | a6) << 1) < value9) {
        a7 = (uint8_t)(((a_hi5 << 8) | a6) << 1);
        a_hi6 = (uint16_t)(((a_hi5 << 8) | a6) << 1) >> 8;
        x4 = x3;
    } else {
        RAM16_SET(0x0000, (uint16_t)(((a_hi5 << 8) | a6) << 1));
        uint16_t value10 = RAM16(0x0000);
        a7 = (uint8_t)((uint16_t)(value9 << 1) - value10);
        a_hi6 = (uint16_t)((uint16_t)(value9 << 1) - value10) >> 8;
        x4 = x3 ^ 0x80;
    }
    uint16_t value11 = RAM16(0x001A);
    bool m_flag4;
    if ((uint16_t)(((a_hi6 << 8) | a7) - value11) & 0x8000) {
        m_flag4 = 0;
    } else {
        bool m_flag3;
        if ((uint16_t)(((a_hi6 << 8) | a7) - value11) == 0) {
            m_flag3 = 0;
        } else {
            uint8_t a9;
            if ((uint16_t)(((a_hi6 << 8) | a7) - value11) >> 1 < 4) {
                a9 = (uint8_t)((uint16_t)(((a_hi6 << 8) | a7) - value11) >> 1);
            } else {
                uint8_t value12 = RAM8(0x0017);
                uint8_t a8;
                if (value12 >= 3) {
                    a8 = value12;
                } else {
                    a8 = 3;
                }
                a9 = a8;
            }
            uint8_t a10;
            if (x4 < 0x80) {
                a10 = a9;
            } else {
                a10 = a9 | 0x80;
            }
            RAM8(0x0007) = a10;
            m_flag3 = 1;
        }
        m_flag4 = m_flag3;
    }
    r->x = x4;
    r->c = 1;
    r->v = ((((a_hi6 << 8) | a7) ^ value11) & (((a_hi6 << 8) | a7) ^ (uint16_t)(((a_hi6 << 8) | a7) - value11)) & 0x8000) != 0;
    r->mf = m_flag4;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F124, SOM_RTS, "gen", compute_native_wrapped_partner_steering_velocity, 0, L_X | L_C | L_V, 1, 0, 0, 138, 76)
