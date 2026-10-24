; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E6A
.include "src/rom/event_command_macros.inc"
event_4B2_command_1E6A:
    event_wait 0
