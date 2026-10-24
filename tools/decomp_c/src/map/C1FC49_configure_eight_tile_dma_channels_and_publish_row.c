#include "som_c.h"

/* C1FC49 configure_eight_tile_dma_channels_and_publish_row   [class D, 90 bytes, 32 instructions]
 * Source: src/rom/configure_eight_tile_dma_channels_and_publish_row.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: BXY.
 */
static void configure_eight_tile_dma_channels_and_publish_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    BUS16_SET(c, 0x002116, RAM16(0x0000));
    BUS16_SET(c, 0x004302, BUS16(c, 0x0000 + y));
    BUS16_SET(c, 0x004312, BUS16(c, 0x0002 + y));
    BUS16_SET(c, 0x004322, BUS16(c, 0x0008 + y));
    BUS16_SET(c, 0x004332, BUS16(c, 0x000A + y));
    BUS16_SET(c, 0x004342, BUS16(c, 0x0010 + y));
    BUS16_SET(c, 0x004352, BUS16(c, 0x0012 + y));
    BUS16_SET(c, 0x004362, BUS16(c, 0x0018 + y));
    BUS16_SET(c, 0x004372, BUS16(c, 0x001A + y));
    BUS16_SET(c, 0x004305, 0x20);
    BUS16_SET(c, 0x004315, 0x20);
    BUS16_SET(c, 0x004325, 0x20);
    BUS16_SET(c, 0x004335, 0x20);
    BUS16_SET(c, 0x004345, 0x20);
    BUS16_SET(c, 0x004355, 0x20);
    BUS16_SET(c, 0x004365, 0x20);
    BUS16_SET(c, 0x004375, 0x20);
    BUS8_SET(c, 0x00420B, 0xFF);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FC49, SOM_RTS, "hand", configure_eight_tile_dma_channels_and_publish_row, 0, L_B | L_X | L_Y, 1, -1, 0, 90, 32)
