#include "som_c.h"

/* C10028 execute_actor_program_step_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/execute_actor_program_step_long.s
 * Documented in docs/actor-program-step-long.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void execute_actor_program_step_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x002A, 0xC12552); /* execute_actor_program_step */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10028, SOM_RTL, "gen", execute_actor_program_step_long, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
