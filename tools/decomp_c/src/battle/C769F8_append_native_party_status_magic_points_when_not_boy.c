#include "som_c.h"

/* C769F8 append_native_party_status_magic_points_when_not_boy   [class B, 55 bytes, 25 instructions]
 * Source: src/rom/append_native_party_status_magic_points_when_not_boy.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_party_status_magic_points_when_not_boy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x19FE);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 0) {
        m_flag = 1;
        x_flag = 0;
        a1 = value;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = value == 0;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0;
    } else {
        r->a = (a_hi << 8) | 4;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A02, 0xC759E0); GUARD_JSR(c, sp_call, 0x6A02); } /* append_native_saved_slot_format_pair */
        r->y = 0x7B33;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A08, 0xC76ABE); GUARD_JSR(c, sp_call, 0x6A08); } /* select_bank_C7_and_copy_native_terminated_tokens */
        uint8_t db_ret = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A0B, 0xC76A95); GUARD_JSR(c, sp_call, 0x6A0B); } /* derive_selected_native_party_status_record_offset */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t y_ret2 = r->y;
        RAM8(0x0000 + sp0) = y_ret2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y_ret2;
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xE186 + y_ret2);
        r->a = value2;
        r->y = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 1;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A16, 0xC75AFC); GUARD_JSR(c, sp_call, 0x6A16); } /* format_and_append_native_saved_slot_decimal_pair */
        r->sp += 2;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        uint16_t x_ret4 = r->x;
        BUS8_SET(c, (db_ret2 << 0x10) + 0x9C00 + x_ret4, 0xC1);
        r->a = (a_all4 >> 8 << 8) | 0xC1;
        r->x = (uint16_t)(x_ret4 + 1);
        r->z = (uint16_t)(x_ret4 + 1) == 0;
        r->n = (uint16_t)(x_ret4 + 1) & 0x8000;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A1F, 0xC75389); GUARD_JSR(c, sp_call, 0x6A1F); } /* append_native_saved_slot_text_space_token */
        r->sp += 2;
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value5 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE187 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)));
        r->a = value5;
        r->y = value5;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6A2A, 0xC75AFC); GUARD_JSR(c, sp_call, 0x6A2A); } /* format_and_append_native_saved_slot_decimal_pair */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret6 = r->xf;
        uint16_t a_all6 = r->a;
        uint16_t x_ret7 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret6 = r->z;
        bool overflow_ret2 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret6;
        a1 = (uint8_t)a_all6;
        a_hi1 = a_all6 >> 8;
        x1 = x_ret7;
        y1 = y_ret4;
        carry1 = carry_ret4;
        zero1 = zero_ret6;
        overflow1 = overflow_ret2;
        data_bank = db_ret4;
        direct_page = dp_ret4;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6A2D, 0xC7538D); GUARD_JSR(c, sp_call, 0x6A2D); } /* append_native_saved_slot_text_line_token */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC769F8, SOM_RTS, "gen", append_native_party_status_magic_points_when_not_boy, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 55, 25)
