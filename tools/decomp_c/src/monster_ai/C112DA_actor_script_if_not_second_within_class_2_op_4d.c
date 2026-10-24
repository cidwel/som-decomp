#include "som_c.h"

/* C112DA actor_script_if_not_second_within_class_2_op_4d   [class B, 23 bytes, 10 instructions]
 * Source: src/rom/actor_script_if_not_second_within_class_2_op_4d.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_if_not_second_within_class_2_op_4d(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x12DC, 0xC105BA); GUARD_JSR(c, sp_call, 0x12DC); } /* resolve_visible_second_actor_target */
    bool zero_ret = r->z;
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
    if (!zero_ret) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x12EA, 0xC10285); GUARD_JSR(c, sp_call, 0x12EA); } /* jump_actor_script_after_1_bytes */
        uint16_t dp_ret2 = r->dp;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag3 = m_ret;
        x_flag3 = x_ret3;
        a3 = (uint8_t)a_all2;
        a_hi3 = a_all2 >> 8;
        x3 = x_ret4;
        carry3 = carry_ret2;
        zero3 = zero_ret2;
        negative3 = negative_ret2;
        overflow3 = overflow_ret2;
        direct_page3 = dp_ret2;
    } else {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x12E1, 0xC10358); GUARD_JSR(c, sp_call, 0x12E1); } /* classify_actor_squared_distance */
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
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
        if ((uint8_t)a_all3 == 2) {
            r->c = (uint8_t)a_all3 >= 2;
            r->z = (uint8_t)a_all3 == 2;
            r->n = (uint8_t)((uint8_t)a_all3 - 2) & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x12EF, 0xC10213); GUARD_JSR(c, sp_call, 0x12EF); } /* skip_actor_script_after_1_bytes */
            uint16_t dp_ret3 = r->dp;
            bool m_ret2 = r->mf;
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret7 = r->x;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            m_flag2 = m_ret2;
            x_flag2 = x_ret6;
            a2 = (uint8_t)a_all4;
            a_hi2 = a_all4 >> 8;
            x2 = x_ret7;
            carry2 = carry_ret4;
            zero2 = zero_ret4;
            negative2 = negative_ret4;
            overflow2 = overflow_ret4;
            direct_page2 = dp_ret3;
        } else {
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
            if ((uint8_t)a_all3 < 2) {
                r->c = (uint8_t)a_all3 >= 2;
                r->z = (uint8_t)a_all3 == 2;
                r->n = (uint8_t)((uint8_t)a_all3 - 2) & 0x80;
                { const uint16_t sp_call = r->sp; JSR(c, 0x12EF, 0xC10213); GUARD_JSR(c, sp_call, 0x12EF); } /* skip_actor_script_after_1_bytes */
                uint16_t dp_ret4 = r->dp;
                bool m_ret3 = r->mf;
                bool x_ret8 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret9 = r->x;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret5 = r->v;
                m_flag = m_ret3;
                x_flag = x_ret8;
                a1 = (uint8_t)a_all5;
                a_hi1 = a_all5 >> 8;
                x1 = x_ret9;
                carry1 = carry_ret5;
                zero1 = zero_ret5;
                negative1 = negative_ret5;
                overflow1 = overflow_ret5;
                direct_page = dp_ret4;
            } else {
                r->c = (uint8_t)a_all3 >= 2;
                r->z = (uint8_t)a_all3 == 2;
                r->n = (uint8_t)((uint8_t)a_all3 - 2) & 0x80;
                { const uint16_t sp_call = r->sp; JSR(c, 0x12EA, 0xC10285); GUARD_JSR(c, sp_call, 0x12EA); } /* jump_actor_script_after_1_bytes */
                uint16_t dp_ret5 = r->dp;
                bool m_ret4 = r->mf;
                bool x_ret10 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t x_ret11 = r->x;
                bool carry_ret6 = r->c;
                bool zero_ret6 = r->z;
                bool negative_ret6 = r->n;
                bool overflow_ret6 = r->v;
                m_flag = m_ret4;
                x_flag = x_ret10;
                a1 = (uint8_t)a_all6;
                a_hi1 = a_all6 >> 8;
                x1 = x_ret11;
                carry1 = carry_ret6;
                zero1 = zero_ret6;
                negative1 = negative_ret6;
                overflow1 = overflow_ret6;
                direct_page = dp_ret5;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            carry2 = carry1;
            zero2 = zero1;
            negative2 = negative1;
            overflow2 = overflow1;
            direct_page2 = direct_page;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        carry3 = carry2;
        zero3 = zero2;
        negative3 = negative2;
        overflow3 = overflow2;
        direct_page3 = direct_page2;
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
}
SOM_REGISTER(0xC112DA, SOM_RTS, "gen", actor_script_if_not_second_within_class_2_op_4d, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 23, 10)
