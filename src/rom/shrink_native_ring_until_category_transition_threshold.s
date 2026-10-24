; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

store_native_ring_radius_then_project_rows = $6C47
tail_transfer_to_native_ring_phase_completion = $6C4C

.segment "CODE"
.org $6C1D
shrink_native_ring_until_category_transition_threshold:
    .a16
    cmp #$0010
    bcc tail_transfer_to_native_ring_phase_completion
    clc
    .a16
    adc #$FFF6
    bra store_native_ring_radius_then_project_rows
