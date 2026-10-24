; Typed seven-phase ring jump targets; docs/event-menu-ring-phase.md.
.setcpu "65816"
.segment "CODE"
.org $6C0F
native_menu_ring_phase_jump_targets:
    .word $6C6D, $6C28, $6C33, $6C3E, $6C1D, $6C3E, $6C33
