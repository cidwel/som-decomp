; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5086
.include "src/rom/event_command_macros.inc"
event_4FD_command_5086:
    event_call 86
event_4FD_command_5088:
    event_wait 24
event_4FD_command_508A:
    event_screen_word 6, 65535
event_4FD_command_508E:
    event_call 1854
event_4FD_command_5090:
    event_call 83
event_4FD_command_5092:
    event_actor_animation_loop 1, 137
event_4FD_command_5095:
    event_actor_animation_loop 2, 137
event_4FD_command_5098:
    event_wait_idle 
event_4FD_command_5099:
    event_wait 16
event_4FD_command_509B:
    event_call 1842
event_4FD_command_509D:
    event_toggle_visibility_04 
event_4FD_command_509E:
    event_increment_flag 1
event_4FD_command_50A0:
    event_change_map 1006
event_4FD_command_50A2:
    event_actor_walk 1, 0, 0
event_4FD_command_50A5:
    event_actor_walk 2, 0, 0
event_4FD_command_50A8:
    event_wait_idle 
event_4FD_command_50A9:
    event_actor_animation_loop 1, 139
event_4FD_command_50AC:
    event_actor_animation_loop 2, 139
event_4FD_command_50AF:
    event_actor_animation_loop 5, 129
event_4FD_command_50B2:
    event_actor_animation_loop 6, 129
event_4FD_command_50B5:
    event_actor_animation_loop 7, 129
event_4FD_command_50B8:
    event_wait_idle 
