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
.org $122E
actor_script_if_not_current_within_class_48_op_59:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_within_class_48_op_59_c1123c
    jsr classify_actor_squared_distance
    .a8
    cmp #$30
    beq actor_script_if_not_current_within_class_48_op_59_c11241
    bcc actor_script_if_not_current_within_class_48_op_59_c11241
actor_script_if_not_current_within_class_48_op_59_c1123c:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_within_class_48_op_59_c11244
actor_script_if_not_current_within_class_48_op_59_c11241:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_within_class_48_op_59_c11244:
    rts
