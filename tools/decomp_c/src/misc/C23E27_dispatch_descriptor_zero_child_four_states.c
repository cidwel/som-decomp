#include "som_c.h"

/* C23E27 dispatch_descriptor_zero_child_four_states   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_descriptor_zero_child_four_states.s
 * Documented in docs/boss-descriptor-zero-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_zero_child_four_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC23E37, SOM_RTS); /* initialize_descriptor_zero_child_animation_and_linked_effect */
    case 0x0002: TAIL_CALL_DYN(c, 0xC23E5A, SOM_RTS); /* advance_descriptor_zero_child_at_elapsed_counter_sixteen */
    case 0x0004: TAIL_CALL_DYN(c, 0xC23E69, SOM_RTS); /* advance_descriptor_zero_child_when_global_freeze_releases */
    case 0x0006: TAIL_CALL_DYN(c, 0xC23E7D, SOM_RTS); /* descriptor_zero_child_return_without_termination */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x3E2F + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC23E27, SOM_RTS, "gen", dispatch_descriptor_zero_child_four_states, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
