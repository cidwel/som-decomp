#include "som_c.h"

/* C0314B handle_native_controller_direction_and_unwind_nested_callback_frame   [class C, 51 bytes, 23 instructions]
 * Source: src/rom/handle_native_controller_direction_and_unwind_nested_callback_frame.s
 * Documented in docs/ui-native-controller-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void handle_native_controller_direction_and_unwind_nested_callback_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x314D, 0xC03269); GUARD_JSR(c, sp_call, 0x314D); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM8(0x0000 + sp0 - 2) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    uint8_t value2 = RAM8(0xA204 + x_ret);
    if (value == value2) {
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(x_ret + 0x42));
    if (((value | value3) & 0xC0) == 0) {
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    if ((value4 & 1) == 0) {
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
        if (value5 == value2) {
            r->mf = 1;
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
        if ((value5 & 2) == 0) {
            r->mf = 1;
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
        r->a = (a_all >> 8 << 8) | value5;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3178, 0xC76E8F); GUARD_JSL(c, sp_call, 0x3178); } /* retreat_native_controller_layout_button_assignment_and_swap */
        { const uint16_t sp_call = r->sp; JSR(c, 0x317B, 0xC01BAA); GUARD_JSR(c, sp_call, 0x317B); } /* external */
        bool x_ret4 = r->xf;
        if (x_ret4) {
            r->xf = 1;
            r->sp += 1;
            RETURN_RTS(c);
        } else {
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
    }
    r->a = (a_all >> 8 << 8) | value4;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3165, 0xC76E8B); GUARD_JSL(c, sp_call, 0x3165); } /* advance_native_controller_layout_button_assignment */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3168, 0xC01BAA); GUARD_JSR(c, sp_call, 0x3168); } /* external */
    r->sp += 2;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool x_ret7 = r->xf;
    uint16_t a_all5 = r->a;
    if (x_ret7) {
        uint8_t value13 = RAM8(0x0000 + sp0 - 3);
        uint8_t value14 = RAM8(0x0043 + dp_ret3 + value13);
        uint8_t value15 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA204 + value13);
        if (value14 == value15) {
            r->xf = 1;
            RETURN_RTS(c);
        }
        if ((value14 & 2) == 0) {
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = (a_all5 >> 8 << 8) | value14;
        r->xf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3178, 0xC76E8F); GUARD_JSL(c, sp_call, 0x3178); } /* retreat_native_controller_layout_button_assignment_and_swap */
        r->sp += 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x317B, 0xC01BAA); GUARD_JSR(c, sp_call, 0x317B); } /* external */
        r->sp += 1;
        bool x_ret11 = r->xf;
        if (x_ret11) {
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            r->xf = 0;
            r->sp += 1;
            RETURN_RTS(c);
        }
    } else {
        uint8_t value21 = RAM8(0x0000 + sp0 - 3);
        uint8_t value22 = RAM8(0x0000 + sp0 - 2);
        uint8_t value23 = RAM8(0x0043 + dp_ret3 + ((value22 << 8) | value21));
        uint8_t value24 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA204 + ((value22 << 8) | value21));
        if (value23 == value24) {
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
        if ((value23 & 2) == 0) {
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
        r->a = (a_all5 >> 8 << 8) | value23;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3178, 0xC76E8F); GUARD_JSL(c, sp_call, 0x3178); } /* retreat_native_controller_layout_button_assignment_and_swap */
        { const uint16_t sp_call = r->sp; JSR(c, 0x317B, 0xC01BAA); GUARD_JSR(c, sp_call, 0x317B); } /* external */
        bool x_ret15 = r->xf;
        if (x_ret15) {
            r->xf = 1;
            r->sp += 1;
            RETURN_RTS(c);
        } else {
            r->xf = 0;
            r->sp += 2;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC0314B, SOM_RTS, "gen", handle_native_controller_direction_and_unwind_nested_callback_frame, SOM_UNWINDS, 0, 4, 1, 0, 51, 23)
