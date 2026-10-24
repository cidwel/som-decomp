; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-right-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8009
dispatch_native58_right_child_phase:
    lda a:$0094,X
    asl
    tax
    jmp ($8011,X)
