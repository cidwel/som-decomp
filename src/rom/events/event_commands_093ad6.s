; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3AD6
.include "src/rom/event_command_macros.inc"
event_127_command_3AD6:
    event_wait 8
