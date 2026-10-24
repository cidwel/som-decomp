#include "som_c.h"

/* C1E01E load_actor_map_palette_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/load_actor_map_palette_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_actor_map_palette_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE020, 0xC1E022); /* load_actor_map_palette */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E01E, SOM_RTL, "gen", load_actor_map_palette_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
