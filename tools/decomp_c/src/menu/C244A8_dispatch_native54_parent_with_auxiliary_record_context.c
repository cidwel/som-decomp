#include "som_c.h"

/* C244A8 dispatch_native54_parent_with_auxiliary_record_context   [class C, 15 bytes, 8 instructions]
 * Source: src/rom/dispatch_native54_parent_with_auxiliary_record_context.s
 * Documented in docs/boss-native54-header.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_native54_parent_with_auxiliary_record_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0289);
    uint16_t value2 = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value2 << 1);
    r->x = (uint16_t)(value2 << 1);
    r->y = (uint16_t)(value - 0xF800);
    r->c = value2 & 0x8000;
    r->z = (uint16_t)(value2 << 1) == 0;
    r->n = (uint16_t)(value2 << 1) & 0x8000;
    r->v = ((value ^ 0xF800) & (value ^ (uint16_t)(value - 0xF800)) & 0x8000) != 0;
    switch ((uint16_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC244D9, SOM_RTS); /* initialize_native54_attack_and_state11 */
    case 0x0002: TAIL_CALL_DYN(c, 0xC24517, SOM_RTS); /* advance_native54_to_state2_after_animation */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2454E, SOM_RTS); /* choose_native54_spawn_or_attack_state_after_twelve_ticks */
    case 0x0006: TAIL_CALL_DYN(c, 0xC24596, SOM_RTS); /* create_missing_native54_body_parts_or_mark_variant_zero_limit */
    case 0x0008: TAIL_CALL_DYN(c, 0xC24653, SOM_RTS); /* start_native54_auxiliary_lunge_after_animation */
    case 0x000A: TAIL_CALL_DYN(c, 0xC24682, SOM_RTS); /* advance_native54_lunge_or_consume_hurt */
    case 0x000C: TAIL_CALL_DYN(c, 0xC246ED, SOM_RTS); /* complete_native54_attack_animation_and_create_projectile */
    case 0x000E: TAIL_CALL_DYN(c, 0xC2478F, SOM_RTS); /* move_auxiliary_record_until_native54_return_animation */
    case 0x0010: TAIL_CALL_DYN(c, 0xC247BD, SOM_RTS); /* reset_native54_radius_and_enter_recovery */
    case 0x0012: TAIL_CALL_DYN(c, 0xC247D2, SOM_RTS); /* advance_native54_cast_pose_and_recover_after_spell_attempt */
    case 0x0014: TAIL_CALL_DYN(c, 0xC248F1, SOM_RTS); /* complete_auxiliary_recoil_or_accelerate */
    case 0x0016: TAIL_CALL_DYN(c, 0xC249AF, SOM_RTS); /* select_native54_random_recovery_position_at_tick24 */
    case 0x0018: TAIL_CALL_DYN(c, 0xC24A63, SOM_RTS); /* choose_native54_attack_or_cast_state_after_target_timer */
    case 0x001A: TAIL_CALL_DYN(c, 0xC24AD6, SOM_RTS); /* enter_native54_return_state_after_attack_notification */
    case 0x001C: TAIL_CALL_DYN(c, 0xC20AFD, SOM_RTS); /* begin_boss_death_initialization_when_control_and_lock_clear */
    case 0x001E: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
    case 0x0020: TAIL_CALL_DYN(c, 0xC24AEA, SOM_RTS); /* finish_native54_death_and_request_literal_event */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x44B7 + ((uint16_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC244A8, SOM_RTS, "gen", dispatch_native54_parent_with_auxiliary_record_context, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 15, 8)
