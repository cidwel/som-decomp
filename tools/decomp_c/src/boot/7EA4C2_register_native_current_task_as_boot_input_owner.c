#include "som_c.h"

/* 7EA4C2 register_native_current_task_as_boot_input_owner   [class A, 21 bytes, 14 instructions]
 * Source: src/boot/register_native_current_task_as_boot_input_owner.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: XYCZNV.
 */
static void register_native_current_task_as_boot_input_owner(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a >> 8 << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA4CF, 0x7EACE9); GUARD_JSR(c, sp_call, 0xA4CF); } /* current_task_id */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (db_ret << 0x10) + 0x97, (uint8_t)a_all);
        uint8_t value = RAM8(0x0000 + sp0 - 3);
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->c = value2 & 0x01;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->db = value;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x97, a_all);
        uint8_t value5 = RAM8(0x0000 + sp0 - 3);
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->c = value6 & 0x01;
        r->z = ((value8 << 8) | value7) == 0;
        r->n = ((value8 << 8) | value7) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->db = value5;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EA4C2, SOM_RTS, "gen", register_native_current_task_as_boot_input_owner, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 21, 14)
