#include "som_c.h"

/* C76411 compose_native_selected_item_detail_tokens   [class B, 141 bytes, 65 instructions]
 * Source: src/rom/compose_native_selected_item_detail_tokens.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void compose_native_selected_item_detail_tokens(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6413, 0xC76BCF); GUARD_JSR(c, sp_call, 0x6413); } /* initialize_six_native_blank_detail_rows */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA211);
    uint8_t inventory_weapons = RAM8(INVENTORY_WEAPONS + value);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (inventory_weapons == 0xFF) {
        a_hi1 = 0;
        x1 = value;
        y1 = y;
        carry1 = inventory_weapons >= 0xFF;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0;
    } else {
        r->a = inventory_weapons;
        r->x = 0;
        r->c = inventory_weapons >= 0xFF;
        r->z = 1;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6427, 0xC75389); GUARD_JSR(c, sp_call, 0x6427); } /* append_native_saved_slot_text_space_token */
        if (r->xf != 0) { c->fail = 3; return; }
        r->y = 0x7BA5;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x642D, 0xC76ABE); GUARD_JSR(c, sp_call, 0x642D); } /* select_bank_C7_and_copy_native_terminated_tokens */
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        r->a = (a_all3 >> 8 << 8) | 4;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6432, 0xC759E0); GUARD_JSR(c, sp_call, 0x6432); } /* append_native_saved_slot_format_pair */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret5 = r->x;
        RAM8(0x0000 + sp0) = x_ret5 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret5;
        uint16_t value2 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA211);
        uint16_t value3 = BUS16(c, 0xC77BB7 + ((value2 & 0xFF) << 1));
        r->a = value3;
        r->y = value3;
        r->c = value2 & 0xFF & 0x8000;
        r->z = x_ret5 == 0;
        r->n = x_ret5 & 0x8000;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6448, 0xC76ABE); GUARD_JSR(c, sp_call, 0x6448); } /* select_bank_C7_and_copy_native_terminated_tokens */
        { const uint16_t sp_call = r->sp; JSR(c, 0x644B, 0xC7538D); GUARD_JSR(c, sp_call, 0x644B); } /* append_native_saved_slot_text_line_token */
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        r->a = (a_all6 >> 8 << 8) | 4;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6450, 0xC759E0); GUARD_JSR(c, sp_call, 0x6450); } /* append_native_saved_slot_format_pair */
        if (r->xf != 0) { c->fail = 3; return; }
        r->y = 0x7BAA;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6456, 0xC76ABE); GUARD_JSR(c, sp_call, 0x6456); } /* select_bank_C7_and_copy_native_terminated_tokens */
        uint8_t db_ret5 = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6459, 0xC75386); GUARD_JSR(c, sp_call, 0x6459); } /* append_two_native_saved_slot_text_space_tokens */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value4 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA211);
        uint8_t value5 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xCFB0 + value4);
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = value4;
        r->a = (uint8_t)(value5 + 1);
        r->y = (uint8_t)(value5 + 1);
        r->z = (uint8_t)(value5 + 1) == 0;
        r->n = (uint8_t)(value5 + 1) & 0x8000;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6469, 0xC75AFC); GUARD_JSR(c, sp_call, 0x6469); } /* format_and_append_native_saved_slot_decimal_pair */
        r->sp += 2;
        if (r->xf != 0) { c->fail = 3; return; }
        r->y = 0x7BB5;
        r->z = 0;
        r->n = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x646F, 0xC76ABE); GUARD_JSR(c, sp_call, 0x646F); } /* select_bank_C7_and_copy_native_terminated_tokens */
        r->sp += 2;
        uint8_t db_ret7 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value8 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xCFB8 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)));
        r->a = (uint8_t)(value8 + 1);
        r->y = (uint8_t)(value8 + 1);
        r->z = (uint8_t)(value8 + 1) == 0;
        r->n = (uint8_t)(value8 + 1) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x647B, 0xC75AFC); GUARD_JSR(c, sp_call, 0x647B); } /* format_and_append_native_saved_slot_decimal_pair */
        { const uint16_t sp_call = r->sp; JSR(c, 0x647E, 0xC7538D); GUARD_JSR(c, sp_call, 0x647E); } /* append_native_saved_slot_text_line_token */
        uint8_t db_ret9 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret18 = r->x;
        RAM8(0x0000 + sp0) = x_ret18 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret18;
        uint16_t value9 = BUS16_RDP(c, (db_ret9 << 0x10) + 0xA211);
        r->a = value9 & 0xFF;
        r->y = value9 & 0xFF;
        r->z = (value9 & 0xFF) == 0;
        r->n = value9 & 0xFF & 0x8000;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x648C, 0xC06426); GUARD_JSL(c, sp_call, 0x648C); } /* jump_native_item_slot_description_index_api */
        r->sp += 2;
        uint16_t dp_ret10 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all14 = r->a;
        bool overflow_ret3 = r->v;
        uint16_t value10 = BUS16(c, 0xCA0A9E + (uint16_t)(a_all14 << 1));
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = value10;
        r->x = (value12 << 8) | value11;
        r->y = value10;
        r->c = a_all14 & 0x8000;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6499, 0xC76AB7); GUARD_JSR(c, sp_call, 0x6499); } /* select_bank_CA_for_native_terminated_token_copy */
        uint8_t db_ret11 = r->db;
        uint16_t a_all15 = r->a;
        uint16_t x_ret20 = r->x;
        uint16_t y_ret8 = r->y;
        a_hi1 = a_all15 >> 8;
        x1 = x_ret20;
        y1 = y_ret8;
        carry1 = a_all14 & 0x8000;
        overflow1 = overflow_ret3;
        data_bank = db_ret11;
        direct_page = dp_ret10;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x649C, 0xC76512); GUARD_JSR(c, sp_call, 0x649C); } /* render_six_native_detail_rows_and_rebuild_selection_frame */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76411, SOM_RTS, "gen", compose_native_selected_item_detail_tokens, 0, 0, 2, 1, 0, 141, 65)
