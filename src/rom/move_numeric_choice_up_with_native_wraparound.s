; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

toggle_numeric_choice_tile_attributes_and_request_publication = $1B55

.segment "CODE"
.org $1B20
move_numeric_choice_up_with_native_wraparound:
    bne move_numeric_choice_up_with_native_wraparound_c01b3a
    pha
    jsr toggle_numeric_choice_tile_attributes_and_request_publication
    lda a:$A200
    dec
    .a8
    cmp #$FF
    bne move_numeric_choice_up_with_native_wraparound_c01b32
    lda a:$A1D4
    dec
move_numeric_choice_up_with_native_wraparound_c01b32:
    sta a:$A200
    tay
    jsr toggle_numeric_choice_tile_attributes_and_request_publication
    pla
move_numeric_choice_up_with_native_wraparound_c01b3a:
    rts
