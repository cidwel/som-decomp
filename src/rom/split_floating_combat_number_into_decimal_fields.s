; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

center_single_digit_floating_number_fields = $8516
divide_floating_number_byte_by_ten = $84F9
offset_three_digit_floating_number_origin = $8522
read_floating_number_division_remainder = $8503

.segment "CODE"
.org $84C9
split_floating_combat_number_into_decimal_fields:
    rep #$20
    .a16
    lda #$CB00
    sta $02
    sta $04
    lda $1E
    sta f:$004204
    sep #$20
    jsr read_floating_number_division_remainder
    sta $00
    stz $01
    lda f:$004214
    beq center_single_digit_floating_number_fields
    jsr divide_floating_number_byte_by_ten
    sta $02
    stz $03
    lda f:$004214
    beq offset_three_digit_floating_number_origin
    sta $04
    stz $05
    rts
