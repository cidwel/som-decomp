#include "som_c.h"

/* C1F8E5 prepare_scene_palette_templates_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/prepare_scene_palette_templates_long.s
 * Documented in docs/ui-native-music-palette-transition.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void prepare_scene_palette_templates_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xF8E7, 0xC1F8E9); /* copy_scene_palette_templates_and_refresh_special_palette_rows */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1F8E5, SOM_RTL, "gen", prepare_scene_palette_templates_long, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 4, 2)
