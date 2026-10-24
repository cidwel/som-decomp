#include "som_c.h"

/* C23857 boss_state_set_horizontal_orientation   [class A, 15 bytes, 6 instructions]
 * Source: src/rom/boss_state_set_horizontal_orientation.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_state_set_horizontal_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0098 + value);
    RAM16_SET(0x0098 + value, (value2 & 0xFFBF) | 0x40);
    r->a = (value2 & 0xFFBF) | 0x40;
    r->x = value;
    r->z = ((value2 & 0xFFBF) | 0x40) == 0;
    r->n = ((value2 & 0xFFBF) | 0x40) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23857, SOM_RTS, "gen", boss_state_set_horizontal_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 15, 6)
