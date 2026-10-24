; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-music-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FD10
copy_fifteen_colors_from_hardware_multiplied_palette_index:
    sep #$20
    sta a:$4202
    .a8
    lda #$1E
    sta a:$4203
    .a8
    lda #$0F
    sta $00
    stz $01
    rep #$20
    ldx a:$4216
copy_fifteen_colors_from_hardware_multiplied_palette_index_c1fd25:
    lda f:$C81000,X
    sta a:$0700,Y
    iny
    iny
    inx
    inx
    dec $00
    bne copy_fifteen_colors_from_hardware_multiplied_palette_index_c1fd25
    sep #$20
    rts
