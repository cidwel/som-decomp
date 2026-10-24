; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5B74
terminate_linked_child_when_parent_reaches_state_two:
    stz a:$0090,X
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0002
    bne terminate_linked_child_when_parent_reaches_state_two_c25b84
    sec
    rts
terminate_linked_child_when_parent_reaches_state_two_c25b84:
    clc
    rts
