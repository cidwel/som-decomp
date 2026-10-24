#include "som_c.h"

/* C23963 boss_external_actor_command_if_selected   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/boss_external_actor_command_if_selected.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AYCV.
 */
static void boss_external_actor_command_if_selected(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0362);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value & 0x8000) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)a;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0200;
    } else {
        r->x = value;
        r->z = value == 0;
        r->n = value & 0x8000;
        { const uint16_t sp_call = r->sp; JSL(c, 0x396B, 0x018003); GUARD_JSL(c, sp_call, 0x396B); } /* actor_command_public_jump */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a >> 8 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23963, SOM_RTS, "gen", boss_external_actor_command_if_selected, 0, L_A | L_Y | L_C | L_V, 1, 0, 0, 10, 4)
