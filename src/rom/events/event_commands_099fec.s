; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9FEC
.include "src/rom/event_command_macros.inc"
event_250_command_9FEC:
    event_actor_walk 3, 3, 0
event_250_command_9FEF:
    event_wait_idle 
event_250_command_9FF0:
    event_wait 8
event_250_command_9FF2:
    event_actor_walk 3, 2, 0
event_250_command_9FF5:
    event_wait_idle 
event_250_command_9FF6:
    event_wait 8
event_250_command_9FF8:
    event_actor_walk 1, 0, 16
event_250_command_9FFB:
    event_actor_walk 2, 0, 16
event_250_command_9FFE:
    event_actor_walk 3, 1, 0
event_250_command_A001:
    event_wait_idle 
event_250_command_A002:
    event_screen 8
event_250_command_A004:
    event_actor_animation_loop 1, 128
event_250_command_A007:
    event_actor_animation_loop 2, 128
event_250_command_A00A:
    event_actor_animation_loop 3, 167
