#include "som_c.h"

/* 7E81AA release_graphics_buffer   [class B, 44 bytes, 26 instructions]
 * Source: src/boot/release_graphics_buffer.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: YCV.
 */
static void release_graphics_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    r->z = a == 0;
    r->n = a & 0x80;
    r->mf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x81BB, 0x7E805F); GUARD_JSR(c, sp_call, 0x81BB); } /* select_graphics_registration */
    r->sp += 4;
    uint16_t a_all = r->a;
    uint16_t value = BUS16(c, 0x7F0006 + a_all);
    BUS16_SET(c, 0x7F0006 + a_all, 0);
    uint16_t value2 = BUS16(c, 0x7F0000 + a_all);
    BUS16_SET(c, 0x7F0000 + a_all, 0);
    RAM8(0x0000 + sp0 - 4) = value2 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)value2;
    r->a = value2;
    r->x = value;
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x81CD, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x81CD); } /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 6;
    bool m_ret = r->mf;
    if (m_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value8 = RAM8(0x0000 + sp0 - 5);
        uint8_t value9 = RAM8(0x0000 + sp0 - 4);
        r->a = (value9 << 8) | value8;
        r->z = ((value9 << 8) | value8) == 0;
        r->n = ((value9 << 8) | value8) & 0x8000;
        r->mf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x81D1, 0x7ED678); GUARD_JSR(c, sp_call, 0x81D1); } /* release_matching_vram_tag */
        r->sp += 4;
        uint8_t value10 = RAM8(0x0000 + sp0 - 3);
        uint8_t value11 = RAM8(0x0000 + sp0 - 2);
        uint8_t value12 = RAM8(0x0000 + sp0 - 1);
        uint8_t value13 = RAM8(0x0000 + sp0);
        r->c = value11 & 0x01;
        r->v = value11 & 0x40;
        r->mf = value11 & 0x20;
        r->xf = value11 & 0x10;
        r->db = value10;
        r->dp = (value13 << 8) | value12;
        r->i = value11 & 0x04;
        r->d = value11 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E81AA, SOM_RTS, "gen", release_graphics_buffer, 0, L_Y | L_C | L_V, 6, 1, 0, 44, 26)
