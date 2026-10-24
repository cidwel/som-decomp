; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7126
.include "src/rom/event_command_macros.inc"
event_586_command_7126:
    event_audio_request 1, 48, 10, 255
