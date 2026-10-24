; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2605
.include "src/rom/event_command_macros.inc"
event_102_command_2605:
    event_actor_walk 0, 2, 0
event_102_command_2608:
    event_wait 4
