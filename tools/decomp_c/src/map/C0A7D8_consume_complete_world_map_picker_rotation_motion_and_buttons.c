#include "som_c.h"

/* C0A7D8 consume_complete_world_map_picker_rotation_motion_and_buttons   [class B, 105 bytes, 56 instructions]
 * Source: src/rom/consume_complete_world_map_picker_rotation_motion_and_buttons.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void consume_complete_world_map_picker_rotation_motion_and_buttons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xA7DA, 0xC087E0); GUARD_JSR(c, sp_call, 0xA7DA); } /* poll_selected_hero_controller_and_restore_ui_input_word */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t value = RAM8(0x00CC);
    RAM8(0x00CC) &= 0xEF;
    if ((value & 0x10) == 0) {
        uint8_t value2 = RAM8(0x00CC);
        RAM8(0x00CC) &= 0xF7;
        if ((value2 & 8) == 0) {
            uint8_t value3 = RAM8(0x0043);
            bool m_flag2;
            bool x_flag2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool overflow2;
            if ((value3 & 3) == 0) {
                m_flag2 = 1;
                x_flag2 = 1;
                a_hi2 = a_all >> 8;
                x2 = (uint8_t)x_ret;
                y2 = (uint8_t)y_ret;
                overflow2 = overflow_ret;
            } else {
                uint8_t value4 = RAM8(0x001F);
                bool m_flag;
                bool x_flag;
                uint8_t a_hi1;
                uint16_t x1;
                uint16_t y1;
                bool overflow1;
                if (value4 != 0) {
                    m_flag = 1;
                    x_flag = 1;
                    a_hi1 = a_all >> 8;
                    x1 = (uint8_t)x_ret;
                    y1 = (uint8_t)y_ret;
                    overflow1 = overflow_ret;
                } else {
                    RAM8(0x001F)++;
                    uint8_t value5 = RAM8(0x001F);
                    r->a = (a_all >> 8 << 8) | value4;
                    r->x = (uint8_t)x_ret;
                    r->y = (uint8_t)y_ret;
                    r->z = value5 == 0;
                    r->n = value5 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xA7FF, 0xC083E7); GUARD_JSR(c, sp_call, 0xA7FF); } /* advance_ui_horizontal_rotation_and_attribute_windows */
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xA802, 0xC0A9E1); GUARD_JSR(c, sp_call, 0xA802); } /* prepare_world_map_picker_scaled_matrix_coefficients */
                    bool x_ret3 = r->xf;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret3 = r->y;
                    bool overflow_ret3 = r->v;
                    m_flag = 0;
                    x_flag = x_ret3;
                    a_hi1 = a_all3 >> 8;
                    x1 = x_ret4;
                    y1 = y_ret3;
                    overflow1 = overflow_ret3;
                }
                m_flag2 = m_flag;
                x_flag2 = x_flag;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                overflow2 = overflow1;
            }
            uint8_t value6 = RAM8(0x0043);
            if ((value6 & 0x0C) != 0) {
                RAM8(0x005E) = 0x0B;
                r->a = a_hi2 << 8 | (value6 & 0x0C);
                r->x = 0x0B;
                r->y = (uint8_t)y2;
                r->z = 0;
                r->n = 0;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA813, 0xC08700); GUARD_JSR(c, sp_call, 0xA813); } /* external */
                uint16_t dp_ret = r->dp;
                uint16_t x_ret6 = r->x;
                uint16_t y_ret4 = r->y;
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x43));
                uint8_t a_hi3;
                bool overflow3;
                if ((value7 & 4) == 0) {
                    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x0A));
                    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x68));
                    BUS16_SET(c, (uint16_t)(dp_ret + 0x0A), (uint16_t)(value8 - value9));
                    uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 8));
                    uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x66));
                    BUS16_SET(c, (uint16_t)(dp_ret + 8), (uint16_t)(value10 - value11));
                    a_hi3 = (uint16_t)(value10 - value11) >> 8;
                    overflow3 = ((value10 ^ value11) & (value10 ^ (uint16_t)(value10 - value11)) & 0x8000) != 0;
                } else {
                    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x0A));
                    uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x68));
                    BUS16_SET(c, (uint16_t)(dp_ret + 0x0A), (uint16_t)(value12 + value13));
                    uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 8));
                    uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x66));
                    BUS16_SET(c, (uint16_t)(dp_ret + 8), (uint16_t)(value14 + value15));
                    a_hi3 = (uint16_t)(value14 + value15) >> 8;
                    overflow3 = ((value14 ^ (uint16_t)(value14 + value15)) & (value15 ^ (uint16_t)(value14 + value15)) & 0x8000) != 0;
                }
                r->a = 1;
                r->x = (uint8_t)x_ret6;
                r->y = (uint8_t)y_ret4;
                r->c = 0;
                r->v = overflow3;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTS(c);
            }
            r->a = a_hi2 << 8 | (value6 & 0x0C);
            r->x = (uint8_t)x2;
            r->y = (uint8_t)y2;
            r->c = 0;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        SET_A8(r, 0);
        r->x = (uint8_t)x_ret;
        r->y = (uint8_t)y_ret;
        r->c = 1;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    SET_A8(r, 1);
    r->x = (uint8_t)x_ret;
    r->y = (uint8_t)y_ret;
    r->c = 1;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A7D8, SOM_RTS, "gen", consume_complete_world_map_picker_rotation_motion_and_buttons, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 105, 56)
