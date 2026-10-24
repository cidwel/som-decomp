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
.org $0FCE
actor_script_if_not_current_lane_mask_fc_within_8_op_6f:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe4
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    bne actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe4
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    beq actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe9
    bcc actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe9
actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe4:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fec
actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fe9:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_lane_mask_fc_within_8_op_6f_c10fec:
    rts
