; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D198
.include "src/rom/event_command_macros.inc"
event_35D_command_D198:
    event_jump 864
event_35D_command_D19A:
    event_end 
event_35E_command_D19B:
    event_audio_request 2, 23, 15, 136
event_35E_command_D1A0:
    event_actor_animation_loop 4, 135
