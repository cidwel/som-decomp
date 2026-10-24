#include "som_c.h"

/* 7EBE1F copy_native_palette_words_to_backup_half   [class A, 29 bytes, 19 instructions]
 * Source: src/boot/copy_native_palette_words_to_backup_half.s
 * Documented in docs/source-recovery-parallel-palette-apis.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0000.  Callers read: ABXYCZNV.
 */
static void copy_native_palette_words_to_backup_half(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
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
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = 0x20;
    r->y = (uint16_t)(x + 0x0200);
    r->c = x + 0x0200 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((x ^ (uint16_t)(x + 0x0200)) & ((uint16_t)(x + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBE37, 0x7EC3BF); GUARD_JSR(c, sp_call, 0xBE37); } /* copy_native_same_bank_memory_through_stack_generated_mvn */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
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
}
SOM_REGISTER(0x7EBE1F, SOM_RTS, "gen", copy_native_palette_words_to_backup_half, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 29, 19)
