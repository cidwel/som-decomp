#include "som_c.h"

/* C10018 jump_to_warm_boot   [class A, 4 bytes, 1 instructions]
 * Source: src/rom/jump_to_warm_boot.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void jump_to_warm_boot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC14CFA, SOM_RTS); /* start_warm_boot_program */
}
SOM_REGISTER(0xC10018, SOM_RTS, "gen", jump_to_warm_boot, 0, 0, 1, 1, 1, 4, 1)
