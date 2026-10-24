; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
mask_angle_and_derive_native_sine = $2A60

.segment "CODE"
.org $649D
advance_orbit_sine_and_cosine_phases:
    lda a:$00B0,X
    clc
    .a16
    adc #$002A
    sta a:$00B0,X
    jsr mask_angle_and_derive_native_sine
    sta $95
    ldx $87
    lda a:$00B2,X
    clc
    .a16
    adc #$0020
    sta a:$00B2,X
    jsr derive_cosine_by_adding_quarter_turn
    sta $97
    rts
