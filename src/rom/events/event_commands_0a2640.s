; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2640
.include "src/rom/event_command_macros.inc"
event_4C8_command_2640:
    event_actor_walk 5, 2, 0
event_4C8_command_2643:
    event_wait_idle 
