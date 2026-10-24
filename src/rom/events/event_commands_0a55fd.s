; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $55FD
.include "src/rom/event_command_macros.inc"
event_4FD_command_55FD:
    event_actor_walk 2, 1, 0
event_4FD_command_5600:
    event_wait_idle 
