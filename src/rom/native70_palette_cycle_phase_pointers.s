; Three phase pointers consumed by native70 definition; docs/boss-native70-palette-cycle.md.
.setcpu "65816"
initialize_native70_palette_cycle_phase = $D407
advance_native70_first_palette_transition_at_six_ticks = $D411
advance_native70_second_palette_transition_at_six_ticks = $D431
.segment "CODE"
.org $D401
native70_palette_cycle_phase_pointers:
    .word initialize_native70_palette_cycle_phase
    .word advance_native70_first_palette_transition_at_six_ticks
    .word advance_native70_second_palette_transition_at_six_ticks
