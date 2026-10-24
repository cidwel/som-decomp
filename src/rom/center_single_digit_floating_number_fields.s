; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8516
center_single_digit_floating_number_fields:
    rep #$20
    lda $00
    sta $02
    .a16
    lda #$CB00
    sta $00
    rts
