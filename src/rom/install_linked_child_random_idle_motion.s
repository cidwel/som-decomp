; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5CC8
install_linked_child_random_idle_motion:
    inc a:$00B8,X
    .a16
    lda #$5CD9
    sta a:$0090,X
    .a16
    lda #$5CD7
    sta a:$008E,X
