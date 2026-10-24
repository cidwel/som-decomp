; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_byte_word_divide_by_100 = $543B



.segment "CODE"
.org $52E7
calculate_physical_defence_roll:
    .a8
    lda #$64
    jsl f:$C03884
    cmp $8E
    rep #$20
    bcs calculate_physical_defence_roll_c05309
    lda $94
    lsr
    lsr
    lsr
    lsr
    sep #$20
    jsl f:$C03884
    rep #$20
    .a16
    and #$00FF
    clc
    adc $94
    bra calculate_physical_defence_roll_c0531f
calculate_physical_defence_roll_c05309:
    lda $94
    sta $A8
    lsr
    lsr
    clc
    adc $A8
    sep #$20
    lda $8E
    sta $A6
    jsr multiply_byte_word_divide_by_100
    rep #$20
    lda $A4
calculate_physical_defence_roll_c0531f:
    .a16
    cmp #$03E7
    bcc calculate_physical_defence_roll_c05327
    .a16
    lda #$03E7
calculate_physical_defence_roll_c05327:
    sta $94
    sep #$20
    rts
