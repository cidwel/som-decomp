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
.org $12DA
actor_script_if_not_second_within_class_2_op_4d:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_within_class_2_op_4d_c112e8
    jsr classify_actor_squared_distance
    .a8
    cmp #$02
    beq actor_script_if_not_second_within_class_2_op_4d_c112ed
    bcc actor_script_if_not_second_within_class_2_op_4d_c112ed
actor_script_if_not_second_within_class_2_op_4d_c112e8:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_within_class_2_op_4d_c112f0
actor_script_if_not_second_within_class_2_op_4d_c112ed:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_within_class_2_op_4d_c112f0:
    rts
