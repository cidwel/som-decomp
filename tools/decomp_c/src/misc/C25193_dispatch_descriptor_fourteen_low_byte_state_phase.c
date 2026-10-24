#include "som_c.h"

/* C25193 dispatch_descriptor_fourteen_low_byte_state_phase   [class C, 11 bytes, 5 instructions]
 * Source: src/rom/dispatch_descriptor_fourteen_low_byte_state_phase.s
 * Documented in docs/boss-descriptor-fourteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_fourteen_low_byte_state_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    r->a = (value & 0xFF) << 1;
    r->x = (value & 0xFF) << 1;
    r->c = value & 0xFF & 0x8000;
    r->z = (value & 0xFF) << 1 == 0;
    r->n = (value & 0xFF) << 1 & 0x8000;
    switch ((value & 0xFF) << 1) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC251A2, SOM_RTS); /* choose_descriptor_fourteen_phase_zero_direction_state */
    case 0x0002: TAIL_CALL_DYN(c, 0xC251C9, SOM_RTS); /* choose_descriptor_fourteen_phase_one_state */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x519E + ((value & 0xFF) << 1))), SOM_RTS);
    }
}
SOM_REGISTER(0xC25193, SOM_RTS, "gen", dispatch_descriptor_fourteen_low_byte_state_phase, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 11, 5)
