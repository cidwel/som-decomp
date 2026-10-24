; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7CC5
.include "src/rom/event_command_macros.inc"
event_5F8_command_7CC5:
    event_wait 32
event_5F8_command_7CC7:
    event_toggle_visibility_04 
event_5F8_command_7CC8:
    event_change_map 872
event_5F8_command_7CCA:
    event_call 1844
event_5F8_command_7CCC:
    event_actor_walk 1, 0, 16
event_5F8_command_7CCF:
    event_actor_walk 2, 1, 8
event_5F8_command_7CD2:
    event_actor_walk 3, 3, 8
event_5F8_command_7CD5:
    event_wait_idle 
event_5F8_command_7CD6:
    event_decrement_flag 1
event_5F8_command_7CD8:
    event_set_actor_field 1, 144, 1
event_5F8_command_7CDC:
    event_set_actor_field 2, 144, 1
event_5F8_command_7CE0:
    event_set_actor_field 3, 144, 1
event_5F8_command_7CE4:
    event_actor_animation_loop 1, 135
event_5F8_command_7CE7:
    event_actor_animation_loop 2, 135
event_5F8_command_7CEA:
    event_actor_animation_loop 3, 135
event_5F8_command_7CED:
    event_wait_idle 
event_5F8_command_7CEE:
    event_toggle_visibility_05 
event_5F8_command_7CEF:
    event_wait 64
event_5F8_command_7CF1:
    event_increment_flag 248
