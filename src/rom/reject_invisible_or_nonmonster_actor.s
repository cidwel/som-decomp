; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_on_screen = $0526

ACTOR_ID = $0180

.segment "CODE"
.org $057E
reject_invisible_or_nonmonster_actor:
    jsr test_actor_on_screen
    bne reject_invisible_or_nonmonster_actor_c10589
    lda a:ACTOR_ID,X
    .a8
    cmp #$80
    rts
reject_invisible_or_nonmonster_actor_c10589:
    sec
    rts
