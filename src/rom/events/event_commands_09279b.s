; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $279B
.include "src/rom/event_command_macros.inc"
event_103_command_279B:
    event_audio_request 1, 24, 4, 255
event_103_command_27A0:
    event_increment_flag 0
event_103_command_27A2:
    event_screen 7
event_103_command_27A4:
    event_call 1865
