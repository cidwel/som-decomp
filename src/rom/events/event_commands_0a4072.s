; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4072
.include "src/rom/event_command_macros.inc"
event_4E6_command_4072:
    event_call 1844
