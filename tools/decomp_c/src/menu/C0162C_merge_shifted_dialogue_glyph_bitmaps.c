#include "som_c.h"

/* C0162C merge_shifted_dialogue_glyph_bitmaps   [class A, 55 bytes, 31 instructions]
 * Source: src/rom/merge_shifted_dialogue_glyph_bitmaps.s
 * Documented in docs/event-dialogue-glyph-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void merge_shifted_dialogue_glyph_bitmaps(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    RAM8(0xA176) = 0x20;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    do {
        uint8_t a1 = 0x0C;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        bool carry2 = carry1;
        for (;;) {
            RAM8(0x9404 + x2) = (uint8_t)((RAM8(0x9000 + y2) << 1) | carry2) | RAM8(0x9404 + x2);
            uint8_t value3 = RAM8(0x9000 + y2);
            uint8_t value4 = RAM8(0x9404 + x2);
            RAM8(0x9404 + x2) = (value3 >> 1) | value4;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = (value3 >> 1) | value4;
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 + 1);
            carry2 = value3 & 0x01;
            if (!(a1 != 0)) break;
        }
        RAM8(0xA176)--;
        a_hi1 = a_hi2;
        x1 = (uint16_t)(x2 + 8);
        y1 = y2;
        carry1 = carry2;
    } while (RAM8(0xA176) != 0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0162C, SOM_RTS, "gen", merge_shifted_dialogue_glyph_bitmaps, 0, 0, 1, 1, 0, 55, 31)
