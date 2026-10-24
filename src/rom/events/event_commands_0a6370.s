; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6370
.include "src/rom/event_command_macros.inc"
event_555_command_6370:
    event_set_actor_field 2, 144, 1
event_555_command_6374:
    event_actor_animation_loop 2, 153
event_555_command_6377:
    event_wait_idle 
event_555_command_6378:
    event_screen 0
event_555_command_637A:
    event_audio_request 2, 135, 15, 136
event_555_command_637F:
    event_wait 48
event_555_command_6381:
    event_screen 1
event_555_command_6383:
    event_set_actor_field 2, 130, 0
event_555_command_6387:
    event_set_actor_field 2, 131, 0
event_555_command_638B:
    event_set_actor_field 2, 144, 0
event_555_command_638F:
    event_set_actor_field 2, 145, 128
event_555_command_6393:
    event_restore_hero 66
event_555_command_6395:
    event_native_command_35 
event_555_command_6396:
    event_call 1988
