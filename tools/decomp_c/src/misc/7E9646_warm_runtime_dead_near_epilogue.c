#include "som_c.h"
#include "som_hand.h"

/* 7E9646 warm_runtime_dead_near_epilogue   [class C, 5 bytes, 5 instructions]
 * Source: src/boot/source_recovery_parallel_boot_static_fragments_warm_runtime_dead_near_epilogue.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void warm_runtime_dead_near_epilogue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp + 7;
    uint8_t value3 = RAM8(0x0000 + sp0 - 4);
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (value4 << 8) | value3;
    som_pull_p(c, sp0 - 2); /* PLP */
    r->z = ((value7 << 8) | value6) == 0; /* PLD */
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->dp = (value7 << 8) | value6;
    r->sp += 7;
    /* The RTS pops an address from the forged frame and returns to the caller's caller.  The original is not followed
     * further: the capture window ends at this unwinding RTS (core option unwind=7). */
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9646, SOM_RTS, "hand", warm_runtime_dead_near_epilogue, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 0, 0, 5, 5)
