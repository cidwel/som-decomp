#include "som_c.h"

/* C26CCB advance_descriptor_four_child_height_and_real_axis_motion   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/advance_descriptor_four_child_height_and_real_axis_motion.s
 * Documented in docs/boss-descriptor-four-child-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_four_child_height_and_real_axis_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00C6 + x);
    uint16_t value2 = RAM16(0x0066 + x);
    RAM16_SET(0x0066 + x, (uint16_t)(value + value2));
    r->a = (uint16_t)(value + value2);
    JSR(c, 0x6CD7, 0xC236BC); /* move_boss_axes_with_rejected_axis_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26CCB, SOM_RTS, "gen", advance_descriptor_four_child_height_and_real_axis_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)
