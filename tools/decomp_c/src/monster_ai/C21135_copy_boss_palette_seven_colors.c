#include "som_c.h"

/* C21135 copy_boss_palette_seven_colors   [class B, 60 bytes, 36 instructions]
 * Source: src/rom/copy_boss_palette_seven_colors.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void copy_boss_palette_seven_colors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0x024E) = a;
    RAM8(0x0278) = 0xC8;
    uint16_t value = RAM16(0x024E);
    uint16_t value2 = RAM16(0x0246);
    RAM16_SET(0x024E, (value2 & 0xFF) << 1);
    uint16_t value3 = RAM16(0x024E);
    RAM16_SET(0x0276, (uint16_t)((uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 - (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)) + 0x1000 + (((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 >= (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1))));
    uint8_t a_hi1 = (uint16_t)((uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 - (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)) + 0x1000 + (((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 >= (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1))) >> 8;
    uint16_t x1 = (value & 0xFF) << 1 << 1 << 1 << 1 << 1;
    uint16_t y1 = 0;
    for (;;) {
        uint16_t value4 = BUS16(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y1);
        RAM16_SET(0x0602 + x1, value4);
        a_hi1 = value4 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        if (!(y1 != 0x0E)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x;
    r->y = y1;
    r->v = (((uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 - (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)) ^ (uint16_t)((uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 - (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)) + 0x1000 + (((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 >= (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)))) & ((uint16_t)((uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 - (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1)) + 0x1000 + (((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3 >= (((value2 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F) ^ 1))) ^ 0x1000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21135, SOM_RTS, "gen", copy_boss_palette_seven_colors, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 60, 36)
