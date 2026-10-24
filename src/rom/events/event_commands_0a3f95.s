; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3F95
.include "src/rom/event_command_macros.inc"
event_4E6_command_3F95:
    event_call 1864
