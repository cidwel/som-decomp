; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-definitions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C9F
dispatch_position_height_boss_child_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($6CA7,X)
