; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $98C6
.include "src/rom/event_command_macros.inc"
event_7FF_command_98C6:
    event_call 2043
