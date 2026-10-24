; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D131
.include "src/rom/event_command_macros.inc"
event_358_command_D131:
    event_jump 864
event_358_command_D133:
    event_end 
event_359_command_D134:
    event_audio_request 2, 23, 15, 136
event_359_command_D139:
    event_actor_animation_loop 4, 130
