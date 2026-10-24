; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-grid.md.
.setcpu "65816"
.smart
.a8
.i16

upload_native_twelve_icon_grid_in_two_vram_blocks = $C94B
upload_one_equipment_preview_row_and_optional_overlay = $C91E

.segment "CODE"
.org $C90B
select_three_row_equipment_preview_or_twelve_icon_grid:
    lda a:$1803
    bpl upload_native_twelve_icon_grid_in_two_vram_blocks
    rep #$20
    .a16
    lda #$6E00
    sta a:$180C
    jsr upload_one_equipment_preview_row_and_optional_overlay
    jsr upload_one_equipment_preview_row_and_optional_overlay
