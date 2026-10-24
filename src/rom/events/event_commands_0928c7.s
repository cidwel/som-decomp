; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28C7
.include "src/rom/event_command_macros.inc"
event_106_command_28C7:
    event_actor_walk 4, 3, 8
event_106_command_28CA:
    event_wait_idle 
