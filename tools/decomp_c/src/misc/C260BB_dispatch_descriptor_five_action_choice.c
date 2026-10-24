#include "som_c.h"

/* C260BB dispatch_descriptor_five_action_choice   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_descriptor_five_action_choice.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_five_action_choice(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC260C9, SOM_RTS); /* choose_descriptor_five_phase_zero_action */
    case 0x0002: TAIL_CALL_DYN(c, 0xC260CE, SOM_RTS); /* choose_descriptor_five_target_hold_or_hp_fallback */
    case 0x0004: TAIL_CALL_DYN(c, 0xC26170, SOM_RTS); /* choose_descriptor_five_phase_two_action */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x60C3 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC260BB, SOM_RTS, "gen", dispatch_descriptor_five_action_choice, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
