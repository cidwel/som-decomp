; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7608
.include "src/rom/event_command_macros.inc"
event_59B_command_7608:
    event_actor_walk 4, 1, 8
event_59B_command_760B:
    event_wait_idle 
