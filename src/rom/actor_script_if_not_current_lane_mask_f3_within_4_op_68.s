; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_actor_direction_codes = $0404
classify_actor_squared_distance = $0358
jump_actor_script_after_1_bytes = $0285
resolve_visible_current_actor_target = $05A5
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0F90
actor_script_if_not_current_lane_mask_f3_within_4_op_68:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fa6
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$F3
    bne actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fa6
    jsr classify_actor_squared_distance
    .a8
    cmp #$04
    beq actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fab
    bcc actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fab
actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fa6:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fae
actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fab:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_lane_mask_f3_within_4_op_68_c10fae:
    rts
