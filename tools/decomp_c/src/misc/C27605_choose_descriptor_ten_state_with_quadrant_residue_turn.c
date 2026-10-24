#include "som_c.h"

/* C27605 choose_descriptor_ten_state_with_quadrant_residue_turn   [class B, 92 bytes, 43 instructions]
 * Source: src/rom/choose_descriptor_ten_state_with_quadrant_residue_turn.s
 * Documented in docs/boss-descriptor-ten.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_ten_state_with_quadrant_residue_turn(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 3;
    JSR(c, 0x760A, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret = r->z;
    if (!zero_ret) {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x761B, 0xC23224); /* select_nearest_active_living_party_actor */
        uint16_t a_all2 = r->a;
        RAM16_SET(0x00A9 + RAM16(0x0287), a_all2);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7623, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
        uint16_t value2 = RAM16(0x026A);
        RAM16_SET(0x0295, value2);
        uint16_t value3 = RAM16(0x0287);
        uint16_t value4 = RAM16(0x00AB + value3);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(value2 - value4) & 0x8000)) {
            a1 = (uint8_t)(value2 - value4);
            a_hi1 = (uint16_t)(value2 - value4) >> 8;
        } else {
            uint16_t value5 = RAM16(0x02C7);
            a1 = (uint8_t)(((uint16_t)(value2 - value4) ^ value5) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value2 - value4) ^ value5) + 1) >> 8;
        }
        uint8_t a_hi2;
        if (((a_hi1 << 8) | a1) != 2) {
            a_hi2 = a_hi1;
        } else {
            r->a = 1;
            r->x = value3;
            r->c = ((a_hi1 << 8) | a1) >= 2;
            r->v = ((value2 ^ value4) & (value2 ^ (uint16_t)(value2 - value4)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x763D, 0xC2300B); /* draw_boss_frame_random_number */
            bool zero_ret4 = r->z;
            if (!zero_ret4) {
                RAM16_SET(0x0295, (uint16_t)(RAM16(0x0295) - 1) & 3);
            } else {
                RAM16_SET(0x0295, (uint16_t)(RAM16(0x0295) + 1) & 3);
            }
            a_hi2 = 0;
        }
        uint16_t value8 = RAM16(0x0295);
        RAM16_SET(0x00AB + RAM16(0x0287), value8);
        uint16_t value10 = BUS16(c, 0xDCE567 + (uint16_t)(value8 << 1));
        r->a = value10;
        r->x = (uint16_t)(value8 << 1);
        r->c = 0;
        r->z = value10 == 0;
        r->n = value10 & 0x8000;
        r->v = ((value2 ^ value4) & (value2 ^ (uint16_t)(value2 - value4)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value12 = RAM16(0x00AB + RAM16(0x0287));
    uint16_t value13 = BUS16(c, 0xDCE56F + (uint16_t)(value12 << 1));
    r->a = value13;
    r->x = (uint16_t)(value12 << 1);
    r->c = value12 & 0x8000;
    r->z = value13 == 0;
    r->n = value13 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27605, SOM_RTS, "gen", choose_descriptor_ten_state_with_quadrant_residue_turn, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 92, 43)
