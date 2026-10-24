; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16

assemble_native_icon_palette_rows_and_cache_page = $CB2F

.segment "CODE"
.org $CB1F
choose_native_icon_palette_page_from_menu_mode:
    rep #$30
    .i16
    ldx #$0702
    lda a:$1802
    .a16
    and #$0001
    beq assemble_native_icon_palette_rows_and_cache_page
