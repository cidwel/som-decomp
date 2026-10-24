#include "som_c.h"

/* C02ACF clear_native_menu_sprite_tables_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/clear_native_menu_sprite_tables_long_wrapper.s
 * Documented in docs/ui-native-name-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void clear_native_menu_sprite_tables_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AD1, 0xC01F36); /* clear_native_menu_sprite_and_high_oam_tables */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02ACF, SOM_RTL, "gen", clear_native_menu_sprite_tables_long_wrapper, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 4, 2)
