; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $08AE
.include "src/rom/event_command_macros.inc"
event_00B_command_08AE:
    event_audio_request 2, 22, 15, 136
event_00B_command_08B3:
    event_wait 16
