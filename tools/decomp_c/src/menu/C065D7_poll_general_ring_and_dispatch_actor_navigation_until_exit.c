#include "som_c.h"

/* C065D7 poll_general_ring_and_dispatch_actor_navigation_until_exit   [class C, 64 bytes, 25 instructions]
 * Source: src/rom/poll_general_ring_and_dispatch_actor_navigation_until_exit.s
 * Documented in docs/event-menu-general.md
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: BXYCZNV.
 */
static void poll_general_ring_and_dispatch_actor_navigation_until_exit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t a_hi_65ed = 0;
    uint8_t x_65ed = 0;
    uint8_t y_65ed = 0;
    bool overflow_65ed = 0;
    uint16_t direct_page_65ed = 0;
    uint8_t data_bank_65ed = 0;
    uint8_t a_hi_65ed2 = 0;
    uint16_t x_65ed2 = 0;
    uint16_t y_65ed2 = 0;
    bool overflow_65ed2 = 0;
    uint16_t direct_page_65ed2 = 0;
    uint8_t data_bank_65ed2 = 0;
    uint8_t a_hi_6610 = 0;
    uint8_t x_6610 = 0;
    uint8_t y_6610 = 0;
    bool carry_6610 = 0;
    bool zero_6610 = 0;
    bool negative_6610 = 0;
    bool overflow_6610 = 0;
    uint16_t direct_page_6610 = 0;
    uint8_t data_bank_6610 = 0;
    uint8_t a_hi_6608 = 0;
    uint8_t x_6608 = 0;
    uint8_t y_6608 = 0;
    bool carry_6608 = 0;
    bool zero_6608 = 0;
    bool negative_6608 = 0;
    bool overflow_6608 = 0;
    uint16_t direct_page_6608 = 0;
    uint8_t data_bank_6608 = 0;
    uint8_t a_hi_66082 = 0;
    uint8_t x_66082 = 0;
    uint8_t y_66082 = 0;
    bool carry_66082 = 0;
    bool zero_66082 = 0;
    bool negative_66082 = 0;
    bool overflow_66082 = 0;
    uint16_t direct_page_66082 = 0;
    uint8_t data_bank_66082 = 0;
    uint8_t a_hi_66102 = 0;
    uint16_t x_66102 = 0;
    uint16_t y_66102 = 0;
    bool carry_66102 = 0;
    bool zero_66102 = 0;
    bool negative_66102 = 0;
    bool overflow_66102 = 0;
    uint16_t direct_page_66102 = 0;
    uint8_t data_bank_66102 = 0;
    uint8_t a_hi_66083 = 0;
    uint16_t x_66083 = 0;
    uint16_t y_66083 = 0;
    bool carry_66083 = 0;
    bool zero_66083 = 0;
    bool negative_66083 = 0;
    bool overflow_66083 = 0;
    uint16_t direct_page_66083 = 0;
    uint8_t data_bank_66083 = 0;
    uint8_t a_hi_66084 = 0;
    uint16_t x_66084 = 0;
    uint16_t y_66084 = 0;
    bool carry_66084 = 0;
    bool zero_66084 = 0;
    bool negative_66084 = 0;
    bool overflow_66084 = 0;
    uint16_t direct_page_66084 = 0;
    uint8_t data_bank_66084 = 0;
    uint8_t a_hi_66103 = 0;
    uint8_t x_66103 = 0;
    uint8_t y_66103 = 0;
    bool carry_66103 = 0;
    bool zero_66103 = 0;
    bool negative_66103 = 0;
    bool overflow_66103 = 0;
    uint16_t direct_page_66103 = 0;
    uint8_t data_bank_66103 = 0;
    uint8_t a_hi_66104 = 0;
    uint16_t x_66104 = 0;
    uint16_t y_66104 = 0;
    bool carry_66104 = 0;
    bool zero_66104 = 0;
    bool negative_66104 = 0;
    bool overflow_66104 = 0;
    uint16_t direct_page_66104 = 0;
    uint8_t data_bank_66104 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65D9, 0xC0695E); GUARD_JSR(c, sp_call, 0x65D9); } /* wait_vblank_before_polling_native_menu_input */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65DC, 0xC06BF8); GUARD_JSR(c, sp_call, 0x65DC); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    uint8_t value = BUS8(c, (db_ret2 << 0x10) + 0x1812);
    if (value != 0) {
        a_hi_65ed = a_all2 >> 8;
        x_65ed = (uint8_t)x_ret4;
        y_65ed = (uint8_t)y_ret2;
        overflow_65ed = overflow_ret2;
        direct_page_65ed = dp_ret2;
        data_bank_65ed = db_ret2;
        goto shared_65ED;
    }
    r->a = (a_all2 >> 8 << 8) | value;
    r->x = (uint8_t)x_ret4;
    r->y = (uint8_t)y_ret2;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E6, 0xC06740); GUARD_JSR(c, sp_call, 0x65E6); } /* request_native_menu_vertical_inventory_transition */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E9, 0xC066F3); GUARD_JSR(c, sp_call, 0x65E9); } /* update_native_menu_horizontal_repeat_and_description_request */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65EC, 0xC06775); GUARD_JSR(c, sp_call, 0x65EC); } /* cycle_shop_actor_then_consume_held_actor_change_input */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret4 = r->y;
    bool overflow_ret4 = r->v;
    a_hi_65ed2 = a_all5 >> 8;
    x_65ed2 = x_ret9;
    y_65ed2 = y_ret4;
    overflow_65ed2 = overflow_ret4;
    direct_page_65ed2 = dp_ret3;
    data_bank_65ed2 = db_ret3;
    shared_65ED_1:;
    uint8_t value6 = BUS8(c, (data_bank_65ed2 << 0x10) + 0x19F0);
    if (value6 == 0xC0) {
        uint8_t value7 = BUS8(c, (data_bank_65ed2 << 0x10) + 0x19F1);
        if (value7 & 0x80) {
            a_hi_66102 = a_hi_65ed2;
            x_66102 = x_65ed2;
            y_66102 = y_65ed2;
            carry_66102 = value6 >= 0xC0;
            zero_66102 = value7 == 0;
            negative_66102 = value7 & 0x80;
            overflow_66102 = overflow_65ed2;
            direct_page_66102 = direct_page_65ed2;
            data_bank_66102 = data_bank_65ed2;
            goto shared_6610_1;
        }
        r->x = x_65ed2;
        r->y = y_65ed2;
        r->c = value6 >= 0xC0;
        r->v = overflow_65ed2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_65ed2;
        r->dp = direct_page_65ed2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6604, 0xC0692D); GUARD_JSR(c, sp_call, 0x6604); } /* request_event_menu_loop_and_initialize_input_state */
        uint16_t a_all12 = r->a;
        bool zero_ret12 = r->z;
        bool negative_ret12 = r->n;
        BUS16_SET(c, (data_bank_65ed2 << 0x10) + 0x1826, 0);
        a_hi_66083 = a_all12 >> 8;
        x_66083 = x_65ed2;
        y_66083 = y_65ed2;
        carry_66083 = value6 >= 0xC0;
        zero_66083 = zero_ret12;
        negative_66083 = negative_ret12;
        overflow_66083 = overflow_65ed2;
        direct_page_66083 = direct_page_65ed2;
        data_bank_66083 = data_bank_65ed2;
        goto shared_6608_2;
    }
    uint8_t value8 = BUS8(c, (data_bank_65ed2 << 0x10) + 0x1826);
    if (value8 == 0) {
        a_hi_66084 = a_hi_65ed2;
        x_66084 = x_65ed2;
        y_66084 = y_65ed2;
        carry_66084 = value6 >= 0xC0;
        zero_66084 = value8 == 0;
        negative_66084 = value8 & 0x80;
        overflow_66084 = overflow_65ed2;
        direct_page_66084 = direct_page_65ed2;
        data_bank_66084 = data_bank_65ed2;
        goto shared_6608_3;
    }
    r->a = (a_hi_65ed2 << 8) | value8;
    r->x = x_65ed2;
    r->y = y_65ed2;
    r->c = value6 >= 0xC0;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->v = overflow_65ed2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_65ed2;
    r->dp = direct_page_65ed2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65D9, 0xC0695E); GUARD_JSR(c, sp_call, 0x65D9); } /* wait_vblank_before_polling_native_menu_input */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65DC, 0xC06BF8); GUARD_JSR(c, sp_call, 0x65DC); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    uint16_t a_all14 = r->a;
    uint16_t x_ret22 = r->x;
    uint16_t y_ret10 = r->y;
    bool overflow_ret10 = r->v;
    uint8_t value9 = BUS8(c, (db_ret8 << 0x10) + 0x1812);
    if (value9 != 0) {
        a_hi_65ed = a_all14 >> 8;
        x_65ed = (uint8_t)x_ret22;
        y_65ed = (uint8_t)y_ret10;
        overflow_65ed = overflow_ret10;
        direct_page_65ed = dp_ret8;
        data_bank_65ed = db_ret8;
        goto shared_65ED;
    }
    r->a = (a_all14 >> 8 << 8) | value9;
    r->x = (uint8_t)x_ret22;
    r->y = (uint8_t)y_ret10;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E6, 0xC06740); GUARD_JSR(c, sp_call, 0x65E6); } /* request_native_menu_vertical_inventory_transition */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E9, 0xC066F3); GUARD_JSR(c, sp_call, 0x65E9); } /* update_native_menu_horizontal_repeat_and_description_request */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65EC, 0xC06775); GUARD_JSR(c, sp_call, 0x65EC); } /* cycle_shop_actor_then_consume_held_actor_change_input */
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    uint16_t a_all17 = r->a;
    uint16_t x_ret27 = r->x;
    uint16_t y_ret12 = r->y;
    bool overflow_ret12 = r->v;
    a_hi_65ed2 = a_all17 >> 8;
    x_65ed2 = x_ret27;
    y_65ed2 = y_ret12;
    overflow_65ed2 = overflow_ret12;
    direct_page_65ed2 = dp_ret9;
    data_bank_65ed2 = db_ret9;
    goto shared_65ED_1;
    shared_65ED:;
    uint8_t value2 = BUS8(c, (data_bank_65ed << 0x10) + 0x19F0);
    if (value2 == 0xC0) {
        uint8_t value3 = BUS8(c, (data_bank_65ed << 0x10) + 0x19F1);
        if (value3 & 0x80) {
            a_hi_6610 = a_hi_65ed;
            x_6610 = x_65ed;
            y_6610 = y_65ed;
            carry_6610 = value2 >= 0xC0;
            zero_6610 = value3 == 0;
            negative_6610 = value3 & 0x80;
            overflow_6610 = overflow_65ed;
            direct_page_6610 = direct_page_65ed;
            data_bank_6610 = data_bank_65ed;
            goto shared_6610;
        }
        r->x = x_65ed;
        r->y = y_65ed;
        r->c = value2 >= 0xC0;
        r->v = overflow_65ed;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_65ed;
        r->dp = direct_page_65ed;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6604, 0xC0692D); GUARD_JSR(c, sp_call, 0x6604); } /* request_event_menu_loop_and_initialize_input_state */
        uint16_t a_all6 = r->a;
        bool zero_ret6 = r->z;
        bool negative_ret6 = r->n;
        BUS16_SET(c, (data_bank_65ed << 0x10) + 0x1826, 0);
        a_hi_6608 = a_all6 >> 8;
        x_6608 = x_65ed;
        y_6608 = y_65ed;
        carry_6608 = value2 >= 0xC0;
        zero_6608 = zero_ret6;
        negative_6608 = negative_ret6;
        overflow_6608 = overflow_65ed;
        direct_page_6608 = direct_page_65ed;
        data_bank_6608 = data_bank_65ed;
        goto shared_6608;
    }
    uint8_t value4 = BUS8(c, (data_bank_65ed << 0x10) + 0x1826);
    if (value4 == 0) {
        a_hi_66082 = a_hi_65ed;
        x_66082 = x_65ed;
        y_66082 = y_65ed;
        carry_66082 = value2 >= 0xC0;
        zero_66082 = value4 == 0;
        negative_66082 = value4 & 0x80;
        overflow_66082 = overflow_65ed;
        direct_page_66082 = direct_page_65ed;
        data_bank_66082 = data_bank_65ed;
        goto shared_6608_1;
    }
    r->a = (a_hi_65ed << 8) | value4;
    r->x = x_65ed;
    r->y = y_65ed;
    r->c = value2 >= 0xC0;
    r->z = value4 == 0;
    r->n = value4 & 0x80;
    r->v = overflow_65ed;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_65ed;
    r->dp = direct_page_65ed;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65D9, 0xC0695E); GUARD_JSR(c, sp_call, 0x65D9); } /* wait_vblank_before_polling_native_menu_input */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65DC, 0xC06BF8); GUARD_JSR(c, sp_call, 0x65DC); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    uint16_t a_all8 = r->a;
    uint16_t x_ret13 = r->x;
    uint16_t y_ret6 = r->y;
    bool overflow_ret6 = r->v;
    uint8_t value5 = BUS8(c, (db_ret5 << 0x10) + 0x1812);
    if (value5 != 0) {
        a_hi_65ed = a_all8 >> 8;
        x_65ed = (uint8_t)x_ret13;
        y_65ed = (uint8_t)y_ret6;
        overflow_65ed = overflow_ret6;
        direct_page_65ed = dp_ret5;
        data_bank_65ed = db_ret5;
        goto shared_65ED;
    }
    r->a = (a_all8 >> 8 << 8) | value5;
    r->x = (uint8_t)x_ret13;
    r->y = (uint8_t)y_ret6;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E6, 0xC06740); GUARD_JSR(c, sp_call, 0x65E6); } /* request_native_menu_vertical_inventory_transition */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65E9, 0xC066F3); GUARD_JSR(c, sp_call, 0x65E9); } /* update_native_menu_horizontal_repeat_and_description_request */
    { const uint16_t sp_call = r->sp; JSR(c, 0x65EC, 0xC06775); GUARD_JSR(c, sp_call, 0x65EC); } /* cycle_shop_actor_then_consume_held_actor_change_input */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    uint16_t a_all11 = r->a;
    uint16_t x_ret18 = r->x;
    uint16_t y_ret8 = r->y;
    bool overflow_ret8 = r->v;
    a_hi_65ed2 = a_all11 >> 8;
    x_65ed2 = x_ret18;
    y_65ed2 = y_ret8;
    overflow_65ed2 = overflow_ret8;
    direct_page_65ed2 = dp_ret6;
    data_bank_65ed2 = db_ret6;
    goto shared_65ED_1;
    shared_6610:;
    RAM16_SET(0x00CC + direct_page_6610, 0);
    RAM16_SET(0x00CD + direct_page_6610, 0);
    r->a = (a_hi_6610 << 8) | (uint8_t)a;
    r->x = x_6610;
    r->y = y_6610;
    r->c = carry_6610;
    r->z = zero_6610;
    r->n = negative_6610;
    r->v = overflow_6610;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_6610;
    r->dp = direct_page_6610;
    RETURN_RTS(c);
    shared_6608:;
    r->a = (a_hi_6608 << 8) | (uint8_t)a;
    r->x = x_6608;
    r->y = y_6608;
    r->c = carry_6608;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_6608;
    r->dp = direct_page_6608;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660B, 0xD0D5A0); GUARD_JSL(c, sp_call, 0x660B); } /* select_native_menu_window_close_script_when_needed */
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660F, 0xD0CD6D); GUARD_JSL(c, sp_call, 0x660F); } /* restore_saved_menu_palette_and_request_upload */
    bool m_ret11 = r->mf;
    bool x_ret30 = r->xf;
    uint16_t a_all19 = r->a;
    uint16_t x_ret31 = r->x;
    uint16_t y_ret14 = r->y;
    bool carry_ret14 = r->c;
    bool zero_ret19 = r->z;
    bool negative_ret19 = r->n;
    bool overflow_ret14 = r->v;
    if (m_ret11) {
        if (x_ret30) {
            a_hi_6610 = a_all19 >> 8;
            x_6610 = (uint8_t)x_ret31;
            y_6610 = (uint8_t)y_ret14;
            carry_6610 = carry_ret14;
            zero_6610 = zero_ret19;
            negative_6610 = negative_ret19;
            overflow_6610 = overflow_ret14;
            direct_page_6610 = dp_ret10;
            data_bank_6610 = db_ret10;
            goto shared_6610;
        } else {
            a_hi_66102 = a_all19 >> 8;
            x_66102 = x_ret31;
            y_66102 = y_ret14;
            carry_66102 = carry_ret14;
            zero_66102 = zero_ret19;
            negative_66102 = negative_ret19;
            overflow_66102 = overflow_ret14;
            direct_page_66102 = dp_ret10;
            data_bank_66102 = db_ret10;
            goto shared_6610_1;
        }
    } else {
        if (x_ret30) {
            a_hi_66103 = a_all19 >> 8;
            x_66103 = (uint8_t)x_ret31;
            y_66103 = (uint8_t)y_ret14;
            carry_66103 = carry_ret14;
            zero_66103 = zero_ret19;
            negative_66103 = negative_ret19;
            overflow_66103 = overflow_ret14;
            direct_page_66103 = dp_ret10;
            data_bank_66103 = db_ret10;
            goto shared_6610_2;
        } else {
            a_hi_66104 = a_all19 >> 8;
            x_66104 = x_ret31;
            y_66104 = y_ret14;
            carry_66104 = carry_ret14;
            zero_66104 = zero_ret19;
            negative_66104 = negative_ret19;
            overflow_66104 = overflow_ret14;
            direct_page_66104 = dp_ret10;
            data_bank_66104 = db_ret10;
            goto shared_6610_3;
        }
    }
    shared_6608_1:;
    r->a = (a_hi_66082 << 8) | (uint8_t)a;
    r->x = x_66082;
    r->y = y_66082;
    r->c = carry_66082;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_66082;
    r->dp = direct_page_66082;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660B, 0xD0D5A0); GUARD_JSL(c, sp_call, 0x660B); } /* select_native_menu_window_close_script_when_needed */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660F, 0xD0CD6D); GUARD_JSL(c, sp_call, 0x660F); } /* restore_saved_menu_palette_and_request_upload */
    bool m_ret13 = r->mf;
    bool x_ret34 = r->xf;
    uint16_t a_all21 = r->a;
    uint16_t x_ret35 = r->x;
    uint16_t y_ret16 = r->y;
    bool carry_ret16 = r->c;
    bool zero_ret21 = r->z;
    bool negative_ret21 = r->n;
    bool overflow_ret16 = r->v;
    if (m_ret13) {
        if (x_ret34) {
            a_hi_6610 = a_all21 >> 8;
            x_6610 = (uint8_t)x_ret35;
            y_6610 = (uint8_t)y_ret16;
            carry_6610 = carry_ret16;
            zero_6610 = zero_ret21;
            negative_6610 = negative_ret21;
            overflow_6610 = overflow_ret16;
            direct_page_6610 = dp_ret11;
            data_bank_6610 = db_ret11;
            goto shared_6610;
        } else {
            a_hi_66102 = a_all21 >> 8;
            x_66102 = x_ret35;
            y_66102 = y_ret16;
            carry_66102 = carry_ret16;
            zero_66102 = zero_ret21;
            negative_66102 = negative_ret21;
            overflow_66102 = overflow_ret16;
            direct_page_66102 = dp_ret11;
            data_bank_66102 = db_ret11;
            goto shared_6610_1;
        }
    } else {
        if (x_ret34) {
            a_hi_66103 = a_all21 >> 8;
            x_66103 = (uint8_t)x_ret35;
            y_66103 = (uint8_t)y_ret16;
            carry_66103 = carry_ret16;
            zero_66103 = zero_ret21;
            negative_66103 = negative_ret21;
            overflow_66103 = overflow_ret16;
            direct_page_66103 = dp_ret11;
            data_bank_66103 = db_ret11;
            goto shared_6610_2;
        } else {
            a_hi_66104 = a_all21 >> 8;
            x_66104 = x_ret35;
            y_66104 = y_ret16;
            carry_66104 = carry_ret16;
            zero_66104 = zero_ret21;
            negative_66104 = negative_ret21;
            overflow_66104 = overflow_ret16;
            direct_page_66104 = dp_ret11;
            data_bank_66104 = db_ret11;
            goto shared_6610_3;
        }
    }
    shared_6610_1:;
    RAM16_SET(0x00CC + direct_page_66102, 0);
    RAM16_SET(0x00CD + direct_page_66102, 0);
    r->a = (a_hi_66102 << 8) | (uint8_t)a;
    r->x = x_66102;
    r->y = y_66102;
    r->c = carry_66102;
    r->z = zero_66102;
    r->n = negative_66102;
    r->v = overflow_66102;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_66102;
    r->dp = direct_page_66102;
    RETURN_RTS(c);
    shared_6608_2:;
    r->a = (a_hi_66083 << 8) | (uint8_t)a;
    r->x = x_66083;
    r->y = y_66083;
    r->c = carry_66083;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_66083;
    r->dp = direct_page_66083;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660B, 0xD0D5A0); GUARD_JSL(c, sp_call, 0x660B); } /* select_native_menu_window_close_script_when_needed */
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660F, 0xD0CD6D); GUARD_JSL(c, sp_call, 0x660F); } /* restore_saved_menu_palette_and_request_upload */
    bool m_ret15 = r->mf;
    bool x_ret38 = r->xf;
    uint16_t a_all23 = r->a;
    uint16_t x_ret39 = r->x;
    uint16_t y_ret18 = r->y;
    bool carry_ret18 = r->c;
    bool zero_ret23 = r->z;
    bool negative_ret23 = r->n;
    bool overflow_ret18 = r->v;
    if (m_ret15) {
        if (x_ret38) {
            a_hi_6610 = a_all23 >> 8;
            x_6610 = (uint8_t)x_ret39;
            y_6610 = (uint8_t)y_ret18;
            carry_6610 = carry_ret18;
            zero_6610 = zero_ret23;
            negative_6610 = negative_ret23;
            overflow_6610 = overflow_ret18;
            direct_page_6610 = dp_ret12;
            data_bank_6610 = db_ret12;
            goto shared_6610;
        } else {
            a_hi_66102 = a_all23 >> 8;
            x_66102 = x_ret39;
            y_66102 = y_ret18;
            carry_66102 = carry_ret18;
            zero_66102 = zero_ret23;
            negative_66102 = negative_ret23;
            overflow_66102 = overflow_ret18;
            direct_page_66102 = dp_ret12;
            data_bank_66102 = db_ret12;
            goto shared_6610_1;
        }
    } else {
        if (x_ret38) {
            a_hi_66103 = a_all23 >> 8;
            x_66103 = (uint8_t)x_ret39;
            y_66103 = (uint8_t)y_ret18;
            carry_66103 = carry_ret18;
            zero_66103 = zero_ret23;
            negative_66103 = negative_ret23;
            overflow_66103 = overflow_ret18;
            direct_page_66103 = dp_ret12;
            data_bank_66103 = db_ret12;
            goto shared_6610_2;
        } else {
            a_hi_66104 = a_all23 >> 8;
            x_66104 = x_ret39;
            y_66104 = y_ret18;
            carry_66104 = carry_ret18;
            zero_66104 = zero_ret23;
            negative_66104 = negative_ret23;
            overflow_66104 = overflow_ret18;
            direct_page_66104 = dp_ret12;
            data_bank_66104 = db_ret12;
            goto shared_6610_3;
        }
    }
    shared_6608_3:;
    r->a = (a_hi_66084 << 8) | (uint8_t)a;
    r->x = x_66084;
    r->y = y_66084;
    r->c = carry_66084;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_66084;
    r->dp = direct_page_66084;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660B, 0xD0D5A0); GUARD_JSL(c, sp_call, 0x660B); } /* select_native_menu_window_close_script_when_needed */
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret13 = r->db;
    { const uint16_t sp_call = r->sp; JSL(c, 0x660F, 0xD0CD6D); GUARD_JSL(c, sp_call, 0x660F); } /* restore_saved_menu_palette_and_request_upload */
    bool m_ret17 = r->mf;
    bool x_ret42 = r->xf;
    uint16_t a_all25 = r->a;
    uint16_t x_ret43 = r->x;
    uint16_t y_ret20 = r->y;
    bool carry_ret20 = r->c;
    bool zero_ret25 = r->z;
    bool negative_ret25 = r->n;
    bool overflow_ret20 = r->v;
    if (m_ret17) {
        if (x_ret42) {
            a_hi_6610 = a_all25 >> 8;
            x_6610 = (uint8_t)x_ret43;
            y_6610 = (uint8_t)y_ret20;
            carry_6610 = carry_ret20;
            zero_6610 = zero_ret25;
            negative_6610 = negative_ret25;
            overflow_6610 = overflow_ret20;
            direct_page_6610 = dp_ret13;
            data_bank_6610 = db_ret13;
            goto shared_6610;
        } else {
            a_hi_66102 = a_all25 >> 8;
            x_66102 = x_ret43;
            y_66102 = y_ret20;
            carry_66102 = carry_ret20;
            zero_66102 = zero_ret25;
            negative_66102 = negative_ret25;
            overflow_66102 = overflow_ret20;
            direct_page_66102 = dp_ret13;
            data_bank_66102 = db_ret13;
            goto shared_6610_1;
        }
    } else {
        if (x_ret42) {
            a_hi_66103 = a_all25 >> 8;
            x_66103 = (uint8_t)x_ret43;
            y_66103 = (uint8_t)y_ret20;
            carry_66103 = carry_ret20;
            zero_66103 = zero_ret25;
            negative_66103 = negative_ret25;
            overflow_66103 = overflow_ret20;
            direct_page_66103 = dp_ret13;
            data_bank_66103 = db_ret13;
            goto shared_6610_2;
        } else {
            a_hi_66104 = a_all25 >> 8;
            x_66104 = x_ret43;
            y_66104 = y_ret20;
            carry_66104 = carry_ret20;
            zero_66104 = zero_ret25;
            negative_66104 = negative_ret25;
            overflow_66104 = overflow_ret20;
            direct_page_66104 = dp_ret13;
            data_bank_66104 = db_ret13;
            goto shared_6610_3;
        }
    }
    shared_6610_2:;
    RAM16_SET(0x00CC + direct_page_66103, 0);
    RAM16_SET(0x00CD + direct_page_66103, 0);
    r->a = (a_hi_66103 << 8) | (uint8_t)a;
    r->x = x_66103;
    r->y = y_66103;
    r->c = carry_66103;
    r->z = zero_66103;
    r->n = negative_66103;
    r->v = overflow_66103;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_66103;
    r->dp = direct_page_66103;
    RETURN_RTS(c);
    shared_6610_3:;
    RAM16_SET(0x00CC + direct_page_66104, 0);
    RAM16_SET(0x00CD + direct_page_66104, 0);
    r->a = (a_hi_66104 << 8) | (uint8_t)a;
    r->x = x_66104;
    r->y = y_66104;
    r->c = carry_66104;
    r->z = zero_66104;
    r->n = negative_66104;
    r->v = overflow_66104;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_66104;
    r->dp = direct_page_66104;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC065D7, SOM_RTS, "gen", poll_general_ring_and_dispatch_actor_navigation_until_exit, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 64, 25)
