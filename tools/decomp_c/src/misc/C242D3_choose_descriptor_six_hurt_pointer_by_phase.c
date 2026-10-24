#include "som_c.h"

/* C242D3 choose_descriptor_six_hurt_pointer_by_phase   [class A, 13 bytes, 6 instructions]
 * Source: src/rom/choose_descriptor_six_hurt_pointer_by_phase.s
 * Documented in docs/boss-descriptor-six.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_six_hurt_pointer_by_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(0x007E + x) != 0) {
        r->a = 0xD46F;
        r->z = 0;
        r->n = 1;
        RETURN_RTS(c);
    }
    r->a = 0xD46D;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC242D3, SOM_RTS, "gen", choose_descriptor_six_hurt_pointer_by_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 6)
