#include "som_c.h"

/* C27ABD publish_descriptor_ten_public_reward_after_tick24   [class A, 19 bytes, 8 instructions]
 * Source: src/rom/publish_descriptor_ten_public_reward_after_tick24.s
 * Documented in docs/boss-descriptor-ten-terminal.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void publish_descriptor_ten_public_reward_after_tick24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value < 0x18) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = battle_defence_work;
        y1 = y;
        zero1 = value == 0x18;
        negative1 = (uint16_t)(value - 0x18) & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        uint16_t value2 = RAM16(OBJECT_PHASE + battle_defence_work);
        r->a = value;
        r->x = battle_defence_work;
        r->c = value >= 0x18;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7ACD, 0xC0006F); GUARD_JSL(c, sp_call, 0x7ACD); } /* public_actor_death_jump */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
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
SOM_REGISTER(0xC27ABD, SOM_RTS, "gen", publish_descriptor_ten_public_reward_after_tick24, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 19, 8)
