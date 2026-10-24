; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $34FC
dispatch_seven_boss_lifecycle_states:
    lda a:$0094,X
    asl
    tax
    jmp ($3504,X)
