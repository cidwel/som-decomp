; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $27E0
configure_native_menu_background_and_scroll_ports:
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$05
    sta a:$2105
    .a8
    lda #$48
    sta a:$2107
    .a8
    lda #$58
    sta a:$2108
    .a8
    lda #$64
    sta a:$210B
    stz a:$210F
    stz a:$210F
    stz a:$2106
    .a8
    lda #$FF
    sta a:$2110
    sta a:$2110
    .a8
    lda #$30
    sta a:$2130
    .a8
    lda #$13
    sta a:$212C
    sta a:$212D
    .a8
    lda #$02
    sta a:$2101
    plb
    rts
