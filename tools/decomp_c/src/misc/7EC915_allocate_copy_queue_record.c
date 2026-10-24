#include "som_c.h"

/* 7EC915 allocate_copy_queue_record   [class A, 37 bytes, 22 instructions]
 * Source: src/boot/allocate_copy_queue_record.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02D9.  Callers read: XCV.
 */
static void allocate_copy_queue_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02D9) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xD9;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x102F8);
    bool interrupt_disable;
    bool decimal_mode;
    bool m_flag;
    bool x_flag;
    if (value == 0) {
        interrupt_disable = i_entry;
        decimal_mode = d_entry;
        m_flag = 0;
        x_flag = 0;
    } else {
        RAM8(0x0000 + sp0 - 4) = ((((value >> 0x0F << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((value == 0) << 1) | carry;
        uint16_t value2 = BUS16(c, 0x7F0000 + value);
        RAM16_SET(0x102F8, value2);
        BUS16_SET(c, 0x7F0003 + value, 0x7F);
        uint8_t value3 = RAM8(0x0000 + sp0 - 4);
        interrupt_disable = value3 & 0x04;
        decimal_mode = value3 & 0x08;
        m_flag = value3 & 0x20;
        x_flag = value3 & 0x10;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->x = value;
    r->c = value5 & 0x01;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value4;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC915, SOM_RTS, "gen", allocate_copy_queue_record, 0, L_X | L_C | L_V, 5, 1, 0, 37, 22)
