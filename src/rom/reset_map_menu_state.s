; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0EBF
reset_map_menu_state:
    pha
    phb
    php
    sep #$20
    rep #$10
    .a8
    lda #$7E
    pha
    plb
    lda a:$A196
    sta a:$A17C
    lda a:$A197
    sta a:$A17D
    .i16
    ldx #$0122
    stx a:$A17E
    stz a:$A15C
    stz a:$A15D
    stz a:$A15E
    stz a:$A15F
    stz a:$A16D
    stz a:$A160
    stz a:$A170
    stz a:$A181
    stz a:$A1D0
    stz a:$A1A4
    lda f:$001D10
    .a8
    and #$FE
    sta f:$001D10
    plp
    plb
    pla
    rtl
