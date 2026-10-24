; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller-pool.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3ED6
dispatch_homing_projectile_two_states:
    ldx $87
    lda a:$0094,X
    asl
    tax
    jmp ($3EE0,X)
