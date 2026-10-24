; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5D98
.include "src/rom/event_command_macros.inc"
event_526_command_5D98:
    event_freeze 
event_526_command_5D99:
    event_gather 
event_526_command_5D9A:
    event_call 1040
event_526_command_5D9C:
    event_actor_walk 4, 1, 0
event_526_command_5D9F:
    event_actor_walk 5, 1, 0
event_526_command_5DA2:
    event_actor_walk 6, 1, 0
event_526_command_5DA5:
    event_wait_idle 
event_526_command_5DA6:
    event_call 1932
event_526_command_5DA8:
    event_increment_flag 53
event_526_command_5DAA:
    event_redraw_pieces 
event_526_command_5DAB:
    event_actor_walk 128, 2, 16
event_526_command_5DAE:
    event_wait_idle 
event_526_command_5DAF:
    event_actor_walk 128, 3, 0
event_526_command_5DB2:
    event_actor_walk 0, 1, 32
event_526_command_5DB5:
    event_wait_idle 
event_526_command_5DB6:
    event_call 1152
event_526_command_5DB8:
    event_actor_walk 128, 3, 16
event_526_command_5DBB:
    event_wait_idle 
event_526_command_5DBC:
    event_actor_walk 128, 1, 8
event_526_command_5DBF:
    event_wait_idle 
event_526_command_5DC0:
    event_call 1932
event_526_command_5DC2:
    event_decrement_flag 53
event_526_command_5DC4:
    event_redraw_pieces 
event_526_command_5DC5:
    event_refresh_objects 
event_526_command_5DC6:
    event_actor_walk 0, 0, 4
event_526_command_5DC9:
    event_wait_idle 
