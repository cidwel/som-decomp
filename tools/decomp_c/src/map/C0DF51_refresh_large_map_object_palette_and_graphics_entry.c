#include "som_c.h"

/* C0DF51 refresh_large_map_object_palette_and_graphics_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_large_map_object_palette_and_graphics_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void refresh_large_map_object_palette_and_graphics_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xDF53, 0xC0DF48); GUARD_JSR(c, sp_call, 0xDF53); } /* external */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0DF51, SOM_RTL, "hand", refresh_large_map_object_palette_and_graphics_entry, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
