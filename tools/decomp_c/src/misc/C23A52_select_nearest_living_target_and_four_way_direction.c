#include "som_c.h"

/* C23A52 select_nearest_living_target_and_four_way_direction   [class A, 17 bytes, 7 instructions]
 * Source: src/rom/select_nearest_living_target_and_four_way_direction.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void select_nearest_living_target_and_four_way_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3A56, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3A5E, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00AB + x_ret2, a_all2);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23A52, SOM_RTS, "gen", select_nearest_living_target_and_four_way_direction, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 17, 7)
