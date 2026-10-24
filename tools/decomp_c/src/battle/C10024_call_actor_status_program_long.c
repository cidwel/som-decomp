#include "som_c.h"

/* C10024 call_actor_status_program_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/call_actor_status_program_long.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void call_actor_status_program_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x0026, 0xC12698); /* call_actor_status_program */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10024, SOM_RTL, "gen", call_actor_status_program_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
