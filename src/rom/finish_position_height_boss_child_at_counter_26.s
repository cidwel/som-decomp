; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-definitions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6CC2
finish_position_height_boss_child_at_counter_26:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0026
    rts
