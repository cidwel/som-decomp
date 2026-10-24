; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4F10
.include "src/rom/event_command_macros.inc"
event_4FD_command_4F10:
    event_set_flag 247, 11
event_4FD_command_4F13:
    event_call 84
event_4FD_command_4F15:
    event_actor_animation_loop 1, 137
event_4FD_command_4F18:
    event_actor_animation_loop 2, 137
event_4FD_command_4F1B:
    event_wait_idle 
