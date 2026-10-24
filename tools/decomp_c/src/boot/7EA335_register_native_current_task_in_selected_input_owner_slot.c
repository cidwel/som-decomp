#include "som_c.h"

/* 7EA335 register_native_current_task_in_selected_input_owner_slot   [class A, 28 bytes, 18 instructions]
 * Source: src/boot/register_native_current_task_in_selected_input_owner_slot.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void register_native_current_task_in_selected_input_owner_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = RAM16(0x0092);
    RAM8(0x0000 + sp0 - 3) = (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value) >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value);
    r->a = (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value);
    r->c = ((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value > 0xFFFF;
    r->z = (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value) == 0;
    r->n = (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value) & 0x8000;
    r->v = ((((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) ^ (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value)) & (value ^ (uint16_t)(((((a_hi << 8) | a) & 7) << 1 << 1 << 1 << 1) + value)) & 0x8000) != 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA349, 0x7EACE9); GUARD_JSR(c, sp_call, 0xA349); } /* current_task_id */
    r->sp += 5;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value9 = RAM8(0x0000 + sp0 - 4);
        uint8_t value10 = RAM8(0x0000 + sp0 - 3);
        if (m_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 1 + ((value10 << 8) | value9), (uint8_t)a_all);
            uint8_t value11 = RAM8(0x0000 + sp0 - 2);
            uint8_t value12 = RAM8(0x0000 + sp0 - 1);
            uint8_t value13 = RAM8(0x0000 + sp0);
            r->x = (value10 << 8) | value9;
            r->c = value11 & 0x01;
            r->z = ((value13 << 8) | value12) == 0;
            r->n = ((value13 << 8) | value12) & 0x8000;
            r->v = value11 & 0x40;
            r->mf = value11 & 0x20;
            r->xf = value11 & 0x10;
            r->dp = (value13 << 8) | value12;
            r->i = value11 & 0x04;
            r->d = value11 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 1 + ((value10 << 8) | value9), a_all);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->x = (value10 << 8) | value9;
            r->c = value14 & 0x01;
            r->z = ((value16 << 8) | value15) == 0;
            r->n = ((value16 << 8) | value15) & 0x8000;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EA335, SOM_RTS, "gen", register_native_current_task_in_selected_input_owner_slot, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 28, 18)
