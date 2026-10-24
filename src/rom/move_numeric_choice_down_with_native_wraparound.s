; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

toggle_numeric_choice_tile_attributes_and_request_publication = $1B55

.segment "CODE"
.org $1B3B
move_numeric_choice_down_with_native_wraparound:
    bne move_numeric_choice_down_with_native_wraparound_c01b54
    pha
    jsr toggle_numeric_choice_tile_attributes_and_request_publication
    lda a:$A200
    inc
    cmp a:$A1D4
    bcc move_numeric_choice_down_with_native_wraparound_c01b4c
    .a8
    lda #$00
move_numeric_choice_down_with_native_wraparound_c01b4c:
    sta a:$A200
    tay
    jsr toggle_numeric_choice_tile_attributes_and_request_publication
    pla
move_numeric_choice_down_with_native_wraparound_c01b54:
    rts
