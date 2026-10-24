#include "som_c.h"

/* C273A7 advance_descriptor_seven_integer_terrain_axes   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/advance_descriptor_seven_integer_terrain_axes.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_seven_integer_terrain_axes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = RAM16(0x02C5);
    JSR(c, 0x73AB, 0xC20A47); /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC273A7, SOM_RTS, "gen", advance_descriptor_seven_integer_terrain_axes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 6, 3)
