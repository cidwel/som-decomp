#include "som_c.h"

/* C12226 actor_script_compare_shared_charge_stage   [class B, 49 bytes, 24 instructions]
 * Source: src/rom/actor_script_compare_shared_charge_stage.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_compare_shared_charge_stage(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xCC7D + (((uint8_t)((y & 0x0600) >> 1) << 8) | ((y & 0x0600) >> 1 >> 8)));
    uint8_t value3 = BUS8(c, 0xD04F16 + RAM16(0x0144 + y));
    bool m_flag5;
    bool x_flag5;
    uint8_t a5;
    uint8_t a_hi5;
    uint16_t x5;
    bool carry5;
    bool zero5;
    bool negative5;
    bool overflow5;
    uint16_t direct_page5;
    if (value3 == 0) {
        uint8_t value4 = RAM8(0x019B + y);
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
        if (value == value4) {
            r->c = value >= value4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2248, 0xC1021B); GUARD_JSR(c, sp_call, 0x2248); } /* skip_actor_script_after_2_bytes */
            uint16_t dp_ret = r->dp;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret = r->c;
            bool zero_ret = r->z;
            bool negative_ret = r->n;
            bool overflow_ret = r->v;
            m_flag2 = m_ret;
            x_flag2 = x_ret;
            a2 = (uint8_t)a_all;
            a_hi2 = a_all >> 8;
            x2 = x_ret2;
            carry2 = carry_ret;
            zero2 = zero_ret;
            negative2 = negative_ret;
            overflow2 = overflow_ret;
            direct_page2 = dp_ret;
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
            if (value < value4) {
                r->c = value >= value4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2248, 0xC1021B); GUARD_JSR(c, sp_call, 0x2248); } /* skip_actor_script_after_2_bytes */
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
                r->c = value >= value4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2255, 0xC1028D); GUARD_JSR(c, sp_call, 0x2255); } /* jump_actor_script_after_2_bytes */
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
        m_flag5 = m_flag2;
        x_flag5 = x_flag2;
        a5 = a2;
        a_hi5 = a_hi2;
        x5 = x2;
        carry5 = carry2;
        zero5 = zero2;
        negative5 = negative2;
        overflow5 = overflow2;
        direct_page5 = direct_page2;
    } else {
        uint8_t value5 = RAM8(0x019B + y);
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
        if (value == value5) {
            r->c = value >= value5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2255, 0xC1028D); GUARD_JSR(c, sp_call, 0x2255); } /* jump_actor_script_after_2_bytes */
            uint16_t dp_ret4 = r->dp;
            bool m_ret4 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret8 = r->x;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            m_flag4 = m_ret4;
            x_flag4 = x_ret7;
            a4 = (uint8_t)a_all4;
            a_hi4 = a_all4 >> 8;
            x4 = x_ret8;
            carry4 = carry_ret4;
            zero4 = zero_ret4;
            negative4 = negative_ret4;
            overflow4 = overflow_ret4;
            direct_page4 = dp_ret4;
        } else {
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
            if (value < value5) {
                r->c = value >= value5;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2255, 0xC1028D); GUARD_JSR(c, sp_call, 0x2255); } /* jump_actor_script_after_2_bytes */
                uint16_t dp_ret5 = r->dp;
                bool m_ret5 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret10 = r->x;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret5 = r->v;
                m_flag3 = m_ret5;
                x_flag3 = x_ret9;
                a3 = (uint8_t)a_all5;
                a_hi3 = a_all5 >> 8;
                x3 = x_ret10;
                carry3 = carry_ret5;
                zero3 = zero_ret5;
                negative3 = negative_ret5;
                overflow3 = overflow_ret5;
                direct_page3 = dp_ret5;
            } else {
                r->c = value >= value5;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2248, 0xC1021B); GUARD_JSR(c, sp_call, 0x2248); } /* skip_actor_script_after_2_bytes */
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
        m_flag5 = m_flag4;
        x_flag5 = x_flag4;
        a5 = a4;
        a_hi5 = a_hi4;
        x5 = x4;
        carry5 = carry4;
        zero5 = zero4;
        negative5 = negative4;
        overflow5 = overflow4;
        direct_page5 = direct_page4;
    }
    r->a = (a_hi5 << 8) | a5;
    r->x = x5;
    r->c = carry5;
    r->z = zero5;
    r->n = negative5;
    r->v = overflow5;
    r->mf = m_flag5;
    r->xf = x_flag5;
    r->dp = direct_page5;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12226, SOM_RTS, "gen", actor_script_compare_shared_charge_stage, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 49, 24)
