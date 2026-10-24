#include "som_c.h"

/* C0382D secondary_cast_queue_initializer_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/secondary_cast_queue_initializer_jump.s
 * Documented in docs/boss-public-initialize.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void secondary_cast_queue_initializer_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC038CE, SOM_RTL); /* clear_cast_queues_and_seed_fifteen_byte_random_pool */
}
SOM_REGISTER(0xC0382D, SOM_RTL, "gen", secondary_cast_queue_initializer_jump, 0, L_X | L_Y, 1, 0, 0, 3, 1)
