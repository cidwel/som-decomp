; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E38
dispatch_descriptor_eleven_height_child_three_states:
    lda a:$0094,X
    asl
    tax
    jmp ($8E40,X)
