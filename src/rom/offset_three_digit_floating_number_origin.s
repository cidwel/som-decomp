; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8522
offset_three_digit_floating_number_origin:
    rep #$20
    .a16
    lda #$FFFC
    sta a:$E118,X
    rts
