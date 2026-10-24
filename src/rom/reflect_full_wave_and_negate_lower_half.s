; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

reflect_angle_into_quarter_wave = $2A7B

.segment "CODE"
.org $2A67
reflect_full_wave_and_negate_lower_half:
    .a16
    cmp #$0200
    bcs reflect_full_wave_and_negate_lower_half_c22a70
    jsr reflect_angle_into_quarter_wave
    rts
reflect_full_wave_and_negate_lower_half_c22a70:
    .a16
    and #$01FF
    jsr reflect_angle_into_quarter_wave
    .a16
    eor #$FFFF
    inc
    rts
