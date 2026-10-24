; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D171
.include "src/rom/event_command_macros.inc"
event_35B_command_D171:
    event_jump 864
event_35B_command_D173:
    event_end 
event_35C_command_D174:
    event_audio_request 2, 23, 15, 136
event_35C_command_D179:
    event_actor_animation_loop 4, 133
