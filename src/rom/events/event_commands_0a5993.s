; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5993
.include "src/rom/event_command_macros.inc"
event_509_command_5993:
    event_audio_request 2, 216, 0, 136
event_509_command_5998:
    event_wait 8
