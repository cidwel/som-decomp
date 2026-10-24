#include "som_c.h"

/* C20018 public_first_three_boss_animation_control_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_first_three_boss_animation_control_jump.s
 * Documented in docs/boss-public-party-services.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void public_first_three_boss_animation_control_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC20396, SOM_RTL); /* notify_control40_bosses_with_animation57_through7F */
}
SOM_REGISTER(0xC20018, SOM_RTL, "gen", public_first_three_boss_animation_control_jump, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 3, 1)
