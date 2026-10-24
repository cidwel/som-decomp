#include "som_c.h"

/* C23F93 choose_descriptor_two_state_with_literal_nearest_x_store   [class B, 34 bytes, 14 instructions]
 * Source: src/rom/choose_descriptor_two_state_with_literal_nearest_x_store.s
 * Documented in docs/boss-descriptor-two.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_two_state_with_literal_nearest_x_store(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3F95, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x00A9 + x_ret, a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3F9B, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00AB + x_ret2, a_all2);
    uint16_t value = RAM16(0x007E + x_ret2);
    uint8_t a_hi1;
    if (value != 0) {
        a_hi1 = value >> 8;
    } else {
        r->a = value;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3FA6, 0xC23FB5); /* request_descriptor_two_half_hp_phase_and_height */
        uint16_t a_all3 = r->a;
        a_hi1 = a_all3 >> 8;
    }
    uint16_t value2 = RAM16(0x00AB + x_ret2);
    uint16_t value3 = RAM16(0x007E + x_ret2);
    uint16_t value4 = BUS16(c, 0xDCE068 + (uint16_t)((uint16_t)(value2 << 1) + value3));
    r->a = value4;
    r->x = (uint16_t)((uint16_t)(value2 << 1) + value3);
    r->c = (uint16_t)(value2 << 1) + value3 > 0xFFFF;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->v = (((uint16_t)(value2 << 1) ^ (uint16_t)((uint16_t)(value2 << 1) + value3)) & (value3 ^ (uint16_t)((uint16_t)(value2 << 1) + value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23F93, SOM_RTS, "gen", choose_descriptor_two_state_with_literal_nearest_x_store, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 34, 14)
