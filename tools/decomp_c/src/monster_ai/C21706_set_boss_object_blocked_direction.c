#include "som_c.h"

/* C21706 set_boss_object_blocked_direction   [class A, 29 bytes, 13 instructions]
 * Source: src/rom/set_boss_object_blocked_direction.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void set_boss_object_blocked_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value2 = BUS8(c, 0xD97EE0 + ((a >> 8 << 8) | (RAM8(0x0270) >> 1)));
    uint16_t value3 = RAM16(0x0287);
    RAM8(0x004E + value3) = value2 & RAM8(0x004E + value3);
    uint16_t value5 = RAM16(0x0270);
    uint16_t value6 = RAM16(0x004E + value3);
    RAM16_SET(0x004E + value3, value5 | value6);
    r->a = value5 | value6;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21706, SOM_RTS, "gen", set_boss_object_blocked_direction, 0, L_B | L_Y | L_V, 1, 0, 0, 29, 13)
