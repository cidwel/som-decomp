; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FC9
.include "src/rom/event_command_macros.inc"
event_52F_command_5FC9:
    event_wait 32
event_52F_command_5FCB:
    event_audio_request 2, 35, 0, 136
