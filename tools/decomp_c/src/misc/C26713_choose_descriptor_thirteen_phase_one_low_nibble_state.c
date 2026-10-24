#include "som_c.h"

/* C26713 choose_descriptor_thirteen_phase_one_low_nibble_state   [class B, 42 bytes, 19 instructions]
 * Source: src/rom/choose_descriptor_thirteen_phase_one_low_nibble_state.s
 * Documented in docs/boss-descriptor-thirteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_thirteen_phase_one_low_nibble_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x6717, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    r->a = 1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x671D, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret2 = r->z;
    if (!zero_ret2) {
        uint16_t value2 = RAM16(0x0287);
        uint16_t value3 = RAM16(0x007E + value2);
        uint16_t value4 = BUS16(c, 0xDCE372 + ((value3 & 0x0F) << 1));
        r->a = value4;
        r->x = value2;
        r->c = value3 & 0x0F & 0x8000;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x00AB + RAM16(0x0287));
    uint16_t value7 = BUS16(c, 0xDCE356 + (uint16_t)(value6 << 1));
    r->a = value7;
    r->x = (uint16_t)(value6 << 1);
    r->c = value6 & 0x8000;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26713, SOM_RTS, "gen", choose_descriptor_thirteen_phase_one_low_nibble_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 42, 19)
