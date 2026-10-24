; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F0A8
.include "src/rom/event_command_macros.inc"
event_3EB_command_F0A8:
    event_audio_request 2, 164, 0, 136
