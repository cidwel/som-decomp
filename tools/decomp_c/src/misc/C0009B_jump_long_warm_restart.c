#include "som_c.h"

/* C0009B jump_long_warm_restart   [class A, 4 bytes, 1 instructions]
 * Source: src/rom/jump_long_warm_restart.s
 * Documented in docs/event-party-warm-aliases.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void jump_long_warm_restart(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC10018, SOM_RTS); /* jump_to_warm_boot */
}
SOM_REGISTER(0xC0009B, SOM_RTS, "gen", jump_long_warm_restart, 0, 0, 1, 1, 1, 4, 1)
