#include "som_c.h"

/* C02C3C advance_native_settings_palette_cursor   [class B, 29 bytes, 13 instructions]
 * Source: src/rom/advance_native_settings_palette_cursor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_native_settings_palette_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2C3E, 0xC03269); GUARD_JSR(c, sp_call, 0x2C3E); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x42));
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if ((value & 0xC0) != 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        a2 = value;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        zero2 = (value & 0xC0) == 0;
        negative2 = value & 0x80;
        overflow2 = overflow;
    } else {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if ((value2 & 0x40) != 0) {
            m_flag = 1;
            x_flag = 0;
            a1 = value2;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y;
            carry1 = carry_ret;
            zero1 = (value2 & 0x40) == 0;
            negative1 = value2 & 0x80;
            overflow1 = overflow;
        } else {
            uint8_t value3 = RAM8(0xA24E);
            RAM8(0xA24E) = (uint8_t)(value3 + 1) & 7;
            r->a = a_all >> 8 << 8 | ((uint8_t)(value3 + 1) & 7);
            r->z = ((uint8_t)(value3 + 1) & 7) == 0;
            r->n = (uint8_t)(value3 + 1) & 7 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2C57, 0xC76256); GUARD_JSL(c, sp_call, 0x2C57); } /* refresh_native_shop_frame_graphics_icons_and_request_sound */
            bool m_ret = r->mf;
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            bool overflow_ret = r->v;
            m_flag = m_ret;
            x_flag = x_ret2;
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret3;
            y1 = y_ret;
            carry1 = carry_ret2;
            zero1 = zero_ret2;
            negative1 = negative_ret2;
            overflow1 = overflow_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02C3C, SOM_RTS, "gen", advance_native_settings_palette_cursor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 29, 13)
