#include "som_c.h"

/* 7EA8BE idle_until_tasks_complete   [class A, 24 bytes, 12 instructions]
 * Source: src/boot/idle_until_tasks_complete.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0000.  Callers read: ABXYCZNV.
 */
static void idle_until_tasks_complete(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_a8c0 = 0;
    uint16_t y_a8c0 = 0;
    bool carry_a8c0 = 0;
    bool overflow_a8c0 = 0;
    uint16_t direct_page_a8c0 = 0;
    uint8_t data_bank_a8c0 = 0;
    uint8_t a_hi_a8c02 = 0;
    uint8_t y_a8c02 = 0;
    bool carry_a8c02 = 0;
    bool overflow_a8c02 = 0;
    uint16_t direct_page_a8c02 = 0;
    uint8_t data_bank_a8c02 = 0;
    uint8_t a_hi_a8c03 = 0;
    uint16_t y_a8c03 = 0;
    bool carry_a8c03 = 0;
    bool overflow_a8c03 = 0;
    uint16_t direct_page_a8c03 = 0;
    uint8_t data_bank_a8c03 = 0;
    uint8_t a_hi_a8c04 = 0;
    uint8_t y_a8c04 = 0;
    bool carry_a8c04 = 0;
    bool overflow_a8c04 = 0;
    uint16_t direct_page_a8c04 = 0;
    uint8_t data_bank_a8c04 = 0;
    a_hi_a8c0 = a_hi;
    y_a8c0 = y;
    carry_a8c0 = carry;
    overflow_a8c0 = overflow;
    direct_page_a8c0 = 0;
    data_bank_a8c0 = 0x7F;
    shared_A8C0:;
    r->x = 0;
    r->y = y_a8c0;
    r->c = carry_a8c0;
    r->z = 1;
    r->n = 0;
    r->v = overflow_a8c0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_a8c0;
    r->dp = direct_page_a8c0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA8C5, 0x7EABE7); GUARD_JSR(c, sp_call, 0xA8C5); } /* receive_with_supplied_delay */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (m_ret) {
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0x9A);
        if (value != 0) {
            if (x_ret) {
                a_hi_a8c02 = a_all >> 8;
                y_a8c02 = (uint8_t)y_ret;
                carry_a8c02 = carry_ret;
                overflow_a8c02 = overflow_ret;
                direct_page_a8c02 = dp_ret;
                data_bank_a8c02 = db_ret;
                goto shared_A8C0_1;
            } else {
                a_hi_a8c03 = a_all >> 8;
                y_a8c03 = y_ret;
                carry_a8c03 = carry_ret;
                overflow_a8c03 = overflow_ret;
                direct_page_a8c03 = dp_ret;
                data_bank_a8c03 = db_ret;
                goto shared_A8C0_2;
            }
        }
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x98);
        r->sp = (a_all >> 8 << 8) | value2;
        sp0 = r->sp + 4;
        r->a = (a_all >> 8 << 8) | value2;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA8D1, 0x7EA241); GUARD_JSR(c, sp_call, 0xA8D1); } /* release_vertical_irq_use */
        uint8_t value3 = RAM8(0x0000 + sp0 - 3);
        uint8_t value4 = RAM8(0x0000 + sp0 - 2);
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->c = value4 & 0x01;
        r->z = ((value6 << 8) | value5) == 0;
        r->n = ((value6 << 8) | value5) & 0x8000;
        r->v = value4 & 0x40;
        r->mf = value4 & 0x20;
        r->xf = value4 & 0x10;
        r->db = value3;
        r->dp = (value6 << 8) | value5;
        r->i = value4 & 0x04;
        r->d = value4 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 4;
        RETURN_RTS(c);
    } else {
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x9A);
        if (value7 != 0) {
            if (x_ret) {
                a_hi_a8c04 = value7 >> 8;
                y_a8c04 = (uint8_t)y_ret;
                carry_a8c04 = carry_ret;
                overflow_a8c04 = overflow_ret;
                direct_page_a8c04 = dp_ret;
                data_bank_a8c04 = db_ret;
                goto shared_A8C0_3;
            } else {
                a_hi_a8c0 = value7 >> 8;
                y_a8c0 = y_ret;
                carry_a8c0 = carry_ret;
                overflow_a8c0 = overflow_ret;
                direct_page_a8c0 = dp_ret;
                data_bank_a8c0 = db_ret;
                goto shared_A8C0;
            }
        }
        uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0x98);
        r->sp = value8;
        sp0 = r->sp + 4;
        r->a = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA8D1, 0x7EA241); GUARD_JSR(c, sp_call, 0xA8D1); } /* release_vertical_irq_use */
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->c = value10 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value10 & 0x40;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->db = value9;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 4;
        RETURN_RTS(c);
    }
    shared_A8C0_1:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_A8C0_2:;
    r->x = 0;
    r->y = y_a8c03;
    r->c = carry_a8c03;
    r->z = 1;
    r->n = 0;
    r->v = overflow_a8c03;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_a8c03;
    r->dp = direct_page_a8c03;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA8C5, 0x7EABE7); GUARD_JSR(c, sp_call, 0xA8C5); } /* receive_with_supplied_delay */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (m_ret2) {
        uint8_t value13 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x9A);
        if (value13 != 0) {
            if (x_ret5) {
                a_hi_a8c02 = a_all4 >> 8;
                y_a8c02 = (uint8_t)y_ret2;
                carry_a8c02 = carry_ret4;
                overflow_a8c02 = overflow_ret4;
                direct_page_a8c02 = dp_ret2;
                data_bank_a8c02 = db_ret2;
                goto shared_A8C0_1;
            } else {
                a_hi_a8c03 = a_all4 >> 8;
                y_a8c03 = y_ret2;
                carry_a8c03 = carry_ret4;
                overflow_a8c03 = overflow_ret4;
                direct_page_a8c03 = dp_ret2;
                data_bank_a8c03 = db_ret2;
                goto shared_A8C0_2;
            }
        }
        uint8_t value14 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x98);
        r->sp = (a_all4 >> 8 << 8) | value14;
        sp0 = r->sp + 4;
        r->a = (a_all4 >> 8 << 8) | value14;
        r->z = value14 == 0;
        r->n = value14 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA8D1, 0x7EA241); GUARD_JSR(c, sp_call, 0xA8D1); } /* release_vertical_irq_use */
        uint8_t value15 = RAM8(0x0000 + sp0 - 3);
        uint8_t value16 = RAM8(0x0000 + sp0 - 2);
        uint8_t value17 = RAM8(0x0000 + sp0 - 1);
        uint8_t value18 = RAM8(0x0000 + sp0);
        r->c = value16 & 0x01;
        r->z = ((value18 << 8) | value17) == 0;
        r->n = ((value18 << 8) | value17) & 0x8000;
        r->v = value16 & 0x40;
        r->mf = value16 & 0x20;
        r->xf = value16 & 0x10;
        r->db = value15;
        r->dp = (value18 << 8) | value17;
        r->i = value16 & 0x04;
        r->d = value16 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 4;
        RETURN_RTS(c);
    } else {
        uint16_t value19 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x9A);
        if (value19 != 0) {
            if (x_ret5) {
                a_hi_a8c04 = value19 >> 8;
                y_a8c04 = (uint8_t)y_ret2;
                carry_a8c04 = carry_ret4;
                overflow_a8c04 = overflow_ret4;
                direct_page_a8c04 = dp_ret2;
                data_bank_a8c04 = db_ret2;
                goto shared_A8C0_3;
            } else {
                a_hi_a8c0 = value19 >> 8;
                y_a8c0 = y_ret2;
                carry_a8c0 = carry_ret4;
                overflow_a8c0 = overflow_ret4;
                direct_page_a8c0 = dp_ret2;
                data_bank_a8c0 = db_ret2;
                goto shared_A8C0;
            }
        }
        uint16_t value20 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x98);
        r->sp = value20;
        sp0 = r->sp + 4;
        r->a = value20;
        r->z = value20 == 0;
        r->n = value20 & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA8D1, 0x7EA241); GUARD_JSR(c, sp_call, 0xA8D1); } /* release_vertical_irq_use */
        uint8_t value21 = RAM8(0x0000 + sp0 - 3);
        uint8_t value22 = RAM8(0x0000 + sp0 - 2);
        uint8_t value23 = RAM8(0x0000 + sp0 - 1);
        uint8_t value24 = RAM8(0x0000 + sp0);
        r->c = value22 & 0x01;
        r->z = ((value24 << 8) | value23) == 0;
        r->n = ((value24 << 8) | value23) & 0x8000;
        r->v = value22 & 0x40;
        r->mf = value22 & 0x20;
        r->xf = value22 & 0x10;
        r->db = value21;
        r->dp = (value24 << 8) | value23;
        r->i = value22 & 0x04;
        r->d = value22 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 4;
        RETURN_RTS(c);
    }
    shared_A8C0_3:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7EA8BE, SOM_RTL, "gen", idle_until_tasks_complete, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 12)
