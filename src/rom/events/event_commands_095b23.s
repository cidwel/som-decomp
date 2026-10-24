; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B23
.include "src/rom/event_command_macros.inc"
event_187_command_5B23:
    event_set_flag 19, 2
event_187_command_5B26:
    event_redraw_pieces 
event_187_command_5B27:
    event_call 1927
event_187_command_5B29:
    event_actor_walk 0, 2, 8
event_187_command_5B2C:
    event_wait_idle 
event_187_command_5B2D:
    event_actor_walk 0, 3, 0
event_187_command_5B30:
    event_actor_walk 4, 1, 32
event_187_command_5B33:
    event_wait_idle 
event_187_command_5B34:
    event_actor_walk 0, 1, 0
event_187_command_5B37:
    event_actor_walk 4, 1, 48
event_187_command_5B3A:
    event_wait_idle 
event_187_command_5B3B:
    event_refresh_objects 
event_187_command_5B3C:
    event_end 
event_188_command_5B3D:
    event_test_flag_range 19, 0, 1
event_188_command_5B40:
    event_jump 391
event_188_command_5B42:
    event_end 
event_189_command_5B43:
    event_test_flag_range 18, 6, 8
event_189_command_5B46:
    event_jump 406
