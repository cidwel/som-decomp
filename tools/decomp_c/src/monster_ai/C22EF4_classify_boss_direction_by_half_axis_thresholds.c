#include "som_c.h"

/* C22EF4 classify_boss_direction_by_half_axis_thresholds   [class A, 38 bytes, 20 instructions]
 * Source: src/rom/classify_boss_direction_by_half_axis_thresholds.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void classify_boss_direction_by_half_axis_thresholds(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x026C, 2);
    uint16_t value = RAM16(0x024E);
    RAM16_SET(0x025E, value);
    RAM16_SET(0x025E, RAM16(0x025E) >> 1);
    uint16_t value3 = RAM16(0x025E);
    uint16_t value4 = RAM16(0x0246);
    if (value3 < value4) {
        RAM16_SET(0x0256, value4);
        RAM16_SET(0x0256, RAM16(0x0256) >> 1);
        if (RAM16(0x0256) < value) {
            RAM16_SET(0x026C, (uint16_t)(RAM16(0x026C) - 1));
        }
    } else {
        RAM16_SET(0x026C, 0);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22EF4, SOM_RTS, "gen", classify_boss_direction_by_half_axis_thresholds, 0, L_X | L_Y, 1, 0, 0, 38, 20)
