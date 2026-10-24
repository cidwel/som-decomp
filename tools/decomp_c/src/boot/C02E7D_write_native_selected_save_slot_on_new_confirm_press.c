#include "som_c.h"

/* C02E7D write_native_selected_save_slot_on_new_confirm_press   [class B, 37 bytes, 14 instructions]
 * Source: src/rom/write_native_selected_save_slot_on_new_confirm_press.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void write_native_selected_save_slot_on_new_confirm_press(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E7F, 0xC03269); GUARD_JSR(c, sp_call, 0x2E7F); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t value = RAM8(0xA204 + x_ret);
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
    uint8_t data_bank;
    if ((value & 0x80) != 0) {
        m_flag = 1;
        x_flag = 0;
        a1 = value;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y;
        carry1 = carry_ret;
        zero1 = (value & 0x80) == 0;
        negative1 = value & 0x80;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->z = (value & 0x80) == 0;
        r->n = value & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2E8A, 0xC755D6); GUARD_JSL(c, sp_call, 0x2E8A); } /* write_selected_saved_game_to_primary_and_backup_sram */
        uint8_t db_ret = r->db;
        uint16_t a_all2 = r->a;
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA211);
        BUS8_SET(c, 0x307FFF, value2);
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
        BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value3 | 1);
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
        BUS8_SET(c, (db_ret << 0x10) + 0xA212, value4 & 0xDF);
        r->a = (a_all2 >> 8 << 8) | 2;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2EA0, 0xC029D2); GUARD_JSR(c, sp_call, 0x2EA0); } /* expand_local_audio_preset_and_send_four_byte_request */
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret3;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        carry1 = carry_ret3;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02E7D, SOM_RTS, "gen", write_native_selected_save_slot_on_new_confirm_press, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 37, 14)
