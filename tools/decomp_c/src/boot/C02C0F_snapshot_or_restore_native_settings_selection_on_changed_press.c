#include "som_c.h"

/* C02C0F snapshot_or_restore_native_settings_selection_on_changed_press   [class B, 45 bytes, 17 instructions]
 * Source: src/rom/snapshot_or_restore_native_settings_selection_on_changed_press.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void snapshot_or_restore_native_settings_selection_on_changed_press(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2C11, 0xC03269); GUARD_JSR(c, sp_call, 0x2C11); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x0343));
    uint8_t value2 = RAM8(0xA204 + x_ret);
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
    uint16_t direct_page2;
    if (value == value2) {
        x_flag2 = 0;
        a2 = value;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = value >= value2;
        zero2 = value == value2;
        negative2 = (uint8_t)(value - value2) & 0x80;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0x0300;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->c = value >= value2;
        r->z = value == value2;
        r->n = (uint8_t)(value - value2) & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2C1C, 0xC7626A); GUARD_JSL(c, sp_call, 0x2C1C); } /* snapshot_native_shop_item_selection_records */
        uint16_t a_all2 = r->a;
        uint16_t y_ret = r->y;
        uint8_t value3 = RAM8(0xA212);
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
        uint16_t direct_page;
        if ((value3 & 0x80) == 0) {
            uint8_t value4 = RAM8(0xA20A);
            RAM8(0xA20A) |= 1;
            r->a = (a_all2 >> 8 << 8) | 1;
            r->z = (value4 & 1) == 0;
            r->n = 0;
            r->v = value3 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2C3A, 0xC76FA7); GUARD_JSL(c, sp_call, 0x2C3A); } /* commit_three_native_controller_bindings_to_runtime_and_save_records */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            x_flag = 0;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret3;
            y1 = y_ret;
            carry1 = value >= value2;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = value3 & 0x40;
            data_bank = 0x7E;
            direct_page = 0x0300;
        } else {
            r->a = (a_all2 >> 8 << 8) | 0x80;
            r->z = (value3 & 0x80) == 0;
            r->n = value3 & 0x80;
            r->v = value3 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2C26, 0xC01BAF); GUARD_JSR(c, sp_call, 0x2C26); } /* external */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2C2A, 0xC76256); GUARD_JSL(c, sp_call, 0x2C2A); } /* refresh_native_shop_frame_graphics_icons_and_request_sound */
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret2 = r->v;
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
            BUS8_SET(c, (db_ret << 0x10) + 0xA212, value5 & 0x7F);
            x_flag = x_ret6;
            a1 = 0x80;
            a_hi1 = a_all5 >> 8;
            x1 = x_ret7;
            y1 = y_ret3;
            carry1 = carry_ret3;
            zero1 = (value5 & 0x80) == 0;
            negative1 = 1;
            overflow1 = overflow_ret2;
            data_bank = db_ret;
            direct_page = dp_ret;
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
        direct_page2 = direct_page;
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
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02C0F, SOM_RTS, "gen", snapshot_or_restore_native_settings_selection_on_changed_press, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 45, 17)
