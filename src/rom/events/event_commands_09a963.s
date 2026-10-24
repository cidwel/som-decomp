; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A963
.include "src/rom/event_command_macros.inc"
event_289_command_A963:
    event_increment_flag 54
event_289_command_A965:
    event_end 
event_28A_command_A966:
    event_freeze 
event_28A_command_A967:
    event_actor_animation_loop 1, 137
event_28A_command_A96A:
    event_actor_animation_loop 2, 137
event_28A_command_A96D:
    event_actor_animation_loop 3, 137
event_28A_command_A970:
    event_wait_idle 
event_28A_command_A971:
    event_wait 16
event_28A_command_A973:
    event_actor_walk 3, 0, 0
event_28A_command_A976:
    event_wait_idle 
event_28A_command_A977:
    event_wait 4
event_28A_command_A979:
    event_actor_walk 2, 0, 0
event_28A_command_A97C:
    event_actor_animation_loop 3, 167
event_28A_command_A97F:
    event_wait_idle 
event_28A_command_A980:
    event_wait 4
event_28A_command_A982:
    event_actor_walk 1, 0, 0
event_28A_command_A985:
    event_wait_idle 
