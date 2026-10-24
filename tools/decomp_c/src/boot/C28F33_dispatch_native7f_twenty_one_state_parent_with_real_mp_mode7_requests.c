#include "som_c.h"

/* C28F33 dispatch_native7f_twenty_one_state_parent_with_real_mp_mode7_requests   [class C, 30 bytes, 12 instructions]
 * Source: src/rom/dispatch_native7f_twenty_one_state_parent_with_real_mp_mode7_requests.s
 * Documented in docs/boss-native7f-header.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void dispatch_native7f_twenty_one_state_parent_with_real_mp_mode7_requests(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x0186 + x, 0x6363);
    BUS8_SET(c, 0x00211A, 0xC0);
    BUS16_SET(c, (db << 0x10) + 0x0FAE, 2);
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x94 + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC28F7B, SOM_RTS); /* initialize_native7f_phase8_matrix_and_two_real_effect_children */
    case 0x0002: TAIL_CALL_DYN(c, 0xC28FB3, SOM_RTS); /* expand_native7f_scale_then_seed_animation_and_matrix_offsets */
    case 0x0004: TAIL_CALL_DYN(c, 0xC29027, SOM_RTS); /* wait_native7f_animation_then_change_phase_seed_and_matrix_offsets */
    case 0x0006: TAIL_CALL_DYN(c, 0xC2904E, SOM_RTS); /* advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound */
    case 0x0008: TAIL_CALL_DYN(c, 0xC290AC, SOM_RTS); /* shrink_native7f_while_rotating_then_attack_and_mask_party */
    case 0x000A: TAIL_CALL_DYN(c, 0xC2910E, SOM_RTS); /* shrink_native7f_until_sign_transition_then_attack_and_seed */
    case 0x000C: TAIL_CALL_DYN(c, 0xC2917F, SOM_RTS); /* advance_native7f_integer_y_and_change_phase_above_0160 */
    case 0x000E: TAIL_CALL_DYN(c, 0xC291A4, SOM_RTS); /* release_native7f_party_mask_once_and_wait_for_left_boundary */
    case 0x0010: TAIL_CALL_DYN(c, 0xC2924B, SOM_RTS); /* enter_native7f_phase_one_from_initial_phase_eight */
    case 0x0012: TAIL_CALL_DYN(c, 0xC292A8, SOM_RTS); /* advance_native7f_after_twelve_ticks_and_load_four_equal_palettes */
    case 0x0014: TAIL_CALL_DYN(c, 0xC292F6, SOM_RTS); /* enter_native7f_phase_five_at_exact_timer60_with_vertical_callback */
    case 0x0016: TAIL_CALL_DYN(c, 0xC29381, SOM_RTS); /* advance_native7f_timed_spell_state_or_enter_death_palette_phase */
    case 0x0018: TAIL_CALL_DYN(c, 0xC29463, SOM_RTS); /* shrink_native7f_scale_by_eight_then_enter_phase_fifteen */
    case 0x001A: TAIL_CALL_DYN(c, 0xC29499, SOM_RTS); /* move_native7f_up_two_pixels_until_unsigned_y_at_most0160 */
    case 0x001C: TAIL_CALL_DYN(c, 0xC294BE, SOM_RTS); /* consume_native7f_request_and_choose_upper_or_lower_entrance */
    case 0x001E: TAIL_CALL_DYN(c, 0xC29539, SOM_RTS); /* consume_native7f_request_then_install_lateral_linear_motion */
    case 0x0020: TAIL_CALL_DYN(c, 0xC295BD, SOM_RTS); /* accelerate_native7f_anisotropic_collapse_and_complete_event */
    case 0x0022: TAIL_CALL_DYN(c, 0xC2964B, SOM_RTS); /* restart_native7f_after_twelve_ticks_with_real_palette_effects */
    case 0x0024: TAIL_CALL_DYN(c, 0xC296A5, SOM_RTS); /* start_native7f_terminal_after_low_control_byte_clears */
    case 0x0026: TAIL_CALL_DYN(c, 0xC296F8, SOM_RTS); /* advance_native7f_terminal_particles_then_enter_phase_sixteen */
    case 0x0028: TAIL_CALL_DYN(c, 0xC2977B, SOM_RTS); /* finish_native7f_only_when_overlapping_request_words_clear */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x8F51 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC28F33, SOM_RTS, "gen", dispatch_native7f_twenty_one_state_parent_with_real_mp_mode7_requests, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 12)
