; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F2B3
.include "src/rom/event_command_macros.inc"
event_3F0_command_F2B3:
    event_wait 16
event_3F0_command_F2B5:
    event_audio_request 2, 23, 0, 136
