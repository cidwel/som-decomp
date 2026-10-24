; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-grid.md.
.setcpu "65816"
.smart
.a8
.i16

select_three_row_equipment_preview_or_twelve_icon_grid = $C90B

.segment "CODE"
.org $C8FB
publish_native_menu_icon_grid_or_equipment_preview:
    rep #$10
    sep #$20
    .a8
    lda #$FB
    sta a:$1810
    .i16
    ldx #$1880
    jsr select_three_row_equipment_preview_or_twelve_icon_grid
    rtl
