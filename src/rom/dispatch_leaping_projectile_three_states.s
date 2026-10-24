; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7456
dispatch_leaping_projectile_three_states:
    lda a:$0094,X
    asl
    tax
    jmp ($745E,X)
