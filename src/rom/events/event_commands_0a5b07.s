; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B07
.include "src/rom/event_command_macros.inc"
event_511_command_5B07:
    event_wait 0
