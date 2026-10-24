; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6759
.include "src/rom/event_command_macros.inc"
event_559_command_6759:
    event_wait 48
event_559_command_675B:
    event_call 82
event_559_command_675D:
    event_actor_walk 2, 0, 8
event_559_command_6760:
    event_wait_idle 
event_559_command_6761:
    event_wait 48
