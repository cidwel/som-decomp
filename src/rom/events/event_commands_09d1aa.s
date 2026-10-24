; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D1AA
.include "src/rom/event_command_macros.inc"
event_35E_command_D1AA:
    event_jump 864
event_35E_command_D1AC:
    event_end 
event_35F_command_D1AD:
    event_audio_request 2, 23, 15, 136
event_35F_command_D1B2:
    event_actor_animation_loop 4, 136
