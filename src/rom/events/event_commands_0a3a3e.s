; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A3E
.include "src/rom/event_command_macros.inc"
event_4E4_command_3A3E:
    event_actor_walk 5, 3, 8
event_4E4_command_3A41:
    event_wait_idle 
