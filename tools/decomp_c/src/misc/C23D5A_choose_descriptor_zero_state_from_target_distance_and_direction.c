#include "som_c.h"

/* C23D5A choose_descriptor_zero_state_from_target_distance_and_direction   [class B, 50 bytes, 21 instructions]
 * Source: src/rom/choose_descriptor_zero_state_from_target_distance_and_direction.s
 * Documented in docs/boss-descriptor-zero.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_zero_state_from_target_distance_and_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3D5C, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3D62, 0xC208BC); /* derive_clamped_target_distance_minus_one */
    uint16_t a_all2 = r->a;
    if (a_all2 >= 2) {
        uint16_t value3 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value4 = BUS16(c, 0xDCE000 + (uint16_t)(value3 << 1));
        r->a = value4;
        r->x = (uint16_t)(value3 << 1);
        r->c = value3 & 0x8000;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->c = a_all2 >= 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3D6D, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret3 = r->z;
    if (!zero_ret3) {
        uint16_t value6 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value7 = BUS16(c, 0xDCE000 + (uint16_t)(value6 << 1));
        r->a = value7;
        r->x = (uint16_t)(value6 << 1);
        r->c = value6 & 0x8000;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3D75, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret4 = r->z;
    if (zero_ret4) {
        r->a = 0xD09E;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD0AA;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23D5A, SOM_RTS, "gen", choose_descriptor_zero_state_from_target_distance_and_direction, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 50, 21)
