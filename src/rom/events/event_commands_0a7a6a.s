; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A6A
.include "src/rom/event_command_macros.inc"
event_5F8_command_7A6A:
    event_actor_animation_loop 0, 139
event_5F8_command_7A6D:
    event_wait_idle 
event_5F8_command_7A6E:
    event_wait 64
event_5F8_command_7A70:
    event_actor_walk 0, 0, 0
event_5F8_command_7A73:
    event_wait_idle 
event_5F8_command_7A74:
    event_wait 64
event_5F8_command_7A76:
    event_actor_walk 6, 3, 0
event_5F8_command_7A79:
    event_wait_idle 
