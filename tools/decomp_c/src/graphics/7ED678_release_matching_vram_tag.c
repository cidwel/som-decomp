#include "som_c.h"

/* 7ED678 release_matching_vram_tag   [class B, 59 bytes, 37 instructions]
 * Source: src/boot/release_matching_vram_tag.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BY.
 */
static void release_matching_vram_tag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint16_t value = RAM16(0x1032C);
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = 0x20;
    uint8_t value2 = RAM8(0x10000 + (uint16_t)((a & 0xFF) + value));
    uint16_t x1 = RAM16(0x1032C);
    do {
        if (value2 == RAM8(0x10000 + x1)) {
            RAM8(0x10000 + x1) = 0;
        }
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1))--;
        x1 = (uint16_t)(x1 + 1);
    } while (RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) != 0);
    r->a = ((uint16_t)((a & 0xFF) + value) >> 8 << 8) | RAM8(0x0000 + sp0 - 3);
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED678, SOM_RTS, "gen", release_matching_vram_tag, 0, L_B | L_Y, 7, 0, 0, 59, 37)
