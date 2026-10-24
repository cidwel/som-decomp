#include "som_c.h"

/* C76933 append_native_party_status_experience_quantity   [class B, 40 bytes, 19 instructions]
 * Source: src/rom/append_native_party_status_experience_quantity.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_party_status_experience_quantity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    r->y = 0x7B39;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6938, 0xC76ABE); GUARD_JSR(c, sp_call, 0x6938); } /* select_bank_C7_and_copy_native_terminated_tokens */
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0000 + sp0) = (uint8_t)x_ret2;
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)y_ret;
        r->xf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x693C, 0xC76A95); GUARD_JSR(c, sp_call, 0x693C); } /* derive_selected_native_party_status_record_offset */
        r->sp += 1;
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        RAM8(0x0000 + sp0) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret2;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x693C, 0xC76A95); GUARD_JSR(c, sp_call, 0x693C); } /* derive_selected_native_party_status_record_offset */
        r->sp += 2;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret2 = r->c;
        uint8_t a1 = 4;
        uint8_t a_hi1 = a_all3 >> 8;
        uint16_t x1 = 0;
        uint16_t y1 = y_ret3;
        for (;;) {
            uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xE18D + y1);
            BUS8_SET(c, (db_ret << 0x10) + 0xA136 + x1, value);
            a1 = (uint8_t)(a1 - 1);
            a_hi1 = value;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 + 1);
            if (!(a1 != 0)) break;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry_ret2;
        r->v = overflow;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6952, 0xC754DB); GUARD_JSL(c, sp_call, 0x6952); } /* convert_24_bit_dialogue_quantity_to_seven_digit_fields */
        r->sp += 2;
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        r->x = (value3 << 8) | value2;
        r->z = ((value3 << 8) | value2) == 0;
        r->n = ((value3 << 8) | value2) & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6956, 0xC754B0); GUARD_JSR(c, sp_call, 0x6956); } /* append_seven_native_decimal_quantity_glyphs_with_leading_spaces */
        { const uint16_t sp_call = r->sp; JSR(c, 0x6959, 0xC7538D); GUARD_JSR(c, sp_call, 0x6959); } /* append_native_saved_slot_text_line_token */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC76933, SOM_RTS, "gen", append_native_party_status_experience_quantity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 40, 19)
