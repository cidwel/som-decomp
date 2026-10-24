#include "som_c.h"

/* 7EC8C8 initialize_copy_queue_pool   [class B, 77 bytes, 41 instructions]
 * Source: src/boot/initialize_copy_queue_pool.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: YCV.
 */
static void initialize_copy_queue_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x7F;
    r->x = 0x0100;
    r->z = 0;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC8DD, 0x7EB081); GUARD_JSR(c, sp_call, 0xC8DD); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 6;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    BUS16_SET(c, (db_ret << 0x10) + 0x02F6, x_ret);
    BUS16_SET(c, (db_ret << 0x10) + 0x02F8, (uint16_t)(x_ret + 8));
    uint8_t a1 = (uint8_t)(x_ret + 8);
    uint8_t a_hi1 = (uint16_t)(x_ret + 8) >> 8;
    uint16_t x1 = (uint16_t)(x_ret + 8);
    uint16_t y1 = 0x1E;
    for (;;) {
        BUS16_SET(c, (db_ret << 0x10) + x1, (uint16_t)(((a_hi1 << 8) | a1) + 8));
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 8);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 8) >> 8;
        uint16_t x1_next = (uint16_t)(((a_hi1 << 8) | a1) + 8);
        uint16_t y1_next = (uint16_t)(y1 - 1);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 != 0)) break;
    }
    BUS16_SET(c, (db_ret << 0x10) + x1, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02FE, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0300, 0x02FE);
    BUS16_SET(c, (db_ret << 0x10) + 0x02FA, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02FC, 0x02FA);
    uint8_t value = RAM8(0x0000 + sp0 - 5);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->y = y1;
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC8C8, SOM_RTS, "gen", initialize_copy_queue_pool, 0, L_Y | L_C | L_V, 7, 0, 0, 77, 41)
