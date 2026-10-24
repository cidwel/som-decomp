#include "som_c.h"

/* C2AFA9 compute_scene_curve_square_over_one_hundred_forty_four   [class A, 39 bytes, 22 instructions]
 * Source: src/rom/compute_scene_curve_square_over_one_hundred_forty_four.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void compute_scene_curve_square_over_one_hundred_forty_four(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    BUS8_SET(c, 0x004202, a);
    BUS8_SET(c, 0x004203, a);
    uint8_t value = BUS8(c, 0x004216);
    BUS8_SET(c, 0x004204, value);
    uint8_t value2 = BUS8(c, 0x004217);
    BUS8_SET(c, 0x004205, value2);
    BUS8_SET(c, 0x004206, 0x90);
    uint8_t value3 = BUS8(c, 0x004214);
    SET_A8(r, value3);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AFA9, SOM_RTS, "gen", compute_scene_curve_square_over_one_hundred_forty_four, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 1, 39, 22)
