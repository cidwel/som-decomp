#include "som_c.h"

/* C21462 toggle_boss_animation_horizontal_orientation   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/toggle_boss_animation_horizontal_orientation.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void toggle_boss_animation_horizontal_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0098 + value);
    RAM16_SET(0x0098 + value, value2 ^ 0x40);
    r->a = value2 ^ 0x40;
    r->x = value;
    r->z = (value2 ^ 0x40) == 0;
    r->n = (value2 ^ 0x40) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21462, SOM_RTS, "gen", toggle_boss_animation_horizontal_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 12, 5)
