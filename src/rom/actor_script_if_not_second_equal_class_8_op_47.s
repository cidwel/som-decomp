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
.org $12C5
actor_script_if_not_second_equal_class_8_op_47:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_equal_class_8_op_47_c112d1
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    beq actor_script_if_not_second_equal_class_8_op_47_c112d6
actor_script_if_not_second_equal_class_8_op_47_c112d1:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_equal_class_8_op_47_c112d9
actor_script_if_not_second_equal_class_8_op_47_c112d6:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_equal_class_8_op_47_c112d9:
    rts
