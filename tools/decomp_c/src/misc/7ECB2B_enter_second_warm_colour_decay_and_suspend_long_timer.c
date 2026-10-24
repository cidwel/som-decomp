#include "som_c.h"

/* 7ECB2B enter_second_warm_colour_decay_and_suspend_long_timer   [class C, 41 bytes, 18 instructions]
 * Source: src/boot/enter_second_warm_colour_decay_and_suspend_long_timer.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void enter_second_warm_colour_decay_and_suspend_long_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->x = 0x0168;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB36, 0x7EABE7); GUARD_JSR(c, sp_call, 0xCB36); } /* receive_with_supplied_delay */
    r->sp += 3;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret2;
    uint16_t y1 = y_ret;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = dp_ret;
    for (;;) {
        r->a = (a_hi1 << 8) | 0x32;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = x_ret;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB3B, 0x7EC030); GUARD_JSR(c, sp_call, 0xCB3B); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint8_t db_ret2 = r->db;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint8_t value = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + x_ret4);
        if ((value & 0x1F) == 0) {
            r->a = a_all2 >> 8 << 8 | (value & 0x1F);
            r->z = (value & 0x1F) == 0;
            r->n = value & 0x1F & 0x80;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCB4B, 0x7EC097); GUARD_JSR(c, sp_call, 0xCB4B); } /* append_oneshot_ppu_entry */
            r->sp += 3;
            r->x = 4;
            r->z = 0;
            r->n = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCB51, 0x7EABE7); GUARD_JSR(c, sp_call, 0xCB51); } /* receive_with_supplied_delay */
            r->sp += 3;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            bool m_ret2 = r->mf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            if (m_ret2 != 1) { c->fail = 3; return; }
            a_hi1 = a_all4 >> 8;
            x1 = x_ret6;
            y1 = y_ret4;
            carry1 = carry_ret4;
            overflow1 = overflow_ret4;
            data_bank = db_ret4;
            direct_page = dp_ret4;
            continue;
        }
        BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret4, (uint8_t)((value & 0x1F) - 1) | 0xE0);
        r->a = (a_all2 >> 8 << 8) | ((uint8_t)((value & 0x1F) - 1) | 0xE0);
        r->z = ((uint8_t)((value & 0x1F) - 1) | 0xE0) == 0;
        r->n = ((uint8_t)((value & 0x1F) - 1) | 0xE0) & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB4B, 0x7EC097); GUARD_JSR(c, sp_call, 0xCB4B); } /* append_oneshot_ppu_entry */
        r->sp += 3;
        r->x = 4;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB51, 0x7EABE7); GUARD_JSR(c, sp_call, 0xCB51); } /* receive_with_supplied_delay */
        r->sp += 3;
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        bool m_ret4 = r->mf;
        uint16_t a_all6 = r->a;
        uint16_t x_ret8 = r->x;
        uint16_t y_ret6 = r->y;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        if (m_ret4 != 1) { c->fail = 3; return; }
        a_hi1 = a_all6 >> 8;
        x1 = x_ret8;
        y1 = y_ret6;
        carry1 = carry_ret6;
        overflow1 = overflow_ret6;
        data_bank = db_ret6;
        direct_page = dp_ret6;
    }
}
SOM_REGISTER(0x7ECB2B, SOM_RTS, "gen", enter_second_warm_colour_decay_and_suspend_long_timer, 0, 0, 3, 1, 0, 41, 18)
