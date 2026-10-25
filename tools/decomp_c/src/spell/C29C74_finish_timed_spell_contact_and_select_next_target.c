#include "som_c.h"

/* C29C74 finish_timed_spell_contact_and_select_next_target   [class B, 31 bytes, 12 instructions]
 * Source: src/rom/finish_timed_spell_contact_and_select_next_target.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_timed_spell_contact_and_select_next_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9C78, 0xC29910); GUARD_JSR(c, sp_call, 0x9C78); } /* set_eligible_spell_target_status_and_timer */
    uint16_t y_ret = r->y;
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 < 0x0C) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y_ret;
        carry1 = value2 >= 0x0C;
        zero1 = value2 == 0x0C;
        negative1 = (uint16_t)(value2 - 0x0C) & 0x8000;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->c = value2 >= 0x0C;
        r->z = value2 == 0x0C;
        r->n = (uint16_t)(value2 - 0x0C) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9C83, 0xC29FBD); GUARD_JSR(c, sp_call, 0x9C83); } /* clear_spell_status_and_mark_reciprocal_contacts */
        uint16_t value3 = RAM16(0x0287);
        RAM16_SET(0x0090 + value3, 0x9C93);
        RAM16_SET(0x00BA + value3, 0);
        r->a = 0x9C93;
        r->x = value3;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9C91, 0xC29A74); GUARD_JSR(c, sp_call, 0x9C91); } /* select_next_live_active_party_spell_target */
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret3;
        y1 = y_ret3;
        carry1 = carry_ret2;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29C74, SOM_RTS, "gen", finish_timed_spell_contact_and_select_next_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 12)
