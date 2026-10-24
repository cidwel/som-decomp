; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6550
.include "src/rom/event_command_macros.inc"
event_558_command_6550:
    event_actor_animation 1, 141
event_558_command_6553:
    event_actor_animation 3, 141
event_558_command_6556:
    event_wait_idle 
