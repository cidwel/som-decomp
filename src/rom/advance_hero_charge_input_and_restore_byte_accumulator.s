; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-charge-input.md.
.setcpu "65816"
.smart
.a8
.i16

advance_selected_hero_charge_timing_and_publish_native_gauge = $B330

.segment "CODE"
.org $B32A
advance_hero_charge_input_and_restore_byte_accumulator:
    jsr advance_selected_hero_charge_timing_and_publish_native_gauge
    sep #$20
    rts
