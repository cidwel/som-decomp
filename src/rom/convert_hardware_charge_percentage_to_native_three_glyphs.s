; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-gauge-presentation.md.
.setcpu "65816"
.smart
.a8
.i16

divide_native_charge_percentage_by_ten = $ECF1

.segment "CODE"
.org $ECB1
convert_hardware_charge_percentage_to_native_three_glyphs:
    .a8
    lda #$0B
    sta $00
    sta $01
    sta $02
    .a8
    lda #$65
    sec
    sbc f:$004214
    .a8
    cmp #$65
    bcc convert_hardware_charge_percentage_to_native_three_glyphs_c0ecc6
    .a8
    lda #$64
convert_hardware_charge_percentage_to_native_three_glyphs_c0ecc6:
    .a8
    cmp #$0A
    bcs convert_hardware_charge_percentage_to_native_three_glyphs_c0eccd
    sta $00
    rts
convert_hardware_charge_percentage_to_native_three_glyphs_c0eccd:
    jsr divide_native_charge_percentage_by_ten
    lda f:$004216
    sta $00
    lda f:$004214
    .a8
    cmp #$0A
    bcs convert_hardware_charge_percentage_to_native_three_glyphs_c0ece1
    sta $01
    rts
convert_hardware_charge_percentage_to_native_three_glyphs_c0ece1:
    jsr divide_native_charge_percentage_by_ten
    lda f:$004216
    sta $01
    lda f:$004214
    sta $02
    rts
