#include "som_c.h"

/* C8EA69 divide_spell_level_by_target_count   [class A, 34 bytes, 17 instructions]
 * Source: src/rom/divide_spell_level_by_target_count.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void divide_spell_level_by_target_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004204, RAM8(0x039D));
    BUS8_SET(c, 0x004206, RAM8(0xE176 + y));
    uint8_t value3 = BUS8(c, 0x004214);
    RAM8(0x039D) = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EA69, SOM_RTS, "gen", divide_spell_level_by_target_count, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 34, 17)
