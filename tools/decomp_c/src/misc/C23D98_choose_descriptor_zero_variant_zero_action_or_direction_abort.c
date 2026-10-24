#include "som_c.h"

/* C23D98 choose_descriptor_zero_variant_zero_action_or_direction_abort   [class B, 67 bytes, 32 instructions]
 * Source: src/rom/choose_descriptor_zero_variant_zero_action_or_direction_abort.s
 * Documented in docs/boss-descriptor-zero.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_zero_variant_zero_action_or_direction_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3D9C, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    uint16_t value2 = RAM16(0x00AB + x_ret);
    if (value2 != 6) {
        r->a = RAM16(0x00A9 + x_ret);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3DAC, 0xC208BC); /* derive_clamped_target_distance_minus_one */
        uint16_t a_all2 = r->a;
        if (a_all2 < 4) {
            if (a_all2 < 3) {
                uint16_t value5 = RAM16(0x00AB + RAM16(0x0287));
                uint16_t value6 = BUS16(c, 0xDCE010 + (uint16_t)(value5 << 1));
                r->a = value6;
                r->x = (uint16_t)(value5 << 1);
                r->c = 0;
                r->z = value6 == 0;
                r->n = value6 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xD0BF;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 2;
        r->c = a_all2 >= 4;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3DB7, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret3 = r->z;
        if (zero_ret3) {
            r->a = 0xD0BD;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xD0BA;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->c = 1;
    r->z = value2 == 6;
    r->n = (uint16_t)(value2 - 6) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23D98, SOM_RTS, "gen", choose_descriptor_zero_variant_zero_action_or_direction_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 67, 32)
