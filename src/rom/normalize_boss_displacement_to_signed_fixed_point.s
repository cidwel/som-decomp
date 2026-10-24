; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_displacement_squared_length_and_root = $2FCC
divide_signed_double_words_with_remainder = $2DA5

.segment "CODE"
.org $2F61
normalize_boss_displacement_to_signed_fixed_point:
    sec
    lda $A1
    sbc $99
    sta $A1
    sec
    lda $9D
    sbc $95
    sta $9D
    lda $9D
    bne normalize_boss_displacement_to_signed_fixed_point_c22f9a
    lda $A1
    sta $AD
    lda $AD
    bpl normalize_boss_displacement_to_signed_fixed_point_c22f82
    sec
    lda $C5
    sbc $AD
    sta $AD
normalize_boss_displacement_to_signed_fixed_point_c22f82:
    stz $A5
    stz $A7
    lda $A1
    bmi normalize_boss_displacement_to_signed_fixed_point_c22f92
    .a16
    lda #$0001
    sta $AB
    stz $A9
    rts
normalize_boss_displacement_to_signed_fixed_point_c22f92:
    .a16
    lda #$FFFF
    sta $AB
    stz $A9
    rts
normalize_boss_displacement_to_signed_fixed_point_c22f9a:
    jsr derive_boss_displacement_squared_length_and_root
    stz $46
    lda $9D
    sta $48
    stz $50
    lda $AD
    sta $4E
    jsr divide_signed_double_words_with_remainder
    lda $56
    sta $A5
    lda $58
    sta $A7
    stz $46
    lda $A1
    sta $48
    stz $50
    lda $AD
    sta $4E
    jsr divide_signed_double_words_with_remainder
    lda $56
    sta $A9
    lda $58
    sta $AB
    rts
