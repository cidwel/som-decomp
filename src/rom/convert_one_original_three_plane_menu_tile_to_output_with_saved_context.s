; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-single-icon.md.
.setcpu "65816"
.smart
.a8
.i16

convert_native_menu_icon_pixels_with_selected_palette_base = $CAD6
normalize_menu_native_direct_page_and_bank = $C064A4
routine_d0c868 = $C868

.segment "CODE"
.org $CA10
convert_one_original_three_plane_menu_tile_to_output_with_saved_context:
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    rep #$30
    sep #$20
    phx
    sta a:$1810
    sty a:$1820
    .i16
    ldy #$18C0
    .a8
    lda #$08
convert_one_original_three_plane_menu_tile_to_output_with_saved_context_d0ca27:
    pha
    lda f:$D40000,X
    sta a:$0000,Y
    inx
    lda f:$D40000,X
    sta a:$0001,Y
    inx
    lda f:$D40000,X
    sta a:$0010,Y
    inx
    iny
    iny
    pla
    dec
    bne convert_one_original_three_plane_menu_tile_to_output_with_saved_context_d0ca27
    jsr convert_native_menu_icon_pixels_with_selected_palette_base
    rep #$30
    ldx a:$1820
    .i16
    ldy #$18E0
    .a16
    lda #$0010
convert_one_original_three_plane_menu_tile_to_output_with_saved_context_d0ca54:
    pha
    lda a:$0000,Y
    sta f:$7E0000,X
    inx
    inx
    iny
    iny
    pla
    dec
    bne convert_one_original_three_plane_menu_tile_to_output_with_saved_context_d0ca54
    txy
    pla
    clc
    .a16
    adc #$0018
    tax
    jmp routine_d0c868
