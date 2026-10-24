#include "som_c.h"

/* C12042 actor_script_if_byte_field_mask_nonzero   [class B, 24 bytes, 9 instructions]
 * Source: src/rom/actor_script_if_byte_field_mask_nonzero.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_if_byte_field_mask_nonzero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2044, 0xC11FEB); GUARD_JSR(c, sp_call, 0x2044); } /* resolve_actor_script_field_reference */
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0x0180 + x_ret);
    uint8_t value3 = BUS8(c, 0xD04F18 + RAM16(0x0144 + y));
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
    if ((value & value3) != 0) {
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2058, 0xC102A0); GUARD_JSR(c, sp_call, 0x2058); } /* jump_actor_script_after_4_bytes */
        uint16_t dp_ret = r->dp;
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
        direct_page = dp_ret;
    } else {
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2053, 0xC1022E); GUARD_JSR(c, sp_call, 0x2053); } /* skip_actor_script_after_4_bytes */
        uint16_t dp_ret2 = r->dp;
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
        direct_page = dp_ret2;
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
SOM_REGISTER(0xC12042, SOM_RTS, "gen", actor_script_if_byte_field_mask_nonzero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 9)
