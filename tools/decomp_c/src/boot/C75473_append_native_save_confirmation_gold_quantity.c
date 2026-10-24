#include "som_c.h"

/* C75473 append_native_save_confirmation_gold_quantity   [class B, 61 bytes, 30 instructions]
 * Source: src/rom/append_native_save_confirmation_gold_quantity.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void append_native_save_confirmation_gold_quantity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5477, 0xC75D00); GUARD_JSR(c, sp_call, 0x5477); } /* derive_selected_save_slot_primary_or_backup_offset */
    uint16_t x_ret = r->x;
    uint8_t a1 = 4;
    uint8_t a_hi1 = (uint16_t)(x_ret + 0x6D) >> 8;
    uint16_t x1 = (uint16_t)(x_ret + 0x6D);
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0x306000 + x1);
        RAM8(0xA136 + y1) = value;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = x_ret + 0x6D > 0xFFFF;
    r->v = ((x_ret ^ (uint16_t)(x_ret + 0x6D)) & ((uint16_t)(x_ret + 0x6D) ^ 0x6D) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5496, 0xC754DB); GUARD_JSL(c, sp_call, 0x5496); } /* convert_24_bit_dialogue_quantity_to_seven_digit_fields */
    uint16_t a_all2 = r->a;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint16_t x2 = 0;
    uint16_t y2 = 8;
    for (;;) {
        RAM8(0x9C00 + x2) = 0x80;
        x2 = (uint16_t)(x2 + 1);
        y2 = (uint16_t)(y2 - 1);
        if (!(y2 != 0)) break;
    }
    r->a = (a_all2 >> 8 << 8) | 0x80;
    r->x = x2;
    r->y = y2;
    r->c = carry_ret2;
    r->v = overflow_ret2;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x54A8, 0xC754B0); GUARD_JSR(c, sp_call, 0x54A8); } /* append_seven_native_decimal_quantity_glyphs_with_leading_spaces */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    RAM8(0x9C00 + x_ret4) = 0xA1;
    if (x_ret3) {
        SET_A8(r, 0xA1);
        r->x = (uint8_t)((uint8_t)x_ret4 + 1);
        r->y = (uint8_t)y_ret2;
        r->z = (uint8_t)((uint8_t)x_ret4 + 1) == 0;
        r->n = (uint8_t)((uint8_t)x_ret4 + 1) & 0x80;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        SET_A8(r, 0xA1);
        r->x = (uint16_t)(x_ret4 + 1);
        r->z = (uint16_t)(x_ret4 + 1) == 0;
        r->n = (uint16_t)(x_ret4 + 1) & 0x8000;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC75473, SOM_RTS, "gen", append_native_save_confirmation_gold_quantity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 61, 30)
