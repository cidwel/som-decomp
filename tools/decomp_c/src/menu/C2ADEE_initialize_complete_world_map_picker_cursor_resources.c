#include "som_c.h"

/* C2ADEE initialize_complete_world_map_picker_cursor_resources   [class D, 47 bytes, 18 instructions]
 * Source: src/rom/initialize_complete_world_map_picker_cursor_resources.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void initialize_complete_world_map_picker_cursor_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0x7E);
    r->x = 0;
    JSR(c, 0xAE01, 0xC2AE1D); /* upload_cursor_tile_low_planes_and_clear_remainder */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE04, 0xC2AE1D); /* upload_cursor_tile_low_planes_and_clear_remainder */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE07, 0xC2AE39); /* upload_cursor_tile_high_planes_and_clear_remainder */
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0x7F);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE12, 0xC2AE1D); /* upload_cursor_tile_low_planes_and_clear_remainder */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE15, 0xC2AE1D); /* upload_cursor_tile_low_planes_and_clear_remainder */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE18, 0xC2AE55); /* initialize_complete_picker_cursor_object_buffer */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xAE1B, 0xC2AEA5); /* upload_complete_picker_cursor_object_buffer */
    r->mf = 1;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2ADEE, SOM_RTL, "gen", initialize_complete_world_map_picker_cursor_resources, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 47, 18)
