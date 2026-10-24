#include "som_c.h"

/* C00039 initialize_hero_record_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/initialize_hero_record_public_jump.s
 * Documented in docs/actor-hero-initialize.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void initialize_hero_record_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03821, SOM_RTL); /* initialize_hero_record_public_jump_mirror */
}
SOM_REGISTER(0xC00039, SOM_RTL, "gen", initialize_hero_record_public_jump, 0, L_B, 1, 1, 0, 3, 1)
