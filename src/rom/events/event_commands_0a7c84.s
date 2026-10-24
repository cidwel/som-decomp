; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C84
.include "src/rom/event_command_macros.inc"
event_5F8_command_7C84:
    event_decrement_flag 248
event_5F8_command_7C86:
    event_set_flag 70, 8
event_5F8_command_7C89:
    event_refresh_objects 
event_5F8_command_7C8A:
    event_wait 16
event_5F8_command_7C8C:
    event_screen_word 6, 32767
event_5F8_command_7C90:
    event_audio_request 1, 24, 68, 143
