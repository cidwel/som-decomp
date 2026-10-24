; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4153
.include "src/rom/event_command_macros.inc"
event_4E7_command_4153:
    event_audio_request 1, 8, 27, 143
