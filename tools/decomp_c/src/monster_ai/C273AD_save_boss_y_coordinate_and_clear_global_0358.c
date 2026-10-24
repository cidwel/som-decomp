#include "som_c.h"

/* C273AD save_boss_y_coordinate_and_clear_global_0358   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/save_boss_y_coordinate_and_clear_global_0358.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void save_boss_y_coordinate_and_clear_global_0358(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0032 + x);
    RAM16_SET(0x035C, value);
    RAM16_SET(0x0358, 0);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC273AD, SOM_RTS, "gen", save_boss_y_coordinate_and_clear_global_0358, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 4)
