; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CBA2
read_native_icon_color_or_disabled_row_color:
    lda f:$D2C900,X
    phx
    pha
    ldx a:$1820
    lda $00,X
    .a16
    and #$4000
    beq read_native_icon_color_or_disabled_row_color_d0cbbb
    lda $03,S
    tax
    lda f:$D0CBCC,X
    sta $01,S
read_native_icon_color_or_disabled_row_color_d0cbbb:
    pla
    plx
    inx
    inx
