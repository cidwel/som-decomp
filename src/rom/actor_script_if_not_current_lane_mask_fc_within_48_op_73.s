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
.org $100C
actor_script_if_not_current_lane_mask_fc_within_48_op_73:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11022
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    bne actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11022
    jsr classify_actor_squared_distance
    .a8
    cmp #$30
    beq actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11027
    bcc actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11027
actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11022:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_lane_mask_fc_within_48_op_73_c1102a
actor_script_if_not_current_lane_mask_fc_within_48_op_73_c11027:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_lane_mask_fc_within_48_op_73_c1102a:
    rts
