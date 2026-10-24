; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $987A
.include "src/rom/event_command_macros.inc"
event_227_command_987A:
    event_wait 0
