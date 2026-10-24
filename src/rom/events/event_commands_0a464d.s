; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $464D
.include "src/rom/event_command_macros.inc"
event_4E8_command_464D:
    event_actor_walk 4, 1, 8
event_4E8_command_4650:
    event_wait_idle 
event_4E8_command_4651:
    event_actor_walk 4, 2, 0
event_4E8_command_4654:
    event_actor_walk 0, 1, 2
event_4E8_command_4657:
    event_wait_idle 
event_4E8_command_4658:
    event_actor_animation_loop 4, 138
event_4E8_command_465B:
    event_actor_walk 0, 1, 6
event_4E8_command_465E:
    event_wait_idle 
event_4E8_command_465F:
    event_actor_walk 0, 2, 16
