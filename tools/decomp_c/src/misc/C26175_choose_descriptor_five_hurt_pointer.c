#include "som_c.h"

/* C26175 choose_descriptor_five_hurt_pointer   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/choose_descriptor_five_hurt_pointer.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_five_hurt_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    uint16_t value2 = BUS16(c, 0xDCE2A2 + (uint16_t)(value << 1));
    r->a = value2;
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26175, SOM_RTS, "gen", choose_descriptor_five_hurt_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 5)
