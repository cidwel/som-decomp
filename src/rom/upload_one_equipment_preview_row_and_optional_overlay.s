; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-grid.md.
.setcpu "65816"
.smart
.a8
.i16

advance_menu_icon_palette_and_select_descriptor_tile = $C979
expand_and_upload_two_native_menu_icon_tile_rows = $C986

.segment "CODE"
.org $C91E
upload_one_equipment_preview_row_and_optional_overlay:
    rep #$20
    jsr advance_menu_icon_palette_and_select_descriptor_tile
    lda a:$180C
    pha
    clc
    .a16
    adc #$01E0
    sta a:$180C
    phx
    dex
    dex
    lda $00,X
    .a16
    cmp #$FFFF
    beq upload_one_equipment_preview_row_and_optional_overlay_d0c945
    lda $20,X
    .a16
    and #$FF00
    beq upload_one_equipment_preview_row_and_optional_overlay_d0c945
    lda $00,X
    inc
    jsr expand_and_upload_two_native_menu_icon_tile_rows
upload_one_equipment_preview_row_and_optional_overlay_d0c945:
    plx
    pla
    sta a:$180C
    rts
