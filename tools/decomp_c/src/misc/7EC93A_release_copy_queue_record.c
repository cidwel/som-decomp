#include "som_c.h"

/* 7EC93A release_copy_queue_record   [class A, 32 bytes, 21 instructions]
 * Source: src/boot/release_copy_queue_record.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: XY.
 */
static void release_copy_queue_record(SomCtx *c)
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
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    bool interrupt_disable;
    bool decimal_mode;
    bool m_flag;
    bool x_flag;
    if (x == 0) {
        interrupt_disable = i_entry;
        decimal_mode = d_entry;
        m_flag = 0;
        x_flag = 0;
    } else {
        RAM8(0x0000 + sp0 - 4) = ((((x >> 0x0F << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((x == 0) << 1) | carry;
        BUS16_SET(c, 0x7F0000 + x, RAM16(0x102F8));
        RAM16_SET(0x102F8, x);
        uint8_t value2 = RAM8(0x0000 + sp0 - 4);
        interrupt_disable = value2 & 0x04;
        decimal_mode = value2 & 0x08;
        m_flag = value2 & 0x20;
        x_flag = value2 & 0x10;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC93A, SOM_RTS, "gen", release_copy_queue_record, 0, L_X | L_Y, 5, 0, 0, 32, 21)
