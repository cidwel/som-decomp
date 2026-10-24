; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8375
.include "src/rom/event_command_macros.inc"
event_5F8_command_8375:
    event_wait 32
event_5F8_command_8377:
    event_actor_walk 2, 2, 0
event_5F8_command_837A:
    event_actor_walk 3, 3, 0
event_5F8_command_837D:
    event_wait_idle 
