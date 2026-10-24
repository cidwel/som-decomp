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
.org $1245
actor_script_if_not_current_distance_bits_class_16_op_5a:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_distance_bits_class_16_op_5a_c11251
    jsr classify_actor_squared_distance
    .a8
    bit #$10
    bne actor_script_if_not_current_distance_bits_class_16_op_5a_c11256
actor_script_if_not_current_distance_bits_class_16_op_5a_c11251:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_distance_bits_class_16_op_5a_c11259
actor_script_if_not_current_distance_bits_class_16_op_5a_c11256:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_distance_bits_class_16_op_5a_c11259:
    rts
