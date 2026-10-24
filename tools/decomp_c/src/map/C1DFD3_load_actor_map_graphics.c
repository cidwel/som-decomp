#include "som_c.h"

/* C1DFD3 load_actor_map_graphics   [class B, 75 bytes, 43 instructions]
 * Source: src/rom/load_actor_map_graphics.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_actor_map_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0000, 8);
    uint16_t value = RAM16(0xE180 + x);
    uint8_t a_hi1 = (value & 0xFF) << 1 << 1 << 1 << 1 >> 8;
    uint16_t x1 = (value & 0xFF) << 1 << 1 << 1 << 1;
    uint16_t y1 = x;
    do {
        uint16_t value2 = BUS16(c, 0xD00000 + x1);
        RAM16_SET(0xE070 + y1, value2);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a_hi1 = value2 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0000) != 0);
    RAM16_SET(0xE065 + x, RAM16(0xE077 + x));
    uint16_t value4 = RAM16(0xE070 + x);
    RAM16_SET(0xE080 + x, (value4 & 0x03FF) << 1 << 1 << 1 << 1 << 1 << 1);
    uint8_t value5 = RAM8(0xE071 + x);
    RAM8(0xE082 + x) = (uint8_t)(((value5 >> 2) & 7) + 0xD5);
    r->a = ((value4 & 0x03FF) << 1 << 1 << 1 << 1 << 1 << 1 >> 8 << 8) | (uint8_t)(((value5 >> 2) & 7) + 0xD5);
    r->x = x;
    r->y = y;
    r->c = ((value5 >> 2) & 7) + 0xD5 > 0xFF;
    r->v = ((((value5 >> 2) & 7) ^ (uint8_t)(((value5 >> 2) & 7) + 0xD5)) & ((uint8_t)(((value5 >> 2) & 7) + 0xD5) ^ 0xD5) & 0x80) != 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DFD3, SOM_RTS, "gen", load_actor_map_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 75, 43)
