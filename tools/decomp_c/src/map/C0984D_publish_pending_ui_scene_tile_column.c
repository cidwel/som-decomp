#include "som_c.h"

/* C0984D publish_pending_ui_scene_tile_column   [class D, 52 bytes, 22 instructions]
 * Source: src/rom/publish_pending_ui_scene_tile_column.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: AV.
 */
static void publish_pending_ui_scene_tile_column(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(0x002F) & 0x80) {
        RAM8(0x002F) = 0;
        BUS8_SET(c, 0x002115, 3);
        BUS16_SET(c, 0x004370, 0x1800);
        BUS8_SET(c, 0x004374, 0);
        BUS16_SET(c, 0x004372, 0x0B80);
        BUS16_SET(c, 0x002116, RAM16(0x0078));
        BUS16_SET(c, 0x004375, 0x80);
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = 0x80;
        r->mf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0984D, SOM_RTS, "gen", publish_pending_ui_scene_tile_column, 0, L_A | L_V, 1, 1, 1, 52, 22)
