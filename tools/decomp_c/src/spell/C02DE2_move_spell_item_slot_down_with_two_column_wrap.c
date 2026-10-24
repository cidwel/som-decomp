#include "som_c.h"

/* C02DE2 move_spell_item_slot_down_with_two_column_wrap   [class B, 91 bytes, 39 instructions]
 * Source: src/rom/move_spell_item_slot_down_with_two_column_wrap.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_spell_item_slot_down_with_two_column_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA20A);
    if ((value & 0x40) == 0) {
        SET_A8(r, value);
        r->z = (value & 0x40) == 0;
        r->n = value & 0x80;
        RETURN_RTS(c);
    }
    r->a = (a_hi << 8) | value;
    r->z = (value & 0x40) == 0;
    r->n = value & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2DEB, 0xC03269); GUARD_JSR(c, sp_call, 0x2DEB); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    uint8_t value3 = RAM8(0xA204 + x_ret);
    if (value2 == value3) {
        SET_A8(r, value2);
        r->c = value2 >= value3;
        r->z = value2 == value3;
        r->n = (uint8_t)(value2 - value3) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a_all >> 8 << 8) | value2;
    r->c = value2 >= value3;
    r->z = value2 == value3;
    r->n = (uint8_t)(value2 - value3) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2DF6, 0xC757D5); GUARD_JSL(c, sp_call, 0x2DF6); } /* clear_native_saved_slot_rectangle_highlight */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint8_t value4 = RAM8(0xA211);
    uint8_t a2;
    bool carry1;
    bool zero2;
    bool negative2;
    if (value4 == 6) {
        a2 = 1;
        carry1 = value4 >= 6;
        zero2 = 0;
        negative2 = 0;
    } else {
        uint8_t a1;
        bool zero1;
        bool negative1;
        if (value4 == 7) {
            a1 = 0;
            zero1 = 1;
            negative1 = 0;
        } else {
            a1 = (uint8_t)(value4 + 2);
            zero1 = (uint8_t)(value4 + 2) == 0;
            negative1 = (uint8_t)(value4 + 2) & 0x80;
        }
        a2 = a1;
        carry1 = value4 >= 7;
        zero2 = zero1;
        negative2 = negative1;
    }
    RAM8(0xA211) = a2;
    r->a = (a_all2 >> 8 << 8) | a2;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2E12, 0xC757DC); GUARD_JSL(c, sp_call, 0x2E12); } /* highlight_native_saved_slot_rectangle_and_request_publication */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02DE2, SOM_RTS, "gen", move_spell_item_slot_down_with_two_column_wrap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 91, 39)
