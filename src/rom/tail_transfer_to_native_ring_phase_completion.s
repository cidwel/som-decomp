; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

finish_native_ring_phase_or_rebuild_category_and_animate_palette = $6E9F

.segment "CODE"
.org $6C4C
tail_transfer_to_native_ring_phase_completion:
    jmp finish_native_ring_phase_or_rebuild_category_and_animate_palette
