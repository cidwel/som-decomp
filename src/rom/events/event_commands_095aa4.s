; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5AA4
.include "src/rom/event_command_macros.inc"
event_186_command_5AA4:
    event_set_flag 19, 2
event_186_command_5AA7:
    event_redraw_pieces 
event_186_command_5AA8:
    event_call 64
event_186_command_5AAA:
    event_jump 1555
event_186_command_5AAC:
    event_end 
event_187_command_5AAD:
    event_freeze 
event_187_command_5AAE:
    event_gather 
event_187_command_5AAF:
    event_set_flag 19, 1
event_187_command_5AB2:
    event_refresh_objects 
event_187_command_5AB3:
    event_screen 8
event_187_command_5AB5:
    event_call 1935
event_187_command_5AB7:
    event_actor_walk 4, 1, 8
event_187_command_5ABA:
    event_wait_idle 
event_187_command_5ABB:
    event_actor_walk 4, 0, 0
