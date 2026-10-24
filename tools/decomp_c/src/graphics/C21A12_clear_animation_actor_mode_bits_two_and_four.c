#include "som_c.h"

/* C21A12 clear_animation_actor_mode_bits_two_and_four   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/clear_animation_actor_mode_bits_two_and_four.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void clear_animation_actor_mode_bits_two_and_four(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x0070 + value);
    RAM16_SET(0x0070 + value, value2 & 0xFFF9);
    r->a = value2 & 0xFFF9;
    r->x = value;
    r->z = (value2 & 0xFFF9) == 0;
    r->n = value2 & 0xFFF9 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21A12, SOM_RTS, "gen", clear_animation_actor_mode_bits_two_and_four, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 12, 5)
