; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $540C
.include "src/rom/event_command_macros.inc"
event_4FD_command_540C:
    event_change_map 1008
event_4FD_command_540E:
    event_actor_walk 1, 3, 8
event_4FD_command_5411:
    event_wait_idle 
event_4FD_command_5412:
    event_wait 16
event_4FD_command_5414:
    event_call 86
event_4FD_command_5416:
    event_wait 16
event_4FD_command_5418:
    event_actor_walk 4, 1, 0
event_4FD_command_541B:
    event_wait_idle 
event_4FD_command_541C:
    event_actor_animation_loop 4, 129
event_4FD_command_541F:
    event_wait_idle 
