; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $74E1
.include "src/rom/event_command_macros.inc"
event_592_command_74E1:
    event_actor_walk 3, 1, 0
event_592_command_74E4:
    event_wait_idle 
