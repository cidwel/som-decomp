#include "som_c.h"

/* 7EB1A9 allocate_eight_byte_record   [class B, 52 bytes, 31 instructions]
 * Source: src/boot/allocate_eight_byte_record.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void allocate_eight_byte_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = ((overflow << 6) | (d_entry << 3)) | (i_entry << 2) | carry;
    uint16_t value = RAM16(0x102C6);
    uint16_t value2 = BUS16(c, 0x7F0000 + value);
    RAM16_SET(0x102C6, value2);
    BUS16_SET(c, 0x7F0000 + value, 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value);
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->i = 1;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB1CB, 0x7EACE9); GUARD_JSR(c, sp_call, 0xB1CB); } /* current_task_id */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        if (m_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 2 + value3, (uint8_t)a_all);
            BUS8_SET(c, (db_ret << 0x10) + 3 + value3, 0);
            uint8_t value4 = RAM8(0x0000 + sp0 - 6);
            uint8_t value5 = RAM8(0x0000 + sp0 - 5);
            uint8_t value8 = RAM8(0x0000 + sp0 - 2);
            uint8_t value9 = RAM8(0x0000 + sp0 - 1);
            uint8_t value10 = RAM8(0x0000 + sp0);
            r->x = value3 & 0xFFFF - ((value4 >> 4) & 1) * 0xFF00;
            r->y = (uint8_t)y & 0xFFFF - ((value4 >> 4) & 1) * 0xFF00;
            r->c = value8 & 0x01;
            r->v = value8 & 0x40;
            r->mf = value8 & 0x20;
            r->xf = value8 & 0x10;
            r->db = value5;
            r->dp = (value10 << 8) | value9;
            r->i = value8 & 0x04;
            r->d = value8 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 2 + value3, a_all);
            BUS16_SET(c, (db_ret << 0x10) + 3 + value3, 0);
            uint8_t value11 = RAM8(0x0000 + sp0 - 6);
            uint8_t value12 = RAM8(0x0000 + sp0 - 5);
            uint8_t value15 = RAM8(0x0000 + sp0 - 2);
            uint8_t value16 = RAM8(0x0000 + sp0 - 1);
            uint8_t value17 = RAM8(0x0000 + sp0);
            r->x = value3 & 0xFFFF - ((value11 >> 4) & 1) * 0xFF00;
            r->y = (uint8_t)y & 0xFFFF - ((value11 >> 4) & 1) * 0xFF00;
            r->c = value15 & 0x01;
            r->v = value15 & 0x40;
            r->mf = value15 & 0x20;
            r->xf = value15 & 0x10;
            r->db = value12;
            r->dp = (value17 << 8) | value16;
            r->i = value15 & 0x04;
            r->d = value15 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        if (m_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 2 + value18, (uint8_t)a_all);
            BUS8_SET(c, (db_ret << 0x10) + 3 + value18, 0);
            uint8_t value19 = RAM8(0x0000 + sp0 - 6);
            uint8_t value20 = RAM8(0x0000 + sp0 - 5);
            uint8_t value23 = RAM8(0x0000 + sp0 - 2);
            uint8_t value24 = RAM8(0x0000 + sp0 - 1);
            uint8_t value25 = RAM8(0x0000 + sp0);
            r->x = value18 & 0xFFFF - ((value19 >> 4) & 1) * 0xFF00;
            r->y = y & 0xFFFF - ((value19 >> 4) & 1) * 0xFF00;
            r->c = value23 & 0x01;
            r->v = value23 & 0x40;
            r->mf = value23 & 0x20;
            r->xf = value23 & 0x10;
            r->db = value20;
            r->dp = (value25 << 8) | value24;
            r->i = value23 & 0x04;
            r->d = value23 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 2 + value18, a_all);
            BUS16_SET(c, (db_ret << 0x10) + 3 + value18, 0);
            uint8_t value26 = RAM8(0x0000 + sp0 - 6);
            uint8_t value27 = RAM8(0x0000 + sp0 - 5);
            uint8_t value30 = RAM8(0x0000 + sp0 - 2);
            uint8_t value31 = RAM8(0x0000 + sp0 - 1);
            uint8_t value32 = RAM8(0x0000 + sp0);
            r->x = value18 & 0xFFFF - ((value26 >> 4) & 1) * 0xFF00;
            r->y = y & 0xFFFF - ((value26 >> 4) & 1) * 0xFF00;
            r->c = value30 & 0x01;
            r->v = value30 & 0x40;
            r->mf = value30 & 0x20;
            r->xf = value30 & 0x10;
            r->db = value27;
            r->dp = (value32 << 8) | value31;
            r->i = value30 & 0x04;
            r->d = value30 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EB1A9, SOM_RTS, "gen", allocate_eight_byte_record, 0, L_B | L_X | L_Y | L_C | L_V, 7, -1, 0, 52, 31)
