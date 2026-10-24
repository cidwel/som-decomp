; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5354
dispatch_descriptor_fourteen_linked_child_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($535C,X)
