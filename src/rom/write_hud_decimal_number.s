; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

divide_hud_number_by_ten = $E3FA

.segment "CODE"
.org $E390
write_hud_decimal_number:
    tay
    sep #$20
    jsr divide_hud_number_by_ten
    sta $01
    stz $00
    ldy a:$4214
    jsr divide_hud_number_by_ten
    sta $02
    lda a:$4214
    bne write_hud_decimal_number_c1e3b6
    bit $08
    bpl write_hud_decimal_number_c1e3af
    inc $09
    bra write_hud_decimal_number_c1e3be
write_hud_decimal_number_c1e3af:
    .a8
    lda #$13
    sta a:$2118
    bra write_hud_decimal_number_c1e3be
write_hud_decimal_number_c1e3b6:
    clc
    .a8
    adc #$08
    sta a:$2118
    dec $00
write_hud_decimal_number_c1e3be:
    lda $02
    bne write_hud_decimal_number_c1e3d5
    bit $00
    bmi write_hud_decimal_number_c1e3d5
    bit $08
    bpl write_hud_decimal_number_c1e3ce
    inc $09
    bra write_hud_decimal_number_c1e3dd
write_hud_decimal_number_c1e3ce:
    .a8
    lda #$13
    sta a:$2118
    bra write_hud_decimal_number_c1e3dd
write_hud_decimal_number_c1e3d5:
    clc
    .a8
    adc #$08
    sta a:$2118
    dec $00
write_hud_decimal_number_c1e3dd:
    lda $01
    clc
    .a8
    adc #$08
    sta a:$2118
    bit $08
    bpl write_hud_decimal_number_c1e3f9
    .a8
    lda #$13
    dec $09
    bmi write_hud_decimal_number_c1e3f9
    sta a:$2118
    dec $09
    bmi write_hud_decimal_number_c1e3f9
    sta a:$2118
write_hud_decimal_number_c1e3f9:
    rts
