; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D7E2
divide_menu_number_using_snes_arithmetic_registers:
    sep #$20
    sty a:$4204
    sta a:$4206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4214
    ldy a:$4216
    rtl
