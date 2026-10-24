; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C02
.include "src/rom/event_command_macros.inc"
event_400_command_0C02:
    event_toggle_visibility_04 
event_400_command_0C03:
    event_increment_flag 248
event_400_command_0C05:
    event_audio_request 1, 43, 12, 255
event_400_command_0C0A:
    event_call 1936
