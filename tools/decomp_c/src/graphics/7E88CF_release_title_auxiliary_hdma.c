#include "som_c.h"

/* 7E88CF release_title_auxiliary_hdma   [class A, 24 bytes, 14 instructions]
 * Source: src/boot/release_title_auxiliary_hdma.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BYCV.
 */
static void release_title_auxiliary_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
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
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint16_t value = BUS16(c, 0x7F0002 + x);
    r->x = value;
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88DC, 0x7E9066); GUARD_JSR(c, sp_call, 0x88DC); } /* release_transfer_descriptor */
    r->sp += 5;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value7 = RAM8(0x0000 + sp0 - 4);
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint16_t value9 = BUS16_RDP(c, (db_ret << 0x10) + ((value8 << 8) | value7));
        r->x = value9;
        r->y = (value8 << 8) | value7;
        r->z = value9 == 0;
        r->n = value9 & 0x8000;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0x88E3, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x88E3); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 3;
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->c = value10 & 0x01;
        r->v = value10 & 0x40;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E88CF, SOM_RTS, "gen", release_title_auxiliary_hdma, 0, L_B | L_Y | L_C | L_V, 5, 1, 0, 24, 14)
