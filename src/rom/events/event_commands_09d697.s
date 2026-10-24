; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D697
.include "src/rom/event_command_macros.inc"
event_36F_command_D697:
    event_increment_flag 27
event_36F_command_D699:
    event_refresh_objects 
event_36F_command_D69A:
    event_actor_walk 5, 0, 0
event_36F_command_D69D:
    event_actor_walk 6, 0, 0
event_36F_command_D6A0:
    event_actor_walk 7, 0, 0
event_36F_command_D6A3:
    event_wait_idle 
event_36F_command_D6A4:
    event_actor_animation_loop 5, 129
event_36F_command_D6A7:
    event_actor_animation_loop 6, 129
event_36F_command_D6AA:
    event_actor_animation_loop 7, 129
event_36F_command_D6AD:
    event_wait_idle 
event_36F_command_D6AE:
    event_wait 64
event_36F_command_D6B0:
    event_increment_flag 27
event_36F_command_D6B2:
    event_refresh_objects 
event_36F_command_D6B3:
    event_end 
