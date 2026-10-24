#include "som_c.h"

/* C27AF4 dispatch_native58_parent_with_complete_motion_guard   [class C, 13 bytes, 6 instructions]
 * Source: src/rom/dispatch_native58_parent_with_complete_motion_guard.s
 * Documented in docs/boss-native58-header.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_native58_parent_with_complete_motion_guard(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AF6, 0xC27DE7); GUARD_JSR(c, sp_call, 0x7AF6); } /* move_native58_and_clear_party_hp_at_lower_boundary */
    uint16_t value2 = RAM16(OBJECT_PHASE + RAM16(0x0287));
    r->a = (uint16_t)(value2 << 1);
    r->x = (uint16_t)(value2 << 1);
    r->c = value2 & 0x8000;
    r->z = (uint16_t)(value2 << 1) == 0;
    r->n = (uint16_t)(value2 << 1) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    switch ((uint16_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC27B0F, SOM_RTS); /* initialize_native58_parent_and_four_linked_objects */
    case 0x0002: TAIL_CALL_DYN(c, 0xC27BAE, SOM_RTS); /* advance_native58_after_initial_sixty_tick_wait */
    case 0x0004: TAIL_CALL_DYN(c, 0xC27BC0, SOM_RTS); /* aim_native58_and_advance_or_enter_death_phase */
    case 0x0006: TAIL_CALL_DYN(c, 0xC27C0C, SOM_RTS); /* execute_native58_action_and_return_to_aim */
    case 0x0008: TAIL_CALL_DYN(c, 0xC20AFD, SOM_RTS); /* begin_boss_death_initialization_when_control_and_lock_clear */
    case 0x000A: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
    case 0x000C: TAIL_CALL_DYN(c, 0xC27C22, SOM_RTS); /* complete_native58_death_gate_and_numeric_event */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x7B01 + ((uint16_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC27AF4, SOM_RTS, "gen", dispatch_native58_parent_with_complete_motion_guard, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 6)
