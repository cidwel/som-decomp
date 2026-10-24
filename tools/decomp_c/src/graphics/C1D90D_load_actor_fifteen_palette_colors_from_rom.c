#include "som_c.h"

/* C1D90D load_actor_fifteen_palette_colors_from_rom   [class B, 53 bytes, 24 instructions]
 * Source: src/rom/load_actor_fifteen_palette_colors_from_rom.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_actor_fifteen_palette_colors_from_rom(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    BUS8_SET(c, 0x004202, RAM8(0x000C));
    BUS8_SET(c, 0x004203, 0x1E);
    RAM8(0x000A) = 0x0F;
    RAM8(0x000B) = 0;
    uint16_t value2 = RAM16(0xE0F8 + x);
    RAM8(0x000F) = 0xC8;
    uint16_t value3 = BUS16(c, 0x004216);
    RAM16_SET(0x000D, (uint16_t)(value3 + 0x1000));
    uint8_t a1 = (uint8_t)(value3 + 0x1000);
    uint8_t a_hi1 = (uint16_t)(value3 + 0x1000) >> 8;
    uint16_t y1 = value2;
    do {
        uint16_t value4 = BUS16(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D));
        RAM16_SET(0x0700 + y1, value4);
        RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
        RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
        RAM16_SET(0x000A, (uint16_t)(RAM16(0x000A) - 1));
        a1 = (uint8_t)value4;
        a_hi1 = value4 >> 8;
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x000A) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x;
    r->y = y1;
    r->c = value3 + 0x1000 > 0xFFFF;
    r->v = (((uint16_t)(value3 + 0x1000) ^ 0x1000) & (value3 ^ (uint16_t)(value3 + 0x1000)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D90D, SOM_RTS, "gen", load_actor_fifteen_palette_colors_from_rom, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 53, 24)
