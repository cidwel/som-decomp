; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8374
dispatch_left_native58_linked_effect:
    lda a:$0094,X
    asl
    tax
    jmp ($837C,X)
