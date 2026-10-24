; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_1_bytes = $0285
resolve_visible_current_actor_target = $05A5
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $11E9
actor_script_if_not_current_within_class_2_op_4c:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_within_class_2_op_4c_c111f7
    jsr classify_actor_squared_distance
    .a8
    cmp #$02
    beq actor_script_if_not_current_within_class_2_op_4c_c111fc
    bcc actor_script_if_not_current_within_class_2_op_4c_c111fc
actor_script_if_not_current_within_class_2_op_4c_c111f7:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_within_class_2_op_4c_c111ff
actor_script_if_not_current_within_class_2_op_4c_c111fc:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_within_class_2_op_4c_c111ff:
    rts
