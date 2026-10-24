#include "som_c.h"

/* C184F9 divide_floating_number_byte_by_ten   [class A, 29 bytes, 15 instructions]
 * Source: src/rom/divide_floating_number_byte_by_ten.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: AXYCV.
 */
static void divide_floating_number_byte_by_ten(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    BUS8_SET(c, 0x004204, a);
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004206, 0x0A);
    uint8_t value = BUS8(c, 0x004216);
    SET_A8(r, value);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC184F9, SOM_RTS, "gen", divide_floating_number_byte_by_ten, 0, L_A | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 15)
