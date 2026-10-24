#include "som_c.h"

/* C10695 actor_script_if_variable_1_zero   [class B, 16 bytes, 7 instructions]
 * Source: src/rom/actor_script_if_variable_1_zero.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_if_variable_1_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0697, 0xC10169); GUARD_JSR(c, sp_call, 0x0697); } /* read_actor_script_variable_1 */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
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
    if ((uint8_t)a_all == 0) {
        r->c = (uint8_t)a_all >= 0;
        r->z = (uint8_t)a_all == 0;
        r->n = (uint8_t)a_all & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x06A3, 0xC10285); GUARD_JSR(c, sp_call, 0x06A3); } /* jump_actor_script_after_1_bytes */
        uint16_t dp_ret2 = r->dp;
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret3;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
        direct_page = dp_ret2;
    } else {
        r->c = (uint8_t)a_all >= 0;
        r->z = (uint8_t)a_all == 0;
        r->n = (uint8_t)a_all & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x069E, 0xC10213); GUARD_JSR(c, sp_call, 0x069E); } /* skip_actor_script_after_1_bytes */
        uint16_t dp_ret3 = r->dp;
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret3 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret4;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret5;
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
}
SOM_REGISTER(0xC10695, SOM_RTS, "gen", actor_script_if_variable_1_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
