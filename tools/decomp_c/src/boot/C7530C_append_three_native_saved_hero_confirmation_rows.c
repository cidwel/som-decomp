#include "som_c.h"

/* C7530C append_three_native_saved_hero_confirmation_rows   [class B, 93 bytes, 39 instructions]
 * Source: src/rom/append_three_native_saved_hero_confirmation_rows.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void append_three_native_saved_hero_confirmation_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->mf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5311, 0xC75D00); GUARD_JSR(c, sp_call, 0x5311); } /* derive_selected_save_slot_primary_or_backup_offset */
    r->sp += 2;
    uint16_t x_ret = r->x;
    RAM16_SET(0xA171, x_ret);
    uint16_t value = RAM16(0xA177);
    RAM16_SET(0xA173, (value & 0xFF) << 1);
    uint16_t value2 = RAM16(0xA173);
    uint16_t value3 = RAM16(0xA171);
    uint8_t value4 = BUS8(c, 0x306283 + (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3));
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    bool m_flag2;
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value4 != 1) {
        r->a = ((uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3) >> 8 << 8) | value4;
        r->x = (value6 << 8) | value5;
        r->c = value4 >= 1;
        r->v = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5361, 0xC7538D); GUARD_JSR(c, sp_call, 0x5361); } /* append_native_saved_slot_text_line_token */
        { const uint16_t sp_call = r->sp; JSR(c, 0x5364, 0xC7538D); GUARD_JSR(c, sp_call, 0x5364); } /* append_native_saved_slot_text_line_token */
        { const uint16_t sp_call = r->sp; JSR(c, 0x5367, 0xC7538D); GUARD_JSR(c, sp_call, 0x5367); } /* append_native_saved_slot_text_line_token */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret6 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret7 = r->x;
        m_flag2 = m_ret3;
        x_flag2 = x_ret6;
        a_hi2 = a_all4 >> 8;
        x2 = x_ret7;
        y2 = y;
        overflow2 = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & 0x8000) != 0;
        data_bank2 = db_ret3;
        direct_page2 = dp_ret3;
    } else {
        uint8_t value7 = RAM8(0xA216);
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value7 & 3) == 3) {
            r->a = (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3) >> 8 << 8 | (value7 & 3);
            r->x = (value6 << 8) | value5;
            r->c = (value7 & 3) >= 3;
            r->v = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5361, 0xC7538D); GUARD_JSR(c, sp_call, 0x5361); } /* append_native_saved_slot_text_line_token */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5364, 0xC7538D); GUARD_JSR(c, sp_call, 0x5364); } /* append_native_saved_slot_text_line_token */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5367, 0xC7538D); GUARD_JSR(c, sp_call, 0x5367); } /* append_native_saved_slot_text_line_token */
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            bool m_ret6 = r->mf;
            bool x_ret12 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t x_ret13 = r->x;
            m_flag = m_ret6;
            x_flag = x_ret12;
            a_hi1 = a_all7 >> 8;
            x1 = x_ret13;
            y1 = y;
            overflow1 = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & 0x8000) != 0;
            data_bank = db_ret6;
            direct_page = dp_ret6;
        } else {
            r->a = (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3) >> 8 << 8 | (value7 & 3);
            r->x = (value6 << 8) | value5;
            r->v = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + value3)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x533F, 0xC75394); GUARD_JSR(c, sp_call, 0x533F); } /* append_terminated_native_saved_hero_confirmation_name */
            uint16_t a_all8 = r->a;
            r->a = (a_all8 >> 8 << 8) | 7;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5344, 0xC759E0); GUARD_JSR(c, sp_call, 0x5344); } /* append_native_saved_slot_format_pair */
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5347, 0xC753C8); GUARD_JSR(c, sp_call, 0x5347); } /* append_native_confirmation_hero_level */
            { const uint16_t sp_call = r->sp; JSR(c, 0x534A, 0xC7538D); GUARD_JSR(c, sp_call, 0x534A); } /* append_native_saved_slot_text_line_token */
            { const uint16_t sp_call = r->sp; JSR(c, 0x534D, 0xC75386); GUARD_JSR(c, sp_call, 0x534D); } /* append_two_native_saved_slot_text_space_tokens */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5350, 0xC753D6); GUARD_JSR(c, sp_call, 0x5350); } /* append_native_confirmation_hero_statistics */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5353, 0xC7538D); GUARD_JSR(c, sp_call, 0x5353); } /* append_native_saved_slot_text_line_token */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5356, 0xC75386); GUARD_JSR(c, sp_call, 0x5356); } /* append_two_native_saved_slot_text_space_tokens */
            { const uint16_t sp_call = r->sp; JSR(c, 0x5359, 0xC753EB); GUARD_JSR(c, sp_call, 0x5359); } /* append_optional_second_and_third_hero_confirmation_row */
            uint16_t y_ret4 = r->y;
            bool overflow_ret5 = r->v;
            { const uint16_t sp_call = r->sp; JSR(c, 0x535C, 0xC7538D); GUARD_JSR(c, sp_call, 0x535C); } /* append_native_saved_slot_text_line_token */
            uint16_t dp_ret9 = r->dp;
            uint8_t db_ret10 = r->db;
            bool m_ret14 = r->mf;
            bool x_ret30 = r->xf;
            uint16_t a_all17 = r->a;
            uint16_t x_ret31 = r->x;
            m_flag = m_ret14;
            x_flag = x_ret30;
            a_hi1 = a_all17 >> 8;
            x1 = x_ret31;
            y1 = y_ret4;
            overflow1 = overflow_ret5;
            data_bank = db_ret10;
            direct_page = dp_ret9;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7530C, SOM_RTS, "gen", append_three_native_saved_hero_confirmation_rows, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 93, 39)
