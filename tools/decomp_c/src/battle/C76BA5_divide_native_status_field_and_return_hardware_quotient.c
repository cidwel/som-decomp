#include "som_c.h"

/* C76BA5 divide_native_status_field_and_return_hardware_quotient   [class A, 18 bytes, 12 instructions]
 * Source: src/rom/divide_native_status_field_and_return_hardware_quotient.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void divide_native_status_field_and_return_hardware_quotient(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    BUS16_SET(c, 0x004204, y);
    BUS8_SET(c, 0x004206, a);
    uint16_t value = BUS16(c, 0x004214);
    r->y = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76BA5, SOM_RTS, "gen", divide_native_status_field_and_return_hardware_quotient, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 18, 12)
