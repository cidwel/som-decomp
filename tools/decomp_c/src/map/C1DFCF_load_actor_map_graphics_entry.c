#include "som_c.h"

/* C1DFCF load_actor_map_graphics_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/load_actor_map_graphics_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void load_actor_map_graphics_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xDFD1, 0xC1DFD3); /* load_actor_map_graphics */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1DFCF, SOM_RTL, "gen", load_actor_map_graphics_entry, 0, L_X | L_Y, 1, 1, 0, 4, 2)
