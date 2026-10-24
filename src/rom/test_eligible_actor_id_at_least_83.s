; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_target_eligibility = $054A

ACTOR_ID = $0180

.segment "CODE"
.org $0598
test_eligible_actor_id_at_least_83:
    jsr test_actor_target_eligibility
    bne test_eligible_actor_id_at_least_83_c105a3
    lda a:ACTOR_ID,X
    .a8
    cmp #$83
    rts
test_eligible_actor_id_at_least_83_c105a3:
    clc
    rts
