#include "som_c.h"

/* C021DB construct_native_menu_page_with_saved_slots_and_real_text_publication   [class B, 76 bytes, 28 instructions]
 * Source: src/rom/construct_native_menu_page_with_saved_slots_and_real_text_publication.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void construct_native_menu_page_with_saved_slots_and_real_text_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0xA198) = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x21E0, 0xC02227); GUARD_JSR(c, sp_call, 0x21E0); } /* render_native_menu_heading_until_text_command */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA202);
    r->a = (a_all >> 8 << 8) | value;
    r->c = value >= 3;
    r->z = value == 3;
    r->n = (uint8_t)(value - 3) & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x21EA, 0xC02293); GUARD_JSR(c, sp_call, 0x21EA); } /* render_native_menu_description_with_alternating_rows */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA212);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value2 & 2) == 0) {
        x_flag = x_ret3;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = value2 & 0x40;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    } else {
        uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA212);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA212, value3 & 0xFD);
        r->a = (a_all2 >> 8 << 8) | 2;
        r->z = (value3 & 2) == 0;
        r->n = value2 & 0x80;
        r->v = value2 & 0x40;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x21F8, 0xC75979); GUARD_JSL(c, sp_call, 0x21F8); } /* render_four_native_saved_slot_descriptions */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        x_flag = x_ret5;
        a_hi1 = a_all3 >> 8;
        y1 = y_ret3;
        carry1 = carry_ret3;
        overflow1 = overflow_ret3;
        data_bank = db_ret3;
        direct_page = dp_ret3;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x21FB, 0xC02781); GUARD_JSR(c, sp_call, 0x21FB); } /* clear_native_menu_sprite_and_tile_workspaces */
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    uint8_t value4 = BUS8_RDP(c, (data_bank << 0x10) + 0xA202);
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t y2;
    bool overflow2;
    if (value4 != 5) {
        x_flag2 = x_ret7;
        a_hi2 = a_all4 >> 8;
        y2 = y_ret4;
        overflow2 = overflow1;
    } else {
        r->a = (a_all4 >> 8 << 8) | value4;
        r->c = value4 >= 5;
        r->z = value4 == 5;
        r->n = (uint8_t)(value4 - 5) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2206, 0xC76170); GUARD_JSL(c, sp_call, 0x2206); } /* render_native_shop_item_tile_frame */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        uint16_t y_ret5 = r->y;
        bool overflow_ret4 = r->v;
        x_flag2 = 0;
        a_hi2 = a_all5 >> 8;
        y2 = y_ret5;
        overflow2 = overflow_ret4;
    }
    if (x_flag2) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        BUS16_SET(c, (data_bank << 0x10) + 0xA1C7, 0x2050);
        r->a = (a_hi2 << 8) | a;
        r->x = 0x2050;
        r->y = y2;
        r->z = 0;
        r->n = 0;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x220F, 0xC023CF); GUARD_JSR(c, sp_call, 0x220F); } /* expand_native_menu_fixed_ornament_records */
        uint8_t db_ret4 = r->db;
        uint16_t a_all6 = r->a;
        uint16_t x_ret10 = r->x;
        uint8_t value5 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA202);
        uint16_t x1;
        bool zero1;
        if (value5 != 7) {
            x1 = x_ret10;
            zero1 = value5 == 7;
        } else {
            BUS16_SET(c, (db_ret4 << 0x10) + 0xA1C7, 0x2184);
            x1 = 0x2184;
            zero1 = 0;
        }
        r->a = (a_all6 >> 8 << 8) | value5;
        r->x = x1;
        r->c = value5 >= 7;
        r->z = zero1;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x221F, 0xC02443); GUARD_JSR(c, sp_call, 0x221F); } /* execute_native_menu_page_record_commands */
        { const uint16_t sp_call = r->sp; JSR(c, 0x2222, 0xC02985); GUARD_JSR(c, sp_call, 0x2222); } /* clear_title_menu_instruction_strip_when_requested */
        { const uint16_t sp_call = r->sp; JSR(c, 0x2225, 0xC025AD); GUARD_JSR(c, sp_call, 0x2225); } /* upload_complete_native_menu_tile_workspace */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC021DB, SOM_RTS, "gen", construct_native_menu_page_with_saved_slots_and_real_text_publication, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 76, 28)
