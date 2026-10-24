#include "som_c.h"

/* C0EB02 decode_actor_frame_tiles_and_geometry_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/decode_actor_frame_tiles_and_geometry_long.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BY.
 */
static void decode_actor_frame_tiles_and_geometry_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xEB04, 0xC0F645); /* external */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0EB02, SOM_RTL, "gen", decode_actor_frame_tiles_and_geometry_long, 0, L_B | L_Y, 1, 0, 0, 4, 2)
