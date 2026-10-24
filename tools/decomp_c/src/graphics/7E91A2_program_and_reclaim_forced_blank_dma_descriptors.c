#include "som_c.h"

/* 7E91A2 program_and_reclaim_forced_blank_dma_descriptors   [class A, 22 bytes, 11 instructions]
 * Source: src/boot/program_and_reclaim_forced_blank_dma_descriptors.s
 * Documented in docs/boot-title-hdma-resources.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXY.
 */
static void program_and_reclaim_forced_blank_dma_descriptors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x006E, RAM16(0x006C));
    r->a = 0x0107;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91B1, 0x7E91B8); GUARD_JSR(c, sp_call, 0x91B1); } /* program_dma_descriptor_pass */
    r->sp += 3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91B4, 0x7E92E9); GUARD_JSR(c, sp_call, 0x91B4); } /* cleanup_processed_transfers */
    r->sp += 3;
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E91A2, SOM_RTS, "gen", program_and_reclaim_forced_blank_dma_descriptors, 0, L_A | L_B | L_X | L_Y, 3, 1, 0, 22, 11)
