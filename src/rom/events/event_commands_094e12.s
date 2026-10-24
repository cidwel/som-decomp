; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E12
.include "src/rom/event_command_macros.inc"
event_16D_command_4E12:
    event_actor_walk 128, 0, 32
event_16D_command_4E15:
    event_wait_idle 
