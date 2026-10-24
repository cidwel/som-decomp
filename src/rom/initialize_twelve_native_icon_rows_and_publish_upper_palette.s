; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-order.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_descriptor_row_attributes = $D308
select_upper_icon_palette_page_then_fall_through = $CB2C

.segment "CODE"
.org $CB11
initialize_twelve_native_icon_rows_and_publish_upper_palette:
    sep #$20
    .a8
    lda #$0C
    sta a:$180B
    jsr clear_native_menu_descriptor_row_attributes
    rep #$30
    bra select_upper_icon_palette_page_then_fall_through
