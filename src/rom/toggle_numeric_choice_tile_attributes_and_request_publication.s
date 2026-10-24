; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c01baa = $1BAA

.segment "CODE"
.org $1B55
toggle_numeric_choice_tile_attributes_and_request_publication:
    jsr routine_c01baa
    .a8
    lda #$00
    xba
    lda a:$A200
    tax
    lda a:$A1D7,X
    sta a:$A173
    lda a:$A1D8,X
    sec
    sbc a:$A173
    tay
    stz a:$A174
    lda a:$A180
    rep #$20
    xba
    lsr
    clc
    .a16
    adc #$0044
    clc
    adc a:$A173
    adc a:$A173
    tax
    sep #$20
toggle_numeric_choice_tile_attributes_and_request_publication_c01b85:
    lda a:$9C01,X
    .a8
    eor #$08
    sta a:$9C01,X
    lda a:$9C41,X
    .a8
    eor #$08
    sta a:$9C41,X
    inx
    inx
    dey
    bne toggle_numeric_choice_tile_attributes_and_request_publication_c01b85
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
    rts
