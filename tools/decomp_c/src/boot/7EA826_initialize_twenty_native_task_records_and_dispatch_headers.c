#include "som_c.h"

/* 7EA826 initialize_twenty_native_task_records_and_dispatch_headers   [class B, 84 bytes, 42 instructions]
 * Source: src/boot/initialize_twenty_native_task_records_and_dispatch_headers.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BYCZNV.
 */
static void initialize_twenty_native_task_records_and_dispatch_headers(SomCtx *c)
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
    r->a = 0;
    r->x = 0x0140;
    r->z = 1;
    r->n = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA83E, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xA83E); } /* allocate_and_fill_bytes */
    r->sp += 6;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x1009C, x_ret);
    RAM16_SET(0x100A6, x_ret);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = 0x13;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    for (;;) {
        BUS16_SET(c, 0x7F0000 + x1, (uint16_t)(x1 + 0x10));
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x10);
        uint16_t y1_next = (uint16_t)(y1 - 1);
        bool carry1_next = x1 + 0x10 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 != 0)) break;
    }
    RAM16_SET(0x100A0, 0);
    RAM16_SET(0x100A2, 0);
    RAM16_SET(0x100AA, 0);
    r->a = 0x13;
    r->x = 0xAA;
    r->y = 0xAB;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA868, 0x7EC3BF); GUARD_JSR(c, sp_call, 0xA868); } /* copy_native_same_bank_memory_through_stack_generated_mvn */
    r->sp += 6;
    bool m_ret = r->mf;
    if (m_ret) {
        RAM8(0x1009E) = 0;
        RAM8(0x100A0) = 0;
        RAM8(0x100A2) = 0;
        uint8_t value = RAM8(0x0000 + sp0 - 5);
        uint8_t value4 = RAM8(0x0000 + sp0 - 2);
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->c = value4 & 0x01;
        r->z = ((value6 << 8) | value5) == 0;
        r->n = ((value6 << 8) | value5) & 0x8000;
        r->v = value4 & 0x40;
        r->mf = value4 & 0x20;
        r->xf = value4 & 0x10;
        r->db = value;
        r->dp = (value6 << 8) | value5;
        r->i = value4 & 0x04;
        r->d = value4 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        RAM16_SET(0x1009E, 0);
        RAM16_SET(0x100A0, 0);
        RAM16_SET(0x100A2, 0);
        uint8_t value7 = RAM8(0x0000 + sp0 - 5);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->c = value10 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value10 & 0x40;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->db = value7;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EA826, SOM_RTS, "gen", initialize_twenty_native_task_records_and_dispatch_headers, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 7, 0, 0, 84, 42)
