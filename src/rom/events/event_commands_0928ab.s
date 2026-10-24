; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28AB
.include "src/rom/event_command_macros.inc"
event_106_command_28AB:
    event_actor_walk 0, 0, 3
event_106_command_28AE:
    event_actor_walk 4, 3, 8
event_106_command_28B1:
    event_wait_idle 
event_106_command_28B2:
    event_actor_walk 0, 3, 0
