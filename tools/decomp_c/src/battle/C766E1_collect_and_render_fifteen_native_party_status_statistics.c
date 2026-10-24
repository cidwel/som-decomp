#include "som_c.h"

/* C766E1 collect_and_render_fifteen_native_party_status_statistics   [class B, 197 bytes, 87 instructions]
 * Source: src/rom/collect_and_render_fifteen_native_party_status_statistics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void collect_and_render_fifteen_native_party_status_statistics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    RAM16_SET(0xA1C7, 0x5898);
    r->x = 0;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x66EC, 0xC76A95); GUARD_JSR(c, sp_call, 0x66EC); } /* derive_selected_native_party_status_record_offset */
    uint16_t y_ret = r->y;
    RAM8(0xA177) = 5;
    uint8_t a_hi1 = (uint16_t)(y_ret + 8) >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = (uint16_t)(y_ret + 8);
    bool carry1 = y_ret + 8 > 0xFFFF;
    bool overflow1 = ((y_ret ^ (uint16_t)(y_ret + 8)) & ((uint16_t)(y_ret + 8) ^ 8) & 0x8000) != 0;
    do {
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x66FE, 0xC767BF); GUARD_JSR(c, sp_call, 0x66FE); } /* collect_zero_extended_native_party_status_byte */
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret2 = r->y;
        RAM8(0xA177)--;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret;
        y1 = y_ret2;
    } while (RAM8(0xA177) != 0);
    r->a = (uint16_t)(y1 + 0x0A);
    r->x = x1;
    r->y = (uint16_t)(y1 + 0x0A);
    r->c = y1 + 0x0A > 0xFFFF;
    r->z = (uint16_t)(y1 + 0x0A) == 0;
    r->n = (uint16_t)(y1 + 0x0A) & 0x8000;
    r->v = ((y1 ^ (uint16_t)(y1 + 0x0A)) & ((uint16_t)(y1 + 0x0A) ^ 0x0A) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6710, 0xC767BF); GUARD_JSR(c, sp_call, 0x6710); } /* collect_zero_extended_native_party_status_byte */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6713, 0xC767BF); GUARD_JSR(c, sp_call, 0x6713); } /* collect_zero_extended_native_party_status_byte */
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    r->a = (a_all4 >> 8 << 8) | (uint8_t)((uint8_t)y_ret4 + 0x0B);
    r->y = (a_all4 >> 8 << 8) | (uint8_t)((uint8_t)y_ret4 + 0x0B);
    r->c = (uint8_t)y_ret4 + 0x0B > 0xFF;
    r->z = ((a_all4 >> 8 << 8) | (uint8_t)((uint8_t)y_ret4 + 0x0B)) == 0;
    r->n = ((a_all4 >> 8 << 8) | (uint8_t)((uint8_t)y_ret4 + 0x0B)) & 0x8000;
    r->v = (((uint8_t)y_ret4 ^ (uint8_t)((uint8_t)y_ret4 + 0x0B)) & ((uint8_t)((uint8_t)y_ret4 + 0x0B) ^ 0x0B) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x671D, 0xC767BF); GUARD_JSR(c, sp_call, 0x671D); } /* collect_zero_extended_native_party_status_byte */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6720, 0xC767CC); GUARD_JSR(c, sp_call, 0x6720); } /* collect_native_party_status_word_prefix */
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t y_ret6 = r->y;
    r->y = (uint16_t)(y_ret6 + 1);
    r->z = (uint16_t)(y_ret6 + 1) == 0;
    r->n = (uint16_t)(y_ret6 + 1) & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6724, 0xC767CC); GUARD_JSR(c, sp_call, 0x6724); } /* collect_native_party_status_word_prefix */
    uint16_t a_all7 = r->a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6727, 0xC767A6); GUARD_JSR(c, sp_call, 0x6727); } /* swap_two_native_party_status_statistic_pairs */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    RAM8(0xA178) = 3;
    RAM8(0xA175) = 0;
    uint8_t a_hi2 = a_all7 >> 8;
    uint16_t x2 = 0;
    uint16_t y2 = 0;
    bool carry2 = (uint8_t)y_ret4 + 0x0B > 0xFF;
    bool overflow2 = (((uint8_t)y_ret4 ^ (uint8_t)((uint8_t)y_ret4 + 0x0B)) & ((uint8_t)((uint8_t)y_ret4 + 0x0B) ^ 0x0B) & 0x80) != 0;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        BUS8_SET(c, (data_bank << 0x10) + 0xA177, 5);
        uint8_t a_hi3 = a_hi2;
        uint16_t x3 = x2;
        uint16_t y3 = y2;
        bool carry3 = carry2;
        bool overflow3 = overflow2;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            uint8_t value = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA1E1 + y3);
            uint8_t value2 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA1E0 + y3);
            RAM8(0x0000 + sp0) = (uint16_t)(y3 + 2) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(y3 + 2);
            RAM8(0x0000 + sp0 - 2) = value;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)((value << 8) | value2);
            RAM8(0x0000 + sp0 - 4) = x3 >> 8;
            RAM8(0x0000 + sp0 - 5) = (uint8_t)x3;
            r->a = (value << 8) | value2;
            r->x = x3;
            r->y = (value << 8) | value2;
            r->c = carry3;
            r->z = ((value << 8) | value2) == 0;
            r->n = ((value << 8) | value2) & 0x8000;
            r->v = overflow3;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x674A, 0xC767D8); GUARD_JSR(c, sp_call, 0x674A); } /* select_native_status_bar_conversion_for_first_ten_fields */
            r->sp += 6;
            uint8_t value3 = RAM8(0x0000 + sp0 - 5);
            uint8_t value4 = RAM8(0x0000 + sp0 - 4);
            uint8_t value5 = RAM8(0x0000 + sp0 - 3);
            uint8_t value6 = RAM8(0x0000 + sp0 - 2);
            r->x = (value4 << 8) | value3;
            r->y = (value6 << 8) | value5;
            r->z = ((value6 << 8) | value5) == 0;
            r->n = ((value6 << 8) | value5) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x674F, 0xC75D17); GUARD_JSR(c, sp_call, 0x674F); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
            r->sp += 2;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6752, 0xC75389); GUARD_JSR(c, sp_call, 0x6752); } /* append_native_saved_slot_text_space_token */
            r->sp += 2;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret2 = r->db;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6755, 0xC75A1E); GUARD_JSR(c, sp_call, 0x6755); } /* append_three_native_saved_slot_decimal_digits */
            r->sp += 2;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x_ret13 = r->x;
            bool overflow_ret3 = r->v;
            uint16_t value7 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA175);
            uint8_t a_hi5;
            bool carry4;
            if ((value7 & 0xFF) != 2) {
                uint8_t a_hi4;
                if ((value7 & 0xFF) != 3) {
                    a_hi4 = 0;
                } else {
                    BUS16_SET(c, (db_ret2 << 0x10) + 0x9BFC + x_ret13, 0x9F9D);
                    a_hi4 = 0x9F;
                }
                a_hi5 = a_hi4;
                carry4 = (value7 & 0xFF) >= 3;
            } else {
                BUS16_SET(c, (db_ret2 << 0x10) + 0x9BFC + x_ret13, 0xA8A9);
                a_hi5 = 0xA8;
                carry4 = (value7 & 0xFF) >= 2;
            }
            uint8_t value8 = RAM8(0x0000 + sp0 - 1);
            uint8_t value9 = RAM8(0x0000 + sp0);
            uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA175);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA175, (uint8_t)(value10 + 1));
            uint8_t value11 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA177);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA177, (uint8_t)(value11 - 1));
            a_hi3 = a_hi5;
            x3 = x_ret13;
            y3 = (value9 << 8) | value8;
            carry3 = carry4;
            overflow3 = overflow_ret3;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret;
            if (!((uint8_t)(value11 - 1) != 0)) break;
        }
        r->a = (a_hi3 << 8) | a;
        r->x = x3;
        r->y = y3;
        r->c = carry3;
        r->v = overflow3;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = direct_page2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6783, 0xC7538D); GUARD_JSR(c, sp_call, 0x6783); } /* append_native_saved_slot_text_line_token */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all12 = r->a;
        uint16_t x_ret14 = r->x;
        uint8_t value12 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA178);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA178, (uint8_t)(value12 - 1));
        a_hi2 = a_all12 >> 8;
        x2 = x_ret14;
        y2 = y3;
        carry2 = carry3;
        overflow2 = overflow3;
        data_bank = db_ret3;
        direct_page = dp_ret2;
        if (!((uint8_t)(value12 - 1) != 0)) break;
    }
    RAM8(0x0000 + sp0) = x2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
    BUS16_SET(c, (data_bank << 0x10) + 0xA18C, 0x68C0);
    BUS16_SET(c, (data_bank << 0x10) + 0xA191, 0x0280);
    BUS16_SET(c, (data_bank << 0x10) + 0xA199, 0x0140);
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank << 0x10) + 0xA171, 3);
    r->a = (a_hi2 << 8) | 3;
    r->x = (value14 << 8) | value13;
    r->y = y2;
    r->c = carry2;
    r->z = 0;
    r->n = 0;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x67A4, 0xC75D9A); GUARD_JSR(c, sp_call, 0x67A4); } /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC766E1, SOM_RTS, "gen", collect_and_render_fifteen_native_party_status_statistics, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 6, 1, 0, 197, 87)
