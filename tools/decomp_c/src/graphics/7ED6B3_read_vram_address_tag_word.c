#include "som_c.h"

/* 7ED6B3 read_vram_address_tag_word   [class A, 32 bytes, 22 instructions]
 * Source: src/boot/read_vram_address_tag_word.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$05AB.  Callers read: ABYCZNV.
 */
static void read_vram_address_tag_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05AB) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xAB;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value2 = BUS16(c, 0x7F0000 + (uint16_t)(((((uint8_t)(x & 0xFC00) << 8) | ((x & 0xFC00) >> 8)) >> 2) + RAM16(0x1032C)));
    r->a = value2;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED6B3, SOM_RTS, "gen", read_vram_address_tag_word, 0, L_A | L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 32, 22)
