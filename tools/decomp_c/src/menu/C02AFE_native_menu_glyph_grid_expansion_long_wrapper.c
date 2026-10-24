#include "som_c.h"

/* C02AFE native_menu_glyph_grid_expansion_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/native_menu_glyph_grid_expansion_long_wrapper.s
 * Documented in docs/event-menu-shop-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void native_menu_glyph_grid_expansion_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2B00, 0xC02169); /* expand_native_menu_glyph_grid_to_two_bitplanes */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AFE, SOM_RTL, "gen", native_menu_glyph_grid_expansion_long_wrapper, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
