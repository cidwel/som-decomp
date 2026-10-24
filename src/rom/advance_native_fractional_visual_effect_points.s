; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A407
advance_native_fractional_visual_effect_points:
    rep #$20
    phx
    txa
    lsr
    tay
    lda a:$C060,Y
    sta $08
    sep #$20
    lda $08
    bne advance_native_fractional_visual_effect_points_c2a41a
    plx
    rtl
advance_native_fractional_visual_effect_points_c2a41a:
    lda a:$C000,Y
    clc
    adc a:$E0D0,X
    sta a:$E0D0,X
    lda a:$C001,Y
    clc
    adc a:$E0D1,X
    sta a:$E0D1,X
    lda a:$C002,Y
    clc
    adc a:$C032,Y
    cmp $09
    bcc advance_native_fractional_visual_effect_points_c2a44d
    sbc $09
    sta a:$C002,Y
    lda a:$C030,Y
    bmi advance_native_fractional_visual_effect_points_c2a448
    inc a:$E0D0,X
    bra advance_native_fractional_visual_effect_points_c2a450
advance_native_fractional_visual_effect_points_c2a448:
    dec a:$E0D0,X
    bra advance_native_fractional_visual_effect_points_c2a450
advance_native_fractional_visual_effect_points_c2a44d:
    sta a:$C002,Y
advance_native_fractional_visual_effect_points_c2a450:
    lda a:$C003,Y
    clc
    adc a:$C033,Y
    cmp $09
    bcc advance_native_fractional_visual_effect_points_c2a46f
    sbc $09
    sta a:$C003,Y
    lda a:$C031,Y
    bmi advance_native_fractional_visual_effect_points_c2a46a
    inc a:$E0D1,X
    bra advance_native_fractional_visual_effect_points_c2a472
advance_native_fractional_visual_effect_points_c2a46a:
    dec a:$E0D1,X
    bra advance_native_fractional_visual_effect_points_c2a472
advance_native_fractional_visual_effect_points_c2a46f:
    sta a:$C003,Y
advance_native_fractional_visual_effect_points_c2a472:
    inx
    inx
    inx
    inx
    iny
    iny
    iny
    iny
    dec $08
    bne advance_native_fractional_visual_effect_points_c2a41a
    plx
    rtl
