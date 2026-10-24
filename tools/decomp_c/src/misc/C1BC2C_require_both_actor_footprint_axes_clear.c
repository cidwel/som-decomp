#include "som_c.h"

/* C1BC2C require_both_actor_footprint_axes_clear   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/require_both_actor_footprint_axes_clear.s
 * Documented in docs/actor-map-terrain-queries.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void require_both_actor_footprint_axes_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->c = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC2F, 0xC1B9EA); GUARD_JSR(c, sp_call, 0xBC2F); } /* test_actor_horizontal_footprint_and_redirect_step */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (carry_ret) {
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        r->c = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBC35, 0xC1BAE2); GUARD_JSR(c, sp_call, 0xBC35); } /* test_actor_vertical_footprint_and_redirect_step */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret2 = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret2;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1BC2C, SOM_RTS, "gen", require_both_actor_footprint_axes_clear, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 11, 6)
