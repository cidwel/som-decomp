#include "som_c.h"

/* C0300C cancel_native_controller_layout_changes_or_request_menu_close   [class C, 74 bytes, 29 instructions]
 * Source: src/rom/cancel_native_controller_layout_changes_or_request_menu_close.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void cancel_native_controller_layout_changes_or_request_menu_close(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA212);
    if ((value & 0x80) == 0) {
        r->a = (a_hi << 8) | 0x80;
        r->z = (value & 0x80) == 0;
        r->n = value & 0x80;
        r->v = value & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0x305C, 0xC0325A); GUARD_JSR(c, sp_call, 0x305C); } /* compare_selected_pad_buttons_against_native_previous_buttons */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        uint8_t a1;
        bool zero1;
        bool negative1;
        if (zero_ret) {
            a1 = (uint8_t)a_all;
            zero1 = zero_ret;
            negative1 = negative_ret;
        } else {
            RAM8(0xA20A) |= 1;
            uint8_t value3 = RAM8(0xA212);
            RAM8(0xA212) &= 0xDF;
            a1 = 0x20;
            zero1 = (value3 & 0x20) == 0;
            negative1 = 0;
        }
        SET_A8(r, a1);
        r->z = zero1;
        r->n = negative1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0xA212);
    RAM8(0xA212) &= 0x7F;
    r->a = (a_hi << 8) | 0x80;
    r->z = (value4 & 0x80) == 0;
    r->n = value & 0x80;
    r->v = value & 0x40;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3018, 0xC01BAF); GUARD_JSR(c, sp_call, 0x3018); } /* external */
    { const uint16_t sp_call = r->sp; JSL(c, 0x301C, 0xC76FB7); GUARD_JSL(c, sp_call, 0x301C); } /* restore_native_controller_bindings_and_copy_mirror_free_runtime_flags */
    { const uint16_t sp_call = r->sp; JSL(c, 0x3020, 0xC76DFC); GUARD_JSL(c, sp_call, 0x3020); } /* decode_native_controller_layout_and_publish_four_button_labels */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3024, 0xC76E17); GUARD_JSL(c, sp_call, 0x3024); } /* publish_native_controller_layout_frame_and_optional_mirror */
    uint8_t db_ret2 = r->db;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3028, 0xC76F29); GUARD_JSL(c, sp_call, 0x3028); } /* snapshot_native_controller_permutation_to_two_buffers */
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA20A);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA20A, value5 | 2);
    SET_A8(r, 2);
    r->z = (value5 & 2) == 0;
    r->n = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0300C, SOM_RTS, "gen", cancel_native_controller_layout_changes_or_request_menu_close, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 94, 29)
