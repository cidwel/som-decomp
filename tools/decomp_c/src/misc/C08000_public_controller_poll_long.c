#include "som_c.h"

/* C08000 public_controller_poll_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/public_controller_poll_long.s
 * Documented in docs/game-controller-poll.md
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCV.
 */
static void public_controller_poll_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x8002, 0xC0939F); /* poll_controllers_preserving_native_context */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC08000, SOM_RTL, "gen", public_controller_poll_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 4, 2)
