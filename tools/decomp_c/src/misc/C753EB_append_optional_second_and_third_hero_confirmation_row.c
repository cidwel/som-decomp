#include "som_c.h"

/* C753EB append_optional_second_and_third_hero_confirmation_row   [class B, 29 bytes, 13 instructions]
 * Source: src/rom/append_optional_second_and_third_hero_confirmation_row.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_optional_second_and_third_hero_confirmation_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA177);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0;
    } else {
        RAM8(0x9C00 + x) = 0xA7;
        RAM8(0x9C00 + (uint16_t)(x + 1)) = 0xAA;
        r->a = (a_hi << 8) | 6;
        r->x = (uint16_t)(x + 2);
        { const uint16_t sp_call = r->sp; JSR(c, 0x5400, 0xC759E0); GUARD_JSR(c, sp_call, 0x5400); } /* append_native_saved_slot_format_pair */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5403, 0xC75389); GUARD_JSR(c, sp_call, 0x5403); } /* append_native_saved_slot_text_space_token */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5406, 0xC75408); GUARD_JSR(c, sp_call, 0x5406); } /* append_native_confirmation_hero_extra_statistics */
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret2;
        x_flag = x_ret4;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret5;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC753EB, SOM_RTS, "gen", append_optional_second_and_third_hero_confirmation_row, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 13)
