; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $521A
.include "src/rom/event_command_macros.inc"
event_16E_command_521A:
    event_actor_walk 2, 0, 16
