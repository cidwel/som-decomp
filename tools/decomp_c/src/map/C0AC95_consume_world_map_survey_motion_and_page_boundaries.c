#include "som_c.h"

/* C0AC95 consume_world_map_survey_motion_and_page_boundaries   [class B, 130 bytes, 67 instructions]
 * Source: src/rom/consume_world_map_survey_motion_and_page_boundaries.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void consume_world_map_survey_motion_and_page_boundaries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xAC97, 0xC087E0); GUARD_JSR(c, sp_call, 0xAC97); } /* poll_selected_hero_controller_and_restore_ui_input_word */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t value = RAM8(0x00CC);
    RAM8(0x00CC) &= 0xDF;
    if ((value & 0x20) == 0) {
        uint8_t value2 = RAM8(0x00CC);
        RAM8(0x00CC) &= 0xF7;
        if ((value2 & 8) == 0) {
            uint8_t value3 = RAM8(0x0043);
            bool m_flag;
            uint8_t a_hi2;
            bool overflow2;
            if ((value3 & 3) == 0) {
                m_flag = 1;
                a_hi2 = a_all >> 8;
                overflow2 = overflow_ret;
            } else {
                uint8_t a1;
                uint8_t a_hi1;
                bool overflow1;
                if (!(value3 & 3 & 0x01)) {
                    uint16_t value4 = RAM16(0x0008);
                    a1 = (uint8_t)(value4 - 4);
                    a_hi1 = (uint16_t)(value4 - 4) >> 8;
                    overflow1 = ((value4 ^ 4) & (value4 ^ (uint16_t)(value4 - 4)) & 0x8000) != 0;
                } else {
                    uint16_t value5 = RAM16(0x0008);
                    a1 = (uint8_t)(value5 + 4);
                    a_hi1 = (uint16_t)(value5 + 4) >> 8;
                    overflow1 = ((value5 ^ (uint16_t)(value5 + 4)) & ((uint16_t)(value5 + 4) ^ 4) & 0x8000) != 0;
                }
                RAM16_SET(0x0008, ((a_hi1 << 8) | a1) & 0x01FC);
                m_flag = 0;
                a_hi2 = (((a_hi1 << 8) | a1) & 0x01FC) >> 8;
                overflow2 = overflow1;
            }
            if ((value3 & 0x0C) != 0) {
                if ((value3 & 4) != 0) {
                    uint16_t value6 = RAM16(0x000A);
                    RAM16_SET(0x000A, (uint16_t)(value6 + 4) & 0x01FC);
                    if (((uint16_t)(value6 + 4) & 0x01FC) == 0) {
                        r->x = (uint8_t)x_ret;
                        r->y = (uint8_t)y_ret;
                        r->mf = 0;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xACF8, 0xC0ADF0); GUARD_JSR(c, sp_call, 0xACF8); } /* external */
                        r->c = 0;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (((uint16_t)(value6 + 4) & 0x01FC) != 0x0180) {
                        r->a = (uint16_t)(value6 + 4) & 0x01FC;
                        r->x = (uint8_t)x_ret;
                        r->y = (uint8_t)y_ret;
                        r->c = 0;
                        r->v = ((value6 ^ (uint16_t)(value6 + 4)) & ((uint16_t)(value6 + 4) ^ 4) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        RETURN_RTS(c);
                    }
                    uint16_t value7 = RAM16(0x0015);
                    if (value7 & 0x01) {
                        r->a = value7 >> 1;
                        r->x = (uint8_t)x_ret;
                        r->y = (uint8_t)y_ret;
                        r->c = 0;
                        r->v = ((value6 ^ (uint16_t)(value6 + 4)) & ((uint16_t)(value6 + 4) ^ 4) & 0x8000) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        RETURN_RTS(c);
                    }
                    r->x = (uint8_t)x_ret;
                    r->y = (uint8_t)y_ret;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xAD14, 0xC0ADE3); GUARD_JSR(c, sp_call, 0xAD14); } /* switch_world_map_survey_visible_vram_page_and_scroll */
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 1;
                    RETURN_RTS(c);
                }
                uint16_t value8 = RAM16(0x000A);
                RAM16_SET(0x000A, (uint16_t)(value8 - 4) & 0x01FC);
                if (((uint16_t)(value8 - 4) & 0x01FC) == 0x01FC) {
                    r->x = (uint8_t)x_ret;
                    r->y = (uint8_t)y_ret;
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xAD14, 0xC0ADE3); GUARD_JSR(c, sp_call, 0xAD14); } /* switch_world_map_survey_visible_vram_page_and_scroll */
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 1;
                    RETURN_RTS(c);
                }
                bool m_flag3;
                bool x_flag2;
                uint8_t a3;
                uint8_t a_hi4;
                bool overflow4;
                uint8_t data_bank2;
                uint16_t direct_page2;
                if (((uint16_t)(value8 - 4) & 0x01FC) != 0x80) {
                    m_flag3 = 0;
                    x_flag2 = 1;
                    a3 = (uint8_t)((uint16_t)(value8 - 4) & 0x01FC);
                    a_hi4 = ((uint16_t)(value8 - 4) & 0x01FC) >> 8;
                    overflow4 = ((value8 ^ 4) & (value8 ^ (uint16_t)(value8 - 4)) & 0x8000) != 0;
                    data_bank2 = 0;
                    direct_page2 = 0;
                } else {
                    uint16_t value9 = RAM16(0x0015);
                    bool m_flag2;
                    bool x_flag;
                    uint8_t a2;
                    uint8_t a_hi3;
                    bool overflow3;
                    uint8_t data_bank;
                    uint16_t direct_page;
                    if (!(value9 & 0x01)) {
                        m_flag2 = 0;
                        x_flag = 1;
                        a2 = (uint8_t)(value9 >> 1);
                        a_hi3 = value9 >> 1 >> 8;
                        overflow3 = ((value8 ^ 4) & (value8 ^ (uint16_t)(value8 - 4)) & 0x8000) != 0;
                        data_bank = 0;
                        direct_page = 0;
                    } else {
                        r->x = (uint8_t)x_ret;
                        r->y = (uint8_t)y_ret;
                        r->mf = 0;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xACF8, 0xC0ADF0); GUARD_JSR(c, sp_call, 0xACF8); } /* external */
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        bool m_ret2 = r->mf;
                        bool x_ret3 = r->xf;
                        uint16_t a_all5 = r->a;
                        bool overflow_ret5 = r->v;
                        m_flag2 = m_ret2;
                        x_flag = x_ret3;
                        a2 = (uint8_t)a_all5;
                        a_hi3 = a_all5 >> 8;
                        overflow3 = overflow_ret5;
                        data_bank = db_ret2;
                        direct_page = dp_ret2;
                    }
                    m_flag3 = m_flag2;
                    x_flag2 = x_flag;
                    a3 = a2;
                    a_hi4 = a_hi3;
                    overflow4 = overflow3;
                    data_bank2 = data_bank;
                    direct_page2 = direct_page;
                }
                r->a = (a_hi4 << 8) | a3;
                r->x = (uint8_t)x_ret;
                r->y = (uint8_t)y_ret;
                r->c = 0;
                r->v = overflow4;
                r->mf = m_flag3;
                r->xf = x_flag2;
                r->db = data_bank2;
                r->dp = direct_page2;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = a_hi2 << 8 | (value3 & 0x0C);
            r->x = (uint8_t)x_ret;
            r->y = (uint8_t)y_ret;
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
SOM_REGISTER(0xC0AC95, SOM_RTS, "gen", consume_world_map_survey_motion_and_page_boundaries, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 130, 67)
