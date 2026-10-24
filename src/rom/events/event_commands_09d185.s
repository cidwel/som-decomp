; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D185
.include "src/rom/event_command_macros.inc"
event_35C_command_D185:
    event_jump 864
event_35C_command_D187:
    event_end 
event_35D_command_D188:
    event_audio_request 2, 23, 15, 136
event_35D_command_D18D:
    event_actor_animation_loop 4, 134
