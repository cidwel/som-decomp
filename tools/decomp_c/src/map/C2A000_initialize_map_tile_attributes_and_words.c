#include "som_c.h"

/* C2A000 initialize_map_tile_attributes_and_words   [class B, 67 bytes, 35 instructions]
 * Source: src/rom/initialize_map_tile_attributes_and_words.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BX.
 */
static void initialize_map_tile_attributes_and_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x001C);
    RAM16_SET(0x0010, ((value & 0x3F) << 8) | 0);
    uint16_t value2 = RAM16(0x0010);
    RAM16_SET(0x0010, (uint16_t)(((((value & 0x3F) << 8) | 0) >> 1) + value2 + ((((value & 0x3F) << 8) | 0) & 1)));
    RAM16_SET(0x0012, (uint16_t)((uint16_t)(((((value & 0x3F) << 8) | 0) >> 1) + value2 + ((((value & 0x3F) << 8) | 0) & 1)) + 0xC0));
    RAM16_SET(0x0014, 0xB800);
    uint16_t value3 = RAM16(0x001B);
    uint16_t x1;
    if (!(value3 & 0x4000)) {
        x1 = (uint16_t)(((((value & 0x3F) << 8) | 0) >> 1) + value2 + ((((value & 0x3F) << 8) | 0) & 1));
    } else {
        x1 = RAM16(0x0012);
    }
    r->a = 0xB800;
    r->x = x1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7F;
    r->sp -= 1;
    JSR(c, 0xA02B, 0xC2A043); /* copy_map_tile_attribute_entries */
    r->sp += 1;
    RAM16_SET(0x0014, 0xBC00);
    uint16_t value5 = RAM16(0x0012);
    uint16_t value6 = RAM16(0x001B);
    uint16_t x2;
    if (value6 & 0x8000) {
        x2 = value5;
    } else {
        x2 = RAM16(0x0010);
    }
    r->a = 0xBC00;
    r->x = x2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xA03B, 0xC2A043); /* copy_map_tile_attribute_entries */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xA03E, 0xC2A069); /* decode_map_tile_word_layers */
    r->sp += 1;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A000, SOM_RTL, "gen", initialize_map_tile_attributes_and_words, 0, L_B | L_X, 2, 1, 1, 67, 35)
