; Recovered Secret of Mana USA routine; behaviour documented in docs/map-camera-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FD37
shift_and_align_three_party_horizontal_positions:
    rep #$20
    lda f:$7EE002
    sec
    .a16
    sbc #$0400
    sta f:$7EE002
    sta f:$7EE202
    sta f:$7EE402
    rtl
