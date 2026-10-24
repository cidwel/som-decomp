#include "som_c.h"

/* C01539 compose_dialogue_tile_mask_pair_rows   [class B, 101 bytes, 47 instructions]
 * Source: src/rom/compose_dialogue_tile_mask_pair_rows.s
 * Documented in docs/event-dialogue-render-blend.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: Y.
 */
static void compose_dialogue_tile_mask_pair_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0xA175) = 8;
    uint16_t value = RAM16(0xA182);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = value;
    uint16_t y1 = y;
    do {
        uint8_t value2 = RAM8(0x9400 + y1);
        uint8_t value3 = BUS8(c, 0xD2D480 + x1);
        RAM8(0x9000 + y1) = ((uint8_t)(0xFF - value2) & value3) | value2;
        uint8_t value4 = BUS8(c, 0xD2D480 + (uint16_t)(x1 + 1));
        RAM8(0x9000 + (uint16_t)(y1 + 1)) = ((uint8_t)(0xFF - value2) & value4) | RAM8(0x9400 + (uint16_t)(y1 + 1));
        RAM8(0xA175)--;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM8(0xA175) != 0);
    RAM8(0xA175) = 8;
    uint16_t value6 = RAM16(0xA182);
    uint8_t a_hi2 = (uint16_t)(y1 + 0x10) >> 8;
    uint16_t x2 = value6;
    uint16_t y2 = (uint16_t)(y1 + 0x10);
    do {
        uint8_t value7 = RAM8(0x9400 + y2);
        uint8_t value8 = BUS8(c, 0xD2D480 + x2);
        RAM8(0x9000 + y2) = ((uint8_t)(0xFF - value7) & value8) | value7;
        uint8_t value9 = BUS8(c, 0xD2D480 + (uint16_t)(x2 + 1));
        RAM8(0x9000 + (uint16_t)(y2 + 1)) = ((uint8_t)(0xFF - value7) & value9) | RAM8(0x9400 + (uint16_t)(y2 + 1));
        RAM8(0xA175)--;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 2);
    } while (RAM8(0xA175) != 0);
    r->y = y2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01539, SOM_RTS, "gen", compose_dialogue_tile_mask_pair_rows, 0, L_Y, 1, 1, 0, 101, 47)
