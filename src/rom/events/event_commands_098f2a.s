; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8F2A
.include "src/rom/event_command_macros.inc"
event_204_command_8F2A:
    event_actor_walk 5, 1, 16
event_204_command_8F2D:
    event_actor_walk 0, 2, 16
event_204_command_8F30:
    event_wait_idle 
event_204_command_8F31:
    event_actor_walk 0, 3, 0
event_204_command_8F34:
    event_actor_walk 5, 1, 48
event_204_command_8F37:
    event_wait_idle 
event_204_command_8F38:
    event_actor_walk 0, 3, 16
event_204_command_8F3B:
    event_wait_idle 
event_204_command_8F3C:
    event_actor_walk 0, 0, 28
event_204_command_8F3F:
    event_actor_walk 5, 0, 0
event_204_command_8F42:
    event_wait_idle 
event_204_command_8F43:
    event_screen 8
event_204_command_8F45:
    event_screen 0
event_204_command_8F47:
    event_wait 1
event_204_command_8F49:
    event_screen 1
event_204_command_8F4B:
    event_screen_word 5, 30313
event_204_command_8F4F:
    event_actor_walk 4, 0, 48
event_204_command_8F52:
    event_wait_idle 
event_204_command_8F53:
    event_actor_walk 4, 2, 0
event_204_command_8F56:
    event_wait_idle 
event_204_command_8F57:
    event_call 1922
event_204_command_8F59:
    event_wait 16
event_204_command_8F5B:
    event_call 1922
event_204_command_8F5D:
    event_wait 16
event_204_command_8F5F:
    event_call 1922
event_204_command_8F61:
    event_actor_walk 4, 1, 48
event_204_command_8F64:
    event_wait_idle 
event_204_command_8F65:
    event_screen 7
event_204_command_8F67:
    event_actor_walk 0, 1, 16
event_204_command_8F6A:
    event_wait_idle 
event_204_command_8F6B:
    event_screen 8
event_204_command_8F6D:
    event_call 1428
event_204_command_8F6F:
    event_set_flag 144, 1
