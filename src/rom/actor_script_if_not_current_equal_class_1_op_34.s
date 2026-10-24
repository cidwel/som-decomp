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
.org $1195
actor_script_if_not_current_equal_class_1_op_34:
    jsr resolve_visible_current_actor_target
    bne actor_script_if_not_current_equal_class_1_op_34_c111a1
    jsr classify_actor_squared_distance
    .a8
    cmp #$01
    beq actor_script_if_not_current_equal_class_1_op_34_c111a6
actor_script_if_not_current_equal_class_1_op_34_c111a1:
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_not_current_equal_class_1_op_34_c111a9
actor_script_if_not_current_equal_class_1_op_34_c111a6:
    jsr skip_actor_script_after_1_bytes
actor_script_if_not_current_equal_class_1_op_34_c111a9:
    rts
