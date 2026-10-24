; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $567E
.include "src/rom/event_command_macros.inc"
event_180_command_567E:
    event_wait 0
