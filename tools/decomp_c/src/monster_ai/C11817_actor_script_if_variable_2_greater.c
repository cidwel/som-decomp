#include "som_c.h"

/* C11817 actor_script_if_variable_2_greater   [class B, 23 bytes, 9 instructions]
 * Source: src/rom/actor_script_if_variable_2_greater.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_if_variable_2_greater(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1819, 0xC10179); GUARD_JSR(c, sp_call, 0x1819); } /* read_actor_script_variable_2 */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t value = RAM8(0x0144 + (uint8_t)y);
        if (m_ret) {
            uint8_t value2 = BUS8(c, 0xD04F16 + value);
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
            if ((uint8_t)a_all == value2) {
                r->x = value;
                r->y = (uint8_t)y;
                r->c = (uint8_t)a_all >= value2;
                r->z = (uint8_t)a_all == value2;
                r->n = (uint8_t)((uint8_t)a_all - value2) & 0x80;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                uint16_t dp_ret2 = r->dp;
                bool m_ret2 = r->mf;
                bool x_ret2 = r->xf;
                uint16_t a_all2 = r->a;
                uint16_t x_ret3 = r->x;
                bool carry_ret2 = r->c;
                bool zero_ret2 = r->z;
                bool negative_ret2 = r->n;
                bool overflow_ret2 = r->v;
                m_flag2 = m_ret2;
                x_flag2 = x_ret2;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
                x2 = x_ret3;
                carry2 = carry_ret2;
                zero2 = zero_ret2;
                negative2 = negative_ret2;
                overflow2 = overflow_ret2;
                direct_page2 = dp_ret2;
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
                if ((uint8_t)a_all >= value2) {
                    r->x = value;
                    r->y = (uint8_t)y;
                    r->c = (uint8_t)a_all >= value2;
                    r->z = (uint8_t)a_all == value2;
                    r->n = (uint8_t)((uint8_t)a_all - value2) & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x182C, 0xC1028D); GUARD_JSR(c, sp_call, 0x182C); } /* jump_actor_script_after_2_bytes */
                    uint16_t dp_ret3 = r->dp;
                    bool m_ret3 = r->mf;
                    bool x_ret4 = r->xf;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret5 = r->x;
                    bool carry_ret3 = r->c;
                    bool zero_ret3 = r->z;
                    bool negative_ret3 = r->n;
                    bool overflow_ret3 = r->v;
                    m_flag = m_ret3;
                    x_flag = x_ret4;
                    a1 = (uint8_t)a_all3;
                    a_hi1 = a_all3 >> 8;
                    x1 = x_ret5;
                    carry1 = carry_ret3;
                    zero1 = zero_ret3;
                    negative1 = negative_ret3;
                    overflow1 = overflow_ret3;
                    direct_page = dp_ret3;
                } else {
                    r->x = value;
                    r->y = (uint8_t)y;
                    r->c = (uint8_t)a_all >= value2;
                    r->z = (uint8_t)a_all == value2;
                    r->n = (uint8_t)((uint8_t)a_all - value2) & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                    uint16_t dp_ret4 = r->dp;
                    bool m_ret4 = r->mf;
                    bool x_ret6 = r->xf;
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret7 = r->x;
                    bool carry_ret4 = r->c;
                    bool zero_ret4 = r->z;
                    bool negative_ret4 = r->n;
                    bool overflow_ret4 = r->v;
                    m_flag = m_ret4;
                    x_flag = x_ret6;
                    a1 = (uint8_t)a_all4;
                    a_hi1 = a_all4 >> 8;
                    x1 = x_ret7;
                    carry1 = carry_ret4;
                    zero1 = zero_ret4;
                    negative1 = negative_ret4;
                    overflow1 = overflow_ret4;
                    direct_page = dp_ret4;
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
        } else {
            uint16_t value3 = BUS16(c, 0xD04F16 + value);
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
            if (a_all == value3) {
                r->x = value;
                r->y = (uint8_t)y;
                r->c = a_all >= value3;
                r->z = a_all == value3;
                r->n = (uint16_t)(a_all - value3) & 0x8000;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                uint16_t dp_ret5 = r->dp;
                bool m_ret5 = r->mf;
                bool x_ret8 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t x_ret9 = r->x;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool overflow_ret5 = r->v;
                m_flag4 = m_ret5;
                x_flag4 = x_ret8;
                a4 = (uint8_t)a_all5;
                a_hi4 = a_all5 >> 8;
                x4 = x_ret9;
                carry4 = carry_ret5;
                zero4 = zero_ret5;
                negative4 = negative_ret5;
                overflow4 = overflow_ret5;
                direct_page4 = dp_ret5;
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
                if (a_all >= value3) {
                    r->x = value;
                    r->y = (uint8_t)y;
                    r->c = a_all >= value3;
                    r->z = a_all == value3;
                    r->n = (uint16_t)(a_all - value3) & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x182C, 0xC1028D); GUARD_JSR(c, sp_call, 0x182C); } /* jump_actor_script_after_2_bytes */
                    uint16_t dp_ret6 = r->dp;
                    bool m_ret6 = r->mf;
                    bool x_ret10 = r->xf;
                    uint16_t a_all6 = r->a;
                    uint16_t x_ret11 = r->x;
                    bool carry_ret6 = r->c;
                    bool zero_ret6 = r->z;
                    bool negative_ret6 = r->n;
                    bool overflow_ret6 = r->v;
                    m_flag3 = m_ret6;
                    x_flag3 = x_ret10;
                    a3 = (uint8_t)a_all6;
                    a_hi3 = a_all6 >> 8;
                    x3 = x_ret11;
                    carry3 = carry_ret6;
                    zero3 = zero_ret6;
                    negative3 = negative_ret6;
                    overflow3 = overflow_ret6;
                    direct_page3 = dp_ret6;
                } else {
                    r->x = value;
                    r->y = (uint8_t)y;
                    r->c = a_all >= value3;
                    r->z = a_all == value3;
                    r->n = (uint16_t)(a_all - value3) & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                    uint16_t dp_ret7 = r->dp;
                    bool m_ret7 = r->mf;
                    bool x_ret12 = r->xf;
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret13 = r->x;
                    bool carry_ret7 = r->c;
                    bool zero_ret7 = r->z;
                    bool negative_ret7 = r->n;
                    bool overflow_ret7 = r->v;
                    m_flag3 = m_ret7;
                    x_flag3 = x_ret12;
                    a3 = (uint8_t)a_all7;
                    a_hi3 = a_all7 >> 8;
                    x3 = x_ret13;
                    carry3 = carry_ret7;
                    zero3 = zero_ret7;
                    negative3 = negative_ret7;
                    overflow3 = overflow_ret7;
                    direct_page3 = dp_ret7;
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
    } else {
        uint16_t value4 = RAM16(0x0144 + y);
        if (m_ret) {
            uint8_t value5 = BUS8(c, 0xD04F16 + value4);
            bool m_flag6;
            bool x_flag6;
            uint8_t a6;
            uint8_t a_hi6;
            uint16_t x6;
            bool carry6;
            bool zero6;
            bool negative6;
            bool overflow6;
            uint16_t direct_page6;
            if ((uint8_t)a_all == value5) {
                r->x = value4;
                r->c = (uint8_t)a_all >= value5;
                r->z = (uint8_t)a_all == value5;
                r->n = (uint8_t)((uint8_t)a_all - value5) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                uint16_t dp_ret8 = r->dp;
                bool m_ret8 = r->mf;
                bool x_ret14 = r->xf;
                uint16_t a_all8 = r->a;
                uint16_t x_ret15 = r->x;
                bool carry_ret8 = r->c;
                bool zero_ret8 = r->z;
                bool negative_ret8 = r->n;
                bool overflow_ret8 = r->v;
                m_flag6 = m_ret8;
                x_flag6 = x_ret14;
                a6 = (uint8_t)a_all8;
                a_hi6 = a_all8 >> 8;
                x6 = x_ret15;
                carry6 = carry_ret8;
                zero6 = zero_ret8;
                negative6 = negative_ret8;
                overflow6 = overflow_ret8;
                direct_page6 = dp_ret8;
            } else {
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
                if ((uint8_t)a_all >= value5) {
                    r->x = value4;
                    r->c = (uint8_t)a_all >= value5;
                    r->z = (uint8_t)a_all == value5;
                    r->n = (uint8_t)((uint8_t)a_all - value5) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x182C, 0xC1028D); GUARD_JSR(c, sp_call, 0x182C); } /* jump_actor_script_after_2_bytes */
                    uint16_t dp_ret9 = r->dp;
                    bool m_ret9 = r->mf;
                    bool x_ret16 = r->xf;
                    uint16_t a_all9 = r->a;
                    uint16_t x_ret17 = r->x;
                    bool carry_ret9 = r->c;
                    bool zero_ret9 = r->z;
                    bool negative_ret9 = r->n;
                    bool overflow_ret9 = r->v;
                    m_flag5 = m_ret9;
                    x_flag5 = x_ret16;
                    a5 = (uint8_t)a_all9;
                    a_hi5 = a_all9 >> 8;
                    x5 = x_ret17;
                    carry5 = carry_ret9;
                    zero5 = zero_ret9;
                    negative5 = negative_ret9;
                    overflow5 = overflow_ret9;
                    direct_page5 = dp_ret9;
                } else {
                    r->x = value4;
                    r->c = (uint8_t)a_all >= value5;
                    r->z = (uint8_t)a_all == value5;
                    r->n = (uint8_t)((uint8_t)a_all - value5) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                    uint16_t dp_ret10 = r->dp;
                    bool m_ret10 = r->mf;
                    bool x_ret18 = r->xf;
                    uint16_t a_all10 = r->a;
                    uint16_t x_ret19 = r->x;
                    bool carry_ret10 = r->c;
                    bool zero_ret10 = r->z;
                    bool negative_ret10 = r->n;
                    bool overflow_ret10 = r->v;
                    m_flag5 = m_ret10;
                    x_flag5 = x_ret18;
                    a5 = (uint8_t)a_all10;
                    a_hi5 = a_all10 >> 8;
                    x5 = x_ret19;
                    carry5 = carry_ret10;
                    zero5 = zero_ret10;
                    negative5 = negative_ret10;
                    overflow5 = overflow_ret10;
                    direct_page5 = dp_ret10;
                }
                m_flag6 = m_flag5;
                x_flag6 = x_flag5;
                a6 = a5;
                a_hi6 = a_hi5;
                x6 = x5;
                carry6 = carry5;
                zero6 = zero5;
                negative6 = negative5;
                overflow6 = overflow5;
                direct_page6 = direct_page5;
            }
            r->a = (a_hi6 << 8) | a6;
            r->x = x6;
            r->c = carry6;
            r->z = zero6;
            r->n = negative6;
            r->v = overflow6;
            r->mf = m_flag6;
            r->xf = x_flag6;
            r->dp = direct_page6;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value6 = BUS16(c, 0xD04F16 + value4);
            bool m_flag8;
            bool x_flag8;
            uint8_t a8;
            uint8_t a_hi8;
            uint16_t x8;
            bool carry8;
            bool zero8;
            bool negative8;
            bool overflow8;
            uint16_t direct_page8;
            if (a_all == value6) {
                r->x = value4;
                r->c = a_all >= value6;
                r->z = a_all == value6;
                r->n = (uint16_t)(a_all - value6) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                uint16_t dp_ret11 = r->dp;
                bool m_ret11 = r->mf;
                bool x_ret20 = r->xf;
                uint16_t a_all11 = r->a;
                uint16_t x_ret21 = r->x;
                bool carry_ret11 = r->c;
                bool zero_ret11 = r->z;
                bool negative_ret11 = r->n;
                bool overflow_ret11 = r->v;
                m_flag8 = m_ret11;
                x_flag8 = x_ret20;
                a8 = (uint8_t)a_all11;
                a_hi8 = a_all11 >> 8;
                x8 = x_ret21;
                carry8 = carry_ret11;
                zero8 = zero_ret11;
                negative8 = negative_ret11;
                overflow8 = overflow_ret11;
                direct_page8 = dp_ret11;
            } else {
                bool m_flag7;
                bool x_flag7;
                uint8_t a7;
                uint8_t a_hi7;
                uint16_t x7;
                bool carry7;
                bool zero7;
                bool negative7;
                bool overflow7;
                uint16_t direct_page7;
                if (a_all >= value6) {
                    r->x = value4;
                    r->c = a_all >= value6;
                    r->z = a_all == value6;
                    r->n = (uint16_t)(a_all - value6) & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x182C, 0xC1028D); GUARD_JSR(c, sp_call, 0x182C); } /* jump_actor_script_after_2_bytes */
                    uint16_t dp_ret12 = r->dp;
                    bool m_ret12 = r->mf;
                    bool x_ret22 = r->xf;
                    uint16_t a_all12 = r->a;
                    uint16_t x_ret23 = r->x;
                    bool carry_ret12 = r->c;
                    bool zero_ret12 = r->z;
                    bool negative_ret12 = r->n;
                    bool overflow_ret12 = r->v;
                    m_flag7 = m_ret12;
                    x_flag7 = x_ret22;
                    a7 = (uint8_t)a_all12;
                    a_hi7 = a_all12 >> 8;
                    x7 = x_ret23;
                    carry7 = carry_ret12;
                    zero7 = zero_ret12;
                    negative7 = negative_ret12;
                    overflow7 = overflow_ret12;
                    direct_page7 = dp_ret12;
                } else {
                    r->x = value4;
                    r->c = a_all >= value6;
                    r->z = a_all == value6;
                    r->n = (uint16_t)(a_all - value6) & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1827, 0xC1021B); GUARD_JSR(c, sp_call, 0x1827); } /* skip_actor_script_after_2_bytes */
                    uint16_t dp_ret13 = r->dp;
                    bool m_ret13 = r->mf;
                    bool x_ret24 = r->xf;
                    uint16_t a_all13 = r->a;
                    uint16_t x_ret25 = r->x;
                    bool carry_ret13 = r->c;
                    bool zero_ret13 = r->z;
                    bool negative_ret13 = r->n;
                    bool overflow_ret13 = r->v;
                    m_flag7 = m_ret13;
                    x_flag7 = x_ret24;
                    a7 = (uint8_t)a_all13;
                    a_hi7 = a_all13 >> 8;
                    x7 = x_ret25;
                    carry7 = carry_ret13;
                    zero7 = zero_ret13;
                    negative7 = negative_ret13;
                    overflow7 = overflow_ret13;
                    direct_page7 = dp_ret13;
                }
                m_flag8 = m_flag7;
                x_flag8 = x_flag7;
                a8 = a7;
                a_hi8 = a_hi7;
                x8 = x7;
                carry8 = carry7;
                zero8 = zero7;
                negative8 = negative7;
                overflow8 = overflow7;
                direct_page8 = direct_page7;
            }
            r->a = (a_hi8 << 8) | a8;
            r->x = x8;
            r->c = carry8;
            r->z = zero8;
            r->n = negative8;
            r->v = overflow8;
            r->mf = m_flag8;
            r->xf = x_flag8;
            r->dp = direct_page8;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC11817, SOM_RTS, "gen", actor_script_if_variable_2_greater, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 23, 9)
