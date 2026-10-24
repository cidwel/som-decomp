; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-target-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $578A
test_whether_either_linked_boss_child_has_state_word_81:
    ldy a:$00B0,X
    lda a:$0081,Y
    bne test_whether_either_linked_boss_child_has_state_word_81_c2579c
    ldy a:$00B2,X
    lda a:$0081,Y
    bne test_whether_either_linked_boss_child_has_state_word_81_c2579c
    clc
    rts
test_whether_either_linked_boss_child_has_state_word_81_c2579c:
    sec
    rts
