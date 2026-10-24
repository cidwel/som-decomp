#include "som_c.h"

/* C2604B dispatch_descriptor_five_state_choice   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_descriptor_five_state_choice.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_five_state_choice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC26059, SOM_RTS); /* advance_descriptor_five_hp_ratio_phase */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26073, SOM_RTS); /* choose_descriptor_five_directional_distance_state */
    case 0x0004: TAIL_CALL_DYN(c, 0xC260B7, SOM_RTS); /* choose_descriptor_five_hold_state */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6053 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2604B, SOM_RTS, "gen", dispatch_descriptor_five_state_choice, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
