; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $515B
.include "src/rom/event_command_macros.inc"
event_4FD_command_515B:
    event_actor_walk 4, 3, 0
event_4FD_command_515E:
    event_wait_idle 
event_4FD_command_515F:
    event_actor_animation_loop 4, 129
event_4FD_command_5162:
    event_wait_idle 
event_4FD_command_5163:
    event_wait 16
event_4FD_command_5165:
    event_change_map 999
event_4FD_command_5167:
    event_toggle_visibility_05 
event_4FD_command_5168:
    event_actor_walk 2, 1, 16
event_4FD_command_516B:
    event_wait_idle 
event_4FD_command_516C:
    event_actor_walk 2, 3, 0
event_4FD_command_516F:
    event_actor_walk 5, 2, 0
event_4FD_command_5172:
    event_actor_walk 4, 2, 63
event_4FD_command_5175:
    event_wait_idle 
event_4FD_command_5176:
    event_actor_walk 4, 0, 16
event_4FD_command_5179:
    event_wait_idle 
event_4FD_command_517A:
    event_wait 16
