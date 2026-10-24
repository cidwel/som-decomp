; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $50BA
dispatch_native54_palette_transition_effect:
    lda a:$0094,X
    asl
    tax
    jmp ($50C2,X)
