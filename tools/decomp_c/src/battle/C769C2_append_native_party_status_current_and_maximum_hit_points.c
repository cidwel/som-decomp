#include "som_c.h"

/* C769C2 append_native_party_status_current_and_maximum_hit_points   [class B, 54 bytes, 24 instructions]
 * Source: src/rom/append_native_party_status_current_and_maximum_hit_points.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_party_status_current_and_maximum_hit_points(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 4;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x69C6, 0xC759E0); GUARD_JSR(c, sp_call, 0x69C6); } /* append_native_saved_slot_format_pair */
    r->y = 0x7B2D;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x69CC, 0xC76ABE); GUARD_JSR(c, sp_call, 0x69CC); } /* select_bank_C7_and_copy_native_terminated_tokens */
    uint8_t db_ret = r->db;
    uint16_t x_ret3 = r->x;
    { const uint16_t sp_call = r->sp; JSR(c, 0x69CF, 0xC76A95); GUARD_JSR(c, sp_call, 0x69CF); } /* derive_selected_native_party_status_record_offset */
    bool x_ret4 = r->xf;
    uint16_t y_ret2 = r->y;
    if (x_ret4) {
        RAM8(0x0000 + sp0) = (uint8_t)y_ret2;
        uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0xE182 + (uint8_t)y_ret2);
        r->a = value;
        r->x = (uint8_t)x_ret3;
        r->y = (uint8_t)value;
        r->z = (uint8_t)value == 0;
        r->n = (uint8_t)value & 0x80;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x69DB, 0xC75D17); GUARD_JSR(c, sp_call, 0x69DB); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        r->sp += 1;
        uint8_t db_ret2 = r->db;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x69DE, 0xC75A1E); GUARD_JSR(c, sp_call, 0x69DE); } /* append_three_native_saved_slot_decimal_digits */
        r->sp += 1;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret6 = r->xf;
        uint16_t x_ret7 = r->x;
        BUS8_SET(c, (db_ret2 << 0x10) + 0x9C00 + x_ret7, 0xC1);
        if (x_ret6) {
            uint16_t value3 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE184 + RAM8(0x0000 + sp0));
            r->a = value3;
            r->x = (uint8_t)((uint8_t)x_ret7 + 1);
            r->y = (uint8_t)value3;
            r->z = (uint8_t)value3 == 0;
            r->n = (uint8_t)value3 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F0, 0xC75D17); GUARD_JSR(c, sp_call, 0x69F0); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F3, 0xC75A1E); GUARD_JSR(c, sp_call, 0x69F3); } /* append_three_native_saved_slot_decimal_digits */
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F6, 0xC7538D); GUARD_JSR(c, sp_call, 0x69F6); } /* append_native_saved_slot_text_line_token */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            c->fail = 3;
            return;
        }
    } else {
        RAM8(0x0000 + sp0) = y_ret2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y_ret2;
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xE182 + y_ret2);
        r->a = value4;
        r->y = value4;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x69DB, 0xC75D17); GUARD_JSR(c, sp_call, 0x69DB); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        r->sp += 2;
        uint8_t db_ret5 = r->db;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x69DE, 0xC75A1E); GUARD_JSR(c, sp_call, 0x69DE); } /* append_three_native_saved_slot_decimal_digits */
        r->sp += 2;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret14 = r->xf;
        uint16_t x_ret15 = r->x;
        BUS8_SET(c, (db_ret5 << 0x10) + 0x9C00 + x_ret15, 0xC1);
        if (x_ret14) {
            c->fail = 3;
            return;
        } else {
            uint16_t value9 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xE184 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)));
            r->a = value9;
            r->x = (uint16_t)(x_ret15 + 1);
            r->y = value9;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F0, 0xC75D17); GUARD_JSR(c, sp_call, 0x69F0); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F3, 0xC75A1E); GUARD_JSR(c, sp_call, 0x69F3); } /* append_three_native_saved_slot_decimal_digits */
            { const uint16_t sp_call = r->sp; JSR(c, 0x69F6, 0xC7538D); GUARD_JSR(c, sp_call, 0x69F6); } /* append_native_saved_slot_text_line_token */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC769C2, SOM_RTS, "gen", append_native_party_status_current_and_maximum_hit_points, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 54, 24)
