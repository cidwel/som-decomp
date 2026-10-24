#include "som_c.h"

/* C20A3F return_no_target_query_result_a   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/return_no_target_query_result_a.s
 * Documented in docs/boss-target-status-queries.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void return_no_target_query_result_a(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    r->a = 0xFFFF;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20A3F, SOM_RTS, "gen", return_no_target_query_result_a, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
