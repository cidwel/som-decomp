#include "som_c.h"

/* C28FED advance_native7f_fractional_xy_and_subtract_vertical_gravity   [class B, 58 bytes, 22 instructions]
 * Source: src/rom/advance_native7f_fractional_xy_and_subtract_vertical_gravity.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_native7f_fractional_xy_and_subtract_vertical_gravity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0029 + x);
    uint16_t value2 = RAM16(0x003A + x);
    RAM16_SET(0x0029 + x, (uint16_t)(value + value2));
    RAM16_SET(0x002B + x, (uint16_t)(RAM16(0x002B + x) + RAM16(0x003C + x) + (value + value2 > 0xFFFF)));
    uint16_t value5 = RAM16(0x0030 + x);
    uint16_t value6 = RAM16(0x003E + x);
    RAM16_SET(0x0030 + x, (uint16_t)(value5 + value6));
    RAM16_SET(0x0032 + x, (uint16_t)(RAM16(0x0032 + x) + RAM16(0x0040 + x) + (value5 + value6 > 0xFFFF)));
    uint16_t value9 = RAM16(0x003E + x);
    RAM16_SET(0x003E + x, (uint16_t)(value9 - 0x0100));
    uint16_t value10 = RAM16(0x0040 + x);
    RAM16_SET(0x0040 + x, (uint16_t)(value10 - (value9 >= 0x0100 ^ 1)));
    r->a = (uint16_t)(value10 - (value9 >= 0x0100 ^ 1));
    r->c = value10 >= (value9 >= 0x0100 ^ 1);
    r->z = (uint16_t)(value10 - (value9 >= 0x0100 ^ 1)) == 0;
    r->n = (uint16_t)(value10 - (value9 >= 0x0100 ^ 1)) & 0x8000;
    r->v = (value10 & (value10 ^ (uint16_t)(value10 - (value9 >= 0x0100 ^ 1))) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28FED, SOM_RTS, "gen", advance_native7f_fractional_xy_and_subtract_vertical_gravity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 58, 22)
