#include "som_c.h"

/* C22EE3 classify_boss_direction_by_larger_absolute_axis   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/classify_boss_direction_by_larger_absolute_axis.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void classify_boss_direction_by_larger_absolute_axis(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    if (RAM16(0x024E) < RAM16(0x0246)) {
        RAM16_SET(0x026C, 1);
    } else {
        RAM16_SET(0x026C, 0);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22EE3, SOM_RTS, "gen", classify_boss_direction_by_larger_absolute_axis, 0, L_X | L_Y, 1, 0, 0, 17, 9)
