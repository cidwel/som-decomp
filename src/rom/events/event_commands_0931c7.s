; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31C7
.include "src/rom/event_command_macros.inc"
event_10C_command_31C7:
    event_actor_walk 0, 2, 8
event_10C_command_31CA:
    event_wait_idle 
event_10C_command_31CB:
    event_actor_walk 0, 3, 16
event_10C_command_31CE:
    event_wait_idle 
event_10C_command_31CF:
    event_actor_walk 0, 2, 8
event_10C_command_31D2:
    event_wait_idle 
