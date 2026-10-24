; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E3FA
divide_hud_number_by_ten:
    sty a:$4204
    .a8
    lda #$0A
    sta a:$4206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4216
    rts
