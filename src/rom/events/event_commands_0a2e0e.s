; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E0E
.include "src/rom/event_command_macros.inc"
event_4E1_command_2E0E:
    event_call 1864
