#include "som_c.h"

/* C252B0 compare_native55_integer_height_against_512   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/compare_native55_integer_height_against_512.s
 * Documented in docs/boss-native55-gravity.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void compare_native55_integer_height_against_512(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0066 + x);
    r->a = value;
    r->c = value >= 0x0200;
    r->z = value == 0x0200;
    r->n = (uint16_t)(value - 0x0200) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC252B0, SOM_RTS, "gen", compare_native55_integer_height_against_512, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
