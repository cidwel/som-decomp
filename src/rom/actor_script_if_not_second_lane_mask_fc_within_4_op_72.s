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
.org $10A7
actor_script_if_not_second_lane_mask_fc_within_4_op_72:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110bd
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    bne actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110bd
    jsr classify_actor_squared_distance
    .a8
    cmp #$04
    beq actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110c2
    bcc actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110c2
actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110bd:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110c5
actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110c2:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_lane_mask_fc_within_4_op_72_c110c5:
    rts
