#include "som_c.h"

/* C8E5FB select_actor_status_attack_row_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/select_actor_status_attack_row_long.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void select_actor_status_attack_row_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xE5FD, 0xC8E5FF); GUARD_JSR(c, sp_call, 0xE5FD); } /* select_actor_status_attack_row */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC8E5FB, SOM_RTL, "hand", select_actor_status_attack_row_long, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
