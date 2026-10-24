#include "som_c.h"

/* C0FD1F tail_dispatch_ordinary_enemy_animation_step   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/tail_dispatch_ordinary_enemy_animation_step.s
 * Documented in docs/actor-enemy-group-workers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void tail_dispatch_ordinary_enemy_animation_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0F4CB, SOM_RTS); /* advance_actor_animation_and_resume_native_frame_stream */
}
SOM_REGISTER(0xC0FD1F, SOM_RTS, "gen", tail_dispatch_ordinary_enemy_animation_step, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
