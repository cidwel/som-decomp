#include "som_c.h"

/* C10010 jump_to_cold_boot   [class A, 4 bytes, 1 instructions]
 * Source: src/rom/jump_to_cold_boot.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void jump_to_cold_boot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC14CE5, SOM_RTS); /* start_cold_boot_program */
}
SOM_REGISTER(0xC10010, SOM_RTS, "gen", jump_to_cold_boot, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 4, 1)
