#include "som_c.h"

/* C1CB12 dispatch_external_actor_command_with_saved_context   [class A, 38 bytes, 23 instructions]
 * Source: src/rom/dispatch_external_actor_command_with_saved_context.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AYCV.
 */
static void dispatch_external_actor_command_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 2;
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    RAM8(0x000C) = (uint8_t)a;
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (a >> 8 >= 0xB0) {
        r->a = a >> 8;
        r->c = a >> 8 >= 0xB0;
        r->z = a >> 8 == 0xB0;
        r->n = (uint8_t)((a >> 8) - 0xB0) & 0x80;
        r->mf = 1;
        r->dp = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCB33, 0x01D6EF); GUARD_JSL(c, sp_call, 0xCB33); } /* dispatch_actor_commands_b0_and_above */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        y1 = y_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        r->a = a >> 8;
        r->c = a >> 8 >= 0xB0;
        r->z = a >> 8 == 0xB0;
        r->n = (uint8_t)((a >> 8) - 0xB0) & 0x80;
        r->mf = 1;
        r->dp = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCB2D, 0x01D5CB); GUARD_JSL(c, sp_call, 0xCB2D); } /* dispatch_actor_commands_below_b0 */
        r->sp += 4;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        m_flag = m_ret2;
        x_flag = x_ret3;
        a1 = (uint8_t)a_all2;
        y1 = y_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (a >> 8 << 8) | a1;
    r->y = y1;
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value;
    r->dp = (value3 << 8) | value2;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CB12, SOM_RTL, "gen", dispatch_external_actor_command_with_saved_context, 0, L_A | L_Y | L_C | L_V, 7, 0, 0, 38, 23)
