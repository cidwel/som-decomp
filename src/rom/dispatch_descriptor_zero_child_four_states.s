; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3E27
dispatch_descriptor_zero_child_four_states:
    lda a:$0094,X
    asl
    tax
    jmp ($3E2F,X)
