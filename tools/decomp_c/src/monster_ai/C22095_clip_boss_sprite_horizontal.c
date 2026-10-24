#include "som_c.h"

/* C22095 clip_boss_sprite_horizontal   [class B, 43 bytes, 22 instructions]
 * Source: src/rom/clip_boss_sprite_horizontal.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXC.
 */
static void clip_boss_sprite_horizontal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = BUS16(c, RAM16(0x0279) + 0x7E0000);
    uint8_t a1;
    uint8_t a_hi1;
    if ((value & 0x80) == 0) {
        a1 = value & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)((value & 0xFF) | 0xFF00);
        a_hi1 = ((value & 0xFF) | 0xFF00) >> 8;
    }
    uint16_t value2 = RAM16(0x028F);
    RAM16_SET(0x0297, (uint16_t)(((a_hi1 << 8) | a1) + value2));
    if ((uint16_t)((uint16_t)(((a_hi1 << 8) | a1) + value2) + 0x20) & 0x8000) {
        RAM16_SET(0x0285, (uint16_t)(RAM16(0x0285) - 1));
        r->a = (uint16_t)((uint16_t)(((a_hi1 << 8) | a1) + value2) + 0x20);
        r->c = 1;
        RETURN_RTS(c);
    }
    if (!((uint16_t)((uint16_t)((uint16_t)(((a_hi1 << 8) | a1) + value2) + 0x20) - 0x0120) & 0x8000)) {
        RAM16_SET(0x0285, (uint16_t)(RAM16(0x0285) - 1));
        r->a = (uint16_t)((uint16_t)((uint16_t)(((a_hi1 << 8) | a1) + value2) + 0x20) - 0x0120);
        r->c = 1;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x0297);
    RAM16_SET(0x0800 + x, value3);
    RAM16_SET(0x0299, value3);
    r->a = value3;
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22095, SOM_RTS, "gen", clip_boss_sprite_horizontal, 0, L_B | L_X | L_C, 1, 0, 0, 43, 22)
