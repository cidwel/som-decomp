#include "som_c.h"

/* C22C91 divide_unsigned_byte_through_cpu_ports   [class A, 46 bytes, 23 instructions]
 * Source: src/rom/divide_unsigned_byte_through_cpu_ports.s
 * Documented in docs/boss-byte-port-math.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: Z.
 */
static void divide_unsigned_byte_through_cpu_ports(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    BUS8_SET(c, 0x004204, RAM8(0x0346));
    BUS8_SET(c, 0x004205, 0);
    uint8_t value2 = RAM8(0x034E);
    if (value2 == 0) {
        r->z = 0;
        RETURN_RTS(c);
    }
    BUS8_SET(c, 0x004206, value2);
    uint8_t value3 = BUS8(c, 0x004214);
    RAM8(0x0356) = value3;
    uint8_t value4 = BUS8(c, 0x004216);
    RAM8(0x035E) = value4;
    r->z = RAM8(0x03C5) == 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22C91, SOM_RTS, "gen", divide_unsigned_byte_through_cpu_ports, 0, L_Z, 1, 1, 0, 46, 23)
