#include "som_c.h"

/* C0BD3D transfer_controller_to_eligible_party_actor   [class B, 84 bytes, 41 instructions]
 * Source: src/rom/transfer_controller_to_eligible_party_actor.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void transfer_controller_to_eligible_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xE000 + x);
    if (value == 0) {
        r->c = 0;
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        r->c = 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xE190 + x);
    if ((value2 & 0xC160) != 0) {
        r->a = (r->a & 0x00FF) | (((value2 & 0xC160) >> 8) << 8);
        r->c = 0;
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE02C + x);
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE08C + x);
    if ((value3 | value4) != 0) {
        r->a = (r->a & 0x00FF) | (((value2 & 0xC160) >> 8) << 8);
        r->c = 0;
        RETURN_RTS(c);
    }
    BUS16_SET(c, dp, x);
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 1));
    uint8_t a1;
    if (value5 != 0) {
        a1 = value5;
    } else {
        a1 = (uint8_t)(value5 + 1);
    }
    BUS8_SET(c, (db << 0x10) + 0xD9 + y, a1);
    uint8_t a2;
    if ((uint8_t)((uint8_t)y + 1) != 3) {
        a2 = (uint8_t)((uint8_t)y + 1);
    } else {
        a2 = 4;
    }
    BUS8_SET(c, (db << 0x10) + 0xE02C + x, a2);
    BUS8_SET(c, (db << 0x10) + 0xE013 + x, 0);
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 4));
    BUS8_SET(c, (db << 0x10) + 0xE02C + value6, 0);
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE08C + value6);
    BUS8_SET(c, (db << 0x10) + 0xE08C + value6, 0);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value7 != 0) {
        x_flag = 0;
        a_hi1 = (value2 & 0xC160) >> 8;
        x1 = value6;
        y1 = y;
        carry1 = (uint8_t)((uint8_t)y + 1) >= 3;
        overflow1 = overflow;
        data_bank = db;
        direct_page = dp;
    } else {
        r->a = ((value2 & 0xC160) >> 8 << 8) | value7;
        r->x = value6;
        r->c = (uint8_t)((uint8_t)y + 1) >= 3;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBD81, 0xC0BDB0); GUARD_JSR(c, sp_call, 0xBD81); } /* external */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    RAM8(0x0000 + sp0) = data_bank;
    RAM8(0x0000 + sp0 - 1) = 0;
    r->a = (a_hi1 << 8) | 0;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = x_flag;
    r->db = 0;
    r->dp = direct_page;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBD8B, 0xC0BF38); GUARD_JSR(c, sp_call, 0xBD8B); } /* wait_for_nmi_and_update_controller_hud */
    r->sp += 1;
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->c = 1;
    r->db = value8;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BD3D, SOM_RTS, "gen", transfer_controller_to_eligible_party_actor, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 84, 41)
