#include "som_c.h"

/* 7EAAD7 free_task_id_and_record   [class A, 40 bytes, 21 instructions]
 * Source: src/boot/free_task_id_and_record.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BXY.
 */
static void free_task_id_and_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16(c, 0x7F0006 + x);
    RAM8(0x10000 + (uint16_t)((((uint8_t)((uint16_t)(value - 0x0200) & 0xFF00) << 8) | (((uint16_t)(value - 0x0200) & 0xFF00) >> 8)) + 0xAA)) = 0;
    uint16_t value2 = RAM16(0x100A6);
    BUS16_SET(c, 0x7F0000 + x, value2);
    RAM16_SET(0x100A6, x);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = value2;
    r->x = (uint16_t)((((uint8_t)((uint16_t)(value - 0x0200) & 0xFF00) << 8) | (((uint16_t)(value - 0x0200) & 0xFF00) >> 8)) + 0xAA);
    r->y = x;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAAD7, SOM_RTS, "gen", free_task_id_and_record, 0, L_B | L_X | L_Y, 3, 0, 0, 40, 21)
