; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2FFE
.include "src/rom/event_command_macros.inc"
event_10C_command_2FFE:
    event_actor_walk 5, 1, 0
event_10C_command_3001:
    event_call 95
