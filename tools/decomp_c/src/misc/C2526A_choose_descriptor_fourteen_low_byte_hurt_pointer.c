#include "som_c.h"

/* C2526A choose_descriptor_fourteen_low_byte_hurt_pointer   [class A, 13 bytes, 6 instructions]
 * Source: src/rom/choose_descriptor_fourteen_low_byte_hurt_pointer.s
 * Documented in docs/boss-descriptor-fourteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_fourteen_low_byte_hurt_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    uint16_t value2 = BUS16(c, 0xC2DAE6 + ((value & 0xFF) << 1));
    r->a = value2;
    r->x = (value & 0xFF) << 1;
    r->c = value & 0xFF & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2526A, SOM_RTS, "gen", choose_descriptor_fourteen_low_byte_hurt_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 6)
