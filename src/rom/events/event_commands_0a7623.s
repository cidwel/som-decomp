; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7623
.include "src/rom/event_command_macros.inc"
event_59B_command_7623:
    event_actor_walk 5, 0, 0
event_59B_command_7626:
    event_wait_idle 
