; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3353
.include "src/rom/event_command_macros.inc"
event_112_command_3353:
    event_actor_walk 6, 0, 63
event_112_command_3356:
    event_actor_walk 5, 2, 0
event_112_command_3359:
    event_wait_idle 
event_112_command_335A:
    event_actor_walk 6, 0, 63
event_112_command_335D:
    event_actor_walk 5, 0, 0
event_112_command_3360:
    event_actor_walk 0, 0, 12
event_112_command_3363:
    event_wait_idle 
event_112_command_3364:
    event_wait 16
event_112_command_3366:
    event_actor_walk 5, 2, 1
event_112_command_3369:
    event_actor_walk 0, 3, 0
event_112_command_336C:
    event_wait_idle 
event_112_command_336D:
    event_screen 8
