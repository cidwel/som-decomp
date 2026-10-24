#include "som_c.h"

/* C1E723 upload_map_party_icon_tile   [class D, 48 bytes, 27 instructions]
 * Source: src/rom/upload_map_party_icon_tile.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void upload_map_party_icon_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    BUS16_SET(c, 0x004372, (a & 0x07FF) << 1 << 1 << 1 << 1 << 1);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS16_SET(c, 0x004375, 0x20);
    BUS8_SET(c, 0x004374, (uint8_t)(((a >> 0x0C) & 7) + 0xD5));
    BUS8_SET(c, 0x00420B, 0x80);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E723, SOM_RTS, "gen", upload_map_party_icon_tile, 0, L_X | L_Y, 2, 0, 0, 48, 27)
