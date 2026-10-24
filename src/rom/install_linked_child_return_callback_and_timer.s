; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5C61
install_linked_child_return_callback_and_timer:
    .a16
    lda #$5C80
    sta a:$0090,X
    .a16
    lda #$5C70
    sta a:$008E,X
    stz a:$0096,X
