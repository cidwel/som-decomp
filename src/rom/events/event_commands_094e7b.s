; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E7B
.include "src/rom/event_command_macros.inc"
event_16D_command_4E7B:
    event_actor_walk 2, 0, 16
event_16D_command_4E7E:
    event_wait_idle 
