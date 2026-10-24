; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

advance_orbit_sine_and_cosine_phases = $649D
position_orbit_from_signed_products_parent_and_offset_with_carry = $64BE

.segment "CODE"
.org $6483
contract_orbit_radius_or_terminate:
    ldx $87
    jsr advance_orbit_sine_and_cosine_phases
    ldx $87
    lda a:$00B4,X
    sec
    .a16
    sbc #$0004
    bmi contract_orbit_radius_or_terminate_c2649b
    sta a:$00B4,X
    jsr position_orbit_from_signed_products_parent_and_offset_with_carry
    clc
    rts
contract_orbit_radius_or_terminate_c2649b:
    sec
    rts
