#include "som_c.h"

/* 7E8363 release_auxiliary_graphics_buffers   [class A, 27 bytes, 16 instructions]
 * Source: src/boot/release_auxiliary_graphics_buffers.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: BYCZNV.
 */
static void release_auxiliary_graphics_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x10018);
    r->a = (a_hi << 8) | 0x7F;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8373, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x8373); } /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x1A);
        r->x = value2;
        r->y = (uint8_t)y;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8379, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x8379); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 4;
        uint8_t value3 = RAM8(0x0000 + sp0 - 3);
        uint8_t value4 = RAM8(0x0000 + sp0 - 2);
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->c = value4 & 0x01;
        r->z = ((value6 << 8) | value5) == 0;
        r->n = ((value6 << 8) | value5) & 0x8000;
        r->v = value4 & 0x40;
        r->mf = value4 & 0x20;
        r->xf = value4 & 0x10;
        r->db = value3;
        r->dp = (value6 << 8) | value5;
        r->i = value4 & 0x04;
        r->d = value4 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x1A);
        r->x = value7;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8379, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x8379); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 4;
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        r->c = value9 & 0x01;
        r->z = ((value11 << 8) | value10) == 0;
        r->n = ((value11 << 8) | value10) & 0x8000;
        r->v = value9 & 0x40;
        r->mf = value9 & 0x20;
        r->xf = value9 & 0x10;
        r->db = value8;
        r->dp = (value11 << 8) | value10;
        r->i = value9 & 0x04;
        r->d = value9 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E8363, SOM_RTS, "gen", release_auxiliary_graphics_buffers, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 27, 16)
