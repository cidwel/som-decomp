#include "som_c.h"

/* C27716 advance_descriptor_ten_positive_diagonal_sine_motion   [class B, 20 bytes, 8 instructions]
 * Source: src/rom/advance_descriptor_ten_positive_diagonal_sine_motion.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_ten_positive_diagonal_sine_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x7718, 0xC2773E); /* advance_descriptor_ten_global_axis_origins_by_velocity */
    uint16_t value = RAM16(0x007E + x);
    RAM16_SET(0x007E + x, (uint16_t)(value + 0x20));
    r->a = (uint16_t)(value + 0x20);
    r->c = value + 0x20 > 0xFFFF;
    r->v = ((value ^ (uint16_t)(value + 0x20)) & ((uint16_t)(value + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7725, 0xC27753); /* derive_descriptor_ten_x_sine_offset_from_phase */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7728, 0xC2776F); /* derive_descriptor_ten_positive_y_sine_offset_from_phase */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27716, SOM_RTS, "gen", advance_descriptor_ten_positive_diagonal_sine_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 8)
