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
.org $12F1
actor_script_if_not_second_within_class_4_op_52:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_within_class_4_op_52_c112ff
    jsr classify_actor_squared_distance
    .a8
    cmp #$04
    beq actor_script_if_not_second_within_class_4_op_52_c11304
    bcc actor_script_if_not_second_within_class_4_op_52_c11304
actor_script_if_not_second_within_class_4_op_52_c112ff:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_within_class_4_op_52_c11307
actor_script_if_not_second_within_class_4_op_52_c11304:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_within_class_4_op_52_c11307:
    rts
