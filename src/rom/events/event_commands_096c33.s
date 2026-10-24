; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C33
.include "src/rom/event_command_macros.inc"
event_1B9_command_6C33:
    event_actor_walk 5, 2, 0
event_1B9_command_6C36:
    event_wait 0
