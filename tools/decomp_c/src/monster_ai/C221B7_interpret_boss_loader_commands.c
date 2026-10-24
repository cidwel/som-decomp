#include "som_c.h"

/* C221B7 interpret_boss_loader_commands   [class A, 27 bytes, 13 instructions]
 * Source: src/rom/interpret_boss_loader_commands.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXY.
 */
static void interpret_boss_loader_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    BUS16_SET(c, (uint16_t)(dp + 0x30), a);
    BUS16_SET(c, (uint16_t)(dp + 0x32), 0xC1);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = dp;
    for (;;) {
        uint8_t value = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page + 0x32)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page + 0x30)), BUS8_RDP(c, (uint16_t)(direct_page + 0x32)));
        if (value != 0xFF) {
            uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
            BUS16_RMW_SET(c, (uint16_t)(direct_page + 0x30), (uint16_t)(value2 + 1));
            r->a = (a_hi1 << 8) | value;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = value >= 0xFF;
            r->z = (uint16_t)(value2 + 1) == 0;
            r->n = (uint16_t)(value2 + 1) & 0x8000;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0x21CC, 0xC221D2); GUARD_JSR(c, sp_call, 0x21CC); } /* dispatch_boss_loader_command */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            if (m_ret != 0) { c->fail = 3; return; }
            if (x_ret != 0) { c->fail = 3; return; }
            a_hi1 = a_all >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        x1 = (uint8_t)x1;
        y1 = (uint8_t)y1;
        break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = (uint8_t)x1;
    r->y = (uint8_t)y1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC221B7, SOM_RTS, "gen", interpret_boss_loader_commands, 0, L_B | L_X | L_Y, 1, 0, 0, 27, 13)
