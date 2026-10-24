; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5AFC
install_linked_child_periodic_motion_and_idle_definition:
    .a16
    lda #$5B10
    sta a:$0090,X
    stz a:$0049,X
    .a16
    lda #$5B0E
    sta a:$008E,X
    stz a:$0096,X
