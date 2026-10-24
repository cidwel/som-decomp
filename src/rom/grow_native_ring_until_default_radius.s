; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

reset_native_ring_phase_direction_and_description_request = $6C4F
store_native_ring_radius_then_project_rows = $6C47

.segment "CODE"
.org $6C28
grow_native_ring_until_default_radius:
    .a16
    cmp #$0024
    bcs reset_native_ring_phase_direction_and_description_request
    clc
    .a16
    adc #$000A
    bra store_native_ring_radius_then_project_rows
