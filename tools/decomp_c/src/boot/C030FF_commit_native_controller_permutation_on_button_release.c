#include "som_c.h"

/* C030FF commit_native_controller_permutation_on_button_release   [class B, 53 bytes, 20 instructions]
 * Source: src/rom/commit_native_controller_permutation_on_button_release.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void commit_native_controller_permutation_on_button_release(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3101, 0xC03269); GUARD_JSR(c, sp_call, 0x3101); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x42));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    uint8_t data_bank2;
    if ((value | value2) != 0) {
        x_flag2 = 0;
        a2 = value | value2;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        zero2 = (value | value2) == 0;
        negative2 = (value | value2) & 0x80;
        overflow2 = overflow;
        data_bank2 = 0x7E;
    } else {
        uint8_t value3 = RAM8(0xA203 + x_ret);
        uint8_t value4 = RAM8(0xA204 + x_ret);
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        uint8_t data_bank;
        if (((value3 | value4) & 0xC0) == 0) {
            x_flag = 0;
            a1 = (value3 | value4) & 0xC0;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y;
            carry1 = carry_ret;
            zero1 = ((value3 | value4) & 0xC0) == 0;
            negative1 = (value3 | value4) & 0xC0 & 0x80;
            overflow1 = overflow;
            data_bank = 0x7E;
        } else {
            r->a = a_all >> 8 << 8 | ((value3 | value4) & 0xC0);
            r->z = ((value3 | value4) & 0xC0) == 0;
            r->n = (value3 | value4) & 0xC0 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x3114, 0xC01BA5); GUARD_JSR(c, sp_call, 0x3114); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
            uint8_t db_ret = r->db;
            { const uint16_t sp_call = r->sp; JSL(c, 0x3118, 0xC757D5); GUARD_JSL(c, sp_call, 0x3118); } /* clear_native_saved_slot_rectangle_highlight */
            { const uint16_t sp_call = r->sp; JSL(c, 0x311C, 0xC76ED6); GUARD_JSL(c, sp_call, 0x311C); } /* encode_native_controller_permutation_from_twenty_four_masks */
            { const uint16_t sp_call = r->sp; JSL(c, 0x3120, 0xC76DFC); GUARD_JSL(c, sp_call, 0x3120); } /* decode_native_controller_layout_and_publish_four_button_labels */
            bool x_ret8 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret9 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret4 = r->v;
            BUS8_SET(c, (db_ret << 0x10) + 0xA180, 0);
            BUS8_SET(c, (db_ret << 0x10) + 0xA1D8, 4);
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value5 | 2);
            uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
            BUS8_SET(c, (db_ret << 0x10) + 0xA212, value6 & 0xBF);
            x_flag = x_ret8;
            a1 = 0x40;
            a_hi1 = a_all5 >> 8;
            x1 = x_ret9;
            y1 = y_ret4;
            carry1 = carry_ret5;
            zero1 = (value6 & 0x40) == 0;
            negative1 = 0;
            overflow1 = overflow_ret4;
            data_bank = db_ret;
        }
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = x_flag2;
    r->db = data_bank2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC030FF, SOM_RTS, "gen", commit_native_controller_permutation_on_button_release, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 53, 20)
