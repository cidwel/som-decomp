#include "som_c.h"

/* C237C7 dispatch_boss_state_byte_command_through_original_twenty_two_word_table   [class C, 5 bytes, 3 instructions]
 * Source: src/rom/dispatch_boss_state_byte_command_through_original_twenty_two_word_table.s
 * Documented in docs/boss-state-engine-vm.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void dispatch_boss_state_byte_command_through_original_twenty_two_word_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->a = (uint16_t)(a << 1);
    r->x = (uint16_t)(a << 1);
    r->c = a & 0x8000;
    r->z = (uint16_t)(a << 1) == 0;
    r->n = (uint16_t)(a << 1) & 0x8000;
    switch ((uint16_t)(a << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC237F8, SOM_RTS); /* boss_state_select_animation_operand */
    case 0x0002: TAIL_CALL_DYN(c, 0xC23802, SOM_RTS); /* boss_state_set_six_motion_words */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2382F, SOM_RTS); /* boss_state_set_motion_callback_operand */
    case 0x0006: TAIL_CALL_DYN(c, 0xC23839, SOM_RTS); /* boss_state_set_field_48_operand */
    case 0x0008: TAIL_CALL_DYN(c, 0xC23843, SOM_RTS); /* boss_state_set_field_4a_operand */
    case 0x000A: TAIL_CALL_DYN(c, 0xC2384D, SOM_RTS); /* boss_state_set_duration_operand */
    case 0x000C: TAIL_CALL_DYN(c, 0xC23857, SOM_RTS); /* boss_state_set_horizontal_orientation */
    case 0x000E: TAIL_CALL_DYN(c, 0xC23866, SOM_RTS); /* boss_state_set_vertical_orientation */
    case 0x0010: TAIL_CALL_DYN(c, 0xC23875, SOM_RTS); /* boss_state_toggle_horizontal_orientation */
    case 0x0012: TAIL_CALL_DYN(c, 0xC23881, SOM_RTS); /* boss_state_toggle_vertical_orientation */
    case 0x0014: TAIL_CALL_DYN(c, 0xC2388D, SOM_RTS); /* boss_state_clear_horizontal_orientation */
    case 0x0016: TAIL_CALL_DYN(c, 0xC23899, SOM_RTS); /* boss_state_clear_vertical_orientation */
    case 0x0018: TAIL_CALL_DYN(c, 0xC238A5, SOM_RTS); /* boss_state_set_field_1e3_operand */
    case 0x001A: TAIL_CALL_DYN(c, 0xC238AF, SOM_RTS); /* boss_state_set_field_a7_operand */
    case 0x001C: TAIL_CALL_DYN(c, 0xC238B9, SOM_RTS); /* boss_state_prepare_spell_operand */
    case 0x001E: TAIL_CALL_DYN(c, 0xC238CB, SOM_RTS); /* boss_state_create_projectile_operand */
    case 0x0020: TAIL_CALL_DYN(c, 0xC2390F, SOM_RTS); /* boss_state_call_native_operand */
    case 0x0022: TAIL_CALL_DYN(c, 0xC23922, SOM_RTS); /* boss_state_store_actor_relative_word */
    case 0x0024: TAIL_CALL_DYN(c, 0xC23934, SOM_RTS); /* boss_state_external_actor_command_operand */
    case 0x0026: TAIL_CALL_DYN(c, 0xC23940, SOM_RTS); /* boss_state_prepare_attack_row_operand */
    case 0x0028: TAIL_CALL_DYN(c, 0xC2394F, SOM_RTS); /* boss_state_request_sound_operand */
    case 0x002A: TAIL_CALL_DYN(c, 0xC2395C, SOM_RTS); /* boss_state_jump_to_operand_pointer */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x37CC + ((uint16_t)(a << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC237C7, SOM_RTS, "gen", dispatch_boss_state_byte_command_through_original_twenty_two_word_table, SOM_UNWINDS, L_X | L_Y | L_V, 1, 0, 0, 5, 3)
