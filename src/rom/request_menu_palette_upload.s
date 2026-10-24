; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CDA9
request_menu_palette_upload:
    sep #$20
    .a8
    lda #$04
    tsb $EC
    rep #$20
    rts
