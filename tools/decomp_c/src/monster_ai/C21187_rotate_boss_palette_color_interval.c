#include "som_c.h"

/* C21187 rotate_boss_palette_color_interval   [class B, 64 bytes, 36 instructions]
 * Source: src/rom/rotate_boss_palette_color_interval.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void rotate_boss_palette_color_interval(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM16_SET(0x0256, (((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1 << 1 << 1);
    uint16_t value = RAM16(0x0246);
    uint16_t value2 = RAM16(0x0256);
    RAM16_SET(0x025E, (uint16_t)(((value & 0xF0) >> 3) + value2 + (((value & 0xF0) >> 2) & 1)));
    uint16_t value3 = RAM16(0x0600 + (uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F)));
    RAM16_SET(0x0295, value3);
    uint8_t a_hi1 = value3 >> 8;
    uint16_t x1 = (uint16_t)((uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F)) - 2);
    uint16_t y1 = (uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F));
    for (;;) {
        uint16_t value4 = RAM16(0x0600 + x1);
        RAM16_SET(0x0600 + y1, value4);
        uint16_t value5 = RAM16(0x025E);
        uint8_t a_hi1_next = value4 >> 8;
        uint16_t x1_next = (uint16_t)(x1 - 2);
        uint16_t y1_next = x1;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!(y1 != value5)) break;
    }
    uint16_t value6 = RAM16(0x0295);
    RAM16_SET(0x0600 + y1, value6);
    r->a = value6;
    r->y = y1;
    r->v = (((uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F)) ^ 2) & ((uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F)) ^ (uint16_t)((uint16_t)(((value & 0x0F) << 1) + value2 + ((value & 0x0F) >> 0x0F)) - 2)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21187, SOM_RTS, "gen", rotate_boss_palette_color_interval, 0, L_B | L_Y | L_V, 1, 1, 0, 64, 36)
