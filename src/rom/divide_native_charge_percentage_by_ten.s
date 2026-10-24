; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-gauge-presentation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ECF1
divide_native_charge_percentage_by_ten:
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
    .a8
    lda #$0A
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    rts
