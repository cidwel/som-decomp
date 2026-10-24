; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

advance_orbit_sine_and_cosine_phases = $649D
position_orbit_from_signed_products_parent_and_offset_with_carry = $64BE

.segment "CODE"
.org $646C
hold_orbit_for_eighty_counter_ticks_then_contract:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0050
    bcs hold_orbit_for_eighty_counter_ticks_then_contract_c26480
    jsr advance_orbit_sine_and_cosine_phases
    ldx $87
    jsr position_orbit_from_signed_products_parent_and_offset_with_carry
    clc
    rts
hold_orbit_for_eighty_counter_ticks_then_contract_c26480:
    inc a:$0094,X
