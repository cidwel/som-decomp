#include "som_c.h"

/* C26CD9 compare_descriptor_four_child_height_against_96   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/compare_descriptor_four_child_height_against_96.s
 * Documented in docs/boss-descriptor-four-child-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void compare_descriptor_four_child_height_against_96(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0066 + x);
    r->a = value;
    r->c = value >= 0x60;
    r->z = value == 0x60;
    r->n = (uint16_t)(value - 0x60) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26CD9, SOM_RTS, "gen", compare_descriptor_four_child_height_against_96, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
