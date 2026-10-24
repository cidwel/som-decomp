; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E27
.include "src/rom/event_command_macros.inc"
event_16D_command_4E27:
    event_actor_walk 128, 1, 0
event_16D_command_4E2A:
    event_actor_walk 1, 0, 16
event_16D_command_4E2D:
    event_wait_idle 
