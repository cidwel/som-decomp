#include "som_c.h"

/* C76890 compose_and_render_native_party_status_summary_rows   [class B, 87 bytes, 34 instructions]
 * Source: src/rom/compose_and_render_native_party_status_summary_rows.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void compose_and_render_native_party_status_summary_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    r->x = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6895, 0xC76A4F); GUARD_JSR(c, sp_call, 0x6895); } /* append_selected_native_party_status_twelve_byte_name */
    { const uint16_t sp_call = r->sp; JSR(c, 0x6898, 0xC76A2F); GUARD_JSR(c, sp_call, 0x6898); } /* append_native_party_status_level_label_and_decimal */
    { const uint16_t sp_call = r->sp; JSR(c, 0x689B, 0xC769C2); GUARD_JSR(c, sp_call, 0x689B); } /* append_native_party_status_current_and_maximum_hit_points */
    uint8_t db_ret = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0x689E, 0xC769F8); GUARD_JSR(c, sp_call, 0x689E); } /* append_native_party_status_magic_points_when_not_boy */
    { const uint16_t sp_call = r->sp; JSR(c, 0x68A1, 0xC76933); GUARD_JSR(c, sp_call, 0x68A1); } /* append_native_party_status_experience_quantity */
    { const uint16_t sp_call = r->sp; JSR(c, 0x68A4, 0xC7695B); GUARD_JSR(c, sp_call, 0x68A4); } /* append_native_party_status_remaining_experience_unless_level99 */
    bool overflow_ret6 = r->v;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x68A9, 0xC76AA4); GUARD_JSR(c, sp_call, 0x68A9); } /* read_selected_native_party_status_excluding_low_two_bits */
    bool zero_ret7 = r->z;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (!zero_ret7) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x68BB, 0xC768E7); GUARD_JSR(c, sp_call, 0x68BB); } /* append_first_four_native_party_status_restriction_labels */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all8 = r->a;
        uint16_t x_ret15 = r->x;
        uint16_t y_ret7 = r->y;
        bool carry_ret8 = r->c;
        a_hi1 = a_all8 >> 8;
        x1 = x_ret15;
        y1 = y_ret7;
        carry1 = carry_ret8;
        overflow1 = overflow_ret6;
        data_bank = db_ret;
        direct_page = 0;
    } else {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x68B0, 0xC76978); GUARD_JSR(c, sp_call, 0x68B0); } /* append_native_party_status_active_slot_count_label */
        { const uint16_t sp_call = r->sp; JSR(c, 0x68B3, 0xC7538D); GUARD_JSR(c, sp_call, 0x68B3); } /* append_native_saved_slot_text_line_token */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0x68B6, 0xC76997); GUARD_JSR(c, sp_call, 0x68B6); } /* append_native_party_status_gold_quantity_and_suffix */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all11 = r->a;
        uint16_t x_ret20 = r->x;
        uint16_t y_ret9 = r->y;
        bool carry_ret10 = r->c;
        bool overflow_ret8 = r->v;
        a_hi1 = a_all11 >> 8;
        x1 = x_ret20;
        y1 = y_ret9;
        carry1 = carry_ret10;
        overflow1 = overflow_ret8;
        data_bank = db_ret2;
        direct_page = dp_ret;
    }
    RAM8(0x0000 + sp0) = x1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
    BUS16_SET(c, (data_bank << 0x10) + 0xA18C, 0x6C20);
    BUS16_SET(c, (data_bank << 0x10) + 0xA191, 0x0380);
    BUS16_SET(c, (data_bank << 0x10) + 0xA199, 0x01C0);
    uint8_t value = RAM8(0x0000 + sp0 - 1);
    uint8_t value2 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank << 0x10) + 0xA171, 9);
    r->a = (a_hi1 << 8) | 9;
    r->x = (value2 << 8) | value;
    r->y = y1;
    r->v = overflow1;
    r->mf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x68D9, 0xC76AA4); GUARD_JSR(c, sp_call, 0x68D9); } /* read_selected_native_party_status_excluding_low_two_bits */
    bool zero_ret12 = r->z;
    bool zero1;
    if (zero_ret12) {
        zero1 = zero_ret12;
    } else {
        BUS8_SET(c, (data_bank << 0x10) + 0xA171, 0x0A);
        zero1 = 0;
    }
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x68E5, 0xC75D9A); GUARD_JSR(c, sp_call, 0x68E5); } /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76890, SOM_RTS, "gen", compose_and_render_native_party_status_summary_rows, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 87, 34)
