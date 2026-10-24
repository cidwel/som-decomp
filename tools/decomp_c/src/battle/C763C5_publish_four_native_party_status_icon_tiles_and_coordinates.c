#include "som_c.h"

/* C763C5 publish_four_native_party_status_icon_tiles_and_coordinates   [class B, 60 bytes, 28 instructions]
 * Source: src/rom/publish_four_native_party_status_icon_tiles_and_coordinates.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void publish_four_native_party_status_icon_tiles_and_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xA17E);
    RAM16_SET(0x9C02 + x, (uint16_t)(value + 0x1848));
    RAM16_SET(0x9C06 + x, (uint16_t)(value + 0x1849));
    RAM16_SET(0x9C0A + x, (uint16_t)(value + 0x184A));
    RAM16_SET(0x9C0E + x, (uint16_t)(value + 0x184B));
    uint16_t value2 = RAM16(0xA159);
    RAM16_SET(0x9C00 + x, value2);
    RAM16_SET(0x9C04 + x, (uint16_t)(value2 + 8));
    RAM16_SET(0x9C0C + x, (uint16_t)(value2 + 0x0808));
    RAM16_SET(0x9C08 + x, (uint16_t)(value2 + 0x0800));
    r->a = (r->a & 0x00FF) | (((uint16_t)(x - 0x10) >> 8) << 8);
    r->x = (uint16_t)(x - 0x10);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC763C5, SOM_RTS, "gen", publish_four_native_party_status_icon_tiles_and_coordinates, 0, L_B | L_X | L_Y, 1, 1, 0, 60, 28)
