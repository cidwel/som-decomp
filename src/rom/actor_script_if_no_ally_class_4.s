; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_ally_class_4 = $0B7A
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0BB1
actor_script_if_no_ally_class_4:
    jsr find_first_eligible_ally_class_4
    .a8
    cmp #$FF
    bne actor_script_if_no_ally_class_4_c10bbd
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_ally_class_4_c10bc0
actor_script_if_no_ally_class_4_c10bbd:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_ally_class_4_c10bc0:
    rts
