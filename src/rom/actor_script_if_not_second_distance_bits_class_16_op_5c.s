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
.org $1271
actor_script_if_not_second_distance_bits_class_16_op_5c:
    jsr resolve_visible_second_actor_target
    bne actor_script_if_not_second_distance_bits_class_16_op_5c_c1127d
    jsr classify_actor_squared_distance
    .a8
    bit #$10
    bne actor_script_if_not_second_distance_bits_class_16_op_5c_c11282
actor_script_if_not_second_distance_bits_class_16_op_5c_c1127d:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_second_distance_bits_class_16_op_5c_c11285
actor_script_if_not_second_distance_bits_class_16_op_5c_c11282:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_second_distance_bits_class_16_op_5c_c11285:
    rts
