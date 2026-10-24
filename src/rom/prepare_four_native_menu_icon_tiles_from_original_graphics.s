; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16

expand_one_native_menu_icon_tile_into_output_rows = $CA8B

.segment "CODE"
.org $CA6E
prepare_four_native_menu_icon_tiles_from_original_graphics:
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    asl
    pha
    asl
    clc
    adc $01,S
    tax
    pla
    .i16
    ldy #$1900
    jsr expand_one_native_menu_icon_tile_into_output_rows
    jsr expand_one_native_menu_icon_tile_into_output_rows
    jsr expand_one_native_menu_icon_tile_into_output_rows
