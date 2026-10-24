; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_target_eligibility = $054A

ACTOR_ID = $0180

.segment "CODE"
.org $058B
reject_ineligible_or_nonmonster_actor:
    jsr test_actor_target_eligibility
    bne reject_ineligible_or_nonmonster_actor_c10596
    lda a:ACTOR_ID,X
    .a8
    cmp #$80
    rts
reject_ineligible_or_nonmonster_actor_c10596:
    sec
    rts
