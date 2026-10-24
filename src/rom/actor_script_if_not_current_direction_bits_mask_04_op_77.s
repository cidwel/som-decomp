; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
jump_actor_script_after_1_bytes = $0285
resolve_visible_current_actor_target = $05A5
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $10FB
actor_script_if_not_current_direction_bits_mask_04_op_77:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_direction_bits_mask_04_op_77_c11108
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$04
    bne actor_script_if_not_current_direction_bits_mask_04_op_77_c1110d
actor_script_if_not_current_direction_bits_mask_04_op_77_c11108:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_direction_bits_mask_04_op_77_c11110
actor_script_if_not_current_direction_bits_mask_04_op_77_c1110d:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_direction_bits_mask_04_op_77_c11110:
    rts
