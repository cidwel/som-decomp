; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_map_object_palette_row = $C568

.segment "CODE"
.org $C524
select_map_object_palette_rows:
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    pha
    .a8
    cmp #$FF
    .a8
    lda #$00
    ror
    sta $ED
    pla
    rep #$30
    .a16
    and #$007F
    asl
    asl
    tax
    lda f:$C82E00,X
    .i16
    ldy #$0082
    jsr copy_map_object_palette_row
    lda f:$C82E01,X
    .i16
    ldy #$00A2
    jsr copy_map_object_palette_row
    lda f:$C82E02,X
    .i16
    ldy #$00C2
    jsr copy_map_object_palette_row
    lda f:$C82E03,X
    .i16
    ldy #$00E2
    jsr copy_map_object_palette_row
    plb
    rts
