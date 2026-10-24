#include "som_c.h"

/* C18018 create_floating_combat_number_with_saved_context   [class A, 37 bytes, 24 instructions]
 * Source: src/rom/create_floating_combat_number_with_saved_context.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void create_floating_combat_number_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0;
    RAM8(0x0000 + sp0 - 5) = 0;
    uint8_t value = RAM8(0x00F1);
    bool m_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    uint8_t data_bank;
    if (value & 0x80) {
        m_flag = 1;
        a1 = 0;
        a_hi1 = a;
        x1 = x;
        y1 = y;
        data_bank = 0x7E;
    } else {
        RAM8(0x0000 + sp0 - 4) = 0x7E;
        RAM8(0xE04F + x) = a;
        RAM8(0xE061 + x) = 1;
        RAM16_SET(0x001E, y);
        r->a = 0x7E01;
        r->z = 0;
        r->n = 0;
        r->v = value & 0x40;
        r->dp = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8038, 0xC1810E); GUARD_JSR(c, sp_call, 0x8038); } /* create_complete_floating_combat_number */
        r->sp += 4;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        m_flag = m_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        data_bank = db_ret;
    }
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = value5 & 0x01;
    r->z = value5 & 0x02;
    r->n = value5 & 0x80;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value2;
    r->dp = (value4 << 8) | value3;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC18018, SOM_RTL, "gen", create_floating_combat_number_with_saved_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 37, 24)

/* Catalogued at the bank mirror 018018: registered under that key as well. */
static void create_floating_combat_number_with_saved_context_mirror(SomCtx *c) { create_floating_combat_number_with_saved_context(c); }
SOM_REGISTER(0x018018, SOM_RTL, "gen", create_floating_combat_number_with_saved_context_mirror, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 37, 24)
