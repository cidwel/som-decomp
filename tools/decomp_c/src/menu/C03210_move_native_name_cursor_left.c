#include "som_c.h"

/* C03210 move_native_name_cursor_left   [class B, 52 bytes, 23 instructions]
 * Source: src/rom/move_native_name_cursor_left.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_native_name_cursor_left(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x3212, 0xC0324A); GUARD_JSR(c, sp_call, 0x3212); } /* reset_native_name_repeat_timer_on_new_direction */
    uint16_t a_all = r->a;
    uint8_t value = RAM8(0xA159);
    uint8_t a1;
    if ((uint8_t)(value - 8) >= 0x13) {
        a1 = (uint8_t)(value - 8);
    } else {
        a1 = 0xDB;
    }
    RAM8(0xA159) = a1;
    r->a = (a_all >> 8 << 8) | a1;
    r->c = (uint8_t)(value - 8) >= 0x13;
    r->v = ((value ^ 8) & (value ^ (uint8_t)(value - 8)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3236, 0xC7503D); GUARD_JSL(c, sp_call, 0x3236); } /* publish_four_native_name_entry_cursor_corners */
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3239, 0xC03269); GUARD_JSR(c, sp_call, 0x3239); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    bool carry_ret3 = r->c;
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret3 + 0x43));
    bool m_flag;
    bool x_flag;
    uint8_t a2;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value2 & 0x0C) != 0) {
        m_flag = 1;
        x_flag = 0;
        a2 = value2 & 0x0C;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret3;
        y1 = y_ret;
        carry1 = carry_ret3;
        zero1 = (value2 & 0x0C) == 0;
        negative1 = value2 & 0x0C & 0x80;
        overflow1 = overflow_ret;
        data_bank = 0x7E;
        direct_page = 0;
    } else {
        r->a = a_all3 >> 8 << 8 | (value2 & 0x0C);
        r->z = (value2 & 0x0C) == 0;
        r->n = value2 & 0x0C & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3242, 0xC01BAA); GUARD_JSR(c, sp_call, 0x3242); } /* external */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret4;
        a2 = (uint8_t)a_all4;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret5;
        y1 = y_ret2;
        carry1 = carry_ret4;
        zero1 = zero_ret4;
        negative1 = negative_ret4;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a2;
    r->x = x1;
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
SOM_REGISTER(0xC03210, SOM_RTS, "gen", move_native_name_cursor_left, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 52, 23)
