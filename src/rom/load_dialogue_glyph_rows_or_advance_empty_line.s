; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-font-rows.md.
.setcpu "65816"
.smart
.a8
.i16

advance_empty_dialogue_line_and_reset_render_origin = $13CD

.segment "CODE"
.org $1664
load_dialogue_glyph_rows_or_advance_empty_line:
    lda a:$A1CE
    .a8
    and #$7F
    bne load_dialogue_glyph_rows_or_advance_empty_line_c0167d
    lda f:$001D05
    .a8
    cmp #$05
    beq load_dialogue_glyph_rows_or_advance_empty_line_c0167d
    jsr advance_empty_dialogue_line_and_reset_render_origin
    .a8
    lda #$07
    sta a:$A15D
    bra load_dialogue_glyph_rows_or_advance_empty_line_c016b7
load_dialogue_glyph_rows_or_advance_empty_line_c0167d:
    .a8
    lda #$20
    sta a:$A176
    .i16
    ldx #$0000
    txy
load_dialogue_glyph_rows_or_advance_empty_line_c01686:
    lda a:$A1A4,X
    inx
    phx
    rep #$20
    .a16
    and #$00FF
    sec
    .a16
    sbc #$0080
    asl
    asl
    sta a:$A1C7
    asl
    clc
    adc a:$A1C7
    tax
    sep #$20
    .a8
    lda #$0C
load_dialogue_glyph_rows_or_advance_empty_line_c016a3:
    xba
    lda f:$D2DC00,X
    sta a:$9000,Y
    iny
    inx
    xba
    dec
    bne load_dialogue_glyph_rows_or_advance_empty_line_c016a3
    plx
    dec a:$A176
    bne load_dialogue_glyph_rows_or_advance_empty_line_c01686
load_dialogue_glyph_rows_or_advance_empty_line_c016b7:
    rts
