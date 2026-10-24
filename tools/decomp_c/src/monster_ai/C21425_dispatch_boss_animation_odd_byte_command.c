#include "som_c.h"

/* C21425 dispatch_boss_animation_odd_byte_command   [class C, 9 bytes, 4 instructions]
 * Source: src/rom/dispatch_boss_animation_odd_byte_command.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void dispatch_boss_animation_odd_byte_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = ((a_hi << 8) | a) & 0xFE;
    r->x = ((a_hi << 8) | a) & 0xFE;
    r->z = (((a_hi << 8) | a) & 0xFE) == 0;
    r->n = ((a_hi << 8) | a) & 0xFE & 0x8000;
    r->mf = 0;
    switch (((a_hi << 8) | a) & 0xFE) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC21462, SOM_RTS); /* toggle_boss_animation_horizontal_orientation */
    case 0x0002: TAIL_CALL_DYN(c, 0xC2146E, SOM_RTS); /* toggle_boss_animation_vertical_orientation */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2147A, SOM_RTS); /* clear_boss_animation_horizontal_orientation */
    case 0x0006: TAIL_CALL_DYN(c, 0xC21492, SOM_RTS); /* set_boss_animation_horizontal_orientation */
    case 0x0008: TAIL_CALL_DYN(c, 0xC21486, SOM_RTS); /* clear_boss_animation_vertical_orientation */
    case 0x000A: TAIL_CALL_DYN(c, 0xC2149E, SOM_RTS); /* set_boss_animation_vertical_orientation */
    case 0x000C: TAIL_CALL_DYN(c, 0xC214AA, SOM_RTS); /* move_boss_from_animation_signed_offsets_with_collision_sliding */
    case 0x000E: TAIL_CALL_DYN(c, 0xC217E4, SOM_RTS); /* restore_animation_selected_actor */
    case 0x0010: TAIL_CALL_DYN(c, 0xC217E7, SOM_RTS); /* jump_animation_stream_absolute */
    case 0x0012: TAIL_CALL_DYN(c, 0xC217F0, SOM_RTS); /* set_animation_relative_actor_parent */
    case 0x0014: TAIL_CALL_DYN(c, 0xC21802, SOM_RTS); /* replace_animation_and_restart_stream */
    case 0x0016: TAIL_CALL_DYN(c, 0xC2181A, SOM_RTS); /* request_animation_sound_parameter */
    case 0x0018: TAIL_CALL_DYN(c, 0xC21827, SOM_RTS); /* set_animation_actor_byte_a2 */
    case 0x001A: TAIL_CALL_DYN(c, 0xC21834, SOM_RTS); /* rewind_animation_stream */
    case 0x001C: TAIL_CALL_DYN(c, 0xC2183A, SOM_RTS); /* set_animation_target_control_if_eligible */
    case 0x001E: TAIL_CALL_DYN(c, 0xC2186C, SOM_RTS); /* place_animation_target_at_mirrored_signed_offsets */
    case 0x0020: TAIL_CALL_DYN(c, 0xC218D6, SOM_RTS); /* set_animation_target_motion_pair_and_rate */
    case 0x0022: TAIL_CALL_DYN(c, 0xC21906, SOM_RTS); /* set_animation_target_motion_triplet */
    case 0x0024: TAIL_CALL_DYN(c, 0xC21933, SOM_RTS); /* create_animation_object_inheriting_orientation */
    case 0x0026: TAIL_CALL_DYN(c, 0xC219CE, SOM_RTS); /* clear_animation_work_buffer_with_fixed_source_dma */
    case 0x0028: TAIL_CALL_DYN(c, 0xC21A06, SOM_RTS); /* enable_animation_actor_mode_bit_four */
    case 0x002A: TAIL_CALL_DYN(c, 0xC21A12, SOM_RTS); /* clear_animation_actor_mode_bits_two_and_four */
    case 0x002C: TAIL_CALL_DYN(c, 0xC21A1E, SOM_RTS); /* dispatch_animation_selected_actor_command */
    case 0x002E: TAIL_CALL_DYN(c, 0xC21A2A, SOM_RTS); /* set_animation_actor_field_22 */
    case 0x0030: TAIL_CALL_DYN(c, 0xC21A34, SOM_RTS); /* set_animation_actor_field_88 */
    case 0x0032: TAIL_CALL_DYN(c, 0xC21A3E, SOM_RTS); /* create_animation_object_with_explicit_flags */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x142E + (((a_hi << 8) | a) & 0xFE))), SOM_RTS);
    }
}
SOM_REGISTER(0xC21425, SOM_RTS, "gen", dispatch_boss_animation_odd_byte_command, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 9, 4)
