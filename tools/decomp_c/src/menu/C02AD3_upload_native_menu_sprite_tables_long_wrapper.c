#include "som_c.h"

/* C02AD3 upload_native_menu_sprite_tables_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/upload_native_menu_sprite_tables_long_wrapper.s
 * Documented in docs/ui-native-name-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void upload_native_menu_sprite_tables_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AD5, 0xC01F5B); /* upload_complete_native_menu_oam_table */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AD3, SOM_RTL, "gen", upload_native_menu_sprite_tables_long_wrapper, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
