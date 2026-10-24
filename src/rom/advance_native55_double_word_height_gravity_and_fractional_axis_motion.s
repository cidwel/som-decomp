; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native55-gravity.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_fractional_axes_with_terrain_party_rejection_and_sliding = $36FF

.segment "CODE"
.org $5278
advance_native55_double_word_height_gravity_and_fractional_axis_motion:
    lda a:$00C4,X
    clc
    adc a:$0064,X
    sta a:$0064,X
    lda a:$00C6,X
    adc a:$0066,X
    sta a:$0066,X
    bpl advance_native55_double_word_height_gravity_and_fractional_axis_motion_c25299
    stz a:$0064,X
    stz a:$0066,X
    stz a:$00C4,X
    stz a:$00C6,X
advance_native55_double_word_height_gravity_and_fractional_axis_motion_c25299:
    lda a:$00C4,X
    clc
    adc a:$0FC0
    sta a:$00C4,X
    lda a:$00C6,X
    adc a:$0FC2
    sta a:$00C6,X
    jsr move_boss_fractional_axes_with_terrain_party_rejection_and_sliding
    rts
