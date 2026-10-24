; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D15A
.include "src/rom/event_command_macros.inc"
event_35A_command_D15A:
    event_jump 864
event_35A_command_D15C:
    event_end 
event_35B_command_D15D:
    event_audio_request 2, 23, 15, 136
event_35B_command_D162:
    event_actor_animation_loop 4, 131
