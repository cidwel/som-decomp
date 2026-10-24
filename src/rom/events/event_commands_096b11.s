; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6B11
.include "src/rom/event_command_macros.inc"
event_1B6_command_6B11:
    event_freeze 
event_1B6_command_6B12:
    event_gather 
event_1B6_command_6B13:
    event_actor_walk 0, 1, 24
event_1B6_command_6B16:
    event_wait_idle 
event_1B6_command_6B17:
    event_gather 
event_1B6_command_6B18:
    event_actor_walk 4, 1, 32
event_1B6_command_6B1B:
    event_actor_walk 0, 0, 0
event_1B6_command_6B1E:
    event_wait_idle 
event_1B6_command_6B1F:
    event_gather 
event_1B6_command_6B20:
    event_actor_walk 4, 2, 63
event_1B6_command_6B23:
    event_actor_walk 0, 2, 0
event_1B6_command_6B26:
    event_wait_idle 
event_1B6_command_6B27:
    event_actor_walk 4, 0, 48
event_1B6_command_6B2A:
    event_actor_walk 0, 2, 32
event_1B6_command_6B2D:
    event_wait_idle 
event_1B6_command_6B2E:
    event_gather 
event_1B6_command_6B2F:
    event_actor_walk 4, 2, 63
event_1B6_command_6B32:
    event_actor_walk 0, 0, 38
event_1B6_command_6B35:
    event_wait_idle 
event_1B6_command_6B36:
    event_actor_walk 4, 2, 16
event_1B6_command_6B39:
    event_actor_walk 0, 2, 0
event_1B6_command_6B3C:
    event_wait_idle 
event_1B6_command_6B3D:
    event_gather 
event_1B6_command_6B3E:
    event_actor_walk 4, 0, 0
event_1B6_command_6B41:
    event_wait_idle 
event_1B6_command_6B42:
    event_screen 8
event_1B6_command_6B44:
    event_set_flag 20, 7
event_1B6_command_6B47:
    event_call 1932
event_1B6_command_6B49:
    event_redraw_pieces 
event_1B6_command_6B4A:
    event_actor_walk 4, 0, 16
event_1B6_command_6B4D:
    event_actor_walk 0, 2, 56
event_1B6_command_6B50:
    event_wait_idle 
event_1B6_command_6B51:
    event_actor_walk 4, 1, 0
event_1B6_command_6B54:
    event_actor_walk 0, 0, 0
event_1B6_command_6B57:
    event_wait_idle 
event_1B6_command_6B58:
    event_gather 
