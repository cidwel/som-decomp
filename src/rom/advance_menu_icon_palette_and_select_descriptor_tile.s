; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_menu_icon_palette_base_modulo_fifteen = $C9FC
expand_and_upload_two_native_menu_icon_tile_rows = $C986

.segment "CODE"
.org $C979
advance_menu_icon_palette_and_select_descriptor_tile:
    jsr advance_native_menu_icon_palette_base_modulo_fifteen
    sep #$20
    lda $00,X
    .a8
    cmp #$FF
    bne expand_and_upload_two_native_menu_icon_tile_rows
    .a8
    lda #$00
