#include "som_c.h"

/* C1FD37 shift_and_align_three_party_horizontal_positions   [class A, 23 bytes, 8 instructions]
 * Source: src/rom/shift_and_align_three_party_horizontal_positions.s
 * Documented in docs/map-camera-transition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void shift_and_align_three_party_horizontal_positions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t value = RAM16(0xE002);
    RAM16_SET(0xE002, (uint16_t)(value - 0x0400));
    RAM16_SET(0xE202, (uint16_t)(value - 0x0400));
    RAM16_SET(0xE402, (uint16_t)(value - 0x0400));
    r->a = (uint16_t)(value - 0x0400);
    r->c = value >= 0x0400;
    r->v = ((value ^ 0x0400) & (value ^ (uint16_t)(value - 0x0400)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1FD37, SOM_RTL, "gen", shift_and_align_three_party_horizontal_positions, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 23, 8)
