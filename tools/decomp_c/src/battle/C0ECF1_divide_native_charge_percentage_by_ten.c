#include "som_c.h"

/* C0ECF1 divide_native_charge_percentage_by_ten   [class A, 23 bytes, 12 instructions]
 * Source: src/rom/divide_native_charge_percentage_by_ten.s
 * Documented in docs/actor-charge-gauge-presentation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void divide_native_charge_percentage_by_ten(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    BUS8_SET(c, 0x004204, a);
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004206, 0x0A);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0ECF1, SOM_RTS, "gen", divide_native_charge_percentage_by_ten, 0, L_X | L_Y, 1, 1, 0, 23, 12)
