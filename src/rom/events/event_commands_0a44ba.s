; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44BA
.include "src/rom/event_command_macros.inc"
event_4E8_command_44BA:
    event_actor_animation 4, 139
event_4E8_command_44BD:
    event_wait_idle 
event_4E8_command_44BE:
    event_actor_animation_loop 4, 131
event_4E8_command_44C1:
    event_wait 16
event_4E8_command_44C3:
    event_actor_animation 0, 158
event_4E8_command_44C6:
    event_actor_animation 4, 37
event_4E8_command_44C9:
    event_wait_idle 
event_4E8_command_44CA:
    event_actor_walk 0, 1, 0
event_4E8_command_44CD:
    event_wait_idle 
event_4E8_command_44CE:
    event_actor_animation 0, 140
event_4E8_command_44D1:
    event_actor_walk 4, 0, 32
event_4E8_command_44D4:
    event_wait_idle 
