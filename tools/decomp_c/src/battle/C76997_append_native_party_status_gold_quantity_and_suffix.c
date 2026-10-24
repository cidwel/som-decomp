#include "som_c.h"

/* C76997 append_native_party_status_gold_quantity_and_suffix   [class B, 43 bytes, 20 instructions]
 * Source: src/rom/append_native_party_status_gold_quantity_and_suffix.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_party_status_gold_quantity_and_suffix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->y = 0x7B61;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x699C, 0xC76ABE); GUARD_JSR(c, sp_call, 0x699C); } /* select_bank_C7_and_copy_native_terminated_tokens */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM8(0x0000 + sp0) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xCC6A + x1);
        BUS8_SET(c, (db_ret << 0x10) + 0xA136 + y1, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x69B6, 0xC754DB); GUARD_JSL(c, sp_call, 0x69B6); } /* convert_24_bit_dialogue_quantity_to_seven_digit_fields */
    r->sp += 2;
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->x = (value3 << 8) | value2;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x69BA, 0xC754B0); GUARD_JSR(c, sp_call, 0x69BA); } /* append_seven_native_decimal_quantity_glyphs_with_leading_spaces */
    if (r->xf != 0) { c->fail = 3; return; }
    r->y = 0x7B6A;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x69C0, 0xC76ABE); GUARD_JSR(c, sp_call, 0x69C0); } /* select_bank_C7_and_copy_native_terminated_tokens */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76997, SOM_RTS, "gen", append_native_party_status_gold_quantity_and_suffix, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 43, 20)
