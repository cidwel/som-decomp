; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $703D
.include "src/rom/event_command_macros.inc"
event_584_command_703D:
    event_audio_request 1, 48, 10, 255
