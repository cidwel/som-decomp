; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $27A7
.include "src/rom/event_command_macros.inc"
event_103_command_27A7:
    event_call 1853
event_103_command_27A9:
    event_audio_request 1, 28, 138, 15
