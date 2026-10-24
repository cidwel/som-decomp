; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
classify_actor_squared_distance = $0358
jump_actor_script_after_1_bytes = $0285
resolve_visible_second_actor_target = $05BA
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $1069
actor_script_if_not_second_lane_mask_f3_within_48_op_6b:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c1107f
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$F3
    bne actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c1107f
    jsr classify_actor_squared_distance
    .a8
    cmp #$30
    beq actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c11084
    bcc actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c11084
actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c1107f:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c11087
actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c11084:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_lane_mask_f3_within_48_op_6b_c11087:
    rts
