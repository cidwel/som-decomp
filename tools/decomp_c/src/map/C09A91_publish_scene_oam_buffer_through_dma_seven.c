#include "som_c.h"

/* C09A91 publish_scene_oam_buffer_through_dma_seven   [class D, 39 bytes, 15 instructions]
 * Source: src/rom/publish_scene_oam_buffer_through_dma_seven.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void publish_scene_oam_buffer_through_dma_seven(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002102, 0);
    BUS16_SET(c, 0x004372, 0x0800);
    BUS16_SET(c, 0x004370, 0x0400);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004375, 0x0220);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = 0x0220;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09A91, SOM_RTS, "gen", publish_scene_oam_buffer_through_dma_seven, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 39, 15)
