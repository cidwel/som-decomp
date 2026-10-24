#include "som_c.h"

/* C02EBC confirm_native_load_selection_and_apply_save_or_return_title   [class B, 36 bytes, 14 instructions]
 * Source: src/rom/confirm_native_load_selection_and_apply_save_or_return_title.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void confirm_native_load_selection_and_apply_save_or_return_title(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EBE, 0xC0325A); GUARD_JSR(c, sp_call, 0x2EBE); } /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (zero_ret) {
        x_flag2 = 0;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0x0300;
    } else {
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2EC4, 0xC7557A); GUARD_JSL(c, sp_call, 0x2EC4); } /* apply_selected_saved_game_and_restore_live_party */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret = r->v;
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value & 4) == 0) {
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value2 | 1);
            x_flag = x_ret2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret3;
            y1 = y_ret;
            carry1 = carry_ret2;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        } else {
            BUS8_SET(c, (db_ret << 0x10) + 0xA211, 0);
            r->a = (a_all2 >> 8 << 8) | value;
            r->z = (value & 4) == 0;
            r->n = value & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2ED2, 0xC75F4A); GUARD_JSL(c, sp_call, 0x2ED2); } /* select_title_load_or_new_game_page_and_initialize_save_records */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret2 = r->v;
            x_flag = x_ret4;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            carry1 = carry_ret3;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        x_flag2 = x_flag;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value3 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA212);
    BUS8_SET(c, (data_bank2 << 0x10) + 0xA212, value3 & 0xFB);
    r->a = (a_hi2 << 8) | 4;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = (value3 & 4) == 0;
    r->n = 0;
    r->v = overflow2;
    r->mf = 1;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02EBC, SOM_RTS, "gen", confirm_native_load_selection_and_apply_save_or_return_title, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 36, 14)
