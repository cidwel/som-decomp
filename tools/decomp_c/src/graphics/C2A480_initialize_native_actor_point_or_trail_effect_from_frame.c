#include "som_c.h"

/* C2A480 initialize_native_actor_point_or_trail_effect_from_frame   [class B, 37 bytes, 17 instructions]
 * Source: src/rom/initialize_native_actor_point_or_trail_effect_from_frame.s
 * Documented in docs/actor-visual-effect-point-producer.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void initialize_native_actor_point_or_trail_effect_from_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0014);
    if (RAM8(0xE110 + value) >= 5) {
        RAM8(0xE012 + value) = 0;
        RAM8(0xE114 + value) = 0x40;
        uint8_t value3 = RAM8(0xE084 + value);
        uint8_t a1;
        if (!((uint8_t)(value3 - 4) & 0x80)) {
            a1 = (uint8_t)(value3 - 4);
        } else {
            a1 = 0;
        }
        RAM8(0xE116 + value) = a1;
        r->x = value;
        r->c = value3 >= 4;
        r->v = ((value3 ^ 4) & (value3 ^ (uint8_t)(value3 - 4)) & 0x80) != 0;
        RETURN_RTL(c);
    }
    r->x = value;
    JSR(c, 0xA48B, 0xC2A4A5); /* decode_native_frame_point_targets_and_fractional_velocities */
    r->x = RAM16(0x0014);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A480, SOM_RTL, "gen", initialize_native_actor_point_or_trail_effect_from_frame, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 37, 17)
