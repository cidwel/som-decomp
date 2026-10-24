; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28D8
.include "src/rom/event_command_macros.inc"
event_106_command_28D8:
    event_actor_walk 4, 3, 6
event_106_command_28DB:
    event_wait_idle 
event_106_command_28DC:
    event_set_flag 12, 1
event_106_command_28DF:
    event_wait 16
event_106_command_28E1:
    event_toggle_visibility_05 
event_106_command_28E2:
    event_refresh_objects 
event_106_command_28E3:
    event_actor_animation 0, 136
event_106_command_28E6:
    event_wait_idle 
event_106_command_28E7:
    event_actor_animation 0, 136
event_106_command_28EA:
    event_wait_idle 
