; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-definitions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6D6F
dispatch_target_tracking_boss_child_two_states:
    ldx $87
    lda a:$0094,X
    asl
    tax
    jmp ($6D79,X)
