; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16

convert_native_menu_icon_pixels_with_selected_palette_base = $CAD6

.segment "CODE"
.org $CA8B
expand_one_native_menu_icon_tile_into_output_rows:
    rep #$30
    phx
    sep #$20
    phy
    .i16
    ldy #$18C0
    .a8
    lda #$08
expand_one_native_menu_icon_tile_into_output_rows_d0ca96:
    pha
    lda f:$D28400,X
    sta a:$0000,Y
    inx
    lda f:$D28400,X
    sta a:$0001,Y
    inx
    lda f:$D28400,X
    sta a:$0010,Y
    inx
    iny
    iny
    pla
    dec
    bne expand_one_native_menu_icon_tile_into_output_rows_d0ca96
    ply
    jsr convert_native_menu_icon_pixels_with_selected_palette_base
    rep #$30
    .i16
    ldx #$18E0
    .a16
    lda #$0010
expand_one_native_menu_icon_tile_into_output_rows_d0cac1:
    pha
    lda $00,X
    sta a:$0000,Y
    inx
    inx
    iny
    iny
    pla
    dec
    bne expand_one_native_menu_icon_tile_into_output_rows_d0cac1
    pla
    clc
    .a16
    adc #$0018
    tax
    rts
