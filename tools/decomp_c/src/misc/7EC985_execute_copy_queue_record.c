#include "som_c.h"

/* 7EC985 execute_copy_queue_record   [class B, 96 bytes, 52 instructions]
 * Source: src/boot/execute_copy_queue_record.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: YCV.
 */
static void execute_copy_queue_record(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = BUS16(c, 0x7F0004 + x);
    uint8_t a1;
    uint8_t a_hi1;
    if ((value & 0xFF) != 0) {
        a1 = value & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = 0;
        a_hi1 = 1;
    }
    bool x_flag;
    uint16_t y2;
    uint16_t direct_page;
    if (((a_hi1 << 8) | a1) >= 4) {
        RAM8(0x0000 + sp0 - 7) = a_hi1;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)((a_hi1 << 8) | a1);
        uint16_t value2 = BUS16(c, 0x7F0005 + x);
        RAM8(0x0000 + sp0 - 9) = value2 >> 8;
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value2;
        uint8_t value3 = BUS8(c, 0x7F0007 + x);
        RAM8(0x0000 + sp0 - 0x0B) = value3;
        uint16_t value4 = BUS16(c, 0x7F0001 + x);
        RAM8(0x0000 + sp0 - 0x0C) = value4 >> 8;
        RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)value4;
        uint8_t value5 = BUS8(c, 0x7F0003 + x);
        RAM8(0x0000 + sp0 - 0x0E) = value5;
        r->a = (a_hi1 << 8) | value5;
        r->y = value4;
        r->c = ((a_hi1 << 8) | a1) >= 4;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
        r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        r->mf = 1;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC9D3, 0x7EC44E); GUARD_JSR(c, sp_call, 0xC9D3); } /* copy_far_stack_arguments */
        r->sp += 15;
        uint16_t dp_ret = r->dp;
        bool x_ret = r->xf;
        uint16_t y_ret = r->y;
        x_flag = x_ret;
        y2 = y_ret;
        direct_page = dp_ret;
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (a_hi1 << 8) | a1);
        uint16_t value6 = BUS16(c, 0x7F0001 + x);
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), value6);
        uint8_t value7 = BUS8(c, 0x7F0003 + x);
        RAM8(0x0004 + (uint16_t)(sp0 - 7)) = value7;
        uint8_t a_hi2 = value6 >> 8;
        uint16_t x1 = x;
        uint16_t y1 = 0;
        do {
            uint8_t value8 = BUS8(c, 0x7F0005 + x1);
            BUS8_SET(c, (RAM8(0x0004 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0002 + (uint16_t)(sp0 - 7)) + y1, value8);
            RAM8(0x0001 + (uint16_t)(sp0 - 7))--;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 + 1);
        } while (RAM8(0x0001 + (uint16_t)(sp0 - 7)) != 0);
        x_flag = 0;
        y2 = y1;
        direct_page = (uint16_t)(sp0 - 7);
    }
    uint8_t value13 = RAM8(0x0000 + sp0 - 2);
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    r->y = y2;
    r->c = value13 & 0x01;
    r->v = value13 & 0x40;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->dp = (value15 << 8) | value14;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC985, SOM_RTS, "gen", execute_copy_queue_record, 0, L_Y | L_C | L_V, 15, 0, 0, 96, 52)
