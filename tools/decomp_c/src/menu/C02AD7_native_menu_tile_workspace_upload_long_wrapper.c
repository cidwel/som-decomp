#include "som_c.h"

/* C02AD7 native_menu_tile_workspace_upload_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/native_menu_tile_workspace_upload_long_wrapper.s
 * Documented in docs/ui-native-personality-page.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void native_menu_tile_workspace_upload_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AD9, 0xC025AD); /* upload_complete_native_menu_tile_workspace */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AD7, SOM_RTL, "gen", native_menu_tile_workspace_upload_long_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, -1, 0, 4, 2)
