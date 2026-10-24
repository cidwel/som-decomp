; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $07E0
restore_dialogue_style_or_publish_collapsed_window_band:
    lda a:$CFF8
    beq restore_dialogue_style_or_publish_collapsed_window_band_c007f9
    .a8
    lda #$04
    sta a:$A15E
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda a:$A21B
    sta a:$A24F,X
    bra restore_dialogue_style_or_publish_collapsed_window_band_c00843
restore_dialogue_style_or_publish_collapsed_window_band_c007f9:
    lda a:$A166
    sta a:$A157
    pha
    lda a:$A165
    sta a:$A156
    lda a:$A16C
    sta a:$A164
    pha
restore_dialogue_style_or_publish_collapsed_window_band_c0080d:
    .i16
    ldx #$0120
    phx
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    plx
    inc a:$A157
    dec a:$A164
    bne restore_dialogue_style_or_publish_collapsed_window_band_c0080d
    pla
    sta a:$A164
    pla
    sta a:$A157
    inc a:$A156
restore_dialogue_style_or_publish_collapsed_window_band_c00828:
    .i16
    ldx #$8120
    phx
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    plx
    inc a:$A157
    dec a:$A164
    bne restore_dialogue_style_or_publish_collapsed_window_band_c00828
    inc a:$A15E
    lda a:$A16C
    dec
    dec
    sta a:$A164
restore_dialogue_style_or_publish_collapsed_window_band_c00843:
    rts
