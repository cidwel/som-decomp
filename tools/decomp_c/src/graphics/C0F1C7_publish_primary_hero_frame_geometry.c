#include "som_c.h"

/* C0F1C7 publish_primary_hero_frame_geometry   [class A, 8 bytes, 3 instructions]
 * Source: src/rom/publish_primary_hero_frame_geometry.s
 * Documented in docs/actor-visual-frame-geometry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void publish_primary_hero_frame_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->x = 0;
    r->mf = 0;
    TAIL_CALL(c, 0xC0F1CF, SOM_RTS); /* publish_actor_frame_tiles_points_and_collision_rectangle */
}
SOM_REGISTER(0xC0F1C7, SOM_RTS, "gen", publish_primary_hero_frame_geometry, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 8, 3)
