#include "som_c.h"

/* C211C7 set_boss_actor_palettes_and_advance_command   [class B, 37 bytes, 20 instructions]
 * Source: src/rom/set_boss_actor_palettes_and_advance_command.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYV.
 */
static void set_boss_actor_palettes_and_advance_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_11c8 = 0;
    uint16_t x_11c8 = 0;
    uint16_t y_11c8 = 0;
    bool overflow_11c8 = 0;
    uint16_t direct_page_11c8 = 0;
    uint8_t data_bank_11c8 = 0;
    uint8_t a_hi_11e3 = 0;
    uint16_t y_11e3 = 0;
    bool overflow_11e3 = 0;
    uint16_t direct_page_11e3 = 0;
    uint8_t data_bank_11e3 = 0;
    uint8_t a_hi_11c82 = 0;
    uint8_t x_11c82 = 0;
    uint8_t y_11c82 = 0;
    bool overflow_11c82 = 0;
    uint16_t direct_page_11c82 = 0;
    uint8_t data_bank_11c82 = 0;
    uint8_t a_hi_11e32 = 0;
    uint8_t y_11e32 = 0;
    bool overflow_11e32 = 0;
    uint16_t direct_page_11e32 = 0;
    uint8_t data_bank_11e32 = 0;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    a_hi_11c8 = a_hi;
    x_11c8 = x;
    y_11c8 = y;
    overflow_11c8 = overflow;
    direct_page_11c8 = dp;
    data_bank_11c8 = 0x7E;
    shared_11C8:;
    uint8_t value = BUS8_RDP(c, (data_bank_11c8 << 0x10) + 0x18 + x_11c8);
    if (value == 0) {
        a_hi_11e3 = a_hi_11c8;
        y_11e3 = y_11c8;
        overflow_11e3 = overflow_11c8;
        direct_page_11e3 = direct_page_11c8;
        data_bank_11e3 = data_bank_11c8;
        goto shared_11E3;
    }
    RAM8(0x0000 + sp0 - 2) = x_11c8 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_11c8;
    r->a = 1;
    r->x = ((a_hi_11c8 << 8) | value) & 0xFF;
    r->y = y_11c8;
    r->z = 0;
    r->n = 0;
    r->v = overflow_11c8;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_11c8;
    r->dp = direct_page_11c8;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x11D9, 0xC22700); GUARD_JSR(c, sp_call, 0x11D9); } /* external */
    r->sp += 4;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 3);
        if (((uint8_t)(value2 + 1) & 4) == 0) {
            a_hi_11c82 = a_all >> 8;
            x_11c82 = (uint8_t)(value2 + 1);
            y_11c82 = (uint8_t)y_ret;
            overflow_11c82 = overflow_ret;
            direct_page_11c82 = dp_ret;
            data_bank_11c82 = db_ret;
            goto shared_11C8_1;
        }
        a_hi_11e32 = a_all >> 8;
        y_11e32 = (uint8_t)y_ret;
        overflow_11e32 = overflow_ret;
        direct_page_11e32 = dp_ret;
        data_bank_11e32 = db_ret;
        goto shared_11E3_1;
    } else {
        uint8_t value3 = RAM8(0x0000 + sp0 - 3);
        uint8_t value4 = RAM8(0x0000 + sp0 - 2);
        if (((uint8_t)(((value4 << 8) | value3) + 1) & 4) == 0) {
            a_hi_11c8 = a_all >> 8;
            x_11c8 = (uint16_t)(((value4 << 8) | value3) + 1);
            y_11c8 = y_ret;
            overflow_11c8 = overflow_ret;
            direct_page_11c8 = dp_ret;
            data_bank_11c8 = db_ret;
            goto shared_11C8;
        }
        a_hi_11e3 = a_all >> 8;
        y_11e3 = y_ret;
        overflow_11e3 = overflow_ret;
        direct_page_11e3 = dp_ret;
        data_bank_11e3 = db_ret;
        goto shared_11E3;
    }
    shared_11E3:;
    BUS8_SET(c, (data_bank_11e3 << 0x10) + 0x0100 + ((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)), 0xC1);
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(direct_page_11e3 + 0x87));
    r->a = (a_hi_11e3 << 8) | 0xC1;
    r->x = value7;
    r->y = y_11e3;
    r->v = overflow_11e3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_11e3;
    r->dp = direct_page_11e3;
    RETURN_RTS(c);
    shared_11C8_1:;
    uint8_t value8 = BUS8_RDP(c, (data_bank_11c82 << 0x10) + 0x18 + x_11c82);
    if (value8 == 0) {
        a_hi_11e32 = a_hi_11c82;
        y_11e32 = y_11c82;
        overflow_11e32 = overflow_11c82;
        direct_page_11e32 = direct_page_11c82;
        data_bank_11e32 = data_bank_11c82;
        goto shared_11E3_1;
    }
    RAM8(0x0000 + sp0 - 3) = x_11c82;
    r->a = 1;
    r->x = ((a_hi_11c82 << 8) | value8) & 0xFF;
    r->y = y_11c82;
    r->z = 0;
    r->n = 0;
    r->v = overflow_11c82;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_11c82;
    r->dp = direct_page_11c82;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x11D9, 0xC22700); GUARD_JSR(c, sp_call, 0x11D9); } /* external */
    r->sp += 4;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    if (x_ret3) {
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        if (((uint8_t)(value9 + 1) & 4) == 0) {
            a_hi_11c82 = a_all2 >> 8;
            x_11c82 = (uint8_t)(value9 + 1);
            y_11c82 = (uint8_t)y_ret2;
            overflow_11c82 = overflow_ret2;
            direct_page_11c82 = dp_ret2;
            data_bank_11c82 = db_ret2;
            goto shared_11C8_1;
        }
        a_hi_11e32 = a_all2 >> 8;
        y_11e32 = (uint8_t)y_ret2;
        overflow_11e32 = overflow_ret2;
        direct_page_11e32 = dp_ret2;
        data_bank_11e32 = db_ret2;
        goto shared_11E3_1;
    } else {
        uint8_t value10 = RAM8(0x0000 + sp0 - 3);
        uint8_t value11 = RAM8(0x0000 + sp0 - 2);
        if (((uint8_t)(((value11 << 8) | value10) + 1) & 4) == 0) {
            a_hi_11c8 = a_all2 >> 8;
            x_11c8 = (uint16_t)(((value11 << 8) | value10) + 1);
            y_11c8 = y_ret2;
            overflow_11c8 = overflow_ret2;
            direct_page_11c8 = dp_ret2;
            data_bank_11c8 = db_ret2;
            goto shared_11C8;
        }
        a_hi_11e3 = a_all2 >> 8;
        y_11e3 = y_ret2;
        overflow_11e3 = overflow_ret2;
        direct_page_11e3 = dp_ret2;
        data_bank_11e3 = db_ret2;
        goto shared_11E3;
    }
    shared_11E3_1:;
    BUS8_SET(c, (data_bank_11e32 << 0x10) + 0x0100 + RAM8(0x0000 + sp0 - 2), 0xC1);
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_11e32 + 0x87));
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    r->a = (a_hi_11e32 << 8) | 0xC1;
    r->x = value13;
    r->y = y_11e32;
    r->z = value13 == 0;
    r->n = value13 & 0x80;
    r->v = overflow_11e32;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_11e32;
    r->dp = direct_page_11e32;
    TAIL_CALL_DYN(c, 0xC20000 | (uint16_t)(((value15 << 8) | value14) + 1), SOM_RTS); /* jump through a pushed address */
}
SOM_REGISTER(0xC211C7, SOM_RTS, "gen", set_boss_actor_palettes_and_advance_command, SOM_UNWINDS, L_B | L_X | L_Y | L_V, 4, 1, 0, 37, 20)
