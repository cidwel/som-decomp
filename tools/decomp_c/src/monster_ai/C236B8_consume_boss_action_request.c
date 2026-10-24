#include "som_c.h"

/* C236B8 consume_boss_action_request   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/consume_boss_action_request.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void consume_boss_action_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x36BA, 0xC2051C); /* consume_boss_byte35_request */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC236B8, SOM_RTS, "gen", consume_boss_action_request, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
