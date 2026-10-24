; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $43A1
.include "src/rom/event_command_macros.inc"
event_4E8_command_43A1:
    event_audio_request 1, 22, 26, 143
event_4E8_command_43A6:
    event_actor_walk 5, 1, 16
event_4E8_command_43A9:
    event_actor_walk 6, 1, 16
event_4E8_command_43AC:
    event_actor_walk 7, 3, 8
event_4E8_command_43AF:
    event_wait_idle 
event_4E8_command_43B0:
    event_actor_walk 7, 1, 63
event_4E8_command_43B3:
    event_wait_idle 
event_4E8_command_43B4:
    event_actor_walk 5, 3, 0
event_4E8_command_43B7:
    event_actor_walk 6, 2, 0
event_4E8_command_43BA:
    event_actor_walk 7, 1, 32
event_4E8_command_43BD:
    event_wait_idle 
