#include "som_c.h"

/* C07E80 advance_native_shop_vblank_input_and_active_ring_phase   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/advance_native_shop_vblank_input_and_active_ring_phase.s
 * Documented in docs/event-menu-shop-dialogue.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCNV.
 */
static void advance_native_shop_vblank_input_and_active_ring_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E82, 0xC0695E); GUARD_JSR(c, sp_call, 0x7E82); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    uint8_t value = BUS8(c, (db_ret << 0x10) + 0x1803);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 0x40) == 0) {
        m_flag = 1;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = value & 0x40;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        r->v = value & 0x40;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7E8E, 0xC06BF8); GUARD_JSR(c, sp_call, 0x7E8E); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret3;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    uint16_t value2 = BUS16(c, (data_bank << 0x10) + 0x1800);
    r->a = value2;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->n = value2 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07E80, SOM_RTS, "gen", advance_native_shop_vblank_input_and_active_ring_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_N | L_V, 1, -1, 0, 21, 9)
