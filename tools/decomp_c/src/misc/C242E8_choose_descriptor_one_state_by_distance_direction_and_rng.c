#include "som_c.h"

/* C242E8 choose_descriptor_one_state_by_distance_direction_and_rng   [class B, 72 bytes, 31 instructions]
 * Source: src/rom/choose_descriptor_one_state_by_distance_direction_and_rng.s
 * Documented in docs/boss-descriptor-one.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_one_state_by_distance_direction_and_rng(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x42EA, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x42F2, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00AB + x_ret2, a_all2);
    r->a = RAM16(0x00A9 + x_ret2);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x42FB, 0xC208BC); /* derive_clamped_target_distance_minus_one */
    uint16_t a_all3 = r->a;
    if (a_all3 >= 2) {
        uint16_t value4 = RAM16(0x00AB + RAM16(0x0287));
        uint16_t value5 = BUS16(c, 0xDCE176 + (uint16_t)(value4 << 1));
        r->a = value5;
        r->x = (uint16_t)(value4 << 1);
        r->c = value4 & 0x8000;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->c = a_all3 >= 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4306, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all4 = r->a;
    uint16_t value6 = RAM16(0x0287);
    if ((a_all4 & 0xFF) == 0) {
        uint16_t value7 = RAM16(0x00AB + value6);
        uint16_t value8 = BUS16(c, 0xDCE16E + (uint16_t)(value7 << 1));
        r->a = value8;
        r->x = (uint16_t)(value7 << 1);
        r->c = value7 & 0x8000;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value9 = RAM16(0x00AB + value6);
    uint16_t value10 = BUS16(c, 0xDCE166 + (uint16_t)(value9 << 1));
    r->a = value10;
    r->x = (uint16_t)(value9 << 1);
    r->c = value9 & 0x8000;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC242E8, SOM_RTS, "gen", choose_descriptor_one_state_by_distance_direction_and_rng, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 72, 31)
