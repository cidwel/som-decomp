; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9BF3
.include "src/rom/event_command_macros.inc"
event_236_command_9BF3:
    event_call 1927
event_236_command_9BF5:
    event_actor_animation 3, 0
event_236_command_9BF8:
    event_wait_idle 
event_236_command_9BF9:
    event_call 1927
event_236_command_9BFB:
    event_wait 4
event_236_command_9BFD:
    event_actor_animation 3, 1
event_236_command_9C00:
    event_wait_idle 
event_236_command_9C01:
    event_call 1927
event_236_command_9C03:
    event_wait 2
event_236_command_9C05:
    event_actor_animation 3, 2
event_236_command_9C08:
    event_wait_idle 
event_236_command_9C09:
    event_call 1927
