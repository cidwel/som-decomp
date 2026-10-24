#include "som_c.h"

/* C18009 graphics_planes_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/graphics_planes_public_jump.s
 * Documented in docs/actor-cast-entity-graphics-audio.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: Y.
 */
static void graphics_planes_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    TAIL_CALL(c, 0xC1C583, SOM_RTL); /* dispatch_explicit_graphics_plane_conversion */
}
SOM_REGISTER(0xC18009, SOM_RTL, "gen", graphics_planes_public_jump, 0, L_Y, 1, 1, 0, 3, 1)
