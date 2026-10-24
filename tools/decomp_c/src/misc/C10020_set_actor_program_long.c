#include "som_c.h"

/* C10020 set_actor_program_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/set_actor_program_long.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void set_actor_program_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x0022, 0xC125B6); /* set_actor_program_and_status_continuation */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10020, SOM_RTL, "gen", set_actor_program_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
