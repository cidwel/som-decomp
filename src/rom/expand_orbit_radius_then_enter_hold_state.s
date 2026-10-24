; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

advance_orbit_sine_and_cosine_phases = $649D
position_orbit_from_signed_products_parent_and_offset_with_carry = $64BE

.segment "CODE"
.org $644B
expand_orbit_radius_then_enter_hold_state:
    ldx $87
    jsr advance_orbit_sine_and_cosine_phases
    ldx $87
    lda a:$00B4,X
    clc
    .a16
    adc #$0004
    .a16
    cmp #$0050
    bcs expand_orbit_radius_then_enter_hold_state_c26466
    sta a:$00B4,X
    jsr position_orbit_from_signed_products_parent_and_offset_with_carry
    clc
    rts
expand_orbit_radius_then_enter_hold_state_c26466:
    inc a:$0094,X
    stz a:$0096,X
