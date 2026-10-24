; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_boss_displacement_to_signed_fixed_point = $2F61

.segment "CODE"
.org $9E6F
move_party_target_toward_parent_offset_with_fixed_point_vector:
    ldx $87
    ldy a:$00B2,X
    lda a:$0002,Y
    sta $95
    lda a:$0004,Y
    sta $99
    lda a:$00BE,X
    bne move_party_target_toward_parent_offset_with_fixed_point_vector_c29e9a
    ldy a:$00B0,X
    lda a:$002B,Y
    sec
    .a16
    sbc #$0050
    sta $9D
    lda a:$0032,Y
    clc
    .a16
    adc #$0028
    sta $A1
    bra move_party_target_toward_parent_offset_with_fixed_point_vector_c29eaf
move_party_target_toward_parent_offset_with_fixed_point_vector_c29e9a:
    ldy a:$00B0,X
    lda a:$002B,Y
    clc
    .a16
    adc #$0050
    sta $9D
    lda a:$0032,Y
    clc
    .a16
    adc #$0028
    sta $A1
move_party_target_toward_parent_offset_with_fixed_point_vector_c29eaf:
    jsr normalize_boss_displacement_to_signed_fixed_point
    asl $A5
    rol $A7
    asl $A5
    rol $A7
    asl $A9
    rol $AB
    asl $A9
    rol $AB
    ldx $87
    ldy a:$00B2,X
    lda $A7
    clc
    adc a:$0002,Y
    sta a:$0002,Y
    lda $AB
    clc
    adc a:$0004,Y
    sta a:$0004,Y
    rts
