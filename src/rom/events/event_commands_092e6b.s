; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E6B
.include "src/rom/event_command_macros.inc"
event_10C_command_2E6B:
    event_actor_walk 4, 3, 0
event_10C_command_2E6E:
    event_wait 0
