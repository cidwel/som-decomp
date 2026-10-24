#include "som_c.h"

/* C292A8 advance_native7f_after_twelve_ticks_and_load_four_equal_palettes   [class B, 78 bytes, 28 instructions]
 * Source: src/rom/advance_native7f_after_twelve_ticks_and_load_four_equal_palettes.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_native7f_after_twelve_ticks_and_load_four_equal_palettes(SomCtx *c)
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
    if (value < 0x0C) {
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = battle_defence_work;
        y1 = y;
        zero1 = value == 0x0C;
        negative1 = (uint16_t)(value - 0x0C) & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        RAM16_SET(0x00B0 + battle_defence_work, 0x0200);
        r->a = 0x0112;
        r->x = battle_defence_work;
        r->c = value >= 0x0C;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92C3, 0xC21394); GUARD_JSR(c, sp_call, 0x92C3); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x02D5, 0x0C);
        RAM16_SET(0x02D7, 6);
        r->a = 0x66;
        r->x = 4;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92D8, 0xC22700); GUARD_JSR(c, sp_call, 0x92D8); } /* external */
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        r->a = 0x66;
        r->x = 5;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92E1, 0xC22700); GUARD_JSR(c, sp_call, 0x92E1); } /* external */
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        r->a = 0x66;
        r->x = 6;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92EA, 0xC22700); GUARD_JSR(c, sp_call, 0x92EA); } /* external */
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        r->a = 0x66;
        r->x = 7;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92F3, 0xC22700); GUARD_JSR(c, sp_call, 0x92F3); } /* external */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret4 = r->y;
        bool zero_ret5 = r->z;
        bool negative_ret5 = r->n;
        bool overflow_ret4 = r->v;
        m_flag = m_ret;
        x_flag = x_ret4;
        a1 = (uint8_t)a_all5;
        a_hi1 = a_all5 >> 8;
        x1 = x_ret5;
        y1 = y_ret4;
        zero1 = zero_ret5;
        negative1 = negative_ret5;
        overflow1 = overflow_ret4;
        data_bank = db_ret4;
        direct_page = dp_ret4;
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
SOM_REGISTER(0xC292A8, SOM_RTS, "gen", advance_native7f_after_twelve_ticks_and_load_four_equal_palettes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 78, 28)
