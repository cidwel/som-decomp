#include "som_c.h"

/* C26B1B initialize_descriptor_four_height_and_variant_flags   [class A, 24 bytes, 9 instructions]
 * Source: src/rom/initialize_descriptor_four_height_and_variant_flags.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_four_height_and_variant_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0066 + x, 0x40);
    uint16_t value = RAM16(0x0042 + x);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value == 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        zero1 = value == 0;
        negative1 = value & 0x8000;
    } else {
        uint16_t value2 = RAM16(0x0098 + x);
        RAM16_SET(0x0098 + x, (value2 & 0xFFFC) | 1);
        a1 = (uint8_t)((value2 & 0xFFFC) | 1);
        a_hi1 = ((value2 & 0xFFFC) | 1) >> 8;
        zero1 = ((value2 & 0xFFFC) | 1) == 0;
        negative1 = ((value2 & 0xFFFC) | 1) & 0x8000;
    }
    r->a = (a_hi1 << 8) | a1;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26B1B, SOM_RTS, "gen", initialize_descriptor_four_height_and_variant_flags, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 9)
