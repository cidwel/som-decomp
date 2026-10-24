; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16

locate_native_menu_icon_palette_page = $CD18

.segment "CODE"
.org $CBD6
cache_selected_native_menu_icon_palette_page:
    rep #$20
    stz a:$1810
    stz a:$1820
    jsr locate_native_menu_icon_palette_page
    tay
    .i16
    ldx #$0000
cache_selected_native_menu_icon_palette_page_d0cbe5:
    lda a:$0000,Y
    sta f:$7E8100,X
    inx
    inx
    iny
    iny
    .i16
    cpx #$0080
    bcc cache_selected_native_menu_icon_palette_page_d0cbe5
    rts
