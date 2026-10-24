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
.org $125A
actor_script_if_not_second_within_class_48_op_5b:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_within_class_48_op_5b_c11268
    jsr classify_actor_squared_distance
    .a8
    cmp #$30
    beq actor_script_if_not_second_within_class_48_op_5b_c1126d
    bcc actor_script_if_not_second_within_class_48_op_5b_c1126d
actor_script_if_not_second_within_class_48_op_5b_c11268:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_within_class_48_op_5b_c11270
actor_script_if_not_second_within_class_48_op_5b_c1126d:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_within_class_48_op_5b_c11270:
    rts
