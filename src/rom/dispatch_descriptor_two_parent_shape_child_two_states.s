; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4091
dispatch_descriptor_two_parent_shape_child_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($4099,X)
