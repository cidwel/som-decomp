#include "som_c.h"

/* C1852B clear_sixteen_floating_number_tile_words   [class B, 57 bytes, 20 instructions]
 * Source: src/rom/clear_sixteen_floating_number_tile_words.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clear_sixteen_floating_number_tile_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xE06C + x);
    RAM16_SET(0x0000 + value, 0xCB00);
    RAM16_SET(0x0002 + value, 0xCB00);
    RAM16_SET(0x0004 + value, 0xCB00);
    RAM16_SET(0x0006 + value, 0xCB00);
    RAM16_SET(0x0008 + value, 0xCB00);
    RAM16_SET(0x000A + value, 0xCB00);
    RAM16_SET(0x000C + value, 0xCB00);
    RAM16_SET(0x000E + value, 0xCB00);
    RAM16_SET(0x0010 + value, 0xCB00);
    RAM16_SET(0x0012 + value, 0xCB00);
    RAM16_SET(0x0014 + value, 0xCB00);
    RAM16_SET(0x0016 + value, 0xCB00);
    RAM16_SET(0x0018 + value, 0xCB00);
    RAM16_SET(0x001A + value, 0xCB00);
    RAM16_SET(0x001C + value, 0xCB00);
    RAM16_SET(0x001E + value, 0xCB00);
    r->a = 0xCB00;
    r->y = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1852B, SOM_RTS, "gen", clear_sixteen_floating_number_tile_words, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 57, 20)
