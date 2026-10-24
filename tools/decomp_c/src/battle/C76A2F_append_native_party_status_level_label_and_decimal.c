#include "som_c.h"

/* C76A2F append_native_party_status_level_label_and_decimal   [class B, 32 bytes, 14 instructions]
 * Source: src/rom/append_native_party_status_level_label_and_decimal.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_party_status_level_label_and_decimal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 4;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6A33, 0xC759E0); GUARD_JSR(c, sp_call, 0x6A33); } /* append_native_saved_slot_format_pair */
    r->y = 0x7B24;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6A39, 0xC76ABE); GUARD_JSR(c, sp_call, 0x6A39); } /* select_bank_C7_and_copy_native_terminated_tokens */
    uint8_t db_ret = r->db;
    uint16_t x_ret3 = r->x;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6A3C, 0xC76A95); GUARD_JSR(c, sp_call, 0x6A3C); } /* derive_selected_native_party_status_record_offset */
    bool x_ret4 = r->xf;
    uint16_t y_ret2 = r->y;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xE181 + y_ret2);
    BUS8_SET(c, (db_ret << 0x10) + 0xA16E, (uint8_t)(value + 1));
    if (x_ret4) {
        r->a = (uint8_t)(value + 1);
        r->x = (uint8_t)x_ret3;
        r->y = (uint8_t)(value + 1);
        r->z = (uint8_t)(value + 1) == 0;
        r->n = (uint8_t)(value + 1) & 0x80;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A4A, 0xC75AFC); GUARD_JSR(c, sp_call, 0x6A4A); } /* format_and_append_native_saved_slot_decimal_pair */
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A4D, 0xC7538D); GUARD_JSR(c, sp_call, 0x6A4D); } /* append_native_saved_slot_text_line_token */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        r->a = (uint8_t)(value + 1);
        r->y = (uint8_t)(value + 1);
        r->z = (uint8_t)(value + 1) == 0;
        r->n = (uint8_t)(value + 1) & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A4A, 0xC75AFC); GUARD_JSR(c, sp_call, 0x6A4A); } /* format_and_append_native_saved_slot_decimal_pair */
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A4D, 0xC7538D); GUARD_JSR(c, sp_call, 0x6A4D); } /* append_native_saved_slot_text_line_token */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC76A2F, SOM_RTS, "gen", append_native_party_status_level_label_and_decimal, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 32, 14)
