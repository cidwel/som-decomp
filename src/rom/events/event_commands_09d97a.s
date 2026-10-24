; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D97A
.include "src/rom/event_command_macros.inc"
event_384_command_D97A:
    event_actor_walk 128, 1, 16
event_384_command_D97D:
    event_wait_idle 
event_384_command_D97E:
    event_actor_walk 128, 2, 63
event_384_command_D981:
    event_wait_idle 
event_384_command_D982:
    event_actor_walk 128, 1, 63
event_384_command_D985:
    event_wait_idle 
event_384_command_D986:
    event_actor_walk 128, 1, 63
event_384_command_D989:
    event_wait_idle 
event_384_command_D98A:
    event_increment_flag 39
event_384_command_D98C:
    event_refresh_objects 
event_384_command_D98D:
    event_end 
