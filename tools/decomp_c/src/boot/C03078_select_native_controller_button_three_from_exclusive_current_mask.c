#include "som_c.h"

/* C03078 select_native_controller_button_three_from_exclusive_current_mask   [class C, 135 bytes, 64 instructions]
 * Source: src/rom/select_native_controller_button_three_from_exclusive_current_mask.s
 * Documented in docs/ui-native-controller-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void select_native_controller_button_three_from_exclusive_current_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x307A, 0xC03269); GUARD_JSR(c, sp_call, 0x307A); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x42));
    if ((value & 0xC0) != 0x80) {
        SET_A8(r, value & 0xC0);
        r->c = (value & 0xC0) >= 0x80;
        r->z = (value & 0xC0) == 0x80;
        r->n = (uint8_t)((value & 0xC0) - 0x80) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    if ((value2 & 0xC0) != 0) {
        SET_A8(r, value2 & 0xC0);
        r->c = (value & 0xC0) >= 0x80;
        r->z = (value2 & 0xC0) == 0;
        r->n = value2 & 0xC0 & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0 - 1) = 3;
    uint8_t value3 = RAM8(0xA1D8);
    if (value3 != 4) {
        RAM8(0xA1D7) = 3;
        if (value3 != 3) {
            r->a = 0x0303;
            r->c = value3 <= 3;
            r->z = value3 == 3;
            r->n = (uint8_t)(3 - value3) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xA1D8) = 3;
        RAM8(0x0000 + sp0 - 1) = 3;
        uint8_t value4 = RAM8(0xA212);
        if ((value4 & 0x40) != 0) {
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
            { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0xA212) |= 0x40;
        r->a = 0x0340;
        r->c = value3 <= 3;
        r->v = value4 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x30F0, 0xC01BAA); GUARD_JSR(c, sp_call, 0x30F0); } /* external */
        r->sp += 1;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        if (m_ret3) {
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA211, value6);
            RAM8(0x0000 + sp0 - 1) = value6;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
            { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint8_t value7 = RAM8(0x0000 + sp0 - 1);
            uint8_t value8 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (db_ret2 << 0x10) + 0xA211, (value8 << 8) | value7);
            RAM8(0x0000 + sp0) = value8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)((value8 << 8) | value7);
            r->mf = 0;
            r->sp += 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
            r->sp -= 1;
            r->sp += 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
            r->sp -= 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 1;
            RETURN_RTS(c);
        }
    }
    RAM8(0xA1D8) = 3;
    RAM8(0xA1D7) = 3;
    uint8_t value9 = RAM8(0xA1D8);
    if (value9 != 3) {
        r->a = (value3 << 8) | 3;
        r->c = value9 <= 3;
        r->z = value9 == 3;
        r->n = (uint8_t)(3 - value9) & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0xA1D8) = 3;
    RAM8(0x0000 + sp0 - 1) = 3;
    uint8_t value10 = RAM8(0xA212);
    if ((value10 & 0x40) != 0) {
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
        { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RAM8(0xA212) |= 0x40;
    r->a = (value3 << 8) | 0x40;
    r->c = value9 <= 3;
    r->v = value10 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x30F0, 0xC01BAA); GUARD_JSR(c, sp_call, 0x30F0); } /* external */
    r->sp += 1;
    uint8_t db_ret6 = r->db;
    bool m_ret10 = r->mf;
    if (m_ret10) {
        uint8_t value12 = RAM8(0x0000 + sp0 - 1);
        BUS8_SET(c, (db_ret6 << 0x10) + 0xA211, value12);
        RAM8(0x0000 + sp0 - 1) = value12;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
        { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint8_t value13 = RAM8(0x0000 + sp0 - 1);
        uint8_t value14 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret6 << 0x10) + 0xA211, (value14 << 8) | value13);
        RAM8(0x0000 + sp0) = value14;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((value14 << 8) | value13);
        r->mf = 0;
        r->sp += 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x30FA, 0xC757DC); GUARD_JSL(c, sp_call, 0x30FA); } /* highlight_native_saved_slot_rectangle_and_request_publication */
        r->sp -= 1;
        r->sp += 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x30FD, 0xC0314B); GUARD_JSR(c, sp_call, 0x30FD); } /* handle_native_controller_direction_and_unwind_nested_callback_frame */
        r->sp -= 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 1;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC03078, SOM_RTS, "gen", select_native_controller_button_three_from_exclusive_current_mask, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 135, 64)
