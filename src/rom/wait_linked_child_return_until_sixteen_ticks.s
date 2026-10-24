; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5C70
wait_linked_child_return_until_sixteen_ticks:
    lda a:$0096,X
    .a16
    cmp #$0010
    bcc wait_linked_child_return_until_sixteen_ticks_c25c7e
    .a16
    lda #$5CC8
    sta a:$008E,X
wait_linked_child_return_until_sixteen_ticks_c25c7e:
    clc
    rts
