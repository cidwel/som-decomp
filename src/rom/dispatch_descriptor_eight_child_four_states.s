; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F9C
dispatch_descriptor_eight_child_four_states:
    lda a:$0094,X
    asl
    tax
    jmp ($6FA4,X)
