#include "som_c.h"

/* C12072 actor_script_if_byte_field_less   [class B, 24 bytes, 9 instructions]
 * Source: src/rom/actor_script_if_byte_field_less.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_if_byte_field_less(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2074, 0xC11FEB); GUARD_JSR(c, sp_call, 0x2074); } /* resolve_actor_script_field_reference */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (m_ret) {
        uint8_t value = RAM8(0x0180 + x_ret2);
        if (x_ret) {
            uint8_t value2 = RAM8(0x0144 + (uint8_t)y);
            uint8_t value3 = BUS8(c, 0xD04F18 + value2);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow1;
            uint16_t direct_page;
            if (value < value3) {
                r->a = (a_all >> 8 << 8) | value;
                r->x = value2;
                r->y = (uint8_t)y;
                r->c = value >= value3;
                r->z = value == value3;
                r->n = (uint8_t)(value - value3) & 0x80;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2088, 0xC102A0); GUARD_JSR(c, sp_call, 0x2088); } /* jump_actor_script_after_4_bytes */
                uint16_t dp_ret2 = r->dp;
                bool m_ret2 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                uint16_t x_ret4 = r->x;
                bool carry_ret2 = r->c;
                bool zero_ret2 = r->z;
                bool negative_ret2 = r->n;
                bool overflow_ret2 = r->v;
                m_flag = m_ret2;
                x_flag = x_ret3;
                a1 = (uint8_t)a_all2;
                a_hi1 = a_all2 >> 8;
                x1 = x_ret4;
                carry1 = carry_ret2;
                zero1 = zero_ret2;
                negative1 = negative_ret2;
                overflow1 = overflow_ret2;
                direct_page = dp_ret2;
            } else {
                r->a = (a_all >> 8 << 8) | value;
                r->x = value2;
                r->y = (uint8_t)y;
                r->c = value >= value3;
                r->z = value == value3;
                r->n = (uint8_t)(value - value3) & 0x80;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2083, 0xC1022E); GUARD_JSR(c, sp_call, 0x2083); } /* skip_actor_script_after_4_bytes */
                uint16_t dp_ret3 = r->dp;
                bool m_ret3 = r->mf;
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t x_ret6 = r->x;
                bool carry_ret3 = r->c;
                bool zero_ret3 = r->z;
                bool negative_ret3 = r->n;
                bool overflow_ret3 = r->v;
                m_flag = m_ret3;
                x_flag = x_ret5;
                a1 = (uint8_t)a_all3;
                a_hi1 = a_all3 >> 8;
                x1 = x_ret6;
                carry1 = carry_ret3;
                zero1 = zero_ret3;
                negative1 = negative_ret3;
                overflow1 = overflow_ret3;
                direct_page = dp_ret3;
            }
            r->a = (a_hi1 << 8) | a1;
            r->x = x1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = m_flag;
            r->xf = x_flag;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value4 = RAM16(0x0144 + y);
            uint8_t value5 = BUS8(c, 0xD04F18 + value4);
            bool m_flag2;
            bool x_flag2;
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t x2;
            bool carry2;
            bool zero2;
            bool negative2;
            bool overflow2;
            uint16_t direct_page2;
            if (value < value5) {
                r->a = (a_all >> 8 << 8) | value;
                r->x = value4;
                r->c = value >= value5;
                r->z = value == value5;
                r->n = (uint8_t)(value - value5) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2088, 0xC102A0); GUARD_JSR(c, sp_call, 0x2088); } /* jump_actor_script_after_4_bytes */
                uint16_t dp_ret4 = r->dp;
                bool m_ret4 = r->mf;
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t x_ret8 = r->x;
                bool carry_ret4 = r->c;
                bool zero_ret4 = r->z;
                bool negative_ret4 = r->n;
                bool overflow_ret4 = r->v;
                m_flag2 = m_ret4;
                x_flag2 = x_ret7;
                a2 = (uint8_t)a_all4;
                a_hi2 = a_all4 >> 8;
                x2 = x_ret8;
                carry2 = carry_ret4;
                zero2 = zero_ret4;
                negative2 = negative_ret4;
                overflow2 = overflow_ret4;
                direct_page2 = dp_ret4;
            } else {
                r->a = (a_all >> 8 << 8) | value;
                r->x = value4;
                r->c = value >= value5;
                r->z = value == value5;
                r->n = (uint8_t)(value - value5) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2083, 0xC1022E); GUARD_JSR(c, sp_call, 0x2083); } /* skip_actor_script_after_4_bytes */
                uint16_t dp_ret5 = r->dp;
                bool m_ret5 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret10 = r->x;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret5 = r->v;
                m_flag2 = m_ret5;
                x_flag2 = x_ret9;
                a2 = (uint8_t)a_all5;
                a_hi2 = a_all5 >> 8;
                x2 = x_ret10;
                carry2 = carry_ret5;
                zero2 = zero_ret5;
                negative2 = negative_ret5;
                overflow2 = overflow_ret5;
                direct_page2 = dp_ret5;
            }
            r->a = (a_hi2 << 8) | a2;
            r->x = x2;
            r->c = carry2;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow2;
            r->mf = m_flag2;
            r->xf = x_flag2;
            r->dp = direct_page2;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value6 = RAM16(0x0180 + x_ret2);
        if (x_ret) {
            uint8_t value7 = RAM8(0x0144 + (uint8_t)y);
            uint16_t value8 = BUS16(c, 0xD04F18 + value7);
            bool m_flag3;
            bool x_flag3;
            uint8_t a3;
            uint8_t a_hi3;
            uint16_t x3;
            bool carry3;
            bool zero3;
            bool negative3;
            bool overflow3;
            uint16_t direct_page3;
            if (value6 < value8) {
                r->a = value6;
                r->x = value7;
                r->y = (uint8_t)y;
                r->c = value6 >= value8;
                r->z = value6 == value8;
                r->n = (uint16_t)(value6 - value8) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2088, 0xC102A0); GUARD_JSR(c, sp_call, 0x2088); } /* jump_actor_script_after_4_bytes */
                uint16_t dp_ret6 = r->dp;
                bool m_ret6 = r->mf;
                bool x_ret11 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t x_ret12 = r->x;
                bool carry_ret6 = r->c;
                bool zero_ret6 = r->z;
                bool negative_ret6 = r->n;
                bool overflow_ret6 = r->v;
                m_flag3 = m_ret6;
                x_flag3 = x_ret11;
                a3 = (uint8_t)a_all6;
                a_hi3 = a_all6 >> 8;
                x3 = x_ret12;
                carry3 = carry_ret6;
                zero3 = zero_ret6;
                negative3 = negative_ret6;
                overflow3 = overflow_ret6;
                direct_page3 = dp_ret6;
            } else {
                r->a = value6;
                r->x = value7;
                r->y = (uint8_t)y;
                r->c = value6 >= value8;
                r->z = value6 == value8;
                r->n = (uint16_t)(value6 - value8) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2083, 0xC1022E); GUARD_JSR(c, sp_call, 0x2083); } /* skip_actor_script_after_4_bytes */
                uint16_t dp_ret7 = r->dp;
                bool m_ret7 = r->mf;
                bool x_ret13 = r->xf;
                uint16_t a_all7 = r->a;
                uint16_t x_ret14 = r->x;
                bool carry_ret7 = r->c;
                bool zero_ret7 = r->z;
                bool negative_ret7 = r->n;
                bool overflow_ret7 = r->v;
                m_flag3 = m_ret7;
                x_flag3 = x_ret13;
                a3 = (uint8_t)a_all7;
                a_hi3 = a_all7 >> 8;
                x3 = x_ret14;
                carry3 = carry_ret7;
                zero3 = zero_ret7;
                negative3 = negative_ret7;
                overflow3 = overflow_ret7;
                direct_page3 = dp_ret7;
            }
            r->a = (a_hi3 << 8) | a3;
            r->x = x3;
            r->c = carry3;
            r->z = zero3;
            r->n = negative3;
            r->v = overflow3;
            r->mf = m_flag3;
            r->xf = x_flag3;
            r->dp = direct_page3;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value9 = RAM16(0x0144 + y);
            uint16_t value10 = BUS16(c, 0xD04F18 + value9);
            bool m_flag4;
            bool x_flag4;
            uint8_t a4;
            uint8_t a_hi4;
            uint16_t x4;
            bool carry4;
            bool zero4;
            bool negative4;
            bool overflow4;
            uint16_t direct_page4;
            if (value6 < value10) {
                r->a = value6;
                r->x = value9;
                r->c = value6 >= value10;
                r->z = value6 == value10;
                r->n = (uint16_t)(value6 - value10) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2088, 0xC102A0); GUARD_JSR(c, sp_call, 0x2088); } /* jump_actor_script_after_4_bytes */
                uint16_t dp_ret8 = r->dp;
                bool m_ret8 = r->mf;
                bool x_ret15 = r->xf;
                uint16_t a_all8 = r->a;
                uint16_t x_ret16 = r->x;
                bool carry_ret8 = r->c;
                bool zero_ret8 = r->z;
                bool negative_ret8 = r->n;
                bool overflow_ret8 = r->v;
                m_flag4 = m_ret8;
                x_flag4 = x_ret15;
                a4 = (uint8_t)a_all8;
                a_hi4 = a_all8 >> 8;
                x4 = x_ret16;
                carry4 = carry_ret8;
                zero4 = zero_ret8;
                negative4 = negative_ret8;
                overflow4 = overflow_ret8;
                direct_page4 = dp_ret8;
            } else {
                r->a = value6;
                r->x = value9;
                r->c = value6 >= value10;
                r->z = value6 == value10;
                r->n = (uint16_t)(value6 - value10) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2083, 0xC1022E); GUARD_JSR(c, sp_call, 0x2083); } /* skip_actor_script_after_4_bytes */
                uint16_t dp_ret9 = r->dp;
                bool m_ret9 = r->mf;
                bool x_ret17 = r->xf;
                uint16_t a_all9 = r->a;
                uint16_t x_ret18 = r->x;
                bool carry_ret9 = r->c;
                bool zero_ret9 = r->z;
                bool negative_ret9 = r->n;
                bool overflow_ret9 = r->v;
                m_flag4 = m_ret9;
                x_flag4 = x_ret17;
                a4 = (uint8_t)a_all9;
                a_hi4 = a_all9 >> 8;
                x4 = x_ret18;
                carry4 = carry_ret9;
                zero4 = zero_ret9;
                negative4 = negative_ret9;
                overflow4 = overflow_ret9;
                direct_page4 = dp_ret9;
            }
            r->a = (a_hi4 << 8) | a4;
            r->x = x4;
            r->c = carry4;
            r->z = zero4;
            r->n = negative4;
            r->v = overflow4;
            r->mf = m_flag4;
            r->xf = x_flag4;
            r->dp = direct_page4;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC12072, SOM_RTS, "gen", actor_script_if_byte_field_less, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 9)
