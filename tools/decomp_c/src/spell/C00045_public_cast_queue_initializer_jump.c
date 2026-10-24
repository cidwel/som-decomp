#include "som_c.h"

/* C00045 public_cast_queue_initializer_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_cast_queue_initializer_jump.s
 * Documented in docs/boss-public-initialize.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void public_cast_queue_initializer_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0382D, SOM_RTL); /* secondary_cast_queue_initializer_jump */
}
SOM_REGISTER(0xC00045, SOM_RTL, "gen", public_cast_queue_initializer_jump, 0, L_X | L_Y, 1, 0, 0, 3, 1)
