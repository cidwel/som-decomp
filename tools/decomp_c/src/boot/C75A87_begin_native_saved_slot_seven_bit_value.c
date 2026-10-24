#include "som_c.h"

/* C75A87 begin_native_saved_slot_seven_bit_value   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/begin_native_saved_slot_seven_bit_value.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXV.
 */
static void begin_native_saved_slot_seven_bit_value(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA216);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 3) == 3) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        x1 = 0;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = a_hi << 8 | (value & 3);
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A98, 0xC75D00); GUARD_JSR(c, sp_call, 0x5A98); } /* derive_selected_save_slot_primary_or_backup_offset */
        r->sp += 2;
        uint16_t x_ret = r->x;
        uint16_t value2 = BUS16(c, 0x3062B7 + x_ret);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->a = value2 & 0x7F;
        r->x = (value4 << 8) | value3;
        r->y = value2 & 0x7F;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AA6, 0xC75389); GUARD_JSR(c, sp_call, 0x5AA6); } /* append_native_saved_slot_text_space_token */
        { const uint16_t sp_call = r->sp; JSR(c, 0x5AA9, 0xC75AFC); GUARD_JSR(c, sp_call, 0x5AA9); } /* format_and_append_native_saved_slot_decimal_pair */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        bool overflow_ret2 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret4;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret5;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75A87, SOM_RTS, "gen", begin_native_saved_slot_seven_bit_value, 0, L_B | L_X | L_V, 2, 1, 0, 36, 16)
