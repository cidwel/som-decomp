#include "som_c.h"

/* C259DD dispatch_linked_parent_three_death_stages   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_linked_parent_three_death_stages.s
 * Documented in docs/boss-native-linked-death-phases.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_linked_parent_three_death_stages(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC20AFD, SOM_RTS); /* begin_boss_death_initialization_when_control_and_lock_clear */
    case 0x0002: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
    case 0x0004: TAIL_CALL_DYN(c, 0xC20B50, SOM_RTS); /* wait_for_boss_death_controller_event_gates */
    case 0x0006: TAIL_CALL_DYN(c, 0xC25CC8, SOM_RTS); /* install_linked_child_random_idle_motion */
    case 0x0008: TAIL_CALL_DYN(c, 0xC25AFC, SOM_RTS); /* install_linked_child_periodic_motion_and_idle_definition */
    case 0x000A: TAIL_CALL_DYN(c, 0xC25B86, SOM_RTS); /* aim_linked_child_attack_from_signed_fractional_tip */
    case 0x000C: TAIL_CALL_DYN(c, 0xC25B74, SOM_RTS); /* terminate_linked_child_when_parent_reaches_state_two */
    case 0x000E: TAIL_CALL_DYN(c, 0xC25C61, SOM_RTS); /* install_linked_child_return_callback_and_timer */
    case 0x0010: TAIL_CALL_DYN(c, 0xC25A41, SOM_RTS); /* initialize_linked_child_strip_collapse_from_parent_variant */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x59E5 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC259DD, SOM_RTS, "gen", dispatch_linked_parent_three_death_stages, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)
