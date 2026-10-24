; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D145
.include "src/rom/event_command_macros.inc"
event_359_command_D145:
    event_jump 864
event_359_command_D147:
    event_end 
event_35A_command_D148:
    event_audio_request 2, 23, 15, 136
event_35A_command_D14D:
    event_actor_animation_loop 4, 132
