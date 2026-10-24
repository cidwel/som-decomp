; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child-follow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $311D
dispatch_parent_linked_boss_effect_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($3125,X)
