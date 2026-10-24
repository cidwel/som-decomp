#include "som_c.h"

/* C763AD derive_native_party_status_icon_quadrant_tile_offset   [class A, 24 bytes, 12 instructions]
 * Source: src/rom/derive_native_party_status_icon_quadrant_tile_offset.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void derive_native_party_status_icon_quadrant_tile_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0xA17F) = (uint8_t)y & 0x0E;
    uint8_t a1;
    if (((uint8_t)y & 1) == 0) {
        a1 = (uint8_t)y & 1;
    } else {
        a1 = 4;
    }
    RAM8(0xA17E) = (uint8_t)(a1 + RAM8(0xA17E));
    JSR(c, 0x63C3, 0xC763C5); /* publish_four_native_party_status_icon_tiles_and_coordinates */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC763AD, SOM_RTS, "gen", derive_native_party_status_icon_quadrant_tile_offset, 0, L_B | L_X | L_Y, 1, 1, 0, 24, 12)
