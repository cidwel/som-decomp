; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D7D
.include "src/rom/event_command_macros.inc"
event_0DC_command_1D7D:
    event_actor_walk 0, 3, 8
event_0DC_command_1D80:
    event_wait_idle 
