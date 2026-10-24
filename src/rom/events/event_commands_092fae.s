; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2FAE
.include "src/rom/event_command_macros.inc"
event_10C_command_2FAE:
    event_actor_walk 4, 1, 0
event_10C_command_2FB1:
    event_wait 8
