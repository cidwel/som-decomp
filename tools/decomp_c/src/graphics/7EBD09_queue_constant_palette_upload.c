#include "som_c.h"

/* 7EBD09 queue_constant_palette_upload   [class B, 70 bytes, 41 instructions]
 * Source: src/boot/queue_constant_palette_upload.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void queue_constant_palette_upload(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->a = 2;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBD20, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xBD20); } /* allocate_transfer_descriptor */
    r->sp += 6;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret2 = r->x;
    BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret2, 0x20);
    BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret2, 0xBCE9);
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
    uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x02D2);
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((uint16_t)(value - value2) >> 1);
    BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret2, (uint8_t)((uint16_t)(value - value2) >> 1));
    BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret2, 0x7E);
    r->a = ((uint16_t)(value - value2) >> 1 >> 8 << 8) | 0x7E;
    r->c = (uint16_t)(value - value2) & 0x01;
    r->z = 0;
    r->n = 0;
    r->v = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    r->mf = 1;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBD41, 0x7E90DA); GUARD_JSR(c, sp_call, 0xBD41); } /* submit_transfer_or_program_hdma */
    r->sp += 7;
    bool m_ret = r->mf;
    uint16_t a_all2 = r->a;
    if (m_ret) {
        uint8_t value3 = RAM8(0x0000 + sp0 - 6);
        uint8_t value4 = RAM8(0x0000 + sp0 - 5);
        RAM8(0x0000 + sp0 - 3) = value3 >> 4;
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        r->a = (a_all2 >> 8 << 8) | value6;
        r->c = value7 & 0x01;
        r->z = ((value9 << 8) | value8) == 0;
        r->n = ((value9 << 8) | value8) & 0x8000;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = value4;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
}
SOM_REGISTER(0x7EBD09, SOM_RTS, "gen", queue_constant_palette_upload, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 70, 41)
