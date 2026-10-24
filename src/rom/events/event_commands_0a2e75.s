; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E75
.include "src/rom/event_command_macros.inc"
event_4E1_command_2E75:
    event_actor_walk 4, 3, 0
event_4E1_command_2E78:
    event_wait_idle 
event_4E1_command_2E79:
    event_wait 0
