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
.org $1217
actor_script_if_not_current_within_class_8_op_56:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_within_class_8_op_56_c11225
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    beq actor_script_if_not_current_within_class_8_op_56_c1122a
    bcc actor_script_if_not_current_within_class_8_op_56_c1122a
actor_script_if_not_current_within_class_8_op_56_c11225:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_within_class_8_op_56_c1122d
actor_script_if_not_current_within_class_8_op_56_c1122a:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_within_class_8_op_56_c1122d:
    rts
