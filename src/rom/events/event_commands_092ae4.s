; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2AE4
.include "src/rom/event_command_macros.inc"
event_106_command_2AE4:
    event_toggle_visibility_04 
event_106_command_2AE5:
    event_set_flag 1, 0
event_106_command_2AE8:
    event_wait 16
event_106_command_2AEA:
    event_actor_walk 5, 3, 0
event_106_command_2AED:
    event_actor_walk 6, 2, 0
event_106_command_2AF0:
    event_wait_idle 
event_106_command_2AF1:
    event_wait 12
event_106_command_2AF3:
    event_actor_walk 5, 2, 0
event_106_command_2AF6:
    event_wait_idle 
event_106_command_2AF7:
    event_actor_animation_loop 5, 130
event_106_command_2AFA:
    event_actor_animation_loop 6, 130
event_106_command_2AFD:
    event_wait 16
event_106_command_2AFF:
    event_change_map 130
event_106_command_2B01:
    event_test_flag_range 0, 0, 0
event_106_command_2B04:
    event_jump 257
event_106_command_2B06:
    event_toggle_visibility_05 
event_106_command_2B07:
    event_end 
