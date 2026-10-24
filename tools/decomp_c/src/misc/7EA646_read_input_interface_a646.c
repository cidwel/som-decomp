#include "som_c.h"

/* 7EA646 read_input_interface_a646   [class A, 14 bytes, 8 instructions]
 * Source: src/boot/read_input_interface_a646.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void read_input_interface_a646(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t value = BUS16(c, 0x00421E);
    r->a = value | RAM16(0x0094);
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA646, SOM_RTS, "gen", read_input_interface_a646, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 14, 8)
