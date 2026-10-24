; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C05D
.include "src/rom/event_command_macros.inc"
event_2D4_command_C05D:
    event_actor_walk 128, 0, 2
event_2D4_command_C060:
    event_wait_idle 
