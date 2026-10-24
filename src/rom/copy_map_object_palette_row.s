; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C568
copy_map_object_palette_row:
    phx
    sep #$20
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    .a8
    lda #$0F
    sta $00
    stz $01
    rep #$20
    lda $98
    beq copy_map_object_palette_row_c0c586
    tya
    .a16
    eor #$0080
    tay
copy_map_object_palette_row_c0c586:
    lda f:$004216
    tax
copy_map_object_palette_row_c0c58b:
    lda f:$C81000,X
    sta a:$0700,Y
    sta a:$DF00,Y
    iny
    iny
    inx
    inx
    dec $00
    bne copy_map_object_palette_row_c0c58b
    plx
    rts
