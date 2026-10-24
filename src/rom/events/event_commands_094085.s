; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4085
.include "src/rom/event_command_macros.inc"
event_13A_command_4085:
    event_audio_request 1, 47, 10, 255
event_13A_command_408A:
    event_wait 16
event_13A_command_408C:
    event_wait 0
event_13A_command_408E:
    event_audio_request 1, 29, 27, 143
