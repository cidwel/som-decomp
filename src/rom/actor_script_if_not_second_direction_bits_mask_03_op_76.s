; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
jump_actor_script_after_1_bytes = $0285
resolve_visible_second_actor_target = $05BA
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $113D
actor_script_if_not_second_direction_bits_mask_03_op_76:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_direction_bits_mask_03_op_76_c1114a
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$03
    bne actor_script_if_not_second_direction_bits_mask_03_op_76_c1114f
actor_script_if_not_second_direction_bits_mask_03_op_76_c1114a:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_direction_bits_mask_03_op_76_c11152
actor_script_if_not_second_direction_bits_mask_03_op_76_c1114f:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_direction_bits_mask_03_op_76_c11152:
    rts
