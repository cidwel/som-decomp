; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7EC3
dispatch_native58_left_child_phase:
    lda a:$0094,X
    asl
    tax
    jmp ($7ECB,X)
