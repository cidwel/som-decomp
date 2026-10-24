; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28D1
.include "src/rom/event_command_macros.inc"
event_106_command_28D1:
    event_actor_walk 4, 3, 8
event_106_command_28D4:
    event_wait_idle 
