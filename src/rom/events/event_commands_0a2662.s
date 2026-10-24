; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2662
.include "src/rom/event_command_macros.inc"
event_4C8_command_2662:
    event_actor_walk 4, 3, 0
event_4C8_command_2665:
    event_wait_idle 
