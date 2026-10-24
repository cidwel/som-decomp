#include "som_c.h"

/* C1F944 publish_current_palette_buffer_through_dma_channel_seven   [class D, 38 bytes, 15 instructions]
 * Source: src/rom/publish_current_palette_buffer_through_dma_channel_seven.s
 * Documented in docs/ui-native-palette-publication.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void publish_current_palette_buffer_through_dma_channel_seven(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    BUS8_SET(c, 0x002121, 0);
    BUS16_SET(c, 0x004372, 0x0600);
    BUS16_SET(c, 0x004370, 0x2200);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004375, 0x0200);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = 0x0200;
    r->y = (uint8_t)y;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F944, SOM_RTS, "gen", publish_current_palette_buffer_through_dma_channel_seven, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 38, 15)
