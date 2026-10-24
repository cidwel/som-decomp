; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F2A7
.include "src/rom/event_command_macros.inc"
event_3F0_command_F2A7:
    event_audio_request 2, 179, 15, 136
