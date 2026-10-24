; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6610
dispatch_descriptor_nine_collision_child_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($6618,X)
