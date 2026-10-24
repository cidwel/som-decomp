#include "som_c.h"

/* C220C0 clip_boss_sprite_vertical   [class B, 45 bytes, 23 instructions]
 * Source: src/rom/clip_boss_sprite_vertical.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXC.
 */
static void clip_boss_sprite_vertical(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = BUS16(c, RAM16(0x0279) + 0x7E0000);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value & 0xFF00 & 0x8000)) {
        a1 = (uint8_t)(value & 0xFF00);
        a_hi1 = (value & 0xFF00) >> 8;
    } else {
        a1 = (uint8_t)((value & 0xFF00) | 0xFF);
        a_hi1 = ((value & 0xFF00) | 0xFF) >> 8;
    }
    uint16_t value2 = RAM16(0x0291);
    RAM16_SET(0x0297, (uint16_t)(((a1 << 8) | a_hi1) + value2));
    if ((uint16_t)((uint16_t)(((a1 << 8) | a_hi1) + value2) + 0x20) & 0x8000) {
        RAM16_SET(0x0801 + x, 0xE0);
        RAM16_SET(0x0285, (uint16_t)(RAM16(0x0285) - 1));
        r->a = 0xE0;
        r->c = 1;
        RETURN_RTS(c);
    }
    if (!((uint16_t)((uint16_t)((uint16_t)(((a1 << 8) | a_hi1) + value2) + 0x20) - 0x0100) & 0x8000)) {
        RAM16_SET(0x0801 + x, 0xE0);
        RAM16_SET(0x0285, (uint16_t)(RAM16(0x0285) - 1));
        r->a = 0xE0;
        r->c = 1;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x0297);
    RAM16_SET(0x0801 + x, value3);
    r->a = value3;
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC220C0, SOM_RTS, "gen", clip_boss_sprite_vertical, 0, L_B | L_X | L_C, 1, 0, 0, 45, 23)
