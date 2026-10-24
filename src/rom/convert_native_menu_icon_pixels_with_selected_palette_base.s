; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CAD6
convert_native_menu_icon_pixels_with_selected_palette_base:
    sep #$20
    .i16
    ldx #$18C0
    .a8
    lda #$08
convert_native_menu_icon_pixels_with_selected_palette_base_d0cadd:
    pha
    .a8
    lda #$08
convert_native_menu_icon_pixels_with_selected_palette_base_d0cae0:
    pha
    .a8
    lda #$00
    clc
    rol
    asl $10,X
    rol
    asl $01,X
    rol
    asl $00,X
    rol
    .a8
    cmp #$07
    bne convert_native_menu_icon_pixels_with_selected_palette_base_d0caf6
    .a8
    lda #$00
    bra convert_native_menu_icon_pixels_with_selected_palette_base_d0cafa
convert_native_menu_icon_pixels_with_selected_palette_base_d0caf6:
    clc
    adc a:$1810
convert_native_menu_icon_pixels_with_selected_palette_base_d0cafa:
    lsr
    rol $20,X
    lsr
    rol $21,X
    lsr
    rol $30,X
    lsr
    rol $31,X
    pla
    dec
    bne convert_native_menu_icon_pixels_with_selected_palette_base_d0cae0
    inx
    inx
    pla
    dec
    bne convert_native_menu_icon_pixels_with_selected_palette_base_d0cadd
    rts
