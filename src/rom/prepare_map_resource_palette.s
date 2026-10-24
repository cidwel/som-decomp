; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F62D
prepare_map_resource_palette:
    sep #$30
    lda $1B
    .a8
    and #$7F
    sta a:$4202
    .a8
    lda #$D2
    sta a:$4203
    rep #$20
    .a16
    lda #$0000
    tax
prepare_map_resource_palette_c1f641:
    sta a:$0600,X
    inx
    inx
    .i8
    cpx #$20
    bcc prepare_map_resource_palette_c1f641
    rep #$10
    .i16
    ldy #$0022
    .a16
    lda #$000F
    sta $00
    ldx a:$4216
prepare_map_resource_palette_c1f657:
    lda f:$CC8000,X
    sta a:$0600,Y
    inx
    inx
    iny
    iny
    dec $00
    bne prepare_map_resource_palette_c1f657
    .a16
    lda #$000F
    sta $00
    iny
    iny
    .i16
    cpy #$0100
    bcc prepare_map_resource_palette_c1f657
    lda $E8
    lsr
    bcc prepare_map_resource_palette_c1f686
    .i16
    ldx #$001E
prepare_map_resource_palette_c1f67a:
    lda f:$C675B0,X
    sta a:$0600,X
    dex
    dex
    bne prepare_map_resource_palette_c1f67a
    rts
prepare_map_resource_palette_c1f686:
    lda a:$010E
    beq prepare_map_resource_palette_c1f69a
    .i16
    ldx #$0002
prepare_map_resource_palette_c1f68e:
    lda f:$D27E00,X
    sta a:$0604,X
    dex
    dex
    bpl prepare_map_resource_palette_c1f68e
    rts
prepare_map_resource_palette_c1f69a:
    rts
