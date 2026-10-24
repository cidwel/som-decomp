#include "som_c.h"

/* C03134 toggle_native_controller_mirror_on_changed_high_button   [class B, 23 bytes, 9 instructions]
 * Source: src/rom/toggle_native_controller_mirror_on_changed_high_button.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void toggle_native_controller_mirror_on_changed_high_button(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3136, 0xC03269); GUARD_JSR(c, sp_call, 0x3136); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x42));
    uint8_t value2 = RAM8(0xA203 + x_ret);
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
    if (value == value2) {
        x_flag = 0;
        a1 = value;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y;
        carry1 = value >= value2;
        zero1 = value == value2;
        negative1 = (uint8_t)(value - value2) & 0x80;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->c = value >= value2;
        r->z = value == value2;
        r->n = (uint8_t)(value - value2) & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3140, 0xC01BA5); GUARD_JSR(c, sp_call, 0x3140); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        uint8_t db_ret = r->db;
        bool carry_ret2 = r->c;
        bool overflow_ret = r->v;
        { const uint16_t sp_call = r->sp; JSL(c, 0x3144, 0xC76F69); GUARD_JSL(c, sp_call, 0x3144); } /* toggle_native_controller_layout_mirror_flags */
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret2 = r->y;
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
        BUS8_SET(c, (db_ret << 0x10) + 0xA212, value3 | 0x80);
        x_flag = x_ret4;
        a1 = 0x80;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret5;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = (value3 & 0x80) == 0;
        negative1 = 1;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = x_flag;
    r->db = data_bank;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03134, SOM_RTS, "gen", toggle_native_controller_mirror_on_changed_high_button, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 23, 9)
