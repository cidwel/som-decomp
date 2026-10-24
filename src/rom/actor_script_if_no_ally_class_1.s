; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_ally_class_1 = $0AEC
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0B23
actor_script_if_no_ally_class_1:
    jsr find_first_eligible_ally_class_1
    .a8
    cmp #$FF
    bne actor_script_if_no_ally_class_1_c10b2f
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_ally_class_1_c10b32
actor_script_if_no_ally_class_1_c10b2f:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_ally_class_1_c10b32:
    rts
