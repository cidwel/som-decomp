; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

find_first_eligible_ally_within_class_2 = $0C08
jump_actor_script_after_1_bytes = $0285
skip_actor_script_after_1_bytes = $0213

.segment "CODE"
.org $0C41
actor_script_if_no_ally_within_class_2:
    jsr find_first_eligible_ally_within_class_2
    .a8
    cmp #$FF
    bne actor_script_if_no_ally_within_class_2_c10c4d
    jsr jump_actor_script_after_1_bytes
    bra actor_script_if_no_ally_within_class_2_c10c50
actor_script_if_no_ally_within_class_2_c10c4d:
    jsr skip_actor_script_after_1_bytes
actor_script_if_no_ally_within_class_2_c10c50:
    rts
