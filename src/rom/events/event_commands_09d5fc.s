; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D5FC
.include "src/rom/event_command_macros.inc"
event_36F_command_D5FC:
    event_wait 4
event_36F_command_D5FE:
    event_actor_walk 5, 1, 0
