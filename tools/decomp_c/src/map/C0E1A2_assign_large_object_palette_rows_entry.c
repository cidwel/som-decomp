#include "som_c.h"

/* C0E1A2 assign_large_object_palette_rows_entry   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/assign_large_object_palette_rows_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void assign_large_object_palette_rows_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->mf = 0;
    JSR(c, 0xE1A6, 0xC0E2A8); /* assign_large_object_palette_rows */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E1A2, SOM_RTL, "gen", assign_large_object_palette_rows_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 6, 3)
