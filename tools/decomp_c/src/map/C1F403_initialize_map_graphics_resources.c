#include "som_c.h"

/* C1F403 initialize_map_graphics_resources   [class B, 16 bytes, 6 instructions]
 * Source: src/rom/initialize_map_graphics_resources.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_graphics_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xF405, 0xC1F5CE); /* upload_map_scroll_graphics_templates */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xF408, 0xC1F62D); /* prepare_map_resource_palette */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xF40B, 0xC1F69B); /* initialize_map_fixed_graphics */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF40E, 0xC1F702); /* upload_map_mirrored_pattern_tiles */
    r->mf = 0;
    r->xf = 1;
    JSR(c, 0xF411, 0xC1F413); /* upload_map_graphics_descriptor_list */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1F403, SOM_RTL, "gen", initialize_map_graphics_resources, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 16, 6)
