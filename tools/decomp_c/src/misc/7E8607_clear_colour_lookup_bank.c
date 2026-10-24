#include "som_c.h"

/* 7E8607 clear_colour_lookup_bank   [class A, 26 bytes, 16 instructions]
 * Source: src/boot/clear_colour_lookup_bank.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void clear_colour_lookup_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a_hi << 8) | 0;
    r->x = 0x8000;
    r->y = 0x8000;
    r->z = 0;
    r->n = 1;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x861C, 0x7EC37D); GUARD_JSR(c, sp_call, 0x861C); } /* fill_native_boot_memory_using_words_or_forward_copy */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8607, SOM_RTS, "gen", clear_colour_lookup_bank, 0, 0, 5, 1, 0, 26, 16)
