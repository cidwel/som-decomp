#include "som_c.h"

/* C0E351 initialize_sprite_workspace_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_sprite_workspace_long.s
 * Documented in docs/actor-cast-sprite-publication.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void initialize_sprite_workspace_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE353, 0xC0E355); /* initialize_map_sprite_workspace */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E351, SOM_RTL, "gen", initialize_sprite_workspace_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 4, 2)
