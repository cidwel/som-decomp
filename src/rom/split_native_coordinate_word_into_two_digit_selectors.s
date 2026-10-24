; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-coordinates.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DEE1
split_native_coordinate_word_into_two_digit_selectors:
    rep #$30
    pha
    lsr
    lsr
    lsr
    lsr
    tay
    pla
    xba
    rts
