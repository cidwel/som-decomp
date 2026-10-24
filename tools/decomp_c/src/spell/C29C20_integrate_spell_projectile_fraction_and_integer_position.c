#include "som_c.h"

/* C29C20 integrate_spell_projectile_fraction_and_integer_position   [class A, 39 bytes, 15 instructions]
 * Source: src/rom/integrate_spell_projectile_fraction_and_integer_position.s
 * Documented in docs/boss-native-spell-projectile-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void integrate_spell_projectile_fraction_and_integer_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0029 + x);
    uint16_t value2 = RAM16(0x003A + x);
    RAM16_SET(0x0029 + x, (uint16_t)(value + value2));
    RAM16_SET(0x002B + x, (uint16_t)(RAM16(0x002B + x) + RAM16(0x003C + x) + (value + value2 > 0xFFFF)));
    uint16_t value5 = RAM16(0x0030 + x);
    uint16_t value6 = RAM16(0x003E + x);
    RAM16_SET(0x0030 + x, (uint16_t)(value5 + value6));
    uint16_t value7 = RAM16(0x0032 + x);
    uint16_t value8 = RAM16(0x0040 + x);
    RAM16_SET(0x0032 + x, (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF)));
    r->a = (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF));
    r->c = value7 + value8 + (value5 + value6 > 0xFFFF) > 0xFFFF;
    r->z = (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF)) == 0;
    r->n = (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF)) & 0x8000;
    r->v = ((value7 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF))) & (value8 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF))) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29C20, SOM_RTS, "gen", integrate_spell_projectile_fraction_and_integer_position, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 39, 15)
