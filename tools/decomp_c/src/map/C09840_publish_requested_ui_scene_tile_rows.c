#include "som_c.h"

/* C09840 publish_requested_ui_scene_tile_rows   [class A, 13 bytes, 6 instructions]
 * Source: src/rom/publish_requested_ui_scene_tile_rows.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: AV.
 */
static void publish_requested_ui_scene_tile_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x00EC);
    if (!(value & 0x80)) {
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    r->v = value & 0x40;
    r->mf = 1;
    JSR(c, 0x9848, 0xC0984D); /* publish_pending_ui_scene_tile_column */
    r->mf = 0;
    r->xf = 1;
    TAIL_CALL(c, 0xC09881, SOM_RTS); /* publish_scene_tile_row_with_horizontal_page_wrap */
}
SOM_REGISTER(0xC09840, SOM_RTS, "gen", publish_requested_ui_scene_tile_rows, 0, L_A | L_V, 1, 0, 1, 13, 6)
