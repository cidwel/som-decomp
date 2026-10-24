#include "som_c.h"

/* 7ECBDC clear_registrations_by_task   [class B, 58 bytes, 39 instructions]
 * Source: src/boot/clear_registrations_by_task.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BCV.
 */
static void clear_registrations_by_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)((uint16_t)(sp0 - 5) + 1) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)a;
    uint16_t value = RAM16(0x10302);
    RAM8(0x0000 + sp0 - 5) = ((((value >> 0x0F << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((value == 0) << 1) | carry;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = value;
    uint16_t y1 = 0x20;
    for (;;) {
        uint8_t value2 = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
        uint8_t value3 = BUS8(c, 0x7F0001 + x1);
        if (value2 == value3) {
            RAM8(0x10000 + x1) = 0;
        }
        uint8_t a_hi1_next = (uint16_t)(x1 + 4) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 4);
        uint16_t y1_next = (uint16_t)(y1 - 1);
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 != 0)) break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 5);
    uint8_t value5 = RAM8(0x0000 + sp0 - 4);
    if (value4 & 0x20) {
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | value6;
        r->c = value7 & 0x01;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = value5;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
}
SOM_REGISTER(0x7ECBDC, SOM_RTS, "gen", clear_registrations_by_task, 0, L_B | L_C | L_V, 7, 0, 0, 58, 39)
