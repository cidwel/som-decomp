; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CBBF
append_one_native_icon_palette_color:
    phx
    ldx a:$1822
    sta $00,X
    inx
    inx
    stx a:$1822
    plx
    rts
