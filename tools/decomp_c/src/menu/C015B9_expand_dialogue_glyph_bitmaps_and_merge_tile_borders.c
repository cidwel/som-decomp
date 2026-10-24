#include "som_c.h"

/* C015B9 expand_dialogue_glyph_bitmaps_and_merge_tile_borders   [class B, 115 bytes, 61 instructions]
 * Source: src/rom/expand_dialogue_glyph_bitmaps_and_merge_tile_borders.s
 * Documented in docs/event-dialogue-glyph-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void expand_dialogue_glyph_bitmaps_and_merge_tile_borders(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA176) = 0x20;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    do {
        uint8_t a1 = 0x0C;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value = RAM8(0x9000 + y2);
            RAM8(0x9404 + x2) = value;
            RAM8(0x9405 + x2) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 + 1);
            if (!(a1 != 0)) break;
        }
        RAM8(0xA176)--;
        a_hi1 = a_hi2;
        x1 = (uint16_t)(x2 + 8);
        y1 = y2;
    } while (RAM8(0xA176) != 0);
    RAM8(0xA176) = 0x20;
    uint8_t a_hi3 = a_hi1;
    uint16_t x3 = 0;
    uint16_t y3 = 0;
    do {
        RAM16_SET(0x9400 + x3, 0);
        RAM16_SET(0x9402 + x3, 0);
        RAM16_SET(0x941C + x3, 0);
        RAM16_SET(0x941E + x3, 0);
        uint8_t a2 = 0x0C;
        uint8_t a_hi4 = 0;
        uint16_t x4 = x3;
        uint16_t y4 = y3;
        for (;;) {
            RAM8(0x9402 + x4) = RAM8(0x9000 + y4) | RAM8(0x9402 + x4);
            uint8_t value4 = RAM8(0x9000 + y4);
            uint8_t value5 = RAM8(0x9406 + x4);
            RAM8(0x9406 + x4) = value4 | value5;
            a2 = (uint8_t)(a2 - 1);
            a_hi4 = value4 | value5;
            x4 = (uint16_t)(x4 + 2);
            y4 = (uint16_t)(y4 + 1);
            if (!(a2 != 0)) break;
        }
        RAM8(0xA176)--;
        a_hi3 = a_hi4;
        x3 = (uint16_t)(x4 + 8);
        y3 = y4;
    } while (RAM8(0xA176) != 0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC015B9, SOM_RTS, "gen", expand_dialogue_glyph_bitmaps_and_merge_tile_borders, 0, 0, 1, 1, 0, 115, 61)
