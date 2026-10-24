; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44F4
.include "src/rom/event_command_macros.inc"
event_4E8_command_44F4:
    event_call 1864
event_4E8_command_44F6:
    event_actor_walk 4, 3, 32
event_4E8_command_44F9:
    event_wait_idle 
event_4E8_command_44FA:
    event_actor_walk 0, 3, 48
event_4E8_command_44FD:
    event_actor_walk 4, 3, 48
event_4E8_command_4500:
    event_wait_idle 
event_4E8_command_4501:
    event_actor_animation_loop 0, 137
event_4E8_command_4504:
    event_actor_animation_loop 4, 137
event_4E8_command_4507:
    event_wait_idle 
event_4E8_command_4508:
    event_increment_flag 10
event_4E8_command_450A:
    event_change_map 105
event_4E8_command_450C:
    event_audio_request 1, 14, 27, 143
event_4E8_command_4511:
    event_actor_walk 0, 1, 0
event_4E8_command_4514:
    event_wait_idle 
event_4E8_command_4515:
    event_actor_animation_loop 0, 128
