; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F38
.include "src/rom/event_command_macros.inc"
event_582_command_6F38:
    event_audio_request 1, 48, 10, 255
