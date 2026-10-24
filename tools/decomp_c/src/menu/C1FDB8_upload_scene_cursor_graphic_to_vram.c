#include "som_c.h"

/* C1FDB8 upload_scene_cursor_graphic_to_vram   [class D, 44 bytes, 17 instructions]
 * Source: src/rom/upload_scene_cursor_graphic_to_vram.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void upload_scene_cursor_graphic_to_vram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x002116, 0x7000);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS16_SET(c, 0x004372, 0xFB00);
    BUS8_SET(c, 0x004374, 0xC7);
    BUS16_SET(c, 0x004375, 0xA0);
    BUS8_SET(c, 0x00420B, 0x80);
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1FDB8, SOM_RTL, "gen", upload_scene_cursor_graphic_to_vram, 0, L_Y | L_C | L_V, 1, 1, 1, 44, 17)
