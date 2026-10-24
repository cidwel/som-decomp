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
.org $12B0
actor_script_if_not_second_equal_class_4_op_41:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_equal_class_4_op_41_c112bc
    jsr classify_actor_squared_distance
    .a8
    cmp #$04
    beq actor_script_if_not_second_equal_class_4_op_41_c112c1
actor_script_if_not_second_equal_class_4_op_41_c112bc:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_equal_class_4_op_41_c112c4
actor_script_if_not_second_equal_class_4_op_41_c112c1:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_equal_class_4_op_41_c112c4:
    rts
