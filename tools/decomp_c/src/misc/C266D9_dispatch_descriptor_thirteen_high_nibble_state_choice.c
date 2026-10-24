#include "som_c.h"

/* C266D9 dispatch_descriptor_thirteen_high_nibble_state_choice   [class C, 12 bytes, 8 instructions]
 * Source: src/rom/dispatch_descriptor_thirteen_high_nibble_state_choice.s
 * Documented in docs/boss-descriptor-thirteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_thirteen_high_nibble_state_choice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    r->a = value >> 4 << 1;
    r->x = value >> 4 << 1;
    r->c = value >> 4 & 0x8000;
    r->z = value >> 4 << 1 == 0;
    r->n = value >> 4 << 1 & 0x8000;
    switch (value >> 4 << 1) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC266EB, SOM_RTS); /* choose_descriptor_thirteen_phase_zero_state */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26713, SOM_RTS); /* choose_descriptor_thirteen_phase_one_low_nibble_state */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2673D, SOM_RTS); /* choose_descriptor_thirteen_phase_two_state */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x66E5 + (value >> 4 << 1))), SOM_RTS);
    }
}
SOM_REGISTER(0xC266D9, SOM_RTS, "gen", dispatch_descriptor_thirteen_high_nibble_state_choice, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 12, 8)
