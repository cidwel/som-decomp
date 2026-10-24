#include "som_c.h"

/* C270B3 initialize_descriptor_seven_height_and_variant_two_field   [class A, 18 bytes, 7 instructions]
 * Source: src/rom/initialize_descriptor_seven_height_and_variant_two_field.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_seven_height_and_variant_two_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0066 + x, 0x20);
    uint16_t value = RAM16(0x0042 + x);
    if (value == 2) {
        RAM16_SET(0x004C + x, 0);
    }
    r->a = value;
    r->c = value >= 2;
    r->z = value == 2;
    r->n = (uint16_t)(value - 2) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC270B3, SOM_RTS, "gen", initialize_descriptor_seven_height_and_variant_two_field, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 7)
