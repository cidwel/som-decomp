; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

compare_absolute_collision_height_difference_to_129 = $06EF

.segment "CODE"
.org $06C5
test_boss_target_height_with_inverted_flag_pair:
    ldx $87
    lda $24
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$000B,Y
    ora a:$000B,X
    .a8
    and #$03
    .a8
    cmp #$03
    bne test_boss_target_height_with_inverted_flag_pair_c206e9
    rep #$20
    jsr compare_absolute_collision_height_difference_to_129
    bcs test_boss_target_height_with_inverted_flag_pair_c206e7
    sec
    rts
test_boss_target_height_with_inverted_flag_pair_c206e7:
    clc
    rts
test_boss_target_height_with_inverted_flag_pair_c206e9:
    rep #$20
    jsr compare_absolute_collision_height_difference_to_129
    rts
