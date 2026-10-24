#include "som_c.h"

/* C2C7B2 configure_map_overlay_hdma_channels   [class D, 43 bytes, 16 instructions]
 * Source: src/rom/configure_map_overlay_hdma_channels.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void configure_map_overlay_hdma_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x004330, 0x2641);
    BUS16_SET(c, 0x004332, 0xEF00);
    BUS16_SET(c, 0x004334, 0x7E);
    BUS16_SET(c, 0x004336, 0x7E00);
    BUS16_SET(c, 0x004320, 0x0500);
    BUS16_SET(c, 0x004322, 0xEF20);
    BUS16_SET(c, 0x004324, 0x7E);
    r->a = 0x7E;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C7B2, SOM_RTS, "gen", configure_map_overlay_hdma_channels, 0, L_B | L_X | L_Y | L_V, 1, 0, 1, 43, 16)
