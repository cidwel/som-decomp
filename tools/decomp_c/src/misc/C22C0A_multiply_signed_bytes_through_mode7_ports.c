#include "som_c.h"

/* C22C0A multiply_signed_bytes_through_mode7_ports   [class D, 37 bytes, 15 instructions]
 * Source: src/rom/multiply_signed_bytes_through_mode7_ports.s
 * Documented in docs/boss-byte-port-math.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void multiply_signed_bytes_through_mode7_ports(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0x0346);
    BUS8_SET(c, 0x00211B, value);
    uint8_t value2 = RAM8(0x03C5);
    uint8_t a1;
    if (!(value & 0x80)) {
        a1 = value2;
    } else {
        a1 = 0xFF;
    }
    BUS8_SET(c, 0x00211B, a1);
    BUS8_SET(c, 0x00211C, RAM8(0x034E));
    uint8_t value4 = BUS8(c, 0x002134);
    RAM8(0x0356) = value4;
    uint8_t value5 = BUS8(c, 0x002135);
    RAM8(0x0357) = value5;
    SET_A8(r, value5);
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22C0A, SOM_RTS, "gen", multiply_signed_bytes_through_mode7_ports, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 37, 15)
