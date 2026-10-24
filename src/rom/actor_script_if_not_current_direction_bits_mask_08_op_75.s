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
.org $10E5
actor_script_if_not_current_direction_bits_mask_08_op_75:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_direction_bits_mask_08_op_75_c110f2
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$08
    bne actor_script_if_not_current_direction_bits_mask_08_op_75_c110f7
actor_script_if_not_current_direction_bits_mask_08_op_75_c110f2:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_direction_bits_mask_08_op_75_c110fa
actor_script_if_not_current_direction_bits_mask_08_op_75_c110f7:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_direction_bits_mask_08_op_75_c110fa:
    rts
