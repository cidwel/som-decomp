; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3576
.include "src/rom/event_command_macros.inc"
event_112_command_3576:
    event_wait 16
event_112_command_3578:
    event_actor_walk 4, 2, 16
event_112_command_357B:
    event_wait_idle 
event_112_command_357C:
    event_actor_walk 4, 1, 56
event_112_command_357F:
    event_wait_idle 
event_112_command_3580:
    event_actor_walk 4, 3, 63
event_112_command_3583:
    event_wait_idle 
event_112_command_3584:
    event_actor_walk 4, 3, 16
event_112_command_3587:
    event_wait_idle 
event_112_command_3588:
    event_actor_walk 0, 0, 0
event_112_command_358B:
    event_actor_walk 4, 1, 56
event_112_command_358E:
    event_wait_idle 
