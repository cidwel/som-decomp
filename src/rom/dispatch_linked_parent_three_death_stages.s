; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-phases.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $59DD
dispatch_linked_parent_three_death_stages:
    lda a:$0094,X
    asl
    tax
    jmp ($59E5,X)
