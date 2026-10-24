; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

toggle_numeric_choice_tile_attributes_and_request_publication = $1B55

.segment "CODE"
.org $1A52
initialize_numeric_choice_controller_and_highlight:
    .i16
    ldx #$0003
initialize_numeric_choice_controller_and_highlight_c01a55:
    lda $D8,X
    .a8
    and #$80
    bne initialize_numeric_choice_controller_and_highlight_c01a5f
    dex
    bne initialize_numeric_choice_controller_and_highlight_c01a55
    inx
initialize_numeric_choice_controller_and_highlight_c01a5f:
    dex
    .a8
    lda #$00
    xba
    txa
    asl
    tax
    stx a:$A182
    stz a:$A200
    jsr toggle_numeric_choice_tile_attributes_and_request_publication
    stz a:$A201
    inc a:$A160
    rts
