#include "som_c.h"

/* C26EBA choose_descriptor_eight_hurt_pointer_from_phase_bit   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/choose_descriptor_eight_hurt_pointer_from_phase_bit.s
 * Documented in docs/boss-descriptor-eight.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eight_hurt_pointer_from_phase_bit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM16(0x007E + x) & 1) != 0) {
        r->a = 0xE84C;
        r->z = 0;
        r->n = 1;
        RETURN_RTS(c);
    }
    r->a = 0xE84A;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26EBA, SOM_RTS, "gen", choose_descriptor_eight_hurt_pointer_from_phase_bit, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 16, 7)
