#include "som_c.h"

/* C2377A select_changed_boss_state_reset_transients_and_interpret_commands   [class B, 77 bytes, 31 instructions]
 * Source: src/rom/select_changed_boss_state_reset_transients_and_interpret_commands.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void select_changed_boss_state_reset_transients_and_interpret_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x007A + x);
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (a == value) {
        x2 = x;
        y2 = y;
        carry2 = a >= value;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0x0200;
    } else {
        RAM16_SET(0x007A + x, a);
        RAM16_SET(0x0231, 0xC200);
        RAM16_SET(0x0230, RAM16(0x0076 + x));
        uint16_t value3 = BUS16_RDL(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + (uint16_t)(a << 1), RAM8(0x0232));
        RAM16_SET(0x0230, value3);
        RAM16_SET(0x0090 + x, 0);
        RAM16_SET(0x003A + x, 0);
        RAM16_SET(0x003C + x, 0);
        RAM16_SET(0x003E + x, 0);
        RAM16_SET(0x0040 + x, 0);
        RAM16_SET(0x00C4 + x, 0);
        RAM16_SET(0x00C6 + x, 0);
        RAM16_SET(0x0014 + x, 0);
        RAM16_SET(0x0048 + x, 0);
        RAM16_SET(0x004A + x, 0);
        RAM16_SET(0x007C + x, 0);
        uint8_t a_hi1 = value3 >> 8;
        uint16_t x1 = x;
        uint16_t y1 = 0;
        bool carry1 = a & 0x8000;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7E;
        uint16_t direct_page = 0x0200;
        for (;;) {
            uint16_t value4 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page + 0x32)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page + 0x30)) + y1, BUS8_RDP(c, (uint16_t)(direct_page + 0x32)));
            if ((value4 & 0xFF) != 0xFF) {
                r->a = value4 & 0xFF;
                r->x = x1;
                r->y = (uint16_t)(y1 + 1);
                r->c = (value4 & 0xFF) >= 0xFF;
                r->z = (uint16_t)(y1 + 1) == 0;
                r->n = (uint16_t)(y1 + 1) & 0x8000;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                { const uint16_t sp_call = r->sp; JSR(c, 0x37C3, 0xC237C7); GUARD_JSR(c, sp_call, 0x37C3); } /* dispatch_boss_state_byte_command_through_original_twenty_two_word_table */
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                if (m_ret != 0) { c->fail = 3; return; }
                if (x_ret != 0) { c->fail = 3; return; }
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                y1 = y_ret;
                carry1 = carry_ret;
                overflow1 = overflow_ret;
                data_bank = db_ret;
                direct_page = dp_ret;
                continue;
            }
            a_hi1 = 0;
            carry1 = (value4 & 0xFF) >= 0xFF;
            break;
        }
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = direct_page2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2377A, SOM_RTS, "gen", select_changed_boss_state_reset_transients_and_interpret_commands, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 77, 31)
