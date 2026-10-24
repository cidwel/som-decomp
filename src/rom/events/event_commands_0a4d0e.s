; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D0E
.include "src/rom/event_command_macros.inc"
event_4EA_command_4D0E:
    event_actor_walk 6, 3, 52
event_4EA_command_4D11:
    event_actor_walk 7, 3, 52
event_4EA_command_4D14:
    event_actor_walk 8, 3, 52
event_4EA_command_4D17:
    event_actor_walk 9, 3, 52
event_4EA_command_4D1A:
    event_actor_walk 10, 3, 52
event_4EA_command_4D1D:
    event_actor_walk 11, 3, 52
event_4EA_command_4D20:
    event_actor_walk 12, 3, 52
event_4EA_command_4D23:
    event_wait_idle 
event_4EA_command_4D24:
    event_actor_walk 6, 1, 63
event_4EA_command_4D27:
    event_actor_walk 7, 1, 63
event_4EA_command_4D2A:
    event_actor_walk 8, 1, 63
event_4EA_command_4D2D:
    event_actor_walk 9, 1, 63
event_4EA_command_4D30:
    event_actor_walk 10, 1, 63
event_4EA_command_4D33:
    event_actor_walk 11, 1, 63
event_4EA_command_4D36:
    event_actor_walk 12, 1, 63
event_4EA_command_4D39:
    event_actor_walk 0, 1, 8
event_4EA_command_4D3C:
    event_wait_idle 
event_4EA_command_4D3D:
    event_audio_request 2, 114, 0, 17
event_4EA_command_4D42:
    event_audio_request 2, 29, 15, 17
event_4EA_command_4D47:
    event_actor_walk 5, 1, 12
event_4EA_command_4D4A:
    event_actor_walk 6, 1, 63
event_4EA_command_4D4D:
    event_actor_walk 7, 1, 63
event_4EA_command_4D50:
    event_actor_walk 8, 1, 63
event_4EA_command_4D53:
    event_actor_walk 9, 1, 63
event_4EA_command_4D56:
    event_actor_walk 10, 1, 63
event_4EA_command_4D59:
    event_actor_walk 11, 1, 63
event_4EA_command_4D5C:
    event_actor_walk 12, 1, 63
event_4EA_command_4D5F:
    event_wait_idle 
event_4EA_command_4D60:
    event_wait 8
event_4EA_command_4D62:
    event_audio_request 2, 114, 0, 17
event_4EA_command_4D67:
    event_increment_flag 17
event_4EA_command_4D69:
    event_refresh_objects 
event_4EA_command_4D6A:
    event_end 
event_4EB_command_4D6B:
    event_end 
event_4EC_command_4D6C:
    event_end 
event_4ED_command_4D6D:
    event_end 
event_4EE_command_4D6E:
    event_end 
event_4EF_command_4D6F:
    event_end 
