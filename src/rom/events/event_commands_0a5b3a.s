; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B3A
.include "src/rom/event_command_macros.inc"
event_511_command_5B3A:
    event_wait 0
