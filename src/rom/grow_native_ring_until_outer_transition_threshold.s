; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

store_native_ring_radius_then_project_rows = $6C47
tail_transfer_to_native_ring_phase_completion = $6C4C

.segment "CODE"
.org $6C33
grow_native_ring_until_outer_transition_threshold:
    .a16
    cmp #$00FE
    bcs tail_transfer_to_native_ring_phase_completion
    clc
    .a16
    adc #$000A
    bra store_native_ring_radius_then_project_rows
