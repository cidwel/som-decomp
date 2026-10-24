; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

advance_dialogue_window_graphics_pointer = $1257
copy_dialogue_window_rows_with_upload_padding = $1235

.segment "CODE"
.org $11CB
publish_dialogue_window_rows_and_advance_phase:
    .a8
    lda #$06
    xba
    lda a:$A181
    beq publish_dialogue_window_rows_and_advance_phase_c011da
    .a8
    cmp #$03
    beq publish_dialogue_window_rows_and_advance_phase_c011da
    .a8
    lda #$08
    xba
publish_dialogue_window_rows_and_advance_phase_c011da:
    xba
    sta a:$A175
    pha
    ldy a:$A189
    .i16
    ldx #$9400
    jsr copy_dialogue_window_rows_with_upload_padding
    rep #$20
    lda a:$A189
    clc
    .a16
    adc #$0010
    tay
    sep #$20
    pla
    sta a:$A175
    jsr copy_dialogue_window_rows_with_upload_padding
    jsr advance_dialogue_window_graphics_pointer
    rep #$20
    lda a:$A181
    .a16
    and #$00FF
    asl
    tax
    lda f:$C01A36,X
    sta f:$001D06
    lda f:$C01A3E,X
    sta f:$001D08
    .a16
    lda #$0100
    sta f:$001D18
    sep #$20
    inc a:$A181
    .a8
    lda #$04
    cmp a:$A181
    bne publish_dialogue_window_rows_and_advance_phase_c01234
    stz a:$A181
    inc a:$A15D
    inc a:$A15D
publish_dialogue_window_rows_and_advance_phase_c01234:
    rts
