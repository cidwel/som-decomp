; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D9C
.include "src/rom/event_command_macros.inc"
event_0DC_command_1D9C:
    event_actor_walk 0, 2, 8
event_0DC_command_1D9F:
    event_wait_idle 
event_0DC_command_1DA0:
    event_actor_walk 0, 0, 0
event_0DC_command_1DA3:
    event_wait_idle 
