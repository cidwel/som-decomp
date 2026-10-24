; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CD18
locate_native_menu_icon_palette_page:
    rep #$20
    lda a:$1802
    xba
    .a16
    and #$0100
    lsr
    clc
    .a16
    adc #$0700
    rts
