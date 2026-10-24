; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

classify_actor_squared_distance = $0358
jump_actor_script_after_1_bytes = $0285
resolve_visible_second_actor_target = $05BA
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $129B
actor_script_if_not_second_equal_class_2_op_3b:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_equal_class_2_op_3b_c112a7
    jsr classify_actor_squared_distance
    .a8
    cmp #$02
    beq actor_script_if_not_second_equal_class_2_op_3b_c112ac
actor_script_if_not_second_equal_class_2_op_3b_c112a7:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_equal_class_2_op_3b_c112af
actor_script_if_not_second_equal_class_2_op_3b_c112ac:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_equal_class_2_op_3b_c112af:
    rts
