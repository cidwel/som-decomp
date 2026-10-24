; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

reflect_full_wave_and_negate_lower_half = $2A67

.segment "CODE"
.org $2A60
mask_angle_and_derive_native_sine:
    .a16
    and #$03FF
    jsr reflect_full_wave_and_negate_lower_half
    rts
