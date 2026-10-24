; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7443
.include "src/rom/event_command_macros.inc"
event_592_command_7443:
    event_call 90
event_592_command_7445:
    event_call 1040
event_592_command_7447:
    event_actor_walk 3, 0, 16
event_592_command_744A:
    event_wait_idle 
event_592_command_744B:
    event_wait 8
