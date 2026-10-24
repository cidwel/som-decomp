#include "som_c.h"

/* C191E1 update_native_visual_effect_cadence_signed_motion_and_point_trail   [class B, 107 bytes, 46 instructions]
 * Source: src/rom/update_native_visual_effect_cadence_signed_motion_and_point_trail.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void update_native_visual_effect_cadence_signed_motion_and_point_trail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE11E + x);
    bool m_flag6;
    uint8_t a_hi10;
    bool carry6;
    bool overflow6;
    if (value == 0) {
        uint8_t value2 = RAM8(0xE11C + x);
        bool m_flag;
        uint8_t a_hi2;
        bool carry1;
        bool overflow1;
        if (value2 == 0) {
            m_flag = 1;
            a_hi2 = a_hi;
            carry1 = carry;
            overflow1 = overflow;
        } else {
            uint8_t a1;
            uint8_t a_hi1;
            if (value2 < 0x80) {
                a1 = ((a_hi << 8) | value2) & 0x7F;
                a_hi1 = 0;
            } else {
                a1 = (uint8_t)(((((a_hi << 8) | value2) & 0x7F) ^ 0xFFFF) + 1);
                a_hi1 = (uint16_t)(((((a_hi << 8) | value2) & 0x7F) ^ 0xFFFF) + 1) >> 8;
            }
            uint16_t value3 = RAM16(0xE118 + x);
            RAM16_SET(0xE118 + x, (uint16_t)(((a_hi1 << 8) | a1) + value3));
            m_flag = 0;
            a_hi2 = (uint16_t)(((a_hi1 << 8) | a1) + value3) >> 8;
            carry1 = ((a_hi1 << 8) | a1) + value3 > 0xFFFF;
            overflow1 = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + value3)) & (value3 ^ (uint16_t)(((a_hi1 << 8) | a1) + value3)) & 0x8000) != 0;
        }
        uint8_t value4 = RAM8(0xE11D + x);
        bool m_flag2;
        uint8_t a_hi4;
        bool carry2;
        bool overflow2;
        if (value4 == 0) {
            m_flag2 = 1;
            a_hi4 = a_hi2;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            uint8_t a2;
            uint8_t a_hi3;
            if (value4 < 0x80) {
                a2 = ((a_hi2 << 8) | value4) & 0x7F;
                a_hi3 = 0;
            } else {
                a2 = (uint8_t)(((((a_hi2 << 8) | value4) & 0x7F) ^ 0xFFFF) + 1);
                a_hi3 = (uint16_t)(((((a_hi2 << 8) | value4) & 0x7F) ^ 0xFFFF) + 1) >> 8;
            }
            uint16_t value5 = RAM16(0xE11A + x);
            RAM16_SET(0xE11A + x, (uint16_t)(((a_hi3 << 8) | a2) + value5));
            m_flag2 = 0;
            a_hi4 = (uint16_t)(((a_hi3 << 8) | a2) + value5) >> 8;
            carry2 = ((a_hi3 << 8) | a2) + value5 > 0xFFFF;
            overflow2 = ((((a_hi3 << 8) | a2) ^ (uint16_t)(((a_hi3 << 8) | a2) + value5)) & (value5 ^ (uint16_t)(((a_hi3 << 8) | a2) + value5)) & 0x8000) != 0;
        }
        m_flag6 = m_flag2;
        a_hi10 = a_hi4;
        carry6 = carry2;
        overflow6 = overflow2;
    } else {
        RAM8(0xE11F + x)--;
        bool m_flag5;
        uint8_t a_hi9;
        bool carry5;
        bool overflow5;
        if (!(RAM8(0xE11F + x) & 0x80)) {
            m_flag5 = 1;
            a_hi9 = a_hi;
            carry5 = carry;
            overflow5 = overflow;
        } else {
            RAM8(0xE11F + x) = value;
            uint8_t value7 = RAM8(0xE11C + x);
            bool m_flag3;
            uint8_t a_hi6;
            bool carry3;
            bool overflow3;
            if (value7 == 0) {
                m_flag3 = 1;
                a_hi6 = a_hi;
                carry3 = carry;
                overflow3 = overflow;
            } else {
                uint8_t a3;
                uint8_t a_hi5;
                if (value7 < 0x80) {
                    a3 = ((a_hi << 8) | value7) & 0x7F;
                    a_hi5 = 0;
                } else {
                    a3 = (uint8_t)(((((a_hi << 8) | value7) & 0x7F) ^ 0xFFFF) + 1);
                    a_hi5 = (uint16_t)(((((a_hi << 8) | value7) & 0x7F) ^ 0xFFFF) + 1) >> 8;
                }
                uint16_t value8 = RAM16(0xE118 + x);
                RAM16_SET(0xE118 + x, (uint16_t)(((a_hi5 << 8) | a3) + value8));
                m_flag3 = 0;
                a_hi6 = (uint16_t)(((a_hi5 << 8) | a3) + value8) >> 8;
                carry3 = ((a_hi5 << 8) | a3) + value8 > 0xFFFF;
                overflow3 = ((((a_hi5 << 8) | a3) ^ (uint16_t)(((a_hi5 << 8) | a3) + value8)) & (value8 ^ (uint16_t)(((a_hi5 << 8) | a3) + value8)) & 0x8000) != 0;
            }
            uint8_t value9 = RAM8(0xE11D + x);
            bool m_flag4;
            uint8_t a_hi8;
            bool carry4;
            bool overflow4;
            if (value9 == 0) {
                m_flag4 = 1;
                a_hi8 = a_hi6;
                carry4 = carry3;
                overflow4 = overflow3;
            } else {
                uint8_t a4;
                uint8_t a_hi7;
                if (value9 < 0x80) {
                    a4 = ((a_hi6 << 8) | value9) & 0x7F;
                    a_hi7 = 0;
                } else {
                    a4 = (uint8_t)(((((a_hi6 << 8) | value9) & 0x7F) ^ 0xFFFF) + 1);
                    a_hi7 = (uint16_t)(((((a_hi6 << 8) | value9) & 0x7F) ^ 0xFFFF) + 1) >> 8;
                }
                uint16_t value10 = RAM16(0xE11A + x);
                RAM16_SET(0xE11A + x, (uint16_t)(((a_hi7 << 8) | a4) + value10));
                m_flag4 = 0;
                a_hi8 = (uint16_t)(((a_hi7 << 8) | a4) + value10) >> 8;
                carry4 = ((a_hi7 << 8) | a4) + value10 > 0xFFFF;
                overflow4 = ((((a_hi7 << 8) | a4) ^ (uint16_t)(((a_hi7 << 8) | a4) + value10)) & (value10 ^ (uint16_t)(((a_hi7 << 8) | a4) + value10)) & 0x8000) != 0;
            }
            m_flag5 = m_flag4;
            a_hi9 = a_hi8;
            carry5 = carry4;
            overflow5 = overflow4;
        }
        m_flag6 = m_flag5;
        a_hi10 = a_hi9;
        carry6 = carry5;
        overflow6 = overflow5;
    }
    uint8_t value11 = RAM8(0xE114 + x);
    if (!(value11 & 0x80)) {
        if ((value11 & 0x40) == 0) {
            r->a = (a_hi10 << 8) | value11;
            r->c = carry6;
            r->v = overflow6;
            RETURN_RTS(c);
        }
        uint8_t value12 = RAM8(0xE110 + x);
        if (value12 == 5) {
            r->a = (a_hi10 << 8) | value12;
            r->c = value12 >= 5;
            r->z = value12 == 5;
            r->n = (uint8_t)(value12 - 5) & 0x80;
            r->v = overflow6;
            { const uint16_t sp_call = r->sp; JSL(c, 0x924A, 0x02ACA8); GUARD_JSL(c, sp_call, 0x924A); } /* publish_native_visual_effect_point_trail_long */
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE116 + x)++;
        r->a = (a_hi10 << 8) | value12;
        r->c = value12 >= 5;
        r->v = overflow6;
        RETURN_RTS(c);
    }
    r->a = (a_hi10 << 8) | value11;
    r->c = carry6;
    r->z = value11 == 0;
    r->n = value11 & 0x80;
    r->v = overflow6;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9236, 0x02A407); GUARD_JSL(c, sp_call, 0x9236); } /* advance_native_fractional_visual_effect_points */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC191E1, SOM_RTS, "gen", update_native_visual_effect_cadence_signed_motion_and_point_trail, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 107, 46)
