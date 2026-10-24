#include "som_c.h"

/* C1FBDC upload_two_rows_of_eight_character_tiles   [class D, 109 bytes, 49 instructions]
 * Source: src/rom/upload_two_rows_of_eight_character_tiles.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BY.
 */
static void upload_two_rows_of_eight_character_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0014);
    uint16_t value2 = RAM16(0xE06E + value);
    RAM16_SET(0x0000, ((RAM16(0xE08A + value) & 0x01FF) << 1 << 1 << 1 << 1) + 0x6000);
    uint16_t value4 = RAM16(0xE082 + value);
    BUS8_SET(c, 0x004304, (uint8_t)value4);
    BUS8_SET(c, 0x004314, (uint8_t)value4);
    BUS8_SET(c, 0x004324, (uint8_t)value4);
    BUS8_SET(c, 0x004334, (uint8_t)value4);
    BUS8_SET(c, 0x004344, (uint8_t)value4);
    BUS8_SET(c, 0x004354, (uint8_t)value4);
    BUS8_SET(c, 0x004364, (uint8_t)value4);
    BUS8_SET(c, 0x004374, (uint8_t)value4);
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x004300, 0x1801);
    BUS16_SET(c, 0x004310, 0x1801);
    BUS16_SET(c, 0x004320, 0x1801);
    BUS16_SET(c, 0x004330, 0x1801);
    BUS16_SET(c, 0x004340, 0x1801);
    BUS16_SET(c, 0x004350, 0x1801);
    BUS16_SET(c, 0x004360, 0x1801);
    BUS16_SET(c, 0x004370, 0x1801);
    r->x = value;
    r->y = value2;
    r->mf = 0;
    r->db = 0;
    r->sp -= 1;
    JSR(c, 0xFC3B, 0xC1FC49); /* configure_eight_tile_dma_channels_and_publish_row */
    r->sp += 1;
    RAM8(0x0001)++;
    r->y = (uint16_t)(value2 + 4);
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xFC44, 0xC1FC49); /* configure_eight_tile_dma_channels_and_publish_row */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    TAIL_CALL(c, 0xC1FCA3, SOM_RTS); /* copy_character_palette_strip_and_clear_unused_geometry */
}
SOM_REGISTER(0xC1FBDC, SOM_RTS, "gen", upload_two_rows_of_eight_character_tiles, 0, L_B | L_Y, 2, 1, 0, 109, 49)
