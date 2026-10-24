#include "som_c.h"

/* 7EACAC request_task_stop_by_id   [class A, 36 bytes, 23 instructions]
 * Source: src/boot/request_task_stop_by_id.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void request_task_stop_by_id(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = ((((a >> 7 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((a == 0) << 1) | carry;
    r->z = a == 0;
    r->n = a & 0x80;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xACBD, 0x7EAD02); GUARD_JSR(c, sp_call, 0xACBD); } /* find_task_by_id */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (x_ret == 0) {
        m_flag = m_ret;
        x_flag = 0;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        r->c = x_ret >= 0;
        r->z = x_ret == 0;
        r->n = x_ret & 0x8000;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xACC5, 0x7EAC69); GUARD_JSR(c, sp_call, 0xACC5); } /* wake_waiting_task */
        r->sp += 5;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret2 = r->y;
        BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret3, 0x10);
        m_flag = 1;
        x_flag = x_ret2;
        a1 = 0x10;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret3;
        y1 = y_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    uint8_t value = RAM8(0x0000 + sp0 - 4);
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1 & 0xFFFF - ((value >> 4) & 1) * 0xFF00;
    r->y = y1 & 0xFFFF - ((value >> 4) & 1) * 0xFF00;
    r->c = value3 & 0x01;
    r->z = ((value5 << 8) | value4) == 0;
    r->n = ((value5 << 8) | value4) & 0x8000;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->db = value2;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EACAC, SOM_RTS, "gen", request_task_stop_by_id, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 36, 23)
