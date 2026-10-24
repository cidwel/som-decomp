#include "som_c.h"

/* C262B8 initialize_descriptor_three_control_and_phase   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/initialize_descriptor_three_control_and_phase.s
 * Documented in docs/boss-descriptor-three.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_three_control_and_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x007A + x, 1);
    RAM16_SET(0x007E + x, 0);
    r->a = 1;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC262B8, SOM_RTS, "gen", initialize_descriptor_three_control_and_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 4)
