; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3139
.include "src/rom/event_command_macros.inc"
event_10C_command_3139:
    event_screen 3
event_10C_command_313B:
    event_wait 16
event_10C_command_313D:
    event_actor_walk 4, 2, 16
event_10C_command_3140:
    event_wait_idle 
event_10C_command_3141:
    event_actor_walk 4, 3, 32
event_10C_command_3144:
    event_wait_idle 
event_10C_command_3145:
    event_actor_walk 4, 1, 16
event_10C_command_3148:
    event_wait_idle 
event_10C_command_3149:
    event_actor_walk 0, 1, 0
event_10C_command_314C:
    event_actor_walk 4, 2, 16
event_10C_command_314F:
    event_wait_idle 
event_10C_command_3150:
    event_increment_flag 16
event_10C_command_3152:
    event_call 1944
event_10C_command_3154:
    event_call 1864
event_10C_command_3156:
    event_actor_walk 0, 0, 0
event_10C_command_3159:
    event_wait_idle 
event_10C_command_315A:
    event_redraw_pieces 
event_10C_command_315B:
    event_refresh_objects 
event_10C_command_315C:
    event_actor_animation 0, 174
event_10C_command_315F:
    event_wait_idle 
event_10C_command_3160:
    event_toggle_visibility_04 
