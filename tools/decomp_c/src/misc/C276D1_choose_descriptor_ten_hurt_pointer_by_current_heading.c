#include "som_c.h"

/* C276D1 choose_descriptor_ten_hurt_pointer_by_current_heading   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/choose_descriptor_ten_hurt_pointer_by_current_heading.s
 * Documented in docs/boss-descriptor-ten.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_ten_hurt_pointer_by_current_heading(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00AB + x);
    uint16_t value2 = BUS16(c, 0xC276DB + (uint16_t)(value << 1));
    r->a = value2;
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC276D1, SOM_RTS, "gen", choose_descriptor_ten_hurt_pointer_by_current_heading, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 5)
