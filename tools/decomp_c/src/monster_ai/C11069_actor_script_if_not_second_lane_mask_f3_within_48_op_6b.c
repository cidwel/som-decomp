#include "som_c.h"

/* C11069 actor_script_if_not_second_lane_mask_f3_within_48_op_6b   [class B, 31 bytes, 14 instructions]
 * Source: src/rom/actor_script_if_not_second_lane_mask_f3_within_48_op_6b.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_if_not_second_lane_mask_f3_within_48_op_6b(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x106B, 0xC105BA); GUARD_JSR(c, sp_call, 0x106B); } /* resolve_visible_second_actor_target */
    bool zero_ret = r->z;
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
    if (!zero_ret) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1081, 0xC10285); GUARD_JSR(c, sp_call, 0x1081); } /* jump_actor_script_after_1_bytes */
        uint16_t dp_ret2 = r->dp;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag4 = m_ret;
        x_flag4 = x_ret3;
        a4 = (uint8_t)a_all2;
        a_hi4 = a_all2 >> 8;
        x4 = x_ret4;
        carry4 = carry_ret2;
        zero4 = zero_ret2;
        negative4 = negative_ret2;
        overflow4 = overflow_ret2;
        direct_page4 = dp_ret2;
    } else {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1070, 0xC10404); GUARD_JSR(c, sp_call, 0x1070); } /* calculate_actor_direction_codes */
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
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
        if (((a_all3 >> 8) & 0xF3) != 0) {
            r->a = ((uint8_t)a_all3 << 8) | (a_all3 >> 8);
            r->z = ((a_all3 >> 8) & 0xF3) == 0;
            r->n = a_all3 >> 8 & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1081, 0xC10285); GUARD_JSR(c, sp_call, 0x1081); } /* jump_actor_script_after_1_bytes */
            uint16_t dp_ret3 = r->dp;
            bool m_ret2 = r->mf;
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret7 = r->x;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            m_flag3 = m_ret2;
            x_flag3 = x_ret6;
            a3 = (uint8_t)a_all4;
            a_hi3 = a_all4 >> 8;
            x3 = x_ret7;
            carry3 = carry_ret4;
            zero3 = zero_ret4;
            negative3 = negative_ret4;
            overflow3 = overflow_ret4;
            direct_page3 = dp_ret3;
        } else {
            r->a = ((uint8_t)a_all3 << 8) | (a_all3 >> 8);
            r->z = ((a_all3 >> 8) & 0xF3) == 0;
            r->n = a_all3 >> 8 & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1078, 0xC10358); GUARD_JSR(c, sp_call, 0x1078); } /* classify_actor_squared_distance */
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all5 = r->a;
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
            if ((uint8_t)a_all5 == 0x30) {
                r->c = (uint8_t)a_all5 >= 0x30;
                r->z = (uint8_t)a_all5 == 0x30;
                r->n = (uint8_t)((uint8_t)a_all5 - 0x30) & 0x80;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1086, 0xC10213); GUARD_JSR(c, sp_call, 0x1086); } /* skip_actor_script_after_1_bytes */
                uint16_t dp_ret4 = r->dp;
                bool m_ret3 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t x_ret10 = r->x;
                bool carry_ret6 = r->c;
                bool zero_ret6 = r->z;
                bool negative_ret6 = r->n;
                bool overflow_ret6 = r->v;
                m_flag2 = m_ret3;
                x_flag2 = x_ret9;
                a2 = (uint8_t)a_all6;
                a_hi2 = a_all6 >> 8;
                x2 = x_ret10;
                carry2 = carry_ret6;
                zero2 = zero_ret6;
                negative2 = negative_ret6;
                overflow2 = overflow_ret6;
                direct_page2 = dp_ret4;
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
                if ((uint8_t)a_all5 < 0x30) {
                    r->c = (uint8_t)a_all5 >= 0x30;
                    r->z = (uint8_t)a_all5 == 0x30;
                    r->n = (uint8_t)((uint8_t)a_all5 - 0x30) & 0x80;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1086, 0xC10213); GUARD_JSR(c, sp_call, 0x1086); } /* skip_actor_script_after_1_bytes */
                    uint16_t dp_ret5 = r->dp;
                    bool m_ret4 = r->mf;
                    bool x_ret11 = r->xf;
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret12 = r->x;
                    bool carry_ret7 = r->c;
                    bool zero_ret7 = r->z;
                    bool negative_ret7 = r->n;
                    bool overflow_ret7 = r->v;
                    m_flag = m_ret4;
                    x_flag = x_ret11;
                    a1 = (uint8_t)a_all7;
                    a_hi1 = a_all7 >> 8;
                    x1 = x_ret12;
                    carry1 = carry_ret7;
                    zero1 = zero_ret7;
                    negative1 = negative_ret7;
                    overflow1 = overflow_ret7;
                    direct_page = dp_ret5;
                } else {
                    r->c = (uint8_t)a_all5 >= 0x30;
                    r->z = (uint8_t)a_all5 == 0x30;
                    r->n = (uint8_t)((uint8_t)a_all5 - 0x30) & 0x80;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1081, 0xC10285); GUARD_JSR(c, sp_call, 0x1081); } /* jump_actor_script_after_1_bytes */
                    uint16_t dp_ret6 = r->dp;
                    bool m_ret5 = r->mf;
                    bool x_ret13 = r->xf;
                    uint16_t a_all8 = r->a;
                    uint16_t x_ret14 = r->x;
                    bool carry_ret8 = r->c;
                    bool zero_ret8 = r->z;
                    bool negative_ret8 = r->n;
                    bool overflow_ret8 = r->v;
                    m_flag = m_ret5;
                    x_flag = x_ret13;
                    a1 = (uint8_t)a_all8;
                    a_hi1 = a_all8 >> 8;
                    x1 = x_ret14;
                    carry1 = carry_ret8;
                    zero1 = zero_ret8;
                    negative1 = negative_ret8;
                    overflow1 = overflow_ret8;
                    direct_page = dp_ret6;
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
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a4 = a3;
        a_hi4 = a_hi3;
        x4 = x3;
        carry4 = carry3;
        zero4 = zero3;
        negative4 = negative3;
        overflow4 = overflow3;
        direct_page4 = direct_page3;
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
SOM_REGISTER(0xC11069, SOM_RTS, "gen", actor_script_if_not_second_lane_mask_f3_within_48_op_6b, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 31, 14)
