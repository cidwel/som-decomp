; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_quarter_wave_and_saturate_peak = $2A92

.segment "CODE"
.org $2A7B
reflect_angle_into_quarter_wave:
    .a16
    cmp #$00FF
    bcs reflect_angle_into_quarter_wave_c22a84
    jsr read_native_quarter_wave_and_saturate_peak
    rts
reflect_angle_into_quarter_wave_c22a84:
    sta a:$0266
    .a16
    lda #$0200
    sec
    sbc a:$0266
    jsr read_native_quarter_wave_and_saturate_peak
    rts
