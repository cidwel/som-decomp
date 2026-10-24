; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-animation-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $31D4
dispatch_animation_created_linked_child_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($31DC,X)
