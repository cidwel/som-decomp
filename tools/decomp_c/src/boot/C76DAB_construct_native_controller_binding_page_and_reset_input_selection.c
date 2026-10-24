#include "som_c.h"

/* C76DAB construct_native_controller_binding_page_and_reset_input_selection   [class B, 81 bytes, 27 instructions]
 * Source: src/rom/construct_native_controller_binding_page_and_reset_input_selection.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_controller_binding_page_and_reset_input_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA20F) = 7;
    r->a = (a_hi << 8) | 7;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DB3, 0xC76FC2); GUARD_JSL(c, sp_call, 0x6DB3); } /* external */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DB7, 0xC02ACB); GUARD_JSL(c, sp_call, 0x6DB7); } /* construct_native_menu_page_long_call_wrapper */
    uint16_t dp_ret2 = r->dp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DBB, 0xC02ACF); GUARD_JSL(c, sp_call, 0x6DBB); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DBF, 0xC02AD3); GUARD_JSL(c, sp_call, 0x6DBF); } /* upload_native_menu_sprite_tables_long_wrapper */
    uint8_t db_ret3 = r->db;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DC3, 0xC7595C); GUARD_JSL(c, sp_call, 0x6DC3); } /* upload_native_saved_slot_six_byte_palette */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DC7, 0xC76DFC); GUARD_JSL(c, sp_call, 0x6DC7); } /* decode_native_controller_layout_and_publish_four_button_labels */
    uint16_t y_ret3 = r->y;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6DCB, 0xC76F29); GUARD_JSL(c, sp_call, 0x6DCB); } /* snapshot_native_controller_permutation_to_two_buffers */
    bool x_ret13 = r->xf;
    uint16_t a_all7 = r->a;
    if (x_ret13) {
        uint8_t value = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA220);
        uint8_t value2 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA22F + value);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool zero1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value2 & 3) == 0) {
            m_flag = 1;
            x_flag = 1;
            a1 = value2 & 3;
            a_hi1 = a_all7 >> 8;
            x1 = value;
            y1 = (uint8_t)y_ret3;
            zero1 = (value2 & 3) == 0;
            data_bank = db_ret3;
            direct_page = dp_ret2;
        } else {
            r->a = a_all7 >> 8 << 8 | (value2 & 3);
            r->x = value;
            r->y = (uint8_t)y_ret3;
            r->z = (value2 & 3) == 0;
            r->n = value2 & 3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DD9, 0xC76F74); GUARD_JSL(c, sp_call, 0x6DD9); } /* swap_and_mirror_native_controller_frame_tiles */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret15 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t x_ret16 = r->x;
            uint16_t y_ret4 = r->y;
            bool zero_ret8 = r->z;
            m_flag = m_ret3;
            x_flag = x_ret15;
            a1 = (uint8_t)a_all8;
            a_hi1 = a_all8 >> 8;
            x1 = x_ret16;
            y1 = y_ret4;
            zero1 = zero_ret8;
            data_bank = db_ret4;
            direct_page = dp_ret3;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->z = zero1;
        r->mf = m_flag;
        r->xf = x_flag;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6DDD, 0xC02AD7); GUARD_JSL(c, sp_call, 0x6DDD); } /* native_menu_tile_workspace_upload_long_wrapper */
        bool m_ret4 = r->mf;
        if (m_ret4) {
            BUS8_SET(c, (data_bank << 0x10) + 0xA211, 0);
            BUS8_SET(c, (data_bank << 0x10) + 0xA180, 0);
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DE7, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6DE7); } /* reset_native_menu_publication_long_wrapper */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x2 = 6;
            for (;;) {
                BUS8_SET(c, (data_bank << 0x10) + 0xA202 + x2, 0);
                x2 = (uint16_t)(x2 - 1);
                if (!(x2 != 0)) break;
            }
            BUS8_SET(c, (data_bank << 0x10) + 0xA1D8, 4);
            uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0xA212);
            BUS8_SET(c, (data_bank << 0x10) + 0xA212, value3 & 0x7F);
            r->mf = 1;
            RETURN_RTL(c);
        } else {
            BUS16_SET(c, (data_bank << 0x10) + 0xA211, 0);
            BUS16_SET(c, (data_bank << 0x10) + 0xA180, 0);
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DE7, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6DE7); } /* reset_native_menu_publication_long_wrapper */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x3 = 6;
            for (;;) {
                BUS16_SET(c, (data_bank << 0x10) + 0xA202 + x3, 0);
                x3 = (uint16_t)(x3 - 1);
                if (!(x3 != 0)) break;
            }
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
    } else {
        uint16_t value4 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA220);
        uint8_t value5 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA22F + value4);
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x4;
        uint16_t y2;
        bool zero2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if ((value5 & 3) == 0) {
            m_flag2 = 1;
            x_flag2 = 0;
            a2 = value5 & 3;
            a_hi2 = a_all7 >> 8;
            x4 = value4;
            y2 = y_ret3;
            zero2 = (value5 & 3) == 0;
            data_bank2 = db_ret3;
            direct_page2 = dp_ret2;
        } else {
            r->a = a_all7 >> 8 << 8 | (value5 & 3);
            r->x = value4;
            r->z = (value5 & 3) == 0;
            r->n = value5 & 3 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DD9, 0xC76F74); GUARD_JSL(c, sp_call, 0x6DD9); } /* swap_and_mirror_native_controller_frame_tiles */
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret5 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret18 = r->xf;
            uint16_t a_all12 = r->a;
            uint16_t x_ret19 = r->x;
            uint16_t y_ret5 = r->y;
            bool zero_ret12 = r->z;
            m_flag2 = m_ret5;
            x_flag2 = x_ret18;
            a2 = (uint8_t)a_all12;
            a_hi2 = a_all12 >> 8;
            x4 = x_ret19;
            y2 = y_ret5;
            zero2 = zero_ret12;
            data_bank2 = db_ret5;
            direct_page2 = dp_ret4;
        }
        r->a = (a_hi2 << 8) | a2;
        r->x = x4;
        r->y = y2;
        r->z = zero2;
        r->mf = m_flag2;
        r->xf = x_flag2;
        r->db = data_bank2;
        r->dp = direct_page2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6DDD, 0xC02AD7); GUARD_JSL(c, sp_call, 0x6DDD); } /* native_menu_tile_workspace_upload_long_wrapper */
        bool m_ret6 = r->mf;
        if (m_ret6) {
            BUS8_SET(c, (data_bank2 << 0x10) + 0xA211, 0);
            BUS8_SET(c, (data_bank2 << 0x10) + 0xA180, 0);
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DE7, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6DE7); } /* reset_native_menu_publication_long_wrapper */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x5 = 6;
            for (;;) {
                BUS8_SET(c, (data_bank2 << 0x10) + 0xA202 + x5, 0);
                x5 = (uint16_t)(x5 - 1);
                if (!(x5 != 0)) break;
            }
            BUS8_SET(c, (data_bank2 << 0x10) + 0xA1D8, 4);
            uint8_t value6 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xA212);
            BUS8_SET(c, (data_bank2 << 0x10) + 0xA212, value6 & 0x7F);
            r->mf = 1;
            RETURN_RTL(c);
        } else {
            BUS16_SET(c, (data_bank2 << 0x10) + 0xA211, 0);
            BUS16_SET(c, (data_bank2 << 0x10) + 0xA180, 0);
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6DE7, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6DE7); } /* reset_native_menu_publication_long_wrapper */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x6 = 6;
            for (;;) {
                BUS16_SET(c, (data_bank2 << 0x10) + 0xA202 + x6, 0);
                x6 = (uint16_t)(x6 - 1);
                if (!(x6 != 0)) break;
            }
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
    }
}
SOM_REGISTER(0xC76DAB, SOM_RTL, "gen", construct_native_controller_binding_page_and_reset_input_selection, 0, 0, 1, 1, 0, 81, 27)
