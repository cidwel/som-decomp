#include "som_c.h"

/* 7E833E allocate_auxiliary_graphics_buffers   [class A, 37 bytes, 20 instructions]
 * Source: src/boot/allocate_auxiliary_graphics_buffers.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$05F1.  Callers read: YCZNV.
 */
static void allocate_auxiliary_graphics_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a_hi << 8) | 0;
    r->x = 0x34;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8350, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x8350); } /* allocate_and_fill_bytes */
    r->sp += 4;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x10018, x_ret);
    r->a = (a_all >> 8 << 8) | 0;
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x835B, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x835B); } /* allocate_and_fill_bytes */
    r->sp += 4;
    bool x_ret2 = r->xf;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    if (x_ret2) {
        RAM8(0x1001A) = (uint8_t)x_ret3;
        uint8_t value = RAM8(0x0000 + sp0 - 3);
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->y = (uint8_t)y_ret2;
        r->c = value2 & 0x01;
        r->z = ((value4 << 8) | value3) == 0;
        r->n = ((value4 << 8) | value3) & 0x8000;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->db = value;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        RAM16_SET(0x1001A, x_ret3);
        uint8_t value5 = RAM8(0x0000 + sp0 - 3);
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->c = value6 & 0x01;
        r->z = ((value8 << 8) | value7) == 0;
        r->n = ((value8 << 8) | value7) & 0x8000;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->db = value5;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E833E, SOM_RTS, "gen", allocate_auxiliary_graphics_buffers, 0, L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 37, 20)
