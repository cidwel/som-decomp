; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A92
read_native_quarter_wave_and_saturate_peak:
    tax
    .a16
    cmp #$00F6
    bcs read_native_quarter_wave_and_saturate_peak_c22aa2
    lda f:$D97DE0,X
    rep #$20
    .a16
    and #$00FF
    rts
read_native_quarter_wave_and_saturate_peak_c22aa2:
    .a16
    lda #$0100
    rts
