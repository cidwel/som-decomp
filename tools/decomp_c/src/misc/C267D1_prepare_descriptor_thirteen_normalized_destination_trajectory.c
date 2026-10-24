#include "som_c.h"
#include "som_hand_b.h"

/* C267D1 prepare_descriptor_thirteen_normalized_destination_trajectory   [class B, 20 bytes, 8 instructions]
 * Source: src/rom/prepare_descriptor_thirteen_normalized_destination_trajectory.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void prepare_descriptor_thirteen_normalized_destination_trajectory(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x002B + x));
    uint16_t value2 = RAM16(0x0032 + x);
    RAM16_SET(0x0299, value2);
    r->a = value2;
    JSR_CHK(c, 0x67DD, 0xC267E5); /* dispatch_descriptor_thirteen_variant_destination_selection */
    JSR_CHK(c, 0x67E0, 0xC22F61); /* normalize_boss_displacement_to_signed_fixed_point */
    JSR_CHK(c, 0x67E3, 0xC26877); /* derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC267D1, SOM_RTS, "hand", prepare_descriptor_thirteen_normalized_destination_trajectory, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 8)
